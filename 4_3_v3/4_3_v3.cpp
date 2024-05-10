#include <iostream>
#include "Database.h"

using namespace std;

int main() {
    int numStudents;

    cout << "Enter number of students: ";
    cin >> numStudents;
    cout << endl;

    // ������ �������� ������ Student
    Database database;

    // ���������� ����� ������ � ����������
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student #" << i + 1 << endl;
        database.addStudent();
        cout << endl;
    }

    // ����� ���� ���������
    cout << "List of all students:" << endl;
    database.printAllStudents();

    // ����� ��������� �� ���
    char searchName[50];
    cout << "Input NAME for search: ";
    cin >> searchName;
    cout << endl;
    database.findStudents(searchName);

    // ������� ������� ��������� n-�� �����
    int course;
    cout << "Enter number of course you would like to know average age: ";
    cin >> course;
    float averageCourse = database.getAverageAgeForCourse(course);
    cout << "Average age of students " << course << " in course: " << averageCourse << endl;

    return 0;
}