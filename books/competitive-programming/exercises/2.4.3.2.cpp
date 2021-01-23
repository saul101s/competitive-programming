#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

class SegmentTree {         // the segment tree is stored like a heap array
private: vi st, A;            // recall that vi is: typedef vector<int> vi;
  int n;
  int left (int p) { return p << 1; }     // same as binary heap operations
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {                           // O(n log n)
    if (L == R)                            // as L == R, either one is fine
      st[p] = A[L];                                         // store the index
    else {                                // recursively compute the values
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = p1 + p2;
  } }

  int rsq(int p, int L, int R, int i, int j) {                  // O(log n)
    if (i >  R || j <  L) return -1; // current segment outside query range
    if (L >= i && R <= j) return st[p];               // inside query range

     // compute the min position in the left and right part of the interval
    int p1 = rsq(left(p) , L              , (L+R) / 2, i, j);
    int p2 = rsq(right(p), (L+R) / 2 + 1, R          , i, j);

    if (p1 == -1) return p2;   // if we try to access segment outside query
    if (p2 == -1) return p1;   // same as above
    return p1 + p2;      // as as in build routine
  }

public:
  SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size();      // copy content for local usage
    st.assign(4 * n, 0);            // create large enough vector of zeroes
    build(1, 0, n - 1);             // recursive build
  }

  int rsq(int i, int j) { return rsq(1, 0, n - 1, i, j); }   // overloading
};
  
int main() {
  int arr[] = { 18, 17, 13, 19, 15, 11, 20 };         // the original array
  vi A(arr, arr + 7);                      // copy the contents to a vector
  SegmentTree st(A);

  printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
  printf("              A is {18,17,13,19,15, 11,20}\n");
  printf("RSQ(1, 3) = %d\n", st.rsq(1, 3));
  printf("RSQ(4, 6) = %d\n", st.rsq(4, 6));
  printf("RSQ(3, 4) = %d\n", st.rsq(3, 4));
  printf("RSQ(0, 0) = %d\n", st.rsq(0, 0));
  printf("RSQ(0, 1) = %d\n", st.rsq(0, 1));
  printf("RSQ(0, 6) = %d\n", st.rsq(0, 6));

  return 0;
}
