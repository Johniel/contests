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




#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define LOOP(i, b, n) for(int i=0; i<(int)n; ++i)


using namespace std;


static const int MAX_TEXT_LEN = 100000;
static const int MAX_QUERY = 1000;
static const int MAX_QUERY_LEN = 1000;
static const int MAX_CHAR = CHAR_MAX;


struct PMA {
  PMA* next[MAX_CHAR]; // next[0] => fail
  vector<int> accept;
  PMA() {
    fill(next, next + MAX_CHAR, (PMA*)NULL);
  }
};

PMA* buildAM(char word[MAX_QUERY][MAX_QUERY_LEN], const int size)
{
  // build tree/tri
  PMA *root = new PMA();
  REP(i, size){
    PMA *node = root;
    for(int j=0; word[i][j] != '\0'; ++j){
      char c = word[i][j];
      if(node->next[c] == NULL) node->next[c] = new PMA();
      node = node->next[c];
    }
    node->accept.push_back(i);
  }
  // make suffix/failure link with BFS
  queue<PMA*> Q;
  for(int c='A'; c<='z'; ++c){
    if(root->next[c] != NULL){
      root->next[c]->next[0] = root;//truism
      Q.push(root->next[c]);
    }
    else root->next[c] = root;
  }
  while(!Q.empty()){
    PMA *node = Q.front(); Q.pop();
    for(int c='A'; c<='z'; ++c){
      if(node->next[c] != NULL){
        Q.push(node->next[c]);
        PMA *linked = node->next[0];
        while(linked->next[c] == NULL)
          linked = linked->next[0];
        node->next[c]->next[0] = linked->next[c];
      }
    }
  }
  return root;
}

void matching(char *text, PMA *node, int *result)
{
  const int len = strlen(text);
  REP (i, len) {
    char c = text[i];
    while(node->next[c] == NULL) node = node->next[0];
    node = node->next[c];
    REP(j, node->accept.size())
      ++result[node->accept[j]];// count frequency
  }
  return ;
}

char text[MAX_TEXT_LEN];
char query[MAX_QUERY][MAX_QUERY_LEN];
int exist[MAX_QUERY];

const int L = 100 + 3;
const int N = 8;
const int B = (1 << N) + 3;
map<PMA*, lli> memo[L][B];
int n;
int l;

int main(int argc, char *argv[])
{
  while (scanf("%d %d\n", &n, &l) == 2) {
    fill(exist, exist + n, 0);
    REP(i, n) scanf("%s\n", query[i]);
    PMA* root = buildAM(query, n);
    // matching(text, root, exist);


    map<PMA*, lli> dp[L][B];
    dp[0][0][root] = 1;
    for (int len = 0; len < l; ++len) {
      for (int bit = 0; bit < (1 << n); ++bit) {
        each (k, dp[len][bit]) {
          for (char c = 'a'; c <= 'z'; ++c) {
            PMA* node = k.first;
            int nb = bit;
            while(node->next[c] == NULL) {
              node = node->next[0];
              each (i, node->accept) nb |= (1 << i);
            }
            node = node->next[c];
            each (i, node->accept) nb |= (1 << i);
            (dp[len + 1][nb][node] += k.second) %= mod;
          }
        }
      }
    }
    lli z = 0;
    each (k, dp[l][(1 << n) - 1]) {
      (z += k.second) %= mod;
    }
    cout << z << endl;
  }

  return 0;
}
