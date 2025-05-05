#include "main.h"
#include "robot.h"
#include "api.h"
#include "pid.h"
using namespace pros;
using namespace c;
using namespace std;


//stall prot stuff
//bool stallProt = false;
bool stalled = false;
int stallTime = 0;
int direc;
int direc2;
int hookspos;
int prevhookpos;
float view;
int stallC = 0;

double totalError;
bool DaSortMaster = false;
int ringTime = 0;
double vKp;
double vKi;
double vKd;
double prevPower;
double currentpower;
double prevError;
double h;
double power;
float error;
int integral;
int derivitive;
int time2;
//Round two of variables. :/
double vKp2;
double vKi2;
double vKd2;
double prevPower2;
double currentpower2;
double prevError2;
double h2;
double power2;
float error2;
int integral2;
int derivitive2;
int time3;
// round three of variables :/ :/
double vKp3;
double vKi3;
double vKd3;
double prevPower3;
double currentpower3;
double prevError3;
double h3;
double power3;
float error3;
int integral3;
int derivitive3;
int time4;
// round four this time :/ :/ :/ 
double vKp4;
double vKi4;
double vKd4;
double prePower4;
double cur4entpower4;
double prevError4;
double h4;
double power4;
float error4;
int integral4;
int derivitive4;
int time5;
// other variables
double trueTarget = 0;
int color;









//other stuff 
void hooks(int speed){
    direc = speed; 
}

// void stall(){
//     bool stallProt = true;
//     if(stallProt){
//         if(hookspos == prevhookpos){
//             stuck_time += 10;
//         } else {
//             stuck_time = 0;
//         }
//         if(stuck_time > 100){
//             stuck = true;
//             stuck_time = 0;
//         }
            
//         if(stuck){
//                     Intake.move(-127);
//                     stallTime+= 10;
//                     if (stallTime >= 100){
//                         stuck = false;
//                         stallTime = 0;
//                     }
//             } else { 
//                 stuck = false;
//                 Intake.move(127);
//             }
//         Intake.tare_position();
//     }

// }

// void ColorSort(int color){
    // //Red Sort
    //         if(color == 1){
    //         if(eyes.get_hue() < 40 && eyes.get_hue() > 12){
    //             Intake.move(127);
    //         }
    //         else if(eyes.get_hue() > 180 && eyes.get_hue() < 240){
    //             delay(100);
    //             Intake.move(0);
    //         }
    //     }
    // //Blue Sort
    //     if(color == 2){
    //         if(eyes.get_hue() > 180 && eyes.get_hue() < 240){
    //             Intake.move(127);
    //         }
    //         else if(eyes.get_hue() < 40 && eyes.get_hue() > 12){
    //             delay(100);
    //             Intake.move(0);
    //     }
    //     }

    bool InitColor = false;
bool InitCorrect = false;
int ColorCount;
bool Backwards = false;
bool stuck = false;
int stuck_time = 0;
void ColorSort(){

prevhookpos = hookspos;
hookspos = Intake.get_position();
    //blue color rejection
    if (color == 1){  //
        if((eyes.get_hue()<230 && eyes.get_hue()>180) && eyes.get_proximity() > 160){ // 50
            InitColor = true;
        }

        if (InitColor){
            if(Backwards == false){
                Intake.move(127);
                if(Intake.get_position() > 250){
                    Backwards = true;
                }
            } else {
                Intake.move(-127);
                if(Intake.get_position() < 100){
                    Backwards = false;
                    InitColor = false;
                }
            }
        } else {
            if(hookspos == prevhookpos){
                stuck_time += 10;
            } else {
                stuck_time = 0;
            }
            if(stuck_time > 100){
                stuck = true;
                stuck_time = 0;
            }
                
            if(stuck){
                        Intake.move(-127);
                        stallTime+= 10;
                        if (stallTime >= 100){
                            stuck = false;
                            stallTime = 0;
                        }
                } else { 
                    stuck = false;
                    Intake.move(127);
                }
            Intake.tare_position();
        }
    } else if(color == 2){ //red ring rejection 
        if((eyes.get_hue()<40 && eyes.get_hue()>5) && eyes.get_proximity() > 140){ // 50
            InitColor = true;
        }

        if (InitColor){
            if(Backwards == false){
                Intake.move(127);
                if(Intake.get_position() > 250){
                    Backwards = true;
                }
            } else {
                Intake.move(-127);
                if(Intake.get_position() < 100){
                    Backwards = false;
                    InitColor = false;
                }
            }
        } else {
            if(hookspos == prevhookpos){
                stuck_time += 10;
            } else {
                stuck_time = 0;
            }
            if(stuck_time > 100){
                stuck = true;
                stuck_time = 0;
            }
                
            if(stuck){
                        Intake.move(-127);
                        stallTime+= 10;
                        if (stallTime >= 100){
                            stuck = false;
                            stallTime = 0;
                        }
                } else { 
                    stuck = false;
                    Intake.move(127);
                }
            Intake.tare_position();
        }
    }
}


