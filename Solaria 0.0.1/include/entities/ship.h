#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <vector>

#include "mod_armor.h"
#include "mod_capacitor.h"
#include "mod_hardpoint.h"
#include "mod_hyperdrive.h"
#include "mod_inertial.h"
#include "mod_lrsensor.h"
#include "mod_reactor.h"
#include "mod_shield.h"
#include "mod_srsensor.h"
#include "mod_thruster.h"

using namespace std;

class ship
{
    public:
        //Constructs
        ship();
        ship(int id, int playerid);

        //Networking
        int read_id()const;

        //Mesh
        string read_mesh()const;
        void write_mesh(string mesh);

        //Tect
        string read_name()const;

        //Physical
        int read_shipsize()const;
        double read_cargo()const;
        void write_cargo(double input);
        double read_gal_x()const;
        double read_gal_y()const;
        double read_gal_z()const;
        void write_gal(double x, double y, double z);
        double read_loc_x()const;
        double read_loc_y()const;
        double read_loc_z()const;
        void write_loc(double x, double y, double z);

        //Vectors
        double read_vec_pos_x(int index)const;
        void write_vec_pos_x(double i, double j, double k);
        double read_vec_pos_y(int index)const;
        void write_vec_pos_y(double i, double j, double k);
        double read_vec_pos_z(int index)const;
        void write_vec_pos_z(double i, double j, double k);

        double read_vec_velo_x(int index)const;
        void write_vec_velo_x(double i, double j, double k);
        double read_vec_velo_y(int index)const;
        void write_vec_velo_y(double i, double j, double k);
        double read_vec_velo_z(int index)const;
        void write_vec_velo_z(double i, double j, double k);

        //Rotation
        double read_rot_velo_x()const;
        void write_rot_velo_x(double rot);
        double read_rot_velo_y()const;
        void write_rot_velo_y(double rot);
        double read_rot_velo_z()const;
        void write_rot_velo_z(double rot);

        //Base stats
        double read_dim_x()const;
        double read_dim_y()const;
        double read_dim_z()const;
        double read_mass()const;
        void write_mass(double mass);
        double read_shield_max()const;
        void write_shield_max(double shieldmax);
        double read_shield_hp()const;
        void read_shield_hp(double hp);
        double read_armor_thickness()const;
        void write_armor_thickness(double thickness);
        double read_armor_hardness()const;
        void write_armor_hardness(double hardness);

        //Slots
        mod_shield* read_mod_shield()const;
        void write_mod_shield(mod_shield* mod);
        mod_armor* read_mod_armor()const;
        void write_mod_armor(mod_armor* mod);
        mod_reactor* read_mod_reactor()const;
        void write_mod_reactor(mod_reactor* mod);
        mod_capacitor* read_mod_capacitor()const;
        void write_mod_capacitor(mod_capacitor* mod);
        mod_hyperdrive* read_mod_hyperdrive()const;
        void write_mod_hyperdrive(mod_hyperdrive* mod);
        mod_inertial* read_mod_inertial()const;
        void write_mod_inertial(mod_inertial* mod);
        mod_lrsensor* read_mod_lrsensor()const;
        void write_mod_lrsensor(mod_lrsensor* mod);
        mod_srsensor* read_mod_srsensor()const;
        void write_mod_srsensor(mod_srsensor* mod);
        mod_thruster* read_mod_thruster(int index)const;
        void write_mod_thruster(mod_thruster* mod, int index);
        mod_hardpoint* read_mod_hardpoint(int index)const;
        void wite_mod_hardpoint(mod_hardpoint* mod, int index);

        //Functions
        void acceleration();
        void rotation();
        void movement();
        void recharge_capacitor();
        void recharge_shield();
        int hitbox_collision();
        void hardpoint_fire(int index);
        void hardpoint_reload(int index);

    private:
        //Networking
        int id;

        //Mesh
        string mesh;

        //Test
        string name;

        //Location
        double gal_x;
        double gal_y;
        double gal_z;
        double loc_x;
        double loc_y;
        double loc_z;

        //Physical
        int shipsize;
        double cargo;
        double dim_x;
        double dim_y;
        double dim_z;
        double mass;
        double shield_max;
        double shield_hp;
        double armor_thickness;
        double armor_hardness;

        //Vectors
        double vec_pos_x[3];
        double vec_pos_y[3];
        double vec_pos_z[3];

        double vec_velo_x[3];
        double vec_velo_y[3];
        double vec_velo_z[3];

        //Rotation
        double rot_velo_x;
        double rot_velo_y;
        double rot_velo_z;

        //Slots
        mod_shield* shield;
        mod_armor* armor;
        mod_reactor* reactor;
        mod_capacitor* capacitor;
        mod_hyperdrive* hyperdrive;
        mod_inertial* inertial;
        mod_lrsensor* lrsensor;
        mod_srsensor* srsensor;
        vector<mod_thruster*> thruster;
        vector<mod_hardpoint*> hardpoint;
};

#endif // SHIP_H
