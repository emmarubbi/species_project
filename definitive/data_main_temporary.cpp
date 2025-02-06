#include "input_output.hpp"
#include <SFML/System.hpp>

int main() {
    spcs::sim_parameters input_params = spcs::ask_for_input_params();
    spcs::pair init_conditions = spcs::ask_for_init_conditions();
    double duration = spcs::ask_for_duration();
    double output = spcs::ask_for_output_step();

    sf::Clock simulation_clock;
    sf::Clock step_clock;
    sf::Clock output_clock;
    std::vector<spcs::data_set> data_register;

    spcs::simulation this_simulation{init_conditions, input_params};

    while (simulation_clock.getElapsedTime().asSeconds() <= duration) {
        if (step_clock.getElapsedTime().asSeconds() >= this_simulation.get_time_step()) {
            this_simulation.evolve();
            step_clock.restart();
        }
        if (output_clock.getElapsedTime().asSeconds() >= output) {
            spcs::data_set new_entry{simulation_clock.getElapsedTime().asSeconds(), this_simulation};
            spcs::update_register(data_register, new_entry);
            spcs::print(new_entry);
            output_clock.restart();
        }
    }
    std::string filetitle("Species_log.txt");
    spcs::write_to_file(data_register, filetitle);
    spcs::launch_graphic_analyzer();
}

//WIP: aggiungere un controllo per evitare che il file venga sovrascritto???
//WIP: aggiungere richiesta "vuoi printare o no" per abilitare anche la scrittura di tanti dati senza 
//far esplodere il terminale
//WIP: CLANG_FORMAT!!!!
//WIP: ricorda di sputare fuori le cose come int!