#include <iostream>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/IInterface.h>
#include <HelloService.h>



using namespace std;
using namespace android;

String16 serviceName = String16("helloservice");

int main(int argc, char *argv[]) {
    std::cout << "Hello Server" << std::endl;
    
    HelloService::publish();
    
    sp<ProcessState> proc(ProcessState::self());
    proc->startThreadPool();
}