//stall prot for intake
void StallProtection(){



if(hookspos == prevhookpos){
stuck = true;
}

    if(stuck){
        Intake.move(-127);
        stallTime+= 10;
        if (stallTime >= 100){
            stuck = false;
            stallTime = 0;
        }
} else { 
    stuck = false;
    Intake.move(127);
}
    // delay(10);
} 


    
    
void setConstants(double kp, double ki, double kd){

    vKp = kp;
    vKi = ki;
    vKd = kd;
}
 void resetEncoders(){

    LF.tare_position();
    LB.tare_position();
    LM.tare_position();
    RF.tare_position();
    RM.tare_position();
    RB.tare_position();

 }

void chasMove(int voltageLF, int voltageLM, int voltageLB, int voltageRF, int voltageRM, int voltageRB){

    LF.move(voltageLF);
    RF.move(voltageRF);
    LM.move(voltageLM);
    RM.move(voltageRM);
    LB.move(voltageLB);
    RB.move(voltageRB);

}

double calcPID(double target, double input, int integralKI, int maxIntegral){
    // Odometry2();
    // stall();
    //replaced text;
   ColorSort();
  // StallProtection();
    
    int integral;
    prevError = error;
    error = target - input;

    if(abs(error) < integralKI){
        integral += error; 
    }
    else{
        integral = 0;
    }
    if(integral >= 0){
        integral = min(integral, maxIntegral);
    }
    else{
        integral = max(integral, -maxIntegral);
    }
    derivitive = error - prevError;

    power = (vKp * error) + (vKi * integral) + (vKd * derivitive);

    return power;    
}

double calcPID2(double target2, double input2, int integralKI2, int maxIntegral2){
    //replaced text;
    //StallProtection();

    int integral2;
    prevError2 = error2;
    error2 = target2 - input2;

    if(abs(error2) < integralKI2){
        integral2 += error2;
    }
    else{
        integral2 = 0;
    }
    if(integral2 >= 0){
        integral2 = min(integral2, maxIntegral2);
    }
    else{
        integral2 = max(integral2, -maxIntegral2);
    }
    derivitive2 = error2 - prevError2;

    power2 = (vKp * error2) + (vKi * integral2) + (vKd * derivitive2);

    return power2;

}

double calcPID3(double target3, double input3, int integralKI3, int maxIntegral3){
    //replaced text;
    //StallProtection();

    int integral3;
    prevError3 = error3;
    error3 = target3 - input3;

    if(abs(error3) < integralKI3){
        integral3 += error3;
    }
    else{
        integral3 = 0;
    }
    if(integral3 >= 0){
        integral3 = min(integral3, maxIntegral3);
    }
    else{
        integral3 = max(integral3, -maxIntegral3);
    }
    derivitive3 = error3 - prevError3;

    power3 = (vKp * error3) + (vKi * integral3) + (vKd * derivitive3);

    return power3;

}

double calcPID4(double target4, double input4, int integralKI4, int maxIntegral4){
    //replaced text;
    //StallProtection();

    int integral4;
    prevError4 = error4;
    error4 = target4 - input4;

    if(abs(error4) < integralKI4){
        integral4 += error4;
    }
    else{
        integral4 = 0;
    }
    if(integral4 >= 0){
        integral4 = min(integral4, maxIntegral4);
    }
    else{
        integral4 = max(integral4, -maxIntegral4); 
    }

    if(error4*prevError4 >= 0){
        integral4 = 0;
    }

    derivitive4 = error4 - prevError4;

    power4 = (vKp * error4) + (vKi * integral4) + (vKd * derivitive4);

    return power4;

}



       //red sort	
//     if (color == 1){
//         if (eyes.get_hue()<40 && eyes.get_hue()>12){
// 	        DaSortMaster = true;
//             //found a red ring
//         }
//     }
//     //blue sort
//     if (color == 2){
//         if (eyes.get_hue()<110 && eyes.get_hue()>180){
// 	        DaSortMaster = true;
//             //found a blue ring
//         }
//     }


// if (DaSortMaster == true){ //found the right ring
// 	//int delayTime = 200;
// 	    ringTime += 1;
// 	//
// 	// DaSorter.set_value(true);

// 	    if (ringTime >= 1300) {
// 		    DaSortMaster = false;
// 		    ringTime=0;
// 	    } 
//         else if (ringTime>= 1000){
// 		    Intake.move(-127);
//     	}   
//         else {
// 		Intake.move(127);
// 	}
// 	} else{
// 		Intake.move(127);
// 	} 



