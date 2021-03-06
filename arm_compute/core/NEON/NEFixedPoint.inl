/*
 * Copyright (c) 2017 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

namespace arm_compute
{
/**< Exponent polynomial coefficients for 8 bit fixed point (8 elements)
 *  Format is in Q0.7 for all elements */
const std::array<qint8x8_t, 4> exp_tab_qs8 =
{
    {
        vdup_n_s8(0x7F), // 0.9978546
        vdup_n_s8(0x3F), // 0.4994721
        vdup_n_s8(0x16), // 0.1763723
        vdup_n_s8(0x05), // 0.0435108
    }
};

/**< Exponent polynomial coefficients for 8 bit fixed point (16 elements)
 * Format is in Q0.7 for all elements */
const std::array<qint8x16_t, 4> exp_tabq_qs8 =
{
    {
        vdupq_n_s8(0x7F), // 0.9978546
        vdupq_n_s8(0x3F), // 0.4994721
        vdupq_n_s8(0x16), // 0.1763723
        vdupq_n_s8(0x05), // 0.0435108
    }
};

/**< Logarithm polynomial coefficients for 8 bit fixed point (8 elements)
 * Format is in Q0.7 for all elements except the first one which is in Q1.6 */
const std::array<qint8x8_t, 4> log_tab_qs8 =
{
    {
        vdup_n_s8(0x5C),  // 1.4384189
        vdup_n_s8(-0x56), // -0.6771900
        vdup_n_s8(0x29),  // 0.3218538
        vdup_n_s8(-0x0A), // -0.0832229
    }
};

/**< Logarithm polynomial coefficients for 8 bit fixed point (16 elements)
 * Format is in Q0.7 for all elements except the first one which is in Q1.6 */
const std::array<qint8x16_t, 4> log_tabq_qs8 =
{
    {
        vdupq_n_s8(0x5C),  // 1.4384189
        vdupq_n_s8(-0x56), // -0.6771900
        vdupq_n_s8(0x29),  // 0.3218538
        vdupq_n_s8(-0x0A), // -0.0832229
    }
};

inline qint8x8_t vget_low_qs8(qint8x16_t a)
{
    return vget_low_s8(a);
}

inline qint8x8_t vget_high_qs8(qint8x16_t a)
{
    return vget_high_s8(a);
}

inline qint8x8_t vld1_qs8(const qint8_t *addr)
{
    return vld1_s8(addr);
}

inline qint8x16_t vld1q_qs8(const qint8_t *addr)
{
    return vld1q_s8(addr);
}

inline qint16x4_t vld1_qs16(const qint16_t *addr)
{
    return vld1_s16(addr);
}

inline qint16x8_t vld1q_qs16(const qint16_t *addr)
{
    return vld1q_s16(addr);
}

inline qint8x8_t vld1_dup_qs8(const qint8_t *addr)
{
    return vld1_dup_s8(addr);
}

inline qint8x16_t vld1q_dup_qs8(const qint8_t *addr)
{
    return vld1q_dup_s8(addr);
}

inline void vst1_qs8(qint8_t *addr, qint8x8_t b)
{
    vst1_s8(addr, b);
}

inline void vst1q_qs8(qint8_t *addr, qint8x16_t b)
{
    vst1q_s8(addr, b);
}

inline void vst1_qs16(qint16_t *addr, qint16x4_t b)
{
    vst1_s16(addr, b);
}

inline void vst1q_qs16(qint16_t *addr, qint16x8_t b)
{
    vst1q_s16(addr, b);
}

inline qint8x8_t vqmovn_qs16(qint16x8_t a)
{
    return vqmovn_s16(a);
}

inline qint8x8_t vdup_n_qs8(qint8_t a)
{
    return vdup_n_s8(a);
}

inline qint8x16_t vdupq_n_qs8(qint8_t a)
{
    return vdupq_n_s8(a);
}

inline qint8x16_t vdupq_n_qs8_f32(float a, int fixed_point_position)
{
    float32x4x4_t res =
    {
        {
            vdupq_n_f32(a),
            vdupq_n_f32(a),
            vdupq_n_f32(a),
            vdupq_n_f32(a),
        }
    };
    return vcvtq_qs8_f32(res, fixed_point_position);
}

inline qint16x8_t vdupq_n_qs16(qint16_t a)
{
    return vdupq_n_s16(a);
}

inline qint8x8_t vabs_qs8(qint8x8_t a)
{
    return vabs_s8(a);
}

inline qint8x16_t vabsq_qs8(qint8x16_t a)
{
    return vabsq_s8(a);
}

inline qint8x8_t vqabs_qs8(qint8x8_t a)
{
    return vqabs_s8(a);
}

inline qint8x16_t vqabsq_qs8(qint8x16_t a)
{
    return vqabsq_s8(a);
}

inline qint8x8_t vmax_qs8(qint8x8_t a, qint8x8_t b)
{
    return vmax_s8(a, b);
}

inline qint8x16_t vmaxq_qs8(qint8x16_t a, qint8x16_t b)
{
    return vmaxq_s8(a, b);
}

inline qint8x8_t vpmax_qs8(qint8x8_t a, qint8x8_t b)
{
    return vpmax_s8(a, b);
}

inline qint8x8_t vmin_qs8(qint8x8_t a, qint8x8_t b)
{
    return vmin_s8(a, b);
}

inline qint8x16_t vminq_qs8(qint8x16_t a, qint8x16_t b)
{
    return vminq_s8(a, b);
}

inline qint8x8_t vpmin_qs8(qint8x8_t a, qint8x8_t b)
{
    return vpmin_s8(a, b);
}

inline qint8x8_t vadd_qs8(qint8x8_t a, qint8x8_t b)
{
    return vadd_s8(a, b);
}

inline qint8x16_t vaddq_qs8(qint8x16_t a, qint8x16_t b)
{
    return vaddq_s8(a, b);
}

inline qint8x8_t vqadd_qs8(qint8x8_t a, qint8x8_t b)
{
    return vqadd_s8(a, b);
}

