#include "functions.h"
int main()
{
    //bintotxt();// if you want to translate binary file into 1010.txt file (as 101010101...)
    test();
    return 0;
}
// Created by usiox on 13.03.2022.
//

/*  Why this program is stupid?
 *  We are translating 8 bits into char to write it into a file as 8*8 bits (1 and 0 in txt file are bytes-8 bits)
 *  In this situation we are wasting 8x more disk capacity than needed
 *  Next we are comparing these 1 and 0 as string to other 1 and 0 strings that we made from int, in this situation
 *  instead of comparing fe. 10010 to 11111 as bits we are comparing "10010" to "11111" strings that contain 40 bits
 *  each instead of 5. That's because Vegetto is stupid - he should use std::bitset
 *.
 *  "Brainfuck>C++"
 *  ~Vegetto
 */

