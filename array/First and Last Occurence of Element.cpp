#include <iostream>
using namespace std;
int FirstOccurence(int arr[],int n, int key){
    int start=0;
    int end=n-1;
    int mid = start+(end-start)/2;
    int ans=-1;
    while(start<=end){
        if(key==arr[mid]){
            ans=mid;
            end=mid-1;
        }
        else if (key>arr[mid])
        start=mid+1;
        else if(key<arr[mid])
        end=mid-1;

        mid=start+(end-start)/2;
    }
    return ans;
}

int LastOccurence(int arr[],int n, int key){
    int start=0;
    int end=n-1;
    int mid = start+(end-start)/2;
    int ans=-1;
    while(start<=end){
        if(key==arr[mid]){
            ans=mid;
            start=mid+1;
        }
        else if (key>arr[mid])
        start=mid+1;
        else if(key<arr[mid])
        end=mid-1;

        mid=start+(end-start)/2;
    }
    return ans;
}

int main(){
    int n=7;
    int arr[7]={1,2,3,3,3,3,5};
    int key=3;
    cout<<"Fisrt Occurence of 3 is at index "<<FirstOccurence(arr,n,key)<<endl;
    cout<<"Last Occurence of 3 is at index "<<LastOccurence(arr,n,key);

    return 0;
}