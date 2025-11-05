class PrimeFactorization {
private:
    ll n;
    vll spf;      
    vll primes;   

    void build() {
        spf[0] = 0;
        if (n >= 1) spf[1] = 1;
        for (ll i = 2; i <= n; i++) {
            if (spf[i] == 0) {
                spf[i] = i;
                primes.push_back(i);
            }
            for (ll p : primes) {
                ll v = p * i;
                if (v > n || p > spf[i]) break;
                spf[v] = p;
            }
        }
    }

public:
    PrimeFactorization(ll _n) : n(_n), spf(n + 1, 0) {
        build();
    }

    vpll getFactorization(ll x) {
        vpll res;
        if (x <= 1) return res;
        while (x > 1) {
            ll p = spf[x];
            ll ct = 0;
            while (x % p == 0) {
                x /= p;
                ct++;
            }
            res.push_back({p, ct});
        }
        return res;
    }
};