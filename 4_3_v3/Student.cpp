#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
    : m_age(0), m_course(0), m_gender(' '), m_mark(0.0) {
    //memset(m_name, 0, sizeof(m_name));
    for (int i = 0; i < sizeof(m_name); ++i) {
        m_name[i] = 0;
    }
}

Student::Student(const char* name, int age, int course, char gender, double mark)
    : m_age(age), m_course(course), m_gender(gender), m_mark(mark) {
    for (int i = 0; i < sizeof(m_name); i++)
    {
        m_name[i] = 0;
    }
}

Student::Student(const Student& other)
    : m_age(other.m_age), m_course(other.m_course), m_gender(other.m_gender), m_mark(other.m_mark) {
    for (int i = 0; i < sizeof(m_name); i++)
    {
        m_name[i] = 0;
    }
    //strncpy_s(m_name, other.m_name, sizeof(m_name));
    int i = 0;
    while (other.m_name[i] != '\0' && i < sizeof(m_name - 1))
    {
        m_name[i] = other.m_name[i];
        i++;
    }
    m_name[i] = '\0';
}

Student::Student(Student&& other) noexcept
    : m_age(other.m_age), m_course(other.m_course), m_gender(other.m_gender), m_mark(other.m_mark) {
    for (int i = 0; i < sizeof(m_name); i++)
    {
        m_name[i] = 0;
    }
    //strncpy_s(m_name, other.m_name, sizeof(m_name));
    int i = 0;
    while (other.m_name[i] != '\0' && i < sizeof(m_name - 1))
    {
        m_name[i] = other.m_name[i];
        i++;
    }
    m_name[i] = '\0';
}

Student::~Student() {}

void Student::fillFromKeyboard() {
    cout << "Enter name: ";
    cin >> m_name;

    cout << "Enter age: ";
    cin >> m_age;
    while (m_age < 16)
    {
        cout << "Age must be >= 16 " << endl;
        cin >> m_age;
    }

    cout << "Enter course: ";
    cin >> m_course;

    cout << "Enter gender (M/F): ";
    cin >> m_gender;

    cout << "Enter Mark: ";
    cin >> m_mark;
}

void Student::saveToFile(ofstream& file) {
    file.write(reinterpret_cast<char*>(&m_name), sizeof(m_name));
    file.write(reinterpret_cast<char*>(&m_age), sizeof(m_age));
    file.write(reinterpret_cast<char*>(&m_course), sizeof(m_course));
    file.write(reinterpret_cast<char*>(&m_gender), sizeof(m_gender));
    file.write(reinterpret_cast<char*>(&m_mark), sizeof(m_mark));
}

void Student::loadFromFile(ifstream& file) {
    file.read(reinterpret_cast<char*>(&m_name), sizeof(m_name));
    file.read(reinterpret_cast<char*>(&m_age), sizeof(m_age));
    file.read(reinterpret_cast<char*>(&m_course), sizeof(m_course));
    file.read(reinterpret_cast<char*>(&m_gender), sizeof(m_gender));
    file.read(reinterpret_cast<char*>(&m_mark), sizeof(m_mark));
}

void Student::print() {
    cout << "Name: " << m_name << endl;
    cout << "Age: " << m_age << endl;
    cout << "Course: " << m_course << endl;
    cout << "Gender: " << m_gender << endl;
    cout << "Mark: " << m_mark << endl;
}

char* Student::getName() {
    return m_name;
}

int Student::getAge() {
    return m_age;
}

int Student::getCourse() {
    return m_course;
}

char Student::getGender() {
    return m_gender;
}

double Student::getMark() {
    return m_mark;
}