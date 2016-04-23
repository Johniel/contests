#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class ColorfulGarden {
public:
  vector <string> rearrange(vector <string> garden)
  {
    const int H = 2;
    const int W = garden[0].size();
    string g[2] = {string(W, '@'), string(W, '@')};

    vector<pair<int, int>> v;
    for (int i = 0; i < W; ++i) {
      v.push_back(make_pair(i % 2, i));
    }
    for (int i = 0; i < W; ++i) {
      v.push_back(make_pair((i + 1) % 2, i));
    }

    string s = garden[0] + garden[1];
    map<char, int> cnt;
    for (char c = 'a'; c <= 'z'; ++c) {
      cnt[c] = count(s.begin(), s.end(), c);
    }
    sort(s.begin(), s.end(), [&] (char a, char b) { return (cnt[a] != cnt[b]) ? (cnt[a] < cnt[b]) : (a < b); });
    reverse(s.begin(), s.end());

    for (int i = 0; i < v.size(); ++i) {
      g[v[i].first][v[i].second] = s[i];
    }

    auto validate = [&] () {
      const int di[] = {0, 0, +1, -1};
      const int dj[] = {+1, -1, 0, 0};
      for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
          for (int d = 0; d < 4; ++d) {
            const int ni = i + di[d];
            const int nj = j + dj[d];
            unless (0 <= ni && ni < H) continue;
            unless (0 <= nj && nj < W) continue;
            if (g[i][j] == g[ni][nj]) return false;
          }
        }
      }
      return true;
    };

    if (!validate()) return {};
    return {g[0], g[1]};
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"aa",
 "bb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ab", "ba" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, rearrange(Arg0)); }
	void test_case_1() { string Arr0[] = {"xxxx",
 "xxxx"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, rearrange(Arg0)); }
	void test_case_2() { string Arr0[] = {"abcd",
 "abcd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abcd", "dcba" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, rearrange(Arg0)); }
	void test_case_3() { string Arr0[] = {"abcdefghijklm",
 "nopqrstuvwxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abcdefghijklm", "nopqrstuvwxyz" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, rearrange(Arg0)); }
	void test_case_4() { string Arr0[] = {"aaa",
 "aab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, rearrange(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  ColorfulGarden ___test;
  ___test.run_test(-1);
}

// END CUT HERE
