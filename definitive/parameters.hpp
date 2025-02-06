#include <stdexcept>
namespace spcs {
struct pair {
    double x_;
    double y_;

    bool operator== (const pair &other) const;
    pair& operator*= (const pair &other);
    pair& operator/= (const pair &other);
};

struct sim_parameters{
    double prey_rep_; //preys reproduction tax
    double prey_death_; //preys death tax
    double pred_rep_; //predators reproduction tax
    double pred_death_; //predators reproduction tax
    
    pair get_equilibrium_point() const;
    bool is_invalid_for_simulation() const;
};
//WIP: chiedi a chat se ci sono altri test da fare, dopo aver implementato le definizioni
}