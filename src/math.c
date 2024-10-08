#include "common.h"

#include <math.h>

void sc_mat4f_set_perspective(struct ScMat4f *mat, float aspect_ratio, float fov, float near_plane, float far_plane)
{
    float s = 1.0f / tanf(fov * M_PI / 180.0f / 2.0f);
    float coeff = - 1.0f / (far_plane - near_plane);
    sc_mat4f_set_zero(mat);
    mat->m00 = s / aspect_ratio;
    mat->m11 = s;
    mat->m22 = far_plane * coeff;
    mat->m32 = far_plane * near_plane * coeff;
    mat->m23 = -1;
}

void sc_mat4f_set_mul(const struct ScMat4f *mat_a, const struct ScMat4f *mat_b, struct ScMat4f *mat_res)
{
    mat_res->m00 = mat_a->m00 * mat_b->m00 + mat_a->m10 * mat_b->m01 + mat_a->m20 * mat_b->m02 + mat_a->m30 * mat_b->m03;
    mat_res->m01 = mat_a->m01 * mat_b->m00 + mat_a->m11 * mat_b->m01 + mat_a->m21 * mat_b->m02 + mat_a->m31 * mat_b->m03;
    mat_res->m02 = mat_a->m02 * mat_b->m00 + mat_a->m12 * mat_b->m01 + mat_a->m22 * mat_b->m02 + mat_a->m32 * mat_b->m03;
    mat_res->m03 = mat_a->m03 * mat_b->m00 + mat_a->m13 * mat_b->m01 + mat_a->m23 * mat_b->m02 + mat_a->m33 * mat_b->m03;

    mat_res->m10 = mat_a->m00 * mat_b->m10 + mat_a->m10 * mat_b->m11 + mat_a->m20 * mat_b->m12 + mat_a->m30 * mat_b->m13;
    mat_res->m11 = mat_a->m01 * mat_b->m10 + mat_a->m11 * mat_b->m11 + mat_a->m21 * mat_b->m12 + mat_a->m31 * mat_b->m13;
    mat_res->m12 = mat_a->m02 * mat_b->m10 + mat_a->m12 * mat_b->m11 + mat_a->m22 * mat_b->m12 + mat_a->m32 * mat_b->m13;
    mat_res->m13 = mat_a->m03 * mat_b->m10 + mat_a->m13 * mat_b->m11 + mat_a->m23 * mat_b->m12 + mat_a->m33 * mat_b->m13;

    mat_res->m20 = mat_a->m00 * mat_b->m20 + mat_a->m10 * mat_b->m21 + mat_a->m20 * mat_b->m22 + mat_a->m30 * mat_b->m23;
    mat_res->m21 = mat_a->m01 * mat_b->m20 + mat_a->m11 * mat_b->m21 + mat_a->m21 * mat_b->m22 + mat_a->m31 * mat_b->m23;
    mat_res->m22 = mat_a->m02 * mat_b->m20 + mat_a->m12 * mat_b->m21 + mat_a->m22 * mat_b->m22 + mat_a->m32 * mat_b->m23;
    mat_res->m23 = mat_a->m03 * mat_b->m20 + mat_a->m13 * mat_b->m21 + mat_a->m23 * mat_b->m22 + mat_a->m33 * mat_b->m23;

    mat_res->m30 = mat_a->m00 * mat_b->m30 + mat_a->m10 * mat_b->m31 + mat_a->m20 * mat_b->m32 + mat_a->m30 * mat_b->m33;
    mat_res->m31 = mat_a->m01 * mat_b->m30 + mat_a->m11 * mat_b->m31 + mat_a->m21 * mat_b->m32 + mat_a->m31 * mat_b->m33;
    mat_res->m32 = mat_a->m02 * mat_b->m30 + mat_a->m12 * mat_b->m31 + mat_a->m22 * mat_b->m32 + mat_a->m32 * mat_b->m33;
    mat_res->m33 = mat_a->m03 * mat_b->m30 + mat_a->m13 * mat_b->m31 + mat_a->m23 * mat_b->m32 + mat_a->m33 * mat_b->m33;
}

