#include<bits/stdc++.h>
using namespace std;

typedef long long 			ll;
typedef pair<int, int> 		ii;
typedef vector<ii> 			vii;
typedef vector<int> 		vi;
#define INF 1000000000;

int N;

class comparator
{
  public:
  bool operator() (int a, int b) {
    return -a < -b;
  }
};

void solve()
{
	priority_queue<int, vector<int>, comparator> numbers;
	int num = 0;
	int min1 = 0, min2 = 0;
	int sum = 0, cost = 0;
	
	while (N--)
	{
		cin >> num;
		numbers.push(num);
	}
	
	while (numbers.size() > 1)
	{
		min1 = numbers.top();
		numbers.pop();
		min2 = numbers.top();
		numbers.pop();
		
		sum = min1 + min2;
		cost += sum;
		numbers.push(sum);
	}
	
	cout << cost;
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

    while (N != 0)
    {
        solve();
        cout << "\n";
        
        cin >> N;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
