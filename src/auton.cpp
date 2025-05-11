#include "main.h"
#include "api.h"
#include "pid.h"
#include "robot.h"
#include "auton.h"
 using namespace pros;


//below is not accurate. I will renumber later
// auton1=red side ring side
// auton2=blue side ring side
// auton3= red side elims goal side
// autons4= blue side elims goal side
// autons5 = auto skills
//1 = no blue rings, 2 = no red rings.
  void DriveStraightAuto(){
    driveStraightSlow(250, 50);
  }

 void Standard_AWP_red(){// Also retuned
  eyes.set_led_pwm(100); //always do this
  LadyBrown.move(-110);
  driveStraight2(250);
  LadyBrown.move(20);
  driveTurn2(3);
  driveStraightC(-400);
  LadyBrown.move(-127);
  LadyBrown.move(90);
  driveStraight2(-905);
  //driveTurn2(-10);
  driveClampS(-850, 275, 100);
  driveTurn2(150);
  Intake.move(127);
  color = 1;
  driveStraight2(625);
     //delay(200);
  driveTurn2(60);
  driveStraight2(500);
  driveTurn2(-20);
  driveStraightC(1600);
  MogoMech.set_value(false);
  color = 0;
  Intake.move(127);
  driveArcLF(50, 400, 500, 100);
  driveStraight2(10);
      //driveTurn2(-25);
  Intake.move(127);
  driveSortHoldRed(1190, 45);
  Intake.move(0);
  driveTurn2(10);
  driveStraight2(-1200);
  driveClampS(-550, 200, 60);
  Intake.move(127);
  driveTurn2(165);
  LadyBrown.move(-127);
  driveStraight2(150);
 }
 void Goal_Rush_red(){ 
  // color = 1;//1 = no blue rings, 2 = no red rings
  eyes.set_led_pwm(100);
  StakeWing.set_value(true);
  Intake.move(127);
  driveSortHoldRedC(2000, 100);
  StakeWing.set_value(false);
  driveStraightC(70);
  Intake.move(25);
  driveStraightRush(-1205);
  StakeWing.set_value(true);
  driveStraight2(-600);
  StakeWing.set_value(false);
  driveTurn2(169);
  driveStraight2(-900);
  driveClampS(-500, 200, 90);
  color = 1;
  driveTurn2(-175);
  // driveStraightC(1600);
  driveSortHoldRedC(1200, 100);
  driveSortHoldRed(700, 100);
  color = 0;
  Intake.move(0);
  driveTurn2(-11);
  MogoMech.set_value(false);
  driveStraight2(500);
  driveTurn2(150);
  driveClampS(-1300, 100, 50);
  driveTurn2(-150);
  driveStraightC(500);
  color = 1;
  driveStraight2(1000);
  driveStraightSlow(650, 75);
  // StakeWing.set_value(true);
  // driveStraight2(2500);
  // color = 1;
  // driveTurn2(-100);
  // StakeWing.set_value(false);
  // driveStraight2(750);
  // driveStraightC(2900);
  // driveStraight2(100); these don't work. Trouble shoot later
 }

 void Ring_Rush_red(){ //done
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
  LadyBrown.move_relative(-195, 127);
  driveTurn2(49);
  Intake.move(0);
  driveStraight2(750);
  Intake.move(127);
  delay(500);
  Intake.move(0);
  LadyBrown.move(-90);
  delay(1000);
  // driveStraightC(-1000);
  // driveTurn2(-45);
  LadyBrown.move(45);
  //driveArcRF(-45, 500, 1500, 100);
  // driveStraightC(-250);
  // driveTurn2(10);
  // LadyBrown.move_relative(-300, 127);
  // driveStraight2(-1500);

  }

 void goal_safe_side_red(){ //not tested 
  //driveTurn2(10);
  eyes.set_led_pwm(100);
  driveStraight2(-1200);
  driveClampS(-700, 300, 85);
  driveTurn2(30);
  color = 1;
  driveStraight2(1300);
  StakeWing.set_value(true);
  driveStraightC(-700);
  driveTurn2(-60);
  StakeWing.set_value(false);
  delay(100);
  driveArcLF(75, 200, 750, 100);
  driveStraight2(10);
  driveStraightSlow(900, 65);
  driveStraight2(-200);
  driveTurn2(-32);
  StakeWing.set_value(true);
  driveStraight2(1650);
  driveTurn2(60);
  StakeWing.set_value(false);
  driveTurn2(50);
  driveArcRF(130, 400, 1500, 100);
  driveStraight2(750);
  MogoMech.set_value(false);
  driveTurn2(110);
  LadyBrown.move(-70);
  driveStraight2(250);

  }


 void Standard_AWP_blue(){ //done
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
  driveStraight2(625);
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
  driveStraight2(-1200);
  driveClampS(-550, 200, 60);
  driveTurn2(-165);
  Intake.move(127);
  LadyBrown.move(-127);
  }


 void Goal_Rush_Blue(){ // incosistent, but done 
  //blue goal rush
  eyes.set_led_pwm(100);
  StakeWing.set_value(true);
  eyes.set_led_pwm(100);
  Intake.move(60);
  driveSortHoldblueC(2000, 100);
  StakeWing.set_value(false);
  driveStraight2(45);
  Intake.move(0);
  driveStraightRush(-1170);
  StakeWing.set_value(true);
  driveStraight2(-500);
  StakeWing.set_value(false);
  driveTurn2(168);
  driveStraight2(-900);
  driveClampS(-600, 150, 90);
  color = 2;
  driveTurn2(150);
  driveStraight2(350);
  delay(200);
  MogoMech.set_value(false);
  driveTurn2(70);
  driveStraight2(450);
  driveTurn2(-130);
  driveClampS(-1000, 150, 50);
  driveTurn2(15);
  color = 0;
  Intake.move(0);
  driveStraight2(850);
  StakeWing.set_value(true);
  delay(200);
  driveStraightC(-975);
  driveTurn2(170);
  StakeWing.set_value(false);
  delay(100);
  // driveTurn2(20);
  driveTurn2(140);
  color = 2;
  // StakeWing.set_value(true);
  driveArcRF(100, 450, 1500, 100);
  driveStraight2(600);

 }

