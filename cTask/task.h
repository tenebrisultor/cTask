/* 
 * File:   task.h
 * Author: francesco
 *
 * Created on 15 ottobre 2014, 23.49
 */

#ifndef TASK_H
#define	TASK_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <pthread.h>

#define CHILD 0
#define FORK_FAILED -1

 typedef union{
     pid_t pid;
     pthread_t tid;
}TASK_ID;

typedef enum{PROCESS,THREAD}TASK_TYPE;

typedef struct {
    TASK_TYPE type;
    TASK_ID tid;
    void **args;
    void*(*run)(void**);
}TASK_T;
typedef TASK_T* TASK_P;

TASK_P new_task(TASK_TYPE t,void **args,void*(*run)(void**));
void run_task(TASK_P tsk);
void stop_task(TASK_P tsk);

#endif	/* TASK_H */

