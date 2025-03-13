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
 void Standard_AWP_red(){
  color == 1;//1 = no blue rings, 2 = no red rings
  eyes.set_led_pwm(100); //always do this
  LadyBrown.move_relative(-900, 127);
  delay(700);
  driveStraightC(-550);
  driveTurn2(70);
  driveStraight2(-870);
  driveClampS(-620, 25, 100); //grabs goal
  driveTurn2(-215);
  Intake.move(127);
  driveStraightC(500);
  driveTurn2(260);
  //driveArcRF(140, 200, 1500, 50);
  driveStraightC(400);
  driveTurn2(235);
  driveStraight2(400);
  delay(250);
  driveTurn2(220);
      // StakeWing.set_value(true);
      // delay(20);
      // driveStraight2(-750);
      // StakeWing.set_value(false);
      // driveArcRF(120, 200, 500, 55);
      // driveStraight2(200);
      // delay(250);
      // Intake_Piston.set_value(true);
      // driveStraight2(2000);
      // MogoMech.set_value(false);
      // LadyBrown.move_relative(600, 127);
      // driveTurn2(10); //might need this. Its been sometimes needing this and sometimes not
      // driveSortHoldblue(455, 100);
      // Intake_Piston.set_value(false);
      // delay(150);
      // driveTurn2(-125);
      //driveStraight2(500);
      //LadyBrown.move_relative(-825, 127);
 }
 void Goal_Rush_red(){ // power beans goal rush 
  LadyBrown.move_relative(-240, 70);
  //driveTurn2(-10);
  Intake.move(127);
  driveStraightC(1000);
  driveSortHoldRed(1300, 100);
  // LadyBrown.move_relative(-700, 127);
  StakeWing.set_value(true);
  delay(100);
  driveStraight2(-1000);
  StakeWing.set_value(true);

  //driveTurn2(45);
 }
 void Standard_AWP_blue(){
  color == 2;
  eyes.set_led_pwm(100);
  LadyBrown.move_relative(-900, 127);
  delay(700);
  driveStraightC(-550);
  driveTurn2(-72);
  driveStraight2(-870);
  driveClampS(-600, 25, 100);
  driveTurn2(215);
  Intake.move(127);
  driveStraightC(550);
  driveArcLF(105, 200, 1500, 60);
  driveStraight2(720);
  //delay(250);
  driveTurn2(-245);
  StakeWing.set_value(true);
  delay(20);
  driveStraight2(-750);
  //driveTurn2(20);
  StakeWing.set_value(false);
  driveArcLF(120, 200, 500, 55);
  driveStraight2(200);
  delay(250);
  Intake_Piston.set_value(true);
  driveStraight2(2000);
  MogoMech.set_value(false);
  LadyBrown.move_relative(600, 127);
  driveTurn2(-10); //might need this. Its been sometimes needing this and sometimes not
  driveSortHoldblue(455, 100);
  Intake_Piston.set_value(false);
  delay(150);
  driveTurn2(125);
  // driveArcRF(200, 220, 1200, 75);
    // Intake.move(0);
    driveStraight2(500);
    LadyBrown.move_relative(-825, 127);
    // 
    // LadyBrown.move_relative(-825, 127);
  //driveClampS(500, 25, 75);;

      // driveStraightC(750);
      // driveTurn2(-238);
      // delay(100);
      // driveStraight2(750);
//   delay(250);
//   driveTurn2(0);
//   driveStraight2(2300);
//   MogoMech.set_value(true);
//   Intake_Piston.set_value(true);
//   driveSortHoldblue(600, 75);
//   Intake_Piston.set_value(false);
//   Intake.move(0);
//   LadyBrown.move_relative(880, 127);
//   delay(100);
//   driveTurn2(85);
//   Intake.move(127);
//   driveStraight2(1000);
//   Intake.move(0);
//   LadyBrown.move_relative(-900, 127);
  }


 void stand(){
  //blue goal rush
 driveStraightC(100);
 driveTurn2(-11);
 driveStraightC(1400);
 driveTurn2(40);
 driveStraight2(450);
 StakeWing.set_value(true);
 driveTurn2(-50);
 driveTurn2(-40);
 StakeWing.set_value(false);
 delay(100);
 driveTurn2(-95);
 driveStraightSlow(-760, 50);
 driveTurn2(-135);
 //ErrorFixayer1.move(-127);
 driveStraight2(600);
 driveTurn2(-81);
 driveClampS(-1100, 20, 40); 
 Intake.move(-100);
 delay(1000);
 driveTurn2(-135);
 Intake.move(0);
 delay(500);
 StakeWing.set_value(true);
 driveStraight2(2300);
 driveTurn2(-150);
 delay(100);
 driveTurn2(-180);
 StakeWing.set_value(false);
//  delay(100);
//  driveStraight2(250);
//  MogoMech.set_value(true);
//  driveTurn2(-85);
//  //ErrorFixayer1.move(-127);
//  Intake.move(-90);
//  driveStraight2(750);
//  delay(500);
//  driveTurn2(30);
//  MogoMech.set_value(false);
//  driveStraight2(-500);
//  driveTurn2(0);
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
 
 void autons7(){
  // MogoMech.set_value(true);
  // pros::Task colorSortTask([]() {
  //       ColorSort(1); // 1 for red, 2 for blue
  //   });
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

  } 
  else if (atn ==5) {

  } 
  else if (atn ==6) {

  } 
  else if (atn ==7) {

  }
}