void driveStraight(int target) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
   //   timeout = (-0.000000000000750853* pow(x,5)) + (  0.00000000378468 * pow(x,4)) + (-0.00000629527 * pow(x,3)) + (0.00422834* pow(x,2)) + (-0.665814 * x) + 707.21366;
    imu.tare();

    

    double voltage;
    double encoderAVG;
    int count = 0;
    double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    if(init_heading > 180){
        init_heading = init_heading - 360;
    }

    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
         if(abs(target - encoderAVG) < 25){
            setConstants(3, 0, 0);
        } else{
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD); 
        }   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
      
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((init_heading < 0) && (position > 0)){
        if((position - init_heading ) >= 180){
           init_heading = init_heading + 360;
            position = imu.get_heading();
        }
    }else if((init_heading > 0) && (position < 0)){
        if ((init_heading - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
    headingError = calcPID2(init_heading, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);
        
        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
            break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float (error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
             con.print(2,0, "EncoderAVG: %f           ", float(LF.get_encoder_units()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}


 void driveTurn(int target){

    double voltage;
    double position;
    int count = 0;
    // time2 = 0;
    int timeout = 300000;
    double x = 0;
    double variKD = 0;
    double variKP = 0;
    x = double(abs(target));
    // variKD = ((-0.000000010414) * pow(x,5)) + (0.00000436151 * pow(x,4)) + (-0.000635881 * pow(x,3)) + (0.0378021 * pow(x,2)) + (-0.805858 * x) + 69.3766;
    // variKP = ((0.00000000017809) * pow(x,5)) + (-0.000000087322 * pow(x,4)) + (0.000015948* pow(x,3)) + (-0.00128717 * pow(x,2)) + (0.041072 * x) + 6.7388;
    //setConstants(variKP, TURN_KI, variKD);
    if(abs(error) <= 3){
        setConstants(10, 0, 0);
    } else{
        setConstants(TURN_KP, TURN_KI, TURN_KD); 
    } 
   //timeout = (-0.000000141031*pow(x,5)) + (0.0000650427*pow(x,4)) + (-0.0105768*pow(x,3)) + (0.678481*pow(x,2)) + (-8.01221*(x)) + 353.39229;
    imu.tare_heading();

    while(true) { 
        position = imu.get_heading();

        if (position > 180){
            position = ((360 - position) * -1);

        }
        voltage = calcPID(target, position,TURN_INTRGRAL_KI, TURN_MAX_INTEGRAL);
 
        chasMove(voltage, voltage, voltage, - voltage, - voltage, - voltage);

        if(abs(target - position) <= 0.95) count++;

        if (count >= 20 || time2 > timeout) {

        break;
        }
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "error: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "time: %f           ", float(time2));
        }
         if(time2 % 150 == 0){
            con.print(2,0, "pos: %f           ", float(power));
        }
        
        time2 += 10;
        delay(10); 
    }
        LF.brake();
        LM.brake();
        LB.brake();
        RF.brake();
        RM.brake();
        RB.brake();

}

 void driveTurn2(int target){
    int turnv;
    double voltage;
    double position;
    int count = 0;
    time2 = 0;
    trueTarget = target;



    position = imu.get_heading();
     if(position > 180){
        position = ((360 - position)*-1);
     } 
     if ((target <0) && (position > 0)){
        if ((position - target) >= 180){
            target = target + 360;
            position = imu.get_heading();
            turnv = (target - position);
        } else {
            turnv = (abs(position) + abs(target));
        } 
     } else if ((target > 0) && (position < 0)){
        if((target - position) >= 180){
            position = imu.get_heading();
            turnv = (abs(position) - abs(target)); 
        } else {
            turnv = (abs (position) + target);
            }
     } else {
        turnv = abs(abs(position) - abs(target));
     }

    int timeout = 1000000;
    double x = 0;
    double variKD = 0;
    double variKP = 0;
    x = double(abs(turnv));
   timeout = (-0.000000141031*pow(x,5)) + (0.0000650427*pow(x,4)) + (-0.0105768*pow(x,3)) + (0.678481*pow(x,2)) + (-8.01221*(x)) + 353.39229;
    // variKD = ((-0.000000010414) * pow(x,5)) + (0.00000436151 * pow(x,4)) + (-0.000635881 * pow(x,3)) + (0.0378021 * pow(x,2)) + (-0.805858 * x) + 69.3766;
    // variKP = ((0.00000000017809) * pow(x,5)) + (-0.000000087322 * pow(x,4)) + (0.000015948* pow(x,3)) + (-0.00128717 * pow(x,2)) + (0.041072 * x) + 6.7388;

   // setConstants(TURN_KP, TURN_KI, TURN_KD); 
    while(true) { 

    if(abs(error) <= 3){
        setConstants(10, 0, 0);
    } else{
         setConstants(TURN_KP, TURN_KI, TURN_KD); 
    }     
    position = imu.get_heading();
     if(position > 180){
        position = ((360 - position)*-1);
     } 
     if ((target <0) && (position > 0)){
        if ((position - target) >= 180){
            target = target + 360;
            position = imu.get_heading();
            turnv = (target - position);
        } else {
            turnv = (abs(position) + abs(target));
        } 
     } else if ((target > 0) && (position < 0)){
        if((target - position) >= 180){
            position = imu.get_heading();
            turnv = (abs(position) - abs(target)); 
        } else {
            turnv = (abs (position) + target);
            }
     } else {
        turnv = abs(abs(position) - abs(target));
     }
        voltage = calcPID(target, position, TURN_INTRGRAL_KI, TURN_MAX_INTEGRAL);

        chasMove(voltage, voltage, voltage, - voltage, - voltage, - voltage);

        if(abs(target - position) <= 0.95) count++;

        if (count >= 20 || time2 > timeout) {

            break;
        }
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(imu.get_heading()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        time2 += 10;
        delay(10); 
    }
        LF.brake();
        LM.brake();
        LB.brake();
        RF.brake();
        RM.brake();
        RB.brake();

}


void driveTurnT(int target){
    int turnv;
    double voltage;
    double position;
    int count = 0;
    time2 = 0;
    trueTarget = target;

    position = imu.get_heading();
     if(position > 180){
        position = ((360 - position)*-1);
     } 
     if ((target <0) && (position > 0)){
        if ((position - target) >= 180){
            target = target + 360;
            position = imu.get_heading();
            turnv = (target - position);
        } else {
            turnv = (abs(position) + abs(target));
        } 
     } else if ((target > 0) && (position < 0)){
        if((target - position) >= 180){
            position = imu.get_heading();
            turnv = (abs(position) - abs(target)); 
        } else {
            turnv = (abs (position) + target);
            }
     } else {
        turnv = abs(abs(position) - abs(target));
     }

    int timeout = 1000000;
    double x = 0;
    double variKD = 0;
    double variKP = 0;
    x = double(abs(turnv));
    timeout = timeout = (-0.000000141031*pow(x,5)) + (0.0000650427*pow(x,4)) + (-0.0105768*pow(x,3)) + (0.678481*pow(x,2)) + (-8.01221*(x)) + 353.39229;
    // variKD = ((-0.000000010414) * pow(x,5)) + (0.00000436151 * pow(x,4)) + (-0.000635881 * pow(x,3)) + (0.0378021 * pow(x,2)) + (-0.805858 * x) + 69.3766;
    // variKP = ((0.00000000017809) * pow(x,5)) + (-0.000000087322 * pow(x,4)) + (0.000015948* pow(x,3)) + (-0.00128717 * pow(x,2)) + (0.041072 * x) + 6.7388;
    if(abs(error) <= 3){
        setConstants(10, 0, 0);
    } else{
        setConstants(TURN_KP, TURN_KI, TURN_KD); 
    }  
    while(true) { 
    position = imu.get_heading();
     if(position > 180){
        position = ((360 - position)*-1);
     } 
     if ((target <0) && (position > 0)){
        if ((position - target) >= 180){
            target = target + 360;
            position = imu.get_heading();
            turnv = (target - position);
        } else {
            turnv = (abs(position) + abs(target));
        } 
     } else if ((target > 0) && (position < 0)){
        if((target - position) >= 180){
            position = imu.get_heading();
            turnv = (abs(position) - abs(target)); 
        } else {
            turnv = (abs (position) + target);
            }
     } else {
        turnv = abs(abs(position) - abs(target));
     }
        voltage = calcPID4(target, position, TURN_INTRGRAL_KI, TURN_MAX_INTEGRAL);

        chasMove(voltage, voltage, voltage, - voltage, - voltage, - voltage);

        if(abs(target - position) <= 0.95) count++;

        if (count >= 20 || time2 > timeout) {

            break;
        }
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(imu.get_heading()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        time2 += 10;
        delay(10); 
    }
        LF.brake();
        LM.brake();
        LB.brake();
        RF.brake();
        RM.brake();
        RB.brake();

}

void driveStraight2(int target) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
   timeout = (-0.000000000000750853* pow(x,5)) + (  0.00000000378468 * pow(x,4)) + (-0.00000629527 * pow(x,3)) + (0.00422834* pow(x,2)) + (-0.665814 * x) + 707.21366;
    double voltage;
    double encoderAVG;
    int count = 0;
    //double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        if(abs(target - encoderAVG) < 25){
            setConstants(3, 0, 0);
        } else{
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD); 
        }  
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (trueTarget- 360);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget) >= 180){
            trueTarget = trueTarget+ 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget- position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);
      // headingError = 0;

        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 3) count++;
        if (count >= 20 || time2 > timeout){
          break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "time2: %f           ", float(time2));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "TrueTarget: %f           ", float(trueTarget));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "error %f           ", float(error));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}

