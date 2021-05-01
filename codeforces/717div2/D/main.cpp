// codeforces/717div2/D/main.cpp
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

namespace doubling {
  constexpr int N = 1e5 + 5;
  constexpr int DEPTH = 30;

  int T[N][DEPTH];
  function<int(int)> fn;

  void build(const int size, function<int(int)> fn_)
  {
    fn = fn_;

    for (int i = 0; i < size; ++i) {
      T[i][0] = fn(i);
    }

    for (int i = 1; i < DEPTH; ++i) {
      for (int j = 0; j < size; ++j) {
        T[j][i] = T[T[j][i - 1]][i - 1];
      }
    }

    return ;
  }

  int query(int x, int ntimes)
  {
    for (int i = DEPTH; 0 <= i; --i) {
      if (ntimes & (1 << i)) {
        x = T[x][i];
      }
    }
    return x;
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  const int N = 1e5 + 5;
  static bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < N; ++i) {
    for (int j = 2; i * j < N; ++j) {
      prime[i * j] = false;
    }
  }
  vector<int> p;
  for (int i = 0; i < N; ++i) {
    if (prime[i]) p.push_back(i);
  }

  int n, q;
  while (cin >> n >> q) {
    vec<int> a(n);
    cin >> a;

    map<int, vec<int>> m;
    for (int i = 0; i < a.size(); ++i) {
      m[a[i]].push_back(i);
    }

    static int next[N];
    fill(next, next + N, a.size());
    static int idx[N];
    fill(idx, idx + N, -1);
    for (int i = a.size() - 1; 0 <= i; --i) {
      for (lli j = 2; j * j <= a[i]; ++j) {
        if (a[i] % j == 0) {
          int k = a[i] / j;
          if (idx[k] != -1) setmin(next[i], idx[k]);
          if (idx[j] != -1) setmin(next[i], idx[j]);
          idx[k] = i;
          idx[j] = i;
        }
      }
      if (idx[a[i]] != -1) {
        setmin(next[i], idx[a[i]]);
      }
      if (a[i] != 1) idx[a[i]] = i;
    }
    for (int i = a.size() - 2; 0 <= i; --i) {
      setmin(next[i], next[i + 1]);
    }

    doubling::build(n + 1, [&] (int idx) { return next[idx]; });

    while (q--) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      int z = 0;
      int b = doubling::DEPTH - 1;
      while (0 <= b) {
        int w = doubling::query(x, 1 << b);
        if (w <= y) {
          x = w;
          z += (1 << b);
        }
        --b;
      }
      cout << z + 1 << endl;
    }
  }

  return 0;
}
