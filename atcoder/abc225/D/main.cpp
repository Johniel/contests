// atcoder/abc225/D/main.cpp
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

  int n, q;
  while (cin >> n >> q) {
    const int N = 1e5 + 3;
    static int front[N];
    static int back[N];
    fill(front, front + N, -1);
    fill(back, back + N, -1);
    while (q--) {
      int op, x, y;
      cin >> op;
      if (op == 1) {
        cin >> x >> y;
        --x;
        --y;
        back[x] = y;
        front[y] = x;
      }
      if (op == 2) {
        cin >> x >> y;
        --x;
        --y;
        back[x] = -1;
        front[y] = -1;
      }
      if (op == 3) {
        cin >> x;
        --x;
        while (front[x] != -1) x = front[x];
        vec<int> v;
        while (x != -1) {
          v.push_back(x);
          x = back[x];
        }
        cout << v.size();
        each (i, v) cout << ' ' << i + 1;
        cout << endl;
      }
    }
  }

  return 0;
}
