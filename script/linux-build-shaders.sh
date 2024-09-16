#!/bin/sh

glslc ./src/shaders/offscreen.vert -o ./src/shaders/offscreen.vert.spv
glslc ./src/shaders/offscreen.frag -o ./src/shaders/offscreen.frag.spv
glslc ./src/shaders/forward.vert -o ./src/shaders/forward.vert.spv
glslc ./src/shaders/forward.frag -o ./src/shaders/forward.frag.spv

xxd -i ./src/shaders/offscreen.vert.spv > ./src/shaders/offscreen.vert.c
xxd -i ./src/shaders/offscreen.frag.spv > ./src/shaders/offscreen.frag.c
xxd -i ./src/shaders/forward.vert.spv > ./src/shaders/forward.vert.c
xxd -i ./src/shaders/forward.frag.spv > ./src/shaders/forward.frag.c
