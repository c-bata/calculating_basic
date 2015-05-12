#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float increment(float n){
    int i;
    float sum = 0;
    for (i=0; i<(int)n; i++){
        sum += 1/((float)i+1);
    }
    return sum - log(n);
}

float decrement(float n){
    int i;
    float sum = 0;
    for (i=(int)n; i>0; i--){
        sum += 1/(float)i;
    }
    return sum - log(n);
}

int main(void){
    float n;

    printf("nを入力して下さい。\n");
    printf("n > ");
    scanf("%f",&n);

    printf("1/1から1/n: %f\n", increment(n));
    printf("1/nから1/1: %f\n", decrement(n));
    return 0;
}
