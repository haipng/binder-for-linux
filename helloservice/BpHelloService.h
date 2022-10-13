#pragma once

#include <IHelloService.h>

using namespace android;

class BpHelloService : public BpInterface<IHelloService>
{   
public:
    BpHelloService(const sp<IBinder>& impl)
        : BpInterface<IHelloService>(impl)
        {

        }

    virtual void sayhello(void);
    virtual void sayhello_to(const char *name);
}; 
