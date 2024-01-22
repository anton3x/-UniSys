#include "subject.h"

Subject::Subject() {}
Subject::Subject(std::string subjectName, Professor mainProfessor, Professor *assistantProfessors, int numAssistantProfessors, std::string bibliography, std::string objectives,std::string avaliationMethodology) {
    this->subjectName = subjectName;
    this->mainProfessor = mainProfessor;
    for(int i = 0; i < numAssistantProfessors; i++)
    {
        this->assistantProfessors.push_back(assistantProfessors[i]);
    }
    this->bibliography = bibliography;
    this->objectives = objectives;
    this->avaliationMethodology = avaliationMethodology;
}


std::ofstream & operator << (std::ofstream &c, Subject &ca)
{
    c << ca.getSubjectName() << ";" << ca.getBibliography() << ";" << ca.getObjectives() << ";" << ca.getAvaliationMethodology() << ";" << ca.getAssistantProfessors().size() << ";";
    for(int i = 0; i < ca.getAssistantProfessors().size(); i++)
    {
        c << ca.getAssistantProfessors()[i].getName() << ";";
    }
    c << ca.getMainProfessor().getName() << ";";
    return c;
}
std::istream & operator >> (std::istream &c, Subject &ca)
{
    int num;
    Professor p;

    fflush(stdin);
    std::cout << "Enter the name of the subject to be created: ";
    std::getline(std::cin, ca.subjectName);
    fflush(stdin);

    std::cout << "Enter the bibliography of the subject to be created: ";
    std::getline(std::cin, ca.bibliography);
    fflush(stdin);

    std::cout << "Enter the objectives of the subject to be created: ";
    std::getline(std::cin, ca.objectives);
    fflush(stdin);

    std::cout << "Enter the assessment methodology of the subject to be created: ";
    std::getline(std::cin, ca.avaliationMethodology);
    fflush(stdin);

    std::cout << "\nInformation about the main professor:" << std::endl;
    std::cin >> ca.mainProfessor;

    std::cout << "\nEnter the number of assistant professors to teach the subject: ";
    std::cin >> num;


    for(int i = 0 ; i < num; i++)
    {
        std::cin >> p;
        ca.assistantProfessors.push_back(p);
    }
    return c;
}


void Subject::ReadFile(std::ifstream &file) {
    char aux[100];
    int numProfAux;

    file.getline(aux, 100, ';');
    this->setSubjectName(aux);

    file.getline(aux, 100, ';');
    this->setBibliography(aux);

    file.getline(aux, 100, ';');
    this->setObjectives(aux);

    file.getline(aux, 100, ';');
    this->setAvaliationMethodology(aux);

    file.getline(aux, 100, ';');
    numProfAux = atoi(aux);

    for(int i = 0 ; i < numProfAux; i++)
    {
        file.getline(aux, 100, ';');

    }

}

Subject::~Subject(){}