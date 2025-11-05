ll countOfDivisors(vpll &f, ll M) {
    ll res = 1;
    for (auto [p, e] : f)
        res = res * (e + 1) % M;
    return res;
}