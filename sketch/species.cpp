#include "species.hpp"

    spcs::simulation::simulation(d_pair initial_conditions, sim_parameters simulation_parameters) {
        correct_invalid_input(initial_conditions);
        correct_invalid_input(simulation_parameters);
        relative_values = initial_conditions / simulation_parameters.get_equilibrium_point();
        parameters = simulation_parameters;
    }

    spcs::d_pair spcs::simulation::get_absolute_values() const {
        return relative_values * parameters.get_equilibrium_point();
    }

    double spcs::simulation::get_prime_integral() const {
        double H_;
 
        H_ = - (parameters.d_ * ln(get_absolute_values().x_)) + (parameters.c_ * get_absolute_values().x_) + (parameters.b_ * get_absolute_values().y_) - (parameters.a_ * ln(get_absolute_values().y_));
        return H_;
    }
  
    void spcs::simulation::evolve() {
        double x_new = (get_absolute_values().x_ + (parameters.a_ - parameters.b_ * get_absolute_values().y_) * get_absolute_values().x_ * time_step) / parameters.get_equilibrium_point().x_;
        double y_new = (get_absolute_values().y_ + (parameters.c_ * get_absolute_values().x_ - parameters.d_) * get_absolute_values().y_ * time_step) / parameters.get_equilibrium_point().y_;
        relative_values = d_pair{x_new, y_new};
    }

    spcs::d_pair spcs::simulation::get_equilibrium_point() const {
        return parameters.get_equilibrium_point();
    }

    void spcs::print(simulation const& sim) {
        d_pair abs_values = sim.get_absolute_values();
        std::cout << "Prey number: " << abs_values.x_ << " Predator number: " << abs_values.y_ << std::endl;
        std::cout << "Prime integral: " << sim.get_prime_integral() << std::endl;
    }

//solleva exception in ci si resetta la simulazione
//provare a implementare accumulate