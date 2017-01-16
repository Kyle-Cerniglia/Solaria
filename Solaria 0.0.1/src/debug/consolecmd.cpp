#include "consolecmd.h"

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <windows.h>
#include <cstdbool>
#include <ctime>

#include "ship.h"
#include "print_ship_info.h"
#include "uni.h"
#include "physics.h"
#include "interface.h"

using namespace std;

bool consolecmd(uni *universal, int playerid, string input, double dtime){
    stringstream decomp;
    decomp << input;
    string group[4];
    int intt = 0;
    int countt = 0;
    bool exitt = false;
    double ddtime = dtime;
    double btime = 0;
    double etime = 0;

    decomp >> group[0];
    decomp >> group[1];
    decomp >> group[2];
    decomp >> group[3];

    //consolecmd class ping test
    if(group[0] == "ping"){
        cout << "ping success" << endl;
    }

    //Print
    else if(group[0] == "print"){
        if(group[1] == "ship"){
            if(group[2] == "all"){
                while(intt < universal->read_ship_size()){
                    if(universal->read_ship_pointer(intt) != NULL){
                        countt++;
                    }
                    intt++;
                }
                cout << "Number of ships: " << countt << endl;
                countt = 0;
                intt = 0;
            }
            else{
                intt = stoi(group[2]);
                if(intt < universal->read_ship_size() && intt >= 0 && universal->read_ship_pointer(intt) != NULL){
                    print_ship_info(universal->read_ship_pointer(intt));
                }
                else{
                    cout << "Ship is not valid" << endl;
                }
            }
            intt = 0;
        }
    }

    //Entity creation
    else if(group[0] == "create" && group[1] == "ship"){
        if(group[1] == "ship"){
            intt = stoi(group[2]);
            intt = universal->add_ship(playerid, intt);
            cout << universal->read_ship_pointer(intt)->read_name() << " created, ID: " << intt << endl;
            intt = 0;
        }
    }

    //Ship deletion
    else if(group[0] == "delete"){
        if(group[1] == "ship"){
            intt = stoi(group[2]);
            if(intt < universal->read_ship_size() && intt >= 0){
                cout << universal->read_ship_pointer(intt)->read_name() << " deleted" << endl;
                universal->delete_ship(intt);
            }
            else{
                cout << "Ship is not valid" << endl;
            }
        }
        intt = 0;
    }

    //Simulation testing
    else if(group[0] == "sim"){
        intt = stoi(group[1]);
        if(intt < universal->read_ship_size() && intt >= 0 && universal->read_ship_pointer(intt) != NULL){
            read_keyboard(universal);
            while(exitt == false){
                btime = clock();
                system("cls");
                read_keyboard(universal);
                exitt = universal->ESC;
                lin_accel(ddtime, intt, universal);
                lin_move(ddtime, intt, universal);
                rot_accel(ddtime, intt, universal);
                rot_move(ddtime, intt, universal);

                cout << "Loc: " << universal->read_ship_pointer(intt)->read_loc_x() << "," << universal->read_ship_pointer(intt)->read_loc_y() << "," << universal->read_ship_pointer(intt)->read_loc_z() << endl;
                cout << "XPos: " << universal->read_ship_pointer(intt)->read_vec_pos_x(0) << "," << universal->read_ship_pointer(intt)->read_vec_pos_x(1) << "," << universal->read_ship_pointer(intt)->read_vec_pos_x(2) << endl;
                cout << "YPos: " << universal->read_ship_pointer(intt)->read_vec_pos_y(0) << "," << universal->read_ship_pointer(intt)->read_vec_pos_y(1) << "," << universal->read_ship_pointer(intt)->read_vec_pos_y(2) << endl;
                cout << "ZPos: " << universal->read_ship_pointer(intt)->read_vec_pos_z(0) << "," << universal->read_ship_pointer(intt)->read_vec_pos_z(1) << "," << universal->read_ship_pointer(intt)->read_vec_pos_z(2) << endl;

                etime = clock();
                ddtime = ((etime - btime) / (double)CLOCKS_PER_SEC);
            }
            read_keyboard(universal);
        }
        else{
            cout << "Ship is not valid" << endl;
        }
    }

    //Clear console
    else if(group[0] == "clear"){
        system("cls");
    }

    //Exit consolecmd
    else if(group[0] == "close"){
        system("cls");
        return true;
    }

    //Quit program
    else if(group[0] == "quit"){
        cout << "Closing Solaria" << endl;
        exit(0);
    }

    else{
        cout << group[0] << group[1] << group[2] << group[3] << " is not a valid command" << endl;
    }
    return false;
}
