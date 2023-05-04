#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int left=2*root+1;
   int right=2*root+2;
   int largest=root;
   
   if (left<n && arr[left]>arr[largest]){
      largest=left;
   }
   if (right<n && arr[right]>arr[largest]){
      largest=right;
   }
   if (largest != root){
      int temp=arr[root];
      arr[root]=arr[largest];
      arr[largest]=temp;
      heapify(arr,n,largest);
   } 
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i=n/2+1;i>=0;i--){
      heapify(arr,n,i);
   }
   // extracting elements from heap one by one
   for(int i=n-1;i>0;i--){
      int temp2=arr[i];
      arr[i]=arr[0];
      arr[0]=temp2;

      heapify(arr, i, 0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int arr_size;
   cout<<"Enter the size of the array :";
   cin>>arr_size;

   int heap_arr[arr_size];

   cout<<"Input array"<<endl;
   for(int i=0;i<arr_size;i++){
      cin>>heap_arr[i];
   }
  
   heapSort(heap_arr, arr_size);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, arr_size);
}