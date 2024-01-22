#include "course.h"
#include <fstream>

#ifndef SIP_Course
#define SIP_Course

Course::Course() {
}
Course::Course(std::string courseName, std::vector<Student>& students, Person courseDirector, Person courseViceDirector, Person courseVogal, std::vector<Subject> subjects)
{
    this->courseName = courseName;
    this->students = students;
    this->courseDirector = courseDirector;
    this->courseViceDirector = courseViceDirector;
    this->courseVogal = courseVogal;
    this->subjects = subjects;
}

void Course::showSubjects() {
    int nSubjects = 0;

    std::cout << "----------------------------------------------------" << std::endl;
    for (int i = 0; i < subjects.size(); i++)
    {
        std::cout <<"| "<< nSubjects++ << " - " <<  subjects[i].getSubjectName() << " |"<< std::endl;
    }
    std::cout << "----------------------------------------------------" << std::endl;

}
void Course::showStudents() {
    std::cout << "Enrolled Students in " << getCourseName() << ": " << std::endl;
    int nStudent = 0;

    std::cout << "------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < this->students.size(); i++)
    {
        std::cout <<"| " << nStudent++ << " - " << students[i].getAlNumber() << " / " << students[i].getName() << " / " << students[i].getAge()<< " / " << students[i].getAddress() << " |" << std::endl;
    }
    std::cout << "------------------------------------------------------------------" << std::endl;

}
void Course::addStudents(Student student)
{
    bool found = false;
    for(int i = 0 ; i < students.size(); i++)
    {
        if(students[i].getName() == student.getName())
        {
            found = true;
            std::cout << "Student is already in the course !!!\n";
        }
    }
    if(!found) {
        this->students.push_back(student);
        std::cout << "Student added to the course -> " << student.getCourse() << "!!!\n";

    }

}
void Course::remStudents(Student student)
{
    for (int i = 0; i < this->students.size(); i++)
    {
        if (students[i].getAlNumber() == student.getAlNumber())
        {
            students.erase(students.begin() + i);

        }
    }
}
void Course::remStudents(int alNumber)
{
    for (int i = 0; i < this->students.size(); i++)
    {
        if (students[i].getAlNumber() == alNumber)
        {
            students.erase(students.begin() + i);

        }
    }
}
std::ofstream & operator << (std::ofstream &c, Course &course)
{
    c << course.getCourseName() << ";" << course.getNumberSubjects()<< ";";
    for (int i = 0; i < course.getNumberSubjects(); i++)
    {
        c << course.getSubjects()[i].getSubjectName() << ";";
    }
    c << course.getCourseDirector().getName() << ";" << course.getCourseViceDirector().getName() << ";" << course.getCourseVogal().getName() << ";";
    return c;
}
void Course::changeSubject(Subject subject) {
    for(int i = 0; i < subjects.size(); i++)
    {
        if (subjects[i].getSubjectName()==subject.getSubjectName())
        {
            subjects[i] = subject;
        }
    }
}
void Course::changeStudent(Student student) {
    for(int i = 0; i < students.size(); i++)
    {
        if (students[i].getAlNumber() == student.getAlNumber())
        {
            students[i] = student;
        }
    }
}
void Course::addSubject(Subject subject) {
    bool found = false;
    for(int i = 0; i < this->subjects.size(); i++)
    {
        if(subjects[i].getSubjectName() == subject.getSubjectName())
            found = true;
    }
    if(!found)
        subjects.push_back(subject);
}
void Course::remSubject(Subject subject) {
    bool found = false;
    vector<Subject>::iterator it;
    for(it = subjects.begin() ; it != subjects.end(); it++)
    {
        if((*it).getSubjectName() == subject.getSubjectName()) {
            found = true;
            subjects.erase(it);
        }
    }
    if(!found)
        std::cout << "Subject not found!!!" << std::endl;
}

void Course::ReadFile(std::ifstream &file) {
    char aux[200];
    int nSubjects;

    file.getline(aux, 200, ';');
    this->setCourseName(aux);

    file.getline(aux, 200, ';');
    nSubjects = atoi(aux);

    /*do later*/

}

Course::~Course() {}


#endif