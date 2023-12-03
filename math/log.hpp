/*The Math Necromancer*/

/*============ The Natural Logarithm ============*/
/*Computes log(x) on an IEEE-754 Machine (Not yet to good Precision)*/

/*This is only a start on it, I will optimize it more later on*/

#ifndef _LOG_X_
#define _LOG_X_

#include "float_class.hpp"
#include <iomanip>
#include <iostream>

const static long double
     log2_h = 6.93147180369123816490e-01,
     log2_l = 1.90821492927232121458e-10,

     /*I found these on some random stack exchange*/
     // log1 = 6.66666666666667653654896829047862109605e-01,
     // log2 = 3.99999999996639180070480580779767357622e-01,
     // log3 = 2.85714286985476106491309914245597720749e-01,
     // log4 = 2.22222024077476110197597399876978069272e-01,
     // log5 = 1.81833876328594532366358057253631240618e-01,
     // log6 = 1.53181571233880298729095145342556944283e-01,
     // log7 = 1.47580071554569676223389696418304199218e-01;

     log1 = 6.66666666666666666666666666666666666666e-01,
     log2 = 4.00000000000000000000000000000000000000e-01,
     log3 = 2.85714285714285714285714285714285714285e-01,
     log4 = 2.22222222222222222222222222222222222222e-01,
     log5 = 1.81818181818181818181818181818181818181e-01,
     log6 = 0.15384615384615384615384615384615384615e-01,
     log7 = 1.33333333333333333333333333333333333333e-01;

#define LOG_2  6.93147180559945309417232121458176568075e-01;

/*Compute the Natural Logarithm of _x*/

/*Reduce the Range of _x*/
/*   Given an IEEE-754 Machine, find an f and e where _x = f * 2^e:*/
/*        sqrt(2)/2 < f < sqrt(2)*/
/*   log(x) = log(f * 2^e) = (log(f) + elog(2)) via properties of log(x)*/
/*   Solution: Set y to the exponent part of a Floating point value. Now calculate*/
/*   log(f) and let log(2) be a constant - now elog(2) is constant*/
/*   Return log(f) + elog(2)*/
/*   Remember, e is not Euler's number in this situation*/

/*Compute the Natural Logarithm of _x*/
float logf(const float& _x)
{
     float_32 _i;
     _i._x = _x;
     /*Special Cases...*/
     if(_i._y == 0x7f800000)
          /*log(inf) = inf*/
          return INFINITYf;
     if(!(_i._y | 0x000))
          /*log(0^+) -> -inf*/
          return NEGATIVE_INFINITYf;
     if(_i._f_32._sign)
          /*log(_x) for _x < 0 is undefined / complex*/
          return NaNf;
     float _e, _f, _s, _z, _z2, _t1, _t2, _r, _hfsq;
     _e = _i._f_32._exp - 0x07e;
     _i._f_32._exp = 0x07e;
     _f = _i._x;
     if(_i._f_32._mantissa < 0x3504f3)
     {
          _f *= 2;
          _e --;
     }
     _f --;
     _s = _f / (_f + 0x002);
     _z = _s * _s;
     _z2 = _z * _z;
     _t1 = _z * (log1 + _z2 * (log3 + _z2 * (log5 + _z2 * log7)));
     _t2 = _z2 * (log2 + _z2 * (log4 + _z2 * log6));
     _r = _t1 * _t2;
     _hfsq = 0.5f * _f * _f;
     /*We can't just return _e * log(2). It isn't precise enough*/
     return _e * log2_h - ((_hfsq - (_s * (_hfsq + _r) + _e * log2_l)) - _f);
}

double logd(const double& _x)
{
     float_64 _i;
     _i._x = _x;
     if(_i._y == 0x7ff0000000000000)
          return INFINITY;
     if(!(_i._y | 0x000))
          return NEGATIVE_INFINITY;
     if(_i._f_64._sign)
          return NaN;
     double _e, _f, _s, _z, _z2, _t1, _t2, _r, _hfsq;
     _e = _i._f_64._exp - 0x03fe;
     _i._f_64._exp = 0x03fe;
     _f = _i._x;
     if(_i._f_64._mantissa < 0x3ff6a09e667f3bcd)
     {
          _f *= 2;
          _e --;
     }
     _f --;
     _s = _f / (_f + 0x002) ;
     _z = _s * _s;
     _z2 = _z * _z;
     _t1 = _z * (log1 + _z2 * (log3 + _z2 * (log5 + _z2 * log7)));
     _t2 = _z2 * (log2 + _z2 * (log4 + _z2 * log6));
     _r = _t1 * _t2;
     _hfsq = 0.5 * _f * _f;
     /*We can't just return _e * log(2). It isn't precise enough*/
     return _e * log2_h - ((_hfsq - (_s * (_hfsq + _r) + _e * log2_l)) - _f);
}
#endif /*_LOG_X_*/