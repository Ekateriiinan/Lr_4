#pragma once

#include "rectangle.hpp"

template<Scalar T>
class Square : public Rectangle<T> {
public:
    Square(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4);
    Square(T centerX, T centerY, T side);
    Square(const Square<T>& other);
    
    void printVertices() const override;
    std::unique_ptr<Figure<T>> clone() const override;
};

#include "square.ipp"