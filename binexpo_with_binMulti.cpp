typedef long long ll;

// Binary Exponentiation: (a^b) % m in O(log b)
ll binpow(ll a, ll b, ll m) {
    ll res = 1; a %= m;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m; b >>= 1;
    }
    return res;
}

// Binary Multiplication: (a*b) % m in O(log b)
// Use when m > 10^9 and standard (a*b)%m would overflow a 64-bit int
ll binmul(ll a, ll b, ll m) {
    ll res = 0; a %= m;
    while (b) {
        if (b & 1) res = (res + a) % m;
        a = (a + a) % m; b >>= 1;
    }
    return res;
}

// ---------------------------------------------------------
// ICPC PRO-TIP: O(1) Multiplication (Replaces binmul entirely)
// ---------------------------------------------------------
// GCC compilers (Codeforces, ICPC) support 128-bit integers. 
// Instead of using the O(log b) binmul loop, just cast to __int128!
ll fastmul(ll a, ll b, ll m) {
    return (ll)((__int128)a * b % m);
}
