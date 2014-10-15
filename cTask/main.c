/* 
 * File:   main.c
 * Author: francesco
 *
 * Created on 15 ottobre 2014, 23.49
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "task.h"

void *hello_world(void **args);

/*
 * 
 */
int main(int argc, char** argv) {
    
    printf("Creating Task...");
    TASK_P t = new_task(PROCESS,NULL,hello_world);
    
    printf("Task Start");
    run_task(t);
    printf("Task End");
    
    sleep(3);

    return (EXIT_SUCCESS);
}

void *hello_world(void **args){
    
    printf("Hello World!!!\n");
    sleep(5);
}

