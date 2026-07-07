/*
<my first big C++ program!
im really happy with how it turned out even though i needed help from claude after
I encountered my first time complexity issue, a TLE limit
I hope to improve from here greatly!
3/20/2026
genuinely its eid today lmao
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> reorganize_v2(vector<int> perm){
    /*ok chaaaaat
    this is the suggested algorithm after the previous failed to meet time limit
    it worked
    but it failed
    basically the previous used like for all the numbers
    then after it it iterated through all the numbers after the outer loop number
    looking for a possible swap
    this led to the time complexity of O(N^2) which was lowk bad
    soooo now we are adjusting it
    Heres the gist of the new one:
    find the maximums of each substring type thing beforehand
    in a seperate loop iterate over it to see if they work
    was that aura?
    */

    /*this vector carries the maximums for each sub-vector from the right. 
    however, its indexes are still in the correct order. 
    for example, the first index is the smallest sub-vector of length one
    */
    vector<int> maximums_by_index(perm.size());
    //biggest in the set so far
    int biggest_so_far = perm[perm.size()-1];
    maximums_by_index[perm.size()-1] = biggest_so_far;
    /* this little for loop of O(N) is going to find the 
    maximums of subvectors*/
    for (int item = perm.size()-1; item>=0; --item) {
        if (biggest_so_far<perm[item]){
            biggest_so_far = perm[item];
        }
        maximums_by_index[item] = biggest_so_far;
    }
    //starting index for reversal segment
    int best_number = 0;
    //ending index for reversal statement
    int best_switch_number = 0;
    /*now here we compare the max thingies with the rest of the array thing to find where 
    we want to put our reversal based on the maximums we now know.
    this one cycles through the thing from the front and compares the maximums, and ends up
    saving the starting index, however it has to save the ending index as a value because it 
    doesn't know if thats the rightmost (big brain ik ik)
    time complexity O(N)*/
    for (int item = 0; item<perm.size(); ++item){
        if (maximums_by_index[item]>perm[item]){
            best_number = item;
            best_switch_number = maximums_by_index[item];
            break;
        }
    }
    /*so last time we got the value of ending index here we are syncing best possible index 
    with the value. 
    sadly this is O(N) too i think... hopefully O(3N) isnt too much*/
    
    for (int item = perm.size()-1; item>=0; --item){
        if (perm[item] == best_switch_number){
            best_switch_number = item;
            break;
        }
    }
    //ACTUAL PHYSICAL SWITCHING PART FROM LAST FUNCTION
    //new perm for simplicity
    vector<int> new_perm = perm;

    //doing the switching
    int counter_up = best_number;
    for (int counter_down = (best_switch_number);counter_down>=best_number;--counter_down){
        new_perm[counter_up] = perm[counter_down];
        ++counter_up;
    }
    //return outcome
    return new_perm;
}


int main(){
    int test_cases_count;
    cin >> test_cases_count;
    int temp;
    vector<int> lengths_of_perms(test_cases_count);
    /*this is a two dimensional array which holds
     the different permutations read in*/
    vector<vector<int>> perms(test_cases_count, vector<int>());
    //getting the inputs...
    for (int test_case_counter = 0; test_case_counter<test_cases_count; ++test_case_counter){
        cin >> lengths_of_perms[test_case_counter];
        int length = lengths_of_perms[test_case_counter];
        for (int i = 0; i<length; ++i){
            cin >> temp;
            perms[test_case_counter].push_back(temp);
        }
    }
    //reorganizing the perms:
    for (int test_case_counter = 0; test_case_counter<test_cases_count; ++test_case_counter){
        perms[test_case_counter] = reorganize_v2(perms[test_case_counter]);
    }

    //printing the results...
    for (int test_case_counter = 0; test_case_counter<test_cases_count; ++test_case_counter){
        for (int i = 0; i<perms[test_case_counter].size(); ++i){
            cout<<perms[test_case_counter][i]<<" ";
        }
        cout<<"\n";
    }
}