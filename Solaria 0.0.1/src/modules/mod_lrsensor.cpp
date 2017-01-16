#include "mod_lrsensor.h"

using namespace std;

//Constructs
mod_lrsensor::mod_lrsensor(){
    modtype = -1;
    damage = -1;
    name = "null";
    range_max = 0;
    range = range_max;
    time_max = 0;
    time = time_max;
    accuracy_max = 0;
    accuracy = accuracy_max;
}
mod_lrsensor::mod_lrsensor(int id){
    //Test
    if(id == 0){
        modtype = 1;
        damage = 0;
        name = "xlrsensor";
        range_max = 5;
        range = range_max;
        time_max = 60;
        time = time_max;
        accuracy_max = 1;
        accuracy = accuracy_max;
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
    }
}
string mod_lrsensor::read_name()const{
    return name;
}

//Data
int mod_lrsensor::read_modtype()const{
    return modtype;
}
int mod_lrsensor::read_damage()const{
    return damage;
}
void mod_lrsensor::write_damage(int hit){
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

//Stats
double mod_lrsensor::read_range_max()const{
    return range_max;
}
double mod_lrsensor::read_range()const{
    return range;
}
double mod_lrsensor::read_time_max()const{
    return time_max;
}
double mod_lrsensor::read_time()const{
    return time;
}
double mod_lrsensor::read_accuracy_max()const{
    return accuracy_max;
}
double mod_lrsensor::read_accuracy()const{
    return accuracy;
}
