#pragma once
#include <fstream>

using namespace std;

class Student {
public:
    Student(); // ����������� ��� ����������
    Student(const char* name, int age, int course, char gender, double mark); // ����������� � �����������
    Student(const Student& other); // ����������� �����������
    Student(Student&& other) noexcept; // ����������� �����������
    ~Student(); // ����������

    void fillFromKeyboard(); // ���������� ����� ������ � ����������
    void saveToFile(ofstream& file); // ���������� � ���. ����
    void loadFromFile(ifstream& file); // �������� �� ���. �����
    void print(); // ����� �� �����


    char* getName();
    int getAge();
    int getCourse(); 
    char getGender();
    double getMark();

private:
    char m_name[50];
    unsigned int m_age;
    int m_course;
    char m_gender;
    double m_mark;
};