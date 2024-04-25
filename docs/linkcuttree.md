# linkcuttree

+ [プログラミングコンテストでのデータ構造 2　～動的木編～](https://www.slideshare.net/iwiwi/2-12188845)
+ [ei1333の日記 Link-Cut 木](https://ei1333.hateblo.jp/entry/2018/05/29/011140)
+ [kopricky アルゴリズムライブラリ link cut tree](https://kopricky.github.io/code/DataStructure_OnGraph/link_cut_tree.html)

``` cpp
template<typename T>
struct link_cut_tree {
public:
  // njpc2017H
  struct node_t {
    node_t* parent;
    node_t* right;
    node_t* left;
    T value;
    node_t(T v) : value(v), parent(nullptr), left(nullptr), right(nullptr) {}
    // 親を持たない||親への辺がpreferred-edgeでない
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
    // expose(a)でaを根に移動させる。
    // expose(b)でbを根に移動させる。
    // aの代わりにbが根になっていたら同じ木にいるはず。
    return nodes[a]->parent != nullptr;
  }

  size_t size(void) const { return nodes.size(); }

  node_t* expose(node_t* x) {
    node_t* y = nullptr;
    for (node_t* p = x; p != nullptr; p = p->parent) {
      p->splay();
      // 本来パスを扱っていることを考えると末尾への追加になる。木の回転はinorderを維持するのでpの後ろに追加したければ
      // pをsplayしてpの右の子とすればいい。
      p->right = y;
      y = p;
    }
    x->splay();
    return y;
  }

  void cut(node_t* c) {
    expose(c);
    node_t* p = c->left;
    // inorderでパス（列）を扱っていることを思い出すとcの直前の要素はexporseして左にあるはず。
    c->left = nullptr;
    p->parent = nullptr;
    return ;
  }

  void link(node_t* c, node_t* p) {
    expose(c);
    expose(p);
    c->parent = p;
    p->right = c;
    return ;
  }
};
```
