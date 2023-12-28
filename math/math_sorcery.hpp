/*The Math Necromancer*/

#ifndef _MATH_SORCERY_
#define _MATH_SORCERY_

/*For raw file warnings, define _RAW_FILE_WARN_*/

/*Sometimes, it's necessary to catch other math libraries, but these detect <cmath> and <math.h>*/
/*At least, they do on my compiler*/

/*Throw a warning if not using <cmath> or <math.h>*/
#if !defined(_GLIBCXX_CMATH) && !defined(_GLIBCXX_MATH_H) && !defined(_MATH_H_)
     #ifndef _MATH_SORCERY_SKIP_MATH_WARN_
          #warning "Remember, this isn't sophisticated. Use <cmath> or <math.h> for serious work!"
          /*To disable this warning, `#define _NECROMANCER_SKIP_CMATH_WARN_` before including this file*/
     #endif /*_MATH_SORCERY_SKIP_MATH_WARN_*/
#endif /*!defined(_GLIBCXX_CMATH) && !defined(_GLIBCXX_MATH_H)*/
/*Throw an error if the standard math libraries are included, it will cause conflict*/
/*To detect another library, #define _FORBIDDEN_MATH_ as the #define of said library*/
#if (defined(_GLIBCXX_CMATH) || defined(_GLIBCXX_MATH_H) || defined(_MATH_H_) || defined(_FORBIDDEN_MATH_)) && defined(_NECROMANCER_MATH_)
     #error "Never use this library with <cmath> or other math libraries!"
#endif /*(defined(_GLIBCXX_CMATH) || defined(_GLIBCXX_MATH_H) || defined(_MATH_H_)) && defined(_NECROMANCER_MATH_)*/

#include "float_class.hpp"

#ifndef _NECROMANCER_FLOAT_CLASS_
     #error "Could not get float_class.hpp! This is serious!"
#endif /*_NECROMANCER_FLOAT_CLASS_*/

/*12/24/2023*/
/*Return a single precision infinity*/
constexpr float inff(const bool& _neg)
{
     return necromancer_float_class::
          _flt_inff(_neg);
}
/*12/24/2023*/
/*Return a double precision infinity*/
constexpr double inf(const bool& _neg)
{
     return necromancer_float_class::
          _flt_infd(_neg);
}
/*12/24/2023*/
/*Retrun a single precision "Not a Number"*/
constexpr float nanf()
{
     return necromancer_float_class::
          _flt_nanf();
}
/*12/24/2023*/
/*Return a double precision "Not a Number"*/
constexpr double nan()
{
     return necromancer_float_class::
          _flt_nand();
}

/*12/24/2023*/
/*Convert an integral bit representation into it's respective 32-bit float*/
constexpr float flt_bits(const necromancer_float_class::_int32& _i)
{
     return necromancer_float_class::
          _flt_bits(_i);
}
/*12/24/2023*/
/*Conver an integral bit representation into it's respective 64-bit float*/
constexpr double dbl_bits(const necromancer_float_class::_int64 _i)
{
     return necromancer_float_class::
          _dbl_bits(_i);
}

/*Get rid of those macros defined in "float_class.hpp"*/
#undef INFINITYf
#undef INFINITY
#undef NEGATIVE_INFINITYf
#undef NEGATIVE_INFINITY
#undef NaNf
#undef NaN
#undef _FLT_ZERO
#undef _FLT_NAN
#undef _FLT_INFINITY
#undef _FLT_NEGATIVE_INFY
#undef _FLT_NORMAL
#undef _FLT_SUBNORMAL

#define _bit                            \
     bool
#define _s_int08                        \
     char
#define _int08                          \
     unsigned char
#define _s_int16                        \
     short
#define _int16                          \
     unsigned short
#define _s_int32                        \
     long
#define _int32                          \
     unsigned long
#define _s_int64                        \
     long long
#define _int64                          \
     unsigned long long
#define float_32                        \
     necromancer_float_class::float_32
#define float_64                        \
     necromancer_float_class::float_64
#define f32                             \
     float
#define f64                             \
     double
/*Single precision Infinity*/
#define INFINITYf                       \
     inff(false)
/*Double precision Infinity*/
#define INFINITY                        \
     inf(false)
/*Single precision Negative Infinity*/
#define NEGATIVE_INFINITYf              \
     inff(true)
/*Double precision Negative Infinity*/
#define NEGATIVE_INFINITY               \
     inf(true)
