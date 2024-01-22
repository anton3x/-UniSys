#include "university.h"
#include "fstream"
#include <algorithm>

#ifndef SIP_University
#define SIP_University

University::University() {}
University::University(std::vector<Student> &students, std::vector<Course> &courses, Person director) {
    this->students = students;
    this->courses = courses;
    this->directorUniversity = director;
}

void University::showStudents(bool all=true) {
    if (all==true) {

        std::cout << "Students enrolled in this University: " << std::endl;

        int nStudent = 0;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "| id - alnumber / name / age / address |"<< std::endl;
        for (int i = 0; i < students.size(); i++) {
            std::cout << "| " << nStudent++ << " - " << students[i].getAlNumber() << " / " << students[i].getName() << " / " << students[i].getAge() << " / "
                      << students[i].getAddress() << " |" << std::endl;
        }
        std::cout << "------------------------------------------------------------------" << std::endl;

    }
    else
    {
        fflush(stdin);
        std::string courseName;
        std::cout << "Enter the name of the course you want to see the students: ";
        std::getline(std::cin, courseName);
        fflush(stdin);

        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].getCourseName() == courseName)
            {
                courses[i].showStudents();
            }
        }
    }
}
void University::addStudents() {

    std::string nameStudent, address, courseName;
    int age, matriculationYear, nStudentsAdd;

    std::cout << "\nNumber of students to add:";
    std::cin >> nStudentsAdd;

    for (int i = 0; i < nStudentsAdd; i++) {

        fflush(stdin);
        std::cout << "What is the student's name: ";
        std::getline(std::cin, nameStudent);
        fflush(stdin);

        std::cout << "How old are you: ";
        std::cin >> age;

        fflush(stdin);
        std::cout << "Enter the address of the student: ";
        std::getline(std::cin, address);
        fflush(stdin);

        std::cout << "Enter the year he/she is in the course: ";
        std::cin >> matriculationYear;

        fflush(stdin);
        std::cout << "Enter the course that the student attends: ";
        std::getline(std::cin, courseName);
        fflush(stdin);

        Student newStudent(age, nameStudent, address, courses[i].getCourseName(), matriculationYear);
        this->addStudents(newStudent);

        fflush(stdin);
    }

}
void University::addStudents(Student student) {
    bool found = false;
    for(int i = 0 ; i < students.size(); i++)
    {
        if(students[i].getName() == student.getName())
        {
            found = true;
            std::cout << "Student is already enrolled in the University !!!\n";

        }
    }
    if(!found) {
        this->students.push_back(student);
        for(int i = 0; i < this->courses.size();i++) //ver o Course onde o Student esta inscrito e coloca-lo la dentro na lista de students do Course
        {
            if(courses[i].getCourseName()==student.getCourse())
            {
                courses[i].addStudents(student);
            }
        }
        std::cout << "Student added to the University !!!\n";

    }
}
void University::delStudents() {
    
    std::string courseName;
    int nStudentsRemove, alNumber;

    std::cout << "\nEnter the number of students to remove: ";
    std::cin >> nStudentsRemove;

    for (int i = 0; i < nStudentsRemove; i++) {

        std::cout << "Introduza o al do Student a remover: ";
        std::cin >> alNumber;

        fflush(stdin);
        std::cout << "Course Name: ";
        std::getline(std::cin, courseName);
        fflush(stdin);

        bool alValid=false, courseNameValid=false;
        int courseIndex, studentIndex;

        for(int i = 0; i < courses.size(); i++)
        {
            if(courses[i].getCourseName() == courseName) {
                courseNameValid = true;
                courseIndex = i;
                break;
            }
        }

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getAlNumber() == alNumber) {
                alValid = true;
                studentIndex = i;
            }
        }

        if (alValid and courseNameValid) {
            courses[courseIndex].remStudents(alNumber);
            std::cout << "The student " << students[i].getName() << " successfully removed from the course list!!!" << std::endl;
            students.erase(students.begin() + studentIndex);
            std::cout << "The student " << students[i].getName() << " successfully removed from the student list!!!" << std::endl;
        }

        if (!alValid)
            std::cout << "Student does not exist!!!" << std::endl;

        if (!courseNameValid)
            std::cout << "Course ->" << courseName << "<- does not exist!!!" << std::endl;

    }
}

void University::showCourses() {

    std::cout << "\nExisting courses in this University: " << std::endl;
    int nCourse = 0;
    std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "| id - name / number of students / number of subjects / name director / name vice director / name vocal |" << std::endl;
    for(int i = 0; i < courses.size(); i++)
    {
        std::cout <<"| " << nCourse++ << " - " << courses[i].getCourseName() << " / " << courses[i].getNumberStudents() << " / " << courses[i].getNumberSubjects() << " / " << courses[i].getCourseDirector().getName() << " / " << courses[i].getCourseViceDirector().getName() << " / " << courses[i].getCourseVogal().getName() <<  " |" << std::endl;
    }
    std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;

}
void University::showProfessors() {
    std::cout << "\nExisting professors in this University: " << std::endl;
    int nProfessor = 0;
    std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "| id - alNumber / name / age / address / salary |" << std::endl;

    std::vector<Professor> p = getProfessors();
    for(int i = 0; i < p.size(); i++)
    {
        std::cout <<"| " << nProfessor++ << " - " << p[i].getAlNumber() << " / "<< p[i].getName() << " / " << p[i].getAge() << " / " << p[i].getAddress() << " / " << p[i].getSalary() <<  " |" << std::endl;
    }
    std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;
}
void University::addCourses() {
    std::string courseName;
    Course c;
    int numberOfCourses;
    bool found = false;

    std::cout << "\nHow many courses do you want to add: ";
    std::cin >> numberOfCourses;

    for (int i = 0; i < numberOfCourses; i++)
    {
        fflush(stdin);
        std::cout << "Course Name: ";
        std::getline(std::cin, courseName);
        fflush(stdin);

        c.setCourseName(courseName);

        for(int i = 0 ; i < courses.size(); i++)
        {
            if(courses[i].getCourseName() == c.getCourseName())
            {
                found = true;
                std::cout << "Course already exists in the University !!!\n";
                break;

            }
        }
        if(!found) {
            this->courses.push_back(c);
            std::cout << "Course -> " << courseName << " <- successfully added to the University !!!\n";
        }

    }

}
void University::addCourses(Course course)
{
    bool found = false;
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].getCourseName() == course.getCourseName()) {
            found = true;
            std::cout << "Course already exists in the University !!!\n";
            break;
        }
    }

    if (!found) {
        this->courses.push_back(course);
        std::cout << "Course successfully added to the University !!!\n";
    }

}
void University::remCourses() {
    std::string courseName;
    int numberOfCourses;
    bool found=false;

    std::cout << "How many courses to remove: ";
    std::cin >> numberOfCourses;

    for (int i = 0; i < numberOfCourses; i++) {

        fflush(stdin);
        std::cout << "Course Name: ";
        std::getline(std::cin, courseName);
        fflush(stdin);

        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].getCourseName() == courseName) {
                found = true;
                courses.erase(courses.begin() + i);
                std::cout << "Course successfully removed!!!\n";
            }
        }
    }
    if (!found)
    {
        std::cout << "Course not found!!!\n";
    }
}

