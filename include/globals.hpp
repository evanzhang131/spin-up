#pragma once
#include "main.h"

namespace motor {
    extern pros::Motor left_f;
	extern pros::Motor left_m;
    extern pros::Motor left_b;
	extern pros::Motor right_f;
	extern pros::Motor right_m;
    extern pros::Motor right_b;
    extern pros::Motor flywheel1;
    extern pros::Motor flywheel2;
}

namespace piston {
    extern pros::ADIDigitalOut pto;    
}

extern pros::Controller Master;