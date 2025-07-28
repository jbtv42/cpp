#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

void identify(Base* p);
void identify(Base& p);
Base* generate();

#endif
