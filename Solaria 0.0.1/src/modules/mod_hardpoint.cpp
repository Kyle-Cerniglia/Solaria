#include "mod_hardpoint.h"

using namespace std;

//Constructs
mod_hardpoint::mod_hardpoint(){
    type = -1;
    modsize = -1;
    name = "null";
    ammorack_max = 0;
    ammorack = 0;
    power_max = 0;
    power = 0;
    force_max = 0;
    force = 0;
    accuracy_max = 0;
    accuracy = 0;
    damage = -1;
}

mod_hardpoint::mod_hardpoint(int id){
    //Test
    if(id == 0){
        type = 1;
        modsize = 1;
        name = "xhardpoint";
        ammorack_max = 100;
        ammorack = 100;
        power_max = 10;
        power = 10;
        force_max = 100;
        force = 100;
        accuracy_max = 1;
        accuracy = 1;
        damage = 0;
    }
    else{
        type = -1;
        modsize = -1;
        name = "null";
        ammorack_max = 0;
        ammorack = 0;
        power_max = 0;
        power = 0;
        force_max = 0;
        force = 0;
        accuracy_max = 0;
        accuracy = 0;
        damage = -1;
    }
}

//Data
int mod_hardpoint::read_type()const{
    return type;
}
void mod_hardpoint::write_type(int type){
    this->type = type;
}
int mod_hardpoint::read_modsize()const{
    return modsize;
}
void mod_hardpoint::write_modsize(int modsize){
    this->modsize = modsize;
}
int mod_hardpoint::read_ammorack_max()const{
    return ammorack_max;
}
void mod_hardpoint::write_ammorack_max(int ammomax){
    ammorack_max = ammorack;
}
int mod_hardpoint::read_ammorack()const{
    return ammorack;
}
void mod_hardpoint::write_ammorack(int ammo){
    ammorack = ammo;
}

//Stats
double mod_hardpoint::read_power_max()const{
    return power_max;
}
void mod_hardpoint::write_power_max(double powermax){
    power_max = powermax;
}
double mod_hardpoint::read_power()const{
    return power;
}
void mod_hardpoint::write_power(double power){
    this->power = power;
}
double mod_hardpoint::read_force_max()const{
    return force_max;
}
void mod_hardpoint::write_force_max(double forcemax){
    force_max = forcemax;
}
double mod_hardpoint::read_force()const{
    return force;
}
void mod_hardpoint::write_force(double force){
    this->force = force;
}
double mod_hardpoint::read_accuracy_max()const{
    return accuracy_max;
}
void mod_hardpoint::write_accuracy_max(double accuracymax){
    accuracy_max = accuracymax;
}
double mod_hardpoint::read_accuracy()const{
    return accuracy;
}
void mod_hardpoint::write_accuracy(double accuracy){
    this->accuracy = accuracy;
}
string mod_hardpoint::read_name()const{
    return name;
}

//Functions
int mod_hardpoint::read_damage()const{
    return damage;
}
void mod_hardpoint::write_damage(int hit){
    switch(hit){
        case -1:
            damage = -1;
            power = 0;
            force = 0;
            accuracy = 0;
            break;

        case 0:
            damage = 0;
            power = power_max;
            force = force_max;
            accuracy = accuracy_max;
            break;

        case 1:
            damage = 1;
            power = power_max * 2;
            force = force_max / 2.0;
            accuracy = accuracy_max / 2.0;
            break;

        case 2:
            damage = 2;
            power = 0;
            force = 0;
            accuracy = 0;
            break;

        default:
            break;
    }
}
