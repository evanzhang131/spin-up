#pragma once
#include "main.h"

namespace drive {
    void op_drive();    
}

extern bool run_flywheel;
extern bool piston_out;

void op_flywheel();
void op_pto();