void driveStraightRush(int target) {

    int timeout = 15000; //make sure to test this because to might waste a bunch of time for auto/cut auto short

    double x = 0;
    x = double(abs(target));
    timeout = (-0.000000000000750853* pow(x,5)) + (  0.00000000378468 * pow(x,4)) + (-0.00000629527 * pow(x,3)) + (0.00422834* pow(x,2)) + (-0.665814 * x) + 707.21366;    double voltage;
    double encoderAVG;
    int count = 0;
   // double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        if(abs(target - encoderAVG) < 25){
            setConstants(3, 0, 0);
        } else{
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD); 
        }   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (trueTarget - 360);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);
      // headingError = 0;

        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 3) count++;
        if (count >= 20 || time2 > timeout){
          break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "time2: %f           ", float(time2));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(trueTarget));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "error %f           ", float(error));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}

void driveStraightC(int target) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (-0.000000000000750853* pow(x,5)) + (  0.00000000378468 * pow(x,4)) + (-0.00000629527 * pow(x,3)) + (0.00422834* pow(x,2)) + (-0.665814 * x) + 707.21366; 
    if (target > 0){
    target = target + 500;
 } else{
    target = target - 500;
 }
    double voltage;
    double encoderAVG;
    int count = 0;
    //double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;
    bool over = false;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        if(abs(target - encoderAVG) < 25){
            setConstants(3, 0, 0);
        } else{
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD); 
        }   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (trueTarget - 360);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }

    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);

        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if(target > 0){
            if((encoderAVG - (target-500)) > 0){
                over = true;
            }
        } else if(((target+500) - encoderAVG) > 0){
        over = true;
        }

        if(over || time2 > timeout){
            break;
        }



        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(time2));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(LF.get_encoder_units()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}