inline qint8x16_t vqaddq_qs8(qint8x16_t a, qint8x16_t b)
{
    return vqaddq_s8(a, b);
}

inline qint16x4_t vqadd_qs16(qint16x4_t a, qint16x4_t b)
{
    return vqadd_s16(a, b);
}

inline qint16x8_t vqaddq_qs16(qint16x8_t a, qint16x8_t b)
{
    return vqaddq_s16(a, b);
}

inline int16x4_t vpaddl_qs8(qint8x8_t a)
{
    return vpaddl_s8(a);
}

inline qint8x8_t vsub_qs8(qint8x8_t a, qint8x8_t b)
{
    return vsub_s8(a, b);
}

inline qint8x16_t vsubq_qs8(qint8x16_t a, qint8x16_t b)
{
    return vsubq_s8(a, b);
}

inline qint8x8_t vqsub_qs8(qint8x8_t a, qint8x8_t b)
{
    return vqsub_s8(a, b);
}

inline qint8x16_t vqsubq_qs8(qint8x16_t a, qint8x16_t b)
{
    return vqsubq_s8(a, b);
}

inline qint8x8_t vmul_qs8(qint8x8_t a, qint8x8_t b, int fixed_point_position)
{
    const int16x8_t fixed_point_position_s16 = vdupq_n_s16(-fixed_point_position);

    // Initialize the temporary result with a constant used to round up the result
    qint16x8_t res = vdupq_n_s16(1 << (fixed_point_position - 1));

    // Vector multiply-accumulate long
    res = vmlal_s8(res, a, b);

    // Shift right by fixed_point_position
    res = vshlq_s16(res, fixed_point_position_s16);

    // Convert back to qint8
    return vmovn_s16(res);
}

inline qint8x16_t vmulq_qs8(qint8x16_t a, qint8x16_t b, int fixed_point_position)
{
    const int16x8_t fixed_point_position_s16 = vdupq_n_s16(-fixed_point_position);

    // Initialize the temporary results with a constant used to round up the result
    qint16x8_t res0 = vdupq_n_s16(1 << (fixed_point_position - 1));
    qint16x8_t res1 = res0;

    // Vector multiply-accumulate long
    res0 = vmlal_s8(res0, vget_low_s8(a), vget_low_s8(b));
    res1 = vmlal_s8(res1, vget_high_s8(a), vget_high_s8(b));

    // Shift right by fixed_point_position
    res0 = vshlq_s16(res0, fixed_point_position_s16);
    res1 = vshlq_s16(res1, fixed_point_position_s16);

    // Convert back to qint8
    return vcombine_s8(vmovn_s16(res0), vmovn_s16(res1));
}

inline qint8x8_t vqmul_qs8(qint8x8_t a, qint8x8_t b, int fixed_point_position)
{
    const int16x8_t fixed_point_position_s16 = vdupq_n_s16(-fixed_point_position);

    // Initialize the temporary result with a constant used to round up the result
    qint16x8_t res = vdupq_n_s16(1 << (fixed_point_position - 1));

    // Vector multiply-accumulate long
    res = vmlal_s8(res, a, b);

    // Shift right by fixed_point_position
    res = vqshlq_s16(res, fixed_point_position_s16);

    // Convert back to qint8 and saturate
    return vqmovn_s16(res);
}

inline qint8x16_t vqmulq_qs8(qint8x16_t a, qint8x16_t b, int fixed_point_position)
{
    const int16x8_t fixed_point_position_s16 = vdupq_n_s16(-fixed_point_position);

    // Initialize the temporary results with a constant used to round up the result
    qint16x8_t res0 = vdupq_n_s16(1 << (fixed_point_position - 1));
    qint16x8_t res1 = res0;

    // Vector multiply-accumulate long
    res0 = vmlal_s8(res0, vget_low_s8(a), vget_low_s8(b));
    res1 = vmlal_s8(res1, vget_high_s8(a), vget_high_s8(b));

    // Shift right by fixed_point_position
    res0 = vqshlq_s16(res0, fixed_point_position_s16);
    res1 = vqshlq_s16(res1, fixed_point_position_s16);

    // Convert back to qint8 and saturate
    return vcombine_s8(vqmovn_s16(res0), vqmovn_s16(res1));
}

inline qint16x8_t vmull_qs8(qint8x8_t a, qint8x8_t b, int fixed_point_position)
{
    const int16x8_t fixed_point_position_s16 = vdupq_n_s16(-fixed_point_position);

    qint16x8_t res = vmull_s8(a, b);

    return vqrshlq_s16(res, fixed_point_position_s16);
}

inline qint8x8_t vmla_qs8(qint8x8_t a, qint8x8_t b, qint8x8_t c, int fixed_point_position)
{
    const int16x8_t fixed_point_position_s16 = vdupq_n_s16(-fixed_point_position);

    // Initialize the temporary results with a constant used to round up the result
    qint16x8_t tmp = vdupq_n_s16(1 << (fixed_point_position - 1));

    // Vector multiply-accumulate long
    tmp = vmlal_s8(tmp, b, c);

    // Shift right by fixed_point_position
    tmp = vshlq_s16(tmp, fixed_point_position_s16);

    // Convert back to qint8 and accumulate
    return vadd_s8(a, vmovn_s16(tmp));
}

inline qint8x16_t vmlaq_qs8(qint8x16_t a, qint8x16_t b, qint8x16_t c, int fixed_point_position)
{
    const int16x8_t fixed_point_position_s16 = vdupq_n_s16(-fixed_point_position);

    // Initialize the temporary results with a constant used to round up the result
    qint16x8_t tmp0 = vdupq_n_s16(1 << (fixed_point_position - 1));
    qint16x8_t tmp1 = tmp0;

    // Vector multiply-accumulate long
    tmp0 = vmlal_s8(tmp0, vget_low_s8(b), vget_low_s8(c));
    tmp1 = vmlal_s8(tmp1, vget_high_s8(b), vget_high_s8(c));

    // Shift right by fixed_point_position
    tmp0 = vshlq_s16(tmp0, fixed_point_position_s16);
    tmp1 = vshlq_s16(tmp1, fixed_point_position_s16);

    // Convert back to qint8 and accumulate
    return vcombine_s8(vadd_s8(vget_low_s8(a), vmovn_s16(tmp0)), vadd_s8(vget_high_s8(a), vmovn_s16(tmp1)));
}

