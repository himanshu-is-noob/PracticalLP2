#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

void SelectionSort(vector<int>&nums){
    int n = nums.size() ; 

    for(int i=0 ; i<n-1 ; i++){
        int minIndex = i ; 
        for(int j=i+1 ; j<n ; j++){
            if(nums[j] < nums[minIndex]){
                minIndex = j ;
            }
        }
        swap(nums[minIndex] , nums[i]) ;
    }

    cout << "Sorted Array is as follows " << endl ;
    for(int i=0 ; i<n ;i++){
        cout << nums[i] << " " ;
    }
}

int main()
{
    int n ;
    cout << "How many numbers ? " ;
    cin >> n ; 

    vector<int>nums ;

    for(int i=0 ; i<n ; i++){
        int x ;
        cout << "Enter number : " ;
        cin >> x ; 
        
        nums.push_back(x) ;
    }

    SelectionSort(nums) ;
}