#ifndef VK
#define VK

#include <cstdint>

struct filter_bloom {
    filter_bloom() = default;

    ~filter_bloom() = default;

    filter_bloom(filter_bloom &bloom) = default;

    filter_bloom &operator=(filter_bloom const &other) = default;

    void add(int x);

    int get_uniq_num() const;

private:
    const static std::size_t SIZE_ARRAY = 255 * 1024 * 8;
    const static std::size_t SIZE = SIZE_ARRAY * sizeof(uint32_t);
    uint32_t uniq_num = 0;
    uint32_t filter[SIZE_ARRAY]{};
    uint32_t p = 31;
};

#endif //VK