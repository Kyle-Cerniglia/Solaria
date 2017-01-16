#ifndef PHYSICS_H
#define PHYSICS_H
#define M_PI 3.14159265358979323846

#include "ship.h"
#include "uni.h"

using namespace std;

void lin_accel(double dtime, int id, uni *universal);
void lin_move(double dtime, int id, uni *universal);
void rot_accel(double dtime, int id, uni *universal);
void rot_move(double dtime, int id, uni *universal);

#endif // PHYSICS_H