/*Single precision "Not a Number"*/
#define NaNf                            \
     nanf()
/*Double precision "Not a Number"*/
#define NaN                             \
     nan()
/*** IEEE-754 Float Classifications ***/

/*0.0 (Subnormal in IEEE-754)*/
#define _FLT_ZERO 0x001
/*"Not a Number"*/
#define _FLT_NAN 0x0002
/*Infinity*/
#define _FLT_INFINITY 0x0003
/*Negative Infinity*/
#define _FLT_NEG_INFY 0x0004
/*Normal Floating Point*/
#define _FLT_NORMAL 0x0005
/*Subnormal Float*/
#define _FLT_SUBNORMAL 0x0006
/*π*/
#define pi                              \
     3.1415926535897932384
/*π/2*/
#define pi_2                            \
     1.5707963267948966192
/*π/4*/
#define pi_4                            \
     0.7853981633974483096
/*τ = 2π*/
#define tau                             \
     6.2831853071795864769
/*e*/
/*You should know what this is*/
#define e                               \
     2.7182818284590452354
/*log(2)*/
#define ln2                             \
     0.6931471805599453094
/*log_2(e)*/
#define log2e                           \
     1.4426950408889634074
/*√2*/
#define sqrt2                           \
     1.4142135623730950488

/*Maximum value of a 32-bit float (float)*/
#define _NUMERIC_FLT_MAXIMUM_           \
     flt_bits(0x7f7fffff)
/*Minimum normal value of a 32-bit float (float)*/
#define _NUMERIC_FLT_EPSILON_           \
     _flt_bits(0x00800000)
/*Minimum subnormal value of a 32-bit float (float)*/
#define _NUMERIC_FLT_SUB_EPSILON_       \
     _flt_bits(0x00000001)
/*One unit in the last place after 1.0f (float)*/
#define _NUMERIC_FLT_SMALL_             \
     _flt_bits(0x34000000)

/*Maximum value of a 64-bit float (double)*/
#define _NUMERIC_DBL_MAXIMUM_           \
     _dbl_bits(0x7fefffffffffffff)
/*Minimum normal value of a 64-bit float (double)*/
#define _NUMERIC_DBL_EPSILON_           \
     _dbl_bits(0x0010000000000000)
/*Minimum subnormal value of a 64-bit float (double)*/
#define _NUMERIC_DBL_SUB_EPSILON_       \
     _dbl_bits(0x0000000000000001)
/*One unit in the last place after 1.0 (double)*/
#define _NUMERIC_DBL_SMALL_             \
     _dbl_bits(0x3cb0000000000000)

/*Maximum signed 8-bit integer (char)*/
#define _NUMERIC_CHAR_MAXIMUM_          \
     0x07f

/*Maximum signed 16-bit integer (short)*/
#define _NUMERIC_SHORT_MAXIMUM_         \
     0x7fff

/*Maximum signed 32-bit integer (int)*/
#define _NUMERIC_INT32_MAXIMUM_         \
     0x7fffffff

/*Maximum signed 64-bit integer (long long)*/
#define _NUMERIC_INT64_MAXIMUM_         \
     0x7fffffffffffffff

/*Main folder*/
#include "abs.hpp"
#include "float_class.hpp"
#include "gcf.hpp"
#include "lcm.hpp"
#include "log.hpp"
#include "rem.hpp"
#include "roots.hpp"
#include "sign.hpp"
#include "swap.hpp"

/*Trig folder*/
#include "trig/acos.hpp"
#include "trig/asin.hpp"
#include "trig/atan.hpp"
#include "trig/atan2.hpp"

/*** abs ***/
#ifdef _NECROMANCER_ABS_
     /*12/24/2023*/
     /*Get the absolute value of a 32-bit float _x*/
     constexpr float abs(const float& _x)
     {
          return necromancer_abs::
               absf(_x);
     }
     /*12/24/2023*/
     /*Get the absolute value of a 64-bit float _x*/
     constexpr double abs(const double& _x)
     {
          return necromancer_abs::
               absd(_x);
     }
     /*12/24/2023*/
     /*Get the absolute value of a 32-bit integer _x*/
     constexpr int abs(const int& _x)
     {
          return necromancer_abs::
               absi(_x);
     }
     /*12/24/2023*/
     /*Get the absolute value of a number _x*/
     template<typename _abs_ty>
     constexpr _abs_ty abs(const _abs_ty& _x)
     {
          return static_cast<_abs_ty>(necromancer_abs::
               absd(static_cast<double>(_x)));
     }
