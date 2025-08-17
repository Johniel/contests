// github.com/Johniel/contests
// atcoder/abc419/F/main.cpp
#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
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

constexpr lli mod = 998244353; // 1e9 + 7;

constexpr int SIGMA = CHAR_MAX;
struct PMA {
  array<PMA*, SIGMA> next; // next[0] => fail
  vector<int> accept;
  PMA() { next.fill(nullptr); }
  PMA* transact(const char c) {
    PMA* node = this;
    while (node->next[c] == nullptr) node = node->next[0];
    return node->next[c];
  }
  static PMA* build(const vector<string>& words);
  static void match(const string& text, PMA* node, vector<int>& freq);
};

PMA* PMA::build(const vector<string>& words)
{
  PMA* root = new PMA();
  for (int i = 0; i < words.size(); ++i) {
    PMA* node = root;
    for (const char& c: words[i]) {
      if (node->next[c] == nullptr) node->next[c] = new PMA();
      node = node->next[c];
    }
    node->accept.push_back(i);
  }

  queue<PMA*> Q;
  for (int c = 'A'; c <= 'z'; ++c) {
    if (root->next[c] != nullptr) {
      root->next[c]->next[0] = root;
      Q.push(root->next[c]);
    } else {
      root->next[c] = root; // rootはfailを使わない。
    }
  }

  while (!Q.empty()) {
    const PMA* node = Q.front();
    Q.pop();
    for (int c = 'A'; c <= 'z'; ++c) {
      if (node->next[c] != nullptr) {
        PMA* child = node->next[c];
        child->next[0] = node->next[0]->transact(c);
        child->accept.insert(child->accept.end(),
                             child->next[0]->accept.begin(),
                             child->next[0]->accept.end());
        Q.push(child);
      }
    }
  }
  return root;
}

void PMA::match(const string& text, PMA* node, vector<int>& freq)
{
  for (const char& c: text) {
    node = node->transact(c);
    for (const int& j: node->accept) ++freq.at(j);
  }
  return ;
}

int main(int argc, char *argv[])
{
  int n, l;
  while (cin >> n >> l) {
    vec<str> v(n);
    cin >> v;
    PMA* root = PMA::build(v);

    const int L = 100 + 3;
    const int N = 8;
    const int B = (1 << N) + 3;
    map<PMA*, lli> dp[L][B];
    dp[0][0][root] = 1;
    for (int len = 0; len < l; ++len) {
      for (int bit = 0; bit < (1 << n); ++bit) {
        each (k, dp[len][bit]) {
          for (char c = 'a'; c <= 'z'; ++c) {
            PMA* node = k.first->transact(c);
            int nb = bit;
            each (i, node->accept) nb |= (1 << i);
            (dp[len + 1][nb][node] += k.second) %= mod;
          }
        }
      }
    }
    lli z = 0;
    each (k, dp[l][(1 << n) - 1]) (z += k.second) %= mod;
    cout << z << endl;
  }

  return 0;
}
