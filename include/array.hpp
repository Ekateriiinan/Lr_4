#pragma once

#include <memory>
#include <stdexcept>

template<typename T>
class Array {
private:
    T* data;
    size_t capacity;
    size_t size;
    
    void resize(size_t newCapacity);
    
public:
    Array();
    Array(size_t initialCapacity);
    Array(const Array& other);
    Array& operator=(const Array& other);
    Array(Array&& other) noexcept;
    Array& operator=(Array&& other) noexcept;
    ~Array();
    
    void push_back(const T& value);
    void push_back(T&& value);
    void erase(size_t index);
    
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    
    size_t getSize() const;
    size_t getCapacity() const;
    bool empty() const;
    
    void clear();
    
    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;
};

#include "array.ipp"
