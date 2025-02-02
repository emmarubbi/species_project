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
    spcs::graphics::graph_axis axis;
    std::vector<spcs::graphics::graph_point> all_points;
    while (graph.isOpen()) {
        sf::Event event;
        while (graph.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                graph.close();
            }
        }
        if (duration_clock.getElapsedTime().asSeconds() > duration) {
            graph.close();
            break;
        } //davvero va chiuso?
        
        if (output_clock.getElapsedTime().asSeconds() > output_step) {
            spcs::print(sim);
            output_clock.restart();
        }
        if (step_clock.getElapsedTime().asMilliseconds() > 1) {
            sim.evolve();
            all_points.push_back(spcs::graphics::graph_point(sim));
            step_clock.restart();
        }
        graph.clear(sf::Color::Cyan);
        axis.draw(graph);
        std::for_each(all_points.begin(), all_points.end(), [&graph](spcs::graphics::graph_point& point) { 
            point.draw(graph); 
            });
        graph.display();
    }
}