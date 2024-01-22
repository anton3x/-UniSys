#include "person.h"
#include <fstream>

#ifndef SIP_Student_H
#define SIP_Student_H

class Student : public Person{
private:
    std::string course;
    int matriculationYear;
public:
    Student();
    Student(int age, std::string name, std::string address, std::string course, int matriculationYear);


    std::string getCourse(){return this->course;}
    int getMatriculationYear(){return this->matriculationYear;}

    void setCourse(std::string course){this->course = course;}
    void setMatriculationYear(int matriculationYear){this->matriculationYear=matriculationYear;}

    friend bool operator == (Student &a1, Student &a2);
    friend std::ofstream & operator << (std::ofstream &c, Student &a);

    void ReadFile(std::ifstream &file);

    ~Student();
};


#endif //SIP_Student_H
