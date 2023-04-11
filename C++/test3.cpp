#include<iostream>
using namespace std;

double m[] = {0.1,0.2,0.5,1.0};
int dp[100];
int read(int &a, int &b);
int work() {
    int a,b;
    int flag = read(a,b);
    if(flag) {
        return -1;
    }
    double x = a + b*0.1;
    //完全背包
    for(int i = 0; i < 4; i++) {
        for(double j = 0; j <= x; j += 0.1) {
            dp[(int)(j*10)] = min(dp[(int)(j*10)], dp[(int)((j-m[i])*10)] + 1);
        }
    }
    cout << dp[(int)(x*10)] << endl;
    return 0;
}

int main() {
    while(1) {
        work();
    }
    return 0;
}

int read(int &a, int &b) {
    cout << "Input: ";
    char str[100];
    gets(str);
    a = b = 0;
    char ch;
    int i = 0;
    while(1){
        ch = str[i];
        if(ch == '.' || ch == '\0')   break;
        a = a * 10 + ch - '0';
        i++;
    }
    if(ch == '\0') {
        return 0;
    }
    if(str[i+2] != '\0') {
        cout << "Invalid input: " << endl;
        return -1;
    }
    b = str[i+1];
    return 0;
}