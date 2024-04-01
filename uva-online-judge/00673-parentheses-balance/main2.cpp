#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

string line;

void solve()
{
  string line;
  getline(cin, line);
  stringstream ss(line);
  vi pOpened;
  vi bOpened;

  char c;
  bool fail = false;
  while (ss >> c && !fail) {
    if (c == '[') {
      bOpened.push_back(pOpened.size());
    } else if (c == '(') {
      pOpened.push_back(bOpened.size());
    } else if (c == ']') {
      if (bOpened.size() <= 0) {
        fail = true;
      } else {
        uint32_t openedP = bOpened.back();
        if (openedP != pOpened.size()) fail = true;
        bOpened.pop_back();
      }
    } else if (c == ')') {
      if (pOpened.size() <= 0) {
        fail = true;
      } else {
        uint32_t openedB = pOpened.back();
        if (openedB != bOpened.size()) fail = true;
        pOpened.pop_back();
      }
    }
  }
  
  if (pOpened.size() > 0 || bOpened.size() > 0) fail = true;
  
  if (fail) {
    cout << "No";
  } else {
    cout << "Yes";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("my-output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
  #endif

  int t = 1;
  cin >> t;
  getline(cin, line);

  while (t--)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
