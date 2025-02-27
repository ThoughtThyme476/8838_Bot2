
#include "main.h"
#include "api.h"
#include "pid.h"
#include "robot.h"
#include "auton.h"
bool stay_clamp = true;

using namespace pros;
using namespace std;

int atn = 1;
string autstr;
// Task colorSortTask;
// bool colorSortActive = false;

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}//bla bla bla
//bla bla bla

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);

	while(true){
		if (con.get_digital_new_press(E_CONTROLLER_DIGITAL_A)){
			atn++;
		}
		if(atn>7){//change number to number of autons
			atn=0;
		}
		if (atn == 0) {
			autstr = "NONE";
			con.print(0,0, "Aut 0:%s", autstr);
		}
		else if (atn ==1) {
			autstr = "RED RING";
			con.print(0,0, "Aut 1: %s", autstr);
		}
		else if (atn ==2) {
			autstr = "BLUE RING";
			con.print(0,0, "Aut 2: %s", autstr);
		}
		else if (atn ==3) {
			autstr = "RED GOAL QUALS";
			con.print(0,0, "Aut 3: %s", autstr);
		}
		else if (atn ==4) {
			autstr = "BLUE GOAL QUALS";
			con.print(0,0, "Aut 4: %s", autstr);
		}
		else if (atn ==5) {
			autstr = "RED GOAL ELIMS";
			con.print(0,0, "Aut 5: %s", autstr);
		}
		else if (atn ==6) {
			autstr = "BLUE GOALS ELIMS";
			con.print(0,0, "Aut 6: %s", autstr);
		}
		else if (atn ==7) {
			autstr = "SKILLS";
			con.print(0,0, "Aut 7: %s", autstr);
		}

		if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_X)){
			break;
		}




			}

//auton selector

}
void disabled() { 
	// imu.tare(); 
	// while(stay_clamp = true){
	// 	MogoMech.set_value(true);
	// }
}

//void autonomous moved into just auton.cpp

void competition_initialize() {

}


void opcontrol() {


bool arcToggle = true;
bool tankToggle=false;
bool StakeWingToggle=false;
double liftAngle=true;
int time =0;
bool hooks_Macro = false;
bool  hooks_Macro_Rev = false;
bool fishy_macro = false;
bool return_fishmech = false;
bool MogoMechToggle = false;

while (true) {

// if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_A)){
// driveTurn(175);
// delay(3000);
// }

//macro fishy
if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)){
	fishy_macro=!fishy_macro;
}

//Mogo Mech
if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_X)){
	MogoMechToggle = !MogoMechToggle;
}
MogoMech.set_value(MogoMechToggle); 

//Stakewing toggle
if (con.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
            StakeWingToggle = !StakeWingToggle;
 }
 StakeWing.set_value(StakeWingToggle);

// Fish mech
bool is_above = (fishy.get_angle() >= 9000) && (fishy.get_angle() < 27000);
if (con.get_digital(E_CONTROLLER_DIGITAL_L1)){
	// Rotates fishmech back to the starting position
	bool forbidden = ((fishy.get_angle() >= 27000) && (fishy.get_angle() <= 34000));

    if (forbidden == false) {
		// Safe to move
		int speed = 70;
		if (!is_above && (fishy.get_angle() >= 27000)) {
			// Close to the limit so slow down
			speed = 20;
		}
    	Redirect.move(speed);
	} else 
		// There isn't a BRAKE mode, so just move the other way to
		// stay in place
		Redirect.move(0);
	} else if (con.get_digital(E_CONTROLLER_DIGITAL_L2)){
	// Rotates fishmech to put the ring on the stake
	bool forbidden = (is_above && (fishy.get_angle() >= 23000));

    if (forbidden == false) {
		// Safe to move
		int speed = -70;
		if (is_above && (fishy.get_angle() >= 19000)) {
			// Close to the limit so slow down
			speed = -20;
		}
    	Redirect.move(speed);
	} else {
		// There isn't a BRAKE mode, so just move the other way to stay in place 
		Redirect.move(10);
	}

	// Once we are above automatically return to start
	if (is_above) {
		return_fishmech = true;
	}

	fishy_macro=false; 
	liftAngle = fishy.get_position();
	Redirect.set_brake_mode(MOTOR_BRAKE_HOLD);
} 
else if (fishy_macro){
	setConstants(LIFT_KP,LIFT_KI,LIFT_KD);
	Redirect.move(calcPID(37000,fishy.get_position(),0,0));
	if(abs(fishy.get_position()-37000)<200){
		fishy_macro=false;
	}
}
else {
	// We aren't in macro mode, and no buttons are pressed
	// setConstants(LIFT_KP,LIFT_KI,LIFT_KD);
	// Redirect.move(0);
	//Redirect.move(calPID(liftAngle,fishy.get_position(),0,0));
	if (return_fishmech && is_above) {
		// fish mech is above horizontal, automatically return to start
	    Redirect.move(50);
	} else {
		// fish mech is below horizontal, let it just coast
		return_fishmech = false;
		Redirect.move(0);
		Redirect.set_brake_mode(MOTOR_BRAKE_BRAKE);
	}
}
//pid tester m 
// if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_A)){
// autons5();
// }



