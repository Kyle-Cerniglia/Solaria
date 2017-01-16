#ifndef UNI_H
#define UNI_H

#include <vector>
#include <cstdbool>

#include "ship.h"

using namespace std;

class uni
{
    public:
        uni();
        int add_ship(int playerid, int const_id);
        void delete_ship(int id);
        ship* read_ship_pointer(int id)const;
        int read_ship_size()const;

        //Keys
        //Other
        bool ESC;
        bool ENTER;
        bool SPACE;
        bool LEFT;
        bool UP;
        bool RIGHT;
        bool DOWN;
        //Numbers
        bool k0;
        bool k1;
        bool k2;
        bool k3;
        bool k4;
        bool k5;
        bool k6;
        bool k7;
        bool k8;
        bool k9;
        //Letters
        bool A;
        bool B;
        bool C;
        bool D;
        bool E;
        bool F;
        bool G;
        bool H;
        bool I;
        bool J;
        bool K;
        bool L;
        bool M;
        bool N;
        bool O;
        bool P;
        bool Q;
        bool R;
        bool S;
        bool T;
        bool U;
        bool V;
        bool W;
        bool X;
        bool Y;
        bool Z;
        //Functions
        bool F1;
        bool F2;
        bool F3;
        bool F4;
        bool F5;
        bool F6;
        bool F7;
        bool F8;
        bool F9;
        bool F10;
        bool F11;
        bool F12;
        //Shift/control/alt
        bool lSHIFT;
        bool rSHIFT;
        bool lCONTROL;
        bool rCONTROL;
        bool ALT;

    private:
        vector<ship*> shipv;
};

#endif // UNI_H
