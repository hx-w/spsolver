/**
 * matrix base model
 */

#ifndef XMAT_MATRIX_BASE_H
#define XMAT_MATRIX_BASE_H

#include <istream>
#include <vector>

#include "ref.h"

namespace XMAT {

template <class T>
// math matrix base model virtual class
class MatrixBase {
public:
    // constructor
    MatrixBase() = default;
    MatrixBase(__INDX, __INDX) = 0;
    MatrixBase(const MatrixBase<T> &m) = default;
    MatrixBase(MatrixBase<T> &&m) = default;

    virtual T& operator()(__INDX, __INDX) = 0;
    virtual const T& operator()(__INDX, __INDX) const = 0;
    virtual const T& at(__INDX, __INDX) const = 0;

    // matrix shape
    virtual __INDX rows() const = 0;
    virtual __INDX cols() const = 0;

    // basic operators
    virtual MatrixBase<T>& operator=(const MatrixBase<T> &m) = 0;
    virtual MatrixBase<T>& operator+(const MatrixBase<T>&) = 0;
    virtual MatrixBase<T>& operator-(const MatrixBase<T>&) = 0;
    virtual MatrixBase<T>& operator*(const MatrixBase<T>&) = 0;
    virtual MatrixBase<T>& operator+=(const MatrixBase<T>&) = 0;
    virtual MatrixBase<T>& operator-=(const MatrixBase<T>&) = 0;
    virtual MatrixBase<T>& operator*=(const MatrixBase<T>&) = 0;

    virtual MatrixBase<T>& operator+(const Scalar&) = 0;
    virtual MatrixBase<T>& operator-(const Scalar&) = 0;
    virtual MatrixBase<T>& operator*(const Scalar&) = 0;
    virtual MatrixBase<T>& operator/(const Scalar&) = 0;
    virtual MatrixBase<T>& operator+=(const Scalar&) = 0;
    virtual MatrixBase<T>& operator-=(const Scalar&) = 0;
    virtual MatrixBase<T>& operator*=(const Scalar&) = 0;
    virtual MatrixBase<T>& operator/=(const Scalar&) = 0;

    // stream input
    // friend std::istream& operator>>(std::istream&, MatrixBase<T>&);

    // slice
    virtual MatrixBase<T>& slice(__INDX, __INDX, __INDX, __INDX) const = 0;
    // slice with axis
    virtual MatrixBase<T>& slice(std::vector<__INDX>&, int) = 0;

    virtual MatrixBase<T>& transpose() = 0;

    virtual MatrixBase<T>& inverse() = 0;

    virtual Scalar det() const = 0;

    virtual __INDX rank() const = 0;
};


}


#endif
