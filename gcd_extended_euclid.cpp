//Used template as in temp.cpp in this repository

ll gcd_euclid_extended(ll a, ll b, ll & x, ll & y){
  //O(
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    // ll x1, y1;
    ll d = gcd_euclid_extended(b, a % b, x, y);
    ll tmpy = y;
    y = x - a / b * y;
    x = tmpy;
    return d;
}
