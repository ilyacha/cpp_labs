#include <iostream>
#include "Database.h"

using namespace std;

int main() {
    int numStudents;

    cout << "Enter number of students: ";
    cin >> numStudents;
    cout << endl;

    // массив объектов класса Student
    Database database;

    // заполнение полей класса с клавиатуры
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student #" << i + 1 << endl;
        database.addStudent();
        cout << endl;
    }

    // Вывод всех студентов
    cout << "List of all students:" << endl;
    database.printAllStudents();

    // Поиск студентов по ФИО
    char searchName[50];
    cout << "Input NAME for search: ";
    cin >> searchName;
    cout << endl;
    database.findStudents(searchName);

    // Средний возраст студентов n-го курса
    int course;
    cout << "Enter number of course you would like to know average age: ";
    cin >> course;
    float averageCourse = database.getAverageAgeForCourse(course);
    cout << "Average age of students " << course << " in course: " << averageCourse << endl;

    return 0;
}