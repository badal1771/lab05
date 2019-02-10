#include <iostream>
using namespace std;
void swap(int *a,int *b)
{
    int x=*a;
    *a=*b;
    *b=x;
}
int partit(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i,j;
    i=low;
    j=low;
    while(j<=high-1)
    {
        if(arr[j]<arr[high])
        {
            swap(arr[i],arr[j]);
            j++;
            i++;
        }
        else
            j++;
    }
    swap(arr[i],arr[high]);
    return i;
}

void QS(int arr[],int low,int high)
{
    if(high>low)
    {
        int p=partit(arr,low,high);
        QS(arr,low,p-1);
        QS(arr,p+1,high);
    }
    else
        return;
}

int main()
{
    int arr[100],n;
    cout<<"Enter the no of elements to be added ";
    cin>>n;

        cout<<"Enter numbers of your desire "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    QS(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
