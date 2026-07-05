#include <fstream>

int main(){
    std::ofstream outfile("gradient.ppm");
    if (!outfile){
        return 1;
    }
    outfile << "P3\n";
    outfile << "100 100\n";
    outfile << "255\n";
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            int color = (int)((double)j / 99 * 255);
            outfile << color << " 0 0  ";
        }
    }

    return 0;
}