#include "input_output.hpp"
#include <SFML/System.hpp>

int main() {
    spcs::sim_parameters exec_params = spcs::ask_for_input_params();
    spcs::pair input_conditions = spcs::ask_for_init_conditions();
    double sim_duration = spcs::ask_for_duration();
    double output_step = spcs::ask_for_output_step();
    bool print_enabled = spcs::print_is_on(); 

    sf::Clock general_clock;
    sf::Clock evolution_clock;
    sf::Clock output_clock;

    std::vector<spcs::data_set> exec_register;
    spcs::simulation exec_sim{input_conditions, exec_params};

    while(general_clock.getElapsedTime().asSeconds() <= sim_duration) {
        if(evolution_clock.getElapsedTime().asMilliseconds() >= 1) {
            exec_sim.evolve();
            evolution_clock.restart();
        }
        if(output_clock.getElapsedTime().asSeconds() >= output_step) {
            spcs::data_set new_entry{general_clock.getElapsedTime().asSeconds(), exec_sim};
            spcs::update_register(exec_register, new_entry);
            if (print_enabled) {
                spcs::print(new_entry);
            }
            output_clock.restart();
        }
    }
    std::string filetitle("Species_log.txt");
    spcs::write_to_file(exec_register, filetitle);
    spcs::launch_graphic_analyzer();
}