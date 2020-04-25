// atcoder/code-festival-2014-qualb/B/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;

    int x[n];
    fill(x, x + n, 0);

    {
      vec<pair<int, int>> v;
      for (int i = 0; i < a.size(); ++i) {
        v.push_back(make_pair(a[i], i));
      }
      sort(v.begin(), v.end(), [] (pair<int, int> i, pair<int, int> j) {
        if (i.first != j.first) return i.first < j.first;
        return i.second > j.second;
      });
      reverse(v.begin(), v.end());
      set<int> vis;
      for (int i = 0; i < n; ++i) {
        auto itr = vis.lower_bound(v[i].second + 1);
        if (itr != vis.end()) {
          x[v[i].second] += abs(*itr - v[i].second - 1);
        } else {
          x[v[i].second] += n - v[i].second - 1;
        }
        vis.insert(v[i].second);
      }
    }
    {
      vec<pair<int, int>> v;
      for (int i = 0; i < a.size(); ++i) {
        v.push_back(make_pair(a[i], n - i - 1));
      }
      sort(v.begin(), v.end(), [] (pair<int, int> i, pair<int, int> j) {
        if (i.first != j.first) return i.first < j.first;
        return i.second > j.second;
      });
      reverse(v.begin(), v.end());
      set<int> vis;
      for (int i = 0; i < n; ++i) {
        auto itr = vis.lower_bound(v[i].second + 1);
        if (itr != vis.end()) {
          x[n - v[i].second - 1] += abs(*itr - v[i].second - 1);
        } else {
          x[n - v[i].second - 1] += n - v[i].second - 1;
        }
        vis.insert(v[i].second);
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << x[i] << endl;
    }
  }

  return 0;
}
