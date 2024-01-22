cmake_minimum_required(VERSION 3.25)
project(sip)

set(CMAKE_CXX_STANDARD 17)

add_executable(sip main.cpp person.cpp person.h student.cpp student.h professor.cpp professor.h subject.cpp subject.h course.cpp course.h
        university.h
        university.cpp
)
