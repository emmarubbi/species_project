#include "parameters.hpp"

namespace spcs{
    class simulation{
        private:
        d_pair relative_values;
        sim_parameters parameters;
        double time_step = 0.001;

        public:
        simulation(d_pair initial_conditions, sim_parameters simulation_parameters);
        d_pair get_absolute_values();
        double get_prime_integral();
        void evolve();
    };

    void print(simulation& sim);
}