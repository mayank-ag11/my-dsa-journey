void merge(int *arr1, int n1, int *arr2, int n2, int *ans)
{
    int i, j, k;
    i = j = k = 0;
    
    while(i < n1 && j < n2) {
        if(arr1[i] <= arr2[j])
            ans[k++] = arr1[i++];
        else
            ans[k++] = arr2[j++];
    }
    
    while(i < n1) {
        ans[k++] = arr1[i++];
    }
    
    while(j < n2) {
        ans[k++] = arr2[j++];
    }
}