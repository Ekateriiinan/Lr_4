template<Scalar T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template<Scalar T>
T Point<T>::getX() const { return x; }

template<Scalar T>
T Point<T>::getY() const { return y; }

template<Scalar T>
void Point<T>::setX(T x) { this->x = x; }

template<Scalar T>
void Point<T>::setY(T y) { this->y = y; }

template<Scalar T>
bool Point<T>::operator==(const Point<T>& other) const {
    return x == other.x && y == other.y;
}

template<Scalar T>
bool Point<T>::operator!=(const Point<T>& other) const {
    return !(*this == other);
}

template<Scalar T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}