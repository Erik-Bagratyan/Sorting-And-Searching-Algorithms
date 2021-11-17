#include <iostream>
#include <vector>

int find_min_elem_index(const std::vector<int>& vec)
{
	int min_elem_index = 0;
	for(int i = 1; i < vec.size(); ++i)
	{
		min_elem_index = (vec[min_elem_index] > vec[i]) ? i : min_elem_index;
	}
	
	return min_elem_index;
}

void Insertion_Sort_Iterative(std::vector<int>& vec)
{
	std::swap(vec[find_min_elem_index(vec)] , vec[0]);
    for(int i = 2; i < vec.size(); ++i)
    {
        int key = vec[i];
        int index = i - 1;
        while(key < vec[index])
        {
            vec[index + 1] = vec[index];
            --index;
        }
        vec[index + 1] = key;
    }
}

int main()
{
    std::vector<int> vec {3, 10, 24, -5, 0 ,12, 35, 1, 2, 3, -1, 10, -6, -14, 351, -235, -124, 0, 77, 19, 20, -13};
    for(auto elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    Insertion_Sort_Iterative(vec);
    
    for(auto elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}

