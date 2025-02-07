#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "input_output.hpp"

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

  SUBCASE("Testing 1.2 - operators *=, /=") {
    p1 *= p3;
    CHECK(p1.x_ == 1);
    CHECK(p1.y_ == 6);

    p1 /= p3;
    CHECK(p1.x_ == 1);
    CHECK(p1.y_ == 2);

    p2 = {0., 0.};
    CHECK_THROWS_AS(p1 /= p2, std::invalid_argument);
    p3 = {0., 1.};
    CHECK_THROWS_AS(p1 /= p3, std::invalid_argument);
    p3 = {1., 0.};
    CHECK_THROWS_AS(p1 /= p3, std::invalid_argument);
  }
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

  SUBCASE("Testing 2.1 - invalid parameter behaviour") {
    spcs::sim_parameters inv_params{0, 1, 0, 2};
    CHECK(inv_params.is_invalid_for_simulation() == true);

    spcs::sim_parameters inv_params2{1, -1, 2, -2};
    CHECK(inv_params2.is_invalid_for_simulation() == true);
  }

  SUBCASE("Testing 2.2 - constness of methods") {
    spcs::sim_parameters const_params = {1, 2, 4, 8};
    test_eq = const_params.get_equilibrium_point();
    CHECK(test_eq.x_ == 2.);
    CHECK(test_eq.y_ == 0.5);
  }
}

TEST_CASE("Testing 3 - simulation class methods") {
  SUBCASE("Testing 3.1 - constructor, everything okay") {
    spcs::pair init = {1, 2};
    spcs::sim_parameters params = {1, 2, 4, 8};
    spcs::simulation test_sim{init, params};
    CHECK(test_sim.get_simulation_state().x_ == 1);
    CHECK(test_sim.get_simulation_state().y_ == 2);
  }

  SUBCASE("Testing 3.2 - constructor, warning about invalid inputs") {
    spcs::pair init = {0, -1};
    spcs::sim_parameters params = {1, -2, 4, 8};
    CHECK_THROWS_AS(spcs::simulation test_sim(init, params),
                    std::invalid_argument);

    spcs::pair init_err = {0, 2};
    CHECK_THROWS_AS(spcs::simulation err_sim(init_err, params),
                    std::invalid_argument);
  }

  SUBCASE("Testing 3.3 - get_prime_integral") {
    spcs::pair init = {1, 2};
    spcs::sim_parameters params = {1, 2, 4, 8};
    spcs::simulation test_sim{init, params};
    CHECK(test_sim.get_prime_integral() == doctest::Approx(7.30685));
  }

  SUBCASE("Testing 3.4 - evolution method") {
    spcs::pair init = {1, 2};
    spcs::sim_parameters params = {1, 2, 4, 8};
    spcs::simulation test_sim{init, params};
    test_sim.evolve();
    CHECK(test_sim.get_simulation_state().x_ ==
          doctest::Approx(0.997).epsilon(0.001));
    CHECK(test_sim.get_simulation_state().y_ ==
          doctest::Approx(1.992).epsilon(0.001));

    test_sim.evolve();
    CHECK(test_sim.get_simulation_state().x_ ==
          doctest::Approx(0.994).epsilon(0.001));
    CHECK(test_sim.get_simulation_state().y_ ==
          doctest::Approx(1.984).epsilon(0.001));
  }

  SUBCASE("Testing 3.5 - equilibrium point getter") {
    spcs::pair init = {1, 2};
    spcs::sim_parameters params = {1, 2, 4, 8};
    spcs::simulation test_sim{init, params};
    spcs::pair eq = test_sim.get_equilibrium_point();
    CHECK(eq.x_ == 2);
    CHECK(eq.y_ == 0.5);
  }

  SUBCASE("Testing 3.5 - time step getter") {
    spcs::pair init = {1, 2};
    spcs::sim_parameters params = {1, 2, 4, 8};
    spcs::simulation test_sim{init, params};
    CHECK(test_sim.get_time_step() == 0.001);
  }
}

TEST_CASE("Testing 4 - data management elements") {
  SUBCASE("Testing 4.1 - data_set structure") {
    spcs::pair init = {1, 2};
    spcs::sim_parameters params = {1, 2, 4, 8};
    spcs::simulation test_sim{init, params};
    spcs::data_set test_data{1, test_sim};
    CHECK(test_data.time_passed_ == 1);
    CHECK(test_data.preys_ == 1);
    CHECK(test_data.predators_ == 2);
    CHECK(test_data.prime_integral_ == doctest::Approx(7.30685));
  }

  SUBCASE("Testing 4.2 - update register function") {
    spcs::pair init = {1, 2};
    spcs::sim_parameters params = {1, 2, 4, 8};
    spcs::simulation test_sim{init, params};
    spcs::data_set test_data{1, test_sim};
    std::vector<spcs::data_set> test_register;
    spcs::update_register(test_register, test_data);
    CHECK(test_register.size() == 1);
    CHECK(test_register[0].time_passed_ == 1);
    CHECK(test_register[0].preys_ == 1);
    CHECK(test_register[0].predators_ == 2);
    CHECK(test_register[0].prime_integral_ == doctest::Approx(7.30685));

    test_sim.evolve();
    spcs::data_set test_data2{2, test_sim};
    spcs::update_register(test_register, test_data2);
    CHECK(test_register.size() == 2);
    CHECK(test_register[1].time_passed_ == 2);
    CHECK(test_register[1].preys_ == 0); //0.997, rounded to 0
    CHECK(test_register[1].predators_ == 1); //1.992, rounded to 1
    CHECK(test_register[1].prime_integral_ == doctest::Approx(7.30685));
  }

  SUBCASE("Testing 4.3 - write to file function") {
    spcs::pair init = {1, 2};
    spcs::sim_parameters params = {1, 2, 4, 8};
    spcs::simulation test_sim{init, params};
    spcs::data_set test_data{1, test_sim};
    std::vector<spcs::data_set> test_register;
    spcs::update_register(test_register, test_data);
    spcs::write_to_file(test_register, "test_file.txt");

    std::ifstream test_file("test_file.txt");
    std::string line;
    std::getline(test_file, line);
    CHECK(line == "1\t1\t2\t7.30685");
    test_file.close();
    std::remove("test_file.txt");
  }

  SUBCASE("Testing 4.4 - write to file an empty register") {
    std::vector<spcs::data_set> test_register;
    spcs::write_to_file(test_register, "test_file.txt");

    std::ifstream test_file("test_file.txt");
    std::string line;
    std::getline(test_file, line);
    CHECK(line == "");
    test_file.close();
    std::remove("test_file.txt");
  }
}