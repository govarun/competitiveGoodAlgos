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

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(vector<int>& arr, int lo, int hi){
	int pivot = arr[hi];
	int i = lo-1;
	for(int j=lo;j<hi;++j){
		if(arr[j] <= pivot){
			++i;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[hi]);
	return i+1;
}

void quickSort(vector<int>& arr, int lo, int hi){
	if(lo<hi){
		int p = partition(arr,lo,hi);
		quickSort(arr,lo,p-1);
		quickSort(arr,p+1,hi);
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