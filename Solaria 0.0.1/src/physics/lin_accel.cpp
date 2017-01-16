#include "physics.h"

#include <cmath>
#include <iostream>

#include "ship.h"
#include "uni.h"

using namespace std;

double accel_f(ship *shipv);

void lin_accel(double dtime, int id, uni *universal){
    double i = 0;
    double j = 0;
    double k = 0;
    double hypo_i = 0;
    double hypo_x = 0;
    double hypo_y = 0;
    double hypo_z = 0;
    double dot = 0;

    //Reset
    if(universal->C == true){
        universal->read_ship_pointer(id)->write_vec_velo_x(0, 0, 0);
        universal->read_ship_pointer(id)->write_vec_velo_y(0, 0, 0);
        universal->read_ship_pointer(id)->write_vec_velo_z(0, 0, 0);
    }

    //Down -X
    if(universal->D == false && universal->A == true){
        hypo_i = sqrt(pow(universal->read_ship_pointer(id)->read_vec_velo_x(0), 2) + pow(universal->read_ship_pointer(id)->read_vec_velo_x(1), 2) + pow(universal->read_ship_pointer(id)->read_vec_velo_x(2), 2));
        dot = universal->read_ship_pointer(id)->read_vec_pos_x(0) * (universal->read_ship_pointer(id)->read_vec_velo_x(0) / hypo_i) + universal->read_ship_pointer(id)->read_vec_pos_x(1) * (universal->read_ship_pointer(id)->read_vec_velo_x(1) / hypo_i) + universal->read_ship_pointer(id)->read_vec_pos_x(2) * (universal->read_ship_pointer(id)->read_vec_velo_x(2) / hypo_i);
        if(dot > 0){
            hypo_x = hypo_i - accel_f(universal->read_ship_pointer(id)) * dtime;
        }
        else if(dot < 0){
            hypo_x = -hypo_i - accel_f(universal->read_ship_pointer(id)) * dtime;
        }
        else{
            hypo_x = -hypo_i - accel_f(universal->read_ship_pointer(id)) * dtime;
        }
    }
    //Up +X
    else if(universal->D == true && universal->A == false){
        hypo_i = sqrt(pow(universal->read_ship_pointer(id)->read_vec_velo_x(0), 2) + pow(universal->read_ship_pointer(id)->read_vec_velo_x(1), 2) + pow(universal->read_ship_pointer(id)->read_vec_velo_x(2), 2));
        dot = universal->read_ship_pointer(id)->read_vec_pos_x(0) * (universal->read_ship_pointer(id)->read_vec_velo_x(0) / hypo_i) + universal->read_ship_pointer(id)->read_vec_pos_x(1) * (universal->read_ship_pointer(id)->read_vec_velo_x(1) / hypo_i) + universal->read_ship_pointer(id)->read_vec_pos_x(2) * (universal->read_ship_pointer(id)->read_vec_velo_x(2) / hypo_i);
        if(dot > 0){
            hypo_x = hypo_i + accel_f(universal->read_ship_pointer(id)) * dtime;
        }
        else if(dot < 0){
            hypo_x = -hypo_i + accel_f(universal->read_ship_pointer(id)) * dtime;
        }
        else{
            hypo_x = -hypo_i + accel_f(universal->read_ship_pointer(id)) * dtime;
        }
    }

    //Down -Y
    if(universal->lSHIFT == false && universal->ALT == true){
        hypo_i = sqrt(pow(universal->read_ship_pointer(id)->read_vec_velo_y(0), 2) + pow(universal->read_ship_pointer(id)->read_vec_velo_y(1), 2) + pow(universal->read_ship_pointer(id)->read_vec_velo_y(2), 2));
        dot = universal->read_ship_pointer(id)->read_vec_pos_y(0) * (universal->read_ship_pointer(id)->read_vec_velo_y(0) / hypo_i) + universal->read_ship_pointer(id)->read_vec_pos_y(1) * (universal->read_ship_pointer(id)->read_vec_velo_y(1) / hypo_i) + universal->read_ship_pointer(id)->read_vec_pos_y(2) * (universal->read_ship_pointer(id)->read_vec_velo_y(2) / hypo_i);
        if(dot > 0){
            hypo_y = hypo_i - accel_f(universal->read_ship_pointer(id)) * dtime;
        }
        else if(dot < 0){
            hypo_y = -hypo_i - accel_f(universal->read_ship_pointer(id)) * dtime;
        }
        else{
            hypo_y = -hypo_i - accel_f(universal->read_ship_pointer(id)) * dtime;
        }
    }
    //Up +Y
    else if(universal->lSHIFT == true && universal->ALT == false){
        hypo_i = sqrt(pow(universal->read_ship_pointer(id)->read_vec_velo_y(0), 2) + pow(universal->read_ship_pointer(id)->read_vec_velo_y(1), 2) + pow(universal->read_ship_pointer(id)->read_vec_velo_y(2), 2));
        dot = universal->read_ship_pointer(id)->read_vec_pos_y(0) * (universal->read_ship_pointer(id)->read_vec_velo_y(0) / hypo_i) + universal->read_ship_pointer(id)->read_vec_pos_y(1) * (universal->read_ship_pointer(id)->read_vec_velo_y(1) / hypo_i) + universal->read_ship_pointer(id)->read_vec_pos_y(2) * (universal->read_ship_pointer(id)->read_vec_velo_y(2) / hypo_i);
        if(dot > 0){
            hypo_y = hypo_i + accel_f(universal->read_ship_pointer(id)) * dtime;
        }
        else if(dot < 0){
            hypo_y = -hypo_i + accel_f(universal->read_ship_pointer(id)) * dtime;
        }
        else{
            hypo_y = -hypo_i + accel_f(universal->read_ship_pointer(id)) * dtime;
        }
    }

    //Backwards -Z
    if(universal->W == false && universal->S == true){
        hypo_i = sqrt(pow(universal->read_ship_pointer(id)->read_vec_velo_z(0), 2) + pow(universal->read_ship_pointer(id)->read_vec_velo_z(1), 2) + pow(universal->read_ship_pointer(id)->read_vec_velo_z(2), 2));
        dot = universal->read_ship_pointer(id)->read_vec_pos_z(0) * (universal->read_ship_pointer(id)->read_vec_velo_z(0) / hypo_i) + universal->read_ship_pointer(id)->read_vec_pos_z(1) * (universal->read_ship_pointer(id)->read_vec_velo_z(1) / hypo_i) + universal->read_ship_pointer(id)->read_vec_pos_z(2) * (universal->read_ship_pointer(id)->read_vec_velo_z(2) / hypo_i);
        if(dot > 0){
            hypo_z = hypo_i - accel_f(universal->read_ship_pointer(id)) * dtime;
        }
        else if(dot < 0){
            hypo_z = -hypo_i - accel_f(universal->read_ship_pointer(id)) * dtime;
        }
        else{
            hypo_z = -hypo_i - accel_f(universal->read_ship_pointer(id)) * dtime;
        }
    }
    //Forward +Z
    else if(universal->W == true && universal->S == false){
        hypo_i = sqrt(pow(universal->read_ship_pointer(id)->read_vec_velo_z(0), 2) + pow(universal->read_ship_pointer(id)->read_vec_velo_z(1), 2) + pow(universal->read_ship_pointer(id)->read_vec_velo_z(2), 2));
        dot = universal->read_ship_pointer(id)->read_vec_pos_z(0) * (universal->read_ship_pointer(id)->read_vec_velo_z(0) / hypo_i) + universal->read_ship_pointer(id)->read_vec_pos_z(1) * (universal->read_ship_pointer(id)->read_vec_velo_z(1) / hypo_i) + universal->read_ship_pointer(id)->read_vec_pos_z(2) * (universal->read_ship_pointer(id)->read_vec_velo_z(2) / hypo_i);
        if(dot > 0){
            hypo_z = hypo_i + accel_f(universal->read_ship_pointer(id)) * dtime;
        }
        else if(dot < 0){
            hypo_z = -hypo_i + accel_f(universal->read_ship_pointer(id)) * dtime;
        }
        else{
            hypo_z = -hypo_i + accel_f(universal->read_ship_pointer(id)) * dtime;
        }
    }

    //X
    if(universal->D == true || universal->A == true){
        i = hypo_x * universal->read_ship_pointer(id)->read_vec_pos_x(0);
        j = hypo_x * universal->read_ship_pointer(id)->read_vec_pos_x(1);
        k = hypo_x * universal->read_ship_pointer(id)->read_vec_pos_x(2);
        universal->read_ship_pointer(id)->write_vec_velo_x(i, j, k);
    }
    //Y
    if(universal->lSHIFT == true || universal->ALT == true){
        i = hypo_y * universal->read_ship_pointer(id)->read_vec_pos_y(0);
        j = hypo_y * universal->read_ship_pointer(id)->read_vec_pos_y(1);
        k = hypo_y * universal->read_ship_pointer(id)->read_vec_pos_y(2);
        universal->read_ship_pointer(id)->write_vec_velo_y(i, j, k);
    }
    //Z
    if(universal->W == true || universal->S == true){
        i = hypo_z * universal->read_ship_pointer(id)->read_vec_pos_z(0);
        j = hypo_z * universal->read_ship_pointer(id)->read_vec_pos_z(1);
        k = hypo_z * universal->read_ship_pointer(id)->read_vec_pos_z(2);
        universal->read_ship_pointer(id)->write_vec_velo_z(i, j, k);
    }
    return;
}

double accel_f(ship *shipv){
    double thrust = 0;
    int i = 0;
    while(i < 8){
        if(shipv->read_mod_thruster(i) != NULL){
            thrust += shipv->read_mod_thruster(i)->read_thrust();
        }
        i++;
    }
    i = 0;
    return (thrust / shipv->read_mass());
}
