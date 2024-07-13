// github.com/Johniel/contests
// atcoder/abc362/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 2 * 2 * 1e5 + 3;
vec<pair<int, lli>> g[N];

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    int name[n][2];
    const int in = 0;
    const int out = 1;
    {
      int k = 0;
      for (int i = 0; i < n; ++i) {
        name[i][in] = k++;
        name[i][out] = k++;
      }
    }
    fill(g, g + N, vec<pair<int, lli>>());
    vec<lli> a(n);
    cin >> a;
    for (int i = 0; i < n; ++i) {
      g[name[i][in]].push_back(make_pair(name[i][out], a[i]));
    }
    for (int i = 0; i < m; ++i) {
      int a, b;
      lli c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[name[a][out]].push_back(make_pair(name[b][in], c));
      g[name[b][out]].push_back(make_pair(name[a][in], c));
    }

    const lli inf = 1LL << 61;
    lli cost[N];
    fill(cost, cost + N, inf);

    priority_queue<pair<lli, int>> q;
    const int src = name[0][in];
    cost[src] = 0;
    q.push(make_pair(-cost[src], src));
    while (q.size()) {
      auto [c, curr] = q.top();
      c = abs(c);
      q.pop();
      if (cost[curr] != c) continue;
      each (e, g[curr]) {
        auto [next, w] = e;
        if (cost[next] > cost[curr] + w) {
          cost[next] = cost[curr] + w;
          q.push(make_pair(-cost[next], next));
        }
      }
    }
    for (int i = 1; i < n; ++i) {
      cout << cost[name[i][out]] << ' ';
    }
    cout << endl;
  }
  return 0;
}
