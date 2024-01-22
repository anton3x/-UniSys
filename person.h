#include <iostream>
#ifndef SIP_Person_H
#define SIP_Person_H


class Person {
private:
    int alNumber;
    static int idReference;
    int age;
    std::string name;
    std::string address;
public:
    Person();
    Person(int idade, std::string nome, std::string morada);


    inline void setName(std::string name){this->name = name;}
    inline void setAge(int age){this->age = age;}
    inline void setAddress(std::string address){this->address = address;}
    inline void setAlNumber(int alnumber){this->alNumber=alnumber;};

    inline std::string getName(){return this->name;}
    inline int getAge(){return this->age;}
    inline std::string getAddress(){return this->address;}
    inline long int getAlNumber(){return this->alNumber;};

    friend std::ostream & operator << (std::ostream &c, Person &p);
    friend std::ofstream & operator << (std::ofstream &c, Person &p);
    friend std::istream & operator >> (std::istream &c, Person &p);

    //file operators override
    void ReadFile(std::ifstream &file);
    void SaveFile(std::ofstream &file);


    ~Person();
};


#endif //SIP_Person_H
