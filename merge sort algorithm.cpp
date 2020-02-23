#include <iostream>
using namespace std;
void merge(int *,int, int , int );
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}
// Merge sort 
void merge(int *arr, int low, int high, int mid)
{
    int a, d, b, c[50];
    a = low;
    b = low;
    d = mid + 1;
    while (a <= mid && d <= high) {
        if (arr[a] < arr[d]) {
            c[b] = arr[a];
            b++;
            a++;
        }
        else  {
            c[b] = arr[d];
            b++;
            d++;
        }
    }
    while (a <= mid) {
        c[b] = arr[a];
        b++;
        a++;
    }
    while (d <= high) {
        c[b] = arr[d];
        b++;
        d++;
    }
    for (a = low; a < b; a++)  {
        arr[a] = c[a];
    }
}
// read input array and call mergesort
int main()
{
    int myarray[30], num;
    cout<<"Enter number of elements to be sorted:";
    cin>>num;
    cout<<"Enter "<<num<<" elements to be sorted:";
    for (int a = 0; a < num; a++) { cin>>myarray[a];
    }
    merge_sort(myarray, 0, num-1);
    cout<<"Sorted array\n";
    for (int a = 0; a < num; a++)
    {
        cout<<myarray[a]<<"\t";
    }
}
