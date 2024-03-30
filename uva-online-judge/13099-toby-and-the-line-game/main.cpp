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
	int LBx, LBy, RUx, RUy;
	stringstream ss(line);
	ss >> LBx >> LBy >> RUx >> RUy;
	int x = RUx - LBx;
	int y = RUy - LBy;
	int d = x*x + y*y;
	printf("%.8f", d / 6.0);
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
  
  getline(cin, line);

  while (line.size() > 0)
  {
    solve();
    printf("\n");
    getline(cin, line);
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
