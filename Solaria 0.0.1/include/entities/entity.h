#ifndef ENTITY_H
#define ENTITY_H

#include <string>

using namespace std;

class entity
{
    public:
        //Constructs
        entity();

        //Networking
        int read_id()const;

        //Mesh
        string read_mesh()const;
        void write_mesh(string mesh);

        //Physical
        string read_gal()const;
        void write_gal(double x, double y, double z);
        string read_loc()const;
        void write_loc(double x, double y, double z);

        //Vectors
        string read_vec_pos_x()const;
        void write_vec_pos_x(double i, double j, double k);
        string read_vec_pos_y()const;
        void write_vec_pos_y(double i, double j, double k);
        string read_vec_pos_z()const;
        void write_vec_pos_z(double i, double j, double k);

        string read_vec_velo_x()const;
        void write_vec_velo_x(double i, double j, double k);
        string read_vec_velo_y()const;
        void write_vec_velo_y(double i, double j, double k);
        string read_vec_velo_z()const;
        void write_vec_velo_z(double i, double j, double k);

        //Base stats
        double read_dim_x()const;
        double read_dim_y()const;
        double read_dim_z()const;

    private:
        //Networking
        int id;

        //Mesh
        string mesh;

        //Physical
        double dim_x;
        double dim_y;
        double dim_z;

        //Location
        double gal_x;
        double gal_y;
        double gal_z;
        double loc_x;
        double loc_y;
        double loc_z;

        //Vectors
        double vec_pos_x_i;
        double vec_pos_x_j;
        double vec_pos_x_k;
        double vec_pos_y_i;
        double vec_pos_y_j;
        double vec_pos_y_k;
        double vec_pos_z_i;
        double vec_pos_z_j;
        double vec_pos_z_k;

        double vec_velo_x_i;
        double vec_velo_x_j;
        double vec_velo_x_k;
        double vec_velo_y_i;
        double vec_velo_y_j;
        double vec_velo_y_k;
        double vec_velo_z_i;
        double vec_velo_z_j;
        double vec_velo_z_k;
};

#endif // ENTITY_H
