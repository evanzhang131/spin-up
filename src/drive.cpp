#include "main.h"

namespace drive {
    void op_drive() {
        const int deadband = 5;
        int x = abs(Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));
		int y = abs(Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
		double LjoyY = y/10.0;
		double LjoyX = x/10.0;
        double power = 0;
        double turn = 0;

		if (y > deadband || x > deadband) {
			if (y > 85) {
				power = (12.7 / (1.0 + exp(-(3.0/4.0)*(LjoyY - 6.0)))) * 10.0 - 3.0;
			}
			else if (y > 55 && y <= 85) {
				power = (12.7 / (1.0 + exp(-(3.0/4.0)*(LjoyY - 6.0)))) * 10.0 - 10.0;
			}
			else {
				power = 5*pow((1.0/5.5)*(LjoyY), 3.0) * 12.7;
			}

			if (x > 85) {
				turn = (12.7 / (1.0 + exp(-(3.0/4.0)*(LjoyX - 6.0)))) * 10.0 - 3.0;
			}
			else if (x > 55 && x <= 85) {
				turn = (12.7 / (1.0 + exp(-(3.0/4.0)*(LjoyX - 6.0)))) * 10.0 - 10.0;
			}
			else {
				turn = 5*pow((1.0/5.5)*(LjoyX), 3.0) * 12.7;
			}
		}

		if (Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) < 0) {
			power = -power;
		}

		if (Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X) < 0) {
			turn = -turn;
		}

        double leftPower = power - turn;
		double rightPower = power + turn;
        
		motor::left_f.move(leftPower);
        motor::left_m.move(leftPower);
        motor::left_b.move(leftPower);
		motor::right_f.move(rightPower);
		motor::right_m.move(rightPower);
        motor::right_b.move(rightPower);
    }
}