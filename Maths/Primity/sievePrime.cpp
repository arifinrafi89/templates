bool isPrime[1000001];

void sieve() {
    for (ll i = 0; i <= 1000000; i++) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for (ll i = 4; i <= 1000000; i += 2) isPrime[i] = false;
    for (ll i = 3; i <= 1000000; i += 2) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= 1000000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
