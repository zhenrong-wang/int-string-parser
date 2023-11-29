#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//validate the integer string to be parsed out

int validate_interger_string(const char* input_integer_string){
    int length=strlen(input_integer_string);
    int sum=0;
    if(length>3||length<1){
        return -1; // If the length > 3 or <1, it is definitely not 0~255, exit.
    }
    for(int i=0;i<length;i++){
        if(*(input_integer_string+i)<'0'||*(input_integer_string+i)>'9'){
            return -3; // Illegal char found.
        }
        sum+=(*(input_integer_string+i)-'0')*pow(10,length-i-1);
    }
    if(sum>255){
        return -5; // Out of range (0~255)
    }
    return sum;
}

// argv1: an ascii-utf8 string
// argv2: integer_string to be parsed out

int main(int argc, char** argv){
    if(argc<3){
        printf("USAGE  : COMMAND UTF_STRING INTEGER_STRING(0~255).\n");
        printf("FATAL  : Insufficient command args.\n");
        return 1; // There must be at least 2 argvs.
    }
    if(validate_interger_string(argv[2])<0){
        printf("USAGE  : COMMAND UTF_STRING INTEGER_STRING(0~255).\n");
        printf("FATA   : The integer string %s is invalid.\n",argv[2]);
        return 3; // The integer string is invalid.
    }
    int length1=strlen(argv[1]);
    int length2=strlen(argv[2]);
    int i=0,j=0,flag=0,count=0;
    if(length1<length2){
        printf("\nSUMMARY: The UTF string %s is too short, parsed out 0 integer string %s.\n",argv[1],argv[2]);
        return 255; // The given ascii-utf8 string is short than the integer string. Exit.
    }
    while(i<length1-length2+1){
        if(*(argv[1]+i)!=*(argv[2]+0)){
            i++;
            continue;
        }
        flag=0;
        for(j=1;j<length2;j++){
            if(*(argv[1]+i+j)!=*(argv[2]+j)){
                flag=1;
                break;
            }
        }
        if(flag==0){
            count++;
            printf("FOUND  : Parsed out %s at position %d, # %d.\n",argv[2],i,count);
            i+=length2;
        }
        else{
            i++;
        }
    }
    printf("\nSUMMARY: Parsed out %d integer string %s.\n",count,argv[2]);
    return 0; // Succeeded, nothing abnormal
}