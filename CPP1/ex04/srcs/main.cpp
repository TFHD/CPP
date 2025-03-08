#include <fstream>
#include <string>
#include <iostream>

std::string    replace(std::string line, std::string s1, std::string s2)
{
    std::string final_line = line;

    for (int i = 0; i < (int)final_line.length(); i++) {
        if (final_line[i] == s1[0]) {
            for (int j = 0; final_line[j + i] == s1[j]; j++) {
                if (j == (int)s1.length() - 1) {
                    final_line = final_line.substr(0, i) + s2 + final_line.substr(i + j + 1, (int)final_line.length());
                    i += s2.length() - 1;
                    break;
                }
            }
        }
    }
    return final_line;
}

int main(int ac, char **av)
{
    if (ac != 4) {
        std::cout << "Put the filename, s1 and s2. s1 is the char who you want to replace with s2" << std::endl;
        return 1;
    }
    std::ifstream inFile;
    std::ofstream outFile;
    std::string replace_file = (std::string)av[1] + ".replace";
    std::string line;
    std::string final_line;

    inFile.open(av[1]);
    if (inFile.fail()) {
        std::cout << "Error while opening file" << std::endl;
        return 1;
    }
    outFile.open(replace_file.c_str());
    if (outFile.fail()) {
        std::cout << "Error while opening file" << std::endl;
        inFile.close();
        return 1;
    }
    while (std::getline(inFile, line)) {
        final_line = replace(line, av[2], av[3]);
        outFile << final_line << std::endl;
    }
    outFile.close();
    inFile.close();
}
