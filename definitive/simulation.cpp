#include "simulation.hpp"
#include <cmath>

spcs::simulation::simulation(spcs::pair init_conditions, spcs::sim_parameters input_param) : relative_values{init_conditions}, parameters{input_param} {
    if (input_param.is_invalid_for_simulation()) {
        throw std::invalid_argument("Invalid simulation parameters!");
    }
    if (init_conditions.x_ <= 0 || init_conditions.y_ <= 0) {
        throw std::invalid_argument("Invalid initial conditions!");
    }
    relative_values /= input_param.get_equilibrium_point();
} 
//WIP, vedi se aggiungere qualcosa che fornisca l'errore preciso

void spcs::simulation::evolve() {
    double x_new = (get_simulation_state().x_ + (parameters.prey_rep_ - parameters.prey_death_ * get_simulation_state().y_) * get_simulation_state().x_ * time_step) / parameters.get_equilibrium_point().x_;
    double y_new = (get_simulation_state().y_ + (parameters.pred_rep_ * get_simulation_state().x_ - parameters.pred_death_) * get_simulation_state().y_ * time_step) / parameters.get_equilibrium_point().y_;
    if (x_new == 0 || y_new == 0) {
        throw std::runtime_error("One of the species has extinguished!");
    }
    relative_values = pair{x_new, y_new}; 
}

spcs::pair spcs::simulation::get_simulation_state() const {
    pair relative_output = relative_values; //WUP, valutare se implementare anche operatore * puro
    return relative_output *= parameters.get_equilibrium_point();
}

double spcs::simulation::get_prime_integral() const {
    return (- (parameters.pred_death_ * std::log(get_simulation_state().x_)) + (parameters.pred_rep_ * get_simulation_state().x_) + (parameters.prey_death_ * get_simulation_state().y_) - (parameters.prey_rep_ * std::log(get_simulation_state().y_)));
}

spcs::pair spcs::simulation::get_equilibrium_point() const {
    return parameters.get_equilibrium_point();
}

double spcs::simulation::get_time_step() const {
    return time_step;
}