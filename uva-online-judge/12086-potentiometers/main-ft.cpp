#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

#define LSOne(S) (S & (-S))

class FenwickTree {
private:
  vi ft;

public:
  FenwickTree() {}
  // initialization: n + 1 zeroes, ignore index 0
  FenwickTree(int n) { ft.assign(n + 1, 0); }

  int rsq(int b) {                                     // returns RSQ(1, b)
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  int rsq(int a, int b) {                              // returns RSQ(a, b)
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(int k, int v) {                    // note: n = ft.size() - 1
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

vi v;
int N = 0;
int c = 1;

void solve()
{
  cout << "Case " << c++ << ":\n";
  
  int r = 0;
  int i = 1;
  
  FenwickTree ft(N);
  
  while (N--)
  {
    cin >> r;
    ft.adjust(i++, r);
  }
  
  string command;
  stringstream ss;
  char action;
  int x, y;
  
  getline(cin, command, '\n');
  getline(cin, command, '\n');
  
  while (command.find("END") == string::npos)
  { 
    ss.str(command);
    ss.seekg(0);
    
    ss >> action >> x >> y;
    
    if (action == 'S')
    {
      ft.adjust(x, y - ft.rsq(x, x));
    }
    else
    {
      cout << ft.rsq(x, y) << endl;
    }
    
    getline(cin, command, '\n');
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

  cin >> N;

  while (N)
  {
    solve();
    v.clear();
    
    cin >> N;
    
    if (N)
      cout << endl;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
