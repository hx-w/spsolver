/**
 * vector base model
 */

#ifndef XMAT_VEC_BASE_H
#define XMAT_VEC_BASE_H


#include <istream>
#include <vector>

#include "ref.h"

namespace XMAT {

template <class T>
// math vector base model virtual class
class VecBase {
public:
    // constructor
    VecBase() = default;
    VecBase(const VecBase<T> &v) = default;
    VecBase(VecBase<T> &&v) = default;

    VecBase(__INDX);
    VecBase(const std::vector<T> &);
    
    virtual T& operator[](__INDX) = 0;
    virtual T& operator()(__INDX) = 0;
    virtual const T& operator[](__INDX) const = 0;
    virtual const T& operator()(__INDX) const = 0;
    virtual const T& at(__INDX) const = 0;

    virtual __INDX size() const = 0;

    // basic operators
    bool operator==(const VecBase<T> &v) const;
    VecBase<T>& operator=(const VecBase<T>&);
    VecBase<T>& operator+(const VecBase<T>&) const;
    VecBase<T>& operator-(const VecBase<T>&) const;
    Scalar operator*(const VecBase<T>&) const;
    
    VecBase<T>& operator+=(const VecBase<T>&);
    VecBase<T>& operator-=(const VecBase<T>&);

    VecBase<T>& operator+(const Scalar&);
    VecBase<T>& operator-(const Scalar&);
    VecBase<T>& operator*(const Scalar&);

    VecBase<T>& operator+=(const Scalar&);
    VecBase<T>& operator-=(const Scalar&);
    VecBase<T>& operator*=(const Scalar&);

    virtual Scalar norm() const = 0;
    virtual VecBase<T>& normalize() = 0;

    virtual Scalar dot(const VecBase<T>&) const = 0;
    // virtual VecBase<T>& cross(const VecBase<T>&) const;

    // slice
    // virtual VecBase<T>& slice(__INDX, __INDX) const;
    // virtual VecBase<T>& slice(const std::vector<__INDX>&) const;

private:
    std::vector<T> m_data;
    __INDX m_size;
};

}
#endif
