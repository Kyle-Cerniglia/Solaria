#include "ship.h"

#define M_PI 3.14159265358979323846

#define L 0.8660254038
#define M 0.7071067812
#define S 0.5

#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>

using namespace std;

//Constructs
ship::ship(){
    //Networking
    id = -1;

    //Mesh
    mesh = "null";

    //Text
    name = "null";

    //Location
    gal_x = 0;
    gal_y = 0;
    gal_z = 0;
    loc_x = 0;
    loc_y = 0;
    loc_z = 0;

    //Physical
    shipsize = -1;
    cargo = 0;
    dim_x = 0;
    dim_y = 0;
    dim_z = 0;
    mass = 0;
    shield_max = 0;
    shield_hp = 0;
    armor_thickness = 1;
    armor_hardness = 1;

    //Vectors
    vec_pos_x[0] = 0;
    vec_pos_x[1] = 0;
    vec_pos_x[2] = 0;
    vec_pos_y[0] = 0;
    vec_pos_y[1] = 0;
    vec_pos_y[2] = 0;
    vec_pos_z[0] = 0;
    vec_pos_z[1] = 0;
    vec_pos_z[2] = 0;

    vec_velo_x[0] = 0;
    vec_velo_x[1] = 0;
    vec_velo_x[2] = 0;
    vec_velo_y[0] = 0;
    vec_velo_y[1] = 0;
    vec_velo_y[2] = 0;
    vec_velo_z[0] = 0;
    vec_velo_z[1] = 0;
    vec_velo_z[2] = 0;

    //Rotation
    rot_velo_x = 0;
    rot_velo_y = 0;
    rot_velo_z = 0;

    //Slots
    shield = NULL;
    armor = NULL;
    reactor = NULL;
    capacitor = NULL;
    hyperdrive = NULL;
    inertial = NULL;
    lrsensor = NULL;
    srsensor = NULL;

    thruster.resize(8);
    thruster.at(0) = NULL;
    thruster.at(1) = NULL;
    thruster.at(2) = NULL;
    thruster.at(3) = NULL;
    thruster.at(4) = NULL;
    thruster.at(5) = NULL;
    thruster.at(6) = NULL;
    thruster.at(7) = NULL;

    hardpoint.resize(8);
    hardpoint.at(0) = NULL;
    hardpoint.at(1) = NULL;
    hardpoint.at(2) = NULL;
    hardpoint.at(3) = NULL;
    hardpoint.at(4) = NULL;
    hardpoint.at(5) = NULL;
    hardpoint.at(6) = NULL;
    hardpoint.at(7) = NULL;
    return;
}
ship::ship(int id, int playerid){
    //Test
    if(id == 0){
        //Networking
        id = playerid;

        //Mesh
        mesh = "xmesh";

        //Text
        name = "xship";

        //Location
        gal_x = 0;
        gal_y = 0;
        gal_z = 0;
        loc_x = 0;
        loc_y = 0;
        loc_z = 0;

        //Physical
        shipsize = 1;
        cargo = 10;
        dim_x = 1;
        dim_y = 1;
        dim_z = 1;
        mass = 5000;
        shield_max = 100;
        shield_hp = 100;
        armor_thickness = 1;
        armor_hardness = 1;

        //Vectors
        vec_pos_x[0] = 1;
        vec_pos_x[1] = 0;
        vec_pos_x[2] = 0;
        vec_pos_y[0] = 0;
        vec_pos_y[1] = 1;
        vec_pos_y[2] = 0;
        vec_pos_z[0] = 0;
        vec_pos_z[1] = 0;
        vec_pos_z[2] = 1;

        vec_velo_x[0] = 0;
        vec_velo_x[1] = 0;
        vec_velo_x[2] = 0;
        vec_velo_y[0] = 0;
        vec_velo_y[1] = 0;
        vec_velo_y[2] = 0;
        vec_velo_z[0] = 0;
        vec_velo_z[1] = 0;
        vec_velo_z[2] = 0;

        //Rotation
        rot_velo_x = 0;
        rot_velo_y = 0;
        rot_velo_z = 0;

        //Slots
        //Allocate======================================================================
        mod_shield *shield0 = new mod_shield(0);
        shield = shield0;
        mod_armor *armor0 = new mod_armor(0);
        armor = armor0;
        mod_reactor *reactor0 = new mod_reactor(0);
        reactor = reactor0;
        mod_capacitor *capacitor0 = new mod_capacitor(0);
        capacitor = capacitor0;
        mod_hyperdrive *hyperdrive0 = new mod_hyperdrive(0);
        hyperdrive = hyperdrive0;
        mod_inertial *inertial0 = new mod_inertial(0);
        inertial = inertial0;
        mod_lrsensor *lrsensor0 = new mod_lrsensor(0);
        lrsensor = lrsensor0;
        mod_srsensor *srsensor0 = new mod_srsensor(0);
        srsensor = srsensor0;

        thruster.resize(8);
        mod_thruster *thrust0 = new mod_thruster(0);
        thruster.at(0) = thrust0;
        mod_thruster *thrust1 = new mod_thruster(0);
        thruster.at(1) = thrust1;
        mod_thruster *thrust2 = new mod_thruster(0);
        thruster.at(2) = thrust2;
        mod_thruster *thrust3 = new mod_thruster(0);
        thruster.at(3) = thrust3;
        mod_thruster *thrust4 = new mod_thruster(0);
        thruster.at(4) = thrust4;
        mod_thruster *thrust5 = new mod_thruster(0);
        thruster.at(5) = thrust5;
        mod_thruster *thrust6 = new mod_thruster(0);
        thruster.at(6) = thrust6;
        mod_thruster *thrust7 = new mod_thruster(0);
        thruster.at(7) = thrust7;

        hardpoint.resize(8);
        mod_hardpoint *hardpoint0 = new mod_hardpoint(0);
        hardpoint.at(0) = hardpoint0;
        mod_hardpoint *hardpoint1 = new mod_hardpoint(0);
        hardpoint.at(1) = hardpoint1;
        mod_hardpoint *hardpoint2 = new mod_hardpoint(0);
        hardpoint.at(2) = hardpoint2;
        mod_hardpoint *hardpoint3 = new mod_hardpoint(0);
        hardpoint.at(3) = hardpoint3;
        mod_hardpoint *hardpoint4 = new mod_hardpoint(0);
        hardpoint.at(4) = hardpoint4;
        mod_hardpoint *hardpoint5 = new mod_hardpoint(0);
        hardpoint.at(5) = hardpoint5;
        mod_hardpoint *hardpoint6 = new mod_hardpoint(0);
        hardpoint.at(6) = hardpoint6;
        mod_hardpoint *hardpoint7 = new mod_hardpoint(0);
        hardpoint.at(7) = hardpoint7;
    }
    else{
        //Networking
        id = playerid;

        //Mesh
        mesh = "null";

        //Text
        name = "null";

        //Location
        gal_x = 0;
        gal_y = 0;
        gal_z = 0;
        loc_x = 0;
        loc_y = 0;
        loc_z = 0;

        //Physical
        shipsize = -1;
        cargo = 0;
        dim_x = 0;
        dim_y = 0;
        dim_z = 0;
        mass = 0;
        shield_max = 0;
        shield_hp = 0;
        armor_thickness = 1;
        armor_hardness = 1;

        //Vectors
        vec_pos_x[0] = 0;
        vec_pos_x[1] = 0;
        vec_pos_x[2] = 0;
        vec_pos_y[0] = 0;
        vec_pos_y[1] = 0;
        vec_pos_y[2] = 0;
        vec_pos_z[0] = 0;
        vec_pos_z[1] = 0;
        vec_pos_z[2] = 0;

        vec_velo_x[0] = 0;
        vec_velo_x[1] = 0;
        vec_velo_x[2] = 0;
        vec_velo_y[0] = 0;
        vec_velo_y[1] = 0;
        vec_velo_y[2] = 0;
        vec_velo_z[0] = 0;
        vec_velo_z[1] = 0;
        vec_velo_z[2] = 0;

        //Rotation
        rot_velo_x = 0;
        rot_velo_y = 0;
        rot_velo_z = 0;

        //Slots
        shield = NULL;
        armor = NULL;
        reactor = NULL;
        capacitor = NULL;
        hyperdrive = NULL;
        inertial = NULL;
        lrsensor = NULL;
        srsensor = NULL;

        thruster.resize(8);
        thruster.at(0) = NULL;
        thruster.at(1) = NULL;
        thruster.at(2) = NULL;
        thruster.at(3) = NULL;
        thruster.at(4) = NULL;
        thruster.at(5) = NULL;
        thruster.at(6) = NULL;
        thruster.at(7) = NULL;

        hardpoint.resize(8);
        hardpoint.at(0) = NULL;
        hardpoint.at(1) = NULL;
        hardpoint.at(2) = NULL;
        hardpoint.at(3) = NULL;
        hardpoint.at(4) = NULL;
        hardpoint.at(5) = NULL;
        hardpoint.at(6) = NULL;
        hardpoint.at(7) = NULL;
    }
}

