#include <iostream>
#include <fstream>
#include <string>

class Simulation {
private:
    double x, v, m, k;
public:
    Simulation(double x0, double v0, double mass, double springK){
        x = x0;
        v = v0;
        m = mass;
        k = springK;
    }

    void step(double dt){
        double a = - k * x / m;
        x = x + v * dt;
        v = v + a * dt;
    }

    double getX(){
        return x;
    }

    double getV(){
        return v;
    }

    double getEnergy(){
        return 0.5 * m * v * v + 0.5 * k * x * x;
    }
};

void printPlotLine(double x, double xMin, double xMax, int width){
    double column = (x - xMin) * (width - 1) / (xMax - xMin);
    int col = (int)(column);
    for (int i = 0; i < width; i++){
        if (i != col){
            std::cout << " ";
        }
        else{
            std::cout <<"*";
        }
    }
    std::cout <<"\n";
}

int main(){
    std::ifstream infile("config.txt");
    if (!infile){
        std::cout << "Error: could not open config.txt\n";
        return 1;
    }
    double x0, v0, mass, springK;
    std::string header;
    std::getline(infile, header);
    infile >> x0 >> v0 >> mass >> springK;

    std::ofstream outfile("trajectory.csv");
    if (!outfile){
        std::cout << "Error: could not open trajectory.csv\n";
        return 1;
    }
    outfile << "time,position,velocity,energy\n";
    
    Simulation sim(x0, v0, mass, springK);
    double t = 0;
    for (int i = 0; i < 1000; i++){
        sim.step(0.01);
        t += 0.01;
        printPlotLine(sim.getX(), -2.0, 2.0, 40);
        outfile << t << ", " << sim.getX() << ", " << sim.getV() << ", " << sim.getEnergy() << "\n";
    }

    return 0;
}