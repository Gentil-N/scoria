#include "common.h"
#include "ctools.h"

struct BufferSegment create_buffer_segment(size_t max_range_count, size_t base_offset, size_t range_size)
{
    struct BufferSegment segment = {0};
    segment.range_ptrs = list_create(BufferRange_ptr, 0);
    segment.max_range_count = max_range_count;
    segment.base_offset = base_offset;
    segment.range_size = range_size;
    return segment;
}

void destroy_buffer_segment(struct BufferSegment *segment)
{
    for_list(i, segment->range_ptrs)
    {
        ram_free(segment->range_ptrs.data[i]);
    }
    list_BufferRange_ptr_destroy(&segment->range_ptrs);
}

struct BufferRange *segment_allocate_buffer_range(struct BufferSegment *segment, size_t segment_id)
{
    if (segment->max_range_count == segment->range_ptrs.size) return NULL;
    struct BufferRange *range = ram_malloc(sizeof(struct BufferRange));
    range->offset = segment->base_offset + segment->range_ptrs.size * segment->range_size;
    range->segment_id = segment_id;
    range->moved = false;
    list_BufferRange_ptr_append(&segment->range_ptrs, &range);
    return range;
}

void segment_free_buffer_range(struct BufferSegment *segment, struct BufferRange *range)
{
    size_t last_range_index = segment->range_ptrs.size - 1;
    size_t range_index = (size_t)((range->offset - segment->base_offset) / segment->range_size);
    if (range_index != last_range_index)
    {
        assert(range_index < segment->range_ptrs.size);
        segment->range_ptrs.data[last_range_index]->offset = range->offset;
        segment->range_ptrs.data[range_index] = segment->range_ptrs.data[last_range_index];
        segment->range_ptrs.data[range_index]->moved = true;
    }
    list_BufferRange_ptr_resize(&segment->range_ptrs, last_range_index);
    ram_free(range);
}

struct BufferSection create_buffer_section(size_t segment_count, const size_t *max_range_per_segment, const size_t *range_size_per_segment, size_t *buffer_section_size)
{
    struct BufferSection section = {0};
    section.segments = list_create(BufferSegment, segment_count);
    size_t offset = 0;
    for_list(i, section.segments)
    {
        section.segments.data[i] = create_buffer_segment(max_range_per_segment[i], offset, range_size_per_segment[i]);
        offset += max_range_per_segment[i] * range_size_per_segment[i];
    }
    *buffer_section_size = offset;
    return section;
}

void destroy_buffer_section(struct BufferSection *buffer_section)
{
    for_list(i, buffer_section->segments)
    {
        destroy_buffer_segment(&buffer_section->segments.data[i]);
    }
    list_BufferSegment_destroy(&buffer_section->segments);
}

struct BufferRange *allocate_buffer_range(struct BufferSection *buffer_section, size_t segment_id)
{
    assert(segment_id < buffer_section->segments.size);
    return segment_allocate_buffer_range(&buffer_section->segments.data[segment_id], segment_id);
}

void free_buffer_range(struct BufferSection *buffer_section, struct BufferRange *buffer_range)
{
    assert(buffer_range->segment_id < buffer_section->segments.size);
    segment_free_buffer_range(&buffer_section->segments.data[buffer_range->segment_id], buffer_range);
}

size_t get_buffer_range_size(struct BufferSection *buffer_section, struct BufferRange *buffer_range)
{
    assert(buffer_range->segment_id < buffer_section->segments.size);
    return buffer_section->segments.data[buffer_range->segment_id].range_size;
}

size_t get_buffer_segment_offset(struct BufferSection *buffer_section, size_t segment_id)
{
    assert(segment_id < buffer_section->segments.size);
    return buffer_section->segments.data[segment_id].base_offset;
}

size_t get_buffer_segment_max_size(struct BufferSection *buffer_section, size_t segment_id)
{
    assert(segment_id < buffer_section->segments.size);
    return buffer_section->segments.data[segment_id].max_range_count * buffer_section->segments.data[segment_id].range_size;
}

size_t get_buffer_segment_actual_size(struct BufferSection *buffer_section, size_t segment_id)
{
    assert(segment_id < buffer_section->segments.size);
    return buffer_section->segments.data[segment_id].range_ptrs.size * buffer_section->segments.data[segment_id].range_size;
}

size_t get_buffer_segment_range_size(struct BufferSection *buffer_section, size_t segment_id)
{
    assert(segment_id < buffer_section->segments.size);
    return buffer_section->segments.data[segment_id].range_size;
}