//Networking
int ship::read_id()const{
    return id;
}

//Mesh
string ship::read_mesh()const{
    return mesh;
}
void ship::write_mesh(string mesh){
    this->mesh.clear();
    this->mesh = mesh;
    return;
}

//Text
string ship::read_name()const{
    return name;
}

//Physical
int ship::read_shipsize()const{
    return shipsize;
}
double ship::read_cargo()const{
    return cargo;
}
void ship::write_cargo(double input){
    cargo += input;
    return;
}
double ship::read_gal_x()const{
    return gal_x;
}
double ship::read_gal_y()const{
    return gal_y;
}
double ship::read_gal_z()const{
    return gal_z;
}
void ship::write_gal(double x, double y, double z){
    gal_x = x;
    gal_y = y;
    gal_z = z;
    return;
}
double ship::read_loc_x()const{
    return loc_x;
}
double ship::read_loc_y()const{
    return loc_y;
}
double ship::read_loc_z()const{
    return loc_z;
}
void ship::write_loc(double x, double y, double z){
    loc_x = x;
    loc_y = y;
    loc_z = z;
    return;
}

//Vectors
double ship::read_vec_pos_x(int index)const{
    return vec_pos_x[index];
}
void ship::write_vec_pos_x(double i, double j, double k){
    vec_pos_x[0] = i;
    vec_pos_x[1] = j;
    vec_pos_x[2] = k;
    return;
}
double ship::read_vec_pos_y(int index)const{
    return vec_pos_y[index];
}
void ship::write_vec_pos_y(double i, double j, double k){
    vec_pos_y[0] = i;
    vec_pos_y[1] = j;
    vec_pos_y[2] = k;
    return;
}
double ship::read_vec_pos_z(int index)const{
    return vec_pos_z[index];
}
void ship::write_vec_pos_z(double i, double j, double k){
    vec_pos_z[0] = i;
    vec_pos_z[1] = j;
    vec_pos_z[2] = k;
    return;
}

