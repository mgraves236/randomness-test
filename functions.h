#ifndef RANDOMNESS_TEST_FUNCTIONS_H
#define RANDOMNESS_TEST_FUNCTIONS_H

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <thread>
#include <bitset>
#include "namespace_std.h"
#include <filesystem>
#define N 10 // number of digits in the biggest pattern
string rnum;// because multithread is copying variables, without global string we will make 4 copies of
            // rnum 800 MB each, i'm stupid so i don't have any better ideas


void pseudorandom(int n){
    //todo, function will return n random numbers to file
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

void check_pattern(std::ofstream &fres, int i, int j){
    string potatoe=pattern_maker(i,j);
    double count=0;
    for(int k=0;k<rnum.length()-i;k++) {//count pattern in random generated number
        if(rnum.substr(k,i)==potatoe){
            count++;
        }
    }
    cout<<i<<'\t'<<potatoe<<'\t'<<count<<'\t'<<count/(rnum.length()-i)*100<<'\t'<< 1/(double)pow(2,i)*100 <<endl;
    fres<<i<<'\t'<<potatoe<<'\t'<<count<<'\t'<<count/(rnum.length()-i)*100<<'\t'<< 1/(double)pow(2,i)*100 <<endl;
}

void test(){
    std::ifstream fbin ;
    fbin.open("1010.txt",std::ios::out);
    std::ofstream fres ;
    fres.open("test_results.txt", std::ios::in | std::ios::out );
    fres<<"p.length"<<"pattern"<<'\t'<<"pattern count"<<'\t'<<"percentage"<<'\t'<<"should-be %"<<endl;
    if(fres.is_open())cout<<"p.length"<<"pattern"<<'\t'<<"pattern count"<<'\t'<<"percentage"<<'\t'<<"should-be %"<<endl;

    //bintotxt();
    string potatoe; // string named after you
    fbin>>rnum;
    double count=0;
    for(int i=1;i<=N;i++){//how big is pattern?, pow(2,i) is pattern size
        for(int j=0;j<pow(2,i);j=j+4){//set pattern, j is pattern in decimal
            if(i==1){//2 threads
                std::thread t1 (check_pattern,std::ref(fres), i, j);
                std::thread t2 (check_pattern,std::ref(fres), i, j+1);
                t1.join();
                t2.join();
            }
            else{//4 threads
                std::thread t1 (check_pattern,std::ref(fres), i, j);
                std::thread t2 (check_pattern,std::ref(fres), i, j+1);
                std::thread t3 (check_pattern,std::ref(fres), i, j+2);
                std::thread t4 (check_pattern,std::ref(fres), i, j+3);
                t1.join();
                t2.join();
                t3.join();
                t4.join();
            }
        }
    }

    fbin.close();
    fres.close();
}


#endif //RANDOMNESS_TEST_FUNCTIONS_H
