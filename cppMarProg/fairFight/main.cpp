#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

class SegmentTree { // the segment tree is stored like a heap array
private: vi st, A; // recall that vi is: typedef vector<int> vi;
    int n;
    int left (int p) { return p << 1; } // same as binary heap operations
    int right(int p) { return (p << 1) + 1; }
    void build(int p, int L, int R) { // O(n)
    if (L == R) // as L == R, either one is fine
        st[p] = L; // store the index
    else { // recursively compute the values
    build(left(p) , L , (L + R) / 2);
    build(right(p), (L + R) / 2 + 1, R );
    int p1 = st[left(p)], p2 = st[right(p)];
    st[p] = (A[p1] <= A[p2]) ? p2 : p1;
    } }
    int rmq(int p, int L, int R, int i, int j) { // O(log n)
    if (i > R || j < L) return -1; // current segment outside query range
    if (L >= i && R <= j) return st[p]; // inside query range
    // compute the min position in the left and right part of the interval
    int p1 = rmq(left(p) , L , (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);
    if (p1 == -1) return p2; // if we try to access segment outside query
    if (p2 == -1) return p1; // same as above
    return (A[p1] <= A[p2]) ? p2 : p1; // as in build routine
    }

    public:
    SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size(); // copy content for local usage
    st.assign(4 * n, 0); // create large enough vector of zeroes
    build(1, 0, n - 1); // recursive build
    }
    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); } // overloading
    };

int main()
{
    int T,N,K;
    cin >> T;
    for (int t=0;t<T;t++){
        cin >> N >> K;
        int arr1[N],arr2[N];
        for (int i=0;i<N;i++)cin >>arr1[i];
        for (int i=0;i<N;i++)cin >>arr2[i];
        vi A1(arr1,arr1+N);
        vi A2(arr2,arr2+N);
        SegmentTree st1(A1);
        SegmentTree st2(A2);
        int counter=0;
        for (int L=0;L<N;L++){
            for (int R=L;R<N;R++){
                if(abs(arr1[st1.rmq(L,R)]-arr2[st2.rmq(L,R)])<=K)counter++;
            }
        }
        cout << "Case #" << t+1 << ": "<< counter << endl;
    }
    return 0;
}
