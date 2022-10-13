#pragma once

#include <BnHelloService.h>

class HelloService: public BnHelloService {
public:
    static void publish();

    virtual ~HelloService();

    virtual void sayhello();
    virtual void sayhello_to(const char * name);
private:
    static HelloService* test;
};
