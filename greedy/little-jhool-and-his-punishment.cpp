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
	ll tc,n,i,j,x,temp;
	ll b, g;
	whiletc {
		cin >> n >> b >>g;
		if(b-g >=2 or g-b >=2)
			cout << "Little Jhool wins!" << endl;
		else
			cout << "The teacher wins!" << endl;
	}
	return 0;
}
