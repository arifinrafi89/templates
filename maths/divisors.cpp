vector<ll> calcDivs(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.pb(i);
            if (i * i != n) {
                divs.pb(n / i);
            }
        }
    }
    return divs;
}