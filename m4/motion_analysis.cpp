#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double compSim(std::vector<double> t, std::vector<double> v){
    if (v.size()%2 != 0){
        double twoWeightSum = 0;
        double fourWeightSum = 0;
        double h = t[1] - t[0];
        for (size_t i = 0; i < v.size() - 1; i++){
            if (i%2 == 0){
                twoWeightSum += v[i];
            }
            else{
                fourWeightSum += v[i];
            }
        }
        return (h * (v[0] + 4 * fourWeightSum + 2 * twoWeightSum + v[v.size()-1]))/3;
    }
    else{
        double twoWeightSum = 0;
        double fourWeightSum = 0;
        double h = t[1] - t[0]; 
        for (size_t i = 1; i < v.size() - 2; i++){
            if (i%2 == 0){
                twoWeightSum += v[i];
            }
            else{
                fourWeightSum += v[i];
            }
        }
        double firstSum = (h * (v[0] + 4 * fourWeightSum + 2 * twoWeightSum + v[v.size()-2]))/3;
        double secondSum = h * 0.5 * (v[v.size()-2] + v[v.size()-1]);
        return firstSum + secondSum;

    }
}

double mean(std::vector<double> v){
    double sum  = 0;
    for (size_t i = 0; i < v.size(); i++){
        sum += v[i];
    }
    return sum/v.size();
}

double variance(std::vector<double> v){
    double avg = mean(v);
    double varianceSum = 0;
    for (size_t i = 0; i < v.size(); i++){
        varianceSum += pow(v[i] - avg, 2);
    }
    return varianceSum/v.size();
}

double dev(std::vector<double> v){
    return pow(variance(v), 0.5);
}

int main(){
    std::ifstream infile("results.csv");
    if (!infile){
        std::cout << "Error: could not open results.csv";
        return 1;
    }
    double t, v;
    char c;
    std::vector<double> tVector, vVector;
    std::string header;
    std::getline(infile, header);
    while (infile >> t >> c >> v){
        tVector.push_back(t);
        vVector.push_back(v);
    }
    std::cout << "rows read: " << tVector.size() << "\n";

    std::cout << "Distance Traveled: " << compSim(tVector, vVector) << "\n";
    std::cout << "Mean: " << mean(vVector) << "\n";
    std::cout << "Variance: " << variance(vVector) << "\n";
    std::cout << "Standard Deviation: " << dev(vVector) << "\n";

    return 0;
}