//Intake
if (con.get_digital(E_CONTROLLER_DIGITAL_R1)){
	Intake.move(90);
	Intake_Layer1.move(127);
	Intake.tare_position();
	hooks_Macro = false; 
}
else if (con.get_digital(E_CONTROLLER_DIGITAL_R2)){
	Intake.move (-90);
	Intake_Layer1.move(-127);
	Intake.tare_position(); 
	hooks_Macro = false; 
}
// else if(hooks_Macro){
	
//  if(Intake.get_position() > 900){
// 	hooks_Macro_Rev = true;
//  }
//  if((hooks_Macro_Rev == true) && (Intake.get_position() < 200)){

// 	hooks_Macro_Rev = false;
// 	hooks_Macro = false;
//  } else if(hooks_Macro_Rev){
// 	delay(1000);
// 	setConstants(1, 0, 0);
// 	Intake.move(calPID (150, Intake.get_position(), 0, 0));
// 	Intake_Layer1.move(calPID (150, Intake.get_position(), 0, 0));
//  } else{
// 	setConstants(1, 0, 0);
// 	Intake.move(calPID (850, Intake.get_position(), 0, 0));
// 	Intake_Layer1.move(calPID (1000, Intake.get_position(), 0, 0));
//  }

//}
else {
	Intake.move(0);
	Intake_Layer1.move(0);
	Intake.tare_position(); 
	hooks_Macro = false; 
}
//chassis drive 
int power = con.get_analog(ANALOG_LEFT_Y);
int RX = con.get_analog(ANALOG_RIGHT_X);
int turn = int(pow(RX, 3)/ 16129);
int left= power + turn; 
int right = power - turn;

// if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_B)){
// 	arcToggle = !arcToggle;
// 	tankToggle = !tankToggle;
// }

if (tankToggle){
	LF.move(con.get_analog(ANALOG_LEFT_Y));
	LM.move(con.get_analog(ANALOG_LEFT_Y));
	LB.move(con.get_analog(ANALOG_LEFT_Y));
	RF.move(con.get_analog(ANALOG_RIGHT_Y));
	RM.move(con.get_analog(ANALOG_RIGHT_Y));
	RB.move(con.get_analog(ANALOG_RIGHT_Y));
}

if (arcToggle) {
LF.move(left);
LM.move(left);
LB.move(left);
RF.move(right);
RM.move(right);
RB.move(right);
}

if (time % 50 == 0 && time % 100 !=0 && time % 150 !=0){
    con.print(0,0,"Time:%f       ", float(time));//viewTime
} else if (time% 100 == 0 && time % 150 !=0){
    con.print(1,0,"HeadingError!%f          ", float(imu.get_heading()));
} else if (time % 150 == 0){
    con.print(2,0,"Error:%f      ",float(error));
}

delay(10);
time += 10;

}

}
/hello