#else
     #warning "Could not get abs()"
#endif /*_NECROMANCER_ABS_*/

/*** float_class stuff ***/
#ifdef _NECROMANCER_FLOAT_CLASS_
     /*12/27/2023*/
     /*Classify a 32-bit float*/
     /*1: zero*/
     /*2: "Not a Number"*/
     /*3: Infinity*/
     /*4: -Infinity*/
     /*5: Normal float*/
     /*6: Subnormal float*/
     constexpr int classify(const float& _x)
     {
          return necromancer_float_class::
               classify_ieee754_32f(_x);
     }
     /*12/27/2023*/
     /*Classify a 64-bit float*/
     /*1: zero*/
     /*2: "Not a Number"*/
     /*3: Infinity*/
     /*4: -Infinity*/
     /*5: Normal float*/
     /*6: Subnormal float*/
     constexpr int classify(const double& _x)
     {
          return necromancer_float_class::
               classify_ieee754_64f(_x);
     }
     /*12/28/2023*/
     /*Classify a number _x as if it was a 64-bit float*/
     /*1: zero*/
     /*2: "Not a Number"*/
     /*3: Infinity*/
     /*4: -Infinity*/
     /*5: Normal float*/
     /*6: Subnormal float*/
     template<typename _classify_ty>
     int classify(const _classify_ty& _x)
     {
          return necromancer_float_class::
               classify_ieee754_64f(static_cast<double>(_x));
     }
     /*12/27/2023*/
     /*Return true if a 32-bit float is infinite*/
     constexpr bool is_inf(const float& _x)
     {
          return necromancer_float_class::
               is_inff(_x);
     }
     /*12/27/2023*/
     /*Return true if a 64-bit float is infinite*/
     constexpr bool is_inf(const double& _x)
     {
          return necromancer_float_class::
               is_infd(_x);
     }
     /*12/28/2023*/
     /*Return true if a number _x is infinite*/
     /*(Cast to Double)*/
     template<typename _inf_ty>
     constexpr bool is_inf(const _inf_ty& _x)
     {
          return necromancer_float_class::
               is_infd(static_cast<double>(_x));
     }
     /*12/27/2023*/
     /*Return true if a 32-bit float is finite*/
     constexpr bool is_finite(const float& _x)
     {
          return necromancer_float_class::
               is_finitef(_x);
     }
     /*12/27/2023*/
     /*Return true if a 64-bit float is finite*/
     constexpr bool is_finite(const double& _x)
     {
          return necromancer_float_class::
               is_finited(_x);
     }
     /*12/28/2023*/
     /*Return true if a number _x float is finite*/
     /*(Cast to Double)*/
     template<typename _finite_ty>
     constexpr bool is_finite(const _finite_ty& _x)
     {
          return necromancer_float_class::
               is_finited(static_cast<double>(_x));
     }
     /*12/27/2023*/
     /*Return true if a 32-bit float is "Not a Number"*/
     constexpr bool is_nan(const float& _x)
     {
          return necromancer_float_class::
               is_nanf(_x);
     }
     /*12/27/2023*/
     /*Return true if a 64-bit float is "Not a Number"*/
     constexpr bool is_nan(const double& _x)
     {
          return necromancer_float_class::
               is_nand(_x);
     }
     /*12/28/2023*/
     /*Return true if a number _x is "Not a Number"*/
     /*(Cast to Double)*/
     template<typename _nan_ty>
     constexpr bool is_nan(const _nan_ty& _x)
     {
          return necromancer_float_class::
               is_nand(static_cast<double>(_x));
     }
     /*12/27/2023*/
     /*Return true if a 32-bit float is positive*/
     constexpr bool is_positive(const float& _x)
     {
          return necromancer_float_class::
               is_positivef(_x);
     }
     /*12/27/2023*/
     /*Return true if a 64-bit float is positive*/
     constexpr bool is_positive(const double& _x)
     {
          return necromancer_float_class::
               is_positived(_x);
     }
     /*12/28/2023*/
     /*Return true if a number _x is positive*/
     /*(Cast to Double)*/
     template<typename _pos_ty>
     constexpr bool is_positive(const _pos_ty& _x)
     {
          return necromancer_float_class::
               is_positived(static_cast<double>(_x));
     }
     /*12/27/2023*/
     /*Return true if a 32-bit float is negative*/
     constexpr bool is_negative(const float& _x)
     {
          return necromancer_float_class::
               is_negativef(_x);
     }
     /*12/27/2023*/
     /*Return true if a 64-bit float is negative*/
     constexpr bool is_negative(const double& _x)
     {
          return necromancer_float_class::
               is_negatived(_x);
     }
     /*12/28/2023*/
     /*Return true if a number _x is negative*/
     /*(Cast to Double)*/
     template<typename _neg_ty>
     constexpr bool is_negative(const _neg_ty& _x)
     {
          return necromancer_float_class::
               is_negatived(static_cast<double>(_x));
     }
     /*12/27/2023*/
     /*Return true if a 32-bit float can be expressed as an integer*/
     constexpr bool is_int(const float& _x)
     {
          return necromancer_float_class::
               is_intf(_x);
     }
     /*12/27/2023*/
     /*Return true if a 64-bit float can be expressed as an integer*/
     constexpr bool is_int(const double& _x)
     {
          return necromancer_float_class::
               is_intd(_x);
     }
     /*12/28/2023*/
     /*Return true if a number _x can be expressed as an integer*/
     /*(Cast to Double)*/
     template<typename _int_ty>
     constexpr bool is_int(const _int_ty& _x)
     {
          return necromancer_float_class::
               is_intd(static_cast<double>(_x));
     }
     /*12/27/2023*/
     /*Return true if a 32-bit float cannot be expressed as an integer*/
     constexpr bool is_decimal(const float& _x)
     {
          return necromancer_float_class::
               is_decimalf(_x);
     }
     /*12/27/2023*/
     /*Return true if a 64-bit float cannot be expressed as an integer*/
     constexpr bool is_decimal(const double& _x)
     {
          return necromancer_float_class::
               is_decimald(_x);
     }
     /*12/28/2023*/
     /*Return true if a number _x cannot be expressed as an integer*/
     /*(Cast to Double)*/
     template<typename _dec_ty>
     constexpr bool is_decimal(const _dec_ty& _x)
     {
          return necromancer_float_class::
               is_decimald(_x);
     }
     /*12/27/2023*/
     /*Return the next representable 32-bit float after _x towards _y*/
     constexpr float nextafter(const float& _x, const float& _y)
     {
          return necromancer_float_class::
               nextafterf(_x, _y);
     }
     /*12/27/2023*/
     /*Return the next representable 64-bit float after _x towards _y*/
     constexpr double nextafter(const double& _x, const double& _y)
     {
          return necromancer_float_class::
               nextafterd(_x, _y);
     }
     /*12/28/2023*/
     /*Return the next representable 64-bit float after _x towards _y*/
     /*(Cast to Double)*/
     template<typename _next_ty>
     constexpr double nextafter(const _next_ty& _x, const _next_ty& _y)
     {
          return necromancer_float_class::
               nextafterd(static_cast<double>(_x),
                         static_cast<double>(_y));
     }
     /*12/27/2023*/
     /*Divide a 32-bit float by 2*/
     constexpr float flto2(const float& _x)
     {
          return necromancer_float_class::
               f32o2(_x);
     }
     /*12/27/2023*/
     /*Divide a 64-bit float by 2*/
     constexpr double flto2(const double& _x)
     {
          return necromancer_float_class::
               f64o2(_x);
     }
     /*12/28/2023*/
     /*Divide a number _x by 2*/
     /*(Cast to Double)*/
     template<typename _flto2_ty>
     constexpr double flto2(const _flto2_ty& _x)
     {
          return necromancer_float_class::
               f64o2(static_cast<double>(_x));
     }
