#include <iostream>
#include <vector>
#include <algorithm>

int Binary_Search_Recursive(const std::vector<int>& vec, int left, int right, int number)
{
    if(left > right)
        return -1;
        
    int mid = (left + right) / 2;
    if(vec[mid] == number)
    	return mid;
    
    if(vec[mid] < number)
        return Binary_Search_Recursive(vec,mid + 1, right,number);
    else 
        return Binary_Search_Recursive(vec,0, mid - 1,number);
}

void Print_Array(const std::vector<int>& vec)
{
    for(auto elem : vec)
        std::cout << elem << " ";
}

int main()
{
    std::vector<int> myVec = {10, 24, -14, -14, 0, 15, -35, 168, 14, 547, 24, -45, -24, 1, 0};
    std::cout << "Unsorted Array : ";
    Print_Array(myVec);
    
    std::cout << std::endl;
    
    std::sort(myVec.begin(), myVec.end());
    std::cout << "Sorted Array : ";
    Print_Array(myVec);
    
    std::cout << std::endl;
    int number = 14;
    std::cout << "Find " << number << " in myVec , Index of number : " << Binary_Search_Recursive(myVec, 0, myVec.size() - 1, number)
              << std::endl;
    
    return 0;
}
