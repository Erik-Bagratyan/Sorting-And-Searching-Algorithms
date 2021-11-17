#include <iostream>
#include <vector>

void Recursive_Insertion_Sort(std::vector<int>& vec, int size)
{
    if(size <= 1)
        return;
    
    Recursive_Insertion_Sort(vec, size - 1);
    
    int index = size - 1;
    int key = vec[index];
    while(index > 0 && key < vec[index - 1])
    {
        vec[index] = vec[index - 1];
        --index;
    }
    vec[index] = key;
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
