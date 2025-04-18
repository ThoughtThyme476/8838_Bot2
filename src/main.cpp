
#include "main.h"
#include "api.h"
#include "pid.h"
#include "robot.h"
#include "auton.h"
bool stay_clamp = true;

using namespace pros;
using namespace std;

int atn = 3;
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
	// pros::lcd::initialize();
	// pros::lcd::set_text(1, "Hello PROS User!");

	// pros::lcd::register_btn1_cb(on_center_button);

	// while(true){
	// 	if (selec.get_value() == true){
	// 		atn++;
	//delay(350);
	// 	}
	// 	if(atn>7){//change number to number of autons
	// 		atn=0;
	// 	}
	// 	if (atn == 0) {
	// 		autstr = "NONE";
	// 		con.print(0,0, "Aut 0:%s", autstr);
	// 	}
	// 	else if (atn ==1) {
	// 		autstr = "RED RING";
	// 		con.print(0,0, "Aut 1: %s", autstr);
	// 	}
	// 	else if (atn ==2) {
	// 		autstr = "BLUE RING";
	// 		con.print(0,0, "Aut 2: %s", autstr);
	// 	}
	// 	else if (atn ==3) {
	// 		autstr = "RED GOAL QUALS";
	// 		con.print(0,0, "Aut 3: %s", autstr);
	// 	}
	// 	else if (atn ==4) {
	// 		autstr = "BLUE GOAL QUALS";
	// 		con.print(0,0, "Aut 4: %s", autstr);
	// 	}
	// 	else if (atn ==5) {
	// 		autstr = "RED GOAL ELIMS";
	// 		con.print(0,0, "Aut 5: %s", autstr);
	// 	}
	// 	else if (atn ==6) {
	// 		autstr = "BLUE GOALS ELIMS";
	// 		con.print(0,0, "Aut 6: %s", autstr);
	// 	}
	// 	else if (atn ==7) {
	// 		autstr = "SKILLS";
	// 		con.print(0,0, "Aut 7: %s", autstr);
	// 	}

	// 	if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_X)){
	// 		break;
	// 	}




	// 		}

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
// while(true){
	// 	if (selec.get_value() == true){
	// 		atn++;
	//delay(350);
	// 	}
	// 	if(atn>7){//change number to number of autons
	// 		atn=0;
	// 	}
	// 	if (atn == 0) {
	// 		autstr = "NONE";
	// 		con.print(0,0, "Aut 0:%s", autstr);
	// 	}
	// 	else if (atn ==1) {
	// 		autstr = "RED RING";
	// 		con.print(0,0, "Aut 1: %s", autstr);
	// 	}
	// 	else if (atn ==2) {
	// 		autstr = "BLUE RING";
	// 		con.print(0,0, "Aut 2: %s", autstr);
	// 	}
	// 	else if (atn ==3) {
	// 		autstr = "RED GOAL QUALS";
	// 		con.print(0,0, "Aut 3: %s", autstr);
	// 	}
	// 	else if (atn ==4) {
	// 		autstr = "BLUE GOAL QUALS";
	// 		con.print(0,0, "Aut 4: %s", autstr);
	// 	}
	// 	else if (atn ==5) {
	// 		autstr = "RED GOAL ELIMS";
	// 		con.print(0,0, "Aut 5: %s", autstr);
	// 	}
	// 	else if (atn ==6) {
	// 		autstr = "BLUE GOALS ELIMS";
	// 		con.print(0,0, "Aut 6: %s", autstr);
	// 	}
	// 	else if (atn ==7) {
	// 		autstr = "SKILLS";
	// 		con.print(0,0, "Aut 7: %s", autstr);
	// 	}

	// 	if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_X)){
	// 		break;
	// 	}
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
bool LBC = false;
int Macro = 0;
bool IntakePiston = false;
eyes.set_led_pwm(100);


