#include <BpHelloService.h>

       
void BpHelloService::sayhello(void)
{
#if 0 
    Parcel data, reply;
    data.writeInt32(0);
    remote()->transact(SAYHELLO, data, &reply);

    std::cout << "RECV: " << reply.readString8(reply) << std::endl;
#endif
}


void BpHelloService::sayhello_to(const char *name)
{
#if 0
    Parcel data, reply;
    data.writeString8(name);
    remote()->transact(SAYHELLO_TO, data, &reply);
    std::cout << "RECV: " << reply.readString8(reply) << std::endl;
    #endif
}