struct ScMat4f *sc_mat4f_set_rot_x(struct ScMat4f *mat, float alpha)
{
    float sina = sinf(alpha);
    float cosa = cosf(alpha);
    sc_mat4f_set_identity(mat);
    mat->m11 = cosa;
    mat->m12 = sina;
    mat->m21 = -sina;
    mat->m22 = cosa;
    return mat;
}

struct ScMat4f *sc_mat4f_set_rot_y(struct ScMat4f *mat, float alpha)
{
    float sina = sinf(alpha);
    float cosa = cosf(alpha);
    sc_mat4f_set_identity(mat);
    mat->m00 = cosa;
    mat->m20 = sina;
    mat->m02 = -sina;
    mat->m22 = cosa;
    return mat;
}

struct ScMat4f *sc_mat4f_set_rot_z(struct ScMat4f *mat, float alpha)
{
    float sina = sinf(alpha);
    float cosa = cosf(alpha);
    sc_mat4f_set_identity(mat);
    mat->m00 = cosa;
    mat->m01 = sina;
    mat->m10 = -sina;
    mat->m11 = cosa;
    return mat;
}

struct ScMat4f *sc_mat4f_rot_x(struct ScMat4f *mat, float alpha)
{
    float sina = sinf(alpha);
    float cosa = cosf(alpha);
    float nm10 = mat->m10 * cosa + mat->m20 * sina;
    float nm20 = -mat->m10 * sina + mat->m20 * cosa;
    float nm11 = mat->m11 * cosa + mat->m21 * sina;
    float nm21 = -mat->m11 * sina + mat->m21 * cosa;
    float nm12 = mat->m12 * cosa + mat->m22 * sina;
    float nm22 = -mat->m12 * sina + mat->m22 * cosa;
    float nm13 = mat->m13 * cosa + mat->m23 * sina;
    float nm23 = -mat->m13 * sina + mat->m23 * cosa;
    mat->m10 = nm10;
    mat->m11 = nm11;
    mat->m12 = nm12;
    mat->m13 = nm13;
    mat->m20 = nm20;
    mat->m21 = nm21;
    mat->m22 = nm22;
    mat->m23 = nm23;
    return mat;
}

struct ScMat4f *sc_mat4f_rot_y(struct ScMat4f *mat, float alpha)
{
    float sina = sinf(alpha);
    float cosa = cosf(alpha);
    float nm00 = mat->m00 * cosa - mat->m20 * sina;
    float nm20 = mat->m00 * sina + mat->m20 * cosa;
    float nm01 = mat->m01 * cosa - mat->m21 * sina;
    float nm21 = mat->m01 * sina + mat->m21 * cosa;
    float nm02 = mat->m02 * cosa - mat->m22 * sina;
    float nm22 = mat->m02 * sina + mat->m22 * cosa;
    float nm03 = mat->m03 * cosa - mat->m23 * sina;
    float nm23 = mat->m03 * sina + mat->m23 * cosa;
    mat->m00 = nm00;
    mat->m01 = nm01;
    mat->m02 = nm02;
    mat->m03 = nm03;
    mat->m20 = nm20;
    mat->m21 = nm21;
    mat->m22 = nm22;
    mat->m23 = nm23;
    return mat;
}

struct ScMat4f *sc_mat4f_rot_z(struct ScMat4f *mat, float alpha)
{
    float sina = sinf(alpha);
    float cosa = cosf(alpha);
    float nm00 = mat->m00 * cosa + mat->m10 * sina;
    float nm10 = -mat->m00 * sina + mat->m10 * cosa;
    float nm01 = mat->m01 * cosa + mat->m11 * sina;
    float nm11 = -mat->m01 * sina + mat->m11 * cosa;
    float nm02 = mat->m02 * cosa + mat->m12 * sina;
    float nm12 = -mat->m02 * sina + mat->m12 * cosa;
    float nm03 = mat->m03 * cosa + mat->m13 * sina;
    float nm13 = -mat->m03 * sina + mat->m13 * cosa;
    mat->m00 = nm00;
    mat->m01 = nm01;
    mat->m02 = nm02;
    mat->m03 = nm03;
    mat->m10 = nm10;
    mat->m11 = nm11;
    mat->m12 = nm12;
    mat->m13 = nm13;
    return mat;
}

