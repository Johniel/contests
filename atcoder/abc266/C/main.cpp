// github.com/Johniel/contests
// atcoder/abc266/C/main.cpp

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

using P = complex<double>;
const double eps = 1e-8;
double norm(P a) { return a.real()*a.real() + a.imag() * a.imag(); }
double abs (P a) { return sqrt(norm(a)); }
double dot  (P a, P b) { return a.real()*b.real() + a.imag()*b.imag(); }
double cross(P a, P b) { return a.real()*b.imag() - a.imag()*b.real(); }

P project(P s1, P s2, P p) {
  P base = s2 - s1;
  double t = dot(p - s1, base)/norm(base);
  return s1 + base*t;
}

P reflect(P s1, P s2, P p) { return p + (project(s1, s2, p) - p)*2.0; }

P getRotateP(P p, double rad, P o = P(0, 0)) {
  P q = p - o;
  return o + P(q.real()*cos(rad) - q.imag()*sin(rad),
	   q.real()*sin(rad) + q.imag()*cos(rad));
}

namespace CCW {
  enum { COUNTER_CLOCKWISE = 1, CLOCKWISE = -1,
	 ONLINE_BACK = 2, ONLINE_FRONT = -2,
	 ONSEGMENT = 0 };
}

int ccw(P p0, P a, P b) {
  a -= p0;
  b -= p0;
  if(cross(a, b) > eps) return CCW::COUNTER_CLOCKWISE;
  if(cross(a, b) < -eps) return CCW::CLOCKWISE;
  if(dot(a, b) < -eps) return CCW::ONLINE_BACK;
  if(norm(b)-norm(a) > eps) return CCW::ONLINE_FRONT;
  return CCW::ONSEGMENT;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  vec<pair<int, int>> v(4);
  while (cin >> v) {
    bool f = true;
    for (int i = 0; i < v.size(); ++i) {
      int j = (i + 1) % v.size();
      int k = (i + 2) % v.size();
      P a(v[i].first, v[i].second);
      P b(v[j].first, v[j].second);
      P c(v[k].first, v[k].second);
      f = f && (ccw(a, b, c) == CCW::COUNTER_CLOCKWISE);
    }
    cout << (f ? "Yes" : "No") << endl;
  }

  return 0;
}
