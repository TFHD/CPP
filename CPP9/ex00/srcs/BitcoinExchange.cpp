#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string _file) : file(_file.c_str())
{
    if (LOG)
        std::cout << "\e[32mThe BitcoinExchange\e[0m default was created !" << std::endl;
    if (4 >= _file.length())
        throw std::runtime_error(ERR_FILE_FORMAT);
    if (_file.compare(_file.length() - 4, 4, ".csv") != 0)
        throw std::runtime_error(ERR_FILE_FORMAT);
}

BitcoinExchange::~BitcoinExchange(void)
{
    if (LOG)
        std::cout << "\e[32mThe BitcoinExchange\e[0m was destroyed !" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
    if (LOG)
        std::cout << "\e[32mThe BitcoinExchange\e[0m was copied !" << std::endl;
   *this = cpy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[32mThe Span\e[0m Assignation operator called" << std::endl; }
    this->data = src.data;
	return *this;
}

int BitcoinExchange::checkFormatFile(std::string line, char delimiter)
{
    int time_occ = std::count(line.begin(), line.end(), delimiter);
    if (time_occ != 1)
        return 1;
    std::string before = line.substr(0, line.find(delimiter));
    std::string after = line.substr(line.find(delimiter) + 1, line.size());
    for (int i = 0; i < (int)before.size(); i++) {
        if (!std::isalnum(before[i]) && before[i] != ' ' && before[i] != '_')
            return 1;
        if (i == (int)before.size() - 1 && before[i] != ' ' && delimiter == '|')
            return 1;
    }
    for (int i = 0; i < (int)after.size(); i++) {
        if (i == 0 && after[i] != ' ' && delimiter == '|')
            return 1;
        if (!std::isalnum(after[i]) && after[i] != ' ' && after[i] != '_')
            return 1;
    }
    return 0;
}

void BitcoinExchange::loadData(void)
{
    std::ifstream data_file(this->file);
    std::string line;
    std::string date;
    std::string value_after_date;
    float value;

    if (!data_file.is_open())
        throw std::runtime_error(ERR_OPEN);

    getline(data_file, line);
    if (line.empty())
        throw std::runtime_error("Error : Nothing into data.csv");
    if (checkFormatFile(line, ',')) {
        throw std::runtime_error(BAD_FORMAT);
    }

    while(getline(data_file, line))
    {
        date = line.substr(0, line.find(","));
        if (isGoodDate(date))
            throw std::runtime_error(BAD_FORMAT);
        value_after_date = line.substr(line.find(",") + 1, line.size());
        if (value_after_date.empty() || !std::isdigit(value_after_date[0]))
            throw std::runtime_error(BAD_FORMAT);
        value = std::strtof(value_after_date.c_str(), NULL);
        this->data.insert(std::make_pair(date, value));
    }
    data_file.close();
    if (this->data.size() == 0)
        throw std::runtime_error("Error : Nothing into data.csv");
}

float BitcoinExchange::getValue(std::string date) const
{
    return (this->data.at(date));
}

int BitcoinExchange::getScore(const std::string date1, std::string date2) const
{
    int year1 = std::atoi((date1.substr(0, 4)).c_str());
    int month1 = std::atoi((date1.substr(5, 7)).c_str());
    int day1 = std::atoi((date1.substr(8, 10)).c_str());
    int year2 = std::atoi((date2.substr(0, 4)).c_str());
    int month2 = std::atoi((date2.substr(5, 7)).c_str());
    int day2 = std::atoi((date2.substr(8, 10)).c_str());
    if (year2 >= year1)
    {
        month2 = month2 - month1;
        day2 = day2 - day1;
    }
    else
        day2 = -std::abs(day2 - 31) - 2;
    return ((year2 - year1) * 366 + (month2) * 30.5 + (day2));
}

std::string BitcoinExchange::getNearDate(std::string date) const
{
    if (isGoodDate(date)) {
        std::cout << BAD_INPUT << date << std::endl;
        return "";
    }
    int score = getScore(this->data.begin()->first, date);
    std::map<std::string, float>::const_iterator it = this->data.begin();
    std::map<std::string, float>::const_iterator ite = this->data.begin();
    std::string date_result = it->first;
    ite--;
    ite--;
    while (it != ite) {
        int tmp_score = getScore(it->first, date);
        if (tmp_score >= 0 && tmp_score < score) {
            score = tmp_score;
            date_result = it->first;
        }
        it++;
    }
    return date_result;
}

int BitcoinExchange::isGoodDate(std::string date)
{
    if (date.size() != 10)
        return 1;
    if (date[4] != '-' || date[7] != '-')
        return 1;
    for (int i = 0; i < 10; i++) {
        if (!std::isdigit(date[i]))
            return 1;
        if (i == 3 || i == 6)
            i++;
    }

    int year = std::atoi((date.substr(0, 4)).c_str());
    int month = std::atoi((date.substr(5, 7)).c_str());
    int day = std::atoi((date.substr(8, date.size())).c_str());
    if (month == 4 || month == 6 || month == 9 || month == 11 || month == 2) {
        if (day >= 31)
            return 1;
    }
    if (month == 0 || day == 0 || month > 12 || day > 31)
        return 1;
    if (day > 28 && month == 2) {
        if (!(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
            return 1;
    }
    return 0;
}

void BitcoinExchange::printChangeBitcoinValue(std::string file)
{
    std::ifstream file_fd(file.c_str());
    std::string line;
    std::string date;
    std::string date_nearest;
    std::string after_pipe;
    float value;

    if (!file_fd.is_open())
        throw std::runtime_error(ERR_OPEN);

    getline(file_fd, line);
    if (checkFormatFile(line, '|')) {
        throw std::runtime_error(BAD_FORMAT);
    }

    while (getline(file_fd, line)) {
        date = line.substr(0, line.find("|") - 1);
        date_nearest = getNearDate(date);
        after_pipe = line.substr(line.find("|") + 1, line.size());
        value = std::strtof(after_pipe.c_str(), NULL);
        if (line[line.find("|") + 1] != ' ') {
            std::cout << BAD_INPUT << date << std::endl;
            continue;
        }
        if (!(std::istringstream(after_pipe) >> value))
            std::cout << ERR_NAN << std::endl;
        if (!date_nearest.empty() && (value < 0 || value > 1000)) {
            if (value < 0)
                std::cout << ERR_NEG_NUMBER << std::endl;
            else if (value > 1000)
                std::cout << ERR_SIZE_NUMBER << std::endl;
        }
        else if (!date_nearest.empty() && (std::istringstream(after_pipe) >> value)) {
            std::cout << date << " => " << value << " = " << getValue(date_nearest) * value << std::endl;
        }
    }
}
