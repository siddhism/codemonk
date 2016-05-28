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
#define rep(i,n) for(ll i=0;i<n;i++)
#define whiletc int t;cin>>t;while(t--)

using namespace std;

int main(){
	ll tc,n,k,temp;
	cin >> tc;
	list <ll> num, couples;
	// multiset<ll> num, couples;
	while(tc--){
		cin >> n >> k;
		num.clear(); couples.clear();
		// insert all data into list
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			num.push_back(temp);
		}
		num.sort(); //  [1 6 6 7 1 8] => [1 1 6 6 7 8]
		
		while(not num.empty()) {
			ll start = num.front();
			ll end = num.back();
			num.pop_back(); num.pop_front();
			couples.push_back(start+end); 
		}

		//[1+8, 1+7, 6+6] => [9 8 12] => [8 9 12]
		couples.sort();

		list<ll>::iterator it;
		// cout << "These are the array elements" << endl;
		// for(it=couples.begin(); it!=couples.end(); it++){
		// 	cout << *it << " ";
		// }
		// cout << endl;
		it = couples.begin();
		ll first = *it;
		it = couples.end();
		it--;
		ll last = *it;
		ll ans = last-first;
		// dbg2(first, last);
		// dbg(ans);
		cout << ans << endl;
		if (ans > k)
			cout << "No more girlfriends!" << endl;
		else if (ans == k)
			cout << "Lucky chap! " << endl;
		else 
			cout << "Chick magnet Jhool!" << endl;
	}
	return 0;
}