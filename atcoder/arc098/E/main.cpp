// github.com/Johniel/contests
// atcoder/arc098/E/main.cpp

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

struct UnionFind {
  vector<int> r, p;
  UnionFind(int n): r(n, 0), p(n, -1) {}
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (r[a] > r[b]) swap(a, b);
    p[b] += p[a];
    p[a] = b;
    if (r[a] == r[b]) ++r[b];
    return true;
  }
  int find(int a) {
    return (p[a] < 0) ? a : p[a] = find(p[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  size_t size(int n) {
    return -p.at(find(n));
  }
};

constexpr lli mod = 998244353; // 1e9 + 7;

template<typename T, typename Compare = less<T>>
struct skew_heap {
  struct Node {
    T value;
    Node *l;
    Node *r;
    Node(const T& v) : value(v), l(nullptr), r(nullptr) {}
  };
  Compare comp;
  Node* root = nullptr;
  size_t n = 0;
  skew_heap() {}
  skew_heap(const Compare& c) : comp(c) {}
  ~skew_heap() { clear(root); }

  bool empty() const {
    return size() == 0;
  }

  size_t size() const {
    return n;
  }

  void push(const T& x) {
    root = meld(root, new Node(x));
    ++n;
    return ;
  }

  const T& top(void) const {
    assert(root);
    return root->value;
  }

  void pop(void) {
    assert(root);
    Node* a = root->l;
    Node* b = root->r;
    delete root;
    root = meld(a, b);
    --n;
    return ;
  }

  void meld(skew_heap& other) {
    if (this == &other) return;
    root = meld(root, other.root);
    n += other.n;
    other.root = nullptr;
    other.n = 0;
    return ;
  }

  static void clear(Node* t) {
    if (!t) return;
    clear(t->l);
    clear(t->r);
    delete t;
    return ;
  }

  Node* meld(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (comp(b->value, a->value)) swap(a, b);
    a->r = meld(a->r, b);
    swap(a->l, a->r);
    return a;
  }
};


int main(int argc, char *argv[])
{
  int n, k, q;
  while (cin >> n >> k >> q) {
   vec<int> a(n); for (auto& x : a) cin >> x;

    // 値の大きい順に活性化するための並び
    vec<int> ord(n); iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){ return a[i] > a[j]; });

    UnionFind uf(n);
    vec<char> active(n, 0);

    // 各ブロック用の min-heap（skew heap）
    vector<skew_heap<int>> hs(n);

    // グローバル候補: 「小さい方Q個だけ」保持する max-heap
    priority_queue<int> H;
    auto pushToH = [&](int x){
      H.push(x);
      if ((int)H.size() > q) H.pop(); // Q個だけ残す
    };

    // ブロック r のヒープから、サイズが K-1 を超える分だけ
    // 小さい順に吐き出して H へ移す
    auto trim = [&](int r){
      while ((int)hs[r].size() > max(0, k-1)) {
        pushToH(hs[r].top());
        hs[r].pop();
      }
    };

    // 2 つの活性化済み隣接ブロックを併合（UF + ヒープ meld + trim）
    auto merge_blocks = [&](int x, int y){
      int rx = uf.find(x), ry = uf.find(y);
      if (rx == ry) return;
      bool merged = uf.unite(rx, ry);
      int nr = uf.find(rx);                // 新しい根
      int other = (nr == rx ? ry : rx);    // 併合側
      hs[nr].meld(hs[other]);              // ★ skew-heap meld
      trim(nr);
    };

    auto activate = [&](int i){
      active[i] = 1;
      int r = uf.find(i);
      hs[r].push(a[i]);                    // 値を投入
      trim(r);
      if (i>0   && active[i-1]) merge_blocks(i, i-1);
      if (i+1<n && active[i+1]) merge_blocks(i, i+1);
    };

    long long INF = (1LL<<60), ans = INF;
    for (int idx : ord) {
      activate(idx);                       // Y = a[idx] を有効化
      if ((int)H.size() == q) {            // 候補がQ個そろったときのみ
        long long X = H.top();             // Q番目に小さい値
        setmin(ans, X - (long long)a[idx]);
      }
    }
    cout << ans << endl;
  }
  return 0;

}
