#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 4) {
        std::cout << "Put the filename, s1 and s2. s1 is the char who you want to replace with s2" << std::endl;
        return 1;
    }

    std::string filename = av[0];
    std::string s1 = av[1];
    std::string s2 = av[2];
    ifstream inFile;

    inFile.
}
