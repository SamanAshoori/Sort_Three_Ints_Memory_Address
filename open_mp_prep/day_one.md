# Intro to OpenMP Day One Prep

To prepare my C++ skills to get ready for HLRS Training - I am doing a 7 day bootcamp of key C++ concepts.

below is my day_one.cpp code and I will go over what I learnt

```C++
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
```

## Data Density
An Int is saved as 4 bytes which is why my array of 100 is 400 bytes which can be seen in the hexademical

## Spatial Locality
Arrays in C++ are stored in sequence (Modern CPU fetch typically 64 bytes at a time so 0 was computing costly but 15 wasnt)

## Pointer Math
ptrB - PtrA returns number of elements but typecasting char returns the number of bytes

## Direct Memory Access
used an address of a variable to do in place modification
