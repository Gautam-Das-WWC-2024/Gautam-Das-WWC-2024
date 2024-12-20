#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements in array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans;
    unordered_map<int,int>mpp;
    for(auto it: arr){
        if(mpp.find(it) == mpp.end()){
            ans.push_back(it);
            mpp[it]++;
        }
    }
    int k = ans.size();
    cout<<"After removing elements: ";
    for(auto it: ans){
        cout<< it <<" ";
    }
}