#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cstdlib>
# include <algorithm>
# include <sstream>

# define LOG 0
# define BAD_INPUT "Error : bad input => "
# define BAD_FORMAT "Error : bad format"
# define ERR_OPEN "Error : could not open file"
# define ERR_NEG_NUMBER "Error : not a positive number"
# define ERR_SIZE_NUMBER "Error : too large number"
# define ERR_FILE_FORMAT "Error : bad data file format, .csv file is required !"
# define ERR_NAN "Error : this is not a number !"

class BitcoinExchange {

    private:
        const char *file;
        std::map<std::string, float> data;

    public:
        BitcoinExchange(std::string file);
        ~BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &cpy);
        BitcoinExchange &operator=(const BitcoinExchange &src);

        void loadData(void);
        float getValue(std::string date) const;
        std::string getNearDate(std::string date) const;
        int getScore(const std::string date1, std::string date2) const;
        static int isGoodDate(std::string date);
        void printChangeBitcoinValue(std::string file);
        int  checkFormatFile(std::string line, char delimiter);
};


#endif