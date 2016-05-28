// user
// It depends on edges. Uses disjoll set union.
// 1. Sort the edges by their weight in non increasing order.
// 2. Select the edge one by one from beggining.
// 3. If adding an edge forms a cycle -
// 		discard It
//    else
// 		Add the picked edge llo the minimum spanning tree.
// O(E(log*)V).


#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long

using namespace std;
const ll MAX = 1e5 + 5;
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
	long long cost, maximumCost = 0;
	for(ll i=0; i<edges; i++) {
		// extract vertex endpoints and edge's weight (cost)
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if (root(x) != root(y)){
			maximumCost += cost;
			union1(x, y);
		}
	}
	return maximumCost;
}

int main(){
	ll x,y;
	ll weight, maximumCost;
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
		reverse(p, p+edges);
		// for (ll i = 0; i < edges; ++i){
		// 	cout << "weight " << p[i].first << " between " << p[i].second.first << " & " << p[i].second.second << endl; 
		// }
		maximumCost = Kruskal(p);
		cout << maximumCost << endl;		
	}
	return 0;
}