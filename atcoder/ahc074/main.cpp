// github.com/Johniel/contests
// atcoder/ahc074/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& v) { os << "("; for (const auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, const set<T>& s) { os << "set{"; for (const auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, const map<K, V>& m) { os << "map{"; for (const auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (const auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, const deque<T>& q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
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

int N = 64;   // barcode length
int K = 192;  // sheet
int P = 256;  // item
int R = 1024; // order

bool match(str sheet, str barcode)
{
  assert(sheet.size() == barcode.size());
  for (int i = 0; i < sheet.size(); ++i) {
    unless (sheet[i] == '.' || sheet[i] == barcode[i]) return false;
  }
  return true;
}

int common_suffix(str a, str b)
{
  assert(a.size() == b.size());
  int x = 0;
  for (int i = a.size() - 1; 0 <= i; --i) {
    if (a[i] != b[i]) return x;
    ++x;
  }
  return x;
}

bool match_substr(str a, str b, int begin, int end)
{
  assert(begin < end);
  for (int i = begin; i < end; ++i) {
    if (a.at(i) != b.at(i)) return false;
  }
  return true;
}

int main(int argc, char *argv[])
{
  { cin >> N >> K >> P >> R; }
  vec<str> real_barcodes(P);
  cin >> real_barcodes;

  map<str, int> sheet_name;
  deque<str> sheets[N];

  map<str, int> sheet_pos;
  auto update_pos = [&] (void) {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < sheets[i].size(); ++j) {
        sheet_pos[sheets[i][j]] = cnt++;
      }
    }
    return ;
  };

  for (int i = 0; i < N - 5; ++i) {
    str s(N, '.');
    s[i] = '0';
    sheets[i].push_back(s);
    s[i] = '1';
    sheets[i].push_back(s);
  }

  vec<pair<int, int>> operations;
  auto rotate = [&] (int nth_bit) {
    int name = sheet_name[sheets[nth_bit].front()];
    int pos = sheet_pos[sheets[nth_bit].back()];
    operations.push_back(make_pair(name, pos));
    sheets[nth_bit].push_back(sheets[nth_bit].front());
    sheets[nth_bit].pop_front();
    update_pos();
    return ;
  };
  vec<tuple<int, int, int>> history; // sheet_name, src bit, dst bit
  auto expose = [&] (int nth_bit) {
    const int name = sheet_name[sheets[nth_bit].front()];
    operations.push_back(make_pair(name, 0));
    sheets[0].push_front(sheets[nth_bit].front());
    sheets[nth_bit].pop_front();
    history.push_back(make_tuple(name, nth_bit, 0));
    update_pos();
    return ;
  };
  auto lift = [&] (int src_bit, int dst_bit) {
    const int src_name = sheet_name[sheets[src_bit].front()];
    operations.push_back(make_pair(src_name, sheet_pos[sheets[dst_bit].front()]));
    sheets[dst_bit].push_front(sheets[src_bit].front());
    sheets[src_bit].pop_front();
    history.push_back(make_tuple(src_name, src_bit, dst_bit));
    // cerr << "history.back():=" << history.back() << ", " << operations.back() << endl;
    update_pos();
    return ;
  };
  auto revert = [&] (void) {
    while (history.size()) {
      auto [sheet_name, src, dst] = history.back();
      history.pop_back();
      assert(sheets[dst].size());
      sheets[src].push_front(sheets[dst].front());
      sheets[dst].pop_front();
      update_pos();
      operations.push_back(make_pair(sheet_name, sheet_pos[sheets[src].front()]));
    }
    return ;
  };
  auto build_current_barcode = [&] (void) {
    str curr(N, '.');
    for (int nth = 0; nth < N; ++nth) {
      for (int i = 0; i < N; ++i) {
        if (sheets[i].front()[nth] != '.') {
          curr[nth] = sheets[i].front()[nth];
          break;
        }
      }
    }
    assert(count(curr.begin(), curr.end(), '.') == 0);
    return curr;
  };

  {
    deque<str> q;
    vec<str> b = real_barcodes;
    sort(b.begin(), b.end(), [] (auto x, auto y) { return x[N - 1] < y[N - 1]; });
    // cerr << b << endl;
    each (k, b) q.push_back(k);
    for (int _ = 0; _ < 20/2; ++_) {
      if (q.size() < 2) break;
      sheets[63].push_back(q.front());
      sheets[63].push_back(q.back());
      q.pop_front();
      q.pop_back();
    }
    b.clear();
    while (q.size()) {
      b.push_back(q.front());
      q.pop_front();
    }
    each (s, b) s[N - 1] = '.';
    sort(b.begin(), b.end(), [] (auto x, auto y) { return x[N - 2] < y[N - 2]; });
    // cerr << b << endl;
    each (k, b) q.push_back(k);
    for (int _ = 0; _ < 18/2; ++_) {
      if (q.size() < 2) break;
      sheets[62].push_back(q.front());
      sheets[62].push_back(q.back());
      q.pop_front();
      q.pop_back();
    }
    b.clear();
    while (q.size()) {
      b.push_back(q.front());
      q.pop_front();
    }
    each (s, b) s[N - 2] = '.';
    sort(b.begin(), b.end(), [] (auto x, auto y) { return x[N - 3] < y[N - 3]; });
    // cerr << b << endl;
    each (k, b) q.push_back(k);
    for (int _ = 0; _ < 16/2; ++_) {
      if (q.size() < 2) break;
      sheets[61].push_back(q.front());
      sheets[61].push_back(q.back());
      q.pop_front();
      q.pop_back();
    }
    b.clear();
    while (q.size()) {
      b.push_back(q.front());
      q.pop_front();
    }
    each (s, b) s[N - 3] = '.';
    sort(b.begin(), b.end(), [] (auto x, auto y) { return x[N - 4] < y[N - 4]; });
    // cerr << b << endl;
    each (k, b) q.push_back(k);
    for (int _ = 0; _ < 12/2; ++_) {
      if (q.size() < 2) break;
      sheets[60].push_back(q.front());
      sheets[60].push_back(q.back());
      q.pop_front();
      q.pop_back();
    }
    b.clear();
    while (q.size()) {
      b.push_back(q.front());
      q.pop_front();
    }
    each (s, b) s[N - 4] = '.';
    sort(b.begin(), b.end(), [] (auto x, auto y) { return x[N - 5] < y[N - 5]; });
    // cerr << b << endl;
    each (k, b) q.push_back(k);
    for (int _ = 0; _ < 8/2; ++_) {
      if (q.size() < 2) break;
      sheets[59].push_back(q.front());
      sheets[59].push_back(q.back());
      q.pop_front();
      q.pop_back();
    }

    b.clear();
    while (q.size()) {
      b.push_back(q.front());
      q.pop_front();
    }
    for (int i = 58; 0 <= i && b.size(); --i) {
      each (s, b) s[i + 1] = '.';
      map<str, int> suff_freq;
      const int SUFF_PATTERN_LEN = 8;
      for (int j = 0; j < b.size(); ++j) {
        str suff;
        for (int k = 0; k < SUFF_PATTERN_LEN && 0 <= i - k; ++k) {
          suff += b[j][i - k];
        }
        reverse(suff.begin(), suff.end());
        ++suff_freq[suff];
      }
      cerr << suff_freq << endl;

      // sort(b.begin(), b.end(), [&] (auto x, auto y) { return x[N - i - 1] < y[N - i - 1]; });
      int _0 = -1, suff_freq_0 = -1;
      int _1 = -1, suff_freq_1 = -1;
      for (int j = 0; j < b.size(); ++j) {
        str suff;
        for (int k = 0; k < SUFF_PATTERN_LEN && 0 <= i - k; ++k) {
          suff += b[j][i - k];
        }
        reverse(suff.begin(), suff.end());
        assert(suff.size() <= SUFF_PATTERN_LEN);
        if (b[j][i] == '0' && suff_freq_0 < suff_freq[suff]) {
          _0 = j;
          suff_freq_0 = suff_freq[suff];
        }
        if (b[j][i] == '1' && suff_freq_1 < suff_freq[suff]) {
          _1 = j;
          suff_freq_1 = suff_freq[suff];
        }
      }
      if (_0 == -1 || _1 == -1) break;
      cerr << make_pair(suff_freq_0, suff_freq_1) << endl;
      assert(sheets[i].size() == 2);
      sheets[i].pop_back();
      sheets[i].pop_back();
      sheets[i].push_back(b[_0]);
      sheets[i].push_back(b[_1]);
      if (_0 < _1) b.erase(b.begin() + _1), b.erase(b.begin() + _0);
      if (_1 < _0) b.erase(b.begin() + _0), b.erase(b.begin() + _1);
    }
  }

  {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < sheets[i].size(); ++j) {
        sheet_name[sheets[i][j]] = cnt++;
      }
    }
    cerr << cnt << endl;
    assert(cnt == K);
    assert(sheet_name.size() == cnt);
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < sheets[i].size(); ++j) {
      cout << sheets[i][j] << endl;
    }
  }

  const int inf = (1 << 28);
  int final_cost = 0;
  vec<pair<int, int>> lift_history;
  for (int turn = 0; turn < R; ++turn) {
    str curr = build_current_barcode();
    str prev = curr;
    int req;
    cin >> req;
    cerr << "turn:" << turn << ", " << real_barcodes[req] << endl;
    operations.clear();
    if (curr != real_barcodes[req]) {
      update_pos();
      if (history.size()) revert();
      curr = build_current_barcode();

      {
        for (int i = 0; i + 1 < N; ++i) {
          unless (sheets[i].front()[i] != '.' && sheets[i].front()[i + 1] == '.') {
            for (int j = 0; j < N; ++j) {
              cerr << sheets[j].front() << endl;
            }
          }
          assert(sheets[i].front()[i] != '.' && sheets[i].front()[i + 1] == '.');
        }
      }

      vec<int> memo(N + 1, inf); // [index]:=cost
      vec<pair<int, int>> path(N + 1, make_pair(-1, -1)); // [curr]:={next,rot}
      function<int(int)> rec = [&] (const int curr) {
        if (curr == N) return 0;
        if (memo.at(curr) != inf) return memo[curr];
        int mn = inf;
        pair<int, int> p;
        for (int next = curr; next < N; ++next) {
          for (int rot = 0; rot < sheets[next].size(); ++rot) {
            if (match_substr(real_barcodes[req], sheets[next][rot], curr, next + 1)) {
              int c = rec(next + 1);
              c += rot;
              if (curr != next) c += 2; // lift + revert
              if (mn >= c) {
                mn = c;
                p = make_pair(next, rot);
              }
            }
          }
        }
        path[curr] = p;
        return memo[curr] = mn;
      };

      vec<pair<int, int>> costs(N + 1, make_pair(inf, inf)); // {operations,nth}
      for (int i = 0; i < N; ++i) {
        costs[i] = make_pair(0, i);
        if (i) {
          bool found = false;
          for (int k = 0; k < sheets[i - 1].size(); ++k) {
            if (match(sheets[i - 1][k], real_barcodes[req])) {
              found = true;
              break;
            }
            ++costs[i].first; // rot
          }
          ++costs[i].first; // lift
          ++costs[i].first; // revert
          unless (found) costs[i].first = inf;
        }
        costs[i].first += rec(i);
        break;
      }
      auto [_, nth] = *min_element(costs.begin(), costs.end());

      final_cost += _;
      lift_history.push_back(make_pair(nth, _));
      assert(_ < N);

      {
        vec<pair<int, int>> p;
        function<void(int)> build_path = [&] (int curr) {
          if (curr == N) return ;
          p.push_back(path[curr]);
          build_path(path[curr].first + 1);
          return ;
        };
        build_path(nth);
        reverse(p.begin(), p.end());

        // cerr << p << endl;

        for (int i = nth; i < N; ++i) {
          auto [j, rot] = p.back();
          p.pop_back();
          if (i == j) {
            for (int _ = 0; _ < rot; ++_) rotate(i);
            if (real_barcodes[req][i] != sheets[i].front()[i]) rotate(i);
          } else {
            for (int _ = 0; _ < rot; ++_) rotate(j);
            lift(j, i);
          }
          // assert(match_substr(real_barcodes[req], sheets[j].front(), i, j + 1));
          i = j;
        }
        if (0 < nth) {
          int cnt = 0;
          while (!match(sheets[nth - 1].front(), real_barcodes[req])) {
            rotate(nth - 1);
            assert(++cnt < 300);
          }
          expose(nth - 1);
        }
      }
    }

    {
      auto actual = build_current_barcode();
      unless (actual == real_barcodes[req]) {
        for (int i = 0; i < N; ++i) cerr << sheets[i].front() << endl;
        cerr << "actual:   " << actual << endl;
        cerr << "expected: " << real_barcodes[req] << endl;
      }
      assert(actual == real_barcodes[req]);
    }
    cout << operations.size() << endl;
    each (k, operations) cout << k.first << ' ' << k.second << endl;


    bool f = false;
    each (k, operations) f = f || (k.second == -1);
    if (f) {
      for (int i = 0; i < N; ++i) cerr << sheets[i].front() << endl;
      each (k, operations) assert(k.second != -1);
    }
  }
  final_cost -= history.size();

  map<int, int> freq;
  each (i, lift_history) ++freq[i.first];
  map<int, int> cost;
  each (i, lift_history) cost[i.first] += i.second;

  each (i, cost) cerr << i.first << "," << cost[i.first] << "," << freq[i.first] << "," << double(cost[i.first])/freq[i.first] << endl;
  cerr << final_cost << endl;

  return 0;
}
