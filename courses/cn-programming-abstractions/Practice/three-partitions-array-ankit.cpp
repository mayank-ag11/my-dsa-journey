// Qs: https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
// https://www.geeksforgeeks.org/three-way-partitioning-of-an-array-around-a-given-range/

void threeWayPartition(vector<int>& arr, int a, int b)
{
    int low=0,hi=arr.size()-1;
    for(int i=0;i<=hi;i++)
    {
        if(arr[i]<a)
        {
            swap(arr[i],arr[low]);
            low++;
        }
        else if(arr[i]>b)
        {
            swap(arr[i],arr[hi]);
            hi--; i--;
        }
    }
    // code here
}