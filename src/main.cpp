#include <iostream>
#include <memory>

#include "point.hpp"
#include "figure.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "trapezoid.hpp"
#include "array.hpp"


template<Scalar T>
void printFigureInfo(const Figure<T>& fig) {
    std::cout << "Центр: " << fig.getCenter() << std::endl;
    fig.printVertices();
    std::cout << "Площадь: " << fig.area() << std::endl;
    std::cout << "-------------------" << std::endl;
}

template<Scalar T>
double calculateTotalArea(const Array<std::shared_ptr<Figure<T>>>& figures) {
    double total = 0;
    for (size_t i = 0; i < figures.getSize(); ++i) {
        total += figures[i]->area();
    }
    return total;
}

template<Scalar T>
void inputFigures(Array<std::shared_ptr<Figure<T>>>& figures) {
    int choice;
    
    std::cout << "=== Ввод фигур ===" << std::endl;
    std::cout << "1 - Прямоугольник, 2 - Квадрат, 3 - Трапеция, 0 - Завершить ввод" << std::endl;
    
    while (true) {
        std::cout << "Выберите тип фигуры (0 для завершения): ";
        std::cin >> choice;
        
        if (choice == 0) break;
        
        try {
            switch (choice) {
                case 1: {
                    T x, y, width, height;
                    std::cout << "Введите центр прямоугольника (x y): ";
                    std::cin >> x >> y;
                    std::cout << "Введите ширину и высоту: ";
                    std::cin >> width >> height;
                    
                    auto rect = std::make_shared<Rectangle<T>>(x, y, width, height);
                    figures.push_back(rect);
                    std::cout << "Прямоугольник успешно добавлен!" << std::endl;
                    break;
                }
                case 2: {
                    T x, y, side;
                    std::cout << "Введите центр квадрата (x y): ";
                    std::cin >> x >> y;
                    std::cout << "Введите длину стороны: ";
                    std::cin >> side;
                    
                    auto square = std::make_shared<Square<T>>(x, y, side);
                    figures.push_back(square);
                    std::cout << "Квадрат успешно добавлен!" << std::endl;
                    break;
                }
                case 3: {
                    T x, y, topBase, bottomBase, height;
                    std::cout << "Введите центр трапеции (x y): ";
                    std::cin >> x >> y;
                    std::cout << "Введите верхнее основание, нижнее основание и высоту: ";
                    std::cin >> topBase >> bottomBase >> height;
                    
                    auto trapezoid = std::make_shared<Trapezoid<T>>(x, y, topBase, bottomBase, height);
                    figures.push_back(trapezoid);
                    std::cout << "Трапеция успешно добавлена!" << std::endl;
                    break;
                }
                default:
                    std::cout << "Неверный выбор!" << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Ошибка создания фигуры: " << e.what() << std::endl;
        }
    }
}

int main() {
    Array<std::shared_ptr<Figure<double>>> figures;
    
    inputFigures(figures);
    
    std::cout << "\n=== Все фигуры в массиве ===" << std::endl;
    for (size_t i = 0; i < figures.getSize(); ++i) {
        std::cout << "Фигура " << i + 1 << ":" << std::endl;
        printFigureInfo(*(figures[i]));
    }
    
    std::cout << "=== Общая площадь ===" << std::endl;
    std::cout << "Общая площадь всех фигур: " << calculateTotalArea(figures) << std::endl;
    
    std::cout << "\n=== Тестирование массива с разными типами ===" << std::endl;
    
    Array<std::shared_ptr<Figure<int>>> intFigures;
    intFigures.push_back(std::make_shared<Rectangle<int>>(0, 0, 10, 20));
    intFigures.push_back(std::make_shared<Square<int>>(5, 5, 8));
    
    std::cout << "Размер массива int фигур: " << intFigures.getSize() << std::endl;
    
    Array<Square<double>> squaresArray;
    squaresArray.push_back(Square<double>(0, 0, 5));
    squaresArray.push_back(Square<double>(3, 3, 7));
    
    std::cout << "Размер массива квадратов: " << squaresArray.getSize() << std::endl;
    for (size_t i = 0; i < squaresArray.getSize(); ++i) {
        std::cout << "Площадь квадрата " << i + 1 << ": " << squaresArray[i].area() << std::endl;
    }
    
    std::cout << "\n=== Тестирование копирования и сравнения ===" << std::endl;
    
    if (figures.getSize() > 0) {
        auto firstFigureCopy = figures[0]->clone();
        std::cout << "Оригинал фигуры == Копия: " << (*figures[0] == *firstFigureCopy) << std::endl;
        
        std::cout << "Площадь первой фигуры как double: " << static_cast<double>(*figures[0]) << std::endl;
    }
    
    std::cout << "\n=== Удаление фигуры из массива ===" << std::endl;
    std::cout << "До удаления - размер массива: " << figures.getSize() << std::endl;
    
    if (figures.getSize() > 0) {
        figures.erase(0);
        std::cout << "После удаления - размер массива: " << figures.getSize() << std::endl;
    }
    
    std::cout << "\n=== Оставшиеся фигуры ===" << std::endl;
    for (size_t i = 0; i < figures.getSize(); ++i) {
        std::cout << "Фигура " << i + 1 << ":" << std::endl;
        printFigureInfo(*(figures[i]));
    }
    
    return 0;
}