#include "student.h"

Student::Student() {}
Student::Student(int age, std::string name, std::string address, std::string course, int matriculationYear) : Person(age, name,address) {

    this->course = course;
    this->matriculationYear = matriculationYear;
}


bool operator == (Student &a1, Student &a2)
{
    if (a1.getName() == a2.getName())
    {
        if (a1.getAge() == a2.getAge())
        {
            if (a1.getAddress() == a2.getAddress())
            {
                return true;
            }
        }
    }
    return false;
}

std::ofstream & operator << (std::ofstream &c, Student &a)
{
    c << (Person &) a;
    c << a.getCourse() << ';' << a.getMatriculationYear() << ';';
    return c;
}
void Student::ReadFile(std::ifstream &file) {
    char aux[100];

    this->Person::ReadFile(file);
    file.getline(aux, 100, ';');
    this->setCourse(aux);

    file.getline(aux, 100, ';');
    this->setMatriculationYear(atoi(aux));
}

Student::~Student() {}