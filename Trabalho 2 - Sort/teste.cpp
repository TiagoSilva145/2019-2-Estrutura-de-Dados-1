#include <iostream>

using namespace std;

void CopyArray(int A[], int iBegin, int iEnd, int B[])
{
    int k;

    for(k = iBegin; k < iEnd; k++)
        B[k] = A[k];
}

void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
    int i = iBegin, j = iMiddle, k;

    // While there are elements in the left or right runs...
    for (k = iBegin; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
        }
    }
}

void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
    int iMiddle;

    if(iEnd - iBegin < 2)                       // if run size == 1
        return;                                 //   consider it sorted
    // split the run longer than 1 item into halves
    iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
    // recursively sort both runs from array A[] into B[]
    TopDownSplitMerge(A, iBegin,  iMiddle, B);  // sort the left  run
    TopDownSplitMerge(A, iMiddle,    iEnd, B);  // sort the right run
    // merge the resulting runs from array B[] into A[]
    TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

void TopDownMergeSort(int A[], int B[], int n)
{
    CopyArray(A, 0, n, B);           // duplicate array A[] into B[]
    TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
}

int main()
{
    int v[10] = {1,15,2,10,3,50,6,4,5,27};
    int u[10];

    TopDownMergeSort(v,u,10);

    for(int i = 0; i < 10; i++)
        cout << v[i] << " ";
}