#else
     /*This error has already been accounted for*/
#endif

/*** gcf ***/
#ifdef _NECROMANCER_GCF_
     /*12/24/2023*/
     /*Get the greatest common factor of two 32-bit ints _x and _y*/
     constexpr int gcf(const int& _x, const int& _y)
     {
          return necromancer_gcf::gcf(_x, _y);
     }
#else
     #warning "Could not get gcf()"
#endif /*_NECROMANCER_GCF_*/

/*** lcm ***/
#ifdef _NECROMANCER_LCM_
     /*12/24/2023*/
     /*Get the least common multiple of two 32-bit ints _x and _y*/
     constexpr int lcm(const int& _x, const int& _y)
     {
          return necromancer_lcm::lcm(_x, _y);
     }
#else
     #warning "Could not get lcm()"
#endif /*_NECROMANCER_LCM_*/

/*** logarithms ***/
#ifdef _NECROMANCER_LOG_
     /*** log ***/

     /*12/24/2023*/
     /*Compute the natural logarithm of a 32-bit float _x*/
     constexpr float log(const float& _x)
     {
          return necromancer_log::
               logf(_x);
     }
     /*12/24/2023*/
     /*Compute the natural logarithm of a 64-bit float _x*/
     constexpr double log(const double& _x)
     {
          return necromancer_log::
               logd(_x);
     }
     /*12/24/2023*/
     /*Compute the natural logarithm of a number _x*/
     /*(Cast to Double)*/
     template<typename _log_ty>
     constexpr double log(const _log_ty& _x)
     {
          return necromancer_log::
               logd(static_cast<double>(_x));
     }
     /*** log2 ***/

     /*12/24/2023*/
     /*Compute the base-2 logarithm of a 32-bit float _x*/
     constexpr float log2(const float& _x)
     {
          return necromancer_log::
               log2f(_x);
     }
     /*12/24/2023*/
     /*Compute the base-2 logarithm of a 64-bit float _x*/
     constexpr double log2(const double& _x)
     {
          return necromancer_log::
               log2d(_x);
     }
     /*12/24/2023*/
     /*Compute the base-2 logarithm of a number _x*/
     /*(Cast to Double)*/
     template<typename _log2_ty>
     constexpr double log2(const _log2_ty& _x)
     {
          return necromancer_log::
               log2d(static_cast<double>(_x));
     }
     /*** ilog2 ***/

     /*12/24/2023*/
     /*Return the integral part of the base-2 logarithm of a 32-bit float _x*/
     constexpr int ilog2(const float& _x)
     {
          return necromancer_log::
               ilog2f(_x);
     }
     /*12/24/2023*/
     /*Return the integral part of the base-2 logarithm of a 64-bit float _x*/
     constexpr int ilog2(const double& _x)
     {
          return necromancer_log::
               ilog2d(_x);
     }
     /*12/24/2023*/
     /*Return the integral part of the base-2 logarithm of a number _x*/
     /*(Cast to Double)*/
     template<typename _ilog2_ty>
     constexpr int ilog2(const _ilog2_ty& _x)
     {
          return necromancer_log::
               ilog2d(static_cast<double>(_x));
     }
     /*** log10 ***/

     /*12/24/2023*/
     /*Compute the base-10 logarithm of a 32-bit float _x*/
     constexpr float log10(const float& _x)
     {
          return necromancer_log::
               log10f(_x);
     }
     /*12/24/2023*/
     /*Compute the base-10 logarithm of a 64-bit float _x*/
     constexpr double log10(const double& _x)
     {
          return necromancer_log::
               log10d(_x);
     }
     /*12/24/2023*/
     /*Compute the base-10 logarithm of a number _x*/
     /*(Cast to Double)*/
     template<typename _log10_ty>
     constexpr double log10(const _log10_ty& _x)
     {
          return necromancer_log::
               log10d(static_cast<double>(_x));
     }
     /*** custom base logarithm ***/

     /*12/24/2023*/
     /*Return a logarithm with any base of 32-bit floats _x and _y*/
     /*_y is the base of the logarithm*/
     constexpr float log(const float& _x, const float& _y)
     {
          return necromancer_log::
               logf(_x, _y);
     }
     /*12/24/2023*/
     /*Return a logarithm with any base of 64-bit floats _x and _y*/
     /*_y is the base of the logarithm*/
     constexpr double log(const double& _x, const double& _y)
     {
          return necromancer_log::
               logd(_x, _y);
     }
     /*12/24/2023*/
     /*Return a logarithm with any base of numbers _x and _y*/
     /*_y is the base of the logarithm*/
     /*(Cast to Double)*/
     template<typename _log_ty>
     constexpr double log(const _log_ty& _x, const _log_ty& _y)
     {
          return necromancer_log::
               logd(static_cast<double>(_x),
                    static_cast<double>(_y));
     }

