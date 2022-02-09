#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int n, to, amount;
string name;
vector<string> names;
map<string, int> gain;

void solve()
{
  names.clear();
  
  for (int i = 0; i < n; i++)
  {
    cin >> name;
    
    gain[name] = 0;
    names.push_back(name);
  }
  
  for (int i = 0; i < n; i++)
  {
    cin >> name >> amount >> to;
    
    if (amount > 0 && to > 0)
    {
      gain[name] -= amount;
      gain[name] += amount % to;
    }
    
    for (int j = 0; j < to; j++)
    {
      cin >> name;
      gain[name] += amount / to;
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    cout << names[i] << " " << gain[names[i]] << endl;
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

  cin >> n;

  while (true)
  {
    solve();
    
    if (cin >> n)
      cout << "\n";
    else
      break;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