double ship::read_vec_velo_x(int index)const{
    return vec_velo_x[index];
}
void ship::write_vec_velo_x(double i, double j, double k){
    vec_velo_x[0] = i;
    vec_velo_x[1] = j;
    vec_velo_x[2] = k;
    return;
}
double ship::read_vec_velo_y(int index)const{
    return vec_velo_y[index];
}
void ship::write_vec_velo_y(double i, double j, double k){
    vec_velo_y[0] = i;
    vec_velo_y[1] = j;
    vec_velo_y[2] = k;
    return;
}
double ship::read_vec_velo_z(int index)const{
    return vec_velo_z[index];
}
void ship::write_vec_velo_z(double i, double j, double k){
    vec_velo_z[0] = i;
    vec_velo_z[1] = j;
    vec_velo_z[2] = k;
    return;
}

//Rotation
double ship::read_rot_velo_x()const{
    return rot_velo_x;
}
void ship::write_rot_velo_x(double rot){
    rot_velo_x = rot;
    return;
}
double ship::read_rot_velo_y()const{
    return rot_velo_y;
}
void ship::write_rot_velo_y(double rot){
    rot_velo_y = rot;
    return;
}
double ship::read_rot_velo_z()const{
    return rot_velo_z;
}
void ship::write_rot_velo_z(double rot){
    rot_velo_z = rot;
    return;
}

