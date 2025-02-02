#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "parameters.hpp"

TEST_CASE("Testing 1 - pair structure") {
    spcs::pair p1 = {1, 2};
    spcs::pair p2 = {1, 2};
    spcs::pair p3 = {1, 3};

    SUBCASE("Testing 1.1 - operator ==") {
    CHECK(p1 == p2);
    CHECK(!(p1 == p3));
    CHECK(p1.x_ == 1);
    CHECK(p1.y_ == 2);
    }

    /*SUBCASE("Testing 1.1 - operator *, /") {
    spcs::pair p4 = p3 / p1;
    CHECK(p4.x_ == 1);
    CHECK(p4.y_ == 1.5);

    spcs::pair p5 = p2 * p3;
    CHECK(p5.x_ == 1);
    CHECK(p5.y_ == 6);
    } */
   //WIP: se non vengono implementati questi operatori, vanno tolti i test

    SUBCASE("Testing 1.2 - operators *=, /=") {
    p1 *= p3;
    CHECK(p1.x_ == 1);
    CHECK(p1.y_ == 6);

    p1 /= p3;
    CHECK(p1.x_ == 1);
    CHECK(p1.y_ == 2);

    spcs::pair p2{0., 0.};
    CHECK_THROWS_AS(p1 /= p2, std::invalid_argument);
    } //WIP: se vuoi essere precisina, aggiungi anche la divisione per coppie parzialmente nulle
}

TEST_CASE("Testing 2 - sim_parameters class") {
    spcs::sim_parameters test_params = {1, 2, 4, 8};
    spcs::pair test_eq = test_params.get_equilibrium_point();
    SUBCASE("Testing 2.1 - testing constructor and equilibrium point") {
        CHECK(test_params.prey_rep_ == 1);
        CHECK(test_params.prey_death_ == 2);
        CHECK(test_params.pred_rep_ == 4);
        CHECK(test_params.pred_death_ == 8);
        CHECK(test_eq.x_ == 2.);
        CHECK(test_eq.y_ == 0.5);
    }

    /*SUBCASE("Testing 2.1 - invalid parameter behaviour") {
        spcs::sim_parameters inv_params{0, 1, 0, 2};
        spcs::correct_invalipred_death_input(inv_params);
        CHECK(inv_params.prey_rep_ == 1);
        CHECK(inv_params.prepred_death_rep_ == 1);
        CHECK(inv_params.get_equilibrium_point().x_ == 2);
        CHECK(inv_params.get_equilibrium_point().y_ == 1);

        spcs::sim_parameters inv_params2{1, -1, 2, -2};
        spcs::correct_invalipred_death_input(inv_params2);
        CHECK(inv_params2.prey_death_ == 1);
        CHECK(inv_params2.pred_death_ == 1);
        CHECK(inv_params2.get_equilibrium_point().x_ == 0.5);
        CHECK(inv_params2.get_equilibrium_point().y_ == 1);
    } */
   //WIP: questa correzione non esisterà più

    SUBCASE("Testing 2.2 - constness of methods") {
        spcs::sim_parameters const_params = {1, 2, 4, 8};
        spcs::pair test_eq = test_params.get_equilibrium_point();
        CHECK(test_eq.x_ == 2.);
        CHECK(test_eq.y_ == 0.5);
    } //WIP, serve davvero?
}
