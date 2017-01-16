#include "mod_armor.h"

#include <string>

using namespace std;

//Constructs
mod_armor::mod_armor(){
    modsize = -1;
    damage = -1;
    name = "null";
    hardness_max = 0;
    hardness = hardness_max;
    thickness_max = 0;
    thickness = thickness_max;
}
mod_armor::mod_armor(int id){
    //Test
    if(id == 0){
        modsize = 1;
        damage = 0;
        name = "xarmor";
        hardness_max = 2;
        hardness = hardness_max;
        thickness_max = 2;
        thickness = thickness_max;
    }
    else{
        modsize = -1;
        damage = -1;
        name = "null";
        hardness_max = 0;
        hardness = hardness_max;
        thickness_max = 0;
        thickness = thickness_max;
    }
}

//Data
int mod_armor::read_modsize()const{
    return modsize;
}
int mod_armor::read_damage()const{
    return damage;
}
void mod_armor::write_damage(int hit){
    damage = hit;
}
string mod_armor::read_name()const{
    return name;
}

//Stats
double mod_armor::read_hardness_max()const{
    return hardness_max;
}
double mod_armor::read_hardness()const{
    return hardness;
}
double mod_armor::read_thickness_max()const{
    return thickness_max;
}
double mod_armor::read_thickness()const{
    return thickness;
}
