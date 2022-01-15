// atcoder/abc235/D/main.cpp
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

  lli a;
  int dst;
  while (cin >> a >> dst) {
    const lli N = 10000000;
    const lli inf = 1LL << 58;
    static lli cost[N];
    fill(cost, cost + N, inf);
    cost[1] = 0;
    queue<lli> q;
    for (q.push(1); q.size(); ) {
      lli x = q.front();
      q.pop();
      {
        lli y = x * a;
        if (y < N && cost[y] == inf) {
          cost[y] = cost[x] + 1;
          q.push(y);
        }
      }
      if (10 <= x && x % 10) {
        str s = to_string(x / 10);
        s = (char)(x % 10 + '0') + s;
        lli z = stoll(s);
        if (z < N && cost[z] == inf) {
          cost[z] = cost[x] + 1;
          q.push(z);
        }
      }
    }
    if (cost[dst] == inf) cout << -1 << endl;
    else cout << cost[dst] << endl;
  }

  return 0;
}
