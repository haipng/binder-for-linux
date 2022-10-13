#include <iostream>
#include <unistd.h>
#include <BpHelloService.h>
#include <binder/IServiceManager.h>

using namespace std;
using namespace android;


String16 serviceName("helloservice");

int main(int argc, char *argv[]) {
    sp<IBinder> binder;    
    sp<IServiceManager> sm = defaultServiceManager();

    do {
        binder = sm->getService(serviceName);
        if (binder != 0) break;
        cout << serviceName << " not published, waiting..." << endl;
        usleep(500000); // 0.5 s
    } while(true);


    sp<IHelloService> service = interface_cast<IHelloService>(binder);

    service->sayhello();

    service->sayhello_to("Jackson");
}

