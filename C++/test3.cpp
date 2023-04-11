#include<iostream>
using namespace std;

// int f[1000];
int *f;
int fun(int n) {
    if(n == 0) {
        f[0] = 0;
        return 0;
    }
    else if(n == 1 || n == 2) {
        f[0] = 1;
        return 1;
    }
    else if(f[n])   return f[n];
    else {
        f[n] = fun(n-1) + fun(n-2);
        return f[n];
    }
}

int work() {
    int n;
    cin>>n;
    f = new int[n+1];
    for(int i = 0; i <= n; i++) {
        f[i] = 0;
    }
    fun(n);
    for(int i=1; i <= n; i++) {
        cout << fun(i) << "  ";
        // printf("%d ", fun(i));
    }
    putchar('\n');
    delete[]f;
    return 0;
}

int main() {
    while(1) {
        work();
    }
    return 0;
}