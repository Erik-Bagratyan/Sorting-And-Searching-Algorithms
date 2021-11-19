#include <iostream>
#include <vector>

void Print(const std::vector<int>&);
void Merge(std::vector<int>&, int, int);
void Merge_Sort(std::vector<int>&, int, int);

int main()
{
    std::vector<int> myVec = { -24, 0, 14, -5, 1, 5, 1, 1, 2, 0, 17, 4, -6, 15};
    
    std::cout << "Unsorted Array : ";
    Print(myVec);
    std::cout << " Call Merge Sort" << std::endl;
    Merge_Sort(myVec,0,myVec.size() - 1);
    std::cout << "Sorted Array : ";
    Print(myVec);
    
    return 0;
}

void Print(const std::vector<int>& vec)
{
    for(auto elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void Merge(std::vector<int>& vec, int l, int r)
{
    std::vector<int> vec_merge;
    vec_merge.reserve(r - l + 1);
    
    int m = (l + r) / 2;
    int i = l, j = m + 1;
    
    while(i <= m && j <= r)
    {
        if(vec[i] <= vec[j])
            vec_merge.push_back(vec[i++]);
        else
            vec_merge.push_back(vec[j++]);
    }
    
    while(i <= m)
        vec_merge.push_back(vec[i++]);
        
    while(j <= r)
        vec_merge.push_back(vec[j++]);
        
    for(int i = l, j = 0; i <= r; ++i, ++j)
        vec[i] = vec_merge[j];
}

void Merge_Sort(std::vector<int>& vec, int left, int right)
{
    if(left >= right)
        return;
        
    int mid = (left + right) / 2;
    Merge_Sort(vec, left, mid);
    Merge_Sort(vec, mid + 1, right);
    Merge(vec,left,right);
}

