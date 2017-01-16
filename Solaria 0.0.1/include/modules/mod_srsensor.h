#ifndef MOD_SRSENSOR_H
#define MOD_SRSENSOR_H

#include <string>

using namespace std;

class mod_srsensor
{
    public:
        //Constructs
        mod_srsensor();
        mod_srsensor(int id);

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
        int read_target_max()const;
        int read_target()const;
        int read_target_locked()const;
        void write_target_locked(double targets);

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
        int target_max;
        int target;
        int target_locked;
};

#endif // MOD_SRSENSOR_H
