#include "physics.h"

#include <cmath>

#include "ship.h"
#include "uni.h"

using namespace std;

double accel_r(ship *shipv);

void rot_accel(double dtime, int id, uni *universal){

    //Reset
    if(universal->C == true){
        universal->read_ship_pointer(id)->write_rot_velo_x(0);
        universal->read_ship_pointer(id)->write_rot_velo_y(0);
        universal->read_ship_pointer(id)->write_rot_velo_z(0);
    }

    //DownPitch -X
    if(universal->UP == false && universal->DOWN == true){
        universal->read_ship_pointer(id)->write_rot_velo_x(universal->read_ship_pointer(id)->read_rot_velo_x() - accel_r(universal->read_ship_pointer(id)) * dtime);
    }
    //Up Pitch +X
    else if(universal->UP == true && universal->DOWN == false){
        universal->read_ship_pointer(id)->write_rot_velo_x(universal->read_ship_pointer(id)->read_rot_velo_x() + accel_r(universal->read_ship_pointer(id)) * dtime);
    }

    //Right Yaw -Y
    if(universal->LEFT == false && universal->RIGHT == true){
        universal->read_ship_pointer(id)->write_rot_velo_y(universal->read_ship_pointer(id)->read_rot_velo_y() - accel_r(universal->read_ship_pointer(id)) * dtime);
    }
    //Left Yaw +Y
    else if(universal->LEFT == true && universal->RIGHT == false){
        universal->read_ship_pointer(id)->write_rot_velo_y(universal->read_ship_pointer(id)->read_rot_velo_y() + accel_r(universal->read_ship_pointer(id)) * dtime);
    }

    //CW Roll -Z
    if(universal->Q == false && universal->E == true){
        universal->read_ship_pointer(id)->write_rot_velo_z(universal->read_ship_pointer(id)->read_rot_velo_z() + accel_r(universal->read_ship_pointer(id)) * dtime);
    }
    //CCW Roll +Z
    else if(universal->Q == true && universal->E == false){
        universal->read_ship_pointer(id)->write_rot_velo_z(universal->read_ship_pointer(id)->read_rot_velo_z() - accel_r(universal->read_ship_pointer(id)) * dtime);
    }
    return;
}

double accel_r(ship *shipv){
    double torque = 0;
    double moment = 0;
    int i = 0;
    while(i < 8){
        if(shipv->read_mod_thruster(i) != NULL){
            torque += shipv->read_mod_thruster(i)->read_thrust() * (shipv->read_dim_z() / 2);
        }
        i++;
    }
    i = 0;
    moment = (shipv->read_mass() * pow(shipv->read_dim_z(), 2)) / 12.0;//Moment for a rod/plank rotating about its center
    return (torque / moment);
}
