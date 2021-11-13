// codeforces/656div3/D/main.cpp
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
  PrefixSum(vector<T> v = {}) {
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

int n;
str s;

const int N = 18;
const int K = 30;
PrefixSum<int> sum[K];
map<pair<int, int>, int> memo[K];
int rec(int begin, int end, const int C)
{
  if ('z' - 'a' < C) return 1 << 27;
  if (end - begin == 1) return s[begin] != C + 'a';

  pair<int, int> p = make_pair(begin, end);
  if (memo[C].count(p)) return memo[C][p];

  int mid = begin + (end - begin) / 2;

  int x = (mid - begin) - sum[C](begin, mid);
  x += rec(mid, end, C + 1);

  int y =  (end - mid) - sum[C](mid, end);
  y += rec(begin, mid, C + 1);

  return memo[C][p] = min(x, y);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  while (cin >> n >> s) {
    for (char c = 'a'; c <= 'z'; ++c) {
      vec<int> v;
      for (int i = 0; i < s.size(); ++i) {
        v.push_back(s[i] == c);
      }
      sum[c - 'a'] = PrefixSum<int>(v);
    }
    fill(memo, memo + K, map<pair<int, int>, int>());
    int mn = 1 << 29;
    for (char c = 'a'; c <= 'z'; ++c) {
      setmin(mn, rec(0, n, c - 'a'));
      break;
    }
    cout << mn << endl;
  }

  return 0;
}
