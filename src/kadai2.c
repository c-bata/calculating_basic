#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double increment(double n){
    int i;
    double sum = 0;
    for (i=0; i<n; i++){
        sum = 1/(i+1);
    }
    return sum - log(n);
}

double decrement(double n){
    int i;
    double sum = 0;
    for (i=n; i<0; i--){
        sum = 1/i;
    }
    return sum - log(n);
}



int main(void){
    double n;

    printf("nを入力して下さい。\n");
    printf("n > ");
    scanf("%lf",&n);

    printf("1/1から1/n: %f\n", increment(n));
    printf("1/nから1/1: %f\n", decrement(n));
    return 0;
}
