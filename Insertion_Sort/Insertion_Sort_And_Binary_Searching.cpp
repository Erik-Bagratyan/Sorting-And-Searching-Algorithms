#include <iostream>
#include <vector>

int Binary_Search_Recursive(const std::vector<int>&,int, int, int);

void Recursive_Insertion_Sort(std::vector<int>& vec, int size)
{
    if(size <= 1)
        return;
    
    Recursive_Insertion_Sort(vec, size - 1);
    
    int index = Binary_Search_Recursive(vec,0,size - 2,vec[size-1]);
    int key = vec[size - 1];
    for(int i = size - 1; i > index; --i)
    {
        vec[i] = vec[i - 1];
    }
    vec[index] = key;
}


int Binary_Search_Recursive(const std::vector<int>& vec, int left, int right, int number)
{
    if(left > right)
        return left;
        
    int mid = (left + right) / 2;
    if(vec[mid] == number)
    	return mid + 1;
    
    if(vec[mid] < number)
        return Binary_Search_Recursive(vec,mid + 1, right,number);
    else 
        return Binary_Search_Recursive(vec,left, mid - 1,number);
}

int main()
{
    std::vector<int> vec {3, 10, 24, -5, 0 ,12, 35, 1, 2, 3, -1, 10, -6, -14, 351, -235, -124, 0, 77, 19, 20, -13};
    std::cout << "Unsorted Array : ";
    for(auto elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    Recursive_Insertion_Sort(vec, vec.size());
 	
 	std::cout << "Sorted Array : ";   
    for(auto elem : vec)
    {
        std::cout << elem << " ";
              
    }
    std::cout << std::endl;
    return 0;
}
