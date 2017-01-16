#include "physics.h"

using namespace std;

void lin_move(double dtime, int id, uni* universal){
    double i = 0;
    double j = 0;
    double k = 0;

    if(universal->C == true){
        universal->read_ship_pointer(id)->write_loc(0, 0, 0);
    }

    //Vector sums
    i = universal->read_ship_pointer(id)->read_vec_velo_x(0) + universal->read_ship_pointer(id)->read_vec_velo_y(0) + universal->read_ship_pointer(id)->read_vec_velo_z(0);
    j = universal->read_ship_pointer(id)->read_vec_velo_x(1) + universal->read_ship_pointer(id)->read_vec_velo_y(1) + universal->read_ship_pointer(id)->read_vec_velo_z(1);
    k = universal->read_ship_pointer(id)->read_vec_velo_x(2) + universal->read_ship_pointer(id)->read_vec_velo_y(2) + universal->read_ship_pointer(id)->read_vec_velo_z(2);

    universal->read_ship_pointer(id)->write_loc(i * dtime + universal->read_ship_pointer(id)->read_loc_x(), j * dtime + universal->read_ship_pointer(id)->read_loc_y(), k * dtime + universal->read_ship_pointer(id)->read_loc_z());
    return;
}
