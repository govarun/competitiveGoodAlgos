ll maxPo(ll n, ll p){
    if(p == 0 || p == 1){
        return n;
    }
    ll cur = p;
    ll po = 0;
    while(n >= cur){
        po += n / cur;
        n /= cur;
        // debug(cur);
    }
    return po;

}