void driveClamp(int target, int clampDistance) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (-0.000000000000750853* pow(x,5)) + (  0.00000000378468 * pow(x,4)) + (-0.00000629527 * pow(x,3)) + (0.00422834* pow(x,2)) + (-0.665814 * x) + 707.21366;    double voltage;
    double encoderAVG;
    int count = 0;
    //double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        if(abs(target - encoderAVG) < 25){
            setConstants(3, 0, 0);
        } else{
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD); 
        }   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (trueTarget - 360);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);

        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

        if(abs((target - position)) < clampDistance){
            MogoMech.set_value(true); // mabye reveres this?
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
           break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(time2));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(LF.get_encoder_units()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}

void driveClampS(int target, int clampDistanceFromTarget, int speed) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (-0.000000000000750853* pow(x,5)) + (  0.00000000378468 * pow(x,4)) + (-0.00000629527 * pow(x,3)) + (0.00422834* pow(x,2)) + (-0.665814 * x) + 707.21366;    timeout = timeout * (2 - (double(speed)/100.0));

    double voltage;
    double encoderAVG;
    int count = 0;
    //double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        if(abs(target - encoderAVG) < 25){
            setConstants(3, 0, 0);
        } else{
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD); 
        }   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (trueTarget - 360);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);

        if(voltage > 127 * double(speed)/100){
            voltage = 127 * double(speed)/100;
        } else if (voltage < -127 * double(speed)/100){
            voltage = -127 * double(speed)/100;
        }

  if(abs(target - encoderAVG) < clampDistanceFromTarget){
     MogoMech.set_value(true); // mabye reveres this?
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
           break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(imu.get_heading()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}

void driveSortHoldRed(int target, int speed) {
    if (target > 0){
        target = target + 500;
     } else{
        target = target - 500;
     }
    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (-0.000000000000750853* pow(x,5)) + (  0.00000000378468 * pow(x,4)) + (-0.00000629527 * pow(x,3)) + (0.00422834* pow(x,2)) + (-0.665814 * x) + 707.21366;    timeout = timeout * (2 - (double(speed)/100.0));

    double voltage;
    double encoderAVG;
    int count = 0;
    //double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        if(abs(target - encoderAVG) < 25){
            setConstants(3, 0, 0);
        } else{
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD); 
        }   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (trueTarget - 360);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);

        if(voltage > 127 * double(speed)/100){
            voltage = 127 * double(speed)/100;
        } else if (voltage < -127 * double(speed)/100){
            voltage = -127 * double(speed)/100;
        }

  if((eyes.get_hue()<40 && eyes.get_hue()>5) && eyes.get_proximity() > 150){
    Intake.move(0);
  }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
           break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(imu.get_heading()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}


void driveSortHoldblue(int target, int speed) {
    if (target > 0){
        target = target + 500;
     } else{
        target = target - 500;
     }

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (-0.000000000000750853* pow(x,5)) + (  0.00000000378468 * pow(x,4)) + (-0.00000629527 * pow(x,3)) + (0.00422834* pow(x,2)) + (-0.665814 * x) + 707.21366;    timeout = timeout * (2 - (double(speed)/100.0));

    double voltage;
    double encoderAVG;
    int count = 0;
    //double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        if(abs(target - encoderAVG) < 25){
            setConstants(3, 0, 0);
        } else{
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD); 
        }   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (trueTarget - 360);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);

        if(voltage > 127 * double(speed)/100){
            voltage = 127 * double(speed)/100;
        } else if (voltage < -127 * double(speed)/100){
            voltage = -127 * double(speed)/100;
        }

   if((eyes.get_hue()<230 && eyes.get_hue()>170) && eyes.get_proximity() > 150){
    Intake.move(0);
    } 

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
           break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(imu.get_heading()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}