void University::showSubjectsCourse() {

    fflush(stdin);
    std::string courseName;
    std::cout << "Enter the name of the course you want to see the subjects for: ";
    std::getline(std::cin, courseName);
    fflush(stdin);

    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i].getCourseName() == courseName)
        {
            std::cout << "All subjects of " << courseName << ": " << std::endl;
            courses[i].showSubjects();
        }
    }
}
void University::updateSubjectOnCourses(Subject subject) {
    for(int i = 0 ; i < courses.size(); i++)
    {
        std::vector<Subject> c = courses[i].getSubjects();
        for(int j = 0; j < c.size(); j++)
        {
            if(c[j].getSubjectName()==subject.getSubjectName())
            {
                courses[i].changeSubject(subject);
            }
        }
    }



}
void University::addSubject() {
    std::string courseName;
    bool found = false;
    Subject c;

    std::cin >> c;

    fflush(stdin);
    std::cout << "Course Name: ";
    std::getline(std::cin, courseName);
    fflush(stdin);

    for(int i = 0 ; i < courses.size(); i++)
    {
        if(courses[i].getCourseName() == courseName) {
            courses[i].addSubject(c);
            std::cout << "Subject -> " << c.getSubjectName() << " <- successfully added to Course -> " << courseName << " <- !!!" << std::endl;
            found = true;
        }
    }
    if(!found)
    {
        std::cout << "Invalid Course Name, please try again!!!";
    }
}
void University::addSubject(Subject c) {
    std::string courseName;
    bool found = false;

    fflush(stdin);
    std::cout << "Course Name: ";
    std::getline(std::cin, courseName);
    fflush(stdin);

    for(int i = 0 ; i < courses.size(); i++)
    {
        if(courses[i].getCourseName() == courseName) {
            courses[i].addSubject(c);
            std::cout << "Subject -> " << c.getSubjectName() << " <- successfully added to Course -> " << courseName << " <- !!!" << std::endl;
            found = true;
        }
    }
    if(!found)
    {
        std::cout << "Invalid Course Name, please try again!!!";
    }
}
void University::remSubject() {
    std::string courseName,subjectName;
    bool found = false;
    Subject c;

    fflush(stdin);
    std::cout << "Enter the name of the Subject to remove: ";
    std::getline(std::cin, subjectName);
    c.setSubjectName(subjectName);

    fflush(stdin);
    std::cout << "Course Name: ";
    std::getline(std::cin, courseName);
    fflush(stdin);

    for(int i = 0 ; i < courses.size(); i++)
    {
        if(courses[i].getCourseName() == courseName) {
            courses[i].remSubject(c);
            std::cout << "Subject -> " << c.getSubjectName() << " <- successfully removed from Course -> " << courseName << " <- !!!" << std::endl;
            found = true;
        }
    }
    if(!found)
    {
        std::cout << "Invalid Course Name, please try again!!!";
    }
}
void University::remSubject(Subject c) {
    std::string courseName;
    bool found = false;

    fflush(stdin);
    std::cout << "Course Name: ";
    std::getline(std::cin, courseName);
    fflush(stdin);

    for(int i = 0 ; i < courses.size(); i++)
    {
        if(courses[i].getCourseName() == courseName) {
            courses[i].remSubject(c);
            std::cout << "Subject -> " << c.getSubjectName() << " <- successfully removed from Course -> " << courseName << " <- !!!" << std::endl;
            found = true;
        }
    }
    if(!found)
    {
        std::cout << "Invalid Course Name, please try again!!!";
    }
}



void University::showDirector(bool diretorUni = true) {
    if (diretorUni == true) {

        std::cout << "\nUniversity Director: " << std::endl;

        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "| alnumber - name / age / address |"<< std::endl;

        std::cout << "| " << directorUniversity.getAlNumber() << " - " << directorUniversity.getName() << " / " << directorUniversity.getAge() << " / " << directorUniversity.getAddress() << " |" << std::endl;

        std::cout << "----------------------------------------------------" << std::endl;

    }
    else
    {
        fflush(stdin);
        std::string courseName;
        std::cout << "Enter the name of the course to see the director: ";
        std::getline(std::cin, courseName);
        fflush(stdin);

        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].getCourseName() == courseName)
            {
                std::cout << "\nDirector of the Course " << courses[i].getCourseName() << ": " << std::endl;

                std::cout << "---------------------------------------------------" << std::endl;
                std::cout << "| alNumber - name / age / address |" << std::endl;

                std::cout << "| " << courses[i].getCourseDirector().getAlNumber() << " - " << courses[i].getCourseDirector().getName() << " / " << courses[i].getCourseDirector().getAge() << " / " << courses[i].getCourseDirector().getAddress() << " |" << std::endl;

                std::cout << "---------------------------------------------------" << std::endl;
            }
        }
    }
}
void University::showViceDirectorCourse() {

    fflush(stdin);
    std::string courseName;
    std::cout << "Enter the name of the course to see the vice director: ";
    std::getline(std::cin, courseName);
    fflush(stdin);

    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i].getCourseName() == courseName)
        {
            std::cout << "\nDirector of the Course " << courses[i].getCourseName() << ": " << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;
            std::cout << "| alNumber - name / age / address |" << std::endl;
            std::cout << "| " << courses[i].getCourseViceDirector().getAlNumber() << " - " << courses[i].getCourseViceDirector().getName() << " / " << courses[i].getCourseViceDirector().getAge() << " / " << courses[i].getCourseViceDirector().getAddress() << " |" << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;

        }
    }
}
void University::showVogalCourse() {
    fflush(stdin);
    std::string courseName;
    std::cout << "Enter the name of the course to see the vogal: ";
    std::getline(std::cin, courseName);
    fflush(stdin);

    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i].getCourseName() == courseName) {
            std::cout << "\nVogal of the Course " << courses[i].getCourseName() << ": " << std::endl;

            std::cout << "------------------------------------------------------" << std::endl;
            std::cout << "| alNumber - name / age / address |" << std::endl;
            std::cout << "| " << courses[i].getCourseVogal().getAlNumber() << " - " << courses[i].getCourseVogal().getName() << " / " << courses[i].getCourseVogal().getAge() << " / " << courses[i].getCourseVogal().getAddress() << " |" << std::endl;
            std::cout << "------------------------------------------------------" << std::endl;
        }
    }
}


void University::changeCourseName() {

    fflush(stdin);
    std::string courseName, courseNewName;
    std::cout << "Enter the name of the Course you want to modify: ";
    std::getline(std::cin, courseName);
    fflush(stdin);

    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i].getCourseName() == courseName)
        {
            fflush(stdin);
            std::cout << "Enter the new name for the Course: ";
            std::getline(std::cin, courseNewName);
            fflush(stdin);
            courses[i].setCourseName(courseNewName);
        }
    }
    for(int i = 0 ; i < students.size(); i++)
    {
        if(students[i].getCourse() == courseName)
            students[i].setCourse(courseNewName);
    }
}
void University::changeDirector(bool uni=false) {
    std::string name, address;
    int age;
    Person newDirector;

    if (!uni) {
        fflush(stdin);
        std::string courseName;
        std::cout << "Enter the name of the Course: ";
        std::getline(std::cin, courseName);
        fflush(stdin);

        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].getCourseName() == courseName) {
                fflush(stdin);
                std::cout << "Name: ";
                std::getline(std::cin, name);
                fflush(stdin);

                std::cout << "Age: ";
                std::cin >> age;

                fflush(stdin);
                std::cout << "Address: ";
                std::getline(std::cin, address);
                fflush(stdin);

                newDirector = courses[i].getCourseDirector();
                newDirector.setName(name);
                newDirector.setAge(age);
                newDirector.setAddress(address);

                courses[i].setDiretor(newDirector);
            }
        }
    } else {
        std::cout << "Name: ";
        std::getline(std::cin, name);

        std::cout << "Age: ";
        std::cin >> age;

        fflush(stdin);
        std::cout << "Address: ";
        std::getline(std::cin, address);
        fflush(stdin);

        newDirector = getDirectorUni();
        newDirector.setName(name);
        newDirector.setAge(age);
        newDirector.setAddress(address);

        setDirectorUni(newDirector);
    }

}
void University::changeViceDirectorCourse() {

    fflush(stdin);
    std::string courseName;
    std::cout << "Enter the name of the Course: ";
    std::getline(std::cin, courseName);
    fflush(stdin);

    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].getCourseName() == courseName) {
            std::string name, address;
            int age;
            Person newViceDirector;

            fflush(stdin);
            std::cout << "Name: ";
            std::getline(std::cin, name);
            fflush(stdin);

            std::cout << "Age: ";
            std::cin >> age;

            fflush(stdin);
            std::cout << "Address: ";
            std::getline(std::cin, address);
            fflush(stdin);

            newViceDirector = courses[i].getCourseDirector();
            newViceDirector.setName(name);
            newViceDirector.setAge(age);
            newViceDirector.setAddress(address);

            courses[i].setDiretor(newViceDirector);
        }
    }

}
void University::changeVogalCourse() {

    fflush(stdin);
    std::string courseName;
    std::cout << "Enter the name of the Course: ";
    std::getline(std::cin, courseName);
    fflush(stdin);

    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].getCourseName() == courseName) {
            std::string name, address;
            int age;
            Person newVogal;

            fflush(stdin);
            std::cout << "Name: ";
            std::getline(std::cin, name);
            fflush(stdin);

            std::cout << "Age: ";
            std::cin >> age;

            fflush(stdin);
            std::cout << "Address: ";
            std::getline(std::cin, address);
            fflush(stdin);

            newVogal = this->courses[i].getCourseVogal();
            newVogal.setName(name);
            newVogal.setAge(age);
            newVogal.setAddress(address);

            this->courses[i].setVogal(newVogal);
        }
    }

}

