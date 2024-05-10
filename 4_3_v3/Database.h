#pragma once
#include <vector>
#include "Student.h"

using namespace std;

class Database {
private:
    vector<Student> students;

public:
    Database(); // ����������� ��� ����������
    Database(const vector<Student>& students); // ����������� � �����������
    Database(const Database& other); // ����������� �����������
    Database(Database&& other) noexcept; // ����������� �����������
    ~Database();// ����������


    void addStudent(); // ���������� ��������
    void loadFromBinaryFile(char* filename); // �������� �� ���. �����
    void saveToBinaryFile(char* filename); // ���������� � ���. ����
    void printAllStudents();
    void findStudents(const char* name);
    float getAverageAgeForCourse(int year);
};