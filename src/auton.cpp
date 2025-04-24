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
  LadyBrown.move(-110);
  driveStraight2(225);
  LadyBrown.move(20);
  driveTurn2(3);
  driveStraightC(-400);
  LadyBrown.move(-127);
  LadyBrown.move(90);
  driveStraight2(-900);
  driveTurn2(-10);
  driveClampS(-850, 300, 100);
  driveTurn2(165);
  Intake.move(127);
  color = 1;
  driveStraight2(580);
  //delay(200);
  driveTurn2(60);
  driveStraight2(500);
  driveTurn2(-30);
  driveStraightC(1650);
  MogoMech.set_value(false);
  color = 0;
  Intake.move(127);
  driveArcLF(20, 400, 500, 100);
  driveStraight2(100);
  //driveTurn2(-25);
  Intake.move(127);
  driveSortHoldRed(1100, 50);
  Intake.move(0);
  driveTurn2(37);
  driveStraight2(-900);
  driveClampS(-550, 200, 60);
  Intake.move(127);
  driveTurn2(165);
  LadyBrown.move(-127);
 }
 void Goal_Rush_red(){ 
  // color = 1;//1 = no blue rings, 2 = no red rings
  eyes.set_led_pwm(100);
  StakeWing.set_value(true);
  Intake.move(127);
  driveSortHoldblue(1780, 100);
  Intake.move(0);
  StakeWing.set_value(false);
  driveStraightRush(-1100);
  StakeWing.set_value(true);
  driveStraight2(-300);
  StakeWing.set_value(false);
  Intake.move(30);
  driveTurn2(-197);
  delay(100);
  driveStraight2(-850);
  driveClampS(-500, 225, 80);
  color = 2;
  driveTurn2(-210);
  driveStraight2(2000);
  driveTurn2(20);
  MogoMech.set_value(false);
  driveStraight2(1000);
  driveTurn2(-165);
  driveClampS(-1050, 50, 70);
  driveTurn2(-90);
  // driveStraight2(1000);
  // StakeWing.set_value(true);
  // driveStraightC(-500);
  // MogoMech.set_value(false);
  // color = 2;
  // driveStraight2(500);


  // delay(100);
  // color = 0; 
  // MogoMech.set_value(false);
  // driveArcLF(90, 200, 750, 100);
  // driveSortHoldblue(1000, 100);
  // // driveArcLF(90, 100, 750, 100);
  // driveTurn2(225);
  // driveStraightC(-450);
  // driveArcRF(-90, 500, 1500, 100);
  // driveStraight2(-1000);


  // driveArcRF(42, 375, 950, 100);
  // StakeWing.set_value(false);
  // driveStraightC(10);
  //   // driveStraightC(10);
  // driveStraightC(-300);
  // driveTurn2(0);
  // driveStraightC(-450);
  // StakeWing.set_value(true); 
  // driveStraight2(-850);
  // StakeWing.set_value(false);
  // driveTurn2(-112);
  // driveStraightC(-950); //good
  // driveTurn2(-115);
  // driveClampS(-900, 450, 100);
  // driveTurn2(47);
  // driveStraight2(750); //tune 
  // StakeWing.set_value(true);
  // driveStraightC(-1600);
  // StakeWing.set_value(false);
  // driveStraight2(-400);
  // color = 2;
  // driveStraightC(50);
  // driveArcLF(135, 250, 750, 100);
  // driveStraightC(500);
  // driveTurn2(-185);
  // driveStraight2(2150);

 }

 void goal_safe_side_red(){ //not tested 
  //driveTurn2(10);
  driveStraight2(-1200);
  driveClampS(-700, 90, 50);
  driveTurn2(100);
  driveStraight2(750);
  driveTurn2(165);
  StakeWing.set_value(true);
  delay(250);
  driveTurn2(110);
  // driveStraight2(-2000);
  // StakeWing.set_value(false);
  // color = 2;
  // driveStraight2(-250);
  // driveTurn2(-100);
  // driveArcRF(170, 300, 1000, 100);
  // driveStraight2(800);
  // delay(100);
  // driveTurn2(140);
  // driveStraightC(-1000);
  // MogoMech.set_value(false);
  // driveStraightC(-1000);
  // driveStraight2(2100);
  // driveTurn2(10);
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
  driveTurn2(10);
  driveClampS(-850, 300, 100);
  driveTurn2(-160);
  color = 2;
  //color = 1;
  driveStraight2(590);
  //delay(200);
  driveTurn2(-60);
  driveStraight2(500);
  driveTurn2(25);
  driveStraightC(1650);
  MogoMech.set_value(false);
  Intake.move(127);
  driveArcRF(15, 400, 1000, 100);
  driveStraight2(100);
  // //driveTurn2(-25);
  color = 0;
  Intake.move(127);
  driveSortHoldblue(1100, 50);
  Intake.move(0);
  driveTurn2(-45);
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
  driveStraightC(50);
  Intake.move(35);
  driveStraightRush(-1070);
  StakeWing.set_value(true);
  driveStraight2(-500);
  StakeWing.set_value(false);
  driveTurn2(175);
  delay(100);
  driveStraight2(-900);
  driveClampS(-500, 225, 80);
  color = 2;
  driveTurn2(150);
  driveStraight2(2000);
  driveTurn2(20);
  MogoMech.set_value(false);
  driveStraight2(1000);
  driveTurn2(-175);
  driveClampS(-1100, 50, 70);
  driveTurn2(-160);
 }

//blue ring side touch bar bc not doing corner stack
 void goal_safe_side_blue(){
  //driveTurn2(10);
  driveStraight2(-1300);
  driveClampS(-600, 90, 50);
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
  driveTurn2(-140);
  driveStraightC(-1000);
  MogoMech.set_value(false);
  driveStraightC(-1000);
  driveStraight2(2100);
  driveTurn2(-10);
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

  }
}