//first exercise of research arc 🥲✌️
#include <iostream>
#include <vector>
using namespace std;
int main(){
    //obvs one is like iterate through all subarray
    //btw subarray must be consecutive section
    //lets skip to two
    vector<int> arr = {-1, 2, 4, -3, 5, 2, -5, 2};
    int best = 0;
    //iterate through
    for (int a = 0; a < arr.size(); a++) {
        int sum = 0;
        //set b to where we at rn, then iterate through the rest of that 
        for (int b = a; b < arr.size(); b++) {
            sum += arr[b];
        best = max(best,sum);
        }
    }
    cout << best << "\n";
    //ok nvm 1st was somehow even worse, 2nd is like going through all items one by one
    //it's basically what i would do for a bad time solution

    //code 3, for each position, find max sum for something ending there
    //posibility one is the subarray is of one element 
    //other possiblity is that it ends at k-1, followed by k
    int best = 0, sum = 0;
    //iterate through
    //this is apparently called kadanes algorithm
    for (int k = 0; k < arr.size(); k++) {
        //which is bigger, the element at k or sum + k? 
        //(seems to be for negative numbers, which is fairs cause everything else would contribute)
        //is it better to restart on a new day or keep our past array?
        //this linear fashion may seem crude but actually works!
        //genuinely gamebreaking
        sum = max(arr[k],sum+arr[k]);
        //so here we see if the current sum of our array is bigger than the best
        //best serves as a save of our highest point
        best = max(best,sum);
    }
    cout << best << "\n";

    
}