#pragma once

#include "point.hpp"
#include <memory>

template<Scalar T>
class Figure {
public:
    virtual ~Figure() = default;
    
    virtual Point<T> getCenter() const = 0;
    virtual double area() const = 0;
    virtual void printVertices() const = 0;
    virtual std::unique_ptr<Figure<T>> clone() const = 0;
    
    explicit virtual operator double() const;
    
    virtual bool operator==(const Figure<T>& other) const = 0;
    virtual bool operator!=(const Figure<T>& other) const;
};

#include "figure.ipp"