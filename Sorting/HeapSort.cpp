/*Heap Sort Algorithm for sorting in increasing order:
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of tree.
3. Repeat above steps until size of heap is greater than 1.
*/
/*Time complexity of heapify is O(Logn). Time complexity of createAndBuildHeap() is O(n) and overall time complexity of Heap Sort is O(nLogn).
*/


#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1; 
    int r = 2*i + 2; 
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[],int n){
	for(int i=n/2-1; i>=0; i--){
		heapify(arr,n,i);
	}

	for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
	int arr[] = {12,11,13,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	heapSort(arr,n);

	cout<<"The sorted array:\n";
	for(int i=0; i<n; i++){
		cout<<arr[i];
		cout<<"\n";
	}
}