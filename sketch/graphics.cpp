#include "graphics.hpp"

spcs::graphics::graph_axis::graph_axis() {
    x_axis.setSize(sf::Vector2f(840, 2));
    x_axis.setOrigin(420, 1);
    x_axis.setPosition(450, 29);
    x_axis.setFillColor(sf::Color::Black);

    x_arrow.setPointCount(3); 
    x_arrow.setPoint(0, sf::Vector2f(0, 0));
    x_arrow.setPoint(1, sf::Vector2f(18, 6));
    x_arrow.setPoint(2, sf::Vector2f(0, 12));
    x_arrow.setOrigin(6, 6);
    x_arrow.setPosition(870, 30);
    x_arrow.setFillColor(sf::Color::Black);

    y_axis.setSize(sf::Vector2f(2, 540));
    y_axis.setOrigin(1, 270);
    y_axis.setPosition(29, 300);
    y_axis.setFillColor(sf::Color::Black);

    y_arrow.setPointCount(3);
    y_arrow.setPoint(0, sf::Vector2f(0, 18));
    y_arrow.setPoint(1, sf::Vector2f(12, 18));
    y_arrow.setPoint(2, sf::Vector2f(6, 0));
    y_arrow.setOrigin(6, 12);
    y_arrow.setPosition(30, 30);
    y_arrow.setFillColor(sf::Color::Black);
}

void spcs::graphics::graph_axis::draw(sf::RenderWindow& window) {
    window.draw(x_axis);
    window.draw(x_arrow);
    window.draw(y_axis);
    window.draw(y_arrow);
}

spcs::d_pair spcs::graphics::get_rescaling_factor(spcs::simulation& sim) {
    double x_eq = sim.get_equilibrium_point().x_;
    double y_eq = sim.get_equilibrium_point().y_;
    double x_factor = x_eq / 420;
    double y_factor = y_eq / 300;
    return {x_factor, y_factor};
}
spcs::graphics::graph_point::graph_point(spcs::simulation& sim) {
    point.setRadius(1);
    point.setOrigin(1, 1);
    point.setFillColor(sf::Color::Blue);
    point.setPosition(450, 300);
}