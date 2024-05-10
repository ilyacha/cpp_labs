#pragma once
#include <cstdlib>
#include <iostream>

const int MAX_SIZE = 100; // максимальный размер вектора

class Vector {
private:
    double* data; // динамический массив для хранения элементов вектора
    int size;     // размерность вектора

public:
    // конструкторы
    Vector();
    Vector(int n);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;

    // деструктор
    ~Vector();

    // методы
    void setSize(int n); // установление размера
    int getSize() const; // текущий размер ветора
    double getElement(int index) const; // значение элемента по индексу
    void setElement(int index, double value); // устанавливает значение элемента по индексу
    void addScalar(double scalar); // сложение (к вектору числа)
    void subtractScalar(double scalar); // вычитание (от вектора числа)
    void multiplyScalar(double scalar); // умножение (на число вектор)
    void divideScalar(double scalar); // деление (на число вектор)
    double length() const; // длина вектора
    Vector add(const Vector& other) const; // новый вектор суммы z=x+y
    Vector subtract(const Vector& other) const; // новый вектор разности z=x-y
    Vector multiply(const Vector& other) const; // новый вектор произведедния z=x*y
    Vector divide(const Vector& other) const; // новый вектор частного z=x/y
    void print() const; // вывод
    void input(); // ввод
    void fillRandom(); // рандом
};
