template<Scalar T>
Square<T>::Square(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) 
    : Rectangle<T>(x1, y1, x2, y2, x3, y3, x4, y4) {}

template<Scalar T>
Square<T>::Square(T centerX, T centerY, T side) 
    : Rectangle<T>(centerX, centerY, side, side) {}

template<Scalar T>
Square<T>::Square(const Square<T>& other) : Rectangle<T>(other) {}

template<Scalar T>
void Square<T>::printVertices() const {
    std::cout << "Вершины квадрата: ";
    Rectangle<T>::printVertices();
}

template<Scalar T>
std::unique_ptr<Figure<T>> Square<T>::clone() const {
    return std::make_unique<Square<T>>(*this);
}