#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#define ll long long

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<ll, ll> PII;
bool marked[MAX];
vector <PII> adj[MAX];

// void initialize(){
// 	//initially mark all visited = false
// 	for (int i = 0; i < MAX; ++i) {
// 		marked[i] = false;
// 	}
// }

ll prims(ll x) {
	priority_queue<PII, vector<PII>, greater<PII> > Q;
	ll y, minimumCost;
	PII p;
	Q.push(0, x);
	while(!Q.empty()){
		p = Q.top();
		Q.pop();
		ll cost = p.first;
		ll x = p.second;
		if (marked[x] == true) {
			continue;
		}
		minimumCost += cost;
		marked[x] = true;
		for (int i = 0; i < adj[x].size(); ++i) {
			y = adj[x][i].second;
			if(marked[y] == false) {
				Q.push(make_pair(adj[x][i]));
			}
		}
	}

}


int main() {
	ll nodes, edges, i, minimumCost, x, y;
	cin >> nodes >> edges;
	for (int i = 0; i < edges; ++i) {
		cin >> x >> y >> weight;
		adj[x].push_back(make_pair(weight, y));
		adj[y].push_back(make_pair(weight, x));
	}
	minimumCost = prims(1);
	cout << minimumCost <<endl;

	return 0;
}