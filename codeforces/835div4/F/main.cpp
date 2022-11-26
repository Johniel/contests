// github.com/Johniel/contests
// codeforces/835div4/F/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

template<typename T>
struct PrefixSum {
  vector<T> sum;
  PrefixSum(vector<T> v) {
    sum.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back(sum.back() + v[i]);
    }
  }
  T operator () (size_t begin, size_t end) const {
    assert(begin <= end);
    assert(end < sum.size());
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  int n;
  lli c, d;
  while (cin >> n >> c >> d) {
    vec<lli> a(n);
    cin >> a;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    while (a.size() < 4 * n) a.push_back(0);
    PrefixSum<lli> sum(a);
    auto fn = [&] (int k) { // 1周がk+1日
      const lli y = accumulate(a.begin(), a.begin() + min<int>(a.size(), k + 1), 0LL); // 1周でy枚
      lli x = max(0LL, (c / y) - !(c % y)); // x周+w日
      lli w = d - (k + 1) * x;
      setmax(w, 0LL);
      setmin(w, (lli)a.size());
      lli p = sum(0, w); // dまでの残り日数で獲得できる枚数p
      // cout << y << ' ' << x << ' ' << w << ' ' << p << ' ' << c << ' ' << (c <= y * x + p) << endl;
      return c <= y * x + p;
    };

    // fn(12); break;

    if (fn(d)) {
      cout << "Infinity" << endl;
      continue;
    }
    if (!fn(0)) {
      cout << "Impossible" << endl;
      continue;
    }

    int small = 0;
    int large = d;
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (fn(mid)) small = mid;
      else large = mid;
    }
    cout << small << endl;
  }

  return 0;
}
