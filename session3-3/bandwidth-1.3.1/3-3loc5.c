#include <stdint.h>
#include <stdio.h>

#define NROWS    128 // 2^7 rows
#define NCOLS    128 // 2^7 cols
#define NTIMES   10   // Repeat 100000 times

// Matrix size 2^13 = 16 * 8^3 = 16 kBytes
uint8_t matrix[NROWS][NCOLS];

int main(void)
{
    int i, j, rep;

    for (rep = 0; rep < NTIMES; rep++)
    {
        for (i = 0; i < NROWS; i++)
        {
            for(j = 0; j < NCOLS; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
