#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void quadratic_formula(double a, double b, double c){
    double discriminant = b * b - 4 * a * c;
    double ans1, ans2;

    if (discriminant > 0){
        ans1 = ( -b + sqrt(discriminant) ) / (2*a);
        ans2 = ( -b - sqrt(discriminant) ) / (2*a);
        printf("2次方程式の解: x = %f, %fです\n",ans1 ,ans2);
    }else if (discriminant == 0){
        ans1 = -b / ( 2 * a );
        ans2 = ans1;
        printf("2次方程式の解: x = %f, %fです\n",ans1 ,ans2);
    }else{
        double real = -b / (2*a);
        double imag = sqrt(-discriminant) / (2*a);
        printf("2次方程式の解: %.2f+%.2fi, %.2f-%.2fi\n", real, imag, real, imag);
    }

}

int main(void){
    double a, b, c;

    printf("係数を入力して下さい。\n");
    printf("a > ");
    scanf("%lf",&a);
    printf("b > ");
    scanf("%lf",&b);
    printf("c > ");
    scanf("%lf",&c);

    // 解の公式
    quadratic_formula(a, b, c);
    return 0;
}
