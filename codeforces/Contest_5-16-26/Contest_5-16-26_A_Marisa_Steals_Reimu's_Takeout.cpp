/*
https://codeforces.com/contest/2228/problem/A
Find sub-arrays that %3=0 and then remove them? so maybe iterate over keeping a counter, if counter<

in the end, this was like my first bad contest, which is just a jumping point to improve!
it went bad because I spent a lot of time not understanding subarray vs subsequence, didnt think through all the edge cases, and made silly mistakes (% versus minus, line 45 and 49)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int testcases;
    int length;
    int startIndex;
    int endIndex;
    int sum = 0;
    int subarray_counter;
    cin >> testcases;
    vector<int> sequence;
    vector<vector<int>> tagged_index_ranges;
    for(int tcase = 0; tcase<testcases;tcase++){
        sequence.clear();
        tagged_index_ranges.clear();
        cin >> length;
        sequence.resize(length);
        //fill array
        for (auto& element : sequence) {
            cin >> element;
        }
        startIndex = 0;
        sum = 0;
        endIndex = 0;
        subarray_counter = 0;
        //begin operations
        //find and catalog all zeroes
        subarray_counter += count(sequence.begin(), sequence.end(), 0);
        //find and catalog all 1 and 2, look for combos first
        int count1 = count(sequence.begin(), sequence.end(), 1);
        int count2 = count(sequence.begin(), sequence.end(), 2);
        if (count1>count2 && count2!=0){
            subarray_counter+=count2;
            count1-=count2;
            subarray_counter += count1/3;
        } else if(count2>count1 && count1!=0){
            subarray_counter+=count1;
            count2-=count1;
            subarray_counter += count2/3;
        } else if (count1 == count2){
            subarray_counter+=count2;
        } else if (count1>count2){
            subarray_counter += count1/3;
        } else if (count2>count1){
            subarray_counter += count2/3;
        }
        cout<<subarray_counter<<"\n";
    }
}