#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac < 2 || ac >= 3)
    {
        std::cerr << ERR_OPEN << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange btc("data.csv");
        btc.loadData();
        btc.printChangeBitcoinValue(av[ac - 1]);
    }
    catch(const std::exception &e) { std::cerr << e.what() << '\n'; }
    return 0;    
}