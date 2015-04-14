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
        printf("2次方程式の解: x = %f (2重解)です\n",ans1);
    }else{
        double real = -b / (2*a);
        double imag = sqrt(-discriminant) / (2*a);
        printf("2次方程式の解: x = %.2f+%.2fi, %.2f-%.2fです\n", real, imag, real, imag);
    }

}

void new_quadratic_formula(double a, double b, double c){
    double discriminant = b * b - 4 * a * c;
    double ans1, ans2;

    if(discriminant > 0){
        ans1 = (-2*c) / (b + sqrt(b*b - 4*a*c));
        ans2 = (2*c) / (-b + sqrt(b*b - 4*a*c));
        printf("2次方程式の解: x = %f, %fです\n",ans1 ,ans2);
    }else if (discriminant == 0){
        ans1 = (-2 * c) / b;
        printf("2次方程式の解: x = %f (2重解)です\n",ans1);
    }else{
        double real = -b / (2*a);
        double imag = sqrt(-discriminant) / (2*a);
        printf("2次方程式の解: x = %.2f+%.2fi, %.2f-%.2fです\n", real, imag, real, imag);
    }
}

void kadai1(void){
    double a, b, c;

    printf("係数を入力して下さい。\n");
    printf("a > ");
    scanf("%lf",&a);
    printf("b > ");
    scanf("%lf",&b);
    printf("c > ");
    scanf("%lf",&c);

    // 解の公式
    printf("\nそのまま計算した場合\n");
    quadratic_formula(a, b, c);
    printf("\n桁落ち・情報落ちを回避する方法で計算した解\n");
    new_quadratic_formula(a, b, c);
}


int main(void){
    kadai1();
    return 0;
}
