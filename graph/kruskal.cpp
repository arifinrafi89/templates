ll find(ll u, vll &par) {

    if (u == par[u]) return u;
    return par[u] = find(par[u], par);

}

void add(ll u, ll v, vll &par, vll &size) {

    u = find(u, par);
    v = find(v, par);

    if (u == v) return;

    if (size[u] > size[v]) {
        size[u] += size[v];
        par[v] = u;
    }
    else {
        size[v] += size[u];
        par[u] = v;
    }

}

ll kruskalDsu(ll n, ll m, mll &edges) {

    vll size(n + 1, 1), par(n + 1);
    vpll mst;
    ll cost = 0;
    for (ll i = 1; i <= n; i++) {
        par[i] = i;
    }

    sort(all(edges));

    for (ll i = 0; i < m; i++) {

        ll u = edges[i][1];
        ll v = edges[i][2];
        ll w = edges[i][0];

        u = find(u, par);
        v = find(v, par);
        if (u == v) continue;

        cost += w;
        mst.push_back({u, v});
        add(u, v, par, size);

    }

    for (ll i = 1; i < n; i++) {
        if (find(i, par) != find(i + 1, par)) return -1;
    }

    return cost;

}