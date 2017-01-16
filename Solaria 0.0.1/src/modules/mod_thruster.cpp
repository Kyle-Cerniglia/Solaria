#include "mod_thruster.h"

using namespace std;

mod_thruster::mod_thruster(){
    modsize = -1;
    damage = -1;
    name = "null";
    thrust = 0;
    power = 0;
    return;
}

mod_thruster::mod_thruster(int id){
    switch(id){
        //Test
        case 0:
            modsize = 1;
            damage = 0;
            name = "xthruster";
            thrust_max = 100;
            thrust = thrust_max;
            power_max = 10;
            power = power_max;
            break;

        default:
            modsize = -1;
            damage = -1;
            name = "null";
            thrust_max = 0;
            thrust = thrust_max;
            power_max = 0;
            power = power_max;
            break;
    }
    return;
}

int mod_thruster::read_damage()const{
    return damage;
}

void mod_thruster::write_damage(int hit){
    switch(hit){
        case -1:
            damage = -1;
            thrust = 0;
            power = 0;
            break;

        //Repaired
        case 0:
            damage = 0;
            thrust = thrust_max;
            power = power_max;
            break;

        //Damaged
        case 1:
            damage = 1;
            thrust = thrust_max / 2.0;
            power = power_max * 2;
            break;

        //Destroyed
        case 2:
            damage = 2;
            thrust = 0;
            power = 0;
            break;

        default:
            break;
    }
    return;
}
string mod_thruster::read_name()const{
    return name;
}

double mod_thruster::read_thrust_max()const{
    return thrust_max;
}
double mod_thruster::read_thrust()const{
    return thrust;
}
double mod_thruster::read_power_max()const{
    return power_max;
}
double mod_thruster::read_power()const{
    return power;
}
int mod_thruster::read_modsize()const{
    return modsize;
}
