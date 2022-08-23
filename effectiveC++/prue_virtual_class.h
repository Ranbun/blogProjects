//
// Created by RanLH on 2022/8/23.
//

#ifndef BLOG_PROJECTS_PRUE_VIRTUAL_CLASS_H
#define BLOG_PROJECTS_PRUE_VIRTUAL_CLASS_H

class PrueVirtualBase
{
public :
    PrueVirtualBase() = default;
    virtual ~PrueVirtualBase() = 0;


};

inline  PrueVirtualBase::~PrueVirtualBase()
{
    std::cout<<__FUNCTION__ <<std::endl;
}

class Test : public  PrueVirtualBase
{
public:
    Test()
    :PrueVirtualBase()
    {
        std::cout<<__FUNCTION__ <<std::endl;
    }
    ~Test() override
    {
        std::cout<<__FUNCTION__ <<std::endl;
    }

};



#endif //BLOG_PROJECTS_PRUE_VIRTUAL_CLASS_H
