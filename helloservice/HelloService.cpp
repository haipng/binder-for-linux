#include <HelloService.h>
#include <binder/IServiceManager.h>

HelloService * HelloService::test = NULL;

void HelloService::publish() {
    if(test == NULL) {
        test = new HelloService();
        defaultServiceManager()->addService(String16("helloservice"), test);
    }

}

HelloService::~HelloService()
{
}


void HelloService::sayhello()
{
}


void HelloService::sayhello_to(const char * name) {
}