inline qint8x8_t vqmla_qs8(qint8x8_t a, qint8x8_t b, qint8x8_t c, int fixed_point_position)
{
    const int16x8_t fixed_point_position_s16 = vdupq_n_s16(-fixed_point_position);

    // Initialize the temporary results with a constant used to round up the result
    qint16x8_t tmp = vdupq_n_s16(1 << (fixed_point_position - 1));

    // Vector multiply-accumulate long
    tmp = vmlal_s8(tmp, b, c);

    // Shift right by fixed_point_position
    tmp = vqshlq_s16(tmp, fixed_point_position_s16);

    // Convert back to qint8 and accumulate
    return vqadd_s8(a, vqmovn_s16(tmp));
}

inline qint8x16_t vqmlaq_qs8(qint8x16_t a, qint8x16_t b, qint8x16_t c, int fixed_point_position)
{
    const int16x8_t fixed_point_position_s16 = vdupq_n_s16(-fixed_point_position);

    // Initialize the temporary results with a constant used to round up the result
    qint16x8_t tmp0 = vdupq_n_s16(1 << (fixed_point_position - 1));
    qint16x8_t tmp1 = tmp0;

    // Vector multiply-accumulate long
    tmp0 = vmlal_s8(tmp0, vget_low_s8(b), vget_low_s8(c));
    tmp1 = vmlal_s8(tmp1, vget_high_s8(b), vget_high_s8(c));

    // Shift right by fixed_point_position
    tmp0 = vqshlq_s16(tmp0, fixed_point_position_s16);
    tmp1 = vqshlq_s16(tmp1, fixed_point_position_s16);

    // Convert back to qint8 and accumulate
    qint8x16_t res = vcombine_s8(vqmovn_s16(tmp0), vqmovn_s16(tmp1));
    return vqaddq_s8(a, res);
}

inline qint16x8_t vmlal_qs8(qint16x8_t a, qint8x8_t b, qint8x8_t c, int fixed_point_position)
{
    const int16x8_t fixed_point_position_s16 = vdupq_n_s16(-fixed_point_position);

    // Initialize the temporary results with a constant used to round up the result
    qint16x8_t tmp = vdupq_n_s16(1 << (fixed_point_position - 1));

    // Vector multiply-accumulate long
    tmp = vmlal_s8(tmp, b, c);

    // Shift right by fixed_point_position
    tmp = vshlq_s16(tmp, fixed_point_position_s16);

    // Accumulate
    return vaddq_s16(a, tmp);
}

inline qint16x8_t vqmlal_qs8(qint16x8_t a, qint8x8_t b, qint8x8_t c, int fixed_point_position)
{
    const int16x8_t fixed_point_position_s16 = vdupq_n_s16(-fixed_point_position);

    // Initialize the temporary results with a constant used to round up the result
    qint16x8_t tmp = vdupq_n_s16(1 << (fixed_point_position - 1));

    // Vector multiply-accumulate long
    tmp = vmlal_s8(tmp, b, c);

    // Shift right by fixed_point_position
    tmp = vqshlq_s16(tmp, fixed_point_position_s16);

    // Accumulate
    return vqaddq_s16(a, tmp);
}

inline qint8x8_t vcvt_qs8_f32(const float32x4x2_t &a, int fixed_point_position)
{
    const float32x4_t pow2 = vdupq_n_f32(static_cast<float>(1 << fixed_point_position));

    float32x4x2_t res_f32 =
    {
        {
            vdupq_n_f32(0.5f),
            vdupq_n_f32(0.5f)
        }
    };

    res_f32.val[0] = vmlaq_f32(res_f32.val[0], a.val[0], pow2);
    res_f32.val[1] = vmlaq_f32(res_f32.val[1], a.val[1], pow2);

    const int32x4x2_t res_s32 =
    {
        {
            vcvtq_s32_f32(res_f32.val[0]),
            vcvtq_s32_f32(res_f32.val[1]),
        }
    };

    const int16x8_t res_s16 = vcombine_s16(vqmovn_s32(res_s32.val[0]), vqmovn_s32(res_s32.val[1]));

    return vqmovn_s16(res_s16);
}

inline qint8x16_t vcvtq_qs8_f32(const float32x4x4_t &a, int fixed_point_position)
{
    const float32x4_t pow2 = vdupq_n_f32(static_cast<float>(1 << fixed_point_position));

    float32x4x4_t res_f32 =
    {
        {
            vdupq_n_f32(0.5f),
            vdupq_n_f32(0.5f),
            vdupq_n_f32(0.5f),
            vdupq_n_f32(0.5f)
        }
    };

    res_f32.val[0] = vmlaq_f32(res_f32.val[0], a.val[0], pow2);
    res_f32.val[1] = vmlaq_f32(res_f32.val[1], a.val[1], pow2);
    res_f32.val[2] = vmlaq_f32(res_f32.val[2], a.val[2], pow2);
    res_f32.val[3] = vmlaq_f32(res_f32.val[3], a.val[3], pow2);

    const int32x4x4_t res_s32 =
    {
        {
            vcvtq_s32_f32(res_f32.val[0]),
            vcvtq_s32_f32(res_f32.val[1]),
            vcvtq_s32_f32(res_f32.val[2]),
            vcvtq_s32_f32(res_f32.val[3]),
        }
    };

    const int16x8x2_t res_s16 =
    {
        {
            vcombine_s16(vqmovn_s32(res_s32.val[0]), vqmovn_s32(res_s32.val[1])),
            vcombine_s16(vqmovn_s32(res_s32.val[2]), vqmovn_s32(res_s32.val[3])),
        }
    };

    return vcombine_s8(vqmovn_s16(res_s16.val[0]), vqmovn_s16(res_s16.val[1]));
}

