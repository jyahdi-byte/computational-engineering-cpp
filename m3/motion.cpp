#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
    std::ifstream infile("data.txt");
    if (!infile){
        std::cout << "Error: could not open data.txt\n";
        return 1;
    }
        double t, x;
        std::vector<double> tVector, xVector ;
        std::string header;
        std::getline(infile, header);   
        while (infile >> t >> x){
        tVector.push_back(t);
        xVector.push_back(x);
        }
        for (size_t i = 0; i <tVector.size(); i++){
            std::cout << "t = " << tVector[i] << ", x = " << xVector[i] << "\n";
        }
        
        std::cout << "\n";

        std::vector<double> velocities;
        double dt;
        double v;
        for (size_t i = 0; i < tVector.size(); i++){
            if (i == 0){
                dt = tVector[i+1] - tVector[i];
                v = (xVector[i+1] - xVector[i])/dt;
                velocities.push_back(v);
            }
            else if (i == tVector.size() - 1){
                dt = tVector[i] - tVector[i-1];
                v = (xVector[i] - xVector[i-1])/dt;
                velocities.push_back(v);
            }
            else{
                dt = tVector[i+1] - tVector[i-1];
                v = (xVector[i+1] - xVector[i-1])/dt;
                velocities.push_back(v);
            }
        }
        for (size_t i = 0; i < velocities.size(); i++){
            std::cout << "t = " << tVector[i] << ", x = " << velocities[i] << "\n";
        }

        std::ofstream outfile("results.csv");
        if (!outfile) {
            std::cout << "Error: could not open results.csv for writing\n";
            return 1;
        }
        outfile << "time,velocity\n";
        for (size_t i = 0; i < velocities.size(); i++){
            outfile <<  tVector[i] << "," << velocities[i] << "\n";
        }
        return 0;
}