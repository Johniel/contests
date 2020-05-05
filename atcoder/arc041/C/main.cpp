// atcoder/arc041/C/main.cpp
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

  int n, l;
  while (cin >> n >> l) {
    vec<pair<lli, char>> v(n);
    cin >> v;
    each (i, v) --i.first;
    sort(v.begin(), v.end());

    vec<pair<lli, char>> u;
    vec<vec<pair<lli, char>>> w;
    each (i, v) {
      if (u.size() && u.back().second != i.second) {
        w.push_back(u);
        u.clear();
      }
      u.push_back(i);
    }
    w.push_back(u);

    lli sum = 0;
    if (w.size() && w.front().front().second == 'L') {
      vec<pair<lli, char>> u = w.front();
      w.erase(w.begin());
      for (int i = 0; i < u.size(); ++i) {
        sum += u[i].first - i;
      }
    }
    if (w.size() && w.back().back().second == 'R') {
      vec<pair<lli, char>> u = w.back();
      w.pop_back();
      reverse(u.begin(), u.end());
      for (int i = 0; i < u.size(); ++i) {
        sum += (l - 1) - u[i].first - i;
      }
    }


    for (int i = 0; i < w.size(); i += 2) {
      if (w[i].size() < w[i + 1].size()) {
        for (int j = 0; j < w[i + 1].size(); ++j) {
          sum += w[i + 1][j].first - (w[i].back().first + 1) - j;
        }
        for (int j = 0; j < w[i].size() - 1; ++j) {
          sum += (w[i].back().first - 1 - j) - w[i][j].first;
        }
      } else {
        reverse(w[i].begin(), w[i].end());
        for (int j = 0; j < w[i].size(); ++j) {
          sum += (w[i + 1].front().first - 1) - w[i][j].first - j;
        }
        for (int j = 1; j < w[i + 1].size(); ++j) {
          sum += w[i + 1][j].first - (w[i + 1].front().first + 1) - (j - 1);
        }
      }
    }

    cout << sum << endl;
  }

  return 0;
}
