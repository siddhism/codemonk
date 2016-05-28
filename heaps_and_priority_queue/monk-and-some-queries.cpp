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
	ll q, temp, type;
	vector<ll> v;
	vector<ll>::iterator it, it2;

	cin >> q;
	ll length = 0;
	for (ll i = 1; i <= q; ++i) {
		cin >> type;
		if(type==1) {
			cin >> temp;
			v.push_back(temp);
			length++;
			make_heap(all(v));
			sort_heap(all(v));
		}
		else if (type==2) {
			cin >> temp;
			it2 = find(v.begin(), v.end(), temp);
			if (it2 == v.end()){
				cout << -1 << endl;
			}
			else {
				length--;
				v.erase(it2);
				make_heap(all(v));
				sort_heap(all(v));
			}
		}
		else if (type == 3) {
			if (length == 0)
				cout << -1 << endl;
			else {
				cout << v.back() << endl;
			}
		}
		else {
			if (length == 0)
				cout << -1 << endl;
			else {
				cout << v.front() << endl;
			}
		}
		// for(it=v.begin(); it!= v.end(); it++){
		// 	cout << *it << " ";
		// }
	}
	return 0;
}