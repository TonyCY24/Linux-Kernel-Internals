#include <stdint.h>
#include <stdio.h>

#define GOLDEN_RATIO_32 0x61C88647
/*
#ifndef HAVE_ARCH__HASH_32
#define __hash_32 __hash_32_generic
#endif
*/

static inline uint32_t __hash_32_generic(uint32_t val) 
{
    return val * GOLDEN_RATIO_32;
}

static inline uint32_t hash_32(uint32_t val, unsigned int bits, uint32_t constant)
{
    return (val * constant) >> (32 - bits);
}

int main(void) {

    FILE *fp = fopen("hash_32.csv", "w");
   
    fprintf(fp, "buckets, GOLDEN_RATIO_32, 0x80000000, 0x12345678, 0x54061094\n");

    int count[4][1024] = {0};
    uint32_t constants[] = {GOLDEN_RATIO_32, 0x80000000, 0x12345678, 0x54061094};

    for (int k = 0; k <= 10000; k++) {
        for (int c = 0; c < 4; c++) {
            int index = hash_32(k, 10, constants[c]);
            count[c][index]++;
        }
    }

    for (int i = 0; i < 1024; i++) 
        fprintf(fp, "%d,%d,%d,%d,%d\n", i, count[0][i], count[1][i], count[2][i], count[3][i]);
    
    fclose(fp);
    return 0;
}