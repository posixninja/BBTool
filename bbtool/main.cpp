//
//  main.cpp
//  bbtool
//
//  Created by Joshua Hill on 4/24/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "bb.h"

void usage() {
    printf("usage: bbtool <cmd>\n");
    printf("commands: \n");
    printf("\treset\n");
}

int main (int argc, const char* argv[]) {
    if(argc < 2) {
        usage();
    }
    
    printf("Starting BBTool\n");
    const char* command = argv[1];
    if(strcmp(command, "reset") == 0) {
        bb_reset();
        
    } else {
        usage();
    }
    
	return 0;
}

