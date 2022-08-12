#undef NDEBUG
#define ZIP_VECTOR_TRACE 1
#include <zip_vector.h>
#include "test-zip-vector-common.h"

void t1()
{
    block_random<i64> rng;
    zip_vector<i64> vec;

    enum test : size_t { test_size = 8192, page_interval = 512 };

    /* cause 7-bit random to be written to the array */
    vec.resize(test_size);
    for (size_t i = 0; i < vec.size(); i++) {
        vec[i] = rng.abs_i7();
    }

    /* check sum for indexed access vs iterator access */
    i64 sum1 = 0, sum2 = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        sum1 += vec[i];
    }
    for (auto v : vec) {
        sum2 += v;
    }
    assert(sum1 == sum2);

    dump_index(vec);
}

int main(int argc, const char **argv)
{
    parse_options(argc, argv);
    t1();
}
