/*The Math Necromancer*/

#ifndef _NECROMANCER_SIN_COS_
#define _NECROMANCER_SIN_COS_

#include "../float_class.hpp"
#include "../sign.hpp"
#include "../rem.hpp"

/*#defines for pi and tau, used when this file has no incoming definition*/
#ifndef pi
     #define pi 3.1415926535897932384
#endif /*pi*/
#ifndef tau
     #define tau 6.2831853071795864769
#endif /*tau*/
#ifndef pi_2
     #define pi_2 1.5707963267948966192
#endif /*pi_2*/

/*Courtesy of fdlibm for these constants*/
/* ====================================================
* Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
*
* Developed at SunSoft, a Sun Microsystems, Inc. business.
* Permission to use, copy, modify, and distribute this
* software is freely granted, provided that this notice 
* is preserved.
* ====================================================
*/

const static double
     _sin1 = -1.66666666666666324348e-01,
     _sin2 = 8.33333333332248946124e-03,
     _sin3 = -1.98412698298579493134e-04,
     _sin4 = 2.75573137070700676789e-06,
     _sin5 = -2.50507602534068634195e-08,
     _sin6 = 1.58969099521155010221e-10;
const static double
     _cos1 = 4.16666666666666019037e-02,
     _cos2 = -1.38888888888741095749e-03,
     _cos3 = 2.48015872894767294178e-05,
     _cos4 = -2.75573143513906633035e-07,
     _cos5 = 2.08757232129817482790e-09,
     _cos6 = -1.13596475577881948265e-11;
const static double _4opi = 1.2732395447351626862;

namespace necromancer_sin
{
     using namespace necromancer_float_class;
     using namespace necromancer_sign;
     /*12/21/2023*/
     /*We assume that |_x| is within pi/4*/
     float sinf_in_pio4(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          float _z, _r;
          /*|_x|*/
          _i._y &= 0x7fffffff;
          /*|_x| < 2^-8, we return _x as it's sin(x) in single precision*/
          if(_i._y <= 0x3b800000)
               return _x;
          _z = _i._x * _i._x;
          _r = _i._x + _i._x * _z * (_sin1 + _z * (_sin2 + _z * (_sin3 + _z *
               (_sin4 + _z * (_sin5 + _z * _sin6)))));
          /*sin(-x) = -sin(x)*/
          return copysignf(_r, _x);
     }
     /*12/21/2023*/
     /*We assume that |_x| is within pi/4*/
     double sind_in_pio4(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          double _z, _r;
          /*|_x|*/
          _i._y &= 0x7fffffffffffffff;
          /*|_x| < 2^-16, we return _x as it's sin(x) in double precision*/
          if(_i._y < 0x3ef0000000000000)
               return _x;
          _z = _i._x * _i._x;
          _r = _i._x + _i._x * _z * (_sin1 + _z * (_sin2 + _z * (_sin3 + _z *
               (_sin4 + _z * (_sin5 + _z * _sin6)))));
          /*sin(-x) = -sin(x)*/
          return copysignd(_r, _x);
     }
     /*12/21/2023*/
     /*We assume that |_x| is within pi/4*/
     float cosf_in_pio4(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          float _z, _r;
          /*|_x|*/
          _i._y &= 0x7fffffff;
          _z = _i._x * _i._x;
          _r = 1.0f + _z * (0.5 + _z * (_cos1 + _z * (_cos2 + _z *
               (_cos3 + _z * (_cos4 + _z * (_cos5 + _z * _cos6))))));
          /*No need for copysign because cos(-x) = cos(x)*/
          return _r;
     }
     /*12/21/2023*/
     /*We assume that |_x| is within pi/4*/
     double cosd_in_pio4(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          double _z, _r;
          /*|_x|*/
          _i._y &= 0x7fffffffffffffff;
          _z = _i._x * _i._x;
          _r = 1.0f + _z * (0.5 + _z * (_cos1 + _z * (_cos2 + _z *
               (_cos3 + _z * (_cos4 + _z * (_cos5 + _z * _cos6))))));
          /*No need for copysign because cos(-x) = cos(x)*/
          return _r;
     }
}

#endif /*_NECROMANCER_SIN_COS_*/