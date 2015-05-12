#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void quadratic_formula(float a, float b, float c){
    float discriminant = b * b - 4 * a * c;
    float ans1, ans2;

    if (discriminant > 0){
        ans1 = ( -b + sqrt(discriminant) ) / (2*a);
        ans2 = ( -b - sqrt(discriminant) ) / (2*a);
        printf("2次方程式の解: x = %f, %fです\n",ans1 ,ans2);
    }else if (discriminant == 0){
        ans1 = -b / ( 2 * a );
        printf("2次方程式の解: x = %f (2重解)です\n",ans1);
    }else{
        float real = -b / (2*a);
        float imag = sqrt(-discriminant) / (2*a);
        printf("2次方程式の解: x = %.2f+%.2fi, %.2f-%.2fです\n", real, imag, real, imag);
    }
}


float calc_other_quadratic_formula(float a, float c, float x){
    return c / (a * x);
}

void new_quadratic_formula(float a, float b, float c){
    float discriminant = b * b - 4 * a * c;
    float ans1, ans2;

    if(discriminant > 0){
        if(b < 0){
            ans1 = ( -b + sqrt(discriminant) ) / (2*a);
            ans2 = calc_other_quadratic_formula(a, c, ans1);
        } else {
            ans2 = ( -b - sqrt(discriminant) ) / (2*a);
            ans1 = calc_other_quadratic_formula(a, c, ans2);
        }
        printf("2次方程式の解: x = %f, %fです\n",ans1 ,ans2);
    }else if (discriminant == 0){
        ans1 = -b / ( 2 * a );
        printf("2次方程式の解: x = %f (2重解)です\n",ans1);
    }else{
        float real = -b / (2*a);
        float imag = sqrt(-discriminant) / (2*a);
        printf("2次方程式の解: x = %.2f+%.2fi, %.2f-%.2fです\n", real, imag, real, imag);
    }
}

int main(void){
    float a, b, c;

    printf("係数を入力して下さい。\n");
    printf("a > ");
    scanf("%f",&a);
    printf("b > ");
    scanf("%f",&b);
    printf("c > ");
    scanf("%f",&c);

    // 解の公式
    printf("\nそのまま計算した場合\n");
    quadratic_formula(a, b, c);
    printf("\n桁落ち・情報落ちを回避する方法で計算した解\n");
    new_quadratic_formula(a, b, c);
    return 0;
}
