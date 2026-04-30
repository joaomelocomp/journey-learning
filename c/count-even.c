#include <stdio.h>

int main(){
    int numbers[] = {1, 2, 3, 4, 5, 6, 7 , 8, 9, 10};
    int count = 0;

    int lensize = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < lensize; i++){
        if (i % 2 == 0){
            count++;
        }
    }

    printf("%d", count);

    return 0;
}