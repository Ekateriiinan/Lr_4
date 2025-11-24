#pragma once

#include <concepts>
#include <iostream>

template<typename T>
concept Scalar = std::is_scalar_v<T>;

template<Scalar T>
class Point {
private:
    T x, y;
public:
    Point(T x = 0, T y = 0);
    
    T getX() const;
    T getY() const;
    void setX(T x);
    void setY(T y);
    
    bool operator==(const Point<T>& other) const;
    bool operator!=(const Point<T>& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Point<T>& p);
};

#include "point.ipp"