inline float32x4x2_t vcvt_f32_qs8(qint8x8_t a, int fixed_point_position)
{
    const float32x4_t pow2 = vdupq_n_f32(1.0f / (1 << fixed_point_position));

    const int16x8_t res_s16 = vmovl_s8(a);

    const int32x4x2_t res_s32 =
    {
        {
            vmovl_s16(vget_low_s16(res_s16)),
            vmovl_s16(vget_high_s16(res_s16))
        }
    };

    float32x4x2_t res_f32 =
    {
        {
            vcvtq_f32_s32(res_s32.val[0]),
            vcvtq_f32_s32(res_s32.val[1])
        }
    };

    res_f32.val[0] = vmulq_f32(res_f32.val[0], pow2);
    res_f32.val[1] = vmulq_f32(res_f32.val[1], pow2);

    return res_f32;
}

inline float32x4x4_t vcvtq_f32_qs8(qint8x16_t a, int fixed_point_position)
{
    const float32x4_t pow2 = vdupq_n_f32(1.0f / (1 << fixed_point_position));

    const int16x8x2_t res_s16 =
    {
        {
            vmovl_s8(vget_low_s8(a)),
            vmovl_s8(vget_high_s8(a)),
        }
    };

    const int32x4x4_t res_s32 =
    {
        {
            vmovl_s16(vget_low_s16(res_s16.val[0])),
            vmovl_s16(vget_high_s16(res_s16.val[0])),
            vmovl_s16(vget_low_s16(res_s16.val[1])),
            vmovl_s16(vget_high_s16(res_s16.val[1])),
        }
    };

    float32x4x4_t res_f32 =
    {
        {
            vcvtq_f32_s32(res_s32.val[0]),
            vcvtq_f32_s32(res_s32.val[1]),
            vcvtq_f32_s32(res_s32.val[2]),
            vcvtq_f32_s32(res_s32.val[3])
        }
    };

    res_f32.val[0] = vmulq_f32(res_f32.val[0], pow2);
    res_f32.val[1] = vmulq_f32(res_f32.val[1], pow2);
    res_f32.val[2] = vmulq_f32(res_f32.val[2], pow2);
    res_f32.val[3] = vmulq_f32(res_f32.val[3], pow2);

    return res_f32;
}

inline qint8x8_t vrecip_qs8(qint8x8_t a, int fixed_point_position)
{
    // We need two bits to store 2, thus we can only support formats from Q2.5 to Q7.0
    const qint8x8_t const_48_over_17       = vdup_n_s8(0x7A >> (5 - fixed_point_position));    // 2.823
    const qint8x8_t const_minus_32_over_17 = vdup_n_s8(-(0x3C >> (5 - fixed_point_position))); // -1.8823
    const qint8x8_t const_one              = vdup_n_s8(1 << fixed_point_position);

    // Find shift value
    const qint8x8_t shift_value = vneg_s8(vsub_s8(vdup_n_s8(8), vadd_s8(vclz_s8(a), vdup_n_s8(fixed_point_position))));
    const qint8x8_t temp        = vshl_s8(a, shift_value);

    qint8x8_t x = vadd_s8(const_48_over_17, vmul_qs8(temp, const_minus_32_over_17, fixed_point_position));

    uint8x8_t set_one = vcgt_s8(x, const_one);
    x                 = vbsl_s8(set_one, const_one, x);

    // Use three iterations of Newton-Raphson  method to get the result
    x = vadd_s8(x, vmul_qs8(x, vsub_s8(const_one, vmul_qs8(temp, x, fixed_point_position)), fixed_point_position));
    x = vadd_s8(x, vmul_qs8(x, vsub_s8(const_one, vmul_qs8(temp, x, fixed_point_position)), fixed_point_position));
    x = vadd_s8(x, vmul_qs8(x, vsub_s8(const_one, vmul_qs8(temp, x, fixed_point_position)), fixed_point_position));

    return vshl_s8(x, shift_value);
}

inline qint8x16_t vrecipq_qs8(qint8x16_t a, int fixed_point_position)
{
    // We need two bits to store 2, thus we can only support formats from Q2.5 to Q7.0
    const qint8x16_t const_48_over_17       = vdupq_n_s8(0x7A >> (5 - fixed_point_position));   // 2.823
    const qint8x16_t const_minus_32_over_17 = vdupq_n_s8((0x3C >> (5 - fixed_point_position))); // -1.8823
    const qint8x16_t const_one              = vdupq_n_s8(1 << fixed_point_position);

    // Find shift value
    const qint8x16_t shift_value = vnegq_s8(vsubq_s8(vdupq_n_s8(8), vaddq_s8(vclzq_s8(a), vdupq_n_s8(fixed_point_position))));
    const qint8x16_t temp        = vshlq_s8(a, shift_value);

    qint8x16_t x = vsubq_qs8(const_48_over_17, vmulq_qs8(temp, const_minus_32_over_17, fixed_point_position));

    // Set initial guess to one if x > 1
    uint8x16_t set_one = vcgtq_s8(x, const_one);
    x                  = vbslq_s8(set_one, const_one, x);

    // Use three iterations of Newton-Raphson  method to get the result
    x = vaddq_s8(x, vmulq_qs8(x, vsubq_s8(const_one, vmulq_qs8(temp, x, fixed_point_position)), fixed_point_position));
    x = vaddq_s8(x, vmulq_qs8(x, vsubq_s8(const_one, vmulq_qs8(temp, x, fixed_point_position)), fixed_point_position));
    x = vaddq_s8(x, vmulq_qs8(x, vsubq_s8(const_one, vmulq_qs8(temp, x, fixed_point_position)), fixed_point_position));

    return vshlq_s8(x, shift_value);
}

