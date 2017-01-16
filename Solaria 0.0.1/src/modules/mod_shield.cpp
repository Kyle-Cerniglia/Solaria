#include "mod_shield.h"

#include <string>

using namespace std;

//Constructs
mod_shield::mod_shield(){
    modsize = -1;
    damage = -1;
    name = "null";
    field_max = 0;
    power_max = field_max;
    power = power_max;
}
mod_shield::mod_shield(int id){
    //Test
    if(id == 0){
        modsize = 1;
        damage = 0;
        name = "xshield";
        field_max = 100;
        power_max = field_max;
        power = power_max;
    }
    else{
        modsize = -1;
        damage = -1;
        name = "null";
        field_max = 0;
        power_max = field_max;
        power = power_max;
    }
}

//Data
int mod_shield::read_modsize()const{
    return modsize;
}
int mod_shield::read_damage()const{
    return damage;
}
void mod_shield::write_damage(int hit){
    switch(hit){
        case -1:
            damage = -1;
            power_max = 0;
            power = power_max;
            break;

        case 0:
            damage = 0;
            power_max = field_max;
            power = power;
            break;

        case 1:
            damage = 1;
            power_max = field_max / 2.0;
            power /= 2;
            break;

        case 2:
            damage = 2;
            power_max = 0;
            power = power_max;
            break;

        default:
            break;
    }
}
string mod_shield::read_name()const{
    return name;
}

//Stats
double mod_shield::read_field_max()const{
    return field_max;
}
double mod_shield::read_power_max()const{
    return power_max;
}
double mod_shield::read_power()const{
    return power;
}
void mod_shield::write_power(int pow){
    power = pow;
}

//Functions
//void mod_shield::recharge(double){}
