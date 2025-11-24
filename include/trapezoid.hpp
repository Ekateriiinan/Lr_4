#pragma once

#include <memory>
#include <cmath>
#include <iostream>

#include "figure.hpp"

template<Scalar T>
class Trapezoid : public Figure<T> {
private:
    std::unique_ptr<Point<T>> p1, p2, p3, p4;
    
public:
    Trapezoid(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4);
    Trapezoid(T centerX, T centerY, T topBase, T bottomBase, T height);
    Trapezoid(const Trapezoid<T>& other);
    Trapezoid<T>& operator=(const Trapezoid<T>& other);
    
    Point<T> getCenter() const override;
    double area() const override;
    void printVertices() const override;
    std::unique_ptr<Figure<T>> clone() const override;
    bool operator==(const Figure<T>& other) const override;
};

#include "trapezoid.ipp"