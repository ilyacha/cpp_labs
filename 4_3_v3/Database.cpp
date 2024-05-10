#include "Database.h"
#include <iostream>
#include <fstream>

using namespace std;

Database::Database() 
    : students() {}

Database::Database(const vector<Student>& students) 
    : students(students) {}

Database::Database(const Database& other) 
    : students(other.students) {}

Database::Database(Database&& other) noexcept 
    : students(move(other.students)) {}


Database::~Database() {}

// Методы
void Database::addStudent() {
    Student newStudent;
    newStudent.fillFromKeyboard();
    students.push_back(newStudent);
}

void Database::loadFromBinaryFile(char* filename) {
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        // Чтение данных из бинарного файла
        file.close();
    }
    else {
        cerr << "Error opening file for reading. " << filename << endl;
    }
}

void Database::saveToBinaryFile(char* filename) {
    ofstream file(filename, ios::binary);
    if (file.is_open()) {
        // Запись данных в бинарный файл
        file.close();
    }
    else {
        cerr << "Error opening file for writing. " << filename << endl;
    }
}

void Database::printAllStudents() {
    int i = 0;
    for (auto& student : students) {
        cout << "Student #" << i + 1 << endl;
        student.print();
        cout << endl;
        i++;
    }
}

void Database::findStudents(const char* name) {
    cout << "Students with name \"" << name << "\":" << endl;
    for (auto& student : students) {
        if (strcmp(student.getName(), name) == 0) {
            student.print();
            cout << endl;
        }
    }
}

float Database::getAverageAgeForCourse(int course) {
    int count = 0;
    int totalAge = 0;
    for (auto& student : students) {
        if (student.getCourse() == course) {
            totalAge += student.getAge();
            count++;
        }
    }

    if (count == 0) {
        return 0.0f;
    }

    return static_cast<double>(totalAge) / count;
}