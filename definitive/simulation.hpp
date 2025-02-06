#include "parameters.hpp"
//WIP, inserire include guards!

namespace spcs {
    class simulation {
        private:
        pair relative_values;
        sim_parameters parameters;
        const double time_step = 0.001; //WIP: serve sia const? meno modificabilità?

        public:
        simulation(pair init_conditions, sim_parameters input_param); //WIP, sono da passare per reference?
        void evolve();
        pair get_simulation_state() const; //returns the number of preys and predators
        double get_prime_integral() const;
        pair get_equilibrium_point() const;
        double get_time_step() const;
    };
}