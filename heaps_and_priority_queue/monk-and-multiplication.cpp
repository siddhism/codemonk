#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define mset(x,v) memset(x, v, sizeof(x))
#define dbg(x) { cout << #x << " : " << (x) << endl; }
#define dbg2(x,y) { cout << #x << " : " << (x) << " , " << #y << " : " << (y) << endl; }
#define MOD 1000000007

using namespace std;

// For this problem we will build a priority queue and always give top three elements.
// or build a heap and insert elements and give top three product always
// or use cpp's pq directly

void max_heapify(ll A[], ll i, ll N) {
	ll left = 2*i;
	ll right = 2*i + 1;
	ll largest;
	if (left <= N and A[left] > A[i])
		largest = left;
	else
		largest = i;
	if (right <= N and A[right] > A[largest])
		largest = right;
	//swap largest and i
	if(largest != i) {
		swap(A[i], A[largest]);
		max_heapify(A, largest, N);
	}
}

void build_max_heap(ll A[], ll N) {
	for (ll i = N/2; i >= 1; i--) {
		max_heapify(A, i, N);
	}
}

void heap_sort(ll A[], ll N) {
	ll heap_size = N;
	build_max_heap(A, N);
	for (ll i = N; i>=2 ; i--) {
		swap(A[1], A[i]);
		heap_size = heap_size - 1;
		max_heapify(A, 1, heap_size);
	}

}

int main(){
	ll tc,n,i,j,x,temp;
	cin >> n;
	ll A[n];
	for (ll i = 1; i <= n; ++i) {
		cin >> A[i];
		heap_sort(A, i);
		if (i < 3) {
			cout<< -1 << endl;
		}
		else {
			// dbg2(i, A[i]);
			// dbg2(i-1, A[i-1]);
			// dbg2(i-2, A[i-2]);
			cout << A[i] * A[i-1] * A[i-2] << endl;
		}
	}
	return 0;
}