void University::changeNameStudent()
{
    std::string desiredName;
    int alNumber;
    bool alFound = false;

    std::cout << "Enter the alNumber of the Student: ";
    std::cin >> alNumber;

    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getAlNumber() == alNumber)
        {
            fflush(stdin);
            std::cout << "Enter the new name for the Student: ";
            std::getline(std::cin, desiredName);
            fflush(stdin);
            students[i].setName(desiredName);
            alFound = true;

            for(int j = 0 ; j < courses.size(); j++)
            {
                for(int z = 0; z < courses[j].getStudents().size(); z++)
                {
                    if(courses[j].getStudents()[z].getAlNumber() == alNumber)
                        courses[j].changeStudent(students[i]);
                }
            }
            break;
        }
    }

    if (!alFound)
    {
        std::cout << "\n!!!Student not found!!!" << std::endl;
        std::cout << "No Student has the provided alNumber" << std::endl;

    }
}
void University::changeAgeStudent() {
    int alNumber, desiredAge;
    bool alFound = false;

    std::cout << "Enter the alNumber of the Student: ";
    std::cin >> alNumber;

    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getAlNumber() == alNumber)
        {
            std::cout << "Enter the new age for the Student: ";
            std::cin >> desiredAge;
            students[i].setAge(desiredAge);
            alFound = true;

            for(int j = 0 ; j < courses.size(); j++)
            {
                for(int z = 0; z < courses[j].getStudents().size(); z++)
                {
                    if(courses[j].getStudents()[z].getAlNumber() == alNumber)
                        courses[j].changeStudent(students[i]);
                }
            }

            break;
        }
    }

    if (alFound == false)
    {
        std::cout << "\n!!!Student not found!!!" << std::endl;
        std::cout << "No Student has the provided alNumber" << std::endl;
    }

}
void University::changeAddressStudent() {

    std::string desiredAddress;
    int alNumber;
    bool alFound = false;

    std::cout << "Enter the alNumber of the Student: ";
    std::cin >> alNumber;

    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getAlNumber() == alNumber)
        {
            fflush(stdin);
            std::cout << "Enter the new address for the Student: ";
            std::getline(std::cin, desiredAddress);
            fflush(stdin);
            
            students[i].setAddress(desiredAddress);
            alFound = true;

            for(int j = 0 ; j < courses.size(); j++)
            {
                for(int z = 0; z < courses[j].getStudents().size(); z++)
                {
                    if(courses[j].getStudents()[z].getAlNumber() == alNumber)
                        courses[j].changeStudent(students[i]);
                }
            }

            break;
        }
    }

    if (alFound == false)
    {
        std::cout << "\n!!!Student not found!!!" << std::endl;
        std::cout << "No Student has the provided alNumber" << std::endl;
    }
}
void University::changeNameCourseStudent(){
    std::string courseNewName;
    int alNumber, indexNewCourse;
    bool alFound = false, cond = true;


    std::cout << "Enter the alNumber of the Student: ";
    std::cin >> alNumber;

    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getAlNumber() == alNumber)
        {
            do {
                fflush(stdin);
                std::cout << "Enter the new Course name for the Student: ";
                std::getline(std::cin, courseNewName);
                fflush(stdin);

                //verificar se o Course existe
                for(int j = 0; j < courses.size(); j++)
                {
                    if(courses[j].getCourseName() == courseNewName) {
                        cond = false;
                        indexNewCourse = j;
                        break;
                    }
                }
            }while(cond);

            //setar o nome do novo Course no vetor de students da uni
            students[i].setCourse(courseNewName);

            alFound = true;
            bool atributionDone = false;

            for(int j = 0 ; j < courses.size(); j++)
            {
                for(int z = 0; z < courses[j].getStudents().size(); z++)
                {
                    if(courses[j].getStudents()[z].getAlNumber() == alNumber) {
                        courses[indexNewCourse].addStudents(students[i]);
                        courses[j].remStudents(students[i]);
                        atributionDone = true;
                        break;
                    }
                }
                if(atributionDone)
                    break;
            }
            break;
        }
    }

    if (alFound == false)
    {
        std::cout << "\n!!!Student not found!!!" << std::endl;
        std::cout << "No Student has the provided alNumber" << std::endl;
    }
}
void University::changeMatriculationYearStudent() {
    int alNumber, newMatriculationYear;
    bool alFound = false;

    std::cout << "Enter the alNumber of the Student: ";
    std::cin >> alNumber;

    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getAlNumber() == alNumber)
        {
            std::cout << "Enter the new enrollment year for the Student: ";
            std::cin >> newMatriculationYear;
            students[i].setMatriculationYear(newMatriculationYear);
            alFound = true;

            for(int j = 0 ; j < courses.size(); j++)
            {
                for(int z = 0; z < courses[j].getStudents().size(); z++)
                {
                    if(courses[j].getStudents()[z].getAlNumber() == alNumber)
                        courses[j].changeStudent(students[i]);
                }
            }

            break;
        }
    }

    if (alFound == false)
    {
        std::cout << "\n!!!Student not found!!!" << std::endl;
        std::cout << "No Student has the provided alNumber" << std::endl;
    }
}

