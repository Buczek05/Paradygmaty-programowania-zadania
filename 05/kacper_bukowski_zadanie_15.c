#include <stdio.h>
#include <stdint.h>

struct MyStruct {
    int8_t a;
    int8_t b;
};

union MyUnion {
    struct MyStruct myStruct;
    int16_t myInt16;
};

int main() {
    union MyUnion myUnion;

    myUnion.myStruct.a = 0x12;
    myUnion.myStruct.b = 0x34;

    printf("a = %x\n", myUnion.myStruct.a);
    printf("b = %x\n", myUnion.myStruct.b);
    printf("myInt16 = %x\n", myUnion.myInt16);

    return 0;
}
