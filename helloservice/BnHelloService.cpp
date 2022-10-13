#include <BnHelloService.h>

status_t BnHelloService::onTransact(uint32_t code, const Parcel &data, Parcel* reply, uint32_t flags) {
    switch(code) { 
        case SAYHELLO:
        {
        #if 0
            sayhello();
	    std::string hello = "Hello world!";
            reply->writeCString(hello.c_str());
            #endif
            break;
        }
        case SAYHELLO_TO:
        {
        #if 0
            std::string name = data.readCString();
            std::string hello_to = "Greeting to" + name;
            reply->writeCString(hello_to.c_str());
            sayhello_to(name.c_str());
            #endif
            break;
        }
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
    return 0;
}

void sayhello() {
    //
}

void sayhello_to(const char *name) {
    //
}

