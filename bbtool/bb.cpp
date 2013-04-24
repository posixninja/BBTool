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

void bb_enter_download_mode() {
    printf("Entering download mode\n");
    io_connect_t connect = 0;
    CFMutableDictionaryRef match = IOServiceMatching("AppleBaseband");
    io_service_t service = IOServiceGetMatchingService(0, match);
    IOServiceOpen(service, mach_task_self(), 0, &connect);
    uint64_t cmd = 0x1;
    IOConnectCallScalarMethod(connect, 0x1, &cmd, 0x1, 0, 0);
    IOServiceClose(connect);
    sleep(1);
}