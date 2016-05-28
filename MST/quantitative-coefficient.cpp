#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long

using namespace std;
const ll MAX = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll id[MAX], nodes, edges;
pair <long long, pair<ll, ll> > p[MAX];

void initialize() {
	for(ll i=0; i<MAX; i++)
		id[i] = i;
}

ll root(ll x) {
	while(id[x] != x) {
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}

void union1(ll a, ll b) {
	ll root_a = root(a);
	ll root_b = root(b);
	id[root_a] = root_b;
}

long long Kruskal(pair<long long, pair<ll, ll> > p[]) {
	ll x,y;
	long long cost, minimalProduct = 1;
	for(ll i=0; i<edges; i++) {
		// extract vertex endpoints and edge's weight (cost)
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if (root(x) != root(y)){
			minimalProduct = (cost%MOD * minimalProduct%MOD) %MOD;
			union1(x, y);
		}
	}
	return minimalProduct;
}

int main(){
	ll x,y;
	ll weight, minimalProduct;
	ll tc;
	cin >> tc;
	while(tc--) {
		initialize();
		cin >> nodes >> edges;
		// we will make a pair of weight with the edge
		// pair <long long, pair<ll, ll> > p[MAX]; 
		// edge is denoted by pair of both vertex

		for(ll i=0; i<edges; i++) {
			cin >> x >> y >> weight;
			p[i] = make_pair(weight, make_pair(x,y));
		}

		// sort the edges in non increasing order of weight
		sort(p, p+edges);
		// for (ll i = 0; i < edges; ++i){
		// 	cout << "weight " << p[i].first << " between " << p[i].second.first << " & " << p[i].second.second << endl; 
		// }
		minimalProduct = Kruskal(p);
		cout << minimalProduct << endl;		
	}
	return 0;
}