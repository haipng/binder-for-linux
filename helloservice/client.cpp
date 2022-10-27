#include <iostream>
#include <unistd.h>
#include <BpHelloService.h>
#include <binder/IServiceManager.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>

using namespace std;
using namespace android;

class HelloSvcDeathRecipient : public IBinder::DeathRecipient {
    public:
        HelloSvcDeathRecipient() {
            cout << "client: create HelloSvcDeathRecipient\n";
        };
        void binderDied(const wp<IBinder>& who) {
            cout << "!!!!!!!!\n";
            cout << "client: HelloService has died. Terminate client.\n";
            exit(0);
        };

};

String16 serviceName("helloservice");

int main(int argc, char *argv[]) {
    sp<IBinder> binder;    
    sp<IServiceManager> sm = defaultServiceManager();

    do {
        binder = sm->getService(serviceName);
        if (binder != 0) break;
        cout << "client: server is not published, waiting..." << endl;
        usleep(5000); // 5 ms
    } while(true);

    cout << "client: connected to server\n";

    sp<IHelloService> service = interface_cast<IHelloService>(binder);

    cout << "client: recv from server: " << service->sayhello() << endl;

    cout << "client: recv from server: " << service->sayhello_to(String8("Jackson")) << endl;

    cout << "client: add integer: " << service->addInts(35, 36) << endl;

    cout << endl << endl;

    sp<HelloSvcDeathRecipient> dr=(new HelloSvcDeathRecipient());
    cout << "client: linktoDeath returns " << binder->linkToDeath(dr) << endl << endl;

    sp<ProcessState> ps(ProcessState::self());
    ps->startThreadPool();

    while(1) {
        cout << "client: recv from server: " << service->sayhello() << endl;
        
        sleep(1);
    }
}

