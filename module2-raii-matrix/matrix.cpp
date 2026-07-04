#include <iostream>
#include <cmath>
#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<double> data;
public:
    Matrix(int r, int c){
        rows = r;
        cols = c;
        data.resize(r * c);
    }

    double& at(int r, int c){
        return data[r * cols + c];
    }
};

int main(){
    Matrix m(2,2);
    int rowCount = 2;
    int colCount = 2;
    m.at(0,0) = 1;
    m.at(0,1) = 2;
    m.at(1,0) = 1;
    m.at(1,1) = 4;
    for (int i = 0; i < rowCount; i++){
        for (int j = 0; j < colCount; j++){
            std::cout << m.at(i,j) << " ";
        }
        std::cout << "\n";
    }   
    Matrix m2 = m;
    std::cout << m2.at(0, 0) << "\n";
    m2.at(0,0) = 99;
    std::cout << "m.at(0,0) is now: " << m.at(0,0) << "\n";
    Matrix m3(2, 2);
    m3 = m;
    std::cout << "m3.at(0,0) after m3 = m: " << m3.at(0,0) << "\n";
    m3 = m3;
    std::cout << "m3.at(0,0) after self-assign: " << m3.at(0,0) << "\n";
    return 0;
}