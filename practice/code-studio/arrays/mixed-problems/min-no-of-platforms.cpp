/***
 * You have been given two arrays, 'AT' and 'DT', representing the arrival and departure times of all trains that reach a railway station.
 * Your task is to find the minimum number of platforms required for the railway station so that no train needs to wait.
 * Note :
    1. Every train will depart on the same day and the departure time will always be greater than the arrival time. For example, A train with arrival time 2240 and departure time 1930 is not possible.

    2. Time will be given in 24H format and colons will be omitted for convenience. For example, 9:05AM will be given as "905", or 9:10PM will be given as "2110".

    3. Also, there will be no leading zeroes in the given times. For example, 12:10AM will be given as “10” and not as “0010”.
    
 * Try to solve the problem in O(N) time and O(1) space.
 * Link: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381892
 ***/
/*
    Time Complexity : O(N)
    Space Complexity :  O(1)

    Where 'N' is the number of trains.
*/
int calculateMinPatforms(int at[], int dt[], int n){
    // Array to store the number of platforms required at different points of time.
    int platforms[2361] = {0};

    // Variable to store the final answer i.e. minimum number of platforms required.
    int minNumOfPlatforms = 1;

    for (int i = 0; i < n; i++) {
        // Increment the count of platforms at the time of arrival.
        ++platforms[at[i]];

        // Decrease the platform count just after the departure.
        --platforms[dt[i] + 1];
    }

    // We are running loop till 2361 because maximum time value in a day can be 23:60.
    for (int i = 1; i < 2361; i++) {
        // Taking cumulative sum of platforms.
        platforms[i] = platforms[i] + platforms[i - 1];

        // Update minNumOfPlatforms.
        minNumOfPlatforms = max(minNumOfPlatforms, platforms[i]);
    }

    // Return the minimum number of platforms.
    return minNumOfPlatforms;
}

// Using Sorting: O(nlogn)
#include<algorithm>
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);
    
    int i=0, j=0;
    int ctr = 0, platforms = 0;
    while(i < n && j < n) {
        if(at[i] <= dt[j]) {
            i++;
            ctr++;
        }
        else {
            ctr--;
            j++;
        }
        if(ctr > platforms)
            platforms = ctr;
    }
    return platforms;
}