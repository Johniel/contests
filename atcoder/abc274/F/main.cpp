// github.com/Johniel/contests
// atcoder/abc274/F/main.cpp

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

template<typename T = long long int>
struct Frac {
  T molecule;
  T denominator;
  Frac() : molecule(0), denominator(1) {}
  Frac(T m) : molecule(m), denominator(1) {}
  Frac(T m, T d) : molecule(m), denominator(d) {
    assert(d);
    if (molecule) {
      lli g = __gcd(abs(molecule), abs(denominator));
      molecule /= g;
      denominator /= g;
    }
  }
  bool operator < (const Frac& other) const {
    return molecule * other.denominator < other.molecule * denominator;
  }
};
template<typename T>
ostream& operator << (ostream& os, Frac<T> r)
{
  os << r.molecule << '/' << r.denominator;
  return os;
}

int main(int argc, char *argv[])
{
  int n;
  lli a;
  while (cin >> n >> a) {
    lli w[n], x[n], v[n];
    for (int i = 0; i < n; ++i) {
      cin >> w[i] >> x[i] >> v[i];
    }
    lli mx = 0;
    for (int i = 0; i < n; ++i) {
      vec<pair<Frac<>, vec<lli>>> events;
      for (int j = 0; j < n; ++j) {
        lli dx = x[j] - x[i];
        lli dv = v[j] - v[i];
        if (dv == 0 && 0 <= dx && dx <= a) {
          events.push_back(make_pair(Frac<>(), vec<lli>({i, -w[j]})));
        }
        if (0 < dv) {
          Frac<> add(-dx, dv);
          Frac<> del(a - dx, dv);
          events.push_back(make_pair(add, vec<lli>({i, -w[j]})));
          events.push_back(make_pair(del, vec<lli>({i, +w[j]})));
        }
        if (dv < 0) {
          Frac<> add(dx - a, -dv);
          Frac<> del(dx, -dv);
          events.push_back(make_pair(add, vec<lli>({i, -w[j]})));
          events.push_back(make_pair(del, vec<lli>({i, +w[j]})));
        }
      }
      sort(events.begin(), events.end());


    // cout << events << endl;

    lli m[n];
    fill(m, m + n, 0);

    each (e, events) {
        int i = e.second[0];
        int x = e.second[1];
        m[i] -= x;
      unless (e.first < Frac<>()) {
        setmax(mx, m[i]);
      }
    }

    }
    cout << mx << endl;
  }
  return 0;
}
