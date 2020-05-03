// atcoder/abc165/F/main.cpp
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

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

template<typename T>
struct SegTree {
  int n;
  vector<T> dat;
  using F = function<T(T, T)>;
  F fn;
  T e;
  SegTree(int n_, T e_, F fn_) {
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

  T operator [] (size_t idx) const {
    return dat[idx + n - 1];
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

const int N = 2 * 1e5 + 4;
vec<int> g[N];
vec<int> v;
int r[N];

void rec(int curr, int prev, SegTree<int>& rmq, int y)
{
  int tmp = rmq[v[curr]];
  int mx = rmq.query(0, v[curr]);


  int x = max(mx + 1, tmp);
  rmq.update(v[curr], x);
  r[curr] = max(x, y);

  each (next, g[curr]) {
    if (next == prev) continue;
    rec(next, curr, rmq, r[curr]);
  }

  rmq.update(v[curr], tmp);
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    v.resize(n);
    cin >> v;

    {
      map<int, int> p;
      vec<int> u = v;
      sort(u.begin(), u.end());
      u.erase(unique(u.begin(), u.end()), u.end());
      for (int i = 0; i < u.size(); ++i) {
        p[u[i]] = i + 1;
      }
      for (int i = 0; i < n; ++i) {
        v[i] = p[v[i]];
      }
    }

    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    SegTree<int> rmq(N, -(1 << 29), [] (int a, int b) { return max(a, b); });
    rmq.update(0, 0);
    rec(0, -1, rmq, 0);
    for (int i = 0; i < n; ++i) {
      cout << r[i] << endl;
    }
  }

  return 0;
}
