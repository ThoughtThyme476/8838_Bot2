#include "main.h"
#include "api.h"
#include "pid.h"
#include "robot.h"
#include "auton.h"
 using namespace pros;



// auton1=red side ring side
// auton2=blue side ring side
// auton3= red side elims goal side
// autons4= blue side elims goal side
// autons5 = auto skills

 //don't use autons 1 and that stuff anymore just use the above 

 void Standard_AWP_red(){
  //1 = no blue rings, 2 = no red rings
  eyes.set_led_pwm(100); //always do this
  LadyBrown.move(-110);
  driveStraight2(225);
  LadyBrown.move(20);
  driveStraightC(-400);
  LadyBrown.move(90);
  driveStraight2(-900);
  driveTurn2(5);
  ColorSort();
  driveClampS(-850, 300, 100);
  driveTurn2(165);
  Intake.move(127);
  //color = 1;
  driveStraight2(580);
  //delay(200);
  driveTurn2(60);
  driveStraight2(500);
  driveTurn2(-30);
  driveStraightC(1650);
  MogoMech.set_value(false);
  Intake.move(127);
  driveArcLF(20, 400, 500, 100);
  driveStraight2(100);
  //driveTurn2(-25);
  driveSortHoldRed(1100, 50);
  Intake.move(0);
  driveTurn2(37);
  driveStraight2(-900);
  driveClampS(-550, 200, 60);
  Intake.move(127);
  driveTurn2(165);
  LadyBrown.move(-90);
 }
 void Goal_Rush_red(){ // power beans goal rush kinda. Did this saturday night/sunday moring durning states 
  // color = 1;//1 = no blue rings, 2 = no red rings
  eyes.set_led_pwm(100);
  Intake.move(127);
  driveStraight2(1500);
  Intake.move(100);
  driveSortHoldRed(1000, 100);
  StakeWing.set_value(true);
  delay(100);
  Intake_Piston.set_value(true);
  driveTurn2(110);
  StakeWing.set_value(false);
  driveTurn2(70);
  driveStraight2(-450);
  driveClampS(-200, 50, 50);
  delay(100);
  Intake.move(127);
  driveStraightC(600);
  driveTurn2(-180);
  Intake_Piston.set_value(false);
  driveStraight2(2000);
 // color = 1;
  driveStraightSlow(300, 50);
  delay(500);
  driveStraight2(-500);
  driveTurn2(-42.5);
  driveStraight2(-1000);

 }
 void Standard_AWP_blue(){
   //1 = no blue rings, 2 = no red rings
   eyes.set_led_pwm(100); //always do this
   LadyBrown.move(-110);
   driveStraight2(200);
   LadyBrown.move(20);
   driveStraightC(-400);
   LadyBrown.move(90);
   driveStraight2(-900);
   //driveTurn2(0);
   ColorSort();
   driveClampS(-850, 300, 100);
   driveTurn2(-165);
   Intake.move(127);
   //color = 1;
   driveStraight2(610);
   //delay(200);
   driveTurn2(-60);
   driveStraight2(500);
   driveTurn2(10);
   driveStraightC(1850);
   MogoMech.set_value(false);
   Intake.move(127);
   driveArcRF(20, 400, 500, 100);
   driveStraight2(100);
   //driveTurn2(-25);
   driveSortHoldblue(1200, 50);
  //  Intake.move(0);
  //  driveTurn2(-35);
  //  driveStraight2(-900);
  //  driveClampS(-550, 200, 60);
  //  Intake.move(127);
  //  driveTurn2(-165);
  //  LadyBrown.move(-90);
  }


 void Goal_Rush_Blue(){ // need to fix color sensor and goal tip side because of no double doinkers!!
  //blue goal rush
  eyes.set_led_pwm(100);
  Intake.move(127);
  driveStraight2(1650);
  Intake.move(0);
  driveStraightSlow(850, 100);
  StakeWing.set_value(true);
  delay(100);
  Intake_Piston.set_value(true);
  driveTurn2(110);
  StakeWing.set_value(false);
  driveTurn2(-70);
  driveStraight2(-600);
  driveClampS(-800, 50, 50);
  delay(100);
  Intake.move(127);
  driveStraightC(600);
  driveTurn2(165);
  Intake_Piston.set_value(false);
  driveStraight2(2000);
 // color = 1;
  driveStraightSlow(300, 50);
  delay(500);
  driveStraight2(-500);
  driveTurn2(45);
  driveStraight2(-1000);
 }

//blue ring side touch bar bc not doing corner stack
 void autons6(){
 //blue ring side
   LadyBrown.move(-17);
   delay(50);
   driveTurn2(39);
   driveStraight2(360);
   LadyBrown.move(-127);
   delay(650);
   LadyBrown.move(127);
   delay(300);
   LadyBrown.move(0);
   driveStraight2(-1150);
   driveTurn2(-11);
   driveClampS(-1250, 100, 50);
   driveStraight2(500);
   driveTurn2(-90);
   Intake.move(-90);
   //ErrorFixayer1.move(-127);
   driveStraight2(900);
   delay(400);
   driveTurn2(-180);
   driveStraight2(470);
   driveTurn2(-115);
   driveStraight2(100);
   delay(150);
   driveTurn2(80);
   driveStraight2(1111);
  }
 
 void skill_run(){
  LadyBrown.move_relative(-900, 127);
  delay(400);
  driveStraight2(-500);
  driveTurn2(90);
  driveClampS(-1100, 50, 50);
  driveTurn2(-90);
  Intake.move(127);
  LadyBrown.move_relative(400, 127);
  driveStraight2(1800);
  driveTurn2(-200);
  MogoMech.set_value(true);
  driveStraight2(-1000);
  delay(100);
  driveStraight2(500);
 }
 
 void autonomous(){
  if (atn == 0) {
  } else if (atn == 1) {
    // color = 1;
  Standard_AWP_red();
  } 
  else if (atn ==2) {
  Standard_AWP_blue();
  } 
  else if (atn ==3) {
    Goal_Rush_red();
  } 
  else if (atn ==4) {
    Goal_Rush_Blue();
  } 
  else if (atn ==5) {
    skill_run();
  } 
  else if (atn ==6) {

  } 
  else if (atn ==7) {
    eyes.set_led_pwm(100);
    Intake.move(127);
    driveSortHoldRed(750, 25);
  }
}