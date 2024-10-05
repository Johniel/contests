// github.com/Johniel/contests
// atcoder/abc374/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n;
  double s, t;
  while (cin >> n >> s >> t) {
    vec<pair<pair<double, double>, pair<double, double>>> ps(n);
    cin >> ps;
    vec<int> idx(n);
    iota(idx.begin(), idx.end(), 1);
    sort(idx.begin(), idx.end());
    double z = 1e128;
    do {
      for (int bit = 0; bit < (1 << n); ++bit) {
        vec<int> v;
        for (int i = 0; i < n; ++i) {
          if (bit & (1 << i)) v.push_back(-idx[i]);
          else v.push_back(+idx[i]);
        }
        pair<double, double> curr = make_pair(0.0, 0.0);
        double sum = 0;
        for (int k = 0; k < v.size(); ++k) {
          const int i = abs(v[k]) - 1;
          pair<double, double> src = ps[i].first;
          pair<double, double> dst = ps[i].second;
          if (0 <= v[k]) swap(src, dst);
          {
            double x = (src.first - curr.first);
            double y = (src.second - curr.second);
            x *= x;
            y *= y;
            sum += sqrt(x + y) / s;
          }
          {
            double x = (src.first - dst.first);
            double y = (src.second - dst.second);
            x *= x;
            y *= y;
            sum += sqrt(x + y) / t;
          }
          curr = dst;
        }
        setmin(z, sum);
      }
    } while (next_permutation(idx.begin(), idx.end()));
    cout << z << endl;
  }
  return 0;
}
