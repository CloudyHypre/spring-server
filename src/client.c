// Copyright (c) 2016 Brian Barto
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the MIT License. See LICENSE for more details.

// Required header for custom functions. Do not remove.
#include "modules/component.h"
#include <stdio.h>
#include <unistd.h>

#define VERSION "0.1.0"

// Copy and paste the function templates below to start creating your
// custom functions.

int main_callable(char *hostname, char *portno);
void main_init(void);
int main_sigint(int);
int main_shutdown(const char *);
int isprint (int c);

// Copy and paste the function templates below to start creating your
// custom functions.

/***********************************************************************

CONNECT_FUNCTION(function_name) {
	(void)socket;
	
	// Code here
}

DISCONNECT_FUNCTION(function_name) {
	(void)socket;
	
	// Code here
}

PERIODIC_FUNCTION(function_name) {
	// Code here
}

COMMAND_FUNCTION(function_name) {
	(void)socket;
	(void)payload;
	
	// Code here
}

***********************************************************************/

/*
 * The client_init() function is executed when the client starts. This
 * function should be used to load all your custom functions. Further,
 * any other initialization tasks needed for your custom application can
 * be added to this function e.g. connecting to a database.
 */
void client_init(void) {
	
	// Load your custom functions here.
	//
	// e.g.
	// set_connect_function(&function_name);
	// set_disconnect_function(&function_name);
	// add_periodic_function(&function_name);
	// add_command_function("cmnd", &function_name);

}


int main(int argc, char *argv[]) {
    
    char *hostname, *portno;
    int o;
    
    // Check arguments
    while ((o = getopt(argc, argv, "h:p:v")) != -1) {
        switch (o) {
            case 'p':
                portno = optarg;
                break;
            case 'h':
                hostname = optarg;
                break;
            case 'v':
                printf("spring server version " VERSION "\n");
                return 0;
            case '?':
                if (isprint(optopt))
                    log_print("Unknown option '-%c'.", optopt);
                else
                    log_print("Unknown option character '\\x%x'.", optopt);
                return main_shutdown("Invalid command option(s).");
        }
    }
    
//     int argcCopy = malloc(sizeof(int));
//     argcCopy = argc;
    
//     char** argvCopy = argv;
    
    printf("first connection\n");
    main_callable(hostname, portno);
    
    printf("second connection\n");
    main_callable(hostname, portno);
    
    printf("third connection\n");
    main_callable(hostname, portno);
}

