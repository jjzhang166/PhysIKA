/*
 * @file vector_2d.cpp 
 * @brief 2d vector.
 * @author Fei Zhu
 * 
 * This file is part of Physika, a versatile physics simulation library.
 * Copyright (C) 2013 Physika Group.
 *
 * This Source Code Form is subject to the terms of the GNU General Public License v2.0. 
 * If a copy of the GPL was not distributed with this file, you can obtain one at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 *
 */

#include <cmath>
#include "Physika_Core/Vectors/vector_2d.h"

namespace Physika{

template <typename Scalar>
Vector2D<Scalar>::Vector2D()
{
}

template <typename Scalar>
Vector2D<Scalar>::Vector2D(Scalar x, Scalar y)
{
#ifdef PHYSIKA_USE_EIGEN_VECTOR
    eigen_vector_2x_(0)=x;
    eigen_vector_2x_(1)=y;
#endif
}

template <typename Scalar>
Vector2D<Scalar>::Vector2D(Scalar x)
{
#ifdef PHYSIKA_USE_EIGEN_VECTOR
    eigen_vector_2x_(0)=x;
    eigen_vector_2x_(1)=x;
#endif
}

template <typename Scalar>
Vector2D<Scalar>::Vector2D(const Vector2D<Scalar> &vec2)
{
    *this = vec2;
}

template <typename Scalar>
Vector2D<Scalar>::~Vector2D()
{
}

template <typename Scalar>
Vector2D<Scalar>& Vector2D<Scalar>::derived()
{
    return dynamic_cast<Vector2D<Scalar>&>(*this);
}

template <typename Scalar>
const Vector2D<Scalar>& Vector2D<Scalar>::derived() const
{
    return dynamic_cast<const Vector2D<Scalar>&>(*this);
}

template <typename Scalar>
Scalar& Vector2D<Scalar>::operator[] (int idx)
{
#ifdef PHYSIKA_USE_EIGEN_VECTOR
    return eigen_vector_2x_(idx);
#endif
}

template <typename Scalar>
const Scalar& Vector2D<Scalar>::operator[] (int idx) const
{
#ifdef PHYSIKA_USE_EIGEN_VECTOR
    return eigen_vector_2x_(idx);
#endif
}

template <typename Scalar>
Vector2D<Scalar> Vector2D<Scalar>::operator+ (const Vector2D<Scalar> &vec2) const
{
    Scalar result[2];
    for(int i = 0; i < 2; ++i)
        result[i] = (*this)[i] + vec2[i];
    return Vector2D<Scalar>(result[0],result[1]);
}

template <typename Scalar>
Vector2D<Scalar>& Vector2D<Scalar>::operator+= (const Vector2D<Scalar> &vec2)
{
    for(int i = 0; i < 2; ++i)
        (*this)[i] = (*this)[i] + vec2[i];
    return *this;
}

template <typename Scalar>
Vector2D<Scalar> Vector2D<Scalar>::operator- (const Vector2D<Scalar> &vec2) const
{
    Scalar result[2];
    for(int i = 0; i < 2; ++i)
        result[i] = (*this)[i] - vec2[i];
    return Vector2D<Scalar>(result[0],result[1]);
}

template <typename Scalar>
Vector2D<Scalar>& Vector2D<Scalar>::operator-= (const Vector2D<Scalar> &vec2)
{
    for(int i = 0; i < 2; ++i)
        (*this)[i] = (*this)[i] - vec2[i];
    return *this;
}

template <typename Scalar>
Vector2D<Scalar>& Vector2D<Scalar>::operator= (const Vector2D<Scalar> &vec2)
{
    for(int i = 0; i < 2; ++i)
        (*this)[i] = vec2[i];
    return *this;
}

template <typename Scalar>
bool Vector2D<Scalar>::operator== (const Vector2D<Scalar> &vec2) const
{
    for(int i = 0; i < 2; ++i)
        if((*this)[i] != vec2[i])
            return false;
    return true;
}

template <typename Scalar>
Vector2D<Scalar> Vector2D<Scalar>::operator* (Scalar scale) const
{
    Scalar result[2];
    for(int i = 0; i < 2; ++i)
        result[i] = (*this)[i] * scale;
    return Vector2D<Scalar>(result[0],result[1]);
}

template <typename Scalar>
Vector2D<Scalar>& Vector2D<Scalar>::operator*= (Scalar scale)
{
    for(int i = 0; i < 2; ++i)
        (*this)[i] = (*this)[i] * scale;
    return *this;
}

template <typename Scalar>
Vector2D<Scalar> Vector2D<Scalar>::operator/ (Scalar scale) const
{
    Scalar result[2];
    for(int i = 0; i < 2; ++i)
        result[i] = (*this)[i] / scale;
    return Vector2D<Scalar>(result[0],result[1]);
}

template <typename Scalar>
Vector2D<Scalar>& Vector2D<Scalar>::operator/= (Scalar scale)
{
    for(int i = 0; i < 2; ++i)
        (*this)[i] = (*this)[i] / scale;
    return *this;
}

template <typename Scalar>
Scalar Vector2D<Scalar>::norm() const
{
    Scalar result = (*this)[0]*(*this)[0] + (*this)[1]*(*this)[1];
    result = sqrt(result);
    return result;
}

template <typename Scalar>
Vector2D<Scalar>& Vector2D<Scalar>::normalize()
{
    Scalar norm = (*this).norm();
    if(norm)
    {
        for(int i = 0; i < 2; ++i)
        (*this)[i] = (*this)[i] / norm;
    }
    return *this;
}

template <typename Scalar>
Scalar Vector2D<Scalar>::cross(const Vector2D<Scalar>& vec2) const
{
  return (*this)[0]*vec2[1] - (*this)[1]*vec2[0];
}

template <typename Scalar>
Vector2D<Scalar> Vector2D<Scalar>::operator-(void) const
{
    return Vector2D<Scalar>(-(*this)[0],-(*this)[1]);
}

template <typename Scalar>
Scalar Vector2D<Scalar>::dot(const Vector2D<Scalar>& vec2) const
{
    return (*this)[0]*vec2[0] + (*this)[1]*vec2[1];
}

//explicit instantiation of template so that it could be compiled into a lib
template class Vector2D<float>;
template class Vector2D<double>;

} //end of namespace Physika
