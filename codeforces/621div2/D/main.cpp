// codeforces/621div2/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }
template<typename P, typename Q> inline pair<Q, P> reverse(pair<P, Q> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;

const int N = 2 * 1e5 + 5;
vector<int> g[N];

const int inf = 1 << 29;

template<typename T>
struct RMQ {
  int n;
  vector<T> dat;
  using F = function<T(T, T)>;
  F fn;
  T e;
  RMQ(int n_, T e_, F fn_) {
    e = e_;
    fn = fn_;
    n = 1;
    while (n < n_) n *= 2;
    dat.resize(2 * n - 1, e);
  }

  void update(size_t k, T a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = fn(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
    return ;
  }

  T query(size_t a, size_t b) {
    return query(a, b, 0, 0, n);
  }

  T query(size_t a, size_t b, size_t k, size_t l, size_t r) {
    if (r <= a || b <= l) return e;
    if (a <= l && r <= b) return dat.at(k);

    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

    return fn(vl,vr);
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  while (cin >> n >> m >> k) {
    vector<int> a(k);
    cin >> a;
    each (i, a) --i;

    fill(g, g + N, vector<int>());
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    auto bfs = [&] (int src) {
      vector<int> cost(n, inf);
      queue<int> q;
      cost[src] = 0;
      for (q.push(src); q.size(); q.pop()) {
        int curr = q.front();
        each (next, g[curr]) {
          if (cost[next] == inf) {
            cost[next] = cost[curr] + 1;
            q.push(next);
          }
        }
      }
      return cost;
    };

    vector<int> d1 = bfs(0);
    vector<int> d2 = bfs(n - 1);
    sort(a.begin(), a.end(), [&] (int i, int j) { return d1[i] < d1[j]; });

    RMQ<int> rmq(a.size(), -(1 << 29), [] (int a, int b) { return max(a, b); });
    for (int i = 0; i < a.size(); ++i) {
      rmq.update(i, d2[a[i]]);
    }

    int mx = 0;
    for (int i = 0; i < a.size(); ++i) {
      int x = rmq.query(i + 1, a.size());
      setmax(mx, d1[a[i]] + x + 1);
    }
    cout << min(mx, d1[n - 1]) << endl;
  }

  return 0;
}
