#include <stdexcept>
#include <iostream>
#include <cmath>

namespace spcs{
template <class T>
struct pair {
    T x_;
    T y_;

    bool operator== (const pair<T>& other) const {
        return x_ == other.x_ && y_ == other.y_;
    } //serve?
    pair<T> operator* (const pair<T>& other) const {
        return {x_ * other.x_, y_ * other.y_};
    }   
    pair<T> operator/ (const pair<T>& other) const {
        return {x_ / other.x_, y_ / other.y_};
    } //tenere liberi ed usa maggiormente *= e /=
    pair& operator*= (const pair<T>& other) {
        x_ *= other.x_;
        y_ *= other.y_;
        return *this;
    } //per la conversione da relativi ad assoluti nella simulationù
    void operator/= (const pair<T>& other) {
        x_ /= other.x_;
        y_ /= other.y_;
    } //per la conversione da assoluti a relativi
};

using d_pair = pair<double>;

struct sim_parameters{
    double a_; //riproduzione prede
    double b_; //mortalità prede
    double c_; //riproduzione predatori
    double d_; //mortalità predatori
    
    d_pair get_equilibrium_point() const; //non dovrebbe modificare lui i membri
};

void correct_invalid_input(sim_parameters& param);
void correct_invalid_input(d_pair& init);

template <class T>
T ln(T x) {
    return std::log(x);
} //per ora NON E' TESTATA
}