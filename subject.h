#ifndef SIP_Subject_H
#define SIP_Subject_H
#include <iostream>
#include "professor.h"
#include <fstream>
#include <vector>

class Subject {
private:
    std::string subjectName, bibliography, objectives,avaliationMethodology;
    Professor mainProfessor;
    std::vector<Professor> assistantProfessors;
public:
    Subject();
    Subject(std::string subjectName, Professor mainProfessor, Professor *assistantProfessors, int numAssistantProfessors, std::string bibliography, std::string objectives,std::string avaliationMethodology);

    inline std::string getSubjectName(){return this->subjectName;}
    inline std::string getBibliography(){return this->bibliography;}
    inline std::string getObjectives(){return this->objectives;}
    inline std::string getAvaliationMethodology(){return this->avaliationMethodology;}
    inline Professor getMainProfessor(){return this->mainProfessor;}
    inline std::vector<Professor> getAssistantProfessors(){return this->assistantProfessors;}

    inline void setSubjectName(std::string subjectName){this->subjectName=subjectName;}
    inline void setBibliography(std::string biliografia){this->bibliography=biliografia;}
    inline void setObjectives(std::string objectives){this->objectives=objectives;}
    inline void setAvaliationMethodology(std::string avaliationMethodology){this->avaliationMethodology=avaliationMethodology;}
    inline void setMainProfessor(Professor mainProfessor){this->mainProfessor=mainProfessor;}
    inline void setAssistantProfessors(std::vector<Professor> assistantProfessors){this->assistantProfessors = assistantProfessors;}

    inline void setNameMainProfessor(std::string name){mainProfessor.setName(name);}
    inline void setAgeMainProfessor(int age){mainProfessor.setAge(age);}
    inline void setAddressMainProfessor(std::string address){mainProfessor.setAddress(address);}
    inline void setSalaryMainProfessor(float salary){mainProfessor.setSalary(salary);}
    inline void setCoursesToTeachProfPrincipal(std::vector<string> courses){mainProfessor.setCoursesToTeach(courses);}

    friend std::ofstream & operator << (std::ofstream &c, Subject &ca);
    friend std::istream & operator >> (std::istream &c, Subject &ca);
    friend std::ostream & operator << (std::ostream &c, Subject &ca);

    void changeProfessor(Professor p, std::vector<Professor> v, bool main);

    void ReadFile(std::ifstream &file);
    virtual ~Subject();

};


#endif //SIP_Subject_H
