#include "hardware/pio.h"
#include "pico/stdlib.h"

typedef          uint32_t   VALUE;
typedef volatile uint32_t* ADDRESS;


VALUE register_read(ADDRESS  address) {
    return *address;
}

void register_write(ADDRESS address, VALUE value) {
    *address = value;
}
