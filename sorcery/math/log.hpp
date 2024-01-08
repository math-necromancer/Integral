/*The Math Necromancer*/

/*double precision log(x)*/

#ifndef _NECROMANCER_LOG_
#define _NECROMANCER_LOG_

#ifndef _MATH_SORCERY_
     #error This file won't work if you don't include "math_sorcery.hpp"!
#else
     #include "float_class.hpp"
     namespace necromancer_log
     {
          const static double
               /*Doubles to make log(2) better than a single number*/
               /*Their sum is more accurate than the double log(2)*/
               _log2_h = 6.931471805599453e-01,
               _log2_l = 9.417232121458000e-18;
          const static double
               /*Minimax coeficcients for 2 * arctanh(x)*/  
               _log1 = 6.666666666666735130e-01, 
               _log2 = 3.999999999940941908e-01,
               _log3 = 2.857142874366239149e-01, 
               _log4 = 2.222219843214978396e-01,
               _log5 = 1.818357216161805012e-01,
               _log6 = 1.531383769920937332e-01,
               _log7 = 1.479819860511658591e-01;
          const static double 
               two24 = 0x1000000,
               two54 = 0x40000000000000;
          /*Compute the Natural Logarithm of _x*/
          /*Reduce the Range of _x*/
          /*   Given an IEEE-754 Machine, find an f and e where _x = (f + 1) * 2^e:*/
          /*        sqrt(2)/2 < (f - 1) < sqrt(2)*/
          /*   log(x) = log((f - 1) * 2^e) = (log(f - 1) + elog(2)) via properties of log(x)*/
          /*   Solution: Set y to the exponent part of a Floating point value. Now calculate*/
          /*   log(f - 1) and let log(2) be a constant - now elog(2) is constant. For _f, it*/
          /*   is simply a modification of the Mantissa of _x after setting the exponent correctly*/
          /*   Return log(f + 1) + elog(2)*/
          /*   Remember, e is not Euler's number in this situation*/
          /*Computation of log(f - 1)*/
          /*   The informed reader may recall that log(_x) = 2 * arctanh((_x - 1) / (_x + 1))*/
          /*   We will use a polynomial of degree 15 to approximate 2 arctanh().*/
          /*                 1        3        5        7   */
          /*   arctanh(x) = x + (1/3)x + (1/5)x + (1/7)x ...*/
          /*   This is the formula shown in the functions below. We put in _f / (_f + 2), as*/
          /*   _f has been decremented. Then we just return our result scaled back up*/

          /*** log ~ ln ***/

          /*12/24/2023*/
          constexpr float logf(const float& _x)
          {
               float_32 _i = {_x};
               /*Special Cases...*/
               /*log(1) = 0*/
               if(_i._y == 0x3f800000)
                    return 0.0f;
               /*log(inf) = inf*/
               if(_i._y == 0x7f800000)
                    return sorcery::INFINITYf;
               /*log(0^+) -> -inf*/
               if(_i._y == 0)
                    return sorcery::NEGATIVE_INFINITYf;
               /*log(_x) for _x < 0 or is_nan(_x) is undefined; this includes -0*/
               if(_i._y > 0x7f800000)
                    return sorcery::NaNf;
               int _e = 0;
               if(_i._f_32._exp == 0)
               {
                    _e -= 24;
                    _i._x *= two24;
               }
               _e += _i._f_32._exp - 0x07e;
               _i._f_32._exp = 0x07e;
               float _f = _i._x;
               /*Reduce the range of _f further*/
               if(_i._f_32._mantissa < 0x3504f3)
               {
                    _f *= 2;
                    _e --;
               }
               _f --;
               float _s = _f / (_f + 2.0f);
               float _z = _s * _s;
               float _z2 = _z * _z;
               float _t1 = _z * (_log1 + _z2 * (_log3 + _z2 * (_log5 + _z2 * _log7)));
               float _t2 = _z2 * (_log2 + _z2 * (_log4 + _z2 * _log6));
               float _r = _t1 + _t2;
               float _hfsq = 0.5f * _f * _f;
               /*We can't just return _r + _e * log(2). It isn't precise enough*/
               return _e * _log2_h - ((_hfsq - (_s * (_hfsq + _r) + _e * _log2_l)) - _f);
          }
          /*12/24/2023*/
          constexpr double logd(const double& _x)
          {
               float_64 _i = {_x};
               /*Special Cases*/
               /*log(1) = 0.0*/
               if(_i._y == 0x3ff0000000000000)
                    return 0.0;
               /*log(inf) = inf*/
               if(_i._y == 0x7ff0000000000000)
                    return sorcery::INFINITY;
               /*log(0^+) -> -inf*/
               if(_i._y == 0)
                    return sorcery::NEGATIVE_INFINITY;
               /*log(_x) for _x < 0 or is_nan(_x) is undefined; this includes -0*/
               if(_i._y > 0x7ff0000000000000)
                    return sorcery::NaN;
               int _e = 0;
               if(_i._f_64._exp == 0)
               {
                    _e -= 54;
                    _i._x *= two54;
               }
               _e += _i._f_64._exp - 0x03fe;
               _i._f_64._exp = 0x03fe;
               double _f = _i._x;
               /*Reduce the range of _f further*/
               if(_i._f_64._mantissa < 0x3ff6a09e667f3bcd)
               {
                    _f *= 2;
                    _e --;
               }
               _f --;
               double _s = _f / (_f + 2.0);
               double _z = _s * _s;
               double _z2 = _z * _z;
               double _t1 = _z * (_log1 + _z2 * (_log3 + _z2 * (_log5 + _z2 * _log7)));
               double _t2 = _z2 * (_log2 + _z2 * (_log4 + _z2 * _log6));
               double _r = _t1 + _t2;                           
               double _hfsq = 0.5 * _f * _f;
               /*We can't just return _r + _e * log(2). It isn't precise enough*/
               return _e * _log2_h - ((_hfsq - (_s * (_hfsq + _r) + _e * _log2_l)) - _f);
          }
          /*** log2 ***/

          /*12/24/2023*/
          constexpr float log2f(const float& _x)
          {
               return logf(_x) * 1.442695f;
          }
          /*12/24/2023*/
          constexpr double log2d(const double& _x)
          {
               return logd(_x) * 1.4426950408889634;
          }
          /*** ilog2 ~ the integral part of log2(x) ***/

          /*12/24/2023*/
          /*int return type is safe because log2(~3.402e+38) = 128*/
          constexpr int ilog2f(const float& _x)
          {
               float_32 _i = {_x};
               return _i._f_32._exp - 0x07f;
          }
          /*12/24/2023*/
          /*int return type is safe because log2(~1.797e+308) = 1024*/
          constexpr int ilog2d(const double& _x)
          {
               float_64 _i = {_x};
               return _i._f_64._exp - 0x3ff;
          }

          /*** log10 ***/

          /*12/24/2023*/
          constexpr float log10f(const float& _x)
          {
               return logf(_x) * 0.434294492f;
          }
          /*12/24/2023*/
          constexpr double log10d(const double& _x)
          {
               return logd(_x) * 0.4342944819032518;
          }

          /*** custom base log ***/

          /*12/24/2023*/
          constexpr float logf(const float& _x, const float& _y)
          {
               return logf(_x) / logf(_y);
          }
          /*12/24/2023*/
          constexpr double logd(const double& _x, const double& _y)
          {
               return logd(_x) / logd(_y);
          }
     } 
#endif /*_MATH_SORCERY_*/

  

#endif /*_NECROMANCER_LOG_*/