// github.com/Johniel/contests
// atcoder/njpc2017/H/main.cpp

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

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

template<typename T>
struct link_cut_tree {
public:
  // https://www.slideshare.net/iwiwi/2-12188845
  struct node_t {
    node_t* parent;
    node_t* right;
    node_t* left;
    T value;
    node_t(T v) : value(v), parent(nullptr), left(nullptr), right(nullptr) {}
    // splay木の根であるか親への編がpreferredでない場合にtrue
    bool is_root(void) const {
      return parent == nullptr || (parent->left != this && parent->right != this);
    }
    void rotr(void) {
      node_t* x = parent;
      node_t* y = parent->parent;
      if (x->left = right) right->parent = x;
      right = x;
      x->parent = this;
      if (parent = y) {
        if (y->left == x) y->left = this;
        if (y->right == x) y->right = this;
      }
      return ;
    }
    void rotl(void) {
      node_t* x = parent;
      node_t* y = parent->parent;
      if (x->right = left) left->parent = x;
      left = x;
      x->parent = this;
      if (parent = y) {
        if (y->left == x) y->left = this;
        if (y->right == x) y->right = this;
      }
      return ;
    }
    // 自身をpreferred pathsを管理する木の根にまで移動させる
    void splay(void) {
      while (!is_root()) {
        node_t* x = parent;
        if (x->is_root()) {
          if (x->left == this) rotr();
          else rotl();
        } else {
          node_t* y = x->parent;
          if (y->left == x) {
            if (x->left == this) { x->rotr(); rotr(); }
            else { rotl(); rotr(); }
          } else {
            if (x->right == this) { x->rotl(); rotl(); }
            else { rotr(); rotl(); }
          }
        }
      }
      return ;
    }
  };

  vec<node_t*> nodes;

  link_cut_tree() {};
  link_cut_tree(vec<T> ini) {
    for (int i = 0; i < ini.size(); ++i) insert(ini[i]);
  }
  link_cut_tree(int n, T ini) {
    for (int i = 0; i < n; ++i) insert(ini);
  }
  ~link_cut_tree() {
    for (int i = 0; i < nodes.size(); ++i) {
      delete nodes[i];
    }
  };

  size_t insert(T v) {
    nodes.push_back(new node_t(v));
    return nodes.size() - 1;
  }

  void cut(int x) {
    cut(nodes[x]);
    return ;
  }

  void link(int c, int p) {
    link(nodes[c], nodes[p]);
    return ;
  }

  bool is_connected(int a, int b) {
    if (a == b) return true;
    expose(nodes[a]);
    expose(nodes[b]);
    return nodes[a]->parent != nullptr;
  }

  size_t size(void) const { return nodes.size(); }

private:
  // splay操作を繰り返し頂点xをsplay木の根にまで移動させる。
  node_t* expose(node_t* x) {
    node_t* y = nullptr;
    for (node_t* p = x; p != nullptr; p = p->parent) {
      p->splay();
      p->right = y;
      y = p;
    }
    x->splay();
    return x;
  }
  // 頂点cとその親を結ぶ辺を取り除く。
  void cut(node_t* c) {
    expose(c);
    node_t* p = c->left;
    c->left = nullptr;
    p->parent = nullptr;
    return ;
  }
  // 頂点cの親を頂点pに設定する。
  void link(node_t* c, node_t* p) {
    expose(c);
    expose(p);
    c->parent = p;
    p->right = c;
    return ;
  }
};

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<int> p(n - 1);
    cin >> p;
    each (i, p) --i;
    p.insert(p.begin(), -1);
    vec<int> color(p.size());
    cin >> color;
    link_cut_tree<int> tree(n, 0);
    for (int i = 1; i < p.size(); ++i) {
      int j = p[i];
      if (color[i] != color[j]) tree.link(i, j);
    }
    int q;
    cin >> q;
    while (q--) {
      int op;
      cin >> op;
      if (op == 1) {
        int x;
        cin >> x;
        --x;
        if (x == 0) continue;
        int y = p[x];
        if (tree.is_connected(x, y)) tree.cut(x);
        else tree.link(x, y);
      }
      if (op == 2) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        cout << (tree.is_connected(a, b) ? "YES" : "NO") << endl;
      }
    }
  }
  return 0;
}