inline qint8x16_t vqrecipq_qs8(qint8x16_t a, int fixed_point_position)
{
    // We need two bits to store 2, thus we can only support formats from Q2.5 to Q7.0
    const qint8x16_t const_48_over_17       = vdupq_n_s8(0x7A >> (5 - fixed_point_position));   // 2.823
    const qint8x16_t const_minus_32_over_17 = vdupq_n_s8((0x3C >> (5 - fixed_point_position))); // -1.8823
    const qint8x16_t const_one              = vdupq_n_s8(1 << fixed_point_position);

    // Find shift value
    const qint8x16_t shift_value = vqnegq_s8(vqsubq_s8(vdupq_n_s8(8), vqaddq_s8(vclzq_s8(a), vdupq_n_s8(fixed_point_position))));
    const qint8x16_t temp        = vqshlq_s8(a, shift_value);

    qint8x16_t x = vqsubq_qs8(const_48_over_17, vmulq_qs8(temp, const_minus_32_over_17, fixed_point_position));

    // Set initial guess to one if x > 1
    uint8x16_t set_one = vcgtq_s8(x, const_one);
    x                  = vbslq_s8(set_one, const_one, x);

    // Use three iterations of Newton-Raphson  method to get the result
    x = vqaddq_s8(x, vqmulq_qs8(x, vqsubq_s8(const_one, vqmulq_qs8(temp, x, fixed_point_position)), fixed_point_position));
    x = vqaddq_s8(x, vqmulq_qs8(x, vqsubq_s8(const_one, vqmulq_qs8(temp, x, fixed_point_position)), fixed_point_position));
    x = vqaddq_s8(x, vqmulq_qs8(x, vqsubq_s8(const_one, vqmulq_qs8(temp, x, fixed_point_position)), fixed_point_position));

    return vqshlq_s8(x, shift_value);
}

inline qint8x8_t vdiv_qs8(qint8x8_t a, qint8x8_t b, int fixed_point_position)
{
    return vmul_qs8(a, vrecip_qs8(b, fixed_point_position), fixed_point_position);
}

inline qint8x16_t vdivq_qs8(qint8x16_t a, qint8x16_t b, int fixed_point_position)
{
    return vmulq_qs8(a, vrecipq_qs8(b, fixed_point_position), fixed_point_position);
}

template <bool   islog>
inline qint8x8_t vtaylor_poly_qs8(int8x8_t a, int fixed_point_position)
{
    const qint8x8_t shift_value = vdup_n_s8(-(7 - fixed_point_position));
    const qint8x8_t const_one   = vdup_n_s8(1);
    const qint8x8_t A           = vrshl_s8(islog ? log_tab_qs8[0] : exp_tab_qs8[0], islog ? vadd_s8(shift_value, const_one) : shift_value);
    const qint8x8_t B           = vrshl_s8(islog ? log_tab_qs8[1] : exp_tab_qs8[1], shift_value);
    const qint8x8_t C           = vrshl_s8(islog ? log_tab_qs8[2] : exp_tab_qs8[2], shift_value);
    const qint8x8_t D           = vrshl_s8(islog ? log_tab_qs8[3] : exp_tab_qs8[3], shift_value);
    const qint8x8_t x1          = vadd_s8(vmul_qs8(a, D, fixed_point_position), C);
    const qint8x8_t x2          = vadd_s8(vmul_qs8(a, x1, fixed_point_position), B);
    const qint8x8_t x3          = vadd_s8(vmul_qs8(a, x2, fixed_point_position), A);
    const qint8x8_t res         = vmul_qs8(a, x3, fixed_point_position);
    return res;
}

template <bool   islog>
inline qint8x8_t vqtaylor_poly_qs8(int8x8_t a, int fixed_point_position)
{
    const qint8x8_t shift_value = vdup_n_s8(-(7 - fixed_point_position));
    const qint8x8_t const_one   = vdup_n_s8(1);
    const qint8x8_t A           = vqrshl_s8(islog ? log_tab_qs8[0] : exp_tab_qs8[0], islog ? vqadd_s8(shift_value, const_one) : shift_value);
    const qint8x8_t B           = vqrshl_s8(islog ? log_tab_qs8[1] : exp_tab_qs8[1], shift_value);
    const qint8x8_t C           = vqrshl_s8(islog ? log_tab_qs8[2] : exp_tab_qs8[2], shift_value);
    const qint8x8_t D           = vqrshl_s8(islog ? log_tab_qs8[3] : exp_tab_qs8[3], shift_value);
    const qint8x8_t x1          = vqadd_s8(vqmul_qs8(a, D, fixed_point_position), C);
    const qint8x8_t x2          = vqadd_s8(vqmul_qs8(a, x1, fixed_point_position), B);
    const qint8x8_t x3          = vqadd_s8(vqmul_qs8(a, x2, fixed_point_position), A);
    const qint8x8_t res         = vqmul_qs8(a, x3, fixed_point_position);
    return res;
}

template <bool    islog>
inline qint8x16_t vtaylor_polyq_qs8(qint8x16_t a, int fixed_point_position)
{
    const qint8x16_t shift_value = vdupq_n_s8(-(7 - fixed_point_position));
    const qint8x16_t const_one   = vdupq_n_s8(1);
    const qint8x16_t A           = vrshlq_s8(islog ? log_tabq_qs8[0] : exp_tabq_qs8[0], islog ? vaddq_s8(shift_value, const_one) : shift_value);
    const qint8x16_t B           = vrshlq_s8(islog ? log_tabq_qs8[1] : exp_tabq_qs8[1], shift_value);
    const qint8x16_t C           = vrshlq_s8(islog ? log_tabq_qs8[2] : exp_tabq_qs8[2], shift_value);
    const qint8x16_t D           = vrshlq_s8(islog ? log_tabq_qs8[3] : exp_tabq_qs8[3], shift_value);
    const qint8x16_t x1          = vaddq_s8(vmulq_qs8(a, D, fixed_point_position), C);
    const qint8x16_t x2          = vaddq_s8(vmulq_qs8(a, x1, fixed_point_position), B);
    const qint8x16_t x3          = vaddq_s8(vmulq_qs8(a, x2, fixed_point_position), A);
    const qint8x16_t res         = vmulq_qs8(a, x3, fixed_point_position);
    return res;
}

