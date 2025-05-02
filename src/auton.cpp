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


 void Standard_AWP_red(){//1 = no blue rings, 2 = no red rings
  eyes.set_led_pwm(100); //always do this
  LadyBrown.move(-110);
  driveStraight2(225);
  LadyBrown.move(20);
  driveTurn2(3);
  driveStraightC(-400);
  LadyBrown.move(-127);
  LadyBrown.move(90);
  driveStraight2(-900);
  //driveTurn2(-10);
  driveClampS(-850, 300, 100);
  driveTurn2(165);
  Intake.move(127);
  color = 1;
  driveStraight2(650);
  //delay(200);
  driveTurn2(60);
  driveStraight2(500);
  driveTurn2(-30);
  driveStraightC(1700);
  MogoMech.set_value(false);
  color = 0;
  Intake.move(127);
  driveArcLF(15, 400, 500, 100);
  driveStraight2(100);
  //driveTurn2(-25);
  Intake.move(127);
  driveSortHoldRed(1100, 45);
  Intake.move(0);
  driveTurn2(15);
  driveStraight2(-950);
  driveClampS(-550, 200, 60);
  Intake.move(127);
  driveTurn2(165);
  LadyBrown.move(-127);
  driveStraight2(75);
 }
 void Goal_Rush_red(){ 
  // color = 1;//1 = no blue rings, 2 = no red rings
  eyes.set_led_pwm(100);
  StakeWing.set_value(true);
  Intake.move(127);
  driveSortHoldRedC(2000, 100);
  StakeWing.set_value(false);
  driveStraightC(100);
  Intake.move(27);
  driveStraightRush(-995);
  StakeWing.set_value(true);
  driveStraight2(-600);
  StakeWing.set_value(false);
  driveTurn2(169);
  driveStraight2(-900);
  driveClampS(-500, 200, 90);
  color = 1;
  driveTurn2(-175);
  driveStraightC(1600);
  driveStraight2(400);
  driveTurn2(-11);
  MogoMech.set_value(false);
  driveStraight2(500);
  driveTurn2(155);
  driveClampS(-1100, 200, 65);
  driveTurn2(115);
  driveStraight2(1500);
  // driveStraightC(2900);
  // driveStraight2(100); these don't work. Trouble shoot later
 }

 void Ring_Rush_red(){ 
  // color = 1;//1 = no blue rings, 2 = no red rings
  eyes.set_led_pwm(100);
  driveStraight2(-1200);
  driveClampS(-700, 400, 100);
  color = 1;
  driveTurn2(140);
  driveStraight2(700);
  driveTurn2(150);
  driveStraight2(-15);
  delay(100);
  StakeWing.set_value(true);
  driveStraight2(-1485);
  StakeWing.set_value(false);
  driveArcLF(30, 200, 7500, 100);
  driveStraightC(1000);
  driveTurn2(-45);
  driveStraightC(1750);
  driveTurn2(-75);
  MogoMech.set_value(false);
  color = 0;
  driveSortHoldRed(1000, 75);
  Intake.move(0);
  LadyBrown.move_relative(-185, 127);
  driveTurn2(55);
  Intake.move(0);
  driveStraight2(550);
  Intake.move(127);
  delay(500);
  Intake.move(0);
  LadyBrown.move(-127);
  delay(400);
  LadyBrown.move(45);
  //driveArcRF(-45, 500, 1500, 100);
  driveStraightC(-250);
  driveTurn2(10);
  LadyBrown.move_relative(-300, 127);
  driveStraight2(-2200);

  }

 void goal_safe_side_red(){ //not tested 
  //driveTurn2(10);
  driveStraight2(-1200);
  driveClampS(-700, 300, 85);
  driveTurn2(30);
  color = 1;
  driveStraight2(1300);
  StakeWing.set_value(true);
  driveStraightC(-900);
  driveTurn2(-60);
  StakeWing.set_value(false);
  delay(100);
  driveArcLF(75, 200, 750, 100);
  driveStraight2(10);
  driveStraight2(600);
  driveTurn2(-40);
  StakeWing.set_value(true);
  driveStraight2(1650);
  driveTurn2(60);
  driveArcRF(95, 600, 1500, 100);
  MogoMech.set_value(false);
  driveStraightC(750);
  driveTurn2(20);
  }


 void Standard_AWP_blue(){
  eyes.set_led_pwm(100); //always do this
  LadyBrown.move(-110);
  driveStraight2(250);
  LadyBrown.move(20);
  driveTurn2(-3);
  driveStraightC(-400);
  LadyBrown.move(90);
  driveStraight2(-900);
  // driveTurn2(10);
  driveClampS(-850, 300, 100);
  driveTurn2(-160);
  color = 2;
  //color = 1;
  driveStraight2(675);
  //delay(200);
  driveTurn2(-60);
  driveStraight2(600);
  driveTurn2(25);
  driveStraightC(1600);
  MogoMech.set_value(false);
  Intake.move(127);
  driveArcRF(15, 400, 1000, 100);
  driveStraight2(100);
  // //driveTurn2(-25);
  color = 0;
  Intake.move(127);
  driveSortHoldblue(1100, 50);
  Intake.move(0);
  driveTurn2(-30);
  driveStraight2(-1100);
  driveClampS(-550, 200, 60);
  Intake.move(127);
  driveTurn2(-165);
  LadyBrown.move(-127);
  }


 void Goal_Rush_Blue(){ // need to fix color sensor and goal tip side because of no double doinkers!!
  //blue goal rush
  eyes.set_led_pwm(100);
  StakeWing.set_value(true);
  Intake.move(127);
  driveSortHoldblueC(2000, 100);
  StakeWing.set_value(false);
  driveStraightC(55);
  Intake.move(27);
  driveStraightRush(-1070);
  StakeWing.set_value(true);
  driveStraight2(-500);
  StakeWing.set_value(false);
  driveTurn2(168);
  driveStraight2(-900);
  driveClampS(-500, 200, 90);
  color = 2;
  driveStraight2(-100);
  driveTurn2(150);
  driveStraightC(1900);
  MogoMech.set_value(false);
  driveStraight2(100);
  driveTurn2(20);
  driveStraight2(1000);
  driveTurn2(-171);
  driveClampS(-1100, 400, 90);
  driveTurn2(-170);
  driveStraightC(1500);
  StakeWing.set_value(true);
  driveArcRF(45, 380, 1000, 100);
  driveStraight2(400);

 }

