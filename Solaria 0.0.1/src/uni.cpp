#include "uni.h"

#include <vector>
#include <cstdbool>

using namespace std;

uni::uni(){}

int uni::add_ship(int playerid, int const_id){
    int unsigned i = 0;
    while(i < shipv.size()){
        if(shipv.at(i) == NULL){
            ship *shipv_p = new ship(const_id, playerid);
            shipv.at(i) = shipv_p;
            return (i);
        }
        i++;
    }
    i = shipv.size();
    shipv.resize(i + 1);
    ship *shipv_p = new ship(const_id, playerid);
    shipv.at(i) = shipv_p;
    return (i);
}
void uni::delete_ship(int id){
    int i = shipv.size();
    delete shipv.at(id);
    shipv.at(id) = NULL;

    if(shipv.at(0) == NULL && i == 1){
        shipv.resize(0);
    }
    else{
        while(shipv.at(i - 1) == NULL && i > 1){
            shipv.resize(i - 1);
        i--;
        }
    }
    return;
}
ship* uni::read_ship_pointer(int id)const{
    return shipv.at(id);
}
int uni::read_ship_size()const{
    return shipv.size();
}
