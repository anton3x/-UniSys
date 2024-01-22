#include "person.h"
#include <fstream>
Person::Person() {
    alNumber = idReference++;
}
Person::Person(int age, std::string name, std::string address) {
    alNumber = idReference++;
    this->name = name;
    this->address = address;
    this->age = age;
}


std::ostream & operator << (std::ostream &c, Person &p)
{
    c << "Name: " << p.getName() << std::endl;
    c << "Age: " << p.getAge() << std::endl;
    c << "Address: " << p.getAddress() << std::endl;
    return c;
}

std::ofstream & operator << (std::ofstream &c, Person &p)
{
    c << p.getName() << ";" << p.getAge() << ";" << p.getAddress() << ";";
    return c;
}

std::istream & operator >> (std::istream &c, Person &p) {

    fflush(stdin);
    std::cout << "Name: ";
    std::getline(std::cin, p.name);
    fflush(stdin);

    std::cout << "Age: ";
    c >> p.age;
    fflush(stdin);

    std::cout << "Address: ";
    std::getline(std::cin, p.address);
    fflush(stdin);
    return c;
}
int Person::idReference = 0;

void Person::ReadFile(std::ifstream &file) {
    char aux[100];

    file.getline(aux, 100, ';');
    setName(aux);

    file.getline(aux, 100, ';');
    setAge(atoi(aux));

    file.getline(aux, 100, ';');
    setAddress(aux);
}


Person::~Person() {}