void University::showNameStudent() {
    int alNumber;
    bool alFound = false;

    std::cout << "Enter the alNumber of the Student: ";
    std::cin >> alNumber;

    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getAlNumber() == alNumber)
        {
            std::cout << "\n!!!Student found!!!" << std::endl;
            std::cout << "Student's Name: " << students[i].getName() << std::endl;
            alFound = true;
            break;
        }
    }

    if (alFound == false)
    {
        std::cout << "\n!!!Student not found!!!" << std::endl;
        std::cout << "No Student has the provided alNumber" << std::endl;
    }
}
void University::showAgeStudent() {int alNumber;
    bool alFound = false;

    std::cout << "Enter the alNumber of the Student: ";
    std::cin >> alNumber;

    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getAlNumber() == alNumber)
        {
            std::cout << "\n!!!Student found!!!" << std::endl;
            std::cout << "Student's Age: " << students[i].getAge() << std::endl;
            alFound = true;
            break;
        }
    }
    if (alFound == false)
    {
        std::cout << "\n!!!Student not found!!!" << std::endl;
        std::cout << "No Student has the provided alNumber" << std::endl;
    }
}
void University::showAddressStudent() { int alNumber;
    bool alFound = false;

    std::cout << "Enter the alNumber of the Student: ";
    std::cin >> alNumber;

    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getAlNumber() == alNumber)
        {
            std::cout << "\n!!!Student found!!!" << std::endl;
            std::cout << "Student's Address: " << students[i].getAddress() << std::endl;
            alFound = true;
            break;
        }
    }
    if (alFound == false)
    {
        std::cout << "\n!!!Student not found!!!" << std::endl;
        std::cout << "No Student has the provided alNumber" << std::endl;
    }
}
void University::showCourseNameStudent() {
    int alNumber;
    bool alFound = false;

    std::cout << "Enter the alNumber of the Student: ";
    std::cin >> alNumber;

    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getAlNumber() == alNumber)
        {
            std::cout << "\n!!!Student found!!!" << std::endl;
            std::cout << "Student's Course Name: " << students[i].getCourse() << std::endl;
            alFound = true;
            break;
        }
    }

    if (alFound == false)
    {
        std::cout << "\n!!!Student not found!!!" << std::endl;
        std::cout << "No Student has the provided alNumber" << std::endl;
    }
}
void University::showAlNumberStudent() {

    fflush(stdin);
    std::string nomeStudent;
    std::cout << "Enter the name of the student: ";
    std::getline(std::cin, nomeStudent);
    fflush(stdin);

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getName() == nomeStudent)
        {
            std::cout << "Student's AL Number: " << students[i].getAlNumber() << std::endl;
        }
    }

}
void University::showMatriculationYearStudent() {
    int alNumber;
    bool alFound = false;

    std::cout << "Enter the alNumber of the Student: ";
    std::cin >> alNumber;

    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getAlNumber() == alNumber)
        {
            std::cout << "\n!!!Student found!!!" << std::endl;
            std::cout << "Matriculation Year of the Student: " << students[i].getMatriculationYear() << std::endl;
            alFound = true;
            break;
        }
    }

    if (alFound == false)
    {
        std::cout << "\n!!!Student not found!!!" << std::endl;
        std::cout << "No Student has the provided alNumber" << std::endl;
    }
}

void putOnVectorWithoutDuplicates(std::vector<Subject> &vec, Subject element)
{
    bool found = false;
    for(int i = 0 ; i < vec.size(); i++)
    {
        if(vec[i].getSubjectName() == element.getSubjectName())
            found = true;
    }
    if(!found)
        vec.push_back(element);
}
void putOnVectorWithoutDuplicates(std::vector<Professor> &vec, Professor element)
{
    bool found = false;
    for(int i = 0 ; i < vec.size(); i++)
    {
        if(vec[i].getName() == element.getName())
            found = true;
    }
    if(!found)
        vec.push_back(element);
}

void University::SaveDB(std::string studentsFileName, std::string coursesFileName, std::string subjectsFileName, std::string professorsFileName, std::string directoresFileName, std::string viceDirectoresFileName, std::string vogaisFileName, std::string directoresUniFileName) {

    std::ofstream studentsFile(studentsFileName), coursesFile(coursesFileName),SubjectsFile(subjectsFileName),professorsFile(professorsFileName), directoresFile(directoresFileName), viceDirectoresFile(viceDirectoresFileName), vogaisFile(vogaisFileName), directoresUniFile(directoresUniFileName);
    std::vector<Subject> Subjects, SubjectsAux;
    std::vector<Professor> professors, professorsAux;
    Professor professor;
    Person director, viceDirector, vogal, dirUni;

    dirUni = this->getDirectorUni();
    directoresUniFile << dirUni;

    for (int i = 0; i < this->students.size(); i++)
    {
        studentsFile << students[i];
        if(i+1 < this->students.size())
            studentsFile << std::endl;
    }
    studentsFile.close();
    for (int i = 0; i < this->courses.size(); i++)
    {
        coursesFile << this->courses[i];
        if(i+1 < this->courses.size())
            coursesFile << std::endl;
    }
    coursesFile.close();
    for (int i = 0; i < this->courses.size(); i++)
    {
        SubjectsAux = courses[i].getSubjects();
        for(int j = 0 ; j < SubjectsAux.size(); j++)
        {
            //adicionar cada uma das Subjects daquele Course para o vetor principal de Subjects, sem duplicacao
            putOnVectorWithoutDuplicates(Subjects, SubjectsAux[j]);

            //para cada um dos professores auxiliares, adiciona-lo ao vetor
            professorsAux = Subjects[j].getAssistantProfessors();
            for(int z = 0 ; z < professorsAux.size(); z++)
            {
                putOnVectorWithoutDuplicates(professors, professorsAux[z]);
            }

            professor = Subjects[j].getMainProfessor();
            putOnVectorWithoutDuplicates(professors, professor);

        }
        director = courses[i].getCourseDirector();
        viceDirector = courses[i].getCourseViceDirector();
        vogal = courses[i].getCourseVogal();

        directoresFile << director;
        viceDirectoresFile << viceDirector;
        vogaisFile << vogal;

        if(i+1<this->courses.size())
        {
            directoresFile << std::endl;
            viceDirectoresFile << std::endl;
            vogaisFile << std::endl;
        }

    }
    for (int i = 0; i < professors.size(); i++)
    {
        professorsFile << professors[i];
        if(i+1 < professors.size())
            professorsFile << std::endl;
    }
    for (int i = 0; i < Subjects.size(); i++)
    {
        SubjectsFile << Subjects[i];
        if(i+1 < Subjects.size())
            SubjectsFile << std::endl;
    }


    SubjectsFile.close();
    coursesFile.close();
    studentsFile.close();
    directoresFile.close();
    viceDirectoresFile.close();
    vogaisFile.close();
    directoresUniFile.close();
}
void University::LoadDB(std::string studentsFileName, std::string coursesFileName, std::string subjectsFileName,
                        std::string professorsFileName, std::string directoresFileName,
                        std::string viceDirectoresFileName, std::string vogaisFileName,
                        std::string directoresUniFileName) {

    std::ifstream studentsFile(studentsFileName);
    std::ifstream coursesFile(coursesFileName);
    std::ifstream SubjectsFile(subjectsFileName);
    std::ifstream professorsFile(professorsFileName);
    std::ifstream directoresFile(directoresFileName);
    std::ifstream viceDirectoresFile(viceDirectoresFileName);
    std::ifstream vogaisFile(vogaisFileName);
    std::ifstream directoresUniFile(directoresUniFileName);

    Person diretor, viceDiretor, vogal;

    if(!studentsFile)
    {
        std::cout << "!!!Error opening file with students information!!!" << std::endl;
    }
    if(!coursesFile)
    {
        std::cout << "!!!Error opening file with courses information!!!" << std::endl;
    }
    if(!SubjectsFile)
    {
        std::cout << "!!!Error opening file with Subjects information!!!" << std::endl;
    }
    if(!professorsFile)
    {
        std::cout << "!!!Error opening file with teachers information!!!" << std::endl;
    }
    if(!directoresFile)
    {
        std::cout << "!!!Error opening file with directors information!!!" << std::endl;
    }
    if(!viceDirectoresFile)
    {
        std::cout << "!!!Error opening file with vice directors information!!!" << std::endl;
    }
    if(!vogaisFile)
    {
        std::cout << "!!!Error opening file with vogals information!!!" << std::endl;
    }
    if(!directoresUniFile)
    {
        std::cout << "!!!Error opening file with directors of uni information!!!" << std::endl;
    }

    std::vector<Person> diretores;
    std::vector<Person> viceDiretores;
    std::vector<Person> vogais;

    while(directoresUniFile.peek() != EOF)
    {
        Person dir;
        dir.ReadFile(directoresUniFile);
        this->setDirectorUni(dir);
    }

    while(directoresFile.peek() != EOF)
    {
        char aux[100];
        Person dir;
        dir.ReadFile(directoresFile);
        diretores.push_back(dir);
        if(directoresFile.peek() == '\n')
            directoresFile.getline(aux, 100, '\n');
    }
    while(viceDirectoresFile.peek() != EOF)
    {
        char aux[100];
        Person vicDir;
        vicDir.ReadFile(viceDirectoresFile);
        viceDiretores.push_back(vicDir);
        if(viceDirectoresFile.peek() == '\n')
            viceDirectoresFile.getline(aux, 100, '\n');
    }
    while(vogaisFile.peek() != EOF)
    {
        char aux[100];
        Person vog;
        vog.ReadFile(vogaisFile);
        vogais.push_back(vog);
        if(vogaisFile.peek() == '\n')
            vogaisFile.getline(aux, 100, '\n');
    }

    while(studentsFile.peek() != EOF)
    {
        char aux[100];
        Student student;
        student.ReadFile(studentsFile);
        this->addStudents(student);
        if(studentsFile.peek() == '\n')
            studentsFile.getline(aux, 100, '\n');
    }

    std::vector<Professor> professores;
    std::vector<Subject> Subjects;

    while(professorsFile.peek() != EOF)
    {
        char aux[100];
        Professor p;
        p.ReadFile(professorsFile);
        professores.push_back(p);
        if(professorsFile.peek() == '\n')
            professorsFile.getline(aux, 100, '\n');

    }

    char aux[1000];
    int numProfAux;
    while(SubjectsFile.peek() != EOF)
    {
        Subject Subject;
        std::vector<Professor> profAuxs;

        SubjectsFile.getline(aux, 1000, ';');
        Subject.setSubjectName(aux);

        SubjectsFile.getline(aux, 1000, ';');
        Subject.setBibliography(aux);

        SubjectsFile.getline(aux, 1000, ';');
        Subject.setObjectives(aux);

        SubjectsFile.getline(aux, 1000, ';');
        Subject.setAvaliationMethodology(aux);

        SubjectsFile.getline(aux, 100, ';');
        numProfAux = atoi(aux);

        for(int i = 0 ; i < numProfAux; i++)
        {
            SubjectsFile.getline(aux, 100, ';');
            for(int j = 0; j < professores.size(); j++)
            {
                if(professores[j].getName() == aux)
                {
                    profAuxs.push_back(professores[j]);
                    break;
                }
            }

        }
        Subject.setAssistantProfessors(profAuxs);

        SubjectsFile.getline(aux, 100, ';');

        for(int j = 0; j < professores.size(); j++)
        {
            if(professores[j].getName() == aux)
            {
                Subject.setMainProfessor(professores[j]);
                break;
            }
        }

        if(SubjectsFile.peek() == '\n')
            SubjectsFile.getline(aux, 100, '\n');

        Subjects.push_back(Subject);
        profAuxs.clear();

    }


    int numSubjects;
    while(coursesFile.peek() != EOF)
    {
        Course course;
        coursesFile.getline(aux, 1000, ';');
        course.setCourseName(aux);

        coursesFile.getline(aux, 1000, ';');
        numSubjects = atoi(aux);

        for(int i = 0; i < numSubjects; i++)
        {
            coursesFile.getline(aux, 1000, ';');
            for(int j = 0; j < Subjects.size(); j++)
            {
                if(Subjects[j].getSubjectName() == aux) {
                    course.addSubject(Subjects[j]);
                    break;
                }
            }
        }

        coursesFile.getline(aux, 1000, ';');
        for(int i = 0 ; i < diretores.size(); i++)
        {
            if(diretores[i].getName() == aux)
            {
                course.setDiretor(diretores[i]);
                break;
            }
        }

        coursesFile.getline(aux, 1000, ';');
        for(int i = 0 ; i < viceDiretores.size(); i++)
        {
            if(viceDiretores[i].getName() == aux)
            {
                course.setViceDiretor(viceDiretores[i]);
                break;
            }
        }

        coursesFile.getline(aux, 1000, ';');
        for(int i = 0 ; i < vogais.size(); i++)
        {
            if(vogais[i].getName() == aux)
            {
                course.setVogal(vogais[i]);
                break;
            }
        }

        this->addCourses(course);
        if(coursesFile.peek() == '\n')
            coursesFile.getline(aux, 1000, '\n');

    }
    for(int i = 0 ; i < courses.size(); i++)
    {
        for(int j = 0; j < students.size(); j++)
        {
            if(students[j].getCourse() == courses[i].getCourseName())
            {
                courses[i].addStudents(students[j]);
            }
        }
    }


    SubjectsFile.close();
    coursesFile.close();
    studentsFile.close();
    directoresFile.close();
    viceDirectoresFile.close();
    vogaisFile.close();
    directoresUniFile.close();
}