struct ScMat4f *sc_mat4f_rot_x_ahead(struct ScMat4f *mat, float alpha)
{
    float sina = sinf(alpha);
    float cosa = cosf(alpha);
    float nm01 = mat->m01 * cosa - mat->m02 * sina;
    float nm02 = mat->m01 * sina + mat->m02 * cosa;
    float nm11 = mat->m11 * cosa - mat->m12 * sina;
    float nm12 = mat->m11 * sina + mat->m12 * cosa;
    float nm21 = mat->m21 * cosa - mat->m22 * sina;
    float nm22 = mat->m21 * sina + mat->m22 * cosa;
    float nm31 = mat->m31 * cosa - mat->m32 * sina;
    float nm32 = mat->m31 * sina + mat->m32 * cosa;
    mat->m01 = nm01;
    mat->m02 = nm02;
    mat->m11 = nm11;
    mat->m12 = nm12;
    mat->m21 = nm21;
    mat->m22 = nm22;
    mat->m31 = nm31;
    mat->m32 = nm32;
    return mat;
}

struct ScMat4f *sc_mat4f_rot_y_ahead(struct ScMat4f *mat, float alpha)
{
    float sina = sinf(alpha);
    float cosa = cosf(alpha);
    float nm00 = mat->m00 * cosa + mat->m02 * sina;
    float nm02 = -mat->m00 * sina + mat->m02 * cosa;
    float nm10 = mat->m10 * cosa + mat->m12 * sina;
    float nm12 = -mat->m10 * sina + mat->m12 * cosa;
    float nm20 = mat->m20 * cosa + mat->m22 * sina;
    float nm22 = -mat->m20 * sina + mat->m22 * cosa;
    float nm30 = mat->m30 * cosa + mat->m32 * sina;
    float nm32 = -mat->m30 * sina + mat->m32 * cosa;
    mat->m00 = nm00;
    mat->m02 = nm02;
    mat->m10 = nm10;
    mat->m12 = nm12;
    mat->m20 = nm20;
    mat->m22 = nm22;
    mat->m30 = nm30;
    mat->m32 = nm32;
    return mat;
}

struct ScMat4f *sc_mat4f_rot_z_ahead(struct ScMat4f *mat, float alpha)
{
    float sina = sinf(alpha);
    float cosa = cosf(alpha);
    float nm00 = mat->m00 * cosa - mat->m01 * sina;
    float nm01 = mat->m01 * sina + mat->m01 * cosa;
    float nm10 = mat->m10 * cosa - mat->m11 * sina;
    float nm11 = mat->m10 * sina + mat->m11 * cosa;
    float nm20 = mat->m20 * cosa - mat->m21 * sina;
    float nm21 = mat->m20 * sina + mat->m21 * cosa;
    float nm30 = mat->m30 * cosa - mat->m31 * sina;
    float nm31 = mat->m30 * sina + mat->m31 * cosa;
    mat->m00 = nm00;
    mat->m01 = nm01;
    mat->m10 = nm10;
    mat->m11 = nm11;
    mat->m20 = nm20;
    mat->m21 = nm21;
    mat->m30 = nm30;
    mat->m31 = nm31;
    return mat;
}

struct ScMat4f *sc_mat4f_set_translation(struct ScMat4f *mat, float x, float y, float z)
{
    sc_mat4f_set_identity(mat);
    mat->m30 = x;
    mat->m31 = y;
    mat->m32 = z;
    return mat;
}

struct ScMat4f *sc_mat4f_translate(struct ScMat4f *mat, float x, float y, float z)
{
    float nm30 = mat->m00 * x + mat->m10 * y + mat->m20 * z + mat->m30;
    float nm31 = mat->m01 * x + mat->m11 * y + mat->m21 * z + mat->m31;
    float nm32 = mat->m02 * x + mat->m12 * y + mat->m22 * z + mat->m32;
    float nm33 = mat->m03 * x + mat->m13 * y + mat->m23 * z + mat->m33;
    mat->m30 = nm30;
    mat->m31 = nm31;
    mat->m32 = nm32;
    mat->m33 = nm33;
    return mat;
}

