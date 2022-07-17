// atcoder/abc260/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, p;
  while (cin >> n >> p) {
    vec<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
      --a[i];
      --b[i];
    }

    const int N = 2 * 1e5 + 3;
    static vec<int> v[N];
    fill(v, v + N, vec<int>());
    for (int i = 0; i < n; ++i) {
      v[a[i]].push_back(i);
      v[b[i]].push_back(i);
    }

    vec<int> w(p+2, 0);

    queue<int> q;
    map<int, int> m;
    for (int i = 0; i < p; ++i) {
      q.push(i);
      each (j, v[i]) ++m[j];

      if (n <= m.size()) {
        while (n <= m.size()) {
          ++w[q.size()];
          --w[q.size() + (p - i)];
          int k = q.front();
          q.pop();
          each (j, v[k]) {
            --m[j];
            if (m[j] == 0) m.erase(j);
          }
        }
      }
    }

    for (int i = 0; i + 1 < w.size(); ++i) {
      w[i + 1] += w[i];
    }
    for (int i = 1; i + 1 < w.size(); ++i) {
      cout << w[i] << ' ';
    }
    cout << endl;
  }

  return 0;
}
