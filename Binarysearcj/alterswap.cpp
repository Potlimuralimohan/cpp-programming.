#include <iostream>

using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void swapAlternative(int arr[],int size){
    for (int i = 0; i < size; i+=2)
    {
        if(i+1 < size){// check the array limit
            swap(arr[i],arr[i+1]);
        }
    }
    
}
int main(){
    int even[8]={5,2,6,4,7,6,1,0};
    int odd[5]={11,33,9,76,43};

    swapAlternative(even,8);
    printArray(even,8);

    cout<<endl;
    swapAlternative(odd,5);
    printArray(odd,5);



    
    return 0;
}
