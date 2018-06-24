#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main() {
    double eps;
    int n;
    cin >>eps >>n;
    double *A = new double[n+1];
    double *B = new double[n+1];
    double *C = new double[n+1];
    double *F = new double[n+1];
    B[1] = 0;
    C[1] = 1;
    F[1] = 0;
    for(int i = 2; i <= n - 1; ++i){
        A[i] = 1;
        C[i] = eps;
        B[i] = 1;
        F[i] = -(double)i / n;
    }
    A[n] = 0;
    C[n] = 1;
    F[n] = 1;
    cout << "a = ";
    for (int i = 2; i <= n; i++) { //Выводим диагональ a
        cout << A[i] << " ";
    }
    cout<<endl;
    cout << "c = ";
    for (int i = 1; i <= n; i++) { //Выводим диагональ c
        cout << C[i] << " ";
    }
    cout <<endl;
    cout << "b = ";
    for (int i = 1; i < n; i++) {  //Выводим диагональ b
        cout << B[i] << " ";
    }
    cout <<endl;
    cout << "f = ";
    for (int i = 1; i <= n; i++) { //Выводим вектор правой части
        cout << F[i] << " ";
    }
    cout<<endl;
/*-----------------------------------Прямой ход---------------------------------------*/
    double *y = new double[n+1];
    double *alpha = new double[n+1];
    double *beta = new double[n+1];
    alpha[1] = B[1]/C[1];
    beta[1]= F[1]/C[1];
    for (int i = 2; i < n; i++) {
        alpha[i] = B[i] / (C[i] - A[i] * alpha[i - 1]);
        beta[i] = (F[i] + A[i]*beta[i-1])/(C[i] - A[i]*alpha[i-1]);
    }
/*-----------------------------------Прямой ход---------------------------------------*/

/*-----------------------------------Обратный ход---------------------------------------*/
    y[n] = (F[n] + A[n]*beta[n-1])/(C[n] - A[n]*alpha[n-1]);
    for (int i = n - 1; i >= 1; i--) {
        y[i] = alpha[i] * y[i+1] + beta[i];
    }
/*-----------------------------------Обратный ход---------------------------------------*/
    //Выводим решения
     cout <<endl <<"Answer" <<endl;
     ofstream out ("answer.txt");
     for (int i = 1; i <= n; i++) {
         cout << y[i] << " ";
         out << y[i] << ' ';
     }
     cout <<endl;
     out.close();
     system("pause");
     return 0;
 }