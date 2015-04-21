#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double func(double y){
    return (1-y)*y;
}

double euler(double n, double h, double t_init, double y_init){
    int i;
    double y0, y1 = y_init, t0, t1 = t_init;

    for(i=0; i<n; i++){
        t0 = t1;
        y0 = y1;
        t1 = t0 + h;
        y1 = y0 + h * func(y0);

        printf("%d, %f, %f,\n",i ,t0 ,y0);
    }
    printf("%d, %f, %f,\n",i ,t1 ,y1);

    return y1;
}

double huen(double n, double h, double t_init, double y_init){
    int i;
    double s;
    double y0, y1 = y_init, t0, t1 = t_init;

    for(i=0; i<n; i++){
        t0 = t1;
        y0 = y1;
        t1 = t0 + h;
        s = y0 + h * func(y0);
        y1 = y0 + (h/2) * (func(y0) + func(s));

        printf("%d, %f, %f,\n",i ,t0 ,y0);
    }
    printf("%d, %f, %f,\n",i ,t1 ,y1);

    return y1;
}

double runge_kutta(double n, double h, double t_init, double y_init){
    int i;
    double s1, s2, s3, s4;
    double y0, y1 = y_init, t0, t1 = t_init;

    for(i=0; i<n; i++){
        t0 = t1;
        y0 = y1;
        t1 = t0 + h;
        s1 = h * func(y0);
        s2 = h * func(y0 + 0.5*s1);
        s3 = h * func(y0 + 0.5*s2);
        s4 = h * func(y0 + s3);
        y1 = y0 + (s1 + 2*s2 + 2*s3 + s4)/6;

        printf("%d, %f, %f,\n",i ,t0 ,y0);
    }
    printf("%d, %f, %f,\n",i ,t1 ,y1);

    return y1;
}


int main(void){
    double h; // 幅
    printf("Please input a h value (0.1 or 0.01).\nh > ");
    scanf("%lf",&h);

    double t_start = 0, t_end = 2;
    double n = (t_end - t_start) / h;  // 区間を幅で割るとn
    double y_init = 0.1; // 初期値

    printf("オイラー法による解: %f\n", euler(n, h, t_start, y_init));
    printf("ホイン法による解: %f\n", huen(n, h, t_start, y_init));
    printf("ルンゲクッタ法による解: %f\n", runge_kutta(n, h, t_start, y_init));
}
