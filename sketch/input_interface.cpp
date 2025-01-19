#include "input_interface.hpp"
#include <iostream>

double spcs::input::ask_for_duration() {
    double duration;
    std::cout << "Please insert the duration of the simulation: ";
    std::cin >> duration;
    return duration;
}

double spcs::input::ask_for_cout_step() {
    double cout_step;
    std::cout << "The simulation will print the state of the system every x seconds. Please insert x: "; //inserire default
    std::cin >> cout_step;
    return cout_step;
}

spcs::d_pair spcs::input::ask_for_initial_conditions() {
    d_pair initial_conditions;
    std::cout << "Please insert the initial number of preys in the system: ";
    std::cin >> initial_conditions.x_;
    std::cout << "Please insert the initial number of predators in the system: ";
    std::cin >> initial_conditions.y_;
    return initial_conditions;
}

spcs::sim_parameters spcs::input::ask_for_parameters() {
    sim_parameters parameters;
    std::cout << "Please insert the value of the parameter a (reproduction tax for preys): ";
    std::cin >> parameters.a_;
    std::cout << "Please insert the value of the parameter b (death tax for preys): ";
    std::cin >> parameters.b_;
    std::cout << "Please insert the value of the parameter c (reproduction tax for predators): ";
    std::cin >> parameters.c_;
    std::cout << "Please insert the value of the parameter d (death tax for predators): ";
    std::cin >> parameters.d_;
    return parameters;
}

