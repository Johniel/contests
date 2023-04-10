// github.com/Johniel/contests
// atcoder/abc294/F/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

#define double long double

int main(int argc, char *argv[])
{
  int n, m;
  lli k;
  while (cin >> n >> m >> k) {
    vec<pair<lli, lli>> a(n);
    vec<pair<lli, lli>> b(m);
    cin >> a >> b;

    // 濃度w以上の組み合わせの個数
    auto fn = [&] (double w) {
      // 濃度がw以下:=(a[0]+b[0])/(a[0]+a[1]+b[0]+b[1])がw以上o
      // w<=(a[0]+b[0])/(a[0]+a[1]+b[0]+b[1])
      // w(a[0]+a[1]+b[0]+b[1])<=(a[0]+b[0])
      // w(a[0]+a[1])+w(b[0]+b[1])<=(a[0]+b[0])
      // w(a[0]+a[1])-a[0]<b[0]-w(b[0]+b[1])

      vec<double> v;
      each (i, a) {
        double x = w * (i.first + i.second) - i.first;
        v.push_back(x);
      }
      sort(v.begin(), v.end());

      // cout << w << ' ' << v << endl;

      lli z = 0;
      each (i, b) {
        double x = i.first - w * (i.first + i.second);
        const double eps = 1e-10;
        // cout << i << ' ' << x << endl;
        z += lower_bound(v.begin(), v.end(), x + eps) - v.begin();
      }
      return z;
    };

    double small = 0;
    double large = 1;
    for (int _ = 0; _ < 100; ++_) {
      double mid = (small + large) / 2;
      if (k <= fn(mid)) small = mid;
      else large = mid;
    }
    cout << large*100 << endl;
    // cout << fn(1.0) << endl;
    // cout << fn(0.5) << endl;
    // cout << fn(0.25) << endl;
    // cout << endl;
  }
  return 0;
}
