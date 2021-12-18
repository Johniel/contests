// atcoder/abc229/G/main.cpp
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
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  str s;
  lli k;
  while (cin >> s >> k) {
    vec<int> a;
    vec<lli> v;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'Y') {
        a.push_back(i);
        v.push_back(i - v.size());
      }
    }
    PrefixSum<lli> ps(v);
    int z = !!count(s.begin(), s.end(), 'Y');
    queue<int> q;
    for (int i = 0; i < a.size(); ++i) {
      q.push(i);
      while (1 < q.size()) {
        int mn = q.front();
        int mx = q.back();
        lli mid = v[mn + (mx - mn) / 2];
        int idx = lower_bound(v.begin() + mn, v.begin() + mx + 1, mid) - v.begin();
        lli cost = 0;
        cost += ps(idx, mx + 1) - (mx - idx + 1) * mid;
        cost += (idx - mn) * mid - ps(mn, idx);
        if (k < cost) q.pop();
        else {
          setmax<int>(z, q.size());
          break;
        }
      }
    }
    cout << z << endl;
  }

  return 0;
}
