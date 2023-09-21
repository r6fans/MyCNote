#include <stdio.h>

void change(char ch[][3]){
    ch[0][0] = 'n';
}

int main(){
    char cs[2][3] = {
        {'a','b','c'};
        {'d','e','f'}
    };
    printf("cs[0][0] = %c\n", cs[][]);
    change(cs);
    printf("cs[0][0] = %c\n", cs[0][0]);
    return 0;
}