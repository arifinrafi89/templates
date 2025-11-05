vll calcDivs(ll n) {
    vll divs;
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