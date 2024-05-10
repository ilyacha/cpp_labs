#include "vector.h"
#include <cmath>
#include <cstdlib>
#include <ctime> // random

using namespace std;

// ������������
Vector::Vector() : data(nullptr), size(0) {}

Vector::Vector(int n) {
    if (n > MAX_SIZE) {
        cerr << "Error: Vector size exceeds maximum limit" << endl;
        size = 0;
        data = nullptr;
    }
    else {
        size = n;
        data = new double[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0.0;
        }
    }
}

Vector::Vector(const Vector& other) {
    size = other.size;
    data = new double[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

Vector::Vector(Vector&& other) noexcept {
    size = other.size;
    data = other.data;
    other.data = nullptr;
    other.size = 0;
}

// ����������
Vector::~Vector() {
    delete[] data;
}

// ������
// ������������ �������
void Vector::setSize(int n) {
    if (n > MAX_SIZE) {
        cerr << "Error: Vector size exceeds maximum limit" << endl;
        return;
    }
    delete[] data;
    size = n;
    data = new double[size];
    for (int i = 0; i < size; i++) {
        data[i] = 0.0;
    }
}

// ������� ������ ������
int Vector::getSize() const {
    return size;
}

// �������� �������� �� �������
double Vector::getElement(int index) const {
    if (index < 0 || index >= size) {
        cerr << "Error: Index out of range" << endl;
        return 0.0;
    }
    return data[index];
}

// ������������� �������� �������� �� �������
void Vector::setElement(int index, double value) {
    if (index < 0 || index >= size) {
        cerr << "Error: Index out of range" << endl;
        return;
    }
    data[index] = value;
}

// ��������
void Vector::addScalar(double scalar) {
    for (int i = 0; i < size; i++) {
        data[i] += scalar;
    }
}

// ���������
void Vector::subtractScalar(double scalar) {
    for (int i = 0; i < size; i++) {
        data[i] -= scalar;
    }
}

// ���������
void Vector::multiplyScalar(double scalar) {
    for (int i = 0; i < size; i++) {
        data[i] *= scalar;
    }
}

// �������
void Vector::divideScalar(double scalar) {
    if (scalar == 0.0) {
        cerr << "Error: Division by zero" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        data[i] /= scalar;
    }
}

// ����� �������
double Vector::length() const {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i] * data[i];
    }
    return sqrt(sum);
}

// ����� ������ �����
Vector Vector::add(const Vector& other) const {
    if (size != other.size) {
        cerr << "Error: Vector dimensions do not match" << endl;
        return other; //
    }
    Vector result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

// ����� ������ ��������
Vector Vector::subtract(const Vector& other) const {
    if (size != other.size) {
        cerr << "Error: Vector dimensions do not match" << endl;
        return other; //
    }
    Vector result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

// ����� ������ �������������
Vector Vector::multiply(const Vector& other) const {
    if (size != other.size) {
        cerr << "Error: Vector dimensions do not match" << endl;
        return other; //
    }
    Vector result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] * other.data[i];
    }
    return result;
}

// ����� ������ ��������
Vector Vector::divide(const Vector& other) const {
    if (size != other.size) {
        cerr << "Error: Vector dimensions do not match" << endl;
        return other; //
    }
    Vector result(size);
    for (int i = 0; i < size; i++) {
        if (other.data[i] == 0.0) {
            cerr << "Error: Division by zero" << endl;
            result.data[i] = 0.0;
        }
        else {
            result.data[i] = data[i] / other.data[i];
        }
    }
    return result;
}

// �����
void Vector::print() const {
    cout << "Vector: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// ����
void Vector::input() {
    cout << "Enter vector elements: ";
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }
}

void Vector::fillRandom() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < size; i++) {
        data[i] = static_cast<int>(rand() % 100);
    }
}