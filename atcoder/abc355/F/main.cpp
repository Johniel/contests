// github.com/Johniel/contests
// atcoder/abc355/F/main.cpp

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

template<typename T>
struct link_cut_tree {
  // link/cut: njpc2017H
  // evert: ABC355F
  // https://www.slideshare.net/iwiwi/2-12188845
public:
  struct node_t {
    node_t* parent;
    node_t* right;
    node_t* left;
    T value, merged;
    bool rev;
    size_t sz;
    node_t(T v) : value(v), merged(v), parent(nullptr), left(nullptr), right(nullptr), rev(false), sz(1) {}
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
      node_t* y = parent->parent;
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
          x->push();
          push();
          if (x->left == this) rotr();
          else rotl();
        } else {
          node_t* y = x->parent;
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
      return ;
    }
    void update(void) {
      sz = 1;
      merged = value;
      if (left) {
        sz += left->sz;
        merged = max(left->merged, merged);
      }
      if (right) {
        sz += right->sz;
        merged = max(merged, right->merged);
      }
      return ;
    }
    void reverse(void) {
      swap(left, right);
      // TODO: reverse operator for merged
      rev = !rev;
      return ;
    }
    void push(void) {
      if (rev) {
        if (left) left->reverse();
        if (right) right->reverse();
        rev = false;
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

  // 頂点xとその親を結ぶ辺を取り除く。
  void cut(int x) {
    cut(nodes[x]);
    return ;
  }

  // 2頂点間の辺を取り除く。
  void cut(int x, int y) {
    evert(x);
    expose(y);
    assert(nodes[x]->parent == nodes[y]);
    nodes[y]->left = nodes[x]->parent = nullptr;
    nodes[y]->update();
    return ;
  }

  // 頂点cの親を頂点pに設定する。
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

  // 元の木の根を変更する。
  void evert(int x) {
    expose(nodes[x]);
    nodes[x]->reverse();
    nodes[x]->push();
    return ;
  }

  // splay操作を繰り返し頂点xをsplay木の根にまで移動させる。
  void expose(int x) {
    expose(nodes[x]);
    return ;
  }

  T fold(int a, int b) {
    evert(a);
    expose(b);
    return nodes[b]->merged;
  }

  size_t size(void) const { return nodes.size(); }

private:

  node_t* expose(node_t* x) {
    node_t* y = nullptr;
    for (node_t* p = x; p != nullptr; p = p->parent) {
      p->splay();
      p->right = y;
      p->update();
      y = p;
    }
    x->splay();
    return y;
  }

  void cut(node_t* c) {
    expose(c);
    node_t* p = c->left;
    c->left = nullptr;
    p->parent = nullptr;
    c->update();
    return ;
  }

  void link(node_t* c, node_t* p) {
    expose(c);
    expose(p);
    c->parent = p;
    p->right = c;
    p->update();
    return ;
  }
};

int main(int argc, char *argv[])
{
  int n, q;
  while (cin >> n >> q) {
    link_cut_tree<pair<int, int>> tree;
    for (int i = 0; i < n; ++i) {
      tree.insert(make_pair(0, i));
    }
    map<int, pair<int, int>> dummy;
    int z = 0;
    for (int i = 0; i < n - 1; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      const int e = tree.nodes.size();
      tree.insert(make_pair(c, e));
      tree.evert(a);
      tree.link(a, e);
      tree.evert(e);
      tree.link(e, b);
      dummy[e] = make_pair(a, b);
      z += c;
    }

    while (q--) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      pair<int, int> mx = tree.fold(a, b);

      assert(dummy.count(mx.second));

      if (c < mx.first) {
        z -= mx.first;
        z += c;

        pair<int, int> real = dummy[mx.second];
        tree.cut(real.first, mx.second);
        tree.cut(mx.second, real.second);

        dummy.erase(mx.second);

        const int e = tree.nodes.size();
        tree.insert(make_pair(c, e));
        tree.evert(a);
        tree.link(a, e);
        tree.evert(e);
        tree.link(e, b);

        dummy[e] = make_pair(a, b);
      }
      cout << z << endl;
    }
  }

  return 0;
}
