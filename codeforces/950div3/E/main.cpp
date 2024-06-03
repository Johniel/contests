// github.com/Johniel/contests
// codeforces/950div3/E/main.cpp

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

bool canTransform(vector<vector<int>>& a, vector<vector<int>>& b, int n, int m) {
  const lli P = 2 * 1e5 + 3;

  // 各行のソートされた内容を辞書に保存
  map<ull, int> rowMapA, rowMapB;
  for (int i = 0; i < n; ++i) {
    vector<int> rowA = a[i];
    vector<int> rowB = b[i];
    sort(rowA.begin(), rowA.end());
    sort(rowB.begin(), rowB.end());
    ull keyA = 0;
    ull keyB = 0;
    for (int j = 0; j < m; ++j) {
      keyA = (keyA * P) + rowA[j];
      keyB = (keyB * P) + rowB[j];
    }
    rowMapA[keyA]++;
    rowMapB[keyB]++;
  }

  // 各列のソートされた内容を辞書に保存
  map<ull, int> colMapA, colMapB;
  for (int j = 0; j < m; ++j) {
    vector<int> colA(n), colB(n);
    for (int i = 0; i < n; ++i) {
      colA[i] = a[i][j];
      colB[i] = b[i][j];
    }
    sort(colA.begin(), colA.end());
    sort(colB.begin(), colB.end());
    ull keyA = 0;
    ull keyB = 0;
    for (int i = 0; i < n; ++i) {
      keyA = (keyA * P) + colA[i];
      keyB = (keyB * P) + colB[i];
    }
    colMapA[keyA]++;
    colMapB[keyB]++;
  }

  return rowMapA == rowMapB && colMapA == colMapB;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> b[i][j];
      }
    }

    if (canTransform(a, b, n, m)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
