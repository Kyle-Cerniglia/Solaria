#include "interface.h"

#include <uni.h>
#include <windows.h>

using namespace std;

void read_keyboard(uni *key){
    //Other
    key->ESC = GetAsyncKeyState(VK_ESCAPE);
    key->ENTER = GetAsyncKeyState(VK_RETURN);
    key->SPACE = GetAsyncKeyState(VK_SPACE);
    key->LEFT = GetAsyncKeyState(VK_LEFT);
    key->UP = GetAsyncKeyState(VK_UP);
    key->RIGHT = GetAsyncKeyState(VK_RIGHT);
    key->DOWN = GetAsyncKeyState(VK_DOWN);

    //Numbers
    key->k0 = GetAsyncKeyState(0x30);
    key->k1 = GetAsyncKeyState(0x31);
    key->k2 = GetAsyncKeyState(0x32);
    key->k3 = GetAsyncKeyState(0x33);
    key->k4 = GetAsyncKeyState(0x34);
    key->k5 = GetAsyncKeyState(0x35);
    key->k6 = GetAsyncKeyState(0x36);
    key->k7 = GetAsyncKeyState(0x37);
    key->k8 = GetAsyncKeyState(0x38);
    key->k9 = GetAsyncKeyState(0x39);

    //Letters
    key->A = GetAsyncKeyState(0x41);
    key->B = GetAsyncKeyState(0x42);
    key->C = GetAsyncKeyState(0x43);
    key->D = GetAsyncKeyState(0x44);
    key->E = GetAsyncKeyState(0x45);
    key->F = GetAsyncKeyState(0x46);
    key->G = GetAsyncKeyState(0x47);
    key->H = GetAsyncKeyState(0x48);
    key->I = GetAsyncKeyState(0x49);
    key->J = GetAsyncKeyState(0x4A);
    key->K = GetAsyncKeyState(0x4B);
    key->L = GetAsyncKeyState(0x4C);
    key->M = GetAsyncKeyState(0x4D);
    key->N = GetAsyncKeyState(0x4E);
    key->O = GetAsyncKeyState(0x4F);
    key->P = GetAsyncKeyState(0x50);
    key->Q = GetAsyncKeyState(0x51);
    key->R = GetAsyncKeyState(0x52);
    key->S = GetAsyncKeyState(0x53);
    key->T = GetAsyncKeyState(0x54);
    key->U = GetAsyncKeyState(0x55);
    key->V = GetAsyncKeyState(0x56);
    key->W = GetAsyncKeyState(0x57);
    key->X = GetAsyncKeyState(0x58);
    key->Y = GetAsyncKeyState(0x59);
    key->Z = GetAsyncKeyState(0x5A);

    //Functions
    key->F1 = GetAsyncKeyState(0x70);
    key->F2 = GetAsyncKeyState(0x71);
    key->F3 = GetAsyncKeyState(0x72);
    key->F4 = GetAsyncKeyState(0x73);
    key->F5 = GetAsyncKeyState(0x74);
    key->F6 = GetAsyncKeyState(0x75);
    key->F7 = GetAsyncKeyState(0x76);
    key->F8 = GetAsyncKeyState(0x77);
    key->F9 = GetAsyncKeyState(0x78);
    key->F10 = GetAsyncKeyState(0x79);
    key->F11 = GetAsyncKeyState(0x7A);
    key->F12 = GetAsyncKeyState(0x7B);

    //Shift/control/alt
    key->lSHIFT = GetAsyncKeyState(VK_LSHIFT);
    key->rSHIFT = GetAsyncKeyState(VK_RSHIFT);
    key->lCONTROL = GetAsyncKeyState(VK_LCONTROL);
    key->rCONTROL = GetAsyncKeyState(VK_RCONTROL);
    key->ALT = GetAsyncKeyState(VK_MENU);
    return;
}
