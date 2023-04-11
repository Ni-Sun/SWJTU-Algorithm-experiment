#include<iostream>
using namespace std;

int **a;
void fun(int , int = 1);
void show(int n);
int work();

int main() {
    while(1) {
        work();
    }
    return 0;
}

int work() {
    int size;
    cout << "Input size: ";
    cin >> size;
    int &n = size;
    a = new int*[n+1];
    for(int i = 0; i <= n; i++) {
        a[i] = new int[n+1];
        a[0][i] = a[i][0] = 0;
    }
    fun(n);
    show(n);
    for(int i = 0; i <= n; i++) {
        delete[]a[i];
    }
    delete[]a;
    return 0;
}

void fun(int size, int x) {
    if(size <= 0)   return;
    int t = x+size-1;
    for(int i = x; i <= t; i++) {
        a[i][x] = a[i-1][x] + 1;
    }
    for(int i = x; i <= t; i++) {
        a[t][i] = a[t][x] + i-x;
    }
    for(int i = t; i >= x; i--) {
        a[i][t] = a[t][t] + t-i;
    }
    for(int i = t; i > x; i--) {
        a[x][i] = a[x][t] + t-i;
    }
    fun(size-2,x+1);
}

void show(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%4d", a[i][j]);
        }
        putchar('\n');
    }
}