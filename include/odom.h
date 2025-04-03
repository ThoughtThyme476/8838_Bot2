#include "api.h"
#include "main.h"

#ifndef ODOH
#define ODOH

#define FORWARD_OFFSET 0
#define IMU_THERSHOLD 0.0001
#define HEADING_CUTOFF 0.0001745329
#define SIDEWAYS_OFFEST 0.6

extern void Odometry();
extern void Odometry2();
extern void driveToPoint(double xTarget, double yTarget, double preferredHeading);
extern void boomerang(double xTarget, double yTarget);
extern void setPosition(float xcoord, float ycoord, float heading);

extern float x_pos;
extern float y_pos;


#endif