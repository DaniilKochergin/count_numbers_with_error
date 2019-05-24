#include "filter_bloom.h"

void filter_bloom::add(int x) {
    uint32_t pos = x * p;
    pos %= SIZE;

    if (((filter[pos >> 5u] >> (pos % 32u)) & 1u) == 0) {
        uniq_num++;
        filter[pos >> 5u] |= (1u << (pos % 32u));
    }

}

int filter_bloom::get_uniq_num() const {
    return uniq_num + uniq_num / 10;
}