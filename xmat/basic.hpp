#pragma once

#include <omp.h>
#include <vector>

namespace XMAT {

template <typename T>
T add(const T&& a, const T&& b) {
    return a + b;
}

template <typename T>
T sum(const std::vector<T> &v) {
    T sum = static_cast<T>(0);
#pragma omp parallel for reduction(+:sum)
    for (auto i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}


}