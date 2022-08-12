#undef NDEBUG
#define ZIP_VECTOR_TRACE 1
#include <zip_vector.h>
#include "test-zip-vector-common.h"

struct vertex
{
    float pos[3];
    float norm[3];
    float uv[2];
    int col;
};

void t1()
{
    block_random<i64> rng;
    zip_vector<i64> vec;

    /* visual inspection of index for pointer array */
    vec.resize(512);
    for (size_t i = 0; i < 512; i++) {
        vec[i] = (intptr_t)(void*)malloc(sizeof(vertex));
    }
    vec.sync();

    dump_index(vec);
}

int main(int argc, const char **argv)
{
    parse_options(argc, argv);
    t1();
}
