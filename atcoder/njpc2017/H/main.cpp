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
  // njpc2017H
  struct node_t {
  public:
    T value;
    const int index;
    bool rev;
    node_t* parent;
    node_t* right;
    node_t* left;
    int sz;
    node_t(T v, int idx) :
      value(v),
      parent(nullptr),
      left(nullptr),
      right(nullptr),
      index(idx),
      sz(1),
      rev(false) {}

    bool is_root(void) {
      // 親を持たない||親への辺がpreferred-edgeでない
      return parent == nullptr || (parent->left != this && parent->right != this);
    }

    void rotr(void) {
      node_t* x = parent;
      node_t* y = x->parent;
      if (x->left = right) right->parent = x;
      right = x;
      x->parent = this;
      x->update();
      update();
      if (parent = y) {
        if (y->left == x) y->left = this;
        if (y->right == x) y->right = this;
        y->update();
      }
      return ;
    }

    void rotl(void) {
      node_t* x = parent;
      node_t* y = x->parent;
      if (x->right = left) left->parent = x;
      left = x;
      x->parent = this;
      x->update();
      update();
      if (parent = y) {
        if (y->left == x) y->left = this;
        if (y->right == x) y->right = this;
        y->update();
      }
      return ;
    }

    // 自身をpreferred pathsを管理する木の根にまで移動させる
    void splay(void) {
      push();
      while (!is_root()) {
        node_t* x = parent;
        if (x->is_root()) {
          // 根に近い方からpush
          x->push();
          push();
          if (x->left == this) rotr();
          else rotl();
        } else {
          node_t* y = x->parent;
          // 根に近い方からpush
          y->push();
          x->push();
          push();
          if (y->left == x) {
            if (x->left == this) { x->rotr(); rotr(); }
            else { rotl(); rotr(); }
          } else {
            if (x->right == this) { x->rotl(); rotl(); }
            else { rotr(); rotl(); }
          }
        }
      }
      push();
      return ;
    }

    void update(void) {
      sz = 1;
      if (left) {
        left->push();
        sz += left->size();
      }
      if (right) {
        right->push();
        sz += right->size();
      }
      return ;
    }

    // 作用を伝搬させる。
    void push(void) {
      if (rev) {
        swap(left, right);
        if (left) left->reverse();
        if (right) right->reverse();
        rev = 0;
      }
      return ;
    }

    // 左右を反転させる。
    void reverse(void) {
      rev = !rev;
      return ;
    }

    // 部分木の大きさ
    size_t size(void) const { return sz; }
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

  int insert(T v) {
    nodes.push_back(new node_t(v, nodes.size()));
    return nodes.size() - 1;
  }

  void cut(int x) {
    cut(nodes[x]);
    return ;
  }

  void link(int a, int b) {
    assert(!is_connected(a, b));
    evert(a);
    link(nodes[a], nodes[b]);
    return ;
  }

  bool is_connected(int a, int b) {
    if (a == b) return true;
    expose(nodes[a]);
    expose(nodes[b]);
    // expose(a)でaを根に移動させる。
    // expose(b)でbを根に移動させる。
    // aの代わりにbが根になっていたら同じ木にいるはず。
    return nodes[a]->parent;
  }

  // パスの集合として扱っていた元々の木の根を変更する。
  void evert(int x) {
    // exposeして左右を反転させると元々の木の根を変えることができる。信じられない。
    expose(nodes[x]);
    nodes[x]->reverse();
    nodes[x]->push();
    return ;
  }

  // 連結ならLCAの頂点番号を返す。そうでなければ-1。
  int lca(int a, int b) {
    if (a == b) return a;
    expose(nodes[a]);
    node_t* c = expose(nodes[b]);
    return nodes[a]->parent ? c->index : -1;
  }

  // 頂点aから頂点bに向けてkだけ進んだところに存在する頂点zを返す。なければ-1。
  int get_kth(int a, int b, int k) {
    if (!is_connected(a, b)) return -1;
    if (k == 0) return a;
    evert(b);
    expose(nodes[a]);
    node_t* x = nodes[a];
    while (x) {
      x->push();
      if (x->right && k < x->right->size()) {
        x = x->right;
      } else {
        if (x->right) k -= x->right->size();
        if (k == 0) return x->index;
        --k;
        x = x->left;
      }
    }
    return -1;
  }

  // この頂点を根とした部分木の大きさ。
  size_t size(void) const { return nodes.size(); }

  void show(void) {
    for (int i = 0; i < nodes.size(); ++i) {
      if (nodes[i]->is_root()) {
        vec<pair<int, int>> v;
        v.push_back(make_pair(i, 0));
        while (v.size()) {
          auto [x, depth] = v.back();
          v.pop_back();
          nodes[x]->push();
          pair<int, int> p = make_pair(-1, -1);
          if (nodes[x]->left) {
            p.first = nodes[x]->left->index;
            v.push_back(make_pair(p.first, depth + 1));
          }
          if (nodes[x]->right) {
            p.second = nodes[x]->right->index;
            v.push_back(make_pair(p.second, depth + 1));
          }
          int y = -1;
          if (nodes[x]->parent) y = nodes[x]->parent->index;
          cout << str(depth * 2, ' ') << x << ": " << y << p << "s:" << nodes[x]->size() << "r:" << nodes[x]->rev << endl;
        }
      }
    }
    return ;
  }

private:

  // 最後に右の子を書き換えられた(preferred-edgeが変化した)頂点を返す。
  node_t* expose(node_t* x) {
    node_t* y = nullptr;
    for (node_t* p = x; p != nullptr; p = p->parent) {
      p->splay();
      // 本来パスを扱っていることを考えると末尾への追加になる。木の回転はinorderを維持するのでpの後ろに追加したければ
      // pをsplayしてpの右の子とすればいい。
      p->right = y;
      p->update(); // 子を書き換えたので更新
      y = p;
    }
    x->splay(); // どこかの右の子になっただけなのでsplay操作で根まで移動させる。
    return y;
  }

  void cut(node_t* c) {
    expose(c);
    node_t* p = c->left;
    // inorderでパス（列）を扱っていることを思い出すとcの直前の要素はexporseして左にあるはず。
    c->left = nullptr;
    c->update(); // 子を書き換えたので更新
    p->parent = nullptr;
    return ;
  }

  void link(node_t* c, node_t* p) {
    // evert(c)でない理由はなに？
    expose(c);
    expose(p);
    c->parent = p;
    // パスのこの位置から後ろに付け替えるので右
    p->right = c;
    p->update(); // 子を書き換えたので更新
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
