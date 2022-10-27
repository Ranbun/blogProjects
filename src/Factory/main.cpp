#include <iostream>

#include "Factory.h"
#include "concreteFactory.h"

int main()
{
    // const auto factory = new Factory;
    // auto product_a = factory->crteateProduct(product_type::none);

    const auto factory = new FactoryA;
    auto product_a = factory->crteateProduct();

    return 0;
}