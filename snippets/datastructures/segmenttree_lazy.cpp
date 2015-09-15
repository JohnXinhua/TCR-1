#include "../header.h"
using T=int; using U=int; using I=int;
T t_id; U u_id;
T merge(T a, T b){return a+b;}
void join(U &a, U b){ a=a+b; }
struct Node { int l, r, lc, rc; T t; U u;
	Node(int l, int r) : l(l), r(r), lc(-1), rc(-1), t(t_id), u(u_id) {}
};
T apply(const Node &n, int l=-1){ return merge(n.t,(l<0?n.r-n.l+1:l)*n.u); }
T convert(const I &i){ return i; }		// or make a T(I) constructor
struct LazySegmentTree {
	vector<Node> tree;
	void build(int i, int l, int r, const vector<I> &arr) {
		auto &n = tree[i];
		if (l < r) {
			int m = (l + r) / 2;
			n.lc = tree.size();		n.rc = tree.size()+1;
			tree.push_back({l,m});	tree.push_back({m+1,r});
			build(n.lc,l,m,arr);	build(n.rc,m+1,r,arr);
			n.t = merge(tree[n.lc].t, tree[n.rc].t);
		} else n.t = convert(arr[l]);
	}
	LazySegmentTree(const vector<I> &arr){
		tree.reserve(2*arr.size()-1);
		tree.push_back({0,int(arr.size())-1});
		build(0, 0, arr.size()-1, arr);
	}
	T query(int l, int r, int i = 0) {	// 0 <= l <= r < n
		auto &n = tree[i];
		if(l > n.r || r < n.l) return t_id;
		if(l <= n.l && n.r <= r) return apply(n);
		n.t = apply(n);
		join(tree[n.lc].u, n.u); join(tree[n.rc].u, n.u); n.u = u_id;
		return merge(query(l,r,n.lc),query(l,r,n.rc));
	}
	void update(int l, int r, U u, int i = 0) {
		auto &n = tree[i];
		if(l > n.r || r < n.l) return;
		if(l <= n.l && n.r <= r){ join(n.u,u); return; }
		update(l,r,u,n.lc); update(l,r,u,n.rc);
		auto& lc = tree[n.lc], &rc=tree[n.rc];
		n.t = merge(apply(lc), apply(rc));
	}
};