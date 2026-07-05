#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

struct Position {
    double x;
    double y;
};

struct Velocity {
    double vx;
    double vy;
};

struct Acceleration {
    double ax;
    double ay;
};

class Simulation {
private:
    Position p;
    Velocity v;
    double M;
    double G;
public:
    Simulation(double posX, double posY, double velX, double velY, double mass){
        p.x = posX;
        p.y = posY;
        v.vx = velX;
        v.vy = velY;
        M = mass;
        G = 1.0;
    }

    void setG(double n){
        G = n;
    }

    void step(double dt){
        double r = pow((pow(p.x, 2) + pow(p.y, 2)), 0.5);
        Acceleration a;
        a.ax = -(G * M * p.x)/pow(r, 3);
        a.ay = -(G * M * p.y)/pow(r, 3);
        p.x += v.vx * dt;
        p.y += v.vy * dt;
        v.vx += a.ax * dt;
        v.vy += a.ay * dt;
    }

    double getX() { return p.x; }
    double getY() { return p.y; }
    double getVX() { return v.vx; }
    double getVY() { return v.vy; }
    double getEnergy() {return 0.5 * (pow(v.vx, 2) + pow(v.vy, 2)) - G * M / pow((pow(p.x, 2) + pow(p.y, 2)), 0.5);}
};

int main(){
    Simulation sim(1, 0, 0, 1, 1);
    std::ofstream outfile("orbit_trajectory.csv");
    if (!outfile) {
        std::cout << "Error: could not open orbit_trajectory.csv";
        return 1;
    }
    outfile << "time, x_pos, y_pos, x_vel, y_vel, energy\n";
    double t = 0;
    for (int i = 0; i < 100; i++){
        double stepSize = 0.05;
        sim.step(stepSize);
        t += stepSize;
        outfile << t << ", " << sim.getX() << ", " << sim.getY() << ", " 
        << sim.getVX() << ", " << sim.getVY() << ", " << sim.getEnergy() << "\n";
    }

    return 0;
}