void dfsDepth(ll node, ll par, mll &adj, vll &depth) {
    for (ll child : adj[node]) {
        if (par == child) continue;
        depth[child] = depth[node] + 1;
        dfsDepth(child, node, adj, depth);
    }
    return;
}