邊緣觸發，一般都是正邊緣，指的是在觸發時值會改變



一般邊緣觸發如果像正常的圖一樣是一條90度的直線，微分值是無限大，馬克斯威方程式 --> 磁場會超大(用到偏微分)





光學後面的結果是傅立葉轉換

人工智慧使用梯度



微積分基本定理: X積分再微分還是原本的X



## 微積分程式碼

```C
#include <stdio.h>

double h = 0.01
// 微分
double f(double x){
    return x*x;
}

double df(double (*f)(double), double x){ // 對f作微分
    return (f(x+h)-f(x))/h  // 微分定義 斜率
}

double intergral(double (*f)(double), double a, double b){ // 對f作積分
    double area = 0.0
    for (double x=a; x=b; x+=h){
        area += f(x)*h
    }
    return area  // 積分定義 面積
}

double intf(double x){
    return intergral(f, 0, x);
}
int main(){
    printf("df(f, 2.0) = %f\n", df(f, 2.0)) // 微分
    printf("intergral(f, 0, 2) = %f\n", intergral(f, 0, 2)) // 積分
        
    double x = 3.0;
    printf("d  int(f, 0,x)/dt = %f\n"+df(intf, x)); // 微積分基本定理(微分後積分等於自己(f(x)))
}
```



## 驗證尤拉數e

```c
#include <stdio.h>
#include <math.h>

double e(double n){
    return pow(1.0+1.0/n, n)  // e定義
}

int main(){
    double n = 10.0
    for(double n = 1.0; n <10000.0; n+=100){
        printf("e(%d) = %f\n", (int) n ,e(n));
    }
}

```

> e^x 扮演微分積分的單位腳色，像是1是乘法的單位，0是加法的單位



> 泰勒展開式，如果a=0就叫做麥克羅林級數，下面的公式就是用這個證明
>
> e^i * x = cos(x) + i * sin(x)
>
> 如果x = pi --> e^i*pi = -1  ( i = 根號負1, pi = 3.14, e = 2.7)



* 尤拉公式把非線性轉為線性 --> 現在基本所有波，選轉都是用這個，把sin cos合成一體



* 傅立葉轉換是從尤拉那邊推導過來，可以把一個函式轉到剩下sin cos--> 從圖片變成一個點
* 可以把圖片分成很多的函式，在濾波上很好用，可以決定哪個不要就丟，就可以改變圖片

> 傅立葉轉換到資工領域可以資料壓縮，壓縮濾超高(60K)，留下低頻(大概)，刪掉高頻(低頻)
>
> jpg就是用傅立葉轉換去存取圖片，留下cos的部分，bmp是全部存，但會很大







## 偏微分

> 梯度(gradient) --> 梯度下降法(用在人工智慧)

```C
#include <stdio.h>
#include <string.h>

#define N 3
double h = 0.01
// 微分
double f(double x[]){
    return x[0]*x[0] + x[1]*x[1] + x[2]*x[2];
}


double df(double (*f)(double[]), double x[], int i){ // 對f作偏微分
    double xp[N];
    memcpy(xp, x, sizeof(double)*N) // 複製x到xp
    xp[i] += h;
    
    return (f(xp)-f(x))/h;
}

double* grad(double x){  // 回傳陣列
    double g[N];
    for(int i = 0; i < N; i++){
        g[i] = df(f, x, i);
    }
    return g;
}

int main(){
    double p[N] = {0.0, 1.0, 1.0};
    double *g = grad(f, p);
    printf("grad(f, [0, 1, 1]) = (%f, %f, %f)", g[0], g[1], g[2]);
}
```

















> Latex寫論文好用!!!!
