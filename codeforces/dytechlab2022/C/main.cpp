// github.com/Johniel/contests
// codeforces/dytechlab2022/C/main.cpp

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

  int _;
  cin >> _;

  int n;
  vec<pair<int, int>> v(3);
  pair<int, int> dst;
  while (cin >> n >> v >> dst) {
    each (i, v) --i.first, --i.second;
    --dst.first;
    --dst.second;
    sort(v.begin(), v.end());

    vec<int> a;
    vec<int> b;
    each (i, v) {
      a.push_back(i.first);
      b.push_back(i.second);
    }
    pair<int, int> p;
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < b.size(); ++j) {
        p = make_pair(a[i], b[j]);
        if (find(v.begin(), v.end(), p) == v.end()) {
          i = j = (1 << 29);
        }
      }
    }

    bool f = false;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i + 1; j < v.size(); ++j) {
        if (v[i].first == v[j].first && v[i].first == dst.first) f = true;
        if (v[i].second == v[j].second && v[i].second == dst.second) f = true;
      }
    }
    if (f) {
      cout << "YES" << endl;
      continue;
    }

    {
      vec<pair<int, int>> u;
      u.push_back(make_pair(0, 0));
      u.push_back(make_pair(1, 0));
      u.push_back(make_pair(0, 1));
      sort(u.begin(), u.end());
      if (v == u) {
        cout << "NO" << endl;
        continue;
      }
    }
    {
      vec<pair<int, int>> u;
      u.push_back(make_pair(0, n - 1));
      u.push_back(make_pair(0, n - 2));
      u.push_back(make_pair(1, n - 1));
      sort(u.begin(), u.end());
      if (v == u) {
        cout << "NO" << endl;
        continue;
      }
    }
    {
      vec<pair<int, int>> u;
      u.push_back(make_pair(n - 1, 0));
      u.push_back(make_pair(n - 2, 0));
      u.push_back(make_pair(n - 1, 1));
      sort(u.begin(), u.end());
      if (v == u) {
        cout << "NO" << endl;
        continue;
      }
    }
    {
      vec<pair<int, int>> u;
      u.push_back(make_pair(n - 1, n - 1));
      u.push_back(make_pair(n - 2, n - 1));
      u.push_back(make_pair(n - 1, n - 2));
      sort(u.begin(), u.end());
      if (v == u) {
        cout << "NO" << endl;
        continue;
      }
    }

    // cout << v << endl;
    // cout << p << endl;
    dst.first %= 2;
    dst.second %= 2;
    p.first %= 2;
    p.second %= 2;
    cout << (dst == p ? "NO" : "YES")  << endl;
  }

  return 0;
}
