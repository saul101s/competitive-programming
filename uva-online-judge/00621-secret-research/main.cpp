#include<bits/stdc++.h>
#include <regex>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

string code;

regex positive("1|4|78");
regex negative("([0-9]*)35");
regex failed("9([0-9]*)4");
regex not_completed("190([0-9]*)");

void solve()
{
  cin >> code;
  
  if (regex_match(code, positive))
  {
    cout << "+";
  }
  else if (regex_match(code ,negative))
  {
    cout << "-";
  }
  else if (regex_match(code, failed))
  {
    cout << "*";
  }
  else if (regex_match(code, not_completed))
  {
    cout << "?";
  }
  else
  {
    cout << "?";
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

  while (t--)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
