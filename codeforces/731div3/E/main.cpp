// codeforces/731div3/E/main.cpp
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

  int _;
  cin >> _;

  int n, k;
  while (cin >> n >> k) {
    vec<int> a(k);
    vec<int> t(k);
    cin >> a >> t;
    each (i, a) --i;

    const int N = 3 * 1e5 + 3;
    static lli cost[N];
    const lli inf = 1LL << 60;
    fill(cost, cost + N, inf);
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < k; ++i) {
      q.push(make_pair(-t[i], a[i]));
      cost[a[i]] = t[i];
    }
    while (q.size()) {
      auto p = q.top();
      q.pop();
      int c = abs(p.first);
      int curr = p.second;
      if (cost[curr] != c) continue;
      vec<int> v({curr - 1, curr + 1});
      each (next, v) {
        if (next < 0) continue;
        if (n <= next) continue;
        int d = c + 1;
        if (cost[next] > d) {
          cost[next] = d;
          q.push(make_pair(-d, next));
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      cout << cost[i] << ' ';
    }
    cout << endl;
  }

  return 0;
}
