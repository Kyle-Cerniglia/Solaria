#include "mod_inertial.h"
#include <cmath>

using namespace std;

//Constructs
mod_inertial::mod_inertial(){
    modsize = -1;
    damage = -1;
    name = "null";
    speed_max = 0;
    speed = speed_max;
    rotspeed_max = 0;
    rotspeed = rotspeed_max;
}
mod_inertial::mod_inertial(int id){
    //Test
    if(id == 0){
        modsize = 1;
        damage = 0;
        name = "xinertial";
        speed_max = 100;
        speed = speed_max;
        rotspeed_max = M_PI;
        rotspeed = rotspeed_max;
    }
    else{
        modsize = -1;
        damage = -1;
        name = "null";
        speed_max = 0;
        speed = speed_max;
        rotspeed_max = 0;
        rotspeed = rotspeed_max;
    }
}

//Data
int mod_inertial::read_modsize()const{
    return modsize;
}
int mod_inertial::read_damage()const{
    return damage;
}
void mod_inertial::write_damage(int hit){
    switch(hit){
        case -1:
            damage = -1;
            speed = 10;
            rotspeed = 0.1;
            break;

        case 0:
            damage = 0;
            speed = speed_max;
            rotspeed = rotspeed_max;
            break;

        case 1:
            damage = 1;
            speed = speed_max / 2.0;
            rotspeed = rotspeed_max / 2.0;
            break;

        case 2:
            damage = 2;
            speed = 10;
            rotspeed = 0.1;
            break;

        default:
            break;
    }
}
string mod_inertial::read_name()const{
    return name;
}

//Stats
double mod_inertial::read_speed_max()const{
    return speed_max;
}
double mod_inertial::read_speed()const{
    return speed;
}
double mod_inertial::read_rotspeed_max()const{
    return rotspeed_max;
}
double mod_inertial::read_rotspeed()const{
    return rotspeed;
}
