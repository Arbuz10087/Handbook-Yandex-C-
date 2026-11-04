
# Задача: Коварная матрица

## Суть задачи
Ваш друг пишет свою реализацию шаблонного класса «Матрица»:
#include <iostream>

template <typename T>
class Matrix {
private:
    T** data;
    size_t rows, columns;

public:
    Matrix(size_t m, size_t n): rows(m), columns(n) {
        data = new T * [rows];
        size_t i = 0;
        try {
            for (; i != rows; ++i) {
                data[i] = new T[columns];
            }
        } catch (...) {
            for (size_t k = 0; k != i; ++k) {
                delete [] data[k];
            }
            delete [] data;
            throw;
        }
    }

    T* operator [](size_t i) {
        return data[i];
    }
    const T* operator [](size_t i) const {
        return data[i];
    }

    size_t GetRows() const {
        return rows;
    }

    size_t GetColumns() const {
        return columns;
    }

    ~Matrix() {
        for (size_t i = 0; i != rows; ++i) {
            delete [] data[i];
        }
        delete [] data;
    }

    // Сюда можно будет вставить ваш код
    #include "your_code.h"
};

template <typename T>
Matrix<T> FillMatrix(size_t m, size_t n) {
    Matrix<T> A(m, n);
    for (size_t i = 0; i != m; ++i) {
        for (size_t j = 0; j != n; ++j) {
            A[i][j] = i + j;
        }
    }
    return A;
}

template <typename T>
std::ostream& operator << (std::ostream& out, const Matrix<T>& A) {
    for (size_t i = 0; i != A.GetRows(); ++i) {
        for (size_t j = 0; j != A.GetColumns(); ++j) {
            out << A[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

Правда, он зачем-то выбрал очень странную реализацию матрицы на основе двумерного динамического массива, а не вектора. Однако вы можете быть уверенными, что инициализацию и освобождение динамической памяти для отдельно взятой матрицы ваш друг написал правильно.

Пока в классе есть только конструктор, деструктор и оператор []. Ещё ваш друг написал функцию FillMatrix, возвращающую матрицу, заполненную особым образом, а также оператор << для печати матрицы на экране.

Но почему-то вот такой простой код не работает:

#include "matrix.h"
#include <iostream>

int main() {
    size_t m, n;
    std::cin >> m >> n;
    Matrix<int> A(m, n);
    // ...
    A = FillMatrix<int>(m, n);
    std::cout << A << "\n";
}

Вам нужно добиться, чтобы он заработал. Вы можете только дописывать что-то к классу Matrix в месте #include "your_code.h".

## Нюансы
Мы компилируем эту программу с дополнительной опцией компилятора -fno-elide-constructors, которая отменяет copy elision и требует вызова конструктора при возврате значения из функции.

## Статус
- [x] решено
- [ ] требует рефакторинга
- [ ] нужно добавить тесты

