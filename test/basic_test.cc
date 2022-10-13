#include <vector>

#include <gtest/gtest.h>
#include <xmat/basic.hpp>

using namespace XMAT;
using namespace std;

TEST(BasicTest, Addition) {
    EXPECT_EQ(7 * 6, 42);
    EXPECT_EQ(XMAT::add(3, 5), 8);
}

TEST(BasicTest, Sum) {
    vector<int> v = {1, 2, 3, 4, 5};
    EXPECT_EQ(XMAT::sum(v), 15);
}
