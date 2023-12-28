/*The Math Necromancer*/

#ifndef _NECROMANCER_SIGN_
#define _NECROMANCER_SIGN_

#include "float_class.hpp"

#ifndef _MATH_SORCERY_
    #ifdef _RAW_FILE_WARN_
        #warning "Are you sure you want to use this raw file instead of math_sorcery.hpp?"
    #endif /*_RAW_FILE_WARN_*/
#endif /*_MATH_SORCERY_*/

namespace necromancer_sign
{
     using namespace necromancer_float_class;
     /*12/24/2023*/
     constexpr int sign_bitf(const float& _x)
     {
          float_32 _i = {_x};
          return _i._f_32._sign;
     }
     /*12/24/2023*/
     constexpr int sign_bitd(const double& _x)
     {
          float_64 _i = {_x};
          return _i._f_64._sign;
     }

     /*12/24/2023*/
     constexpr int signf(const float& _x)
     {
          float_32 _i = {_x};
          return _i._f_32._sign? -1: 1;
     }
     /*12/10/2023*/
     constexpr int signd(const double& _x)
     {
          float_64 _i = {_x};
          return _i._f_64._sign? -1: 1;
     }

     /*12/24/2023*/
     constexpr float copysignf(const float& _x, const float& _y)
     {
          float_32 _ix = {_x};
          float_32 _iy = {_y};
          /*|_x| OR sign_bit(_y)*/
          _ix._y = (_ix._y & 0x7fffffff) | (_iy._y & 0x80000000);
          return _ix._x;
     }
     /*12/24/2023*/
     constexpr double copysignd(const double& _x, const double& _y)
     {
          float_64 _ix = {_x};
          float_64 _iy = {_y};
          /*|_x| OR sign_bit(_y)*/
          _ix._y = (_ix._y & 0x7fffffffffffffff) | (_iy._y & 0x8000000000000000);
          return _ix._x;
     }
}

#endif /*_NECROMANCER_SIGN_*/