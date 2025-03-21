#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
    uintptr_t raw;
    Data data;
    Data *data_by_raw;

    data.city = "Paris";
    data.country = "France";
    data.population_count = 2113705;
    data.postal_code = 75000;

    // TEST SERIALIZE

    raw = Serializer::serialize(&data);
    std::cout << "address of data : " << raw << std::endl << std::endl;

    // TEST DESERIALIZE

    data_by_raw = Serializer::deserialize(raw);
    std::cout << data_by_raw->country << std::endl;
    std::cout << data_by_raw->city << std::endl;
    std::cout << data_by_raw->population_count << std::endl;
    std::cout << data_by_raw->postal_code << std::endl;

    return 0;
}