void driveSortHoldRedC(int target, int speed) {

    int timeout = 30000;
    bool over = false;
    double x = 0;
    x = double(abs(target));
    timeout = (-0.000000000000750853* pow(x,5)) + (  0.00000000378468 * pow(x,4)) + (-0.00000629527 * pow(x,3)) + (0.00422834* pow(x,2)) + (-0.665814 * x) + 707.21366;    timeout = timeout * (2 - (double(speed)/100.0));

    double voltage;
    double encoderAVG;
    int count = 0;
    //double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        if(abs(target - encoderAVG) < 25){
            setConstants(3, 0, 0);
        } else{
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD); 
        }   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (trueTarget - 360);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);

        if(voltage > 127 * double(speed)/100){
            voltage = 127 * double(speed)/100;
        } else if (voltage < -127 * double(speed)/100){
            voltage = -127 * double(speed)/100;
        }

  if((eyes.get_hue()<40 && eyes.get_hue()>5) && eyes.get_proximity() > 150){
    Intake.move(0);
  }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if(target > 0){
            if((encoderAVG - (target-500)) > 0){
                over = true;
            }
        } else if(((target+500) - encoderAVG) > 0){
        over = true;
        }

        if(over || time2 > timeout){
            break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(imu.get_heading()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}


void driveSortHoldblueC(int target, int speed){

    int timeout = 30000;
    bool over = false;
    double x = 0;
    x = double(abs(target));
    timeout = (-0.000000000000750853* pow(x,5)) + (  0.00000000378468 * pow(x,4)) + (-0.00000629527 * pow(x,3)) + (0.00422834* pow(x,2)) + (-0.665814 * x) + 707.21366;    timeout = timeout * (2 - (double(speed)/100.0));

    double voltage;
    double encoderAVG;
    int count = 0;
    //double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        if(abs(target - encoderAVG) < 25){
            setConstants(3, 0, 0);
        } else{
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD); 
        }   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (trueTarget - 360);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);

        if(voltage > 127 * double(speed)/100){
            voltage = 127 * double(speed)/100;
        } else if (voltage < -127 * double(speed)/100){
            voltage = -127 * double(speed)/100;
        }

   if((eyes.get_hue()<230 && eyes.get_hue()>170) && eyes.get_proximity() > 150){
    Intake.move(0);
    } 

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if(target > 0){
            if((encoderAVG - (target-500)) > 0){
                over = true;
            }
        } else if(((target+500) - encoderAVG) > 0){
        over = true;
        }

        if(over || time2 > timeout){
            break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(imu.get_heading()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}


void driveStraightSlow(int target, int speed) { // RETUNE TIMEOUT!! SLOW PID!

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (-0.000000000000750853* pow(x,5)) + (  0.00000000378468 * pow(x,4)) + (-0.00000629527 * pow(x,3)) + (0.00422834* pow(x,2)) + (-0.665814 * x) + 707.21366;    timeout = timeout * (2 - (double(speed)/100.0));

    double voltage;
    double encoderAVG;
    int count = 0;
   // double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        if(abs(target - encoderAVG) < 25){
            setConstants(3, 0, 0);
        } else{
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD); 
        }   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (trueTarget - 360);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    }else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);

        if(voltage > 127 * double(speed)/100){
            voltage = 127 * double(speed)/100;
        } else if (voltage < -127 * double(speed)/100){
            voltage = -127 * double(speed)/100;
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
           break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(time2));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(LF.get_encoder_units()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}

void driveArcL(double theta, double radius, int timeout, int speed){
    setConstants(STRAIGHT_KI, STRAIGHT_KI, STRAIGHT_KD);


double ltarget = 0;
double rtarget = 0;
double pi =  3.14159265359;
//double init_heading = imu.get_heading();
if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
int count = 0;
time2 = 0;
resetEncoders();

ltarget = double((theta/360) *2 * pi * radius);
rtarget = double((theta / 360) * 2 * pi *(radius + 725)); 

while (true){

if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
double position = imu.get_heading();

if(position > 180){
    position = position - 360;
}
double encoderAVGL = (LF.get_position() + LB.get_position()) /2;
double encoderAVGR = (RB.get_position() + RB.get_position()) /2;
double leftcorrect = -(encoderAVGL * 360) / (2 * pi * radius);

if(((trueTarget + leftcorrect) < 0) && (position > 0)){
    if((position - (trueTarget + leftcorrect) ) >= 180){
        leftcorrect = leftcorrect + 360;
        position = imu.get_heading();
    }
} else if(((trueTarget + leftcorrect) > 0) && (position < 0)){
    if (((trueTarget + leftcorrect) - position) >= 180){
        position = imu.get_heading();
    }
 }
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);


         int voltageL = calcPID(ltarget, encoderAVGL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL); 
    if (voltageL > 127 * double(speed)/100.0){
        voltageL = 127 * double(speed)/100.0;
    }else if(voltageL < -127  * double(speed)/100.0){
        voltageL = -127  * double(speed)/100.0;
    }

    int voltageR = calcPID2(rtarget, encoderAVGR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127 * double(speed)/100.0){
        voltageR = 127 * double(speed)/100.0;
    }else if(voltageR < -127  * double(speed)/100.0){
        voltageR = -127  * double(speed)/100.0;
    }
    
    setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
int fix = calcPID3((trueTarget + leftcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
    if (abs(ltarget - encoderAVGL) <= 25) fix = 0;  
    //fix = 0;
    chasMove( (voltageL + fix), (voltageL + fix ), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));
    if ((abs(ltarget - encoderAVGL) <= 4) && (abs(rtarget - encoderAVGR)<= 4)) count++;
    if (count >= 20  || time2 > timeout){
    trueTarget -= theta;
       break;
    }
     if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "fix: %f           ", float(fix));
        } else if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "position: %f           ", float(position));
        }else if(time2 % 50 == 0){
            con.print(2,0, "trueTarget: %f         ", float(trueTarget + leftcorrect));
        }
        time2 += 10;
        delay(10);
    }   
}

