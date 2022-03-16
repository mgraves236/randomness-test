#ifndef RANDOMNESS_TEST_FUNCTIONS_H
#define RANDOMNESS_TEST_FUNCTIONS_H

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include "namespace_std.h"
void dec_to_bin(){
    fstream fbin ;
    fbin.open("bin.txt");
    fstream fdec;
    fdec.open("dec.txt");

    string data;
    fdec>>data;
    double quot,remain;
    for(int i=0;i<<data.length()){

    }
    //todo kurwa, nie chce mi się tego robić jesli nie muszę.

    fdec.close();
    fbin.close();
}

void test(){
    fstream fbin ;
    fbin.open("bin.txt");
    fstream fres ;
    fres.open("bin.txt");

    //todo,

    fbin.close();
    fres.close();
}


#endif //RANDOMNESS_TEST_FUNCTIONS_H
