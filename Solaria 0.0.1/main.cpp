#define M_PI 3.14159265358979323846

#include <iostream>
#include <fstream>
#include <cstdio>
#include <windows.h>
#include <sstream>
#include <vector>
#include <ctime>

#include "ship.h"
#include "print_ship_info.h"
#include "consolecmd.h"
#include "uni.h"
#include "interface.h"

using namespace std;

double dtime = 0;

int main()
{
    stringstream input_s;
    string input;
    int playerid = 0;
    uni universal;
    bool leave = false;
    /*
    double dtime = 0;
    double btime = 0;
    double etime = 0;
    clock_t start;
*/
    //etime = ((clock() - start) / (double)CLOCKS_PER_SEC);
    dtime = 0.01;

    system("mode 650");

    while(leave == false){
        //btime = clock();
        getline(cin, input);
        leave = consolecmd(&universal, playerid, input, dtime);
        //etime = clock();
        //dtime = ((etime - btime) / (double)CLOCKS_PER_SEC);
        //cout << dtime << endl;
    }
    leave = false;
    cout << "Closing Solaria" << endl;
    return 0;
}