void driveArcR(double theta, double radius, int timeout, int speed){
    setConstants(STRAIGHT_KI, STRAIGHT_KI, STRAIGHT_KD);

  
double ltarget = 0;
double rtarget = 0;
double pi =  3.14159265359;
//double init_heading = imu.get_heading();
if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
int count = 0;
time2 = 0;
resetEncoders();

rtarget = double((theta/360) *2 * pi * radius);
ltarget = double((theta / 360) * 2 * pi *(radius + 725)); 

while (true){

if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
double position = imu.get_heading();

if(position > 180){
    position = position - 360;
}
double encoderAVGL = (LF.get_position() + LB.get_position()) /2;
double encoderAVGR = (RB.get_position() + RB.get_position()) /2;
double rightcorrect = (encoderAVGR * 360) / (2 * pi * radius);

if(((trueTarget + rightcorrect) < 0) && (position > 0)){
    if((position - (trueTarget + rightcorrect) ) >= 180){
        trueTarget = trueTarget + 360;
        position = imu.get_heading();
    }
} else if(((trueTarget + rightcorrect) > 0) && (position < 0)){
    if (((trueTarget + rightcorrect) - position) >= 180){
        position = imu.get_heading();
    }
 }
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
       
         int voltageL = calcPID(ltarget, encoderAVGL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL); 
         if (voltageL > 127 * double(speed)/100.0){
            voltageL = 127 * double(speed)/100.0;
        }else if(voltageL < -127  * double(speed)/100.0){
            voltageL = -127  * double(speed)/100.0;
        }

    int voltageR = calcPID2(rtarget, encoderAVGR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127 * double(speed)/100.0){
        voltageR = 127 * double(speed)/100.0;
    }else if(voltageR < -127  * double(speed)/100.0){
        voltageR = -127  * double(speed)/100.0;
    }
    
    setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
int fix = calcPID3((trueTarget + rightcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
    if (abs(rtarget - encoderAVGR) <= 25) fix = 0;  

    chasMove( (voltageL + fix), (voltageL + fix ), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));
    if ((abs(ltarget - encoderAVGL) <= 4) && (abs(rtarget - encoderAVGR)<= 4)) count++;
    if (count >= 20  || time2 > timeout){
        trueTarget += theta;
       break;
    }
     if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "fix: %f           ", float(fix));
        } else if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "position: %f           ", float(position));
        }else if(time2 % 50 == 0){
            con.print(2,0, "trueTarget: %f         ", float(trueTarget + rightcorrect));
        }
        time2 += 10;
        delay(10);
    }   
}

void driveArcLF(double theta, double radius, int timeout, int speed){

setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);

