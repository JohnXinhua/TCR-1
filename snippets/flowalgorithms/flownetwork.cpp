struct FlowNetwork {
    struct edge {
        int v, nxt; ll cap, flo;
        edge(int _v, ll _cap, int _nxt) : v(_v), cap(_cap), nxt(_nxt), flo(0) { }
    };
    int n, edge_count = 0, *h;
    vector<edge> e;
    FlowNetwork(int V, int E = 0) : n(V) {
        e.reserve(2 * (E == 0 ? V : E));
        memset(h = new int[V], -1, n * sizeof(int));
    }
    void add_edge(int u, int v, ll uv_cap, ll vu_cap = 0) {
        e.push_back(edge(v, uv_cap, h[u])); h[u] = edge_count++;
        e.push_back(edge(u, vu_cap, h[v])); h[v] = edge_count++;
    }
    void cleanup() { delete[] h; }
    ll edmonds_karp(int s, int t);
    ll dinic(int s, int t);
    ll push_relabel(int s, int t);
};