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

int sorted(vector<int>& arr){
	int n = arr.size();
	for(int i=0;i<n-1;++i){
		if(arr[i]>arr[i+1])
			return 0;
	}
	return 1;
}

void bubbleSort(vector<int>& arr){
	int n = arr.size();
	while(!sorted(arr)){
		int temp;
		for(int i=0;i<n-1;++i){
			if(arr[i]>arr[i+1]){
				temp = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

void solve(int TEST_CASE){
    
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