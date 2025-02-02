#include "input_interface.hpp"
#include <fstream>
#include <vector>
#include <cassert>
#include <SFML/System.hpp>


int main () {
    double duration = spcs::input::ask_for_duration();
    double output_step = spcs::input::ask_for_cout_step();
    spcs::d_pair initial_conditions = spcs::input::ask_for_initial_conditions();
    spcs::sim_parameters parameters = spcs::input::ask_for_parameters();
    spcs::simulation sim(initial_conditions, parameters);

    sf::Clock duration_clock;
    sf::Clock output_clock;
    sf::Clock step_clock;

    std::vector<double> time_register;
    std::vector<double> preys_register; //eventualmente diventeranno int
    std::vector<double> predators_register;
    std::vector<double> prime_integral_register;

    while (duration_clock.getElapsedTime().asSeconds() < duration) {
        if (output_clock.getElapsedTime().asSeconds() > output_step) {
            spcs::print(sim); //da rimuovere dopo (forse)
            double preys = sim.get_absolute_values().x_;
            double predators = sim.get_absolute_values().y_;

            preys_register.push_back(preys);
            predators_register.push_back(predators);
            prime_integral_register.push_back(sim.get_prime_integral()); //forse neanche gli altri due servono
            time_register.push_back(duration_clock.getElapsedTime().asSeconds());
            output_clock.restart();
        }
        if (step_clock.getElapsedTime().asMilliseconds() > 1) {
            sim.evolve();
            step_clock.restart();
        }
    }
    spcs::print(sim);
    std::ofstream datafile("species_log.txt");
    assert (time_register.size() == preys_register.size() && time_register.size() == predators_register.size() && time_register.size() == prime_integral_register.size());

    if(!datafile.is_open()) {
        std::cerr << "Errore, file non aperto" << std::endl;
    }

    for (size_t i = 0; i < time_register.size(); ++i) {
        datafile << time_register[i] << "\t" << preys_register[i] << "\t" << predators_register[i] << "\t" << prime_integral_register[i] << "\n";
    }
    datafile.close();

    std::cout << "successful data writing" << std::endl;
    return 0;
}