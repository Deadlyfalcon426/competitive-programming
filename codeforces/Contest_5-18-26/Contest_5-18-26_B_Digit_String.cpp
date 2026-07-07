//bismillah
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int testcases;
    vector<int> string_holder;
    int indexes_removed;
    string input_s;
    bool first_2_found;
    int first_2_index;
    int two_count;
    int odd_count;
    int first_twos;
    cin>>testcases;
    for(int tcase = 0; tcase<testcases;tcase++){
        string_holder.clear();
        indexes_removed=0;
        input_s.clear();
        first_2_found = false;
        first_2_index = -1;
        first_twos=0;
        cin >> input_s;
        //set up vector
        for (char c : input_s){
            string_holder.push_back(c-'0');
        }
        //search for the thing
        //slowly add to a counter of items needing to be removed
        //first delete all 4 since 4 is divisible.
        for(int index = 0;index<string_holder.size();index++){
            if(string_holder[index]==4){
                indexes_removed++;
            }
        }
        //search for last occurence of 2
        for(int index = (int)string_holder.size()-1;index>=0;index--){
            if(string_holder[index]==2){
                first_2_index=index;
                break;
            }
        }
        //first occurence of 2 as for 21112, the first 2 is useless as it cannot become 12 or 32
        for (int index = 0; index<string_holder.size();index++){
            if(string_holder[index]==2){
                first_twos++;
            } else{
                break;
            }
        }
        //if last 2 found, then compare: better to delete all 2 or to delete all 1,3 after the 2???
        if(first_2_index!=-1){
            two_count=count(string_holder.begin(),string_holder.begin()+first_2_index, 2)+1-first_twos;
            odd_count=count(string_holder.begin(),string_holder.begin()+first_2_index, 1)+count(string_holder.begin(),string_holder.begin()+first_2_index, 3);

            indexes_removed+=min(two_count,odd_count);
        }
        //print
        cout<<"\n"<<indexes_removed<<"\n";
    }
}