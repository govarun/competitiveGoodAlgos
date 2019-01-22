#define f(i, n)    for(int i = 0; i < (n); ++i)
#define fa(i, a, n)  for(int i = (a); i <= (n); ++i)
#define pb push_back
typedef long long ll;
typedef vector<int> vi;

vector <int> factorize(ll n){
    //O(sqrt(n))
    
    vi ans;
    for(ll i = 2; i * i <= n; i++){
        while(n % i == 0){
            ans.pb(i);
            n /= i;
        }
    }
    if(n != 1) ans.pb(n;)
    return ans;
}


vector <int> factorizeFast(ll n){
    //O(log(n))
    //Storage O(n) - problematic in 1e9 cases

    vi ans;
    int minprime[n + 1];
    f(i, n + 1){
        minprime[i] = 0;

    }
    for(int i = 2; i * i <= n; i++){
        if(minprime[i] == 0){   //if i is prime
            for(int j = i * i; j <= n; j += i){
                if(minprime[j] == 0){
                    minprime[j] = i;
                }
            }
        }
    }

    fa(i, 2, n){
        if(minprime[i] == 0){
            minprime[i] = i;
        }

    }
    while(n != 1){
        ans.pb(minprime[n]);
        n /= minprime[n];
    }
    return ans;
}
