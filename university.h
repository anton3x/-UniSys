#include <iostream>
#include <vector>
#include "person.h"
#include "person.h"
#include "professor.h"
#include "course.h"



#ifndef SIP_University_H
#define SIP_University_H


class University {
private:
    std::vector<Student> students;
    std::vector<Course> courses;
    Person directorUniversity;
public:
    University();
    University(std::vector<Student>& students, std::vector<Course>& courses, Person directorUniversity);

    void showStudents(bool all);
    void showCourses();
    void showDirector(bool directorUni);
    void showViceDirectorCourse();
    void showVogalCourse();
    void showProfessors();
    void showSubjectsCourse();
    inline Person getDirectorUni(){return this->directorUniversity;};
    std::vector<Professor> getProfessors();

    inline void setDirectorUni(Person directorUniversity){this->directorUniversity = directorUniversity;}
    void setDirectorCourse(Person director, std::string course);
    void setViceDirectorCourse(Person viceDirector, std::string course);
    void setVogalCourse(Person vogal, std::string course);
    inline void setCourses(std::vector<Course> courses){this->courses = courses;}
    inline void setStudents(std::vector<Student> students){this->students = students;}

    //uni
    void addCourses();
    void addCourses(Course course); //adiciona um Course ao vetor Courses diretamente
    void remCourses();
    void addStudents();//vai pedir as informacoes, nao se pode passar diretamente o objeto Student
    void addStudents(Student student); //adiciona diretamente o Student ao vetor Students
    void delStudents();
    void changeDirector(bool uni);
    void changeViceDirectorCourse();
    void changeVogalCourse();
    void changeCourseName();

    //Course
    void changeNameStudent();
    void changeAgeStudent();
    void changeAddressStudent();
    void changeNameCourseStudent();
    void changeMatriculationYearStudent();
    void showNameStudent();
    void showAgeStudent();
    void showAddressStudent();
    void showCourseNameStudent();
    void showMatriculationYearStudent();
    void showAlNumberStudent();

    void updateSubjectOnCourses(Subject c);
    void addSubject();
    void addSubject(Subject c);
    void remSubject();
    void remSubject(Subject c);

    //professor
    void changeNameProfessor();
    void changeAgeProfessor();
    void changeAddressProfessor();
    void changeSalaryProfessor();
    void addCoursesToTeachProfessor();
    void removeCoursesToTeachProfessor();
    void showNameProfessor();
    void showAgeProfessor();
    void showAddressProfessor();
    void showSalaryProfessor();
    void showCoursesOnProfessor();

    //cadeira
    void viewSubjectBibliography();
    void viewSubjectObjectives();
    void viewSubjectMethodology();
    void viewSubjectMainProfessor();
    void viewSubjectAssistantProfessors();
    void changeSubjectBibliography();
    void changeSubjectObjectives();
    void changeSubjectMethodology();
    void changeSubjectMainProfessor();
    void changeSubjectAssistantProfessors();
    void addSubjectAssistantProfessor();
    void removeSubjectAssistantProfessor();


    friend std::ofstream & operator << (std::ofstream &c, University &u);
    void SaveDB(string studentsFileName,string coursesFileName,string subjectsFileName,string professorsFileName,string directoresFileName,string viceDirectoresFileName,string vogaisFileName, string directoresUniFileName);
    void LoadDB(string studentsFileName,string coursesFileName,string subjectsFileName,string professorsFileName,string directoresFileName,string viceDirectoresFileName,string vogaisFileName, string directoresUniFileName);
    ~University();

};


#endif //SIP_University_H
