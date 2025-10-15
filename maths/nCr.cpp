ll nCr(ll n, ll r) {

	r = min(r, n - r);
	ll res = 1;
	for (ll i = 1; i <= r; i++) {
		res *= (n - r + 1) / i;
	}
	return res;
}