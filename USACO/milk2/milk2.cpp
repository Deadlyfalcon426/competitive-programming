/*
ID: ahsan.m1
TASK: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#define START 's'
#define END 'e'
using namespace std;
int main(){
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int n;
    fin >> n;
    int temp;
    vector<pair<int, char>> start_and_end_times;
    for(int i = 0; i<n;i++){
        fin >> temp;
        start_and_end_times.push_back(make_pair(temp, START));
        fin >> temp;
        start_and_end_times.push_back(make_pair(temp, END));
    } 
    //now we sort by times
    sort(start_and_end_times.begin(), start_and_end_times.end());
    //to address a test case where ppl start and end at the exact same time, and the tester thinks that since they do same time its continous
    for(int i = 0; i<start_and_end_times.size()-1;i++){
        if(start_and_end_times[i].first==start_and_end_times[i+1].first && start_and_end_times[i].second!=start_and_end_times[i+1].second){
            cout << "Kill me";
            start_and_end_times[i].second = START;
            start_and_end_times[i+1].second = END;
        }
    }
    int working_period_start = start_and_end_times[0].first;//first one has to be a start
    int working_period_end = 0;
    int working_period_current = 0;
    int bum_period_start = 0;
    int bum_period_end = 0;//last one has to close
    int bum_period_current = 0;
    int longest_working_period = 0;
    int longest_bum_period = 0;
    int farmers_working = 0;
    bool is_bum_period = false;
    bool is_working_period = true;
    for(auto time : start_and_end_times){

        if(time.second == START){
            farmers_working++;
            if(is_bum_period){
                bum_period_end=time.first;//set up the check if last bum period is greater
                bum_period_current=bum_period_end-bum_period_start;
                if(longest_bum_period<bum_period_current){
                    longest_bum_period=bum_period_current;
                }//finish check and update
                is_bum_period=false;//change to work period
                is_working_period=true;
                working_period_start=time.first;//almost forgot to set up new start
            }
            if(is_working_period){
                //nothing lowk happens besides just adding another farmer
            }
        }
        if(time.second == END){
            farmers_working--;
            if(is_bum_period){
                //well if no farmers are even working... how can farmers end?????
            }
            if(is_working_period){//if farmers are working, we need to check if we are ending the bum period
                if(farmers_working==0){
                    //switch to bum period... well lowk... we also need to check if we hit the end
                    //well does it matter if we hit the end... cause like we lose nothing by changing it to a bum state
                    //so we do the change and the check for longest
                    working_period_end=time.first;//set up the check if last work period is greater
                    working_period_current=working_period_end-working_period_start;
                    if(longest_working_period<working_period_current){
                        longest_working_period=working_period_current;
                    }//finish check and update
                    is_working_period=false;
                    is_bum_period=true;
                    bum_period_start=time.first;
                }else{
                    //just delete the farmer which we alr did up there
                }

            }
        }

    }
    //now that the for loop is ended... we are basically done!
    fout << longest_working_period << " " << longest_bum_period << "\n";
}
/*
Notes:
1 -> 300-1000
2 -> 700-1200
3 -> 1500-2100
given a bunch of farmers' start and end times, what are:
    longest time period where at least one cow was milked
    longest time period (after milking begins) that no cows are being milked
what if we iterated through and made notes of how many people were milking...
im thinking we iterate through time lowk, then we keep a running total of people milking BECAUSE...
IT DOESNT MATTER WHO IS MILKING. NO ONE CARES ABOUT THE EXACT FARMERS
YOOO THIS IS LOWK GOATED
*/