#include <bits/stdc++.h>
using namespace std;

int main () {
	vector <int> aux(1000001, 1);
	set<int> primos;
	for(int i=2; i<=1000000; i++){
		if(aux[i]==1)
			primos.insert(i);
		for(int j=i+i; j<=1000000; j+=i)
			aux[j]=0;
	}



	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		long long x;
		cin >> x;
		double aux = sqrt(x);
		long long int auxx = aux;
		if(aux!=auxx) cout << "0" << endl;
		else{
			if(primos.count(auxx)) cout << "1" << endl;
			else cout << "0" << endl;
		}

	}
	return 0;
}