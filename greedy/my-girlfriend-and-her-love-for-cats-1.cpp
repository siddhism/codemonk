#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define mp make_pair
#define pb push_back
#define all(a) a.begin(),a.end()
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define mset(x,v) memset(x, v, sizeof(x))
#define dbg(x) { cout << #x << " : " << (x) << endl; }
#define dbg2(x,y) { cout << #x << " : " << (x) << " , " << #y << " : " << (y) << endl; }
#define MOD 1000000007

using namespace std;

int main(){
	ll tc,n,i,j,x,temp;
	cin >> n;
	vector<ll> s, c;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		s.push_back(temp);
	}
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		c.push_back(temp);
	}
	sort(all(s));
	sort(all(c));
	ll result = 0;
	for (int i = 0; i < n; i++) {
		result = result + s[i]*c[i]; 
	}
	cout << result << endl;

	return 0;
}