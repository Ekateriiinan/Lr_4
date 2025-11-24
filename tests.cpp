#include <gtest/gtest.h>

#include <memory>

#include "rectangle.hpp"
#include "square.hpp" 
#include "trapezoid.hpp"
#include "array.hpp"

TEST(PointTest, Basics) {
    Point<int> p1(1, 2), p2(1, 2), p3(3, 4);
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
    EXPECT_EQ(p1.getX(), 1);
    EXPECT_EQ(p1.getY(), 2);
}

TEST(RectangleTest, ConstructorsAndArea) {
    Rectangle<double> rect1(0, 0, 4, 3);
    Rectangle<double> rect2(0, 0, 4, 0, 4, 3, 0, 3);
    
    EXPECT_DOUBLE_EQ(rect1.area(), 12.0);
    EXPECT_DOUBLE_EQ(rect2.area(), 12.0);
}

TEST(RectangleTest, CopyAndClone) {
    Rectangle<double> original(0, 0, 4, 3);
    Rectangle<double> copy(original);
    auto clone = original.clone();
    
    EXPECT_TRUE(original == copy);
    EXPECT_TRUE(original == *clone);
    EXPECT_DOUBLE_EQ(original.area(), clone->area());
}

TEST(RectangleTest, Center) {
    Rectangle<double> rect(2, 2, 4, 6);
    Point<double> center = rect.getCenter();
    
    EXPECT_DOUBLE_EQ(center.getX(), 2.0);
    EXPECT_DOUBLE_EQ(center.getY(), 2.0);
}

TEST(SquareTest, AreaAndCenter) {
    Square<double> square(2, 2, 4);
    
    EXPECT_DOUBLE_EQ(square.area(), 16.0);
    
    Point<double> center = square.getCenter();
    EXPECT_DOUBLE_EQ(center.getX(), 2.0);
    EXPECT_DOUBLE_EQ(center.getY(), 2.0);
}

TEST(SquareTest, Clone) {
    Square<double> original(0, 0, 4);
    auto clone = original.clone();
    
    EXPECT_TRUE(original == *clone);
    EXPECT_DOUBLE_EQ(original.area(), clone->area());
}

TEST(TrapezoidTest, Area) {
    Trapezoid<double> trap1(0, 0, 4, 0, 3, 2, 1, 2);
    Trapezoid<double> trap2(2, 1, 2, 4, 2);
    
    EXPECT_NEAR(trap1.area(), 6.0, 1e-10);
    EXPECT_NEAR(trap2.area(), 6.0, 1e-10);
}

TEST(TrapezoidTest, Equality) {
    Trapezoid<double> trap1(0, 0, 4, 0, 3, 2, 1, 2);
    Trapezoid<double> trap2(0, 0, 4, 0, 3, 2, 1, 2);
    Trapezoid<double> trap3(1, 1, 2, 2);
    
    EXPECT_TRUE(trap1 == trap2);
    EXPECT_FALSE(trap1 == trap3);
}

TEST(FigureTest, DoubleConversion) {
    Rectangle<double> rect(0, 0, 4, 3);
    EXPECT_DOUBLE_EQ(static_cast<double>(rect), 12.0);
}

TEST(FigureTest, NotEqual) {
    Rectangle<double> rect1(0, 0, 4, 3);
    Rectangle<double> rect2(1, 1, 2, 2);
    EXPECT_TRUE(rect1 != rect2);
}

TEST(ArrayTest, BasicOperations) {
    Array<int> arr;
    
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    
    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    
    arr.erase(1);
    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_EQ(arr[1], 3);
    
    arr.clear();
    EXPECT_TRUE(arr.empty());
}

TEST(ArrayTest, CopyAndMove) {
    Array<int> original;
    original.push_back(1);
    original.push_back(2);
    
    Array<int> copy(original);
    EXPECT_EQ(copy.getSize(), 2);
    
    Array<int> moved(std::move(original));
    EXPECT_EQ(moved.getSize(), 2);
    EXPECT_EQ(original.getSize(), 0);
}

TEST(ArrayTest, WithFigures) {
    Array<std::shared_ptr<Figure<double>>> figures;
    
    figures.push_back(std::make_shared<Rectangle<double>>(0, 0, 4, 3));
    figures.push_back(std::make_shared<Square<double>>(0, 0, 2));
    figures.push_back(std::make_shared<Trapezoid<double>>(2, 1, 2, 4, 2));
    
    EXPECT_EQ(figures.getSize(), 3);
    
    double total = 0;
    for (size_t i = 0; i < figures.getSize(); ++i) {
        total += figures[i]->area();
    }
    EXPECT_GT(total, 0);
}

TEST(ArrayTest, Iterators) {
    Array<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    
    int sum = 0;
    for (const auto& item : arr) {
        sum += item;
    }
    EXPECT_EQ(sum, 6);
}

TEST(ArrayTest, Resize) {
    Array<int> arr;
    
    for (int i = 0; i < 10; ++i) {
        arr.push_back(i);
    }
    
    EXPECT_EQ(arr.getSize(), 10);
    EXPECT_GE(arr.getCapacity(), 10);
}

TEST(TypesTest, IntFigures) {
    Rectangle<int> rect(0, 0, 4, 3);
    EXPECT_DOUBLE_EQ(rect.area(), 12.0);
}

TEST(TypesTest, FloatFigures) {
    Square<float> square(2.0f, 2.0f, 4.0f);
    EXPECT_NEAR(square.area(), 16.0f, 1e-5f);
}

TEST(EdgeCasesTest, ZeroArea) {
    Rectangle<double> rect(0, 0, 0, 0);
    EXPECT_DOUBLE_EQ(rect.area(), 0.0);
}

TEST(EdgeCasesTest, ArrayOutOfRange) {
    Array<int> arr;
    arr.push_back(1);
    
    EXPECT_THROW(arr[5], std::out_of_range);
}

TEST(EdgeCasesTest, EmptyArrayOperations) {
    Array<int> arr;
    
    EXPECT_NO_THROW(arr.erase(0));
    EXPECT_NO_THROW(arr.clear());
    EXPECT_TRUE(arr.empty());
}