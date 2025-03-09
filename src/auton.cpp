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
  
    LadyBrown.move_relative(-160, 70);
    delay(150);
    Intake.move(70);
    driveStraight2(1700);
    driveTurn2(-41.5);
    Intake.move(0);
    driveStraight2(1206);
    LadyBrown.move_relative(-520, 90);
    delay(750);
    driveStraightC(-650);
    driveTurn2(-90);
    LadyBrown.move_relative(700, 70);
    driveClampS(-1200, 100, 50);
    Intake.move(127);
    driveTurn2(-45);
    driveStraight2(1050);
    //driveTurn2()
//     driveTurn2(0);
//     driveStraight2(1175);
//     driveTurn2(-25);
//     driveStraightSlow(225, 50);
//     driveTurn2(-42);
//     driveStraight2(210);
//     LadyBrown.move_relative(-510, 127);
//     delay(950);
//     driveStraightC(-250);
//     LadyBrown.move_relative(750, 90);
//     driveTurn2(0);
//     Intake.move(127);
//     driveStraight2(350);
//  //   LadyBrown.set_zero_position(0);
//     delay(200);
//     Intake.move(0);
//     driveTurn2(25);
//     Intake.move(127);
//     LadyBrown.move_relative(120, 90);
//     driveStraight2(100);

   }
 void autons2(){
   //skills
    LadyBrown.move(-127);
    delay(550);
    LadyBrown.move(127);
    delay(450);
    LadyBrown.move(0);
    driveStraight2(-445);
    driveTurn2(89);
    driveStraight2(-660);
    driveTurn2(88);
    driveClampS(-330, 10, 20);
    driveTurn2(-170);
    Intake.move(-100);
    //ErrorFixayer1.move(-127);
    driveStraight2(950);
    delay(500);
    driveTurn2(-90);
    driveStraight2(750);
    delay(500);
    driveTurn2(-135);
    driveStraight2(1000);
    driveStraight2(-600);
    driveTurn2(5);
    driveStraightSlow(1650,50);
    driveTurn2(135);
    MogoMech.set_value(false);
    driveStraight2(-1000);
    delay(1000);
    driveStraight2(500);
  // //  driveAr m n=cRF(90, 750, 1500);
  //  driveStraight2(50);
  //  delay(100);
  //  driveTurn2(-155);
  //  Intake.move(-90);
  //  driveStraight2(700);
  //  delay(500);
  //  driveStraight2(-600);
  //  driveTurn2(0);

  



 }
 void autons3(){
  //blue ring side
 LadyBrown.move(-17);
  delay(50);
  driveTurn2(40);
  driveStraightSlow(350, 100);
   LadyBrown.move(-127);
   delay(650);
   LadyBrown.move(127);
   delay(500);
   LadyBrown.move(0);
   LadyBrown.set_brake_mode(E_MOTOR_BRAKE_HOLD);
   driveStraight2(-1140);
   driveTurn2(-11);
   driveStraightSlow(-800, 60);
   driveTurn2(-5);
   driveClampS(-250, 10, 30);
   //driveStraight2(300);
   driveTurn2(-115);
   Intake.move(-100);
   //ErrorFixayer1.move(-127);
   driveStraight2(680);
   delay(200);
   driveTurn2(-105);
   driveStraight2(300);
   delay(550);
   driveTurn2(-20);
   driveStraight2(500);
   delay(550);
   driveTurn2(100);
   LadyBrown.move(-35);
   driveStraight2(1200);
  //
  //  StakeWing.set_value(true);
  //  delay(400);
  //  driveTurn2(-50);
  //  driveArcRF(100, 400, 1000);
  //  driveStraight2(10);
  //  driveTurn2(120);
  //  StakeWing.set_value(false);
  //  delay(50);
  //  driveTurn2(100);
  //  delay(50);
  // //  Intake.move(-105);
  //  driveStraightSlow(1500, 70);
  //  driveTurn2(-60);
  //  StakeWing.set_value(false);
  //  driveTurn2(-25);
  //  driveStraight2(400);
   //finsihed code!! Don't touch!!
 }
 void autons4(){
   //red goal rush/45% awp
  driveStraightC(100);
  driveTurn2(12);
  driveStraightC(1500);
  driveTurn2(-55);
  driveStraight2(200);
  StakeWing.set_value(true);
  delay(150);
  driveTurn2(-90);
  driveTurn2(-70);
  StakeWing.set_value(false);
  delay(500);
  driveTurn2(-140);
  //ErrorFixayer1.move(-127);
  driveStraightSlow(720, 75);
  delay(100);
  driveTurn2(100);
  delay(50);
  driveStraight2(-737.5);
  driveTurn2(95);
  driveClampS(-580, 10, 20);
  MogoMech.set_value(true);
  delay(100);
  Intake.move(-100);
  //ErrorFixayer1.move(-127);
  delay(700);
  // StakeWing.set_value(true);
  // driveTurn2(-180);
  // //ErrorFixayer1.move(127);
  // driveArcLF(90, 1300, 1500);
  // driveStraight2(10); 
  // driveTurn2(10);
  // driveStraight2(250);
  // StakeWing.set_value(false);
  // driveTurn2(-45);
  // MogoMech.set_value(false);
  // driveStraight2(-500);
  // // driveStraight2(-250);
  // driveTurn2(-45);
  // MogoMech.set_value(false);
  // driveStraight2(-500);


 }
 void autons5(){
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
    Solo_AWP_red();
  } 
  else if (atn ==2) {

  } 
  else if (atn ==3) {

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