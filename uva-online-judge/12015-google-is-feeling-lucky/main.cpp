#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

char urls[10][101];
int scores[10];
int c = 1;

void solve()
{
  cout << "Case #" << c++ << ":\n";
  int best_score = 0;
  
  for (int i = 0; i < 10; i++)
  {
    cin >> urls[i] >> scores[i];
    
    if (scores[i] > best_score) best_score = scores[i];
  }
  
  for (int i = 0; i < 10; i++)
  { 
    if (scores[i] == best_score)
      cout << urls[i] << "\n";
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
    memset(urls, 0, sizeof(urls));
    memset(scores, 0, sizeof(scores));
    
    solve();
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
