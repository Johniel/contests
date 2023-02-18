// github.com/Johniel/contests
// codeforces/e143/C/main.cpp

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
    return sum[end] - sum[begin];
  }
  T operator () (size_t end) const {
    return (*this)(0, end);
  }
  int lower_bound(T x) const {
    return std::lower_bound(sum.begin(), sum.end(), x) - sum.begin();
  }
  int upper_bound(T x) const {
    return std::upper_bound(sum.begin(), sum.end(), x) - sum.begin();
  }
};

int main(int argc, char *argv[])
{
  int _;
  cin >> _;
  int n;
  while (cin >> n) {
    vec<lli> a(n), b(n);
    cin >> a >> b;

    vec<lli> cnt(n+1, 0);
    vec<lli> add(n+1, 0);

    PrefixSum<lli> sum(b);
    for (int i = 0; i < n; ++i) {
      // 先頭から
      // 飲まれる量が自身を超えるところを二分探索
      int j = sum.upper_bound(a[i] + sum(i)) - 1;
      // 茶iは人iから人jまでに飲まれる
      ++cnt[i];
      --cnt[j];
      // 人j+1が飲む際になくなる。そのときの残り。
      add[j] += a[i] - sum(i, j);
    }
    for (int i = 0; i < n; ++i) {
      cnt[i + 1] += cnt[i];
    }
    for (int i = 0; i < n; ++i) {
      // b[i]をcnt[i]回飲む
      cout << cnt[i] * b[i] + add[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
