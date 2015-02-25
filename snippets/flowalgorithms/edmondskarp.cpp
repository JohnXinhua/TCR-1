#define MAXV 2000
ll FlowNetwork::edmonds_karp(int s, int t) {
    int v, p[MAXV], q[MAXV]; ll f = 0;
    while (true) {
        memset(p, -1, n * sizeof(int));
        int i, u = -1, l = 0, r = 0;
        p[q[r++] = s] = -2; // -2 == source, -1 == unvisited
        while (l != r && u != t) {
            for (u = q[l++], i = h[u]; i != -1; i = e[i].nxt) {
                if (e[i].cap > e[i].flo && p[v = e[i].v] == -1) {
                    p[q[r++] = v] = i;
        }   }   }
        if (p[t] == -1) break;
        ll df = INF; i = p[t];
        for (i = p[t]; i != -2; i = p[e[i ^ 2].v])
            df = min(df, e[i].cap - e[i].flo);
        for (i = p[t]; i != -2; i = p[e[i ^ 2].v]) {
            e[i].flo += df; e[i ^ 1].flo -= df;
        }
        f += df;
    }
    return f;
}