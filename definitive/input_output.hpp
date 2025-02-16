#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "simulation.hpp"

namespace spcs {
pair ask_for_init_conditions();
sim_parameters ask_for_input_params();
double ask_for_duration();
double ask_for_output_step();
bool print_is_on();

struct data_set {
  double time_passed_;
  int predators_;
  int preys_;
  double prime_integral_;

  data_set(double time, simulation const &sim_to_read);
};

void print(data_set const &data);
void update_register(std::vector<data_set> &data_register,
                     data_set const &new_data);
void write_to_file(std::vector<data_set> const &data_register,
                   std::string const &filename);

void launch_graphic_analyzer();
}