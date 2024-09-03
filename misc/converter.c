#include <stdio.h>

void printBinary(int value){
    if (value / 2 == 0)
        return;
    printf("Binary digit \n %d",value % 2);
    printBinary(value / 2 );
    

}
int main(){
    char word []  = "Helo!3";
        int asciiValue = word[0];
        printf("digit %d", asciiValue);
        printBinary(asciiValue);


        
    return 0;
}
