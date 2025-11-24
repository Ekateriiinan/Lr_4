template<Scalar T>
Figure<T>::operator double() const {
    return area();
}

template<Scalar T>
bool Figure<T>::operator!=(const Figure<T>& other) const {
    return !(*this == other);
}