#ifndef MOD_THRUSTER_H
#define MOD_THRUSTER_H

#include <string>

using namespace std;

class mod_thruster
{
    public:
        //Constructs
        mod_thruster();
        mod_thruster(int id);

        //Data
        int read_modsize()const;
        int read_damage()const;
        void write_damage(int hit);
        string read_name()const;

        //Stats
        double read_thrust()const;
        double read_thrust_max()const;
        double read_power()const;
        double read_power_max()const;

    private:
        //Data
        int modsize;
        int damage;
        string name;

        //Stats
        double thrust_max;
        double thrust;
        double power_max;
        double power;
};

#endif // MOD_THRUSTER_H