#else
     #warning "Could not get log(), log2(), ilog2(), or log10()"
#endif /*_NECROMANCER_LOG_*/

/*** rem ***/
#ifdef _NECROMANCER_REM_
     /*12/24/2023*/
     /*Get the remainder after dividing _x by _y*/
     constexpr float rem(const float& _x, const float& _y)
     {
          return necromancer_rem::
               remf(_x, _y);
     }
     /*12/24/2023*/
     /*Get the remainder after dividing _x by _y*/
     constexpr double rem(const double& _x, const double& _y)
     {
          return necromancer_rem::
               remd(_x, _y);
     }
     /*12/24/2023*/
     /*Get the remainder after dividing _x by _y*/
     constexpr int rem(const int& _x, const int& _y)
     {
          return _x % _y;
     }
#else
     #warning "Could not get rem()"
#endif /*_NECROMANCER_REM_*/

/*** sqrt ***/
#ifdef _NECROMANCER_ROOTS_
     /*12/24/2023*/
     /*Compute the square root of a 32-bit float _x*/
     constexpr float sqrt(const float& _x)
     {
          return necromancer_root::
               sqrtf(_x);
     }
     /*12/24/2023*/
     /*Compute the square root of a 64-bit float _x*/
     constexpr double sqrt(const double& _x)
     {
          return necromancer_root::
               sqrtd(_x);
     }
     /*12/24/2023*/
     /*Compute the square root of a number _x*/
     /*(Cast to Double)*/
     template<typename _sqrt_ty>
     constexpr double sqrt(const _sqrt_ty& _x)
     {
          return necromancer_root::
               sqrtd(static_cast<double>(_x));
     }
