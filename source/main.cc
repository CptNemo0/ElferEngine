#include <iostream>
#include <fstream> 
#include <string>
#include "entt/entt.hpp"
#include "glm/glm.hpp"

int main()
{
    std::ifstream stream ("resources/text.txt");

    char c = stream.get();

    while (stream.good()) {
        std::cout << c;
        c = stream.get();
    }

    std::cin >> c;

    std::cout << "AAAAAAAAA\n";

    return 0;
}
