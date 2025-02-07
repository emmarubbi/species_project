#include "parameters.hpp"

bool spcs::pair::operator==(const pair &other) const {
  return (x_ == other.x_ && y_ == other.y_);
}

spcs::pair &spcs::pair::operator*=(const pair &other) {
  x_ *= other.x_;
  y_ *= other.y_;
  return *this;
}

spcs::pair &spcs::pair::operator/=(const pair &other) {
  if (other.x_ == 0 || other.y_ == 0) {
    throw std::invalid_argument(
        "Error, division by 0"); 
  }
  x_ /= other.x_;
  y_ /= other.y_;
  return *this;
}

spcs::pair spcs::sim_parameters::get_equilibrium_point() const {
  double x_equil = pred_death_ / pred_rep_;
  double y_equil = prey_rep_ / prey_death_;
  return {x_equil, y_equil};
}

bool spcs::sim_parameters::is_invalid_for_simulation() const {
  if (pred_death_ <= 0 || pred_rep_ <= 0 || prey_death_ <= 0 ||
      prey_rep_ <= 0) {
    return true;
  } else {
    return false;
  }
}