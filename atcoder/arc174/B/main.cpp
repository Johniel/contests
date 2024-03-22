// github.com/Johniel/contests
// atcoder/arc174/B/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define makepair(a, b) make_pair(a, b)
// #define endl "\n"

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

namespace math {
  template<std::integral T>
  T ceil(T x, T div) {
    // ABC334B,ARC174B
    assert(div != T(0));
    T r = !!(x % div);
    return x / div + ((x < 0) == (div < 0) ? r : 0);
  }
}

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  vec<lli> a(5), p(5);
  while (cin >> a >> p) {
    if (accumulate(a.begin(), a.end(), 0LL) == 0) {
      cout << *min_element(p.begin() + 2, p.end()) << endl;
      continue;
    }

    a.insert(a.begin(), -1);
    p.insert(p.begin(), -1);

    lli review = 0;
    lli star = 0;
    for (int i = 1; i <= 5; ++i) {
      review += a[i];
      star += i * a[i];
    }

    lli w = 8 * 1e18 + 3;
    if (star >= 3 * review) w = 0;

    // star/review>=3
    // (star+wy)/(review+y)>=3
    // (star+wy)>=3(review+y)
    // star+wy>=3review+3y
    // star-3review>=3y-wy
    // star-3review>=(3-w)y

    lli x = math::ceil<lli>(star - 3 * review, -1) * p[4];
    lli y = math::ceil<lli>(star - 3 * review, -2) * p[5];

    lli z = math::ceil<lli>((star + 4) - 3 * (review + 1), -2) * p[5] + p[4];

    // cout << x << ' ' << y << ' ' << z << endl;

    cout << max(0LL, min({x, y, z, w})) << endl;
    a.erase(a.begin());
    p.erase(p.begin());
  }
  return 0;
}
