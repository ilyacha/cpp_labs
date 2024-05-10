#pragma once
#include <cstdlib>
#include <iostream>

const int MAX_SIZE = 100; // ������������ ������ �������

class Vector {
private:
    double* data; // ������������ ������ ��� �������� ��������� �������
    int size;     // ����������� �������

public:
    // ������������
    Vector();
    Vector(int n);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;

    // ����������
    ~Vector();

    // ������
    void setSize(int n); // ������������ �������
    int getSize() const; // ������� ������ ������
    double getElement(int index) const; // �������� �������� �� �������
    void setElement(int index, double value); // ������������� �������� �������� �� �������
    void addScalar(double scalar); // �������� (� ������� �����)
    void subtractScalar(double scalar); // ��������� (�� ������� �����)
    void multiplyScalar(double scalar); // ��������� (�� ����� ������)
    void divideScalar(double scalar); // ������� (�� ����� ������)
    double length() const; // ����� �������
    Vector add(const Vector& other) const; // ����� ������ ����� z=x+y
    Vector subtract(const Vector& other) const; // ����� ������ �������� z=x-y
    Vector multiply(const Vector& other) const; // ����� ������ ������������� z=x*y
    Vector divide(const Vector& other) const; // ����� ������ �������� z=x/y
    void print() const; // �����
    void input(); // ����
    void fillRandom(); // ������
};
