#include "professor.h"
Professor::Professor() {}
Professor::Professor(int age, std::string name, std::string address, std::string *coursesToTeach, int numberOfCoursesToTeach, float salary) : Person( age, name,  address){
    this->salary = salary;
    for(int i = 0; i < numberOfCoursesToTeach; i++)
    {
        this->coursesToTeach[i] = coursesToTeach[i];
    }
}

void Professor::addCoursesToTeach(std::string course)
{
    bool found = false;
    for(int i = 0 ; i < this->coursesToTeach.size(); i++)
    {
        if(coursesToTeach[i] == course)
        {
            found = true;
        }
    }
    if(!found)
        coursesToTeach.push_back(course);
}
void Professor::remCoursesToTeach(std::string course) {
    for(int i = 0 ; i < this->coursesToTeach.size(); i++)
    {
        if(coursesToTeach[i] == course)
        {
            coursesToTeach.erase(coursesToTeach.begin() + i);
        }
    }

}
std::ofstream & operator << (std::ofstream &c, Professor &p)
{
    c << (Person &) p;
    c << p.salary << ";" << p.coursesToTeach.size() << ";";

    for(int i = 0 ; i < p.coursesToTeach.size(); i++)
    {
        c << p.coursesToTeach[i] << ";";
    }
    return c;
}
std::istream & operator >> (std::istream &c, Professor &p)
{
    int numcourses;
    string course;
    float salary;

    std::cin >> (Person &) p;
    std::cout << "Enter the number of courses to teach: ";
    std::cin >> numcourses;

    for(int i = 0 ; i < numcourses; i++)
    {
        fflush(stdin);
        std::cout << "Enter the name of course " << i+1 << ": ";
        std::getline(std::cin, course);
        fflush(stdin);
        p.addCoursesToTeach(course);
        course="";
    }
    std::cout << "Enter the salary: ";
    std::cin >> salary;
    p.setSalary(salary);

    return c;
}

void Professor::ReadFile(std::ifstream &file)
{
    char aux[100];
    int numberOfCoursesToTeach;

    this->Person::ReadFile(file);
    file.getline(aux, 100, ';');
    this->setSalary(atof(aux));

    file.getline(aux, 100, ';');
    numberOfCoursesToTeach = atoi(aux);

    for(int i = 0 ; i < numberOfCoursesToTeach; i++)
    {
        file.getline(aux, 100, ';');
        this->addCoursesToTeach(aux);
    }


}


Professor::~Professor() {}

