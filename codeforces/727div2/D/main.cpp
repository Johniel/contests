// codeforces/727div2/D/main.cpp
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
    vec<pair<ull, ull>> v(n);
    cin >> v;
    sort(v.begin(), v.end(), [] (auto a, auto b) { return a.second < b.second; });

    ull bought = 0;
    ull cost = 0;
    deque<pair<ull, ull>> q;
    each (i, v) q.push_back(i);

    while (q.size()) {
      ull req = q.front().second - bought;
      while (q.size() && 0 < req) {
        auto p = q.back();
        q.pop_back();
        auto mn = min(req, p.first);
        req -= mn;
        p.first -= mn;
        bought += mn;
        cost += mn * 2;
        if (p.first) q.push_back(p);
      }
      if (q.empty()) break;
      while (q.size() && q.front().second <= bought) {
        auto p = q.front();
        q.pop_front();
        bought += p.first;
        cost += p.first;
      }
    }

    cout << cost << endl;
  }

  return 0;
}
