#include <bits/stdc++.h>
using namespace std;


int main () {
	long long x;
	cin >> x;
	long long resp = 0;
	for(long long a=1; a*a <= x; a++){
		if(x%a == 0){
			long long b = x/a;
			if(b==a) resp++;
			else resp+=2;
		}
	}
	cout << resp << endl;
	return 0;
}
