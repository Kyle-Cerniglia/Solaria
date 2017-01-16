#ifndef MOD_HYPERDRIVE_H
#define MOD_HYPERDRIVE_H

#include <string>

using namespace std;

class mod_hyperdrive
{
    public:
        //Constructs
        mod_hyperdrive();
        mod_hyperdrive(int id);

        //Data
        int read_modsize()const;
        int read_damage()const;
        void write_damage(int hit);
        string read_name()const;

        //Stats
        double read_intra_power_max()const;
        double read_intra_power()const;
        double read_intra_speed_max()const;
        double read_intra_speed()const;
        double read_inter_power_max()const;
        double read_inter_power()const;
        double read_inter_speed_max()const;
        double read_inter_speed()const;

    private:
        //Data
        int modsize;
        int damage;
        string name;

        //Stats
        double intra_power_max;
        double intra_power;
        double intra_speed_max;
        double intra_speed;

        double inter_power_max;
        double inter_power;
        double inter_speed_max;
        double inter_speed;
};

#endif // MOD_HYPERDRIVE_H
