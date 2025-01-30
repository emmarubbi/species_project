#include "graphics.hpp"

spcs::graphics::graph_axis::graph_axis() {
    x_axis.setSize(sf::Vector2f(840, 2));
    x_axis.setOrigin(420, 1);
    x_axis.setPosition(450, 571);
    x_axis.setFillColor(sf::Color::Black);

    x_arrow.setPointCount(3); 
    x_arrow.setPoint(0, sf::Vector2f(0, 0));
    x_arrow.setPoint(1, sf::Vector2f(12, 4));
    x_arrow.setPoint(2, sf::Vector2f(0, 8));
    x_arrow.setOrigin(4, 4);
    x_arrow.setPosition(870, 570);
    x_arrow.setFillColor(sf::Color::Black);

    y_axis.setSize(sf::Vector2f(2, 540));
    y_axis.setOrigin(1, 270);
    y_axis.setPosition(29, 300);
    y_axis.setFillColor(sf::Color::Black);

    y_arrow.setPointCount(3);
    y_arrow.setPoint(0, sf::Vector2f(0, 12));
    y_arrow.setPoint(1, sf::Vector2f(8, 12));
    y_arrow.setPoint(2, sf::Vector2f(4, 0));
    y_arrow.setOrigin(4, 8);
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
    double x_factor = 420 / x_eq;
    double y_factor = 300 / y_eq;
    return {x_factor, y_factor};
}

spcs::graphics::graph_point::graph_point(spcs::simulation& sim) {
    point.setRadius(1);
    point.setOrigin(1, 1);
    point.setFillColor(sf::Color::Blue);
    d_pair resc_fact{300. / 840., 300. / 540.};
    d_pair position = sim.get_absolute_values() * resc_fact; //ALTERNATIVA: implementare conversione tra pairs e inizializzare come pair float
    position.y_ = 540 - position.y_;
    point.setPosition(static_cast<float>(position.x_), static_cast<float>(position.y_));
    point.move(30.f, 30.f);
}

void spcs::graphics::graph_point::draw(sf::RenderWindow& window) {
    window.draw(point);
}

void spcs::graphics::graph_point::print_position_for_debug() {
    std::cout << "x: " << point.getPosition().x << " y: " << point.getPosition().y << std::endl;
}