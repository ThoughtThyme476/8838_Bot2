#include "main.h"
#include "api.h"
#include "robot.h"

//header Guards, safety

#define LF_PORT 5 //yes
#define LM_PORT 4 //yes
#define LB_PORT 9 //yes
#define RF_PORT 6
#define RM_PORT 3 //yes
#define RB_PORT 2 //yes
#define IMU_PORT 1
#define Intake_port 7
#define LadyBrown_PORT 8
#define OPTICAL_PORT 21
#define DISTANCE_PORT 19
#define ROTATION_PORT 10


pros::Motor LF (LF_PORT, pros::E_MOTOR_GEARSET_06, true); //keep
pros::Motor LM (LM_PORT, pros::E_MOTOR_GEARSET_06, true); //
pros::Motor LB (LB_PORT, pros::E_MOTOR_GEARSET_06, true); //keep
pros::Motor RF (RF_PORT, pros::E_MOTOR_GEARSET_06, false); //keep
pros::Motor RM (RM_PORT, pros::E_MOTOR_GEARSET_06, false); //keep
pros::Motor RB (RB_PORT, pros::E_MOTOR_GEARSET_06, false); //keep                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

pros::Motor Intake (Intake_port, pros::E_MOTOR_GEARSET_06, true);
pros::Motor LadyBrown (LadyBrown_PORT, pros::E_MOTOR_GEARSET_18, true);

pros::Imu imu(IMU_PORT);
pros::Optical eyes(OPTICAL_PORT);
pros::Rotation roto(ROTATION_PORT);
pros::Distance dis (DISTANCE_PORT);
pros::Controller con (pros::E_CONTROLLER_MASTER);


pros::ADIDigitalOut MogoMech ('B',true);//out soloniod was stolen so I changed this
pros::ADIDigitalOut StakeWing('H',false);
pros::ADIDigitalOut Intake_Piston ('A',false);
pros::ADIDigitalIn selec ('C');//