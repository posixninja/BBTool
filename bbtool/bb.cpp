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
    //IOServiceMatching("AppleBaseband")
    //RET: 0x1ed13540
    CFMutableDictionaryRef match = IOServiceMatching("AppleBaseband");
    
    //IOServiceGetMatchingService(0x0, 0x1ed13540)
    //RET: 0x1107
    io_service_t service = IOServiceGetMatchingService(0, match);
    
    
    //IOServiceOpen(0x1107, 0x907, 0x0, 0x1ed134f8)
    //RET: 0x0
    IOServiceOpen(service, mach_task_self(), 0, &connect);
    
    //IOConnectCallMethod(0x1603, 0x14, 0x0, 0x0, 0x2fdbecc8, 0x40, 0x0, 0x0, 0x0, 0x0)
    //45 54 4c 54 6f 6f 6c 3a  20 54 65 6c 65 70 68 6f  | ETLTool: Telepho
    //6e 79 42 61 73 65 62 61  6e 64 00 00 00 00 00 00  | nyBaseband......
    //00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  | ................
    //00 00 00 00 00 00 00 00  d0 cb 08 3c ac ed db 2f  | ...........<.../
    //RET: 0x0
    
    //IOConnectCallScalarMethod(0x1603, 0x1, 0x2fdbf750, 0x1, 0x0, 0x0)
    //RET: 0x0
    uint64_t cmd = 0x1;
    IOConnectCallScalarMethod(connect, 0x1, &cmd, 0x1, 0, 0);
    IOServiceClose(connect);
    sleep(1);
}