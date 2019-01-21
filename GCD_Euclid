 int gcd_recursive(int a, int b){
    // O(log min(a, b))
    return b ? gcd_recursive(b, a % b) : a;

}
int gcd_iterative(int a, int b){
    // O(log min(a, b))

    while(b){
        a %= b;
        swap(a,b);
    }
    return a;
}
//takes care of the case 0, 0   
