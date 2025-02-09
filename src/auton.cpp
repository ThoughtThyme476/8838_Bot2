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
void auton(){
  driveStraight2(1000);
  driveTurn2(90);
}
 
 void autons1(){
  //red ring side
   Redirect.move(-17);
  delay(50);
  driveTurn2(-40);
  driveStraightSlow(350, 100);
   Redirect.move(-127);
   delay(650);
   Redirect.move(127);
   delay(500);
   Redirect.move(0);
   Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
   driveStraight2(-1140);
   driveTurn2(11);
   driveStraightSlow(-800, 60);
   driveTurn2(5);
   driveClampS(-250, 10, 30);
   driveTurn2(120);
   Intake.move(-100);
   Intake_Layer1.move(-127);
   driveStraight2(680);
   delay(200);
   driveTurn2(110);
   driveStraight2(375);
   delay(600);
   driveTurn2(20);
   driveStraight2(500);
   delay(500);
   driveTurn2(-100);
   Redirect.move(-50);
   driveStraight2(1200);
  // Redirect.move(-17);
  // delay(50);
  // driveTurn2(-40);
  // driveStraightSlow(350, 100);
  //  Redirect.move(-127);
  //  delay(650);
  //  Redirect.move(127);
  //  delay(500);
  //  Redirect.move(0);
  //  Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  //  driveStraight2(-1140);
  //  driveTurn2(11);
  //  driveStraightSlow(-800, 60);
  //  driveTurn2(5);
  //  driveClampS(-250, 10, 30);
  //  delay(200);
  //  driveTurn2(125);
  //  Intake.move(-100);
  //  Intake_Layer1.move(-127);
  //  driveStraightSlow(740, 50);
  //  driveTurn2(105);
  //  driveStraightSlow(300, 75);
  //  driveTurn2(10);
  //  driveStraightSlow(700, 60);
  //  delay(500);
  //  driveTurn2(-120);
  //  driveStraight2(1000);
   //finsihed code!! Don't touch!!
   }
 void autons2(){
   //skills
    Redirect.move(-127);
    delay(550);
    Redirect.move(127);
    delay(450);
    Redirect.move(0);
    driveStraight2(-445);
    driveTurn2(89);
    driveStraight2(-660);
    driveTurn2(88);
    driveClampS(-330, 10, 20);
    driveTurn2(-170);
    Intake.move(-100);
    Intake_Layer1.move(-127);
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
 Redirect.move(-17);
  delay(50);
  driveTurn2(40);
  driveStraightSlow(350, 100);
   Redirect.move(-127);
   delay(650);
   Redirect.move(127);
   delay(500);
   Redirect.move(0);
   Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
   driveStraight2(-1140);
   driveTurn2(-11);
   driveStraightSlow(-800, 60);
   driveTurn2(-5);
   driveClampS(-250, 10, 30);
   //driveStraight2(300);
   driveTurn2(-115);
   Intake.move(-100);
   Intake_Layer1.move(-127);
   driveStraight2(680);
   delay(200);
   driveTurn2(-105);
   driveStraight2(300);
   delay(550);
   driveTurn2(-20);
   driveStraight2(500);
   delay(550);
   driveTurn2(100);
   Redirect.move(-35);
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
  Intake_Layer1.move(-127);
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
  Intake_Layer1.move(-127);
  delay(700);
  // StakeWing.set_value(true);
  // driveTurn2(-180);
  // Intake_Layer1.move(127);
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
 Intake_Layer1.move(-127);
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
//  Intake_Layer1.move(-127);
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
   Redirect.move(-17);
   delay(50);
   driveTurn2(39);
   driveStraight2(360);
   Redirect.move(-127);
   delay(650);
   Redirect.move(127);
   delay(300);
   Redirect.move(0);
   driveStraight2(-1150);
   driveTurn2(-11);
   driveClampS(-1250, 100, 50);
   driveStraight2(500);
   driveTurn2(-90);
   Intake.move(-90);
   Intake_Layer1.move(-127);
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
 
// // driveStraight(1600);
// // driveTurn(15);
// // delay(50);
// // driveSlow(300, 100);
// // StakeWing.set_value(true);
// // //goal grab
// // delay(50);
// // driveSlow(-1000, 50);
// // StakeWing.set_value(false);
// // driveTurn(120);
// // delay(50);
// // driveTurn(72.5);
// // // driveClampSlow(-00, 10, 60);
// // driveStraight(-950);
// // delay(50);
// // //goal clamp
// // justIntake(1);
// // // first ring 
// // driveTurn(-55);
// // MogoMech.set_value(true);
// // ColorSenseIntakeRed(127);




// // StakeWing.set_value(false);
// // Redirect.move(-127);
// // delay(410);
// // Redirect.move(127);
// // delay(300);
// // Redirect.move(0);
// // Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// // driveTurn(30);
// // driveClampSlow(-950, 25, 50);
// // driveStraight2(75);
// // Redirect.move(127);
// // delay(200);
// // Redirect.move(0); //alliance stake code & mogo
// // //driveArcL(-95, 200, 1000);
// // MogoMech.set_value(true);
// // driveTurn(125);
// // Intake.move(-90);
// // Intake_Layer1.move(-127);
// // driveStraight2(900);
// // delay(50);
// // driveTurn(75);
// // driveStraight2(825);
// // driveTurn(-45);
// // driveStraight2(815);
// // driveTurn(-55);
// // driveStraight2(915);
// // delay(50);
// // //RingHold(-95, false); 
// // Intake.move(-45);
// // driveSlow(-850, 75);
// // delay(300);
// // Intake.move(0);
// // driveTurn(85);
// // Redirect.move(-127);
// // delay(410);
// // Redirect.move(127);
// // delay(300);
// // Redirect.move(0);


// //ring side auton red
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveTurn(-35);
// driveSlow(280, 15);
// Redirect.move(-127);
// delay(600);
// Redirect.move(127);
// delay(350);
// Redirect.move(0);
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveTurn(10.5);
// // driveTurn(-10);
// driveClampSlow(-1780, 40, 50);
// driveStraight2(100);
// Redirect.move(127);
// delay(200);
// Redirect.move(0);
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveTurn(150);
// driveTurn(14);
// Intake.move(-80);
// Intake_Layer1.move(-127);
// driveStraight2(750); // first ring 
// driveTurn(-26);
// driveSlow(350, 20);
// delay(50); //second ring
// driveTurn(-100);
// driveSlow(600, 50);
// Intake.move(-95);
// delay(90);
// // Intake.move(0);
// // Intake_Layer1.move(0);
// // ColorSenseIntakeRed(-80);//third ring 
// driveTurn(-115);
// driveStraight2(1000);
// Redirect.move(-127);//touches ladder




// //red side ring side 
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveTurn(-35);
// driveSlow(300, 15);
// Redirect.move(-127);
// delay(450);
// Redirect.move(127);
// delay(350);
// Redirect.move(0);
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveStraight2(-525);
// driveTurn(-60);
// Redirect.move(127);
// delay(200);
// Redirect.move(0);
//     Intake.move(-80);
//     Intake_Layer1.move(-127);
//     driveSlow(700, 25);  
//     bool color = true;
//     while(color){
// if(eyes.get_hue()<25){
//     Intake.move(0);
//     Intake_Layer1.move(0);
//     break;
// }

// driveSlow(-600, 70);
// driveTurn(85);
// driveClampSlow(-1550, 20, 65);
// driveStraight2(100);
// driveTurn(110);
// Intake.move(-90);
// Intake_Layer1.move(-127);
// delay(300);
// driveStraight2(775);
// Intake.move(-100);
// delay(600);
// driveTurn(160);
// driveSlow(900, 100);
// Redirect.move(-127);


// /*
// driveSlow(1875, 50); // speed up later 
// driveTurn(-45);
// // driveStraight2(150);
// StakeWing.set_value(true);
// delay(500);
// driveTurn(-80);
// StakeWing.set_value(false);
// Intake_Layer1.move(-127);
// driveStraight2(400);
// driveTurn(-120);
// //blue side ring side    
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveTurn(35);
// driveSlow(300, 15);
// Redirect.move(-127);
// delay(450);
// Redirect.move(127);
// delay(350);
// Redirect.move(0);
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveStraight2(-525);
// driveTurn(60);
// Redirect.move(127);
// delay(200);
// Redirect.move(0);
//     Intake.move(-80);
//     Intake_Layer1.move(-127);
//     driveSlow(700, 25);  
//     bool color = true;
//     while(color){
// if(eyes.get_hue()<25){
//     Intake.move(0);
//     Intake_Layer1.move(0);
//     break;

    
// driveSlow(-600, 70);
// driveTurn(-85);
// driveClampSlow(-1550, 20, 65);
// driveStraight2(100);
// driveTurn(-110);
// Intake.move(-90);
// Intake_Layer1.move(-127);
// delay(300);
// driveStraight2(775);
// Intake.move(-100);
// delay(600);
// driveTurn(-160);
// driveSlow(900, 100);
// Redirect.move(-127);

// /*
// void () {
// driveSlow(1875, 50); // speed up later 
// driveTurn(-45);
// // driveStraight2(150);
// StakeWing.set_value(true);
// delay(500);
// driveTurn(-80);
// StakeWing.set_value(false);
// Intake_Layer1.move(-127);
// driveStraight2(400);
// driveTurn(-120);
// // work in progress
       

// void arc(){
// Redirect.move(-127);
// delay(600);
// Redirect.move(127);
// delay(300);
// Redirect.move(0);
// driveStraight2(-450);
// driveTurn(89);
// driveClampSlow(-1200, 30, 25);
// driveSlow(200, 50);
// delay(200);
// driveTurn(91);
// Intake.move(-95);
// Intake_Layer1.move(-127);
// Redirect.move(10);
// // StakeWing.set_value(true);
// imu.tare();
// delay(500);
// driveArcRF(90, 725, 2000);
// driveStraight2(450);
// Redirect.move(0);
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveTurn(-75);
// driveStraight2(500);
// // driveArcLF(70, 500, 1500);
// // driveStraight2(30);
// // bool color_sort = true;
// // while(color_sort){
// // if(eyes.get_hue()<25){
// //     delay(40);
// //     Intake.move(0);
// //     Intake_Layer1.move(0);
// //     break;
// // }
// //     }
// // driveTurn(-150);
// // driveTurn(-20);
// // driveSlow(25, 150);
// // Redirect.move(-127);
// // delay(600);
// // Redirect.move(127);
// // delay(650);
// // Redirect.move(0);

// }

// void autons4(){
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveTurn(-35);
// driveSlow(305, 15);
// Redirect.move(-127);
// delay(450);
// Redirect.move(127);
// delay(350);
// Redirect.move(0);
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveStraight2(-500);
// driveTurn(-60);
// Redirect.move(127);
// delay(200);
// Redirect.move(0);
//     Intake.move(-80);
//     Intake_Layer1.move(-127);
//     driveSlow(700, 25);  
//     bool color = true;
//     while(color){
// if(eyes.get_hue()>150){
//     Intake.move(0);
//     Intake_Layer1.move(0);
//     break;
// }
//     }
// driveSlow(-600, 70);
// driveTurn(70);//85
// driveClampSlow(-1350, 20, 45);
// driveStraight2(200);
// driveTurn(110);
// Intake.move(-80);
// Intake_Layer1.move(-127);
// delay(250);
// driveStraight2(775);
// Intake.move(-100);
// delay(250);
// driveTurn(160);
// driveSlow(950, 100);
// Redirect.move(-180);
// }

// void fiveRing(){
// driveTurn(-35);
// driveSlow(240, 50);
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// Redirect.move(-127);
// delay(500);
// Redirect.move(127);
// delay(500);
// Redirect.move(0);
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveTurn(9);
// driveClampSlow(-1700, 25, 50);
// driveTurn(170);
// Intake.move(-85);
// Intake_Layer1.move(-127);
// StakeWing.set_value(true);
// driveArcLF(75, 800, 1000);
// driveTurn(-115);
// //work in progress
// }
 
// void autons5 () {
// //ring side auton blue
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveTurn(35);
// driveSlow(280, 15);
// Redirect.move(-127);
// delay(600);
// Redirect.move(127);
// delay(350);
// Redirect.move(0);
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveTurn(-15);
// // driveTurn(-10);
// driveClampSlow(-1950, 60, 50);
// delay(400);
// driveStraight2(250);
// Redirect.move(127);
// delay(200);
// Redirect.move(0);
// Redirect.set_brake_mode(E_MOTOR_BRAKE_HOLD);
// driveTurn(-150);
// driveTurn(-20);
// Intake.move(-90);
// Intake_Layer1.move(-127);
// driveStraight2(740); // first ring 
// driveTurn(37);
// driveSlow(300, 20);
// delay(50); //second ring
// driveTurn(110);
// driveSlow(600, 50);
// delay(100);
// Intake.move(-95);
// Intake_Layer1.move(0); 
// driveTurn(110);
// Intake.move(0);
// driveStraight2(1000);
// Redirect.move(-127);//touches ladder
// }*/