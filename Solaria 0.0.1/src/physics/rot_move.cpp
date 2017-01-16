#include "physics.h"

#include <cmath>

using namespace std;

void rot_move(double dtime, int id, uni* universal){
    double x = universal->read_ship_pointer(id)->read_rot_velo_x() * dtime;
    double y = universal->read_ship_pointer(id)->read_rot_velo_y() * dtime;
    double z = universal->read_ship_pointer(id)->read_rot_velo_z() * dtime;

    if(universal->C == true){
        universal->read_ship_pointer(id)->write_rot_velo_x(0);
        universal->read_ship_pointer(id)->write_rot_velo_y(0);
        universal->read_ship_pointer(id)->write_rot_velo_z(0);
        universal->read_ship_pointer(id)->write_vec_pos_x(1, 0, 0);
        universal->read_ship_pointer(id)->write_vec_pos_y(0, 1, 0);
        universal->read_ship_pointer(id)->write_vec_pos_z(0, 0, 1);
    }

    //X-axis Z rotation
    universal->read_ship_pointer(id)->write_vec_pos_z(universal->read_ship_pointer(id)->read_vec_pos_z(0) * cos(x) - (universal->read_ship_pointer(id)->read_vec_pos_x(1) * universal->read_ship_pointer(id)->read_vec_pos_z(2) - universal->read_ship_pointer(id)->read_vec_pos_x(2) * universal->read_ship_pointer(id)->read_vec_pos_z(1)) * sin(x),
                                                      universal->read_ship_pointer(id)->read_vec_pos_z(1) * cos(x) + (universal->read_ship_pointer(id)->read_vec_pos_x(0) * universal->read_ship_pointer(id)->read_vec_pos_z(2) - universal->read_ship_pointer(id)->read_vec_pos_x(2) * universal->read_ship_pointer(id)->read_vec_pos_z(0)) * sin(x),
                                                      universal->read_ship_pointer(id)->read_vec_pos_z(2) * cos(x) - (universal->read_ship_pointer(id)->read_vec_pos_x(0) * universal->read_ship_pointer(id)->read_vec_pos_z(1) - universal->read_ship_pointer(id)->read_vec_pos_x(1) * universal->read_ship_pointer(id)->read_vec_pos_z(0)) * sin(x));
    //X-axis Y rotation
    universal->read_ship_pointer(id)->write_vec_pos_y(universal->read_ship_pointer(id)->read_vec_pos_y(0) * cos(x) - (universal->read_ship_pointer(id)->read_vec_pos_x(1) * universal->read_ship_pointer(id)->read_vec_pos_y(2) - universal->read_ship_pointer(id)->read_vec_pos_x(2) * universal->read_ship_pointer(id)->read_vec_pos_y(1)) * sin(x),
                                                      universal->read_ship_pointer(id)->read_vec_pos_y(1) * cos(x) + (universal->read_ship_pointer(id)->read_vec_pos_x(0) * universal->read_ship_pointer(id)->read_vec_pos_y(2) - universal->read_ship_pointer(id)->read_vec_pos_x(2) * universal->read_ship_pointer(id)->read_vec_pos_y(0)) * sin(x),
                                                      universal->read_ship_pointer(id)->read_vec_pos_y(2) * cos(x) - (universal->read_ship_pointer(id)->read_vec_pos_x(0) * universal->read_ship_pointer(id)->read_vec_pos_y(1) - universal->read_ship_pointer(id)->read_vec_pos_x(1) * universal->read_ship_pointer(id)->read_vec_pos_y(0)) * sin(x));
    //Y-axis Z rotation
    universal->read_ship_pointer(id)->write_vec_pos_z(universal->read_ship_pointer(id)->read_vec_pos_z(0) * cos(y) - (universal->read_ship_pointer(id)->read_vec_pos_y(1) * universal->read_ship_pointer(id)->read_vec_pos_z(2) - universal->read_ship_pointer(id)->read_vec_pos_y(2) * universal->read_ship_pointer(id)->read_vec_pos_z(1)) * sin(y),
                                                      universal->read_ship_pointer(id)->read_vec_pos_z(1) * cos(y) + (universal->read_ship_pointer(id)->read_vec_pos_y(0) * universal->read_ship_pointer(id)->read_vec_pos_z(2) - universal->read_ship_pointer(id)->read_vec_pos_y(2) * universal->read_ship_pointer(id)->read_vec_pos_z(0)) * sin(y),
                                                      universal->read_ship_pointer(id)->read_vec_pos_z(2) * cos(y) - (universal->read_ship_pointer(id)->read_vec_pos_y(0) * universal->read_ship_pointer(id)->read_vec_pos_z(1) - universal->read_ship_pointer(id)->read_vec_pos_y(1) * universal->read_ship_pointer(id)->read_vec_pos_z(0)) * sin(y));
    //Y-axis X rotation
    universal->read_ship_pointer(id)->write_vec_pos_x(universal->read_ship_pointer(id)->read_vec_pos_x(0) * cos(y) - (universal->read_ship_pointer(id)->read_vec_pos_y(1) * universal->read_ship_pointer(id)->read_vec_pos_x(2) - universal->read_ship_pointer(id)->read_vec_pos_y(2) * universal->read_ship_pointer(id)->read_vec_pos_x(1)) * sin(y),
                                                      universal->read_ship_pointer(id)->read_vec_pos_x(1) * cos(y) + (universal->read_ship_pointer(id)->read_vec_pos_y(0) * universal->read_ship_pointer(id)->read_vec_pos_x(2) - universal->read_ship_pointer(id)->read_vec_pos_y(2) * universal->read_ship_pointer(id)->read_vec_pos_x(0)) * sin(y),
                                                      universal->read_ship_pointer(id)->read_vec_pos_x(2) * cos(y) - (universal->read_ship_pointer(id)->read_vec_pos_y(0) * universal->read_ship_pointer(id)->read_vec_pos_x(1) - universal->read_ship_pointer(id)->read_vec_pos_y(1) * universal->read_ship_pointer(id)->read_vec_pos_x(0)) * sin(y));
    //Z-axis Y rotation
    universal->read_ship_pointer(id)->write_vec_pos_y(universal->read_ship_pointer(id)->read_vec_pos_y(0) * cos(z) - (universal->read_ship_pointer(id)->read_vec_pos_z(1) * universal->read_ship_pointer(id)->read_vec_pos_y(2) - universal->read_ship_pointer(id)->read_vec_pos_z(2) * universal->read_ship_pointer(id)->read_vec_pos_y(1)) * sin(z),
                                                      universal->read_ship_pointer(id)->read_vec_pos_y(1) * cos(z) + (universal->read_ship_pointer(id)->read_vec_pos_z(0) * universal->read_ship_pointer(id)->read_vec_pos_y(2) - universal->read_ship_pointer(id)->read_vec_pos_z(2) * universal->read_ship_pointer(id)->read_vec_pos_y(0)) * sin(z),
                                                      universal->read_ship_pointer(id)->read_vec_pos_y(2) * cos(z) - (universal->read_ship_pointer(id)->read_vec_pos_z(0) * universal->read_ship_pointer(id)->read_vec_pos_y(1) - universal->read_ship_pointer(id)->read_vec_pos_z(1) * universal->read_ship_pointer(id)->read_vec_pos_y(0)) * sin(z));
    //Z-axis X rotation
    universal->read_ship_pointer(id)->write_vec_pos_x(universal->read_ship_pointer(id)->read_vec_pos_x(0) * cos(z) - (universal->read_ship_pointer(id)->read_vec_pos_z(1) * universal->read_ship_pointer(id)->read_vec_pos_x(2) - universal->read_ship_pointer(id)->read_vec_pos_z(2) * universal->read_ship_pointer(id)->read_vec_pos_x(1)) * sin(z),
                                                      universal->read_ship_pointer(id)->read_vec_pos_x(1) * cos(z) + (universal->read_ship_pointer(id)->read_vec_pos_z(0) * universal->read_ship_pointer(id)->read_vec_pos_x(2) - universal->read_ship_pointer(id)->read_vec_pos_z(2) * universal->read_ship_pointer(id)->read_vec_pos_x(0)) * sin(z),
                                                      universal->read_ship_pointer(id)->read_vec_pos_x(2) * cos(z) - (universal->read_ship_pointer(id)->read_vec_pos_z(0) * universal->read_ship_pointer(id)->read_vec_pos_x(1) - universal->read_ship_pointer(id)->read_vec_pos_z(1) * universal->read_ship_pointer(id)->read_vec_pos_x(0)) * sin(z));
    return;
}
