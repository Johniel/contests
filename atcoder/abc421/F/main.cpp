// github.com/Johniel/contests
// atcoder/abc421/F/main.cpp

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

// splay-treeを使ったordered_set
template<typename T, class Compare = less<T>>
struct Splay {
  // ABC421F
  struct Node {
    Node* parent;
    Node* right;
    Node* left;
    T value;
    size_t sz;
    Node(T v) : value(v), parent(nullptr), left(nullptr), right(nullptr), sz(1) {}
    size_t size(void) const { return sz; }
    bool is_root(void) const { return parent == nullptr; }
    // this が parent の左子のときの右回転
    void rotate_r(void) {
      Node* x = parent;
      Node* y = parent->parent;
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
    // this が parent の右子のときの左回転
    void rotate_l(void) {
      Node* x = parent;
      Node* y = parent->parent;
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
    void splay(void) {
      while (!is_root()) {
        Node* x = parent;
        if (x->is_root()) {
          (x->left == this) ? rotate_r() : rotate_l();
        } else {
          Node* y = x->parent;
          if (y->left == x) {
            if (x->left == this)  { x->rotate_r(); rotate_r(); }
            else                  { rotate_l();    rotate_r(); }
          } else {
            if (x->right == this) { x->rotate_l(); rotate_l(); }
            else                  { rotate_r();    rotate_l(); }
          }
        }
      }
      return ;
    }
    void update(void) {
      sz = 1;
      if (left) sz += left->sz;
      if (right) sz += right->sz;
      return ;
    }
  };

  struct iterator {
    Node* ptr;
    iterator(Node* p) : ptr(p) {}
    iterator& operator ++ (void) {
      if (ptr->right) {
        ptr = ptr->right;
        while (ptr->left) ptr = ptr->left;
      } else {
        Node* cur = ptr;
        Node* p = ptr->parent;
        while (p && p->right == cur) { cur = p; p = p->parent; }
        ptr = p;
      }
      return *this;
    }
    T& operator * (void) {
      assert(ptr && "nullptr");
      return ptr->value;
    }
    friend bool operator == (const iterator& a, const iterator& b) { return a.ptr == b.ptr; }
    friend bool operator != (const iterator& a, const iterator& b) { return a.ptr != b.ptr; }
  };

  // 0-indexedでnth番目の頂点をsplayして返す。
  Node* kth(int nth) {
    if (nth < 0 || nodes.size() <= nth) return nullptr;
    Node* x = root();
    while (true) {
      int size_l = size(x->left);
      if (nth < size_l) x = x->left;
      else if (nth == size_l) break;
      else { nth -= size_l + 1; x = x->right; }
    }
    splay(x);
    return x;
  }

  // 木を2つに分割した根であるLとRを返す。Lのサイズがkとなるように分割する。
  pair<Node*, Node*> split(int k) {
    if (k <= 0) return make_pair(nullptr, root());
    if (nodes.size() <= k) return make_pair(root(), nullptr);
    Node* x = kth(k);
    Node* L = x->left;
    if (L) { L->parent = nullptr; }
    x->left = nullptr;
    x->update();
    return make_pair(L, x);
  }

  Node* merge(Node* L, Node* R) {
    if (!L) return R;
    if (!R) return L;
    Node* x = rightmost(L);
    splay(x);
    x->right = R;
    R->parent = x;
    x->update();
    return x;
  }

  map<T, Node*, Compare> nodes;

  Splay() = default;
  ~Splay() { for (auto [k, v]: nodes) delete v; }

  bool insert(T t, int nth) {
    if (nodes.count(t)) return false;
    nth = max(0, min<int>(nth, nodes.size()));
    Node* new_node = new Node(t);
    auto [L, R] = split(nth);
    merge(merge(L, new_node), R);
    nodes[t] = new_node;
    return true;
  }

  bool erase(T t) {
    if (!nodes.count(t)) return false;
    Node* x = nodes[t];
    splay(x);
    Node* L = x->left; if (L) L->parent = nullptr;
    Node* R = x->right; if (R) R->parent = nullptr;
    merge(L, R);
    delete x;
    nodes.erase(t);
    return true;
  }

  bool erase_nth(int nth) {
    auto itr = find_by_order(nth);
    if (itr != end()) return erase(itr.ptr);
    else return false;
  }

  iterator find(T val) {
    if (nodes.count(val)) return iterator(nodes[val]);
    return end();
  }

  iterator find_by_order(size_t nth) {
    if (nodes.size() <= nth) return end();
    return iterator(kth(nth));
  }

  int order_by_value(T t) {
    if (!nodes.count(t)) return -1;
    splay(nodes[t]);
    return size(nodes[t]->left);
  }

  size_t size(void) const { return nodes.size(); }

  bool empty(void) const { return nodes.empty(); }

  iterator begin(void) {
    if (nodes.empty()) return end();
    Node* p = root();
    return iterator(leftmost(p));
  }

  iterator end(void) const { return iterator(nullptr); }

private:
  void splay(Node* x) { if (x) x->splay(); }

  Node* root(void) {
    if (nodes.empty()) return nullptr;
    Node* root = nodes.begin()->second;
    splay(root);
    return root;
  }

  int size(Node* x) const { return x ? x->sz : 0; }

  Node* leftmost(Node* x) const {
    if (!x) return nullptr;
    while (x->left) x = x->left;
    return x;
  }

  Node* rightmost(Node* x) const {
    if (!x) return nullptr;
    while (x->right) x = x->right;
    return x;
  }
};

int main(int argc, char *argv[])
{
  int q;
  while (cin >> q) {
    Splay<int> splay;
    assert(splay.insert(0, 0));
    for (int i = 1; i <= q; ++i) {
      if (0) {
        auto itr = splay.begin();
        while (itr != splay.end()) {
          cerr << *itr << ' ';
          ++itr;
        }
        cerr << endl;
      }

      int op;
      cin >> op;
      if (op == 1) {
        int x;
        cin >> x;
        int nth = splay.order_by_value(x);
        splay.insert(i, nth + 1);
      }
      if (op == 2) {
        int x, y;
        cin >> x >> y;
        unless (splay.order_by_value(x) < splay.order_by_value(y)) swap(x, y);
        Splay<int>::iterator p1 = splay.find(x);
        Splay<int>::iterator p2 = splay.find(y);
        ++p1;
        vec<int> v;
        lli z = 0;
        while (p1 != p2) {
          v.push_back(*p1);
          z += *p1;
          ++p1;
        }
        each (k, v) splay.erase(k);
        cout << z << "\n";
      }
    }
  }
  return 0;
}
