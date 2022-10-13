/**
 * unit test for xmat/vec.hpp
 */

#include <gtest/gtest.h>
#include <xmat/vec.hpp>

class VecTest : public ::testing::Test {
protected:
    void SetUp() override {
        vec1_ = XMAT::VecXd(3);
        vec2_ = XMAT::VecXd({3, 4, 5});
        vec3_ = XMAT::VecXd({2, 1, 3});
    }

  // void TearDown() override {}
    XMAT::VecXu vec0_;
    XMAT::VecXd vec1_;
    XMAT::VecXd vec2_;
    XMAT::VecXd vec3_;
};

TEST_F(VecTest, IsEmptyInitially) {
    EXPECT_EQ(vec0_.size(), 0);
}

TEST_F(VecTest, CanBeInitializedWithSize) {
    EXPECT_EQ(vec1_.size(), 3);
}

TEST_F(VecTest, Addtion) {
    auto _v = vec2_ + vec3_;
    EXPECT_EQ(_v, XMAT::VecXd({5, 5, 8}));
}

TEST_F(VecTest, DotProduct) {
    auto _dot1 = vec2_.dot(vec3_);
    auto _dot2 = vec3_ * vec2_;
    EXPECT_EQ(_dot1, _dot2);
    EXPECT_EQ(_dot1, 25);
}

TEST_F(VecTest, CrossProduct) {
    auto _cross = vec2_.cross(vec3_);
    EXPECT_EQ(_cross, XMAT::VecXd({7, 1, -5}));
}