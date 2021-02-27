#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

struct State
{
  int value;
  vi treasures;
  
  State()
  {
    value = 0;
  }
  
  State(int _value, const vi& _treasures)
  {
    value = _value;
    treasures = _treasures;
  }
};

int t, w, q;
int v[30], d[30], tt[30];
State memo[30][1001];

State bag(int id, int _t)
{
  if (_t < 0) return State(-INF, vi());
  if (_t == 0 || id == q) return State(0, vi());
  if (memo[id][_t].value != -1) return memo[id][_t];
  
  State tmp = bag(id+1, _t);
  State ans = bag(id+1, _t - tt[id]);
  ans.value += v[id];
  
  if(tmp.value > ans.value) ans = tmp;
  else ans.treasures.insert(ans.treasures.begin(), id);
  
  return memo[id][_t] = ans;
}

void solve()
{
  cin >> q;
  
  for (int i = 0; i < q; i++)
  {
    cin >> d[i] >> v[i];
    tt[i] = d[i] * 3 * w;
  }
  
  for (int i = 0; i < 30; i++)
  {
    for (int j = 0; j < 1001; j++)
    {
      memo[i][j].value = -1;
    }
  }
  
  State ans = bag(0, t);
  
  cout << ans.value << "\n";
  cout << ans.treasures.size() << "\n";
  
  int id = 0;
  
  for (int i = 0; i < (int)ans.treasures.size(); i++)
  {
    id = ans.treasures[i];
    cout << d[id] << " " << v[id] << "\n";
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

  cin >> t >> w;

  while (cin)
  {
    solve();
    
    cin >> t >> w;
    
    if (cin) cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
