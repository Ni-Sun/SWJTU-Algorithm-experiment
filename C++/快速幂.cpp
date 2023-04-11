#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned llu;

llu *a;
const llu m = 998244353;
llu quick_power(llu base,llu power);
int main() {
	llu n, p;
	cin >> n >> p;
	llu result = 1, i, t;
	a = new llu[n];
	for(i = 0; i < n; i++)
		scanf("%llu", a+i);
	for(i = 0; i < n; i++) {
		t = quick_power(p,a[i]) + 1;
		result = result*t%m;
	}
	cout << result << endl;
	delete[]a;
	return 0;
}

//快速幂 
llu quick_power(llu base, llu power) {
	llu result = 1;
	while(power) {
		if(power&1) {	//power为奇数 
			result = result*base%m;
		}
		power >>= 1;
		base = base*base%m;
	}
	return result%m;
}
