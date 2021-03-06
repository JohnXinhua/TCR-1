#ifndef HEADER_H
#define HEADER_H
//#define _GLIBCXX_DEBUG
constexpr bool LOG = false;

#include <iostream> // strings/streams
#include <cstdio> // utils
#include <string>
#include <cstring>
#include <sstream>
#include <vector> // datastructures
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <tuple> // quick compare
#include <numeric>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <cassert>
#include <complex>

#define REP(i,n)	for(auto i = decltype(n)(0); i<(n); i++)
#define all(v)		begin(v), end(v)

using namespace std;
using ll  = long long;
using ull = unsigned long long;
using ld  = long double;
using ii  = pair<ll,ll>;
using vi  = vector<ll>;
using vii = vector<ii>;
using vb  = vector<bool>;
using vvi = vector<vi>;
using vvii = vector<vii>;

constexpr int  INF = 1e9+1; // < 1e9 - -1e9
constexpr ll LLINF = 1e18+1;
void Log() { if(LOG) cerr << "\n"; }
template<class T, class... S> void Log(T t, S... s){
	if(LOG) cerr << t << "\t", Log(s...);
}
#endif
