#pragma once
#include <fstream>

using namespace std;

class Student {
public:
    Student(); // конструктор без параметров
    Student(const char* name, int age, int course, char gender, double mark); // конструктор с параметрами
    Student(const Student& other); // конструктор копирования
    Student(Student&& other) noexcept; // конструктор перемещения
    ~Student(); // деструктор

    void fillFromKeyboard(); // заполнение полей класса с клавиатуры
    void saveToFile(ofstream& file); // сохранение в бин. файл
    void loadFromFile(ifstream& file); // выгрузка из бин. файла
    void print(); // вывод на экран


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