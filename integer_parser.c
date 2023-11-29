/*
 * Copyright (C) 2022-present Zhenrong WANG https://github.com/zhenrong-wang
 * This code is distributed under the license: MIT License
 * Originally written by Zhenrong WANG
 * mailto: zhenrongwang@live.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//validate the integer string to be parsed out

int validate_interger_string(const char* input_integer_string, char* output_string){
    int length=strlen(input_integer_string);
    int sum=0;
    int start_digit_flag=0;
    int curr_digit=0;
    int output_j=0;
    if(length<1){
        return -1;
    }
    for(int i=0;i<length;i++){
        if(*(input_integer_string+i)<'0'||*(input_integer_string+i)>'9'){
            return -3; // Illegal char found.
        }
        if(*(input_integer_string+i)!='0'){
            start_digit_flag=1; // Found the first non-zero digit.
        }
        curr_digit=*(input_integer_string+i)-'0';
        sum+=curr_digit*pow(10,length-i-1);
        if(start_digit_flag==1){
            *(output_string+output_j)=*(input_integer_string+i);
            output_j++;
        }
    }
    if(sum>255){
        return -5; // Out of range (0~255)
    }
    else if(sum==0){
        *(output_string+0)='0';
        return 1;
    }
    else{
        return output_j;
    }
}

// argv1: an ascii-utf8 string
// argv2: integer_string to be parsed out

int main(int argc, char** argv){
    if(argc<3){
        printf("USAGE  : COMMAND UTF_STRING INTEGER_STRING(0~255).\n");
        printf("FATAL  : Insufficient command args.\n");
        return 1; // There must be at least 2 argvs.
    }
    char real_int_string[256]="";
    int length2=validate_interger_string(argv[2],real_int_string);

    if(length2<0){
        printf("USAGE  : COMMAND UTF_STRING INTEGER_STRING(0~255).\n");
        printf("FATA   : The integer string %s is invalid.\n",argv[2]);
        return 3; // The integer string is invalid.
    }
    printf("INFO   : Parsing the integer %s started ...\n\n",real_int_string);
    int length1=strlen(argv[1]);
    int i=0,j=0,flag=0,count=0;
    if(length1<length2){
        printf("\nSUMMARY: The UTF string %s is too short, parsed out 0 integer string %s.\n",argv[1],real_int_string);
        return 255; // The given ascii-utf8 string is short than the integer string. Exit.
    }
    while(i<length1-length2+1){
        if(*(argv[1]+i)!=*(real_int_string+0)){
            i++;
            continue;
        }
        flag=0;
        for(j=1;j<length2;j++){
            if(*(argv[1]+i+j)!=*(real_int_string+j)){
                flag=1;
                break;
            }
        }
        if(flag==0){
            count++;
            printf("FOUND  : Parsed out %s at position %d, # %d.\n",real_int_string,i,count);
            i+=length2;
        }
        else{
            i++;
        }
    }
    printf("\nSUMMARY: Parsed out %d integer string %s.\n",count,real_int_string);
    return 0; // Succeeded, nothing abnormal
}
