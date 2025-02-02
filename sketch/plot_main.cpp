#include <iostream>
int main() {
    std::cout << "Using Gnuplot!" << std::endl;
    int result = system("gnuplot testplot.gp");
    if (result != 0) {
        std::cerr << "Errore esecuzione Gnuplot" << std::endl;
    }
}