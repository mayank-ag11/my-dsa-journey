// Dutch National Flag Algo
void pushZeroesEnd(int *input, int n)
{
    int low = 0, mid = 0;
    while(mid < n) {
        if(input[mid] != 0) {
            swap(input[mid], input[low]);
            // int t = input[mid];
            // input[mid] = input[low];
            // input[low] = t;
            
            low++;
            mid++;
        }
        else   // input[mid] == 1
            mid++;
    }
}