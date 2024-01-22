#include "person.h"
//#include "curso.h"
#include <vector>
#include <fstream>

using namespace std;

#ifndef SIP_PROFESSOR_H
#define SIP_PROFESSOR_H


class Professor : public Person
{
private:
    vector<string> coursesToTeach;
    float salary;
public:
    Professor();
    Professor(int age, std::string name, std::string address, std::string *coursesToTeach, int numberOfCoursesToTeach, float salary);

    inline void setSalary(float salary){this->salary=salary;}
    inline float getSalary(){return this->salary;}

    inline void setCoursesToTeach(vector<string> &coursesToTeach){this->coursesToTeach = coursesToTeach;}
    inline vector<string> getCoursesToTeach(){return this->coursesToTeach;}
    void addCoursesToTeach(std::string course);
    void remCoursesToTeach(std::string course);

    friend std::ofstream & operator << (std::ofstream &c, Professor &p);
    friend std::istream & operator >> (std::istream &c, Professor &p);

    void ReadFile(std::ifstream &file);

    ~Professor();


};


#endif //SIP_PROFESSOR_H
