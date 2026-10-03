/***
 * The fictional World Championship of Formula 7 Drivers 2019 was characterized by exciting races and frequent shifts of driver positions on the leaderboard. Pradeep has missed most of it because he was training for olympiads in informatics. Now, looking at the leaderboard, Pradeep has a simple question for you: "How many drivers participating in this Championship still had a chance to become Formula 7 World Champion at the start of the final race?” The World Champion is, of course, the driver with the largest point total at the end (after the final race).
 * There are N drivers participating in the Championship. They are all assigned points after each race, including the final one. The winner of the race is awarded N points, the runner-up gets N - 1 points, and so on until the last driver, who gets 1 point. Two drivers cannot finish a race in the same spot.
 * Write a program to calculate, based on the total number of points that each driver has earned before the final race, how many drivers still have a chance to have the largest total after the final race and thus win the Championship. If more than one driver has the same maximum point total, they are all awarded the World Champion title.
 * 
 * Sample Test Cases:
 * n = 3, {8, 10, 9} => 3
 * n = 5, {15, 14, 15, 12, 14} => 4
 ***/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n, greater<int>());
    int ctr = 0, points = 0;
    
    for(int i=0; i<n; i++) {
        ctr += (arr[i] + n >= points);
        points = max(points, arr[i] + i + 1);
    }

    cout << ctr;
}