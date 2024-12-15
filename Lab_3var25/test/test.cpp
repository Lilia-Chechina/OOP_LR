#include <gtest/gtest.h>
#include "../include/figure.h"

TEST(Triangle, EmptyConstructor) {
    Triangle t;
    EXPECT_DOUBLE_EQ(t.area(), 0.0);
    EXPECT_EQ(t.center(), std::make_pair(0.0, 0.0));
}

TEST(Triangle, StaticArrayConstructor) {
    double x[3] = {0.0, 10.0, 0.0};
    double y[3] = {0.0, 0.0, 10.0};
    Triangle t(x, y);
    
    EXPECT_DOUBLE_EQ(t.area(), 50.0);
    EXPECT_NEAR(t.center().first, 3.33333, 0.00001);
    EXPECT_NEAR(t.center().second, 3.33333, 0.00001);
}

TEST(Triangle, AssignmentOperator) {
    double x1[3] = {0.0, 10.0, 0.0};
    double y1[3] = {0.0, 0.0, 10.0};
    Triangle t1(x1, y1);
    double x2[3] = {0.0, 5.0, 0.0};
    double y2[3] = {0.0, 0.0, 5.0};
    Triangle t2(x2, y2);

    t2 = t1;

    EXPECT_DOUBLE_EQ(t2.area(), 50.0);
    EXPECT_NEAR(t2.center().first, 3.33333, 0.00001);
    EXPECT_NEAR(t2.center().second, 3.33333, 0.00001);
}

TEST(Square, EmptyConstructor) {
    Square s;
    EXPECT_DOUBLE_EQ(s.area(), 0.0);
    EXPECT_EQ(s.center(), std::make_pair(0.0, 0.0));
}

TEST(Square, StaticArrayConstructor) {
    double x[4] = {0.0, 10.0, 10.0, 0.0};
    double y[4] = {0.0, 0.0, 10.0, 10.0};
    Square s(x, y);
    EXPECT_DOUBLE_EQ(s.area(), 100.0);
    EXPECT_EQ(s.center(), std::make_pair(5.0, 5.0));
}

TEST(Rectangle, EmptyConstructor) {
    Rectangle r;
    EXPECT_DOUBLE_EQ(r.area(), 0.0);
    EXPECT_EQ(r.center(), std::make_pair(0.0, 0.0));
}

TEST(Rectangle, StaticArrayConstructor) {
    double x[4] = {0.0, 10.0, 10.0, 0.0};
    double y[4] = {0.0, 0.0, 5.0, 5.0};
    Rectangle r(x, y);
    
    EXPECT_DOUBLE_EQ(r.area(), 50.0);
    EXPECT_EQ(r.center(), std::make_pair(5.0, 2.5));
}

TEST(Array, EmptyConstructor) {
    Array a;
    EXPECT_EQ(a.get_size(), 10);
    for (size_t i = 0; i < a.get_size(); ++i) {
        EXPECT_EQ(a[i], nullptr);
    }
}

TEST(Array, SizeConstructor) {
    Array a(15);
    EXPECT_EQ(a.get_size(), 15);
    for (size_t i = 0; i < a.get_size(); ++i) {
        EXPECT_EQ(a[i], nullptr);
    }
}

TEST(Square, ConstructorAndArea) {
    double x[4] = {0.0, 10.0, 10.0, 0.0};
    double y[4] = {0.0, 0.0, 10.0, 10.0};
    Square s(x, y);
    EXPECT_DOUBLE_EQ(s.area(), 100.0);
}

TEST(Triangle, Center) {
    double x[3] = {0.0, 10.0, 10.0};
    double y[3] = {0.0, 0.0, 10.0};
    Triangle t(x, y);
    auto center = t.center();
    EXPECT_EQ(t.center(), std::make_pair(6.666666666666667, 3.3333333333333335));
}

TEST(Rectangle, Area) {
    double x[4] = {0.0, 20.0, 20.0, 0.0};
    double y[4] = {0.0, 0.0, 10.0, 10.0};
    Rectangle r(x, y);
    EXPECT_DOUBLE_EQ(r.area(), 200.0);
}

TEST(Rectangle, Center) {
    double x[4] = {0.0, 20.0, 20.0, 0.0};
    double y[4] = {0.0, 0.0, 10.0, 10.0};
    Rectangle r(x, y);
    EXPECT_EQ(r.center(), std::make_pair(10.0, 5.0)); 
}


