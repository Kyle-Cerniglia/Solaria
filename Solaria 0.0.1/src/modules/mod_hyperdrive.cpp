#include "mod_hyperdrive.h"

#include <string>

using namespace std;

mod_hyperdrive::mod_hyperdrive(){
    modsize = -1;
    damage = -1;
    name = "null";
    intra_power_max = 0;
    intra_power = intra_power_max;
    intra_speed_max = 0;
    intra_speed = intra_speed_max;
    inter_power_max = 0;
    inter_power = inter_power_max;
    inter_speed_max = 0;
    inter_speed = inter_speed_max;
}
mod_hyperdrive::mod_hyperdrive(int id){
    //Test
    if(id == 0){
        modsize = 1;
        damage = 0;
        name = "xhyperdrive";
        intra_power_max = 1;
        intra_power = intra_power_max;
        intra_speed_max = 5;
        intra_speed = intra_speed_max;
        inter_power_max = 2;
        inter_power = inter_power_max;
        inter_speed_max = 0.1;
        inter_speed = inter_speed_max;
    }
    else{
        modsize = -1;
        damage = -1;
        name = "null";
        intra_power_max = 0;
        intra_power = intra_power_max;
        intra_speed_max = 0;
        intra_speed = intra_speed_max;
        inter_power_max = 0;
        inter_power = inter_power_max;
        inter_speed_max = 0;
        inter_speed = inter_speed_max;
    }
}

//Data
int mod_hyperdrive::read_modsize()const{
    return modsize;
}
int mod_hyperdrive::read_damage()const{
    return damage;
}
void mod_hyperdrive::write_damage(int hit){
    switch(hit){
        case -1:
            damage = -1;
            intra_power = 0;
            intra_speed = 0;
            inter_power = 0;
            inter_speed = 0;
            break;

        case 0:
            damage = 0;
            intra_power = intra_power_max;
            intra_speed = intra_speed_max;
            inter_power = inter_power_max;
            inter_speed = inter_speed_max;
            break;

        case 1:
            damage = 1;
            intra_power = intra_power_max * 2.0;
            intra_speed = intra_speed_max / 2.0;
            inter_power = inter_power_max * 2.0;
            inter_speed = inter_speed_max / 2.0;
            break;

        case 2:
            damage = 2;
            intra_power = 0;
            intra_speed = 0;
            inter_power = 0;
            inter_speed = 0;
            break;

        default:
            break;
    }
}
string mod_hyperdrive::read_name()const{
    return name;
}

//Stats
double mod_hyperdrive::read_intra_power_max()const{
    return intra_power_max;
}
double mod_hyperdrive::read_intra_power()const{
    return intra_power;
}
double mod_hyperdrive::read_intra_speed_max()const{
    return intra_speed_max;
}
double mod_hyperdrive::read_intra_speed()const{
    return intra_speed;
}
double mod_hyperdrive::read_inter_power_max()const{
    return inter_power_max;
}
double mod_hyperdrive::read_inter_power()const{
    return inter_power;
}
double mod_hyperdrive::read_inter_speed_max()const{
    return inter_speed_max;
}
double mod_hyperdrive::read_inter_speed()const{
    return inter_speed;
}
