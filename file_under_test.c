#include <stdio.h>
#include <stdint.h>

struct myReg_S
{
    uint8_t byte1;
    uint8_t byte2;
};

union myUnion_U
{
    uint8_t R[2];
    struct myReg_S reg;
};

struct myStruct_S
{
    union myUnion_U u1;
    union myUnion_U u2;
};

int main(void)
{
    struct myStruct_S s =
    {
        .u1 =
        {
            .R = { 0, 1 }
        },
        .u2 =
        {
            .reg =
            {
                .byte1 = 0,
                .byte2 = 1
            }
        }
    };

    printf("u1: %d %d\n", s.u1.R[0], s.u1.R[1]);
    printf("u2: %d %d", s.u2.reg.byte1, s.u2.reg.byte2);
}
