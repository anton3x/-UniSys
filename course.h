#include "student.h"
#include "subject.h"
#include <vector>

#ifndef SIP_Course_H
#define SIP_Course_H


class Course {
private:
    std::string courseName;
    std::vector<Student> students;
    Person courseDirector, courseViceDirector, courseVogal;
    std::vector<Subject> subjects;
public:
    Course();
    Course(std::string courseName, std::vector<Student>& students, Person courseDirector, Person courseViceDirector, Person courseVogal, std::vector<Subject> subjects);

    Person getCourseDirector(){return this->courseDirector;}
    Person getCourseViceDirector(){return this->courseViceDirector;}
    Person getCourseVogal(){return this->courseVogal;}
    std::string getCourseName(){return this->courseName;}
    int getNumberSubjects(){return this->subjects.size();}
    int getNumberStudents(){return this->students.size();}
    std::vector<Subject> getSubjects(){return this->subjects;};
    std::vector<Student> getStudents(){return this->students;};


    void showSubjects();
    void showStudents();
    inline void showDirector(){std::cout << courseDirector;}

    inline void setCourseName(std::string courseName){this->courseName = courseName;}
    inline void setDiretor(Person courseDirector){this->courseDirector = courseDirector;}
    inline void setViceDiretor(Person courseViceDirector){this->courseViceDirector = courseViceDirector;}
    inline void setVogal(Person courseVogal){this->courseVogal = courseVogal;}
    inline void setSubjects(std::vector<Subject> c){this->subjects = c;}

    void changeSubject(Subject subject);
    void addSubject(Subject subject);
    void remSubject(Subject subject);

    void changeStudent(Student student);
    void addStudents(Student student);
    void remStudents(Student student);
    void remStudents(int alNumber);


    friend std::ofstream & operator << (std::ofstream &c, Course &course);
    friend std::ifstream & operator >> (std::ifstream &c, Course &course);

    void ReadFile(std::ifstream &file);

    ~Course();
};


#endif //SIP_Course_H
