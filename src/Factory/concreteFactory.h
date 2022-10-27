#ifndef __CONCRETEFACTORY_H__
#define __CONCRETEFACTORY_H__

#include "Factory.h"

class FactoryA final : public Factory
{
public:
    FactoryA() = default;
    ~FactoryA() = default;


    Product* crteateProduct() override
    {
        return new ProductA;
    }

};


#endif 