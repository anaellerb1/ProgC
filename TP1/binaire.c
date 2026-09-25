#include <stdio.h>

int main() {
    int nombres = 4096;
    int ref = nombres;
    int bits[32]; 
    int index = 0;


    while (nombres > 0) {
        bits[index] = nombres % 2; 
        nombres /= 2; 
        index++;
    }
    
    printf("%d en binaire: ", ref);
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", bits[i]);
    }
    printf("\n");

}
