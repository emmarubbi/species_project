#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "species.hpp"

TEST_CASE("Testing 1 - pair structure") {
    spcs::d_pair p1 = {1, 2};
    spcs::d_pair p2 = {1, 2};
    spcs::d_pair p3 = {1, 3};
    CHECK(p1 == p2);
    CHECK(!(p1 == p3));
    CHECK(p1.x_ == 1);
    CHECK(p1.y_ == 2);

    SUBCASE("Testing 1.1 - operator *, /") {
    spcs::d_pair p4 = p3 / p1;
    CHECK(p4.x_ == 1);
    CHECK(p4.y_ == 1.5);

    spcs::d_pair p5 = p2 * p3;
    CHECK(p5.x_ == 1);
    CHECK(p5.y_ == 6);
    }

    SUBCASE("Testing 1.2 - operators *=, /=") {
    p1 *= p3;
    CHECK(p1.x_ == 1);
    CHECK(p1.y_ == 6);

    p1 /= p3;
    CHECK(p1.x_ == 1);
    CHECK(p1.y_ == 2);
    }
}

TEST_CASE("Testing 2 - sim_parameters class") {
    spcs::sim_parameters test_params = {1, 2, 4, 8};
    spcs::d_pair test_eq = test_params.get_equilibrium_point();
    CHECK(test_params.a_ == 1);
    CHECK(test_params.b_ == 2);
    CHECK(test_params.c_ == 4);
    CHECK(test_params.d_ == 8);
    CHECK(test_eq.x_ == 2.);
    CHECK(test_eq.y_ == 0.5);

    SUBCASE("Testing 2.1 - invalid parameter behaviour") {
        spcs::sim_parameters inv_params{0, 1, 0, 2};
        spcs::correct_invalid_input(inv_params);
        CHECK(inv_params.a_ == 1);
        CHECK(inv_params.c_ == 1);
        CHECK(inv_params.get_equilibrium_point().x_ == 2);
        CHECK(inv_params.get_equilibrium_point().y_ == 1);

        spcs::sim_parameters inv_params2{1, -1, 2, -2};
        spcs::correct_invalid_input(inv_params2);
        CHECK(inv_params2.b_ == 1);
        CHECK(inv_params2.d_ == 1);
        CHECK(inv_params2.get_equilibrium_point().x_ == 0.5);
        CHECK(inv_params2.get_equilibrium_point().y_ == 1);
    }

    SUBCASE("Testing 2.2 - constness of methods") {
        spcs::sim_parameters const_params = {1, 2, 4, 8};
        spcs::d_pair test_eq = test_params.get_equilibrium_point();
        CHECK(test_eq.x_ == 2.);
        CHECK(test_eq.y_ == 0.5); //dovrebbe compilare
    }
}

TEST_CASE("Testing 3 - input pair corrector, used for simulation initialization") {
    SUBCASE("Testing 3.1 - no need for correction") {
        spcs::d_pair correct_pair = {1., 2.};
        spcs::correct_invalid_input(correct_pair);
        CHECK(correct_pair.x_ == 1);
        CHECK(correct_pair.y_ == 2);
    }

    SUBCASE("Testing 3.2 - correction needed") {
        spcs::d_pair invalid_pair = {0., -1.};
        spcs::correct_invalid_input(invalid_pair);
        CHECK(invalid_pair.x_ == 1);
        CHECK(invalid_pair.y_ == 1);

        invalid_pair = {-1., 2.};
        spcs::correct_invalid_input(invalid_pair);
        CHECK(invalid_pair.x_ == 1);
        CHECK(invalid_pair.y_ == 2);

        invalid_pair = {2., -1.};
        spcs::correct_invalid_input(invalid_pair);
        CHECK(invalid_pair.x_ == 2);
        CHECK(invalid_pair.y_ == 1);
    }
}

TEST_CASE("Testing 4 - simulation class methods") {
    SUBCASE("Testing 4.1 - constructor, everything okay") {
        spcs::d_pair init = {1, 2};
        spcs::sim_parameters params = {1, 2, 4, 8};
        spcs::simulation test_sim{init, params};
        CHECK(test_sim.get_absolute_values().x_ == 1);
        CHECK(test_sim.get_absolute_values().y_ == 2);
    }
    
    SUBCASE("Testing 4.2 - constructor, correction of invalid inputs") {
        spcs::d_pair init = {0, -1};
        spcs::sim_parameters params = {1, -2, 4, 8};
        spcs::simulation test_sim{init, params};
        CHECK(test_sim.get_absolute_values().x_ == 1);
        CHECK(test_sim.get_absolute_values().y_ == 1);
    }

    SUBCASE("Testing 4.3 - get_prime_integral") {
        spcs::d_pair init = {1, 2};
        spcs::sim_parameters params = {1, 2, 4, 8};
        spcs::simulation test_sim{init, params};
        CHECK(test_sim.get_prime_integral() == doctest::Approx(7.30685)); //ci sono altri casi da aggiungere?

        spcs::d_pair init_err = {0, 2};
        spcs::simulation test_sim_err{init_err, params};
        CHECK(test_sim_err.get_prime_integral() == doctest::Approx(7.30685)); // init_err should be initialized to {1, 2}
    }

    SUBCASE("Testing 4.4 - evolution (and print) method") {
        spcs::d_pair init = {1, 2};
        spcs::sim_parameters params = {1, 2, 4, 8};
        spcs::simulation test_sim{init, params};
        test_sim.evolve();
        CHECK(test_sim.get_absolute_values().x_ == doctest::Approx(0.997).epsilon(0.001));
        CHECK(test_sim.get_absolute_values().y_ == doctest::Approx(1.992).epsilon(0.001));
        print(test_sim);

        test_sim.evolve();
        CHECK(test_sim.get_absolute_values().x_ == doctest::Approx(0.994).epsilon(0.001));
        CHECK(test_sim.get_absolute_values().y_ == doctest::Approx(1.984).epsilon(0.001));
        print(test_sim);
    }

    SUBCASE("Testing 4.5 - equilibrium point getter") {
        spcs::d_pair init = {1, 2};
        spcs::sim_parameters params = {1, 2, 4, 8};
        spcs::simulation test_sim{init, params};
        spcs::d_pair eq = test_sim.get_equilibrium_point();
        CHECK(eq.x_ == 2);
        CHECK(eq.y_ == 0.5);
    } //tests about the function are in the parameters section
} 