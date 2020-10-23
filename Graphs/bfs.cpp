// Program.cpp

#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef pair<int, int>      pii;
typedef vector<int>         vi;

#define fr(i, n)            for(int i=0; i<(n); ++i)
#define frC(i, n)           for(int i=0; (i<(n)) && (c); ++i)
#define frA(i, a, n)        for(int i=a; i<=(n); ++i)
#define frD(i, a, n)        for(int i=a; i>=(n); --i)
#define fill(a)             memset(a, 0, sizeof(a))
#define revsort(a, b)       sort(a, b, greater<int>())
#define dout                if(DEBUGGING) cout
#define dbg                 if(DEBUGGING) 
#define endl                "\n"

int DEBUGGING    =          0;
const int INF    =          1000000000;
const int MOD    =          1000000007;
const double PI  =          3.1415926535897932;
const double EPS =          1e-7;

void solve(int TEST_CASE){
	vector<vector<int>> adj;  //adjacency list
	int n; //number of nodes
	int s; //source node
	queue<int> q;
	vector<int> v(n); //used vector
	vector<int> d(n); //d[i] -> length of shortest path from source node to ith node
	vector<int> p(n); //p[i] -> parent of ith node

	q.push(s);
	used[s] = 1;
	p[s] = -1;
	while (!q.empty()) {
	    int a = q.front();
	    q.pop();
	    for (int u : adj[a]) {
	        if (!v[u]) {
	            v[u] = 1;
	            q.push(u);
	            d[u] = d[a] + 1;
	            p[u] = a;
	        }
	    }
	}    
}

int main(int argc, char* argv[]){
    if(argc==2 && argv[1][1]=='v') DEBUGGING = 1;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int nTestCases=1;
    //cin >> nTestCases;
    frA(i,1,nTestCases) solve(i);
    return 0;
}