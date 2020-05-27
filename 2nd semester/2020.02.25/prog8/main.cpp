/*(10 баллов) Создать структуру с ~8 полями.
 * Экспериментально выяснить, как устроена укладка объекта такой структуры в памяти.
 */
#include <iostream>
using namespace std;

struct IpHeader
{
    uint8_t header_length:4;
    uint8_t version:4;
    uint8_t type_of_service;
    uint16_t total_length;
    uint16_t identificator;

    // Flags
    uint8_t _reserved:1;
    uint8_t dont_fragment:1;
    uint8_t more_fragments:1;

    uint8_t fragment_offset_part1:5;
    uint8_t fragment_offset_part2;
    uint8_t time_to_live;
    uint8_t protocol;
    uint16_t checksum;

};

int main()
{
    cout << "The size of IpHeader is " << sizeof(IpHeader) << "\n";
    return 0;
}