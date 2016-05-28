#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define mset(x,v) memset(x, v, sizeof(x))
#define all(x) x.begin(),x.end()
#define dbg(x) { cout << #x << " : " << (x) << endl; }
#define dbg2(x,y) { cout << #x << " : " << (x) << " , " << #y << " : " << (y) << endl; }
#define MOD 1000000007

using namespace std;


int main(){
	ll m, n, temp, type;
	vector<ll> v;
	vector<ll>::iterator it, it2;
	cin >> m>>n;
	ll length = 0;
	for (ll i = 1; i <= m; ++i) {
		cin >> temp;
		v.push_back(temp);
	}
	make_heap(all(v));
	sort_heap(all(v));
	ll answer = 0;
	while(n--){
		ll top = v.back();
		answer = answer+ top;
		v.pop_back();
		v.push_back(top-1);
		make_heap(all(v));
		sort_heap(all(v));
		// for (it = v.begin(); it!= v.end(); ++it) {
		// 	cout << *it << " ";
		// }
	}
	cout << answer << endl;
	return 0;
}