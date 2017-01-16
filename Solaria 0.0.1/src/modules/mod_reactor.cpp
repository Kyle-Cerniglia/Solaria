#include "mod_reactor.h"

#include <string>

using namespace std;

//Construsts
mod_reactor::mod_reactor(){
    modsize = -1;
    damage = -1;
    name = "null";
    power_max = 0;
    power = power_max;
}
mod_reactor::mod_reactor(int id){
    //Test
    if(id == 0){
        modsize = 1;
        damage = 0;
        name = "xreactor";
        power_max = 10;
        power = power_max;
    }
    else{
        modsize = -1;
        damage = -1;
        name = "null";
        power_max = 0;
        power = power_max;
    }
}

//Data
int mod_reactor::read_modsize()const{
    return modsize;
}
int mod_reactor::read_damage()const{
    return damage;
}
void mod_reactor::write_damage(int hit){
    switch(hit){
        case -1:
            damage = -1;
            power = 0;
            break;

        case 0:
            damage = 0;
            power = power_max;
            break;

        case 1:
            damage = 1;
            power = power_max / 2.0;
            break;

        case 2:
            damage = 2;
            power = 0;
            break;

        default:
            break;
    }
}
string mod_reactor::read_name()const{
    return name;
}

//Stats
double mod_reactor::read_power_max()const{
    return power_max;
}
double mod_reactor::read_power()const{
    return power;
}