struct ScMat4f *sc_mat4f_translate_ahead(struct ScMat4f *mat, float x, float y, float z)
{
    float nm00 = mat->m00 + mat->m03 * x;
    float nm10 = mat->m10 + mat->m13 * x;
    float nm20 = mat->m20 + mat->m23 * x;
    float nm30 = mat->m30 + mat->m33 * x;

    float nm01 = mat->m01 + mat->m03 * y;
    float nm11 = mat->m11 + mat->m13 * y;
    float nm21 = mat->m21 + mat->m23 * y;
    float nm31 = mat->m31 + mat->m33 * y;

    float nm02 = mat->m02 + mat->m03 * z;
    float nm12 = mat->m12 + mat->m13 * z;
    float nm22 = mat->m22 + mat->m23 * z;
    float nm32 = mat->m32 + mat->m33 * z;

    mat->m00 = nm00;
    mat->m10 = nm10;
    mat->m20 = nm20;
    mat->m30 = nm30;

    mat->m01 = nm01;
    mat->m11 = nm11;
    mat->m21 = nm21;
    mat->m31 = nm31;

    mat->m02 = nm02;
    mat->m12 = nm12;
    mat->m22 = nm22;
    mat->m32 = nm32;

    return mat;
}

struct ScMat4f *sc_mat4f_set_scaling(struct ScMat4f *mat, float x, float y, float z)
{
    sc_mat4f_set_identity(mat);
    mat->m00 = x;
    mat->m11 = y;
    mat->m22 = z;
    return mat;
}

struct ScQuatf *sc_quatf_interpolate(struct ScQuatf *quat_out, const struct ScQuatf *quat_start, const struct ScQuatf *quat_end, float factor)
{
    float cosom = quat_start->x * quat_end->x + quat_start->y * quat_end->y + quat_start->z * quat_end->z + quat_start->w * quat_end->w;
    // adjust signs (if necessary)
    struct ScQuatf end = {quat_end->w, quat_end->x, quat_end->y, quat_end->z};
    if( cosom < 0.0f)
    {
        cosom = -cosom;
        end.x = -end.x;   // Reverse all signs
        end.y = -end.y;
        end.z = -end.z;
        end.w = -end.w;
    }
    // Calculate coefficients
    float sclp, sclq;
    if ((1.0f - cosom) > 0.0001f) // 0.0001 -> some epsillon
    {
        // Standard case (slerp)
        float omega, sinom;
        omega = acosf(cosom); // extract theta from dot product's cos theta
        sinom = sinf(omega);
        sclp  = sinf((1.0f - factor) * omega) / sinom;
        sclq  = sinf(factor * omega) / sinom;
    } else
    {
        // Very close, do linear interp (because it's faster)
        sclp = 1.0f - factor;
        sclq = factor;
    }
    quat_out->x = sclp * quat_start->x + sclq * end.x;
    quat_out->y = sclp * quat_start->y + sclq * end.y;
    quat_out->z = sclp * quat_start->z + sclq * end.z;
    quat_out->w = sclp * quat_start->w + sclq * end.w;
    return quat_out;
}

struct ScMat4f *sc_quatf_to_mat4f(const struct ScQuatf *quat, struct ScMat4f *mat)
{
    mat->m00 = 1.0f - 2.0f * (quat->y * quat->y + quat->z * quat->z);
    mat->m10 = 2.0f * (quat->x * quat->y - quat->z * quat->w);
    mat->m20 = 2.0f * (quat->x * quat->z + quat->y * quat->w);
    mat->m01 = 2.0f * (quat->x * quat->y + quat->z * quat->w);
    mat->m11 = 1.0f - 2.0f * (quat->x * quat->x + quat->z * quat->z);
    mat->m21 = 2.0f * (quat->y * quat->z - quat->x * quat->w);
    mat->m02 = 2.0f * (quat->x * quat->z - quat->y * quat->w);
    mat->m12 = 2.0f * (quat->y * quat->z + quat->x * quat->w);
    mat->m22 = 1.0f - 2.0f * (quat->x * quat->x + quat->y * quat->y);
    mat->m30 = mat->m03 = mat->m31 = mat->m13 = mat->m32 = mat->m23 = 0.0f;
    mat->m33 = 1.0f;
    return mat;
}
