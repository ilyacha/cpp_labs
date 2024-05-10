#pragma once
#include <vector>
#include "Student.h"

using namespace std;

class Database {
private:
    vector<Student> students;

public:
    Database(); // конструктор без параметров
    Database(const vector<Student>& students); // конструктор с параметрами
    Database(const Database& other); // конструктор копирования
    Database(Database&& other) noexcept; // конструктор перемещения
    ~Database();// деструктор


    void addStudent(); // добавление студента
    void loadFromBinaryFile(char* filename); // выгрузка из бин. файла
    void saveToBinaryFile(char* filename); // сохранение в бин. файл
    void printAllStudents();
    void findStudents(const char* name);
    float getAverageAgeForCourse(int year);
};