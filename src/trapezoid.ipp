template<Scalar T>
Trapezoid<T>::Trapezoid(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) {
    p1 = std::make_unique<Point<T>>(x1, y1);
    p2 = std::make_unique<Point<T>>(x2, y2);
    p3 = std::make_unique<Point<T>>(x3, y3);
    p4 = std::make_unique<Point<T>>(x4, y4);
}

template<Scalar T>
Trapezoid<T>::Trapezoid(T centerX, T centerY, T topBase, T bottomBase, T height) {
    T topHalf = topBase / 2;
    T bottomHalf = bottomBase / 2;
    
    p1 = std::make_unique<Point<T>>(centerX - bottomHalf, centerY - height/2);
    p2 = std::make_unique<Point<T>>(centerX + bottomHalf, centerY - height/2);
    p3 = std::make_unique<Point<T>>(centerX + topHalf, centerY + height/2);
    p4 = std::make_unique<Point<T>>(centerX - topHalf, centerY + height/2);
}

template<Scalar T>
Trapezoid<T>::Trapezoid(const Trapezoid<T>& other) {
    p1 = std::make_unique<Point<T>>(other.p1->getX(), other.p1->getY());
    p2 = std::make_unique<Point<T>>(other.p2->getX(), other.p2->getY());
    p3 = std::make_unique<Point<T>>(other.p3->getX(), other.p3->getY());
    p4 = std::make_unique<Point<T>>(other.p4->getX(), other.p4->getY());
}

template<Scalar T>
Trapezoid<T>& Trapezoid<T>::operator=(const Trapezoid<T>& other) {
    if (this != &other) {
        p1 = std::make_unique<Point<T>>(other.p1->getX(), other.p1->getY());
        p2 = std::make_unique<Point<T>>(other.p2->getX(), other.p2->getY());
        p3 = std::make_unique<Point<T>>(other.p3->getX(), other.p3->getY());
        p4 = std::make_unique<Point<T>>(other.p4->getX(), other.p4->getY());
    }
    return *this;
}

template<Scalar T>
Point<T> Trapezoid<T>::getCenter() const {
    T centerX = (p1->getX() + p2->getX() + p3->getX() + p4->getX()) / 4;
    T centerY = (p1->getY() + p2->getY() + p3->getY() + p4->getY()) / 4;
    return Point<T>(centerX, centerY);
}

template<Scalar T>
double Trapezoid<T>::area() const {
    T bottomBase = std::sqrt(std::pow(p2->getX() - p1->getX(), 2) + std::pow(p2->getY() - p1->getY(), 2));
    T topBase = std::sqrt(std::pow(p3->getX() - p4->getX(), 2) + std::pow(p3->getY() - p4->getY(), 2));
    T height = std::abs(p3->getY() - p1->getY());
    
    return (topBase + bottomBase) * height / 2;
}

template<Scalar T>
void Trapezoid<T>::printVertices() const {
    std::cout << "Вершины трапеции: " << *p1 << ", " << *p2 << ", " << *p3 << ", " << *p4 << std::endl;
}

template<Scalar T>
std::unique_ptr<Figure<T>> Trapezoid<T>::clone() const {
    return std::make_unique<Trapezoid<T>>(*this);
}

template<Scalar T>
bool Trapezoid<T>::operator==(const Figure<T>& other) const {
    const Trapezoid<T>* trap = dynamic_cast<const Trapezoid<T>*>(&other);
    if (!trap) return false;
    
    return *p1 == *(trap->p1) && *p2 == *(trap->p2) && 
           *p3 == *(trap->p3) && *p4 == *(trap->p4);
}