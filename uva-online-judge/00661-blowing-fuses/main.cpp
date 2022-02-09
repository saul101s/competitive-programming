#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int seq = 1;
int n, m, c;
bool state[21];
int fuse_power[21];

void solve()
{
  int power = 0, max_power = 0, fuse = 0;
  int i = 1;
  bool blown = false;
  
  while (n--)
  {
    cin >> fuse_power[i++];
  }
  
  while (m--)
  {
    cin >> fuse;
    
    if (blown) continue;
    
    if (state[fuse])
    {
      power -= fuse_power[fuse];
    }
    else
    {
      power += fuse_power[fuse];
      
      if (power > c) blown = true;
      if (power > max_power) max_power = power;
    }
    
    state[fuse] = !state[fuse];
  }
  
  cout << "Sequence " << seq++ << "\n";
  
  if (blown)
    cout << "Fuse was blown.";
  else
    cout << "Fuse was not blown.\n" << "Maximal power consumption was "
         << max_power << " amperes.";
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

  cin >> n >> m >> c;

  while (n || m || c)
  {
    memset(state, 0, sizeof state);
    
    solve();
    
    cout << "\n\n";
    
    cin >> n >> m >> c;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
