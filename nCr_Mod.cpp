const int MOD = 1e9 + 7;
const int N = 2000005;
ll fact[N];

ll binpow(ll a, ll b) {
    ll res = 1; a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD; b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * binpow(fact[r] * fact[n - r] % MOD, MOD - 2) % MOD;
}
