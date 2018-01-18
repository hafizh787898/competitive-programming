#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1100000

string str, strP;
int ans, maxPrefix, backTable[MAX_N];

void kmpPreprocess(){
	int a = 0, b = -1;

	backTable[0] = -1;

	while(a < strP.size()){
		while(b >= 0 && strP[a] != strP[b])
			b = backTable[b];

		a++;
		b++;

		backTable[a] = b;
	}
}

void kmpSearch(){
	int a = 0, b = 0;

	while(a < str.size()){
		while(b >= 0 && str[a] != strP[b])
			b = backTable[b];

		a++;
		b++;

		if(maxPrefix < b){
			maxPrefix = b;

			ans = a - b;
		}

		if(b == strP.size())
			b = backTable[b];
	}
}

int main(){
	int num;

	cin >> num >> strP >> str;

	str = str + str;

	maxPrefix = ans = -1;

	kmpPreprocess();

	kmpSearch();

	cout << ans << "\n";
}