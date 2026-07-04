#include <iostream>
#include <memory>

int main(){
    std::unique_ptr<int> p1 = std::make_unique<int>(42);
    std::cout << *p1 << "\n";

    std::unique_ptr<int> p2 = p1;
    return 0;
}