int true_theta = theta;
double ltarget = 0; 
double rtarget = 0;
double ltargetF = 0; 
double rtargetF = 0;
double pi = 3.14159265359;
//double init_heading = imu.get_heading();
int time = 0;
int count = 0;
bool over = false;
resetEncoders();
ltargetF = double(( theta/360) *2 * pi * radius);
rtargetF = double((theta / 360) * 2 * pi *(radius + 725 ));
if(theta > 0){
theta = theta + 45;
} else {
    theta = theta - 45;
}
ltarget = double(( theta/360) *2 * pi * radius);
rtarget = double((theta / 360) * 2 * pi *(radius + 725 ));
while(true){

if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
double position = imu.get_heading();


if(position > 180){
    position = position - 360;
}
double encoderAvgL = LF.get_position(); 
double encoderAvgR = RB.get_position();
double leftcorrect = -(encoderAvgL * 360) / (2 * pi * radius);

if(((trueTarget + leftcorrect) < 0) && (position > 0)){
        if((position - (trueTarget + leftcorrect) ) >= 180){
            leftcorrect = leftcorrect + 360;
            position = imu.get_heading();
        }
    } else if(((trueTarget + leftcorrect) > 0) && (position < 0)){
        if (((trueTarget + leftcorrect) - position) >= 180){
            position = imu.get_heading();
        }
     }
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
 
    int voltageL = calcPID(ltarget, encoderAvgL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageL > 127 * double(speed)/100.0){
        voltageL = 127 * double(speed)/100.0;
    }else if(voltageL < -127  * double(speed)/100.0){
        voltageL = -127  * double(speed)/100.0;
    }

    int voltageR = calcPID2(rtarget, encoderAvgR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127 * double(speed)/100.0){
        voltageR = 127 * double(speed)/100.0;
    }else if(voltageR < -127  * double(speed)/100.0){
        voltageR = -127  * double(speed)/100.0;
    }

 setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
int fix = calcPID3((trueTarget + leftcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
if (abs(ltarget - encoderAvgL) <= 25) fix = 0;  
   // fix = 0;
        chasMove( (voltageL + fix), (voltageL + fix), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));

         if(abs(trueTarget-position) > true_theta){
        over = true;
    }
        if (theta > 0){
            if ((encoderAvgL - ltargetF) > 0){
                over = true;
            }
        } else {
            if ((ltargetF - encoderAvgL)>0){
                over = true;
            }
        }

        if (over || time > timeout){
            trueTarget -= true_theta;
            break;
        }

     if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "fix: %f           ", float(fix));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(LF.get_encoder_units()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        

        time+= 10;
        delay(10);


    }
}

void driveArcRF(double theta, double radius, int timeout, int speed){
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);

    int true_theta = theta;
bool over = false;
double ltargetF = 0;
double rtargetF = 0;
double ltarget = 0;
double rtarget = 0;
double rightcorrect = 0;
double pi =  3.14159265359;
//double init_heading = imu.get_heading();
if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
int count = 0;
int time2 = 0;
resetEncoders();
rtargetF = double((theta/360) *2 * pi * radius);
ltargetF= double((theta / 360) * 2 * pi *(radius + 725)); 
if(theta > 0){
theta = theta + 45;
} else {
    theta = theta - 45;
}
rtarget = double((theta/360) *2 * pi * radius);
ltarget = double((theta / 360) * 2 * pi *(radius + 725)); 

while (true){

if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
double position = imu.get_heading();

if(position > 180){
    position = position - 360;
}

if(((trueTarget + rightcorrect) < 0) && (position > 0)){
        if((position - (trueTarget + rightcorrect) ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if(((trueTarget + rightcorrect) > 0) && (position < 0)){
        if (((trueTarget + rightcorrect) - position) >= 180){
            position = imu.get_heading();
        }
     }
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
         double encoderAVGL = (LF.get_position() + LB.get_position()) /2;
         double encoderAVGR = (RB.get_position() + RB.get_position()) /2;
         int voltageL = calcPID(ltarget, encoderAVGL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL); 
         if (voltageL > 127 * double(speed)/100.0){
            voltageL = 127 * double(speed)/100.0;
        }else if(voltageL < -127  * double(speed)/100.0){
            voltageL = -127  * double(speed)/100.0;
        }

    int voltageR = calcPID2(rtarget, encoderAVGR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127 * double(speed)/100.0){
        voltageR = 127 * double(speed)/100.0;
    }else if(voltageR < -127  * double(speed)/100.0){
        voltageR = -127  * double(speed)/100.0;
    }
    rightcorrect = (encoderAVGR * 360) / (2 * pi * radius);
        setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
int fix = calcPID3((trueTarget + rightcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
 if (abs(rtarget - encoderAVGR) <= 25) fix = 0;  

    chasMove( (voltageL + fix), (voltageL + fix ), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));

    if(abs(trueTarget-position) > true_theta){
        over = true;
    }
   if (theta > 0){
    if ((encoderAVGR - (rtargetF)) > 0){
        over = true;
    }
   } else {
    if(((rtarget) - encoderAVGR) > 0){
        over = true;
    }
   }
    if (over || time2 > timeout){
        trueTarget += true_theta;
        break;
    }
     if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "fix: %f           ", float(fix));
        } else if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "encodeR %f           ", float(encoderAVGR));
        }else if(time2 % 50 == 0){
            con.print(2,0, "encodeL: %f         ", float(encoderAVGL));
        }
        time2 += 10;
        delay(10);
    }   
} 

void wallResetB(int resetTime){
    int count = 0;
    while (true){
        LF.move(-127);
        LM.move(-127);
        LB.move(-127);
        RF.move(-127);
        RM.move(-127);
        RB.move(-127);
        if (abs(RF.get_actual_velocity()) < 2) count ++;
        if (count >= 20) break;
    }
}

void wallResetF(int resetTime){
    int count = 0;
    while (true){
        LF.move(127);
        LM.move(127);
        LB.move(127);
        RF.move(127);
        RM.move(127);
        RB.move(127);
        if (abs(RF.get_actual_velocity()) < 2) count ++;
        if (count >= 20) break;
    }
}

void Rings(int motorVoltage){
    Intake.move(motorVoltage);
}
