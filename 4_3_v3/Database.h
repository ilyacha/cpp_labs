#pragma once
#include "Student.h"

class Database {
private:
    Student* students;
    int capacity; // вместимость базы данных
    int size; // текущее количество студентов в базе

public:
    Database(); // конструктор по умолчанию
    Database(int capacity); // конструктор с параметром
    Database(const Database& other); // конструктор копирования
    Database(Database&& other) noexcept; // конструктор перемещения
    ~Database(); // деструктор

    void addStudent(); // добавление студента
    void loadFromBinaryFile(const char* filename); // выгрузка из бин. файла
    void saveToBinaryFile(const char* filename); // сохранение в бин. файл
    void printAllStudents(); // вывод всех на экран
    void findStudents(const char* name); // поиск по имени 
    float getAverageAgeForCourse(int year); // средний возраст курса
};