//
//  bb.cpp
//  bbtool
//
//  Created by Joshua Hill on 4/24/13.
//
//

#include <mach/mach.h>
#include <IOKit/IOKitLib.h>

#include "bb.h"

void bb_reset() {
    printf("Resetting baseband\n");
    io_connect_t connect = 0;
    CFMutableDictionaryRef match = IOServiceMatching("AppleBaseband");
    io_service_t service = IOServiceGetMatchingService(0, match);
    IOServiceOpen(service, mach_task_self(), 0, &connect);
    IOConnectCallScalarMethod(connect, 0, 0, 0, 0, 0);
    IOServiceClose(connect);
    sleep(1);
}