//blue ring side touch bar bc not doing corner stack
 void goal_safe_side_blue(){
  //driveTurn2(10);
  driveStraight2(-1200);
  driveClampS(-700, 300, 85);
  driveTurn2(-100);
  driveStraight2(750);
  driveTurn2(-110);
  StakeWing.set_value(true);
  delay(250);
  driveStraight2(-2000);
  StakeWing.set_value(false);
  color = 2;
  driveStraight2(-250);
  driveTurn2(-100);
  driveArcLF(170, 300, 1000, 100);
  driveStraight2(800);
  delay(100);
  driveTurn2(20);
  driveStraightC(1000);
  StakeWing.set_value(true);
  //driveStraight2(400);
  driveArcRF(90, 200, 1000, 100);
  driveStraight2(50);
  // driveSortHoldblue(2100, 100);
  driveTurn2(-100);
  StakeWing.set_value(false);
  driveStraight2(250);
  driveArcLF(75, 600, 1000, 100);
  MogoMech.set_value(false);
  driveStraightC(500);
  driveTurn2(-20);
  }

  void Ring_Rush_blue(){ 
    // color = 1;//1 = no blue rings, 2 = no red rings
    eyes.set_led_pwm(100);
    driveStraight2(-1200);
    driveClampS(-700, 400, 85);
    color = 2;
    driveTurn2(-140);
    driveStraight2(700);
    driveTurn2(-120);
    driveStraight2(400);
    delay(200);
    driveStraightC(-400);
    driveTurn2(-150);
    driveStraight2(-1385);
    driveArcRF(30, 250, 7500, 100);
    driveStraightC(1000);
    driveTurn2(45);
    driveStraight2(1950);
    MogoMech.set_value(false);
    color = 0;
    Intake.move(127);
    driveSortHoldblue(1000, 70);
    Intake.move(0);
    LadyBrown.move_relative(-185, 127);
    driveTurn2(-67);
    Intake.move(0);
    driveStraight2(450);
    Intake.move(127);
    delay(500);
    Intake.move(0);
    LadyBrown.move(-127);
    delay(400);
    LadyBrown.move(45);
    driveStraightC(-250);
    driveTurn2(-10);
    LadyBrown.move_relative(-300, 127);
    driveStraight2(-2200);
   }
 
 void skill_run(){
  LadyBrown.move_relative(-850, 127);
  delay(700);
  LadyBrown.move(127);
  delay(200);
  driveStraight2(-475);
  driveTurn2(90);
  driveStraight2(-700);
  driveClampS(-400, 200, 50);
  driveTurn2(180);
  color = 1;
  driveStraightC(400);
  driveArcRF(25, 400, 1000, 100);
  driveStraightC(1000);
  driveArcLF(10, 400, 1000, 100);
  driveStraightC(1000);
  driveArcRF(5, 400, 1000, 100);
  color = 0;
  Intake.move(127);
  driveStraight2(1500);
  LadyBrown.move_relative(-250, 127);
  driveStraightC(-1000);
  color = 0;
  driveStraight2(-1050);
  // color = 0;
  driveTurn2(-90);
  color = 1;
  delay(100);
  color = 0;
  Intake.move(0);
  LadyBrown.move_relative(-300, 127);
  delay(500);
  Intake.move(127);
  driveSortHoldRed(460, 50);
  Intake.move(0);
  LadyBrown.move_relative(-550, 70);
  delay(500);
  Intake.move(45);
  driveStraightSlow(-600, 50);
  LadyBrown.move_relative(1200, 127);
  delay(700);
  Intake.move(127);
  driveStraightSlow(600, 75);
 }
 
 void autonomous(){
  if (atn == 0) {
  }else if (atn == 0) {
    driveStraight2(25);
  }
   else if (atn == 1) {
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
    goal_safe_side_blue();
  } 
  else if (atn ==6) {
    goal_safe_side_red();
  } 
  else if (atn ==7) {
    Ring_Rush_red();
  }
  else if (atn ==8) {
    Ring_Rush_blue();
  }
  else if (atn ==9) {
    skill_run();
  }
}