while (true) {

	//ColorSort();
	//delay(10);
	// if (con.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) {
	// 	//driveStraightC(250);
	// 	// Intake.move(127);
	// 	// driveSortHoldRed(1000, 50);
	// 	//driveStraight2(500);
	// 	MogoMech.set_value(true);
	// }

//Stakewing toggle
 if (con.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) {
	// Intake.move(127);
	// color = 1;
	// while(true){
	// 	ColorSort();
	// 	delay(10);
	// }
	driveStraight2(100);
	driveArcRF(90, 600, 1500, 100);
	driveStraight2(100);
 }

  

  if (con.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
	StakeWingToggle = !StakeWingToggle;
	 }
StakeWing.set_value(StakeWingToggle);

//Intake
if (con.get_digital(E_CONTROLLER_DIGITAL_R1)){
	Intake.move(127);
	Intake.tare_position();
	hooks_Macro = false; 
}
else if (con.get_digital(E_CONTROLLER_DIGITAL_R2)){
	Intake.move (-127);
	Intake.tare_position(); 
	hooks_Macro = false; 
} else {
	Intake.move(0);
	Intake.tare_position(); 
	hooks_Macro = false; 
}


//lady brown macro 
if(con.get_digital(E_CONTROLLER_DIGITAL_L1)){
	LBC = false;
	LadyBrown.move(127);
	
	
} else if(con.get_digital(E_CONTROLLER_DIGITAL_L2)){
	LBC = false;
	LadyBrown.move(-127);

	
	
 } else if (LBC == false){
 	LadyBrown.move(0);
	 LadyBrown.brake();
 }



if (con.get_digital(E_CONTROLLER_DIGITAL_UP)) { //lady brown loading macro
  // Set it into Macro Mode
  LBC = true;
  Macro++;

  // Finds the angle that we need to move 
  double current_angle = roto.get_angle() / 100.0;
  double target_angle = 247;
  double change_angle = target_angle - current_angle;
  
  // Finding how far to move the motor
  double motor_ticks = change_angle * 5;

  // Move motor to the desired position
  LadyBrown.move_relative(motor_ticks, 90);
} 

if (con.get_digital(E_CONTROLLER_DIGITAL_DOWN)) { //lady brown descore macro
	// Set it into Macro Mode
	LBC = true;
	Macro++;
  
	// Finds the angle that we need to move 
	double current_angle = roto.get_angle() / 100.0;
	double target_angle = 135;
	double change_angle = target_angle - current_angle;
	
	// Finding how far to move the motor
	double motor_ticks = change_angle * 5;
  
	// Move motor to the desired position
	LadyBrown.move_relative(motor_ticks, 90);
  } 
  
  if (con.get_digital(E_CONTROLLER_DIGITAL_LEFT)) { //lady brown double loading macro
	// Set it into Macro Mode
	LBC = true;
	Macro++;
  
	// Finds the angle that we need to move 
	double current_angle = roto.get_angle() / 100.0;
	double target_angle = 220;
	double change_angle = target_angle - current_angle;
	
	// Finding how far to move the motor
	double motor_ticks = change_angle * 5;
  
	// Move motor to the desired position
	LadyBrown.move_relative(motor_ticks, 90);
  } 

  if (con.get_digital(E_CONTROLLER_DIGITAL_RIGHT)) { //lady brown double loading macro
	// Set it into Macro Mode
	LBC = true;
	Macro++;
  
	// Finds the angle that we need to move 
	double current_angle = roto.get_angle() / 100.0;
	double target_angle = 105;
	double change_angle = target_angle - current_angle;
	
	// Finding how far to move the motor
	double motor_ticks = change_angle * 5;
  
	// Move motor to the desired position
	LadyBrown.move_relative(motor_ticks, 90);
  } 
// if(LBC){
// 	//LadyBrown.move(127);
// 	setConstants(MACRO_KP, MACRO_KI, MACRO_KD);
// 	Macro = 0;
// 	if (Macro == 0){
// 		LadyBrown.move(calcPID(35000, roto.get_angle(), 0, 0));//need to get the right angle optimal angle `
// 	} else if (Macro == 1){
// 		LadyBrown.move(calcPID(31000, roto.get_angle(), 0, 0));
// 	}else {
// 		//LadyBrown.move(0);
		
// 	}
// }
// make conversion variable


//pistons for mogo

if (con.get_digital_new_press(E_CONTROLLER_DIGITAL_X)){
MogoMechToggle = !MogoMechToggle;
}  MogoMech.set_value(MogoMechToggle);

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
double  chasstemp = ((RF.get_temperature() + RB.get_temperature() + LF.get_temperature() + LB.get_temperature())/4);
if (time % 50 == 0 && time % 100 !=0 && time % 150 !=0){
    con.print(0,0,"Time:%f       ", float(time2));//viewTime
} else if (time% 100 == 0 && time % 150 !=0){
    con.print(1,0,"HeadingError!%f      ", float(Macro));
} else if (time % 150 == 0){
    con.print(2,0,"C:%i H:%i LB:%i      ",int(chasstemp), int(Intake.get_temperature()), int(LadyBrown.get_temperature()));
}

delay(10);
time += 10;

}

}
