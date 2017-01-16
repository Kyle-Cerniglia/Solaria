#ifndef MOD_REACTOR_H
#define MOD_REACTOR_H

#include <string>

using namespace std;

class mod_reactor
{
    public:
        //Constructs
        mod_reactor();
        mod_reactor(int id);

        //Data
        int read_modsize()const;
        int read_damage()const;
        void write_damage(int hit);
        string read_name()const;

        //Stats
        double read_power_max()const;
        double read_power()const;

    private:
        //Data
        int modsize;
        int damage;
        string name;

        //Stats
        double power_max;
        double power;
};

#endif // MOD_REACTOR_H
