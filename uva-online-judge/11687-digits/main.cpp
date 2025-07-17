#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

char x0c[1000001];
char aux[8];

void solve()
{
  int index = 1;
  int prev = atoi(x0c);
  int curr = strlen(x0c);
  
  while (prev != curr) {
    prev = curr;
    sprintf(aux, "%d", prev);
    curr = strlen(aux);
    index++;
  }
  
  cout << index;
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

  while (cin >> x0c && 'E' != x0c[0])
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
