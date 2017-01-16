#ifndef MOD_LRSENSOR_H
#define MOD_LRSENSOR_H

#include <string>

using namespace std;

class mod_lrsensor
{
    public:
        //Constructs
        mod_lrsensor();
        mod_lrsensor(int id);

        //Data
        int read_modtype()const;
        int read_damage()const;
        void write_damage(int hit);
        string read_name()const;

        //Stats
        double read_range_max()const;
        double read_range()const;
        double read_time_max()const;
        double read_time()const;
        double read_accuracy_max()const;
        double read_accuracy()const;

    private:
        //Data
        int modtype;
        int damage;
        string name;

        //Stats
        double range_max;
        double range;
        double time_max;
        double time;
        double accuracy_max;
        double accuracy;
};

#endif // MOD_LRSENSOR_H
