#ifndef PRODUCT_H_
#define PRODUCT_H_
#include <string>

enum class product_type
{
    none,
    one,
    two
    // ...... 
    
};

class Product
{
public:
    Product() = default;
    ~Product() = default;

    virtual const std::string & name()
    {
        return m_name;
    }

private:
    std::string m_name;

};


class ProductA final :public Product
{
public:
    ProductA() = default;
    ~ProductA() = default;

    virtual const std::string& name()
    {
        return m_name;
    }

private:
    std::string m_name;

};

class ProductB final :public Product
{
public:
    ProductB() = default;
    ~ProductB() = default;

    virtual const std::string& name()
    {
        return m_name;
    }

private:
    std::string m_name;

};



#endif 