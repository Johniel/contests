// atcoder/arc042/B/main.cpp
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

constexpr lli mod = 1e9 + 7;

double dot(point a, point b)
{
  return (a.real() * b.real() + a.imag() * b.imag());
}

double cross(point a, point b)
{
  return (a.real() * b.imag() - a.imag() * b.real());
}

const double EPS = 1e-7;

double distance_lp(point a1, point a2, point b)
{
  if(dot(a2-a1, b-a1) < EPS)return abs(b-a1);
  if(dot(a1-a2, b-a2) < EPS)return abs(b-a2);
  return abs(cross(a2-a1, b-a1)) / abs(a2-a1);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x, y, n;
  while (cin >> x >> y >> n) {
    vector<pair<double, double>> v(n);
    cin >> v;
    double mn = 1e128;
    for (int i = 0; i < v.size(); ++i) {
      int j = (i + 1) % v.size();
      point a1(v[i].first, v[i].second);
      point a2(v[j].first, v[j].second);
      point b(x, y);
      setmin(mn, distance_lp(a1, a2, b));
    }
    printf("%.10lf\n", mn);
  }

  return 0;
}
