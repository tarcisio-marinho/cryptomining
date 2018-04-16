#ifndef TASKS_H
#define TASKS_H

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <unistd.h>
#include <thread>
#include <pthread.h>
#include "error.h"

#define MAX_TERMINAL_OUTPUT 50000

namespace Tasks{
    bool lock_task_manager = false;

    void check_task_manager();
    void threading_task_manager();
};



#endif