template <bool    islog>
inline qint8x16_t vqtaylor_polyq_qs8(qint8x16_t a, int fixed_point_position)
{
    const qint8x16_t shift_value = vdupq_n_s8(-(7 - fixed_point_position));
    const qint8x16_t const_one   = vdupq_n_s8(1);
    const qint8x16_t A           = vqrshlq_s8(islog ? log_tabq_qs8[0] : exp_tabq_qs8[0], islog ? vqaddq_s8(shift_value, const_one) : shift_value);
    const qint8x16_t B           = vqrshlq_s8(islog ? log_tabq_qs8[1] : exp_tabq_qs8[1], shift_value);
    const qint8x16_t C           = vqrshlq_s8(islog ? log_tabq_qs8[2] : exp_tabq_qs8[2], shift_value);
    const qint8x16_t D           = vqrshlq_s8(islog ? log_tabq_qs8[3] : exp_tabq_qs8[3], shift_value);
    const qint8x16_t x1          = vqaddq_s8(vqmulq_qs8(a, D, fixed_point_position), C);
    const qint8x16_t x2          = vqaddq_s8(vqmulq_qs8(a, x1, fixed_point_position), B);
    const qint8x16_t x3          = vqaddq_s8(vqmulq_qs8(a, x2, fixed_point_position), A);
    const qint8x16_t res         = vqmulq_qs8(a, x3, fixed_point_position);
    return res;
}

inline qint8x8_t vqexp_qs8(qint8x8_t a, int fixed_point_position)
{
    const qint8x8_t shift_value   = vdup_n_s8(fixed_point_position - 7);
    const qint8x8_t const_one     = vdup_n_s8(1 << fixed_point_position);
    const qint8x8_t const_ln2     = vqrshl_s8(vdup_n_s8(0x58), shift_value);                     // ln(2)
    const qint8x8_t const_inv_ln2 = vorr_s8(vqrshl_s8(vdup_n_s8(0x38), shift_value), const_one); // 1/ln(2)

    // Perform range reduction [-log(2),log(2)]
    const qint8x8_t m = vqmul_qs8(a, const_inv_ln2, fixed_point_position); // x / ln(2)

    // get decimal part from m
    const qint8x8_t dec_m = vqshl_s8(m, vdup_n_s8(-fixed_point_position));

    qint8x8_t alpha = vqmul_qs8(vqshl_s8(dec_m, vdup_n_s8(fixed_point_position)), const_ln2, fixed_point_position);
    alpha           = vqabs_qs8(vqsub_s8(a, alpha));

    // Polynomial Approximation
    qint8x8_t poly = vqtaylor_poly_qs8<false>(alpha, fixed_point_position);
    poly           = vqadd_s8(poly, const_one);

    // Reconstruct
    poly = vqshl_s8(poly, dec_m);

    return poly;
}

inline qint8x16_t vqexpq_qs8(qint8x16_t a, int fixed_point_position)
{
    const qint8x16_t shift_value   = vdupq_n_s8(fixed_point_position - 7);
    const qint8x16_t const_one     = vdupq_n_s8(1 << fixed_point_position);
    const qint8x16_t const_ln2     = vqrshlq_s8(vdupq_n_s8(0x58), shift_value);                      // ln(2)
    const qint8x16_t const_inv_ln2 = vorrq_s8(vqrshlq_s8(vdupq_n_s8(0x38), shift_value), const_one); // 1/ln(2)

    // Perform range reduction [-log(2),log(2)]
    const qint8x16_t m = vqmulq_qs8(a, const_inv_ln2, fixed_point_position); // x / ln(2)

    // get decimal part from m
    const qint8x16_t dec_m = vqshlq_s8(m, vdupq_n_s8(-fixed_point_position));

    qint8x16_t alpha = vqmulq_qs8(vqshlq_s8(dec_m, vdupq_n_s8(fixed_point_position)), const_ln2, fixed_point_position);
    alpha            = vqabsq_qs8(vqsubq_qs8(a, alpha));

    // Polynomial Approximation
    qint8x16_t poly = vqtaylor_polyq_qs8<false>(alpha, fixed_point_position);
    poly            = vqaddq_s8(poly, const_one);

    // Reconstruct
    poly = vqshlq_s8(poly, dec_m);

    return poly;
}

inline qint8x8_t vlog_qs8(qint8x8_t a, int fixed_point_position)
{
    const qint8x8_t const_one       = vdup_n_s8(1 << fixed_point_position);
    const qint8x8_t const_seven_dec = vdup_n_s8(7);
    const qint8x8_t const_ln2       = vdup_n_s8(0x58 >> (7 - fixed_point_position)); // ln(2)

    // If 0 < a < 1, calculate log(1/x)
    uint8x8_t calc_reciprocal = vclt_s8(a, const_one);
    qint8x8_t recip           = vdup_n_s8(0);
    recip                     = vbsl_s8(calc_reciprocal, recip, a);

    // Calculate reciprocal
    recip = vrecip_qs8(recip, fixed_point_position);
    a     = vbsl_s8(calc_reciprocal, recip, a);

    // Get decimal part of a
    qint8x8_t shift_value = vdup_n_s8(-fixed_point_position);
    qint8x8_t dec_a       = vshl_s8(a, shift_value); // a >> fixed_point_position

    // Get exponent of 2^n which is equal or less than dec_a
    shift_value = vsub_s8(const_seven_dec, vclz_s8(dec_a));

    // Get x to range (1, 2]
    const qint8x8_t shift_value_neg = vneg_s8(shift_value);
    const qint8x8_t temp            = vsub_s8(vrshl_s8(a, shift_value_neg), const_one);
    const qint8x8_t sum             = vmul_s8(shift_value, const_one);

    // Polynomial Approximation
    qint8x8_t poly = vtaylor_poly_qs8<true>(temp, fixed_point_position);

    // Reconstruct
    poly = vmul_qs8(vadd_s8(poly, sum), const_ln2, fixed_point_position);

    // Set negative value for 0 < a < 1
    poly = vbsl_s8(calc_reciprocal, vneg_s8(poly), poly);

    return poly;
}

