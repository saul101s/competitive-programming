#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

void solve()
{
  string line;
  char ch, tmp;
  int pos = 0;
  int first_sn, last_sn;
  int q;
  map<char, vi> candidates;
  vi tmp_v;
  vi::iterator it;
  cin >> line;
  
  stringstream ss(line);
  
  while (ss >> ch)
  {
    candidates[ch].push_back(pos++);
  }
  
  cin >> q;
  
  while (q--)
  {
    cin >> line;
    ss = stringstream(line);
    
    ss >> ch;
    
    if (candidates.count(ch) == 0)
    {
      cout << "Not matched" << endl;
      break;
    }
    
    tmp_v = candidates[ch];
    first_sn = tmp_v[0];
    it = tmp_v.begin();
    
    tmp = ch;
    
    while (ss >> ch)
    { 
      if (ch == tmp)
      {
        it++;
        
        if (it == tmp_v.end())
        {
          cout << "Not matched" << endl;
          break;
        }
      }
      else
      {
        if (candidates.count(ch) == 0)
        {
          cout << "Not matched" << endl;
          break;
        }
        
        tmp = ch;
        last_sn = *it;
        tmp_v = candidates[ch];
        it = lower_bound(tmp_v.begin(), tmp_v.end(), last_sn);
        
        if (it == tmp_v.end())
        {
          cout << "Not matched" << endl;
          break;
        }
      }
    }
    
    if (it != tmp_v.end())
    {
      last_sn = *it;
      cout << "Matched " << first_sn << " " << last_sn << endl;
    }
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

  solve();

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