void University::setDirectorCourse(Person director, std::string course){
    for(int i = 0; i < this->courses.size(); i++)
    {
        if(courses[i].getCourseName()==course)
        {
            courses[i].setDiretor(director);
        }
    }
}
void University::setViceDirectorCourse(Person viceDirector, std::string course) {
    for(int i = 0; i < this->courses.size(); i++)
    {
        if(courses[i].getCourseName()==course)
        {
            courses[i].setViceDiretor(viceDirector);
        }
    }
}
void University::setVogalCourse(Person vogal, std::string course){
    for(int i = 0; i < this->courses.size(); i++)
    {
        if(courses[i].getCourseName()==course)
        {
            courses[i].setVogal(vogal);
        }
    }
}

void University::changeNameProfessor(){
    std::string desiredName;
    int alNumber;
    bool alFound = false;
    std::vector<Professor> p;
    std::vector<Professor> profs;
    std::vector<Subject> c;

    p = this->getProfessors();

    std::cout << "Enter the alNumber of the professor: ";
    std::cin >> alNumber;

    for(int i = 0; i < p.size(); i++)
    {
        if(p[i].getAlNumber() == alNumber)
        {
            fflush(stdin);
            std::cout << "Enter the new name for the professor: ";
            std::getline(std::cin, desiredName);
            fflush(stdin);

            alFound = true;

            for(int j = 0 ; j < courses.size(); j++)//para todos os courses
            {
                c = courses[j].getSubjects();
                for(int k = 0; k < c.size(); k++)//para todas as Subjects
                {
                    profs = c[k].getAssistantProfessors();
                    for(int z = 0 ; z < c[k].getAssistantProfessors().size(); z++)//para os profs auxiliares
                    {
                        if(c[k].getAssistantProfessors()[z].getAlNumber() == alNumber)
                        {
                            profs[z].setName(desiredName);
                        }
                    }
                    c[k].setAssistantProfessors(profs);
                    if(c[k].getMainProfessor().getAlNumber() == alNumber)
                    {
                        c[k].setNameMainProfessor(desiredName);
                    }
                }
                courses[j].setSubjects(c);
            }

            break;
        }
    }

    if (!alFound)
{
    std::cout << "\n!!!Professor not found!!!" << std::endl;
    std::cout << "No professor has the provided alNumber" << std::endl;
}

}
void University::changeAgeProfessor()
{
    int alNumber, desiredAge;
    bool alFound = false;
    std::vector<Professor> p;
    std::vector<Professor> profs;
    std::vector<Subject> c;

    p = this->getProfessors();

    std::cout << "Enter the alNumber of the professor: ";
    std::cin >> alNumber;

    for(int i = 0; i < p.size(); i++)
    {
        if(p[i].getAlNumber() == alNumber)
        {
            std::cout << "Enter the new age for the professor: ";
            std::cin >> desiredAge;

            alFound = true;

            for(int j = 0 ; j < courses.size(); j++)//para todos os courses
            {
                c = courses[j].getSubjects();
                for(int k = 0; k < c.size(); k++)//para todas as Subjects
                {
                    profs = c[k].getAssistantProfessors();
                    for(int z = 0 ; z < c[k].getAssistantProfessors().size(); z++)//para os profs auxiliares
                    {
                        if(c[k].getAssistantProfessors()[z].getAlNumber() == alNumber)
                        {
                            profs[z].setAge(desiredAge);
                        }
                    }
                    c[k].setAssistantProfessors(profs);
                    if(c[k].getMainProfessor().getAlNumber() == alNumber)
                    {
                        c[k].setAgeMainProfessor(desiredAge);
                    }
                }
                courses[j].setSubjects(c);
            }

            break;
        }
    }

    if (!alFound)
{
    std::cout << "\n!!!Professor not found!!!" << std::endl;
    std::cout << "No professor has the provided alNumber" << std::endl;
}

}
void University::changeAddressProfessor()
{
    std::string desiredAddress;
    int alNumber;
    bool alFound = false;
    std::vector<Professor> p;
    std::vector<Professor> profs;
    std::vector<Subject> c;

    p = this->getProfessors();

    std::cout << "Enter the alNumber of the professor: ";
    std::cin >> alNumber;

    for(int i = 0; i < p.size(); i++)
    {
        if(p[i].getAlNumber() == alNumber)
        {
            fflush(stdin);
            std::cout << "Enter the new address for the professor: ";
            std::getline(std::cin, desiredAddress);
            fflush(stdin);

            alFound = true;

            for(int j = 0 ; j < courses.size(); j++)//para todos os courses
            {
                c = courses[j].getSubjects();
                for(int k = 0; k < c.size(); k++)//para todas as Subjects
                {
                    profs = c[k].getAssistantProfessors();
                    for(int z = 0 ; z < c[k].getAssistantProfessors().size(); z++)//para os profs auxiliares
                    {
                        if(c[k].getAssistantProfessors()[z].getAlNumber() == alNumber)
                        {
                            profs[z].setAddress(desiredAddress);
                        }
                    }
                    c[k].setAssistantProfessors(profs);
                    if(c[k].getMainProfessor().getAlNumber() == alNumber)
                    {
                        c[k].setAddressMainProfessor(desiredAddress);
                    }
                }
                courses[j].setSubjects(c);
            }

            break;
        }
    }

    if (!alFound)
{
    std::cout << "\n!!!Professor not found!!!" << std::endl;
    std::cout << "No professor has the provided alNumber" << std::endl;
}

}
void University::changeSalaryProfessor()
{
    float desiredSalary;
    int alNumber;
    bool alFound = false;
    std::vector<Professor> p;
    std::vector<Professor> profs;
    std::vector<Subject> c;

    p = this->getProfessors();

    std::cout << "Enter the alNumber of the professor: ";
    std::cin >> alNumber;

    for(int i = 0; i < p.size(); i++)
    {
        if(p[i].getAlNumber() == alNumber)
        {
            std::cout << "Enter the new salary for the professor: ";
            std::cin >> desiredSalary;
            
            alFound = true;

            for(int j = 0 ; j < courses.size(); j++)//para todos os courses
            {
                c = courses[j].getSubjects();
                for(int k = 0; k < c.size(); k++)//para todas as Subjects
                {
                    profs = c[k].getAssistantProfessors();
                    for(int z = 0 ; z < c[k].getAssistantProfessors().size(); z++)//para os profs auxiliares
                    {
                        if(c[k].getAssistantProfessors()[z].getAlNumber() == alNumber)
                        {
                            profs[z].setSalary(desiredSalary);
                        }
                    }
                    c[k].setAssistantProfessors(profs);
                    if(c[k].getMainProfessor().getAlNumber() == alNumber)
                    {
                        c[k].setSalaryMainProfessor(desiredSalary);
                    }
                }
                courses[j].setSubjects(c);
            }

            break;
        }
    }

    if (!alFound)
{
    std::cout << "\n!!!Professor not found!!!" << std::endl;
    std::cout << "No professor has the provided alNumber" << std::endl;
}

}
void University::addCoursesToTeachProfessor()
{
    std::string courseToAdd;
    int alNumber, numCourses;
    bool alFound = false;
    std::vector<Professor> p;
    std::vector<Professor> profs;
    std::vector<Subject> c;
    std::vector<string> coursesV;

    p = this->getProfessors();

    std::cout << "Enter the alNumber of the professor: ";
    std::cin >> alNumber;

    std::cout << "Enter the number of courses to add: ";
    std::cin >> numCourses;

    for(int m = 0; m < numCourses; m++)
    {
        fflush(stdin);
        std::cout << "Enter the course to add: ";
        std::getline(std::cin, courseToAdd);
        fflush(stdin);

        for(int i = 0; i < p.size(); i++)//para todos os professores copia
        {
            if(p[i].getAlNumber() == alNumber)//se o professor for encontrado
            {
                alFound = true;//foi encontrado

                for(int j = 0 ; j < courses.size(); j++)//para todos os courses
                {
                    c = courses[j].getSubjects();
                    for(int k = 0; k < c.size(); k++)//para todas as Subjects
                    {
                        profs = c[k].getAssistantProfessors();
                        for(int z = 0 ; z < profs.size(); z++)//para os profs auxiliares
                        {
                            if(profs[z].getAlNumber() == alNumber)
                            {
                                profs[z].addCoursesToTeach(courseToAdd);
                            }
                        }
                        c[k].setAssistantProfessors(profs);
                        if(c[k].getMainProfessor().getAlNumber() == alNumber)
                        {
                            bool found = false;
                            coursesV = c[k].getMainProfessor().getCoursesToTeach();

                            for(int n = 0 ; n < coursesV.size(); n++)
                            {
                                if(coursesV[n] == courseToAdd)
                                    found = true;
                            }
                            if(!found)
                                coursesV.push_back(courseToAdd);
                            c[k].setCoursesToTeachProfPrincipal(coursesV);
                        }
                    }
                    courses[j].setSubjects(c);
                }

                break;
            }
        }

        if (!alFound)
        {
            std::cout << "\n!!!Professor not found!!!" << std::endl;
            std::cout << "No professor has the provided alNumber" << std::endl;
        }
    }

}
void University::removeCoursesToTeachProfessor()
{
    std::string CourseRemover;
    int alNumber, numCourses;
    bool alFound = false;
    std::vector<Professor> p;
    std::vector<Professor> profs;
    std::vector<Subject> c;
    std::vector<string> coursesV;

    p = this->getProfessors();

    std::cout << "Enter the alNumber of the professor: ";
    std::cin >> alNumber;

    std::cout << "Introduza o numero de courses a remover: ";
    std::cin >> numCourses;

    for(int m = 0; m < numCourses; m++)
    {
        fflush(stdin);
        std::cout << "Introduza o Course a remover: ";
        std::getline(std::cin, CourseRemover);
        fflush(stdin);

        for(int i = 0; i < p.size(); i++)//para todos os professores copia
        {
            if(p[i].getAlNumber() == alNumber)//se o professor for encontrado
            {
                alFound = true;//foi encontrado

                for(int j = 0 ; j < courses.size(); j++)//para todos os courses
                {
                    c = courses[j].getSubjects();
                    for(int k = 0; k < c.size(); k++)//para todas as Subjects
                    {
                        profs = c[k].getAssistantProfessors();
                        for(int z = 0 ; z < profs.size(); z++)//para os profs auxiliares
                        {
                            if(profs[z].getAlNumber() == alNumber)
                            {
                                profs[z].remCoursesToTeach(CourseRemover);
                            }
                        }
                        c[k].setAssistantProfessors(profs);
                        if(c[k].getMainProfessor().getAlNumber() == alNumber)
                        {
                            coursesV = c[k].getMainProfessor().getCoursesToTeach();

                            for(int n = 0 ; n < coursesV.size(); n++)
                            {
                                if(coursesV[n] == CourseRemover)
                                    coursesV.erase(coursesV.begin() + n);
                            }
                            c[k].setCoursesToTeachProfPrincipal(coursesV);
                        }
                    }
                    courses[j].setSubjects(c);
                }

                break;
            }
        }

        if (!alFound)
        {
            std::cout << "\n!!!Professor not found!!!" << std::endl;
            std::cout << "No professor has the provided alNumber" << std::endl;
        }
    }
}
void University::showNameProfessor()
{
    int alNumber;
    bool alFound = false;
    std::vector<Professor> p;

    p = this->getProfessors();

    std::cout << "Enter the alNumber of the professor: ";
    std::cin >> alNumber;

    for(int i = 0; i < p.size(); i++)
    {
        if(p[i].getAlNumber() == alNumber)
        {
            std::cout << "\nProfessor's name: " << p[i].getName() << std::endl;
            alFound = true;
            break;
        }
    }

    if (!alFound)
    {
        std::cout << "\n!!!Professor not found!!!" << std::endl;
        std::cout << "No professor has the provided alNumber" << std::endl;
    }

}
void University::showAgeProfessor()
{
    int alNumber;
    bool alFound = false;
    std::vector<Professor> p;

    p = this->getProfessors();

    std::cout << "Enter the alNumber of the professor: ";
    std::cin >> alNumber;

    for(int i = 0; i < p.size(); i++)
    {
        if(p[i].getAlNumber() == alNumber)
        {
            std::cout << "\nProfessor's age: " << p[i].getAge() << std::endl;
            alFound = true;
            break;
        }
    }

    if (!alFound)
{
    std::cout << "\n!!!Professor not found!!!" << std::endl;
    std::cout << "No professor has the provided alNumber" << std::endl;
}

}
void University::showAddressProfessor()
{
    int alNumber;
    bool alFound = false;
    std::vector<Professor> p;

    p = this->getProfessors();

    std::cout << "Enter the alNumber of the professor: ";
    std::cin >> alNumber;

    for(int i = 0; i < p.size(); i++)
    {
        if(p[i].getAlNumber() == alNumber)
        {
            std::cout << "\nProfessor's address: " << p[i].getAddress() << std::endl;
            alFound = true;
            break;
        }
    }

    if (!alFound)
{
    std::cout << "\n!!!Professor not found!!!" << std::endl;
    std::cout << "No professor has the provided alNumber" << std::endl;
}

}
void University::showSalaryProfessor()
{
    int alNumber;
    bool alFound = false;
    std::vector<Professor> p;

    p = this->getProfessors();

    std::cout << "Enter the alNumber of the professor: ";
    std::cin >> alNumber;

    for(int i = 0; i < p.size(); i++)
    {
        if(p[i].getAlNumber() == alNumber)
        {
            std::cout << "\nProfessor's salary: " << p[i].getSalary() << std::endl;
            alFound = true;
            break;
        }
    }

    if (!alFound)
{
    std::cout << "\n!!!Professor not found!!!" << std::endl;
    std::cout << "No professor has the provided alNumber" << std::endl;
}

}
void University::showCoursesOnProfessor()
{
    int alNumber;
    bool alFound = false;
    std::vector<Professor> p;

    p = this->getProfessors();

    std::cout << "Enter the alNumber of the professor: ";
    std::cin >> alNumber;

    for(int i = 0; i < p.size(); i++)
    {
        if(p[i].getAlNumber() == alNumber)
        {
            int nCourse = 0;
            std::cout << "\nCourses that the professor is teaching: "<< std::endl;
            std::cout << "-------------------------------------" << std::endl;
            for(int j = 0 ; j < p[i].getCoursesToTeach().size(); j++)
            {
                std::cout << "| " << nCourse++ << " - " << p[i].getCoursesToTeach()[j] << " |" << std::endl;
            }
            std::cout << "-------------------------------------" << std::endl;
            alFound = true;
            break;
        }
    }

    if (!alFound)
    {
        std::cout << "\n!!!Professor not found!!!" << std::endl;
        std::cout << "No professor has the provided alNumber" << std::endl;
    }

}