//Base stats
double ship::read_dim_x()const{
    return dim_x;
}
double ship::read_dim_y()const{
    return dim_y;
}
double ship::read_dim_z()const{
    return dim_z;
}
double ship::read_mass()const{
    return mass;
}
void ship::write_mass(double mass){
    this->mass = mass;
    return;
}
double ship::read_shield_max()const{
    return shield_max;
}
void ship::write_shield_max(double shieldmax){
    this->shield_max = shieldmax;
}
double ship::read_shield_hp()const{
    return shield_hp;
}
void ship::read_shield_hp(double hp){
    this->shield_hp = hp;
}
double ship::read_armor_thickness()const{
    return armor_thickness;
}
void ship::write_armor_thickness(double thickness){
    this->armor_thickness = thickness;
}
double ship::read_armor_hardness()const{
    return armor_hardness;
}
void ship::write_armor_hardness(double hardness){
    this->armor_hardness = hardness;
}

//Slots
mod_shield* ship::read_mod_shield()const{
    return shield;
}
void ship::write_mod_shield(mod_shield* mod){
    shield = mod;
    return;
}
mod_armor* ship::read_mod_armor()const{
    return armor;
}
void ship::write_mod_armor(mod_armor* mod){
    armor = mod;
    return;
}
mod_reactor* ship::read_mod_reactor()const{
    return reactor;
}
void ship::write_mod_reactor(mod_reactor* mod){
    reactor = mod;
}
mod_capacitor* ship::read_mod_capacitor()const{
    return capacitor;
}
void ship::write_mod_capacitor(mod_capacitor* mod){
    capacitor = mod;
}
mod_hyperdrive* ship::read_mod_hyperdrive()const{
    return hyperdrive;
}
void ship::write_mod_hyperdrive(mod_hyperdrive* mod){
    hyperdrive = mod;
}
mod_inertial* ship::read_mod_inertial()const{
    return inertial;
}
void ship::write_mod_inertial(mod_inertial* mod){
    inertial = mod;
}
mod_lrsensor* ship::read_mod_lrsensor()const{
    return lrsensor;
}
void ship::write_mod_lrsensor(mod_lrsensor* mod){
    lrsensor = mod;
}
mod_srsensor* ship::read_mod_srsensor()const{
    return srsensor;
}
void ship::write_mod_srsensor(mod_srsensor* mod){
    srsensor = mod;
}
mod_thruster* ship::read_mod_thruster(int index)const{
    return thruster.at(index);
}
void ship::write_mod_thruster(mod_thruster* mod, int index){
    thruster.at(index) = mod;
}
mod_hardpoint* ship::read_mod_hardpoint(int index)const{
    return hardpoint.at(index);
}
void ship::wite_mod_hardpoint(mod_hardpoint* mod, int index){
    hardpoint.at(index) = mod;
}

//Functions
void ship::acceleration(){
    return;
}
void ship::rotation(){
    return;
}
void ship::movement(){
    return;
}
void ship::recharge_capacitor(){
    return;
}
void ship::recharge_shield(){
    return;
}
int ship::hitbox_collision(){
    return 0;
}
void ship::hardpoint_fire(int index){
    return;
}
void ship::hardpoint_reload(int index){
    return;
}
