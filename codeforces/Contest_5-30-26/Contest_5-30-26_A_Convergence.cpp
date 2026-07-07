#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
int main(){
    //input
    int testcases;
    cin >> testcases;
    for (int tcase = 0; tcase<testcases; tcase++){
        //putting the variable declarations inside the for loop for the first time, shouldnt cause too much trouble
        map<int, int> frequency;
        vector<long long> values;
        int n;
        cin >> n;
        //now we fill array and make a hash map of frequency i think? idk im cooking up some bullshit
        for(int idx = 0; idx<n;idx++){
            int temp;
            cin >> temp;
            values.push_back(temp);
            frequency[values[idx]] += 1;

        }
        //find the mode of dataset by iterating over hash map?

        // Initialize with a dummy value or the first element's data

        //never mind! we want median not mode. should just be a sort and divide then ig
        //odd length median easy
        //even length median is between 2, and we would want the one thats closer to the mode!
        //we got our beautiful weighting thing in the end!
        int largest_value = -1; 
        int max_frequency = -1; 
        sort(values.begin(), values.end());
        if(values.size()%2==1){
            largest_value = values[(values.size()-1)/2];
        } else{
            if(frequency[values[(values.size())/2]]>frequency[values[((values.size())/2)-1]]){
                largest_value=values[(values.size())/2];
            } else{
                largest_value=values[((values.size())/2)-1];
            }
        }


        //ok we want everyone to gravitate towards the mode
        //we can do this by just checking how many are not the mode and then dividing by 2 and rounding up
        //not that simple actually we will iterate over table and look for pairs maybe?
        int guys_to_change_counter = 0;
        int smaller = 0;
        int bigger = 0;
        for(const auto& value : values){
            if(value<largest_value){
                smaller++;
            } else if(value>largest_value){
                bigger++;
            }
        }

        if(smaller>bigger){
            guys_to_change_counter+=smaller;
        } else{
            guys_to_change_counter+=bigger;
        }
        
        cout<<guys_to_change_counter<<"\n";

    }
}