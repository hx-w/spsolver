/**
 * @brief 1D vector class
 */

#ifndef XMAT_VEC_HPP
#define XMAT_VEC_HPP

#include <cassert>
#include <cmath>
#include <numeric>
#include <vector>

#include "base/vec_base.h"

namespace XMAT {

template <class T>
class Vec : public VecBase<T> {
public:
    Vec() : m_size(0){};
    Vec(const Vec<T>& v) : m_size(v.m_size), m_data(v.m_data){};
    Vec(Vec<T>&& v) : m_size(v.m_size), m_data(std::move(v.m_data)){};

    Vec(__INDX n) : m_size(n), m_data(n) {}
    Vec(const std::vector<T>& v) : m_size(v.size()), m_data(v) {}
    Vec(std::initializer_list<T>&& v) : m_size(v.size()), m_data(v) {}

    T& operator[](__INDX i) override { return m_data[i]; }
    T& operator()(__INDX i) override { return m_data[i]; }
    const T& operator[](__INDX i) const override { return m_data[i]; }
    const T& operator()(__INDX i) const override { return m_data[i]; }
    const T& at(__INDX i) const override { return m_data.at(i); }

    __INDX size() const override { return m_data.size(); }

    // basic operators
    bool operator==(const Vec<T>& v) const noexcept {
        if (m_size != v.m_size)
            return false;
        for (auto i = 0; i < m_size; ++i) {
            if (m_data[i] != v[i])
                return false;
        }
        return true;
    }

    Vec<T>& operator=(const Vec<T>& v) noexcept {
        m_size = v.m_size;
        m_data = v.m_data;
        return *this;
    }

    decltype(auto) operator+(const Vec<T>& v) const {
        assert(m_size == v.m_size);
        Vec<T> res(m_size);
        for (auto i = 0; i < m_size; ++i) {
            res[i] = m_data[i] + v[i];
        }
        return res;
    }

    decltype(auto) operator-(const Vec<T>& v) const {
        assert(m_size == v.m_size);
        Vec<T> res(m_size);
        for (auto i = 0; i < m_size; ++i) {
            res[i] = m_data[i] - v[i];
        }
        return res;
    }

    decltype(auto) operator*(const Vec<T>& v) const {
        assert(m_size == v.m_size);
        return dot(v);
    }

    Vec<T>& operator+=(const Vec<T>& v) {
        *this = *this + v;
        return *this;
    }

    Vec<T>& operator-=(const Vec<T>& v) {
        *this = *this - v;
        return *this;
    }

    // scalar operators
    decltype(auto) operator+(const Scalar& s) {
        Vec<T> res(m_size);
        for (auto i = 0; i < m_size; ++i) {
            res[i] = m_data[i] + s;
        }
        return res;
    }
    decltype(auto) operator-(const Scalar& s) {
        Vec<T> res(m_size);
        for (auto i = 0; i < m_size; ++i) {
            res[i] = m_data[i] - s;
        }
        return res;
    }
    decltype(auto) operator*(const Scalar& s) const {
        Vec<T> res(m_size);
        for (auto i = 0; i < m_size; ++i) {
            res[i] = m_data[i] * s;
        }
        return res;
    }
    Vec<T>& operator+=(const Scalar& s) {
        *this = *this + s;
        return *this;
    }
    Vec<T>& operator-=(const Scalar& s) {
        *this = *this - s;
        return *this;
    }
    Vec<T>& operator*=(const Scalar& s) {
        *this = *this * s;
        return *this;
    }

    // other methods
    Scalar norm() const override {
        Scalar sum = 0;
        for (auto i = 0; i < m_size; ++i) {
            sum += m_data[i] * m_data[i];
        }
        return std::sqrt(sum);
    }

    Vec<T>& normalize() override {
        Scalar n = norm();
        for (auto i = 0; i < m_size; ++i) {
            m_data[i] = static_cast<T>(m_data[i] * 1.0 / n);
        }
        return *this;
    }

    Scalar dot(const VecBase<T>& v) const override {
        auto _v = dynamic_cast<const Vec<T>&>(v);
        assert(m_size == _v.m_size);
        return std::inner_product(m_data.begin(), m_data.end(), _v.m_data.begin(), 0);
    }

    decltype(auto) cross(const Vec<T>& v) const {
        assert(m_size == v.m_size);
        if (m_data.size() != 3 || v.m_size != 3) {
            throw std::runtime_error("cross product is only defined for 3D vectors");
        }
        return Vec<T>{
            m_data[1] * v[2] - m_data[2] * v[1],
            m_data[2] * v[0] - m_data[0] * v[2],
            m_data[0] * v[1] - m_data[1] * v[0],
        };
    }

    decltype(auto) slice(__INDX start, __INDX end) const {
        // assert
        assert(start >= 0 && end <= m_data.size() && start < end);
        // substract [start, end) from m_data
        return Vec<T>(std::vector<T>(m_data.begin() + start, m_data.begin() + end));
    }

    decltype(auto) slice(const std::vector<__INDX>& inds) const {
        std::vector<T> res;
        for (auto i : inds) {
            res.emplace_back(m_data.at(i));
        }
        return Vec<T>(res);
    }

private:
    std::vector<T> m_data;
    __INDX m_size;
};

using VecXu = Vec<size_t>;
using VecXi = Vec<int>;
using VecXf = Vec<float>;
using VecXd = Vec<double>;

}  // namespace XMAT

#endif