inline qint8x16_t vlogq_qs8(qint8x16_t a, int fixed_point_position)
{
    const qint8x16_t const_one       = vdupq_n_s8(1 << fixed_point_position);
    const qint8x16_t const_seven_dec = vdupq_n_s8(7);
    const qint8x16_t const_ln2       = vdupq_n_s8(0x58 >> (7 - fixed_point_position)); // ln(2)

    // If 0 < a < 1, calculate log(1/x)
    uint8x16_t calc_reciprocal = vcltq_s8(a, const_one);
    qint8x16_t recip           = vdupq_n_s8(0);
    recip                      = vbslq_s8(calc_reciprocal, a, recip);

    // Calculate reciprocal
    recip = vrecipq_qs8(recip, fixed_point_position);
    a     = vbslq_s8(calc_reciprocal, recip, a);

    // Get decimal part of a
    qint8x16_t shift_value = vdupq_n_s8(-fixed_point_position);
    qint8x16_t dec_a       = vshlq_s8(a, shift_value); // a >> fixed_point_position

    // Get exponent of 2^n which is equal or less than dec_a
    shift_value = vsubq_s8(const_seven_dec, vclzq_s8(dec_a));

    // Get x to range (1, 2]
    const qint8x16_t shift_value_neg = vnegq_s8(shift_value);
    const qint8x16_t temp            = vsubq_s8(vrshlq_s8(a, shift_value_neg), const_one);
    const qint8x16_t sum             = vmulq_s8(shift_value, const_one);

    // Polynomial Approximation
    qint8x16_t poly = vtaylor_polyq_qs8<true>(temp, fixed_point_position);

    // Reconstruct
    poly = vmulq_qs8(vaddq_s8(poly, sum), const_ln2, fixed_point_position);

    // Set negative value for 0 < a < 1
    poly = vbslq_s8(calc_reciprocal, vnegq_s8(poly), poly);

    return poly;
}

inline qint8x8_t vinvsqrt_qs8(qint8x8_t a, int fixed_point_position)
{
    const qint8x8_t const_three = vdup_n_s8(3 << fixed_point_position);

    // Find shift value. Number must be in (0.5, 2) range.
    qint8x8_t shift_value = vneg_s8(vsub_s8(vdup_n_s8(8), vadd_s8(vclz_s8(a), vdup_n_s8(fixed_point_position))));

    // Add one when the shift value is negative in order to get the correct result when we shift right with 1
    qint8x8_t temp         = vsub_s8(vdup_n_s8(8), vadd_s8(vclz_s8(a), vdup_n_s8(fixed_point_position)));
    uint8x8_t temp_ltz     = vclt_s8(temp, vdup_n_qs8(0));
    temp                   = vbsl_s8(temp_ltz, vadd_s8(temp, vdup_n_s8(1)), temp);
    qint8x8_t shift_value2 = vneg_s8(vshr_n_s8(temp, 1));

    temp = vshl_s8(a, shift_value);

    // Initial guess
    qint8x8_t x = temp;

    // Calculate (x / 2) * (3 - a * x^2)
    // After three iterations we have the result for 8 bit
    x = vshr_n_s8(vmul_qs8(x, vsub_s8(const_three, vmul_qs8(temp, vmul_qs8(x, x, fixed_point_position), fixed_point_position)), fixed_point_position), 1);
    x = vshr_n_s8(vmul_qs8(x, vsub_s8(const_three, vmul_qs8(temp, vmul_qs8(x, x, fixed_point_position), fixed_point_position)), fixed_point_position), 1);
    x = vshr_n_s8(vmul_qs8(x, vsub_s8(const_three, vmul_qs8(temp, vmul_qs8(x, x, fixed_point_position), fixed_point_position)), fixed_point_position), 1);

    return vshl_s8(x, shift_value2);
}

inline qint8x8_t vqinvsqrt_qs8(qint8x8_t a, int fixed_point_position)
{
    const qint8x8_t const_three = vdup_n_s8(3 << fixed_point_position);

    // Find shift value. Number must be in (0.5, 2) range.
    qint8x8_t shift_value = vneg_s8(vqsub_s8(vdup_n_s8(8), vadd_s8(vclz_s8(a), vdup_n_s8(fixed_point_position))));

    // Add one when the shift value is negative in order to get the correct result when we shift right with 1
    qint8x8_t temp         = vsub_s8(vdup_n_s8(8), vadd_s8(vclz_s8(a), vdup_n_s8(fixed_point_position)));
    uint8x8_t temp_ltz     = vclt_s8(temp, vdup_n_qs8(0));
    temp                   = vbsl_s8(temp_ltz, vadd_s8(temp, vdup_n_s8(1)), temp);
    qint8x8_t shift_value2 = vneg_s8(vshr_n_s8(temp, 1));

    temp = vshl_s8(a, shift_value);

    // Initial guess
    qint8x8_t x = temp;

    // Calculate (x / 2) * (3 - a * x^2)
    // After three iterations we have the result for 8 bit
    x = vshr_n_s8(vqmul_qs8(x, vqsub_s8(const_three, vqmul_qs8(temp, vqmul_qs8(x, x, fixed_point_position), fixed_point_position)), fixed_point_position), 1);
    x = vshr_n_s8(vqmul_qs8(x, vqsub_s8(const_three, vqmul_qs8(temp, vqmul_qs8(x, x, fixed_point_position), fixed_point_position)), fixed_point_position), 1);
    x = vshr_n_s8(vqmul_qs8(x, vqsub_s8(const_three, vqmul_qs8(temp, vqmul_qs8(x, x, fixed_point_position), fixed_point_position)), fixed_point_position), 1);

    return vshl_s8(x, shift_value2);
}

