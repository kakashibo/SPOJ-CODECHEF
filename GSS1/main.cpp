#include <iostream>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
using namespace std;
// implementation https://kartikkukreja.wordpress.com/2014/11/09/a-simple-approach-to-segment-trees/
struct SegmentTreeNode {
	int prefixMaxSum, suffixMaxSum, maxSum, sum;

	void assignLeaf(int value) {
		prefixMaxSum = suffixMaxSum = maxSum = sum = value;
	}

	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		sum = left.sum + right.sum;
		prefixMaxSum = max(left.prefixMaxSum, left.sum + right.prefixMaxSum);
		suffixMaxSum = max(right.suffixMaxSum, right.sum + left.suffixMaxSum);
		maxSum = max(prefixMaxSum, max(suffixMaxSum, max(left.maxSum, max(right.maxSum, left.suffixMaxSum + right.prefixMaxSum))));
	}

	int getValue() {
		return maxSum;
	}
};

template<class T, class V>
class SegmentTree {

	SegmentTreeNode* nodes;
	int N;

public:
	SegmentTree(T arr[], int N) {
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr, 1, 0, N-1);
	}

	~SegmentTree() {
		delete[] nodes;
	}

	V getValue(int lo, int hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}

	void update(int index, T value) {
		update(1, 0, N-1, index, value);
	}
	void printstree(){
	    int size=getSegmentTreeSize(N);
	    for(int i=1;i<=size;i++)
            cout<<nodes[i].getValue()<<" ";
        cout<<endl;
	}

public:
	void buildTree(T arr[], int stIndex, int lo, int hi) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}

		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}

	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
		if (left == lo && right == hi)
			return nodes[stIndex];

		int mid = (left + right) / 2;
		if (lo > mid)
			return getValue(2*stIndex+1, mid+1, right, lo, hi);
		if (hi <= mid)
			return getValue(2*stIndex, left, mid, lo, hi);

		SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
		SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
		SegmentTreeNode result;
		result.merge(leftResult, rightResult);
		return result;
	}

	int getSegmentTreeSize(int N) {
		int size = 1;
		for (; size < N; size <<= 1);
		return size << 1;
	}

	void update(int stIndex, int lo, int hi, int index, T value) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(value);
			return;
		}

		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		if (index <= mid)
			update(left, lo, mid, index, value);
		else
			update(right, mid+1, hi, index, value);

		nodes[stIndex].merge(nodes[left], nodes[right]);
	}

};


int main()
{
    //cout << "Hello world!" << endl;
    int ar[50000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",&ar[i]);
    SegmentTree<int,int> st(ar, n);
    //struct SegmentTreeNode *tree = constructST(ar, n);
    //build_tree(1, 1, n);
    //50010
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1;
    //st.printstree();
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",st.getValue(x-1, y-1));
        //cout<<RMQ(tree,n,x-1,y-1)<<endl;

    }
    return 0;
}
