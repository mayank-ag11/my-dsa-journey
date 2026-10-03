/***
 * Discussed in class (Webinar 9)
 * https://leetcode.com/contest/weekly-contest-252/problems/maximum-number-of-weeks-for-which-you-can-work/
 ***/
class Solution {
private:
    int index_max_in_vector(vector<int>& milestones) {
        int n = milestones.size();
        int max_i = 0;
        for(int i=1; i<n; i++) {
            if(milestones[i] > milestones[max_i])
                max_i = i;
        }
        return max_i;
    }
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int n = milestones.size();
        int max_i = index_max_in_vector(milestones);
        long long max = milestones[max_i];
        
        long long rest_sum = 0;
        milestones[max_i] = 0;
        for(int i=0; i<n; i++)
            rest_sum += milestones[i];
        
        if(max > rest_sum)
            return (2*rest_sum + 1);
        else
            return rest_sum + max;
    }
};