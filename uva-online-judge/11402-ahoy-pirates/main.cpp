#include<bits/stdc++.h>
using namespace std;

typedef long long 			ll;
typedef pair<int, int> 		ii;
typedef vector<ii> 			vii;
typedef vector<int> 		vi;
#define INF 1000000000;


class SegmentTree {         // the segment tree is stored like a heap array
private: vi st, A;            // recall that vi is: typedef vector<int> vi;
  int n;
  int left (int p) { return p << 1; }     // same as binary heap operations
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) { // O(n log n)
    if (L == R)
    {
		st[p] = A[L];
	}
    else {
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = p1 + p2;
  } }

  int rmq(int p, int L, int R, int i, int j) {                  // O(log n)
    if (i >  R || j <  L) return -1; // current segment outside query range
    if (L >= i && R <= j) return st[p];               // inside query range

     // compute the min position in the left and right part of the interval
    int p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);

    if (p1 == -1) return p2;   // if we try to access segment outside query
    if (p2 == -1) return p1;                               // same as above
    return p1 + p2; }          // as as in build routine

  int update(int p, int L, int R, int i, int j, int new_value) {
    if (i > R || j < L)
      return st[p];

    if (L == R) {
		if (new_value == 2)
		{
			A[L] = 1 - A[L];
		}
		else
		{
			A[L] = new_value;
		}
		return st[p] = A[L];
    }
    
    int p1, p2;
    p1 = update(left(p) , L              , (L + R) / 2, i, j, new_value);
    p2 = update(right(p), (L + R) / 2 + 1, R          , i, j, new_value);

    return st[p] = p1 + p2;
  }

public:
  SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size();              // copy content for local usage
    st.assign(4 * n, 0);            // create large enough vector of zeroes
    build(1, 0, n - 1);                                  // recursive build
  }

  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }   // overloading

  int update(int i, int j, int new_value) {
    return update(1, 0, n - 1, i, j, new_value); }
};

void answer_query(int ub, int lb, SegmentTree st, int c)
{
	cout << "Q" << c << ": " <<  st.rmq(ub, lb) << endl;
}

void solve()
{
	int pairs;
	int times;
	int upd_v;
	int q;
	char query;
	int lb, ub;
	string pirates;
	vi v_pirates;
	
	cin >> pairs;
	
	while (pairs--)
	{
		cin >> times >> pirates;
		
		while (times--)
		{
			for (int i = 0; i < (int)pirates.size(); i++)
			{
				v_pirates.push_back(pirates[i] - '0');
			}
		}
	}
	
	SegmentTree st(v_pirates);
	
	cin >> q;
	
	for (int c = 0; c < q; c++)
	{
		upd_v = -1;
		cin >> query >> lb >> ub;
		
		switch (query)
		{
			case 'F':
				upd_v = 1;
				break;
			case 'E':
				upd_v = 0;
				break;
			case 'I':
				upd_v = 2;
				break;
			case 'S':
				st = SegmentTree(v_pirates);
				answer_query(lb, ub, st, c);
				break;
		}
		
		if (upd_v >= 0)
		{
			//st.update(lb, ub, upd_v);
			for (int i = lb; i <= ub; i++)
			{
				v_pirates[i] = (upd_v == 2) ? 1 - v_pirates[i] : upd_v;
			}
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

    int t = 1;
    int c = 1;
    cin >> t;

    while (t--)
    {
		cout << "Case " << c << ":" << endl;
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
