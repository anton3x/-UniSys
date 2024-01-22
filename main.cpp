#include <iostream>
#include "person.h"
#include "student.h"
#include "course.h"
#include "professor.h"
#include "subject.h"
#include "university.h"

#include <cstring>

int main() {

    University utad;

    int op, op2, op3, op4, op5;

    do
    {
        std::cout << "\n------------MENU---------------" << std::endl;
        std::cout << "|\t0 - University        |" << std::endl;
        std::cout << "|\t1 - Courses           |" << std::endl;
        std::cout << "|\t2 - Students          |" << std::endl;
        std::cout << "|\t3 - Professors        |" << std::endl;
        std::cout << "|\t4 - Subjects          |" << std::endl;
        std::cout << "|\t5 - Load Database     |" << std::endl;
        std::cout << "|\t6 - Save Database     |" << std::endl;
        std::cout << "|\t99 - Exit             |" << std::endl;
        std::cout << "-------------------------------" << std::endl;

        std::cout << "Enter an option: ";
        std::cin >> op;

        switch(op)
        {
            case 0:
            {
                do {
                    system("cls");
                    std::cout << "\n\n-----------------------MENU(0)-----------------------" << std::endl;
                    std::cout << "|\t1 - Add courses                            |" << std::endl;
                    std::cout << "|\t2 - Remove courses                         |" << std::endl;
                    std::cout << "|\t3 - Show all courses                       |" << std::endl;
                    std::cout << "|\t4 - Add students                           |" << std::endl;
                    std::cout << "|\t5 - Remove students                        |" << std::endl;
                    std::cout << "|\t6 - Show all students                      |" << std::endl;
                    std::cout << "|\t7 - View university director               |" << std::endl;
                    std::cout << "|\t8 - Change university director             |" << std::endl;
                    std::cout << "|\t9 - Show all professors                    |" << std::endl;
                    std::cout << "|\t99 - Exit                                  |" << std::endl;
                    std::cout << "-----------------------------------------------------" << std::endl;
                    std::cout << "Enter an option: ";

                    std::cin >> op3;
                    switch (op3)
                    {
                        case 1:
                        {
                            utad.addCourses();
                            system("pause");
                            break;
                        }
                        case 2:
                        {
                            utad.remCourses();
                            system("pause");
                            break;
                        }
                        case 3:
                        {
                            utad.showCourses();
                            system("pause");
                            break;
                        }
                        case 4:
                        {
                            utad.addStudents();
                            system("pause");
                            break;
                        }
                        case 5:
                        {
                            utad.delStudents();
                            system("pause");
                            break;
                        }
                        case 6:
                        {
                            utad.showStudents(true);
                            system("pause");
                            break;
                        }
                        case 7:
                        {
                            utad.showDirector(true);
                            system("pause");
                            break;
                        }
                        case 8:
                        {
                            utad.changeDirector(true);
                            system("pause");
                            break;
                        }
                        case 9:
                        {
                            utad.showProfessors();
                            system("pause");
                            break;
                        }
                        case 99:
                        {
                            system("cls");
                            continue;
                        }
                        default:
                            std::cout << "Option not found!!!!" << std::endl;
                    }

                }while(op3 != 99);
                break;
            }
            case 1:
            {
                do {
                    system("cls");
                    std::cout << "\n\n-----------------------MENU(1)-----------------------" << std::endl;
                    std::cout << "|\t 1 - Add students to the course            |" << std::endl;
                    std::cout << "|\t 2 - Remove students from the course       |" << std::endl;
                    std::cout << "|\t 3 - Show students in the course           |" << std::endl;
                    std::cout << "|\t 4 - Show director of the course           |" << std::endl;
                    std::cout << "|\t 5 - Show vice director of the course      |" << std::endl;
                    std::cout << "|\t 6 - Show vogal of the course              |" << std::endl;
                    std::cout << "|\t 7 - Show subjects of the course           |" << std::endl;
                    std::cout << "|\t 8 - Remove subjects from the course       |" << std::endl;
                    std::cout << "|\t 9 - Add subjects to the course            |" << std::endl;
                    std::cout << "|\t10 - Change course name                    |" << std::endl;
                    std::cout << "|\t11 - Change director of the course         |" << std::endl;
                    std::cout << "|\t12 - Change vice director of the course    |" << std::endl;
                    std::cout << "|\t13 - Change vocal of the course            |" << std::endl;
                    std::cout << "|\t99 - Exit                                  |" << std::endl;
                    std::cout << "-----------------------------------------------------" << std::endl;
                    std::cout << "Enter an option: ";

                    std::cin >> op3;
                    switch (op3)
                    {
                        case 1:
                        {
                            utad.addStudents();
                            system("pause");
                            break;
                        }
                        case 2:
                        {
                            utad.delStudents();
                            system("pause");
                            break;
                        }
                        case 3:
                        {
                            utad.showStudents(false);
                            system("pause");
                            break;
                        }
                        case 4:
                        {
                            utad.showDirector(false);
                            system("pause");
                            break;
                        }
                        case 5:
                        {
                            utad.showViceDirectorCourse();
                            system("pause");
                            break;
                        }
                        case 6:
                        {
                            utad.showVogalCourse();
                            system("pause");
                            break;
                        }
                        case 7:
                        {
                            utad.showSubjectsCourse();
                            system("pause");
                            break;
                        }
                        case 8:
                        {
                            utad.remSubject();
                            system("pause");
                            break;
                        }
                        case 9:
                        {
                            utad.addSubject();
                            system("pause");
                            break;
                        }
                        case 10:
                        {
                            utad.changeCourseName();
                            system("pause");
                            break;
                        }
                        case 11:
                        {
                            utad.changeDirector(false);
                            system("pause");
                            break;
                        }
                        case 12:
                        {
                            utad.changeViceDirectorCourse();
                            system("pause");
                            break;
                        }
                        case 13:
                        {
                            utad.changeVogalCourse();
                            system("pause");
                            break;
                        }
                        case 99: {
                            system("cls");
                            break;
                        }
                        default:
                            std::cout << "Option not found!!!!" << std::endl;
                    }

                }while(op3 != 99);
                break;
            }
            case 2:
            {
                do {
                    system("cls");
                    std::cout << "\n\n-----------------------MENU(2)-----------------------" << std::endl;
                    std::cout << "|\t 1 - Change student name                   |" << std::endl;
                    std::cout << "|\t 2 - Change student age                    |" << std::endl;
                    std::cout << "|\t 3 - Change student address                |" << std::endl;
                    std::cout << "|\t 4 - Change student course name            |" << std::endl;
                    std::cout << "|\t 5 - Change student enrollment year        |" << std::endl;
                    std::cout << "|\t 6 - View student name                     |" << std::endl;
                    std::cout << "|\t 7 - View student age                      |" << std::endl;
                    std::cout << "|\t 8 - View student address                  |" << std::endl;
                    std::cout << "|\t 9 - View student course name              |" << std::endl;
                    std::cout << "|\t10 - View student enrollment year          |" << std::endl;
                    std::cout << "|\t11 - View student ID number                |" << std::endl;
                    std::cout << "|\t99 - Exit                                  |" << std::endl;
                    std::cout << "-----------------------------------------------------" << std::endl;
                    std::cout << "Enter an option: ";
                    std::cin >> op2;
                    switch (op2)
                    {
                        case 1:
                        {
                            utad.changeNameStudent();
                            system("pause");
                            break;
                        }
                        case 2:
                        {
                            utad.changeAgeStudent();
                            system("pause");
                            break;
                        }
                        case 3:
                        {
                            utad.changeAddressStudent();
                            system("pause");
                            break;
                        }
                        case 4:
                        {
                            utad.changeNameCourseStudent();
                            system("pause");
                            break;
                        }
                        case 5:
                        {
                            utad.changeMatriculationYearStudent();
                            system("pause");
                            break;
                        }
                        case 6:
                        {
                            utad.showNameStudent();
                            system("pause");
                            break;
                        }
                        case 7:
                        {
                            utad.showAgeStudent();
                            system("pause");
                            break;
                        }
                        case 8:
                        {
                            utad.showAddressStudent();
                            system("pause");
                            break;
                        }
                        case 9:
                        {
                            utad.showCourseNameStudent();
                            system("pause");
                            break;
                        }
                        case 10:
                        {
                            utad.showMatriculationYearStudent();
                            system("pause");
                            break;
                        }
                        case 11:
                        {
                            utad.showAlNumberStudent();
                            system("pause");
                            break;
                        }
                        case 99:
                            system("cls");
                            break;
                        default:
                            std::cout << "Option not found!!!!" << std::endl;
                    }

                }while(op2 != 99);
                break;
            }
            case 3:
            {
                do {
                    system("cls");
                    std::cout << "\n\n-----------------------MENU(3)---------------------------" << std::endl;
                    std::cout << "|\t 1 - Show name of a professor                   |" << std::endl;
                    std::cout << "|\t 2 - Show age of a professor                    |" << std::endl;
                    std::cout << "|\t 3 - Show address of a professor                |" << std::endl;
                    std::cout << "|\t 4 - Show salary of a professor                 |" << std::endl;
                    std::cout << "|\t 5 - Show courses taught by a professor         |" << std::endl;
                    std::cout << "|\t 6 - Change name of a professor                 |" << std::endl;
                    std::cout << "|\t 7 - Change age of a professor                  |" << std::endl;
                    std::cout << "|\t 8 - Change address of a professor              |" << std::endl;
                    std::cout << "|\t 9 - Change salary of a professor               |" << std::endl;
                    std::cout << "|\t10 - Add courses to teach for a professor       |" << std::endl;
                    std::cout << "|\t11 - Remove courses to teach for a professor    |" << std::endl;
                    std::cout << "|\t99 - Exit                                       |" << std::endl;
                    std::cout << "---------------------------------------------------------" << std::endl;
                    std::cout << "Enter an option: ";

                    std::cin >> op4;
                    switch (op4)
                    {
                        case 1:
                        {
                            utad.showNameProfessor();
                            system("pause");
                            break;
                        }
                        case 2:
                        {
                            utad.showAgeProfessor();
                            system("pause");
                            break;
                        }
                        case 3:
                        {
                            utad.showAddressProfessor();
                            system("pause");
                            break;
                        }
                        case 4:
                        {
                            utad.showSalaryProfessor();
                            system("pause");
                            break;
                        }
                        case 5:
                        {
                            utad.showCoursesOnProfessor();
                            system("pause");
                            break;
                        }
                        case 6:
                        {
                            utad.changeNameProfessor();
                            system("pause");
                            break;
                        }
                        case 7:
                        {
                            utad.changeAgeProfessor();
                            system("pause");
                            break;
                        }
                        case 8:
                        {
                            utad.changeAddressProfessor();
                            system("pause");
                            break;
                        }
                        case 9:
                        {
                            utad.changeSalaryProfessor();
                            system("pause");
                            break;
                        }
                        case 10:
                        {
                            utad.addCoursesToTeachProfessor();
                            system("pause");
                            break;
                        }
                        case 11:
                        {
                            utad.removeCoursesToTeachProfessor();
                            system("pause");
                            break;
                        }
                        case 99: {
                            system("cls");
                            break;
                        }
                        default:
                            std::cout << "Option not found!!!!" << std::endl;
                    }

                }while(op4 != 99);
                break;
            }
            case 4:
            {
                do {
                    system("cls");
                    std::cout << "\n\n-----------------------MENU(4)----------------------------------" << std::endl;
                    std::cout << "|\t 1 - Show bibliography of a subject                      |" << std::endl;
                    std::cout << "|\t 2 - Show objectives of a subject                        |" << std::endl;
                    std::cout << "|\t 3 - Show assessment methodology of a subject            |" << std::endl;
                    std::cout << "|\t 4 - Show the main professor of a subject                |" << std::endl;
                    std::cout << "|\t 5 - Show the assistant professors of a subject          |" << std::endl;
                    std::cout << "|\t 6 - Change bibliography of a subject                    |" << std::endl;
                    std::cout << "|\t 7 - Change objectives of a subject                      |" << std::endl;
                    std::cout << "|\t 8 - Change assessment methodology of a subject          |" << std::endl;
                    std::cout << "|\t11 - Add an assistant professor to a subject             |" << std::endl;
                    std::cout << "|\t12 - Remove an assistant professor from a subject        |" << std::endl;
                    std::cout << "|\t99 - Exit                                                |" << std::endl;
                    std::cout << "----------------------------------------------------------------" << std::endl;
                    std::cout << "Enter an option: ";
                    std::cin >> op5;
                    switch (op5)
                    {
                        case 1:
                        {
                            utad.viewSubjectBibliography();
                            system("pause");
                            break;
                        }
                        case 2:
                        {
                            utad.viewSubjectObjectives();
                            system("pause");
                            break;
                        }
                        case 3:
                        {
                            utad.viewSubjectMethodology();
                            system("pause");
                            break;
                        }
                        case 4:
                        {
                            utad.viewSubjectMainProfessor();
                            system("pause");
                            break;
                        }
                        case 5:
                        {
                            utad.viewSubjectAssistantProfessors();
                            system("pause");
                            break;
                        }
                        case 6:
                        {
                            utad.changeSubjectBibliography();
                            system("pause");
                            break;
                        }
                        case 7:
                        {
                            utad.changeSubjectObjectives();
                            system("pause");
                            break;
                        }
                        case 8:
                        {
                            utad.changeSubjectMethodology();
                            system("pause");
                            break;
                        }
                        case 11:
                        {
                            utad.addSubjectAssistantProfessor();
                            system("pause");
                            break;
                        }
                        case 12:
                        {
                            utad.removeSubjectAssistantProfessor();
                            system("pause");
                            break;
                        }
                        case 99: {
                            system("cls");
                            break;
                        }
                        default:
                            std::cout << "Option not found!!!!" << std::endl;
                    }

                }while(op5 != 99);
                break;
            }
            case 5:
            {
                utad.LoadDB("students.txt","courses.txt","cadeiras.txt","professores.txt","diretores.txt","viceDiretores.txt","vogais.txt","dirUni.txt");
                system("pause");
                system("cls");
                break;
            }
            case 6:
            {
                utad.SaveDB("students.txt","courses.txt","cadeiras.txt","professores.txt","diretores.txt","viceDiretores.txt","vogais.txt", "dirUni.txt");
                system("pause");
                system("cls");
                break;
            }
            case 99: {
                std::cout << "!!!Bye!!!";
                break;
            }

            default: {
                std::cout << "Option not found!!!!" << std::endl;
                system("pause");
                system("cls");
                break;
            }
        }

    }
    while(op != 99);
    system("pause");
    return 0;
}

