#include "species.hpp"

    spcs::simulation::simulation(d_pair initial_conditions, sim_parameters simulation_parameters) {
        correct_invalid_input(initial_conditions);
        correct_invalid_input(simulation_parameters);
        relative_values = initial_conditions / simulation_parameters.get_equilibrium_point();
        parameters = simulation_parameters;
    }

    spcs::d_pair spcs::simulation::get_absolute_values() {
        return relative_values * parameters.get_equilibrium_point();
    }

    double spcs::simulation::get_prime_integral() {
        double H_;
        H_ = - (parameters.d_ * ln(relative_values.x_)) + (parameters.c_ * relative_values.x_) + (parameters.b_ * relative_values.y_) - (parameters.a_ * ln(relative_values.y_));
        return H_;
    }
  //parte non controllata
  
    void spcs::simulation::evolve() {
        d_pair new_values;
        new_values.x_ = relative_values.x_ + time_step * (relative_values.x_ * (parameters.a_ - parameters.b_ * relative_values.y_));
        new_values.y_ = relative_values.y_ + time_step * (relative_values.y_ * (parameters.d_ * relative_values.x_ - parameters.c_));
        relative_values = new_values;
    }

    void spcs::print(simulation& sim) {
        d_pair abs_values = sim.get_absolute_values();
        std::cout << "Prey: " << abs_values.x_ << " Predators: " << abs_values.y_ << std::endl;
    }
