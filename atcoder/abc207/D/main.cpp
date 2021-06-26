// atcoder/abc207/D/main.cpp
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
constexpr double eps = 1e-5;

#define double long double

double angle(double x, double y)
{
  return atan2(y, x);
}

double angle(pair<double, double> p)
{
  return angle(p.first, p.second);
}

pair<double, double> rot(pair<double, double> p, double th)
{
  double a = p.first * cos(th) - p.second * sin(th);
  double b = p.first * sin(th) + p.second * cos(th);
  return make_pair(a, b);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<pair<double, double>> a(n), b(n);
    cin >> a >> b;

    pair<double, double> ca, cb;
    ca = cb = make_pair(0, 0);

    each (i, a) {
      ca.first += i.first;
      ca.second += i.second;
    }
    ca.first /= n;
    ca.second /= n;

    each (i, b) {
      cb.first += i.first;
      cb.second += i.second;
    }
    cb.first /= n;
    cb.second /= n;

    each (i, a) {
      i.first -= ca.first;
      i.second -= ca.second;
    }
    each (i, b) {
      i.first -= cb.first;
      i.second -= cb.second;
    }

    bool f = false;
    each (i, a) {
      each (j, b) {
        vec<pair<double, double>> c;
        double th = angle(i) - angle(j);
        each (k, b) c.push_back(rot(k, th));
        sort(a.begin(), a.end());
        sort(c.begin(), c.end());
        bool g = true;
        for (int k = 0; k < n; ++k) {
          g = g && abs(a[k].first - c[k].first) <= eps && abs(a[k].second - c[k].second) <= eps;
        }
        f = f || g;
      }
    }
    cout << (f ? "Yes" : "No") << endl;
  }

  return 0;
}
