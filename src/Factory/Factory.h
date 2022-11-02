#ifndef FACTORY_H_
#define FACTORY_H_

#define FACTORY_METHOD  1
#define SAMPLE_FACTORY 0

#include "Product.h"

#if SAMPLE_FACTORY

class Factory
{
public:
    Factory() = default;
    ~Factory() = default;


    virtual  Product* crteateProduct(const product_type & type)
    {
        if(type == product_type::one)
        {
            return new  ProductA;
        }
        if(type == product_type::two)
        {
            return new ProductB;
        }
        else
        {
            return nullptr;
        }
    }

    virtual Product* crteateProduct(){};

};

#endif 


#if FACTORY_METHOD

class Factory
{
public:
    Factory() = default;
    ~Factory() = default;

    virtual Product* crteateProduct() { return nullptr; };

};

#endif 



#endif
