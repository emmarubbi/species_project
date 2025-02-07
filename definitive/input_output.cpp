#include "input_output.hpp"

double spcs::ask_for_duration() {
  double duration;
  std::cout << "Please insert the duration of the simulation: ";
  std::cin >> duration;
  return duration;
}

double spcs::ask_for_output_step() {
  double output_step;
  std::cout
      << "The simulation will save (and eventually print) the state of the "
         "system every x seconds. Please insert x: ";  // inserire default
  std::cin >> output_step;
  return output_step;
}

spcs::pair spcs::ask_for_init_conditions() {
  pair init_conditions;
  std::cout << "Please insert the initial number of preys in the system: ";
  std::cin >> init_conditions.x_;
  std::cout << "Please insert the initial number of predators in the system: ";
  std::cin >> init_conditions.y_;
  return init_conditions;
}

bool spcs::print_is_on() {
  bool is_on = false;
  std::cout << "Do you want to print data on terminal? (not advised if you "
               "want a lot of data to plot) [y/n]"
            << std::endl;
  char answer;
  std::cin >> answer;
  if (answer == 'y' || answer == 'Y') {
    is_on = true;
  }
  if (!is_on) {
    std::cout
        << "Note that the data will be displayed after the simulation has ended"
        << std::endl;
  }
  return is_on;
}

spcs::sim_parameters spcs::ask_for_input_params() {
  sim_parameters parameters;
  std::cout << "Please insert the value of the parameter a (reproduction tax "
               "for preys): ";
  std::cin >> parameters.prey_rep_;
  std::cout
      << "Please insert the value of the parameter b (death tax for preys): ";
  std::cin >> parameters.prey_death_;
  std::cout << "Please insert the value of the parameter c (reproduction tax "
               "for predators): ";
  std::cin >> parameters.pred_rep_;
  std::cout << "Please insert the value of the parameter d (death tax for "
               "predators): ";
  std::cin >> parameters.pred_death_;
  return parameters;
}

spcs::data_set::data_set(double time, simulation const &sim_to_read)
    : time_passed_{time},
      predators_{static_cast<int>(sim_to_read.get_simulation_state().y_)},
      preys_{static_cast<int>(sim_to_read.get_simulation_state().x_)},
      prime_integral_{sim_to_read.get_prime_integral()} {}

void spcs::print(data_set const &data) {
  std::cout << "Time passed (in seconds): " << data.time_passed_ << std::endl;
  std::cout << "Prey number: " << data.preys_
            << " Predator number: " << data.predators_ << std::endl;
  std::cout << "Prime integral: " << data.prime_integral_ << std::endl;
}

void spcs::update_register(std::vector<data_set> &data_register,
                           data_set const &new_data) {
  data_register.push_back(new_data);
}

void spcs::write_to_file(std::vector<data_set> const &data_register,
                         std::string const &filename) {
  std::ofstream datafile(filename);

  if (!datafile.is_open()) {
    std::cerr << "Errore, file non aperto" << std::endl;
  }

  std::for_each(data_register.begin(), data_register.end(),
                [&](data_set const &this_data) {
                  datafile << this_data.time_passed_ << "\t" << this_data.preys_
                           << "\t" << this_data.predators_ << "\t"
                           << this_data.prime_integral_ << "\n";
                });

  datafile.close();
  std::cout << "successful data writing" << std::endl;
}

void spcs::launch_graphic_analyzer() {
  std::string command1 = "gnuplot ../../prime_plotter.gp";
  std::string command2 = "gnuplot ../../evolution_plotter.gp";
  std::cout << "Eseguendo: " << command1 << std::endl;
  int status = system(command1.c_str());
  if (status != 0) {
    std::cerr << "Error in launching the prime integral analyzer" << std::endl;
  }
  std::cout << "Eseguendo: " << command2 << std::endl;
  status = system(command2.c_str());
  if (status != 0) {
    std::cerr << "Error in launching the evolution analyzer" << std::endl;
  }
}