//blue ring side touch bar bc not doing corner stack
 void goal_safe_side_blue(){
  //driveTurn2(10);
  driveStraight2(-1200);
  driveClampS(-700, 300, 85);
  driveTurn2(-100);
  driveStraight2(750);
  driveTurn2(-115);
  StakeWing.set_value(true);
  delay(300);
  driveStraightC(-1700);
  StakeWing.set_value(false);
  delay(100);
  //driveStraight2(-350);
  driveTurn2(-100);
  color = 2;
  driveArcLF(175, 150, 1000, 100);
  driveStraightC(600);
  // delay(100);
  driveTurn2(20);
  driveStraightC(800);
  StakeWing.set_value(true);
  //driveStraight2(400);
  driveArcRF(90, 400, 1000, 100);
  driveStraight2(100);
  // // driveSortHoldblue(2100, 100);
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
    driveStraight2(385);
    delay(200);
    driveStraightC(-400);
    driveTurn2(-150);
    driveStraight2(-1385);
    driveArcRF(40, 250, 7500, 100);
    driveStraightC(1000);
    driveTurn2(48);
    driveStraight2(1900);
    MogoMech.set_value(false);
    color = 0;
    Intake.move(127);
    driveSortHoldblue(1000, 60);
    LadyBrown.move_relative(-185, 127);
    Intake.move(0);
    driveTurn2(-62);
    Intake.move(0);
    driveStraight2(450);
    Intake.move(127);
    delay(500);
    Intake.move(0);
    LadyBrown.move(-127);
    delay(400);
    LadyBrown.move(45);
    driveStraightC(-350);
    driveTurn2(-10);
    LadyBrown.move_relative(-200, 127);
    driveStraight2(-2200);
   }
 
 void skill_run(){
  LadyBrown.move_relative(-900, 127); // alliance stake 
  delay(700);
  LadyBrown.move(90);
  driveStraight2(100);
  delay(200);
  driveStraight2(-575); 
  driveTurn2(90);
  driveStraight2(-700);
  driveClampS(-400, 200, 50); // grabs goal 
  driveTurn2(180);
  color = 1;
  driveStraightC(400);// grabs first ring 
  driveArcRF(25, 400, 1000, 100); //around ladder
  driveStraightC(1000);
  driveArcLF(10, 400, 1000, 100);//back for second ring
  driveStraightC(1000);
  driveArcRF(10, 400, 1000, 100);//back for third ring for lady brown 
  color = 0;
  Intake.move(120);
  driveStraightC(1500);
  LadyBrown.move_relative(-270, 127);//ready for lady brown load 
  driveStraight2(50);
  delay(100);
  driveTurn2(-165);
  driveStraightC(-1250);
  color = 0;
  driveStraight2(-1015);
  color = 1; //taps into lady brown 
  driveTurn2(-95);
  delay(500);
  color = 0;
  Intake.move(0);
  LadyBrown.move_relative(-150, 90);//makes room for second ring
  delay(500);
  Intake.move(127);
  driveSortHoldRed(440, 40); //grabs second ring 
  Intake.move(0);
  LadyBrown.move_relative(-900, 127); //scores one on wall stake 
  delay(500);
  //Intake.move(20);
  driveStraightSlow(-600, 50);
  LadyBrown.move_relative(1050, 127); //loads for second 
  delay(750);
  Intake.move(127);
  driveStraightSlow(550, 60);
  Intake.move(0);
  delay(100);
  LadyBrown.move_relative(-600, 127); //scores second on wall stake 
  delay(750);
  driveStraight2(-700);
  driveTurn2(-5);
  Intake.move(-127);// anti jam thing 
  delay(100);
  Intake.move(0);
  color = 1;
  driveStraightSlow(2100, 70);  //grabs two more rings 
  driveTurn2(0);
  driveStraightSlow(600, 60); //grabs third ring 
  driveTurn2(-140);
  driveStraight2(700);//sixth ring on goal 
  driveTurn2(140);
  MogoMech.set_value(false);
  driveStraight2(-700); //goal in corner 
  LadyBrown.move(127);
  driveStraight2(400);
  driveTurn2(-87);//ready for second mogo 
  color = 0;
  Intake.move(-127);
  delay(100);
  driveStraightC(-1000);
  driveStraightC(-1000);
  driveStraight2(-800);
  driveTurn2(-105);
  Intake.move(0);
  driveClampS(-1000, 200, 50); //grabs second mogo 
  driveTurn2(-135);
  MogoMech.set_value(false);
  driveStraightC(-2000);
  driveStraight2(500);
  driveStraight2(250);
  driveTurn2(180);
  driveStraightC(2000);
  driveStraightC(2000);
  driveStraight2(500);
  driveTurn2(45);
  driveClampS(-750, 100, 75);

 }
 
 void autonomous(){
  if (atn == 0) {
  }else if (atn == 0) {
    DriveStraightAuto();
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