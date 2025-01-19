#include "input_interface.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main () {
    double duration = spcs::input::ask_for_duration();
    double output_step = spcs::input::ask_for_cout_step();
    spcs::d_pair initial_conditions = spcs::input::ask_for_initial_conditions();
    spcs::sim_parameters parameters = spcs::input::ask_for_parameters();
    spcs::simulation sim(initial_conditions, parameters);

    sf::Clock duration_clock;
    sf::Clock output_clock;
    sf::Clock step_clock;

    while (duration_clock.getElapsedTime().asSeconds() < duration) {
        if (output_clock.getElapsedTime().asSeconds() > output_step) {
            spcs::print(sim);
            output_clock.restart();
        }
        if (step_clock.getElapsedTime().asMilliseconds() > 1) {
            sim.evolve();
            step_clock.restart();
        }
    }
    spcs::print(sim);
    return 0;
}