#include <iostream>

void doubleValue(int* input);


void doubleValue(int* input){
    *input *= 2;
}



int main(){
    int arr[100];

    for(int i = 0; i < 100;i++){
        arr[i] = i;
        std::cout << arr[i] << "lives at this address" <<  &arr[i] <<std::endl;
    }
    std::cout << "Value of arr[16] is: " << arr[16] << std::endl;
    doubleValue(&arr[16]);
    
    std::cout << "Distance in bytes: " << ((char*)&arr[13] - (char*)&arr[0]) << std::endl;
    std::cout << "Position arr[16] is now: " << arr[16] << std::endl;

    return 0;
}

//So ints are stored as 4 bytes
//52 Bytes = 4 x 13
