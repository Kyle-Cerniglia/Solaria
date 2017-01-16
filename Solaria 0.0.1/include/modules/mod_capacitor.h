#ifndef MOD_CAPACITOR_H
#define MOD_CAPACITOR_H

#include <string>

using namespace std;

class mod_capacitor
{
    public:
        //Constructs
        mod_capacitor();
        mod_capacitor(int id);

        //Data
        int read_modsize()const;
        int read_damage()const;
        void write_damage(int hit);
        string read_name()const;

        //Stats
        double read_capacitance_max()const;
        double read_power_max()const;
        double read_power()const;
        void write_power(int pow);

        //Functions
        //void recharge(double)

    private:
        //Data
        int modsize;
        int damage;
        string name;

        //Stats
        double capacitance_max;
        double power_max;
        double power;
};

#endif // MOD_CAPACITOR_H
