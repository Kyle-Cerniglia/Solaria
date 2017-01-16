#ifndef MOD_HARDPOINT_H
#define MOD_HARDPOINT_H

#include <string>

using namespace std;

class mod_hardpoint
{
    public:
        //Construsts
        mod_hardpoint();
        mod_hardpoint(int id);

        //Data
        int read_type()const;
        void write_type(int type);
        int read_modsize()const;
        void write_modsize(int modsize);
        int read_ammorack_max()const;
        void write_ammorack_max(int ammomax);
        int read_ammorack()const;
        void write_ammorack(int ammo);
        string read_name()const;

        //Stats
        double read_power_max()const;
        void write_power_max(double powermax);
        double read_power()const;
        void write_power(double power);
        double read_force_max()const;
        void write_force_max(double forcemax);
        double read_force()const;
        void write_force(double force);
        double read_accuracy_max()const;
        void write_accuracy_max(double accuracymax);
        double read_accuracy()const;
        void write_accuracy(double accuracy);

        //Functions
        int read_damage()const;
        void write_damage(int hit);

    private:
        //Data
        int modsize;
        int damage;
        int type;
        string name;

        //Stats
        int ammorack_max;
        int ammorack;
        double power_max;
        double power;
        double force_max;
        double force;
        double accuracy_max;
        double accuracy;

};

#endif // MOD_HARDPOINT_H
