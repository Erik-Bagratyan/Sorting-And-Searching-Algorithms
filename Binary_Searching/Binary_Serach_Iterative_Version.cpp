#include <iostream>
#include <vector>
#include <algorithm>

int Binary_Search_Iterative(const std::vector<int>& vec, int number)
{
    int left = 0;
    int right = vec.size() - 1;
    
    while(left <= right)
    {
        int mid = (left + right) / 2;
        
        if(vec[mid] == number)
            return mid;
        else if (vec[mid] < number)
        {
            left = mid + 1;
        }
        else 
            right = mid - 1;
    }
    
    return -1;
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
    std::cout << "Find " << number << " in myVec , Index of number : " << Binary_Search_Iterative(myVec, number)
              << std::endl;
    
    return 0;
}
