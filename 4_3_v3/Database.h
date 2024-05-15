#pragma once
#include "Student.h"

class Database {
private:
    Student* students;
    int capacity; // ����������� ���� ������
    int size; // ������� ���������� ��������� � ����

public:
    Database(); // ����������� �� ���������
    Database(int capacity); // ����������� � ����������
    Database(const Database& other); // ����������� �����������
    Database(Database&& other) noexcept; // ����������� �����������
    ~Database(); // ����������

    void addStudent(); // ���������� ��������
    void loadFromBinaryFile(const char* filename); // �������� �� ���. �����
    void saveToBinaryFile(const char* filename); // ���������� � ���. ����
    void printAllStudents(); // ����� ���� �� �����
    void findStudents(const char* name); // ����� �� ����� 
    float getAverageAgeForCourse(int year); // ������� ������� �����
};