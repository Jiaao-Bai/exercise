/*
生成10亿个int64随机数，保存在当前目录下
g++  generateRandomNum.cpp -o generate
*/
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <cstdlib>
#include <ctime>
#include <string>

#define GENERATE_SIZE 1e4
#define DATA_PATH "data.txt"

int main(int argc, const char *argv[]){
    if(GENERATE_SIZE>0xffffffff){//uint32_t max value
        std::cerr<<"generate size too large"<<std::endl;
        return 0;
    }
    FILE *output_file = fopen(DATA_PATH, "w");
    if(errno!=0){
        std::cerr<<"open file fail"<<std::endl;
        return 0;
    }

    srand((uint32_t)time(NULL));

    uint32_t index;
    std::string temp_num_str;
    for(index=0; index<GENERATE_SIZE; index++){
        temp_num_str = std::to_string(rand());
        fputs(temp_num_str.c_str(), output_file);
        fputs(",", output_file);
    }
    return 0;
}
