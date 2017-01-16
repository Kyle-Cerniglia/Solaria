#include "mod_srsensor.h"

#include <string>

using namespace std;

//Constructs
mod_srsensor::mod_srsensor(){
    modtype = -1;
    damage = -1;
    name = "name";
    range_max = 0;
    range = range_max;
    time_max = 0;
    time = time_max;
    accuracy_max = 0;
    accuracy = accuracy_max;
    target_max = 0;
    target = target_max;
    target_locked = 0;
}
mod_srsensor::mod_srsensor(int id){
    //Test
    if(id == 0){
        modtype = 1;
        damage = 0;
        name = "xsrsensor";
        range_max = 1000;
        range = range_max;
        time_max = 5;
        time = time_max;
        accuracy_max = 1;
        accuracy = accuracy_max;
        target_max = 1;
        target = target_max;
        target_locked = 0;
    }
    else{
        modtype = -1;
        damage = -1;
        name = "null";
        range_max = 0;
        range = range_max;
        time_max = 0;
        time = time_max;
        accuracy_max = 0;
        accuracy = accuracy_max;
        target_max = 0;
        target = target_max;
        target_locked = 0;
    }
}

//Data
int mod_srsensor::read_modtype()const{
    return modtype;
}
int mod_srsensor::read_damage()const{
    return damage;
}
void mod_srsensor::write_damage(int hit){
    switch(hit){
        case -1:
            damage = -1;
            range = 0;
            time = 0;
            accuracy = 0;
            break;

        case 0:
            damage = 0;
            range = range_max;
            time = time_max;
            accuracy = accuracy_max;
            break;

        case 1:
            damage = 1;
            range = range_max / 2.0;
            time = time_max * 2.0;
            accuracy = accuracy_max / 2.0;
            break;

        case 2:
            damage = 2;
            range = 0;
            time = 0;
            accuracy = 0;
            break;

        default:
            break;
    }
}
string mod_srsensor::read_name()const{
    return name;
}

//Stats
double mod_srsensor::read_range_max()const{
    return range_max;
}
double mod_srsensor::read_range()const{
    return range;
}
double mod_srsensor::read_time_max()const{
    return time_max;
}
double mod_srsensor::read_time()const{
    return time;
}
double mod_srsensor::read_accuracy_max()const{
    return accuracy_max;
}
double mod_srsensor::read_accuracy()const{
    return accuracy;
}
int mod_srsensor::read_target_max()const{
    return target_max;
}
int mod_srsensor::read_target()const{
    return target;
}
int mod_srsensor::read_target_locked()const{
    return target_locked;
}
void mod_srsensor::write_target_locked(double targets){
    target_locked = targets;
}