void University::viewSubjectBibliography()
{
    string subjectName;
    bool subjectFound = false;
    std::vector<Subject> c;

    fflush(stdin);
    std::cout << "Enter the name of the Subject: ";
    std::getline(std::cin, subjectName);
    fflush(stdin);

    for(int i = 0; i < courses.size(); i++)
    {
        for(int j = 0 ; j < courses[i].getSubjects().size(); j++)
        {
            if(courses[i].getSubjects()[j].getSubjectName() == subjectName)
            {
                std::cout << "Bibliography of " << subjectName << ": " << courses[i].getSubjects()[j].getBibliography() << std::endl;
                subjectFound = true;
                break;
            }
        }
        if(subjectFound)
            break;
    }

    if (!subjectFound)
    {
        std::cout << "\n!!!Subject not found!!!" << std::endl;
    }

}
void University::viewSubjectObjectives()
{
    string subjectName;
    bool subjectFound = false;
    std::vector<Subject> c;

    fflush(stdin);
    std::cout << "Enter the name of the Subject: ";
    std::getline(std::cin, subjectName);
    fflush(stdin);

    for(int i = 0; i < courses.size(); i++)
    {
        for(int j = 0 ; j < courses[i].getSubjects().size(); j++)
        {
            if(courses[i].getSubjects()[j].getSubjectName() == subjectName)
            {
                std::cout << "Objectives of " << subjectName << ": " << courses[i].getSubjects()[j].getObjectives() << std::endl;
                subjectFound = true;
                break;
            }
        }
        if(subjectFound)
            break;
    }

    if (!subjectFound)
    {
        std::cout << "\n!!!Subject not found!!!" << std::endl;
    }

}
void University::viewSubjectMethodology()
{
    string subjectName;
    bool subjectFound = false;
    std::vector<Subject> c;

    fflush(stdin);
    std::cout << "Enter the name of the Subject: ";
    std::getline(std::cin, subjectName);
    fflush(stdin);

    for(int i = 0; i < courses.size(); i++)
    {
        for(int j = 0 ; j < courses[i].getSubjects().size(); j++)
        {
            if(courses[i].getSubjects()[j].getSubjectName() == subjectName)
            {
                std::cout << "Evaluation methodology of " << subjectName << ": " << courses[i].getSubjects()[j].getAvaliationMethodology() << std::endl;
                subjectFound = true;
                break;
            }
        }
        if(subjectFound)
            break;
    }

    if (!subjectFound)
    {
        std::cout << "\n!!!Subject not found!!!" << std::endl;
    }

}
void University::viewSubjectMainProfessor()
{
    string subjectName;
    bool subjectFound = false;
    std::vector<Subject> c;
    int nProfessor = 0;
    std::vector<Professor> p;

    fflush(stdin);
    std::cout << "Enter the name of the Subject: ";
    std::getline(std::cin, subjectName);
    fflush(stdin);

    for(int i = 0; i < courses.size(); i++)
    {
        for(int j = 0 ; j < courses[i].getSubjects().size(); j++)
        {
            if(courses[i].getSubjects()[j].getSubjectName() == subjectName)
            {
                std::cout << "Main professor of " << subjectName << ":\n";
                p.push_back(courses[i].getSubjects()[j].getMainProfessor());

                std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "| id - alNumber / name / age / address / salary |" << std::endl;
                std::cout << "| " << nProfessor++ << " - " << p[0].getAlNumber() << " / "<< p[0].getName() << " / " << p[0].getAge() << " / " << p[0].getAddress() << " / " << p[0].getSalary() <<  " |" << std::endl;
                std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;
                subjectFound = true;
                break;
            }
        }
        if(subjectFound)
            break;
    }

    if (!subjectFound)
    {
        std::cout << "\n!!!Subject not found!!!" << std::endl;
    }

}
void University::viewSubjectAssistantProfessors()
{
    string subjectName;
    bool subjectFound = false;
    std::vector<Subject> c;

    fflush(stdin);
    std::cout << "Enter the name of the Subject: ";
    std::getline(std::cin, subjectName);
    fflush(stdin);

    for(int i = 0; i < courses.size(); i++)
    {
        for(int j = 0 ; j < courses[i].getSubjects().size(); j++)
        {
            if(courses[i].getSubjects()[j].getSubjectName() == subjectName)
            {
                std::cout << "Assistant Professors for " << subjectName << ":\n";
                int nProfessor = 0;
                std::vector<Professor> p;
                p = courses[i].getSubjects()[j].getAssistantProfessors();

                std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;
                for(int k = 0 ; k < p.size(); k++)
                {
                    std::cout << "| " << nProfessor++ << " - " << p[k].getAlNumber() << " / "<< p[k].getName() << " / " << p[k].getAge() << " / " << p[k].getAddress() << " / " << p[k].getSalary() <<  " |" << std::endl;
                }
                std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;

                subjectFound = true;
                break;
            }
        }
        if(subjectFound)
            break;
    }

    if (!subjectFound)
    {
        std::cout << "\n!!!Subject not found!!!" << std::endl;
    }

}
void University::changeSubjectBibliography()
{
    string subjectName, newBibliography;
    bool subjectFound = false, firstTime = false;
    std::vector<Subject> c;

    fflush(stdin);
    std::cout << "Enter the name of the Subject: ";
    std::getline(std::cin, subjectName);
    fflush(stdin);

    for(int i = 0; i < courses.size(); i++)
    {
        for(int j = 0 ; j < courses[i].getSubjects().size(); j++)
        {
            if(courses[i].getSubjects()[j].getSubjectName() == subjectName)
            {
                if(!firstTime) {

                    fflush(stdin);
                    std::cout << "Enter the new bibliography for " << subjectName << ": ";
                    std::getline(std::cin, newBibliography);
                    fflush(stdin);

                    firstTime = true;
                }
                c = courses[i].getSubjects();
                c[j].setBibliography(newBibliography);
                courses[i].setSubjects(c);

                subjectFound = true;
            }
        }
    }

    if (!subjectFound)
    {
        std::cout << "\n!!!Subject not found!!!" << std::endl;
    }
    else
    {
        std::cout << "Bibliography of " << subjectName << " successfully modified!!!" << std::endl;
    }
}
void University::changeSubjectObjectives()
{
    string subjectName, subjectObjectives;
    bool subjectFound = false, firstTime = false;
    std::vector<Subject> c;

    fflush(stdin);
    std::cout << "Enter the name of the Subject: ";
    std::getline(std::cin, subjectName);
    fflush(stdin);

    for(int i = 0; i < courses.size(); i++)
    {
        for(int j = 0 ; j < courses[i].getSubjects().size(); j++)
        {
            if(courses[i].getSubjects()[j].getSubjectName() == subjectName)
            {
                if(!firstTime) {
                    fflush(stdin);
                    std::cout << "Enter the new objectives for " << subjectName << ": ";
                    std::getline(std::cin, subjectObjectives);
                    fflush(stdin);
                    firstTime = true;
                }
                c = courses[i].getSubjects();
                c[j].setObjectives(subjectObjectives);
                courses[i].setSubjects(c);

                subjectFound = true;
            }
        }
    }

    if (!subjectFound)
    {
        std::cout << "\n!!!Subject not found!!!" << std::endl;
    }
    else
    {
        std::cout << "Objectives of " << subjectName << " successfully modified!!!" << std::endl;
    }
}
void University::changeSubjectMethodology()
{
    string subjectName, newMetedology;
    bool subjectFound = false, firstTime = false;
    std::vector<Subject> c;

    fflush(stdin);
    std::cout << "Enter the name of the Subject: ";
    std::getline(std::cin, subjectName);
    fflush(stdin);

    for(int i = 0; i < courses.size(); i++)
    {
        for(int j = 0 ; j < courses[i].getSubjects().size(); j++)
        {
            if(courses[i].getSubjects()[j].getSubjectName() == subjectName)
            {
                if(!firstTime) {
                    fflush(stdin);
                    std::cout << "Enter the new evaluation methodology for " << subjectName << ": ";
                    std::getline(std::cin, newMetedology);
                    fflush(stdin);
                    firstTime = true;
                }

                c = courses[i].getSubjects();
                c[j].setAvaliationMethodology(newMetedology);
                courses[i].setSubjects(c);

                subjectFound = true;
            }
        }
    }

    if (!subjectFound)
    {
        std::cout << "\n!!!Subject not found!!!" << std::endl;
    }
    else
    {
        std::cout << "Evaluation methodology of " << subjectName << " modified successfully!!!" << std::endl;
    }
}
void University::addSubjectAssistantProfessor()
{
    std::string subjectName;
    bool subjectFound = false;
    bool firstTime = false;
    std::vector<Subject> c;
    std:vector<Professor> profs;
    Professor profNovo;

    fflush(stdin);
    std::cout << "Enter the name of the Subject: ";
    std::getline(std::cin, subjectName);


    for(int i = 0; i < courses.size(); i++)//para todos os professores copia
    {
        for(int j = 0 ; j < courses[i].getSubjects().size(); j++)
        {
            if(courses[i].getSubjects()[j].getSubjectName() == subjectName)
            {
                if(!firstTime) {
                    std::cin >> profNovo;
                    firstTime = true;
                }
                c = courses[i].getSubjects();
                profs = c[j].getAssistantProfessors();
                profs.push_back(profNovo);
                c[j].setAssistantProfessors(profs);
                courses[i].setSubjects(c);
                subjectFound = true;

                c.clear();
                profs.clear();
            }
        }
    }

    if (!subjectFound)
    {
        std::cout << "\n!!!Subject not found!!!" << std::endl;
    }
    else
    {
        std::cout << "\nAssistant Professor " << profNovo.getName() << " added to " << subjectName << " successfully!!!" << std::endl;
    }

}
void University::removeSubjectAssistantProfessor()
{
    std::string subjectName, profAuxName;
    bool subjectFound = false;
    bool firstTime = false;
    bool profFound = false;
    std::vector<Subject> c;
    std::vector<Professor> profs;

    fflush(stdin);
    std::cout << "Enter the name of the Subject: ";
    std::getline(std::cin, subjectName);
    fflush(stdin);

    for(int i = 0; i < courses.size(); i++)//para todos os professores copia
    {
        for(int j = 0 ; j < courses[i].getSubjects().size(); j++)
        {
            if(courses[i].getSubjects()[j].getSubjectName() == subjectName)
            {
                if(!firstTime) {

                    fflush(stdin);
                    std::cout << "Enter the name of the assistant professor to remove: ";
                    std::getline(std::cin, profAuxName);
                    fflush(stdin);

                    firstTime = true;
                }
                c = courses[i].getSubjects();
                profs = c[j].getAssistantProfessors();
                for(int k = 0 ; k < profs.size(); k++)
                {
                    if(profs[k].getName() == profAuxName) {
                        profs.erase(profs.begin() + k);
                        profFound = true;
                    }
                }
                c[j].setAssistantProfessors(profs);
                courses[i].setSubjects(c);
                subjectFound = true;

                c.clear();
                profs.clear();
            }
        }
    }

    if (!subjectFound)
    {
        std::cout << "\n!!!Subject not found!!!" << std::endl;
    }

    if (!profFound)
    {
        std::cout << "\n!!!Professor not found!!!" << std::endl;
    }
}


std::vector<Professor> University::getProfessors() {
    std::vector<Professor> p;
    for(int i = 0 ; i < courses.size(); i++)
    {
        for(int j = 0 ; j < courses[i].getSubjects().size();j++)
        {
            putOnVectorWithoutDuplicates(p, courses[i].getSubjects()[j].getMainProfessor());
            for(int k = 0 ; k < courses[i].getSubjects()[j].getAssistantProfessors().size();k++)
            {
                putOnVectorWithoutDuplicates(p, courses[i].getSubjects()[j].getAssistantProfessors()[k]);
            }
        }
    }
    return p;
}

std::ofstream & operator << (std::ofstream &c, University &u)
{
    for (int i = 0; i < u.students.size(); i++)
    {
        c << u.students[i];
    }
    return c;
}

University::~University() {}

#endif