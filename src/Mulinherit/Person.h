#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

class Person
{
public:
    Person(std::string name,std::string ID = "")
        :name_(name)
        ,id_(ID)
    {

    }
    
    ~Person()
    {

    }

protected:
    std::string name_{"name"};
    std::string birthDay_{"2000.1.1"};
    std::string id_{"XXXXXXXXXXXXXXXXXX"};

};


class Student : public Person
{

public:
    Student()
        :Person("stu")
    {

    }
    ~Student() = default;


protected:
    std::string stuId_;



};


class Teacher :public Person
{
public:
    Teacher()
        :Person("teacher")
    {
        
    
    }
    ~Teacher() = default;

protected:
    std::string teacherId_;


};


class Author :public Student, public Teacher
{

public:
    Author()
    {
        Student::name_ = "";
        Teacher::name_ = "";
    }

};

#endif 