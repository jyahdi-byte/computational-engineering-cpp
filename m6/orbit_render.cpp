#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(){
    std::ifstream infile("orbit_trajectory.csv");
    if (!infile){
        std::cout << "Error: could not open orbit_trajectory.csv\n";
        return 1;
    }
    std::string header;
    std::getline(infile, header);

    std::vector<double> xValues, yValues;
    double time, x, y, vx, vy, energy;
    char c;
    while (infile >> time >> c >> x >> c >> y >> c >> vx >> c >> vy >> c >> energy){
        xValues.push_back(x);
        yValues.push_back(y);
    }
    std::cout << "rows read: " << xValues.size() << "\n";

    double xMin = *std::min_element(xValues.begin(), xValues.end());
    double xMax = *std::max_element(xValues.begin(), xValues.end());
    double yMin = *std::min_element(yValues.begin(), yValues.end());
    double yMax = *std::max_element(yValues.begin(), yValues.end());

    std::cout << "x range: " << xMin << " to " << xMax << "\n";
    std::cout << "y range: " << yMin << " to " << yMax << "\n";

    int width = 200;
    int height = 200;
    std::vector<std::vector<int>> grid(height, std::vector<int>(width, 0));

    for (size_t i = 0; i < xValues.size(); i++){
        int col = (int)((xValues[i] - xMin) / (xMax - xMin) * (width - 1));
        int row = (int)((yValues[i] - yMin) / (yMax - yMin) * (height - 1));
        grid[row][col] = 255;
    }

    std::ofstream outfile("orbit_render.ppm");
    outfile << "P3\n";
    outfile << width << " " << height << "\n";
    outfile << "255\n";

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            int value = grid[row][col];
            outfile << value << " " << value << " " << value << "  ";
        }
        outfile << "\n";
    }

    return 0;
}