inline qint8x16_t vinvsqrtq_qs8(qint8x16_t a, int fixed_point_position)
{
    const qint8x16_t const_three = vdupq_n_s8(3 << fixed_point_position);

    // Find shift value. Number must be in (0.5, 2) range.
    qint8x16_t shift_value = vnegq_s8(vsubq_s8(vdupq_n_s8(8), vaddq_s8(vclzq_s8(a), vdupq_n_s8(fixed_point_position))));

    // Add one when the shift value is negative in order to get the correct result when we shift right with 1
    qint8x16_t temp         = vsubq_s8(vdupq_n_s8(8), vaddq_s8(vclzq_s8(a), vdupq_n_s8(fixed_point_position)));
    uint8x16_t temp_ltz     = vcltq_s8(temp, vdupq_n_qs8(0));
    temp                    = vbslq_s8(temp_ltz, vaddq_s8(temp, vdupq_n_s8(1)), temp);
    qint8x16_t shift_value2 = vnegq_s8(vshrq_n_s8(temp, 1));

    temp = vshlq_s8(a, shift_value);

    // Initial guess
    qint8x16_t x = temp;

    // Calculate (x / 2) * (3 - a * x^2)
    // After three iterations we have the result for 8 bit
    x = vshrq_n_s8(vmulq_qs8(x, vsubq_s8(const_three, vmulq_qs8(temp, vmulq_qs8(x, x, fixed_point_position), fixed_point_position)), fixed_point_position), 1);
    x = vshrq_n_s8(vmulq_qs8(x, vsubq_s8(const_three, vmulq_qs8(temp, vmulq_qs8(x, x, fixed_point_position), fixed_point_position)), fixed_point_position), 1);
    x = vshrq_n_s8(vmulq_qs8(x, vsubq_s8(const_three, vmulq_qs8(temp, vmulq_qs8(x, x, fixed_point_position), fixed_point_position)), fixed_point_position), 1);

    return vshlq_s8(x, shift_value2);
}

inline qint8x16_t vqinvsqrtq_qs8(qint8x16_t a, int fixed_point_position)
{
    const qint8x16_t const_three = vdupq_n_s8(3 << fixed_point_position);

    // Find shift value. Number must be in (0.5, 2) range.
    qint8x16_t shift_value = vnegq_s8(vqsubq_s8(vdupq_n_s8(8), vaddq_s8(vclzq_s8(a), vdupq_n_s8(fixed_point_position))));

    // Add one when the shift value is negative in order to get the correct result when we shift right with 1
    qint8x16_t temp         = vsubq_s8(vdupq_n_s8(8), vaddq_s8(vclzq_s8(a), vdupq_n_s8(fixed_point_position)));
    uint8x16_t temp_ltz     = vcltq_s8(temp, vdupq_n_qs8(0));
    temp                    = vbslq_s8(temp_ltz, vaddq_s8(temp, vdupq_n_s8(1)), temp);
    qint8x16_t shift_value2 = vnegq_s8(vshrq_n_s8(temp, 1));

    temp = vshlq_s8(a, shift_value);

    // Initial guess
    qint8x16_t x = temp;

    // Calculate (x / 2) * (3 - a * x^2)
    // After three iterations we have the result for 8 bit
    x = vshrq_n_s8(vqmulq_qs8(x, vqsubq_s8(const_three, vqmulq_qs8(temp, vqmulq_qs8(x, x, fixed_point_position), fixed_point_position)), fixed_point_position), 1);
    x = vshrq_n_s8(vqmulq_qs8(x, vqsubq_s8(const_three, vqmulq_qs8(temp, vqmulq_qs8(x, x, fixed_point_position), fixed_point_position)), fixed_point_position), 1);
    x = vshrq_n_s8(vqmulq_qs8(x, vqsubq_s8(const_three, vqmulq_qs8(temp, vqmulq_qs8(x, x, fixed_point_position), fixed_point_position)), fixed_point_position), 1);

    return vshlq_s8(x, shift_value2);
}

inline qint8x8_t vtanh_qs8(qint8x8_t a, int fixed_point_position)
{
    const qint8x8_t const_one = vdup_n_s8(1 << fixed_point_position);
    const qint8x8_t const_two = vdup_n_s8(2 << fixed_point_position);

    qint8x8_t exp2x = vqexp_qs8(vqmul_qs8(const_two, a, fixed_point_position), fixed_point_position);
    qint8x8_t num   = vqsub_qs8(exp2x, const_one);
    qint8x8_t den   = vqadd_qs8(exp2x, const_one);
    qint8x8_t tanh  = vqmul_qs8(num, vrecip_qs8(den, fixed_point_position), fixed_point_position);

    return tanh;
}

inline qint8x16_t vtanhq_qs8(qint8x16_t a, int fixed_point_position)
{
    const qint8x16_t const_one = vdupq_n_s8(1 << fixed_point_position);
    const qint8x16_t const_two = vdupq_n_s8(2 << fixed_point_position);

    qint8x16_t exp2x = vqexpq_qs8(vqmulq_qs8(const_two, a, fixed_point_position), fixed_point_position);
    qint8x16_t num   = vqsubq_qs8(exp2x, const_one);
    qint8x16_t den   = vqaddq_qs8(exp2x, const_one);
    qint8x16_t tanh  = vqmulq_qs8(num, vqrecipq_qs8(den, fixed_point_position), fixed_point_position);

    return tanh;
}

inline qint8x16_t vqpowq_qs8(qint8x16_t a, qint8x16_t b, int fixed_point_position)
{
    return vqexpq_qs8(vqmulq_qs8(b, vlogq_qs8(a, fixed_point_position), fixed_point_position), fixed_point_position);
}
}
