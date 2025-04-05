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
 void Solo_AWP_red(){
  // driveStraight2(3000);
        LadyBrown.move_relative(-160, 70);
        delay(150);
        Intake.move(70);
        driveStraight2(1400);
        driveStraightSlow(300, 50);
        driveTurn2(-42);
        Intake.move(0);
        driveStraight2(1210);
        LadyBrown.move_relative(-520, 90);
        delay(750);
        driveStraightC(-400);
        LadyBrown.move_relative(670, 70);
        driveTurn2(0);
        Intake.move(127);
        driveStraight2(440);
        delay(100);
        Intake.move(-10);
        delay(100);
        LadyBrown.move_relative(-300, 50);
        Intake.move(0);
        delay(500);
        Intake.move(127);
        driveStraight2(30);
        delay(250);
        driveStraightC(-500);
        Intake.move(0);
        driveTurn2(-100);
        driveStraight2(-1000);
        driveClampS(-275, 25, 25);
        Intake.move(127);
        driveStraightC(400);
        driveTurn2(0);
        driveStraight2(1000);
    // LadyBrown.move_relative(750, 70);
    // driveStraightSlow(-1000, 75);
    // driveClampS(-200, 50, 50);
    // delay(10);
    // Intake.move(127);
    // driveStraightC(600);
    // driveTurn2(0);
          // //driveArcRF(90, 500, 1000, 100);
          // driveStraight2(700);
          // delay(100);
          // driveStraightC(-700);
          // driveTurn2(55);
          // driveStraight2(1500);
          // StakeWing.set_value(true);
   }
 void Standard_AWP_red(){//1 = no blue rings, 2 = no red rings
  eyes.set_led_pwm(100); //always do this
  color = 1;
  LadyBrown.move(-127);
  driveStraight2(650);
  LadyBrown.move(90);
  driveClamp(-2800, 50);

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
  driveStraight2(-600);
  driveClampS(-800, 50, 50);
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
  driveTurn2(-45);
  driveStraight2(-1000);

 }
 void Standard_AWP_blue(){
  eyes.set_led_pwm(100);
 // color = 2;
  LadyBrown.move_relative(-900, 127);
  driveStraight2(50);
  Intake.move(127);
  delay(500);
  driveStraightC(-600);
  driveTurn2(-70);
  driveStraight2(-870);
  driveClampS(-600, 25, 50);
  driveTurn2(215);
  Intake.move(127);
  driveStraight2(800);
  delay(500);
  LadyBrown.move_relative(600, 127);
  driveTurn2(3);
  Intake_Piston.set_value(true); //might need this. Its been sometimes needing this and sometimes not
  driveStraight2(2000);
  driveTurn2(10);
  driveStraightSlow(250, 50);
  Intake_Piston.set_value(false);
  delay(150);
  driveTurn2(135);
  // driveArcRF(200, 220, 1200, 75);
    Intake.move(127);
    delay(250);
    Intake.move(0);
    driveSortHoldRed(1000, 100);
    LadyBrown.move_relative(-825, 127);
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
    Standard_AWP_red();
  } 
  else if (atn ==2) {
    color = 1;
    ColorSort();
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

  }
}