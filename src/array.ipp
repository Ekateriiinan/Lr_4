template<typename T>
void Array<T>::resize(size_t newCapacity) {
    std::shared_ptr<T[]> newData(new T[newCapacity]);
    
    for (size_t i = 0; i < size; ++i) {
        newData[i] = std::move(data[i]);
    }
    
    data = std::move(newData);
    capacity = newCapacity;
}

template<typename T>
Array<T>::Array() : data(nullptr), capacity(0), size(0) {}

template<typename T>
Array<T>::Array(size_t initialCapacity) : capacity(initialCapacity), size(0) {
    data = std::shared_ptr<T[]>(new T[capacity]);
}

template<typename T>
Array<T>::Array(const Array& other) : capacity(other.capacity), size(other.size) {
    data = std::shared_ptr<T[]>(new T[capacity]);
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        data.reset();
        
        capacity = other.capacity;
        size = other.size;
        data = std::shared_ptr<T[]>(new T[capacity]);
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::Array(Array&& other) noexcept 
    : data(std::move(other.data)), capacity(other.capacity), size(other.size) {
    other.capacity = 0;
    other.size = 0;
    other.data = nullptr;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
        capacity = other.capacity;
        size = other.size;
        
        other.capacity = 0;
        other.size = 0;
        other.data = nullptr;
    }
    return *this;
}

template<typename T>
void Array<T>::push_back(const T& value) {
    if (size >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template<typename T>
void Array<T>::push_back(T&& value) {
    if (size >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = std::move(value);
}

template<typename T>
void Array<T>::erase(size_t index) {
    if (index >= size) return;
    
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = std::move(data[i + 1]);
    }
    --size;
}

template<typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= size) throw std::out_of_range("Индекс вне диапазона");
    return data[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= size) throw std::out_of_range("Индекс вне диапазона");
    return data[index];
}

template<typename T>
size_t Array<T>::getSize() const { return size; }

template<typename T>
size_t Array<T>::getCapacity() const { return capacity; }

template<typename T>
bool Array<T>::empty() const { return size == 0; }

template<typename T>
void Array<T>::clear() {
    data.reset();
    capacity = 0;
    size = 0;
}

template<typename T>
T* Array<T>::begin() { return data.get(); }

template<typename T>
T* Array<T>::end() { return data.get() + size; }

template<typename T>
const T* Array<T>::begin() const { return data.get(); }

template<typename T>
const T* Array<T>::end() const { return data.get() + size; }
