#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

string instruction;
int moves[100];

void solve()
{
  int n, p, i, which;
  
  cin >> n;
  getline(cin, instruction, '\n');
  
  p = 0;
  i = 0;
  
  while (n--)
  {
    getline(cin, instruction, '\n');
    
    if (instruction.find("LEFT") != string::npos)
    {
      moves[i] = -1;
    }
    else if (instruction.find("RIGHT") != string::npos)
    {
      moves[i] = 1;
    }
    else
    {
      which = atoi(instruction.substr(8).c_str()) - 1;
      moves[i] = moves[which];
    }
    
    p += moves[i++];
  }
  
  cout << p;
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
    memset(moves, 0, sizeof moves);
    
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
