#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
bool findTriplets(int arr[], int n);
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n]={0};
        for(int i=0;i<n;i++)
            cin>>arr[i];
        if(findTriplets(arr, n))
        cout<<"1"<<endl;
        else 
        cout<<"0"<<endl;
    }
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/

/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
bool findTriplets(int arr[], int n) { 
    //Your code here
    std::vector<int> pair_sum;
    std::vector<std::pair<int, int> > idx;
    for(size_t i=0; i<n; i++) {
        for(size_t j=0; j<n; j++) {
            if(i==j) continue;
            pair_sum.push_back(arr[i] + arr[j]);
            idx.push_back(std::pair<int, int>(i, j));
            std::cout << arr[i] + arr[j] << "  ";
        }
    }

    std::cout << std::endl << "Length of array is" << pair_sum.size() << std::endl;
    std::map<int, int> zeros_sum;
    
    for(size_t i=0;i<n; i++) {
        zeros_sum[-arr[i]] = i;
    }
    
    bool is_triplet=false;
    for(size_t i=0; i<pair_sum.size();i++) {
        try{
            int id= zeros_sum.at(pair_sum[i]);
            if (id== idx[i].first || id==idx[i].second) continue;
            return true;
        } catch(std::out_of_range& e) {
            is_triplet=false;
        }
    }

    return is_triplet;
}   

