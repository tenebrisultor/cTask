#include "common.h"
#include "task.h"
#include <stdlib.h>
#include <stdio.h>

TASK_P new_task(TASK_TYPE type,void **args,void*(*run)(void**)){
    TASK_P t = NULL;
    
    if(!(t=(TASK_P)malloc(sizeof(TASK_T))))
        exit(EXIT_FAILURE);
    
    t->type = type;
    t->args = args;
    t->run = run;
    
    return t;
}

void run_process(TASK_P tsk){
    
    switch(tsk->tid.pid = fork()){
        case CHILD : 
            printf("Fork Success\n");
            tsk->run(tsk->args);
            break;
        case FORK_FAILED:
            printf("Fork Failed!\n");
            exit(EXIT_FAILURE);
            break;
        default:
            break;
    }
}
void run_task(TASK_P tsk){
    
    switch(tsk->type){
        case PROCESS:
            printf("Process Start\n");
            run_process(tsk);
            break;
        case THREAD:
            break;
        default:
            printf("No TASK started\n");
    }
}

void stop_task(TASK_P tsk){
    
    switch(tsk->type){
        case PROCESS:
            exit(EXIT_SUCCESS);
            break;
        case THREAD:
            break;
    }
}
