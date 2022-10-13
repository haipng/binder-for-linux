#pragma once

#include <binder/IInterface.h>
#include <binder/Parcel.h>

using namespace android;

class IHelloService: public IInterface
{
    public:
    DECLARE_META_INTERFACE(HelloService);

    enum command {
        SAYHELLO = 0x11,
        SAYHELLO_TO = 0x12
    };


    virtual void sayhello(void) =0;
    virtual void sayhello_to(const char *name) =0;
};
