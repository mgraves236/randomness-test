#ifndef RANDOMNESS_TEST_FUNCTIONS_H
#define RANDOMNESS_TEST_FUNCTIONS_H

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include "namespace_std.h"
#include <filesystem>
#define N 10 // number of digits in the biggest pattern

void pseudorandom(int n){
    std::ofstream txt;
    txt.open("1010.txt",std::ios::out | std::ios::binary);

}
void bintotxt(){// function will translate binary file to txt file, every 1 and 0 will become char 0 or 1
    std::ifstream binary ;
    binary.open("QNGFile.dat",std::ios::out | std::ios::binary);
    std::ofstream txt;
    txt.open("1010.txt",std::ios::out | std::ios::binary);
    string rnum;// string for random number
    char byte;
    while(binary.get(byte))
    txt<<std::bitset< 8 >( byte );
    txt.close();
    binary.close();
}

string pattern_maker(int size,int n){//Look at the function name... It's not so hard
    {
        string r="";
        while(n!=0) {
            r=(n%2==0 ?"0":"1")+r;
            n/=2;
        }

        while(r.length()<size){// because we want 0011 for 4-digit pattern, without it we will get 11
            r="0"+r;
        }
        return r;
    }
}
void test(){
    std::ifstream fbin ;
    fbin.open("1010.txt",std::ios::out);
    std::ofstream fres ;
    fres.open("test_results.txt", std::ios::in | std::ios::out );
    fres<<"pattern"<<'\t'<<"pattern count"<<'\t'<<"percentage"<<'\t'<<"should-be %"<<endl;
    if(fres.is_open())cout<<"pattern"<<'\t'<<"pattern count"<<'\t'<<"percentage"<<'\t'<<"should-be %"<<endl;

    //bintotxt();
    string rnum;// string for random number
    string potatoe; // string named after you
    fbin>>rnum;
    double count=0;
    for(int i=1;i<=N;i++){//how big is pattern?, pow(2,i) is pattern size
        for(int j=0;j<pow(2,i);j++){//set pattern, j is pattern in decimal
            potatoe=pattern_maker(i,j);
            count=0;
            for(int k=0;k<rnum.length()-i;k++) {//count pattern in random generated number
                if(rnum==potatoe){
                    count++;
                }
            }
            cout<<potatoe<<'\t'<<count<<'\t'<<count/(rnum.length()-i)*100<<'\t'<< 1/(double)pow(2,i)*100 <<endl;
            fres<<potatoe<<'\t'<<count<<'\t'<<count/(rnum.length()-i)*100<<'\t'<< 1/(double)pow(2,i)*100 <<endl;
        }
    }

    fbin.close();
    fres.close();
}


#endif //RANDOMNESS_TEST_FUNCTIONS_H
