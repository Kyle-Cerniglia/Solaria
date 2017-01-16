#ifndef MOD_INERTIAL_H
#define MOD_INERTIAL_H
#define M_PI 3.14159265358979323846

#include <string>

using namespace std;

class mod_inertial
{
    public:
        //Constructs
        mod_inertial();
        mod_inertial(int id);

        //Data
        int read_modsize()const;
        int read_damage()const;
        void write_damage(int hit);
        string read_name()const;

        //Stats
        double read_speed_max()const;
        double read_speed()const;
        double read_rotspeed_max()const;
        double read_rotspeed()const;

    private:
        //Data
        int modsize;
        int damage;
        string name;

        //Stats
        double speed_max;
        double speed;
        double rotspeed_max;
        double rotspeed;
};

#endif // MOD_INERTIAL_H
