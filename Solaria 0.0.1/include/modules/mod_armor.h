#ifndef MOD_ARMOR_H
#define MOD_ARMOR_H

#include <string>

using namespace std;

class mod_armor
{
    public:
        //Constructs
        mod_armor();
        mod_armor(int id);

        //Data
        int read_modsize()const;
        int read_damage()const;
        void write_damage(int hit);
        string read_name()const;

        //Stats
        double read_hardness_max()const;
        double read_hardness()const;
        double read_thickness_max()const;
        double read_thickness()const;

    private:
        //Data
        int modsize;
        int damage;
        string name;

        //Stats
        double hardness_max;
        double hardness;
        double thickness_max;
        double thickness;
};

#endif // MOD_ARMOR_H
