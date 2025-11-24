template<Scalar T>
Rectangle<T>::Rectangle(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) {
    p1 = std::make_unique<Point<T>>(x1, y1);
    p2 = std::make_unique<Point<T>>(x2, y2);
    p3 = std::make_unique<Point<T>>(x3, y3);
    p4 = std::make_unique<Point<T>>(x4, y4);
}

template<Scalar T>
Rectangle<T>::Rectangle(T centerX, T centerY, T width, T height) {
    T halfWidth = width / 2;
    T halfHeight = height / 2;
    
    p1 = std::make_unique<Point<T>>(centerX - halfWidth, centerY - halfHeight);
    p2 = std::make_unique<Point<T>>(centerX + halfWidth, centerY - halfHeight);
    p3 = std::make_unique<Point<T>>(centerX + halfWidth, centerY + halfHeight);
    p4 = std::make_unique<Point<T>>(centerX - halfWidth, centerY + halfHeight);
}

template<Scalar T>
Rectangle<T>::Rectangle(const Rectangle<T>& other) {
    p1 = std::make_unique<Point<T>>(other.p1->getX(), other.p1->getY());
    p2 = std::make_unique<Point<T>>(other.p2->getX(), other.p2->getY());
    p3 = std::make_unique<Point<T>>(other.p3->getX(), other.p3->getY());
    p4 = std::make_unique<Point<T>>(other.p4->getX(), other.p4->getY());
}

template<Scalar T>
Rectangle<T>& Rectangle<T>::operator=(const Rectangle<T>& other) {
    if (this != &other) {
        p1 = std::make_unique<Point<T>>(other.p1->getX(), other.p1->getY());
        p2 = std::make_unique<Point<T>>(other.p2->getX(), other.p2->getY());
        p3 = std::make_unique<Point<T>>(other.p3->getX(), other.p3->getY());
        p4 = std::make_unique<Point<T>>(other.p4->getX(), other.p4->getY());
    }
    return *this;
}

template<Scalar T>
Point<T> Rectangle<T>::getCenter() const {
    T centerX = (p1->getX() + p2->getX() + p3->getX() + p4->getX()) / 4;
    T centerY = (p1->getY() + p2->getY() + p3->getY() + p4->getY()) / 4;
    return Point<T>(centerX, centerY);
}

template<Scalar T>
double Rectangle<T>::area() const {
    T width = std::sqrt(std::pow(p2->getX() - p1->getX(), 2) + std::pow(p2->getY() - p1->getY(), 2));
    T height = std::sqrt(std::pow(p4->getX() - p1->getX(), 2) + std::pow(p4->getY() - p1->getY(), 2));
    return width * height;
}

template<Scalar T>
void Rectangle<T>::printVertices() const {
    std::cout << "Вершины прямоугольника: " << *p1 << ", " << *p2 << ", " << *p3 << ", " << *p4 << std::endl;
}

template<Scalar T>
std::unique_ptr<Figure<T>> Rectangle<T>::clone() const {
    return std::make_unique<Rectangle<T>>(*this);
}

template<Scalar T>
bool Rectangle<T>::operator==(const Figure<T>& other) const {
    const Rectangle<T>* rect = dynamic_cast<const Rectangle<T>*>(&other);
    if (!rect) return false;
    
    return *p1 == *(rect->p1) && *p2 == *(rect->p2) && 
           *p3 == *(rect->p3) && *p4 == *(rect->p4);
}