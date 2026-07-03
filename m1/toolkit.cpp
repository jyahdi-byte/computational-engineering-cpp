#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>

class Vec3 {
public:
    double x, y, z;
    Vec3(){
        x = 0;
        y = 0;
        z = 0;
    }
    Vec3(double a, double b, double c){
        x = a;
        y = b;
        z = c;
    }
};

Vec3 add(Vec3 a, Vec3 b){
    Vec3 result(a.x + b.x, a.y + b.y, a.z + b.z);
     return result;
}

Vec3 subtract(Vec3 a, Vec3 b){
    Vec3 result(a.x - b.x, a.y - b.y, a.z - b.z);
    return result;
}

double dot(Vec3 a, Vec3 b){
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

double evalPoly(std::vector<double> coeffs, double x){
    double result = 0;
    for (int i = 0; i < coeffs.size(); i++){
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

int main(){
    Vec3 v1(5, 7, 8);
    Vec3 v2(2, 5, 4);
    Vec3 v3 = add(v1, v2);
    assert(v3.x == 7);
    assert(v3.y == 12);
    assert(v3.z == 12);
    Vec3 v4 = subtract(v1, v2);
    assert(v4.x == 3);
    assert(v4.y == 2);
    assert(v4.z == 4);
    double dotProduct = dot(v1, v2);
    assert(dotProduct == 10 + 35 + 32);
    std::vector<double> p = {1,0,2};
    double p3 = evalPoly(p, 3);
    assert(p3 == 1 + (2 * 9));
    std::cout << "All Test Passed\n";
    return 0;
}