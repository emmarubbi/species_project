#include "graphics.hpp"

int main() {
    double duration = spcs::input::ask_for_duration();
    double output_step = spcs::input::ask_for_cout_step();
    spcs::d_pair initial_conditions = spcs::input::ask_for_initial_conditions();
    spcs::sim_parameters parameters = spcs::input::ask_for_parameters();
    spcs::simulation sim(initial_conditions, parameters);

    sf::Clock duration_clock;
    sf::Clock output_clock;
    sf::Clock step_clock;

    sf::RenderWindow graph(sf::VideoMode(900, 600), "Level curve animation");
    graph.clear(sf::Color::Cyan);
    spcs::graphics::graph_axis axis;
    axis.draw(graph);
    while (graph.isOpen()) {
        sf::Event event;
        while (graph.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                graph.close();
            }
        }
        if (duration_clock.getElapsedTime().asSeconds() > duration) {
            graph.close();
        } //davvero va chiuso?
        
        
        while (duration_clock.getElapsedTime().asSeconds() < duration) {
        if (output_clock.getElapsedTime().asSeconds() > output_step) {
            spcs::print(sim);
            output_clock.restart();
        }
        if (step_clock.getElapsedTime().asMilliseconds() > 1) {
            sim.evolve();
            spcs::graphics::graph_point point(sim);
            point.draw(graph);
            graph.display();
            step_clock.restart();
        }
        }
    }

}