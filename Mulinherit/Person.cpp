#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

class Person
{
public:
    Person()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    Person(std::string name,std::string ID = "")
        :name_(name)
        ,id_(ID)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    ~Person()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
protected:
    std::string name_{"name"};
    std::string birthDay_{"2000.1.1"};
    std::string id_{"XXXXXXXXXXXXXXXXXX"};
};

class Student : virtual public Person
{

public:
    Student(std::string name_ = "")
        :Person("stu")
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    ~Student()
    {
        std::cout << __FUNCTION__ << std::endl;
    };
protected:
    std::string stuId_;
};


class Teacher : virtual public Person
{
public:
    Teacher(std::string name_ = "")
        :Person("teacher")
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    ~Teacher()
    {
        std::cout << __FUNCTION__ << std::endl;
    };
protected:
    std::string teacherId_;
};


class Author :public Student, public Teacher
{
public:
    Author(std::string name_)
        // : Student(name_)
        // , Teacher(name_)
        // , Person(name_)
    {
        this->name_ = name_;
        std::cout << __FUNCTION__ << std::endl;
    }
    ~Author()
    {
        std::cout << __FUNCTION__ << std::endl;
    }


};








#endif 