#else
     #warning "Could not get sqrt()"
#endif /*_NECROMANCER_ROOTS_*/

/*** sign functions ***/
#ifdef _NECROMANCER_SIGN_
     /*** sign ***/

     /*12/24/2023*/
     /*Get the sign of a 32-bit float _x*/
     constexpr int sign(const float& _x)
     {
          return necromancer_sign::
               signf(_x);
     }
     /*12/24/2023*/
     /*Get the sign of a 64-bit float _x*/
     constexpr int sign(const double& _x)
     {
          return necromancer_sign::
               signd(_x);
     }
     /*12/24/2023*/
     /*Get the sign of a number _x*/
     template<typename _sign_ty>
     constexpr int sign(const _sign_ty& _x)
     {
          return necromancer_sign::
               signd(static_cast<double>(_x));
     }
     /*** signbit ***/

     /*12/24/2023*/
     /*Get the sign bit of a 32-bit float _x*/
     constexpr int signbit(const float& _x)
     {
          return necromancer_sign::
               sign_bitf(_x);
     }
     /*12/24/2023*/
     /*Get the sign bit of a 64-bit float _x*/
     constexpr int signbit(const double& _x)
     {
          return necromancer_sign::
               sign_bitd(_x);
     }
     /*12/24/2023*/
     /*Get the sign bit of a number _x*/
     /*(Cast to Double)*/
     template<typename _signbit_ty>
     constexpr int signbit(const _signbit_ty& _x)
     {
          return necromancer_sign::
               sign_bitd(static_cast<double>(_x));
     }
     /*** copysign ***/

     /*12/24/2023*/
     /*Return a new 32-bit float with a magnitude of _x and a sign of _y*/
     constexpr float copysign(const float& _x, const float& _y)
     {
          return necromancer_sign::
               copysignf(_x, _y);
     }
     /*12/24/2023*/
     /*Return a new 64-bit float with the magnitude of _x and the sign of _y*/
     constexpr double copysign(const double& _x, const double& _y)
     {
          return necromancer_sign::
               copysignd(_x, _y);
     }
     /*12/24/2023*/
     /*Return a new integer with the magnitude of _x and the sign of _y*/
     /*(Cast to Double)*/
     constexpr int copysign(const int& _x, const int& _y)
     {
          return necromancer_sign:: 
               copysignd(static_cast<double>(_x),
                    static_cast<double>(_y));
     }
     /*12/24/2023*/
     /*Return a new number with the magnidute of _x and the sign of _y*/
     /*(Cast to Double)*/
     template<typename _copysign_ty>
     constexpr _copysign_ty copysign(const _copysign_ty& _x, const _copysign_ty& _y)
     {
          return static_cast<_copysign_ty>(necromancer_sign::
               copysignd(static_cast<double>(_x),
                    static_cast<double>(_y)));
     }
#else
     #warning "Could not get signbit(), sign(), or copysign()"
#endif /*_NECROMANCER_SIGN_*/

