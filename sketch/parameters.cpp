#include "parameters.hpp"

//SIMULATION PARAMETERS STRUCT
spcs::d_pair spcs::sim_parameters::get_equilibrium_point() const{
    double x_equilibrium = d_ / c_;
    double y_equilibrium = a_ / b_;
    return {x_equilibrium, y_equilibrium};
}

void spcs::correct_invalid_input(spcs::sim_parameters& param){
    bool need_warning = false;
    if(param.a_ <= 0){
        param.a_ = 1;
        need_warning = true;
    }
    if(param.b_ <= 0){
        param.b_ = 1;
        need_warning = true;
    }
    if(param.c_ <= 0){
        param.c_ = 1;
        need_warning = true;
    }
    if(param.d_ <= 0){
        param.d_ = 1;
        need_warning = true; //valutare sostituzione con switch o algoritmo
    }
    if(need_warning) {
        std::cout << "Warning: one or more parameters are invalid. Corrected to default value (1)." << std::endl;
    }
}

void spcs::correct_invalid_input(d_pair& init) {
    bool need_warning = false;
    if(init.x_ <= 0){
        init.x_ = 1;
        need_warning = true;
    }
    if(init.y_ <= 0){
        init.y_ = 1;
        need_warning = true;
    }
    if(need_warning) {
        std::cout << "Warning: one or more initial conditions are invalid. Corrected to default value (1)." << std::endl;
    }
}

//vanno implementati come int??