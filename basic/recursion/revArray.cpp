/*
Given an array arr of n elements. The task is to reverse the given array.
The reversal of array should be inplace.
Constraints:
1 <= n <= 104
1 <= arr[i] <= 105

Sample Output:
Enter number of elements to enter : 6
Enter 6 elements : 45 2 4 5 8 6
Array Entered : 45 2 4 5 8 6 
Reversed array : 6 8 4 5 2 45
*/
#include<iostream>
//Try without seeing solution
int i=0;
void revarray(int arr[],int n){
    if(n<i)return;
    int temp=arr[n-1];//index 1 less than size
    arr[n-1]=arr[i];
    arr[i]=temp;
    i++;
    revarray(arr,n-1);
}
//function to print array
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        std::cout << arr[i] << ' ';
    }
}

int main(){
    int n;
    do{
        std::cout << "Enter number of elements to enter : ";
        std::cin >> n;
    }while(n<0);
    int arr[n];
    std::cout << "Enter " << n << " elements : ";
    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }
    std::cout << "Array Entered : " ;
    printarray(arr,n);
    std::cout << std::endl;
    std::cout << "Reversed array : ";
    revarray(arr,n);
    printarray(arr,n);
    std::cout << std::endl;
    return 0;
}