/*** swap ***/
#ifdef _NECROMANCER_SWAP_
     /*12/22/2023*/
     /*This does what you think it does*/
     template<typename _swap_ty>
     void swap(_swap_ty& _x, _swap_ty& _y)
     {
          return necromancer_swap::
               swap(_x, _y);
     }
#else     
     #warning "Could not get swap()"
#endif /*_NECROMANCER_SWAP*/

/*** Trig functions ***/

/*** acos ***/
#ifdef _NECROMANCER_ACOS_
     /*12/24/2023*/
     /*Compute the arccosine of a 32-bit float _x*/
     constexpr float acos(const float& _x)
     {
          return necromancer_acos::acosf(_x);
     }
     /*12/24/2023*/
     /*Compute the arccosine of a 64-bit float _x*/
     constexpr double acos(const double& _x)
     {
          return necromancer_acos:: 
               acosd(_x);
     }
     /*12/24/2023*/
     /*Compute the arccosine of a number _x*/
     /*(Cast to double)*/
     template<typename _acos_ty>
     constexpr double acos(const _acos_ty& _x)
     {
          return necromancer_acos::
               acosd(static_cast<double>(_x));
     }
#else
     #warning "Could not get acos()"
#endif /*_NECROMANCER_ACOS_*/

/*** asin ***/
#ifdef _NECROMANCER_ASIN_
     /*12/24/2023*/
     /*Compute the arcsine of a 32-bit float _x*/
     constexpr float asin(const float& _x)
     {
          return necromancer_asin::
               asinf(_x);
     }
     /*12/24/2023*/
     /*Compute the arcsine of a 64-bit float _x*/
     constexpr double asin(const double& _x)
     {
          return necromancer_asin::
               asind(_x);
     }
     /*12/24/2023*/
     /*Compute the arcsine of a number _x*/
     /*(Cast to double)*/
     template<typename _asin_ty>
     constexpr double asin(const _asin_ty& _x)
     {
          return necromancer_asin::
               asind(static_cast<double>(_x));
     }
#else
     #warning "Could not get asin()"
#endif /*_NECROMANCER_ASIN_*/

/*** atan ***/
#ifdef _NECROMANCER_ATAN_
     /*12/24/2023*/
     /*Compute the arctangent of a 32-bit float _x*/
     constexpr float atan(const float& _x)
     {
          return necromancer_atan::
               atanf(_x);
     }
     /*12/24/2023*/
     /*Compute the arctangent of a 64-bit float _x*/
     constexpr double atan(const double& _x)
     {
          return necromancer_atan::
               atand(_x);
     }
     /*12/24/2023*/
     /*Compute the arctangent of a number _x*/
     /*(Cast to Double)*/
     template<typename _atan_ty>
     constexpr double atan(const _atan_ty& _x)
     {
          return necromancer_atan::
               atand(static_cast<double>(_x));
     }
#else
     #warning "Could not get atan()"
#endif /*_NECROMANCER_ATAN_*/

/*** atan2 ***/
#ifdef _NECROMANCER_ATAN2_
     /*12/24/2023*/
     /*Figure out what it does; it's not my job to tell you*/
     constexpr float atan2(const float& _y, const float& _x)
     {
          return necromancer_atan2::
               atan2f(_y, _x);
     }
     /*12/24/2023*/
     /*Figure out what it does; it's not my job to tell you*/
     constexpr double atan2(const double& _y, const double& _x)
     {
          return necromancer_atan2::
               atan2d(_y, _x);
     }
     /*12/24/2023*/
     /*Figure out what it does; it's not my job to tell you*/
     template<typename _atan2_ty>
     constexpr double atan2(const _atan2_ty& _x, const _atan2_ty& _y)
     {
          return necromancer_atan2::
               atan2d(static_cast<double>(_x),
                    static_cast<double>(_y));
     }
#else
     #warning "Could not get atan2()"
#endif /*_NECROMANCER_ATAN2_*/

/*** Variable argument functions ***/

#define _num_args(_type, ...)           \
     (sizeof((_type[]){0, ##__VA_ARGS__}) / sizeof(_type) - 1)
#define _arg_array(_type, ...)          \
     ((_type[]){##__VA_ARGS__})
/*12/28/2023*/
/*Return the number of arguments passed into this function*/
/*Might be useful???*/
template<typename _arg_ty = double, typename... _args>
constexpr int num_args(_args... _arg)
{
     return _num_args(_arg_ty, _arg...);
}

#endif /*_MATH_SORCERY_*/