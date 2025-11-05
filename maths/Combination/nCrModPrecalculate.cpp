class Combination {
private:
    ll n, M;
    vector<ll> fact, inv, inv_fact;

    void init() {
        fact[0] = 1;
        inv_fact[0] = 1;
        for (ll i = 1; i <= n; i++) {
            if (i == 1) {
                inv[i] = 1;
            } else {
                ll a = inv[i - (M % i)];
                ll b = (M / i) + 1;
                inv[i] = (a * b) % M;
            }
            fact[i] = (fact[i - 1] * i) % M;
            inv_fact[i] = (inv_fact[i - 1] * inv[i]) % M;
        }
    }

public:
    Combination(ll _n, ll _M) : n(_n), M(_M), fact(n + 1), inv(n + 1), inv_fact(n + 1) {
        init();
    }

    ll nCr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        return (((fact[n] * inv_fact[r]) % M) * inv_fact[n - r]) % M;
    }
};