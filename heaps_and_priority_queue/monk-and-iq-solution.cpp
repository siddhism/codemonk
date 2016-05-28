/* My First Template  
   :P
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
ll power(ll a, ll b) {
ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}
#define P pair<ll, int>
priority_queue< P, vector<P>, greater<P> > q;
ll a[100002];
int ans[100002];
vector<ll>price[100002];
int main()
{
	//freopen("Input.txt", "r", stdin);
	//freopen("SampleOutput.out", "w", stdout);
	int c,n,k,i,s,l;
    cin>>c>>n>>k;
    for(i = 0; i < k; i++) {
        cin>>a[i];
        q.push(make_pair(a[i],i));
        price[i].push_back(a[i]);
    }
    for(i = k; i < c; i++) {
    	q.push(make_pair(0,i));
    }
    for(i = 0; i < n; i++) {
    	cin>>a[i];
    }
    pair<ll,int>z;
    for(i = 0; i < n; i++) {
        z = q.top();
        if(price[z.second].size() == 0) {
        	price[z.second].push_back(a[i]);
        	z.first += a[i];
        	ans[i] = z.second;
        	q.pop();
        	q.push(z);
        }
        else if(price[z.second].size() == 1) {
            z.first = (z.first+a[i])*2;
            price[z.second].push_back(a[i]);
            ans[i] = z.second;
            q.pop();
            q.push(z);
        }
        else if(price[z.second].size() >= 2) {
            l = price[z.second].size();
            z.first = (price[z.second][l-1]+a[i]);
            price[z.second].push_back(a[i]);
            ans[i] = z.second;
            z.first *= (l+1);
            q.pop();
            q.push(z);
        }
    }
    for(i = 0; i < n; i++) {
        cout<<ans[i]+1<<" ";
    }
	return 0;
}