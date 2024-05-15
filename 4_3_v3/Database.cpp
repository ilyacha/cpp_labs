#include "Database.h"
#include <iostream>
#include <fstream>

using namespace std;

// конструктор по умолчанию
Database::Database()
    : capacity(10), size(0) {
    students = new Student[capacity];
}

// конструктор с параметром
Database::Database(int capacity)
    : capacity(capacity), size(0) {
    students = new Student[capacity];
}

// конструктор копирования
Database::Database(const Database& other)
    : capacity(other.capacity), size(other.size) {
    students = new Student[capacity];
    for (int i = 0; i < size; i++) {
        new(students + i) Student(other.students[i]);
    }
}

// конструктор перемещения
Database::Database(Database&& other) noexcept
    : students(other.students), capacity(other.capacity), size(other.size) {
    other.students = nullptr;
    other.capacity = 0;
    other.size = 0;
}

// деструктор
Database::~Database() {
    for (int i = 0; i < size; i++) {
        students[i].~Student();
    }
    delete[] students;
}

// Методы
// добавление студента
void Database::addStudent() {
    if (size >= capacity) {
        int newCapacity = capacity * 2;
        Student* newStudents = new Student[newCapacity];
        for (int i = 0; i < size; i++) {
            new(newStudents + i) Student(students[i]);
        }
        for (int i = 0; i < size; i++) {
            students[i].~Student();
        }
        delete[] students;
        students = newStudents;
        capacity = newCapacity;
    }

    Student newStudent;
    newStudent.fillFromKeyboard();
    new(students + size) Student(newStudent);
    size++;
}


void Database::loadFromBinaryFile(const char* filename) {
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&size), sizeof(int));
        capacity = size;
        delete[] students;
        students = new Student[capacity];
        for (int i = 0; i < size; i++) {
            file.read(reinterpret_cast<char*>(&students[i]), sizeof(Student));
        }
        file.close();
    }
    else {
        cerr << "Error opening file for reading: " << filename << endl;
    }
}

void Database::saveToBinaryFile(const char* filename) {
    ofstream file(filename, ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(&size), sizeof(int));
        for (int i = 0; i < size; i++) {
            file.write(reinterpret_cast<const char*>(&students[i]), sizeof(Student));
        }
        file.close();
    }
    else {
        cerr << "Error opening file for writing: " << filename << endl;
    }
}

void Database::printAllStudents() {
    for (int i = 0; i < size; i++) {
        cout << "Student #" << i + 1 << endl;
        students[i].print();
        cout << endl;
    }
}

void Database::findStudents(const char* name) {
    cout << "Students with name \"" << name << "\":" << endl;
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].getName(), name) == 0) {
            students[i].print();
            cout << endl;
        }
    }
}

float Database::getAverageAgeForCourse(int course) {
    int count = 0;
    int totalAge = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].getCourse() == course) {
            totalAge += students[i].getAge();
            count++;
        }
    }

    if (count == 0) {
        return 0.0f;
    }

    return static_cast<float>(totalAge) / count;
}