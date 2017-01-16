#ifndef MOD_SHIELD_H
#define MOD_SHIELD_H

#include <string>

using namespace std;

class mod_shield
{
    public:
        //Constructs
        mod_shield();
        mod_shield(int id);

        //Data
        int read_modsize()const;
        int read_damage()const;
        void write_damage(int hit);
        string read_name()const;

        //Stats
        double read_field_max()const;
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
        double field_max;
        double power_max;
        double power;
};

#endif // MOD_SHIELD_H
