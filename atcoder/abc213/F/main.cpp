// github.com/Johniel/contests
// atcoder/abc213/F/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

struct SuffixArray {
  vector<int> rank;
  vector<int> idx;
  const int n;
  SuffixArray(const string& s) : n(s.size()) {
    rank.resize(n + 1);
    idx.resize(n + 1);
    for (int i = 0; i <= s.size(); ++i) {
      idx[i] = i;
      rank[i] = i < n ? s[i] : -1;
    }
    vector<int> tmp(n + 1);
    for (int radix = 1; radix <= n; radix *= 2) {
      auto cmp = [&] (auto i, auto j) {
        if (rank[i] != rank[j]) return rank[i] < rank[j];
        int ri = (i + radix <= n ? rank[i + radix] : -1);
        int rj = (j + radix <= n ? rank[j + radix] : -1);
        return ri < rj;
      };
      sort(idx.begin(), idx.end(), cmp);
      tmp[idx[0]] = 0;
      for (int i = 1; i <= n; ++i) {
        tmp[idx[i]] = tmp[idx[i - 1]] + cmp(idx[i - 1], idx[i]);
      }
      copy(tmp.begin(), tmp.end(), rank.begin());
    }
  }
  int operator [] (int i) const { return idx.at(i); }
  int lower_bound(const string& s, const string& query) const {
    int small = 0;
    int large = idx.size();
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (s.compare(idx[mid], query.size(), query) < 0) small = mid;
      else large = mid;
    }
    return large;
  }
  vector<int> build_lcp(const string& s) {
    rank.resize(n + 1);
    for (int i = 0; i < rank.size(); ++i) rank[idx[i]] = i;

    int h = 0;
    vector<int> lcp(n);
    lcp[0] = 0;
    for (int i = 0; i < n; ++i) {
      int j = idx[rank[i] - 1];
      if (0 < h) --h;
      for (; j + h < n && i + h < n; ++h) {
        if (s[j + h] != s[i + h]) break;
      }
      lcp[rank[i] - 1] = h;
    }
    return lcp;
  }
  void show(string s) const {
    cout << idx << endl;
    for (int i = 0; i < idx.size(); ++i) cout << s.substr(idx[i]) << "$" << endl;
    return ;
  }
};

int main(int argc, char *argv[])
{
  int n;
  str s;
  while (cin >> n >> s) {
    SuffixArray sa(s);
    vec<int> h = sa.build_lcp(s);
    // sa.show(s);

    vec<lli> a(s.size()+1, 0);
    {
      vec<pair<lli, int>> v;
      lli x = 0;
      for (int i = 0; i < h.size(); ++i) {
        lli cnt = 1;
        while (v.size() && h[i] <= v.back().first) {
          x -= v.back().first * v.back().second;
          cnt += v.back().second;
          v.pop_back();
        }
        x += h[i] * cnt;
        v.push_back(make_pair(h[i], cnt));
        a[i + 1] = x;
      }
    }
    vec<lli> b(s.size()+1, 0);
    {
      vec<pair<lli, int>> v;
      lli x = 0;
      for (int i = h.size() - 1; 0 <= i; --i) {
        lli cnt = 1;
        while (v.size() && h[i] <= v.back().first) {
          x -= v.back().first * v.back().second;
          cnt += v.back().second;
          v.pop_back();
        }
        x += h[i] * cnt;
        v.push_back(make_pair(h[i], cnt));
        b[i] = x;
      }
    }
    vec<lli> w(s.size()+1, -999);
    for (int i = 0; i <= s.size(); ++i) {
      w[sa[i]] = a[i] + b[i] + (int)s.size() - sa[i];
    }
    w.pop_back();
    each (i, w) cout << i << endl;
  }
  return 0;
}
