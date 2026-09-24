/*
TD: ahsan.m1
TASK: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int annoying_part(vector<pair<int, bool>>& state_tracking, int boards_to_remove);
int main(){
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    //input section
    int max_boards, total_stalls, amount_of_occupied_stalls;
    fin >> max_boards >> total_stalls >> amount_of_occupied_stalls;
    vector<bool> contains_cow(total_stalls, false);
    //DAAAAAMN THE BELOW ABSTRACTION SAVED OUR LUCKY AHH CAUSE FIRST STALL IS ONE NOT ZERO!!!!
    for(int i = 0; i<amount_of_occupied_stalls;i++){
        int temp;
        fin >> temp;
        contains_cow[temp-1] = true;
    }
    fin.close();
    //input complete
    //hold sections of cows or no cows
    vector<pair<int, bool>> state_tracking;
    bool current_state = contains_cow[0];
    state_tracking.push_back(make_pair(0, current_state));
    for(bool current_stall : contains_cow){
        if(current_stall==current_state){
            state_tracking[state_tracking.size()-1].first++;
        }else{
            current_state=current_stall;
            state_tracking.push_back(make_pair(1, current_state));
        }
    }
    contains_cow.clear();
    //ok the naive section is complete
    //now for the realism adjustment
    //up to this point works correctly assuming i havent changed it
    int naive_board_counter = 0;
    int amount_of_stalls_covered = 0;
    for(auto& lebron : state_tracking){
        if(lebron.second){
            naive_board_counter++;
            amount_of_stalls_covered+=lebron.first;
        }
    }
    if(naive_board_counter>max_boards){
        int boards_to_remove = naive_board_counter-max_boards;
        fout << annoying_part(state_tracking, boards_to_remove) << "\n";
        return 0;
    }else{
        fout << amount_of_stalls_covered << "\n";
        return 0;
    }
}
int annoying_part(vector<pair<int, bool>>& state_tracking, int boards_to_remove){
    //begin the hard type stuff
    vector<pair<int, int>> no_cow_amount_and_idx;
    for(int i = 1; i<state_tracking.size()-1;i++){//doesnt benefit to take first or last! and this one doesnt care for cow holders!!!
        if(state_tracking[i].second==false){
            no_cow_amount_and_idx.push_back(make_pair(state_tracking[i].first, i));
        }
    }
    sort(no_cow_amount_and_idx.begin(), no_cow_amount_and_idx.end());
    int counter = 0;
    int possible_this_rotation = true;
    while(boards_to_remove>0){
        if(counter>=no_cow_amount_and_idx.size()){
            possible_this_rotation=false;
        }else{
            //thought that 0 and last would be only one board but its always only one board leaving.
            //Great news! im sad i couldnt catch it earlier
            state_tracking[no_cow_amount_and_idx[counter].second].second=true;
            boards_to_remove--;

        }
        counter++;
    }
    if(boards_to_remove<0){
        //maaaan that would really suck wouldnt it
        //nope proven impossible
    }
    
    if(possible_this_rotation){
        int amount_of_stalls_covered = 0;
        for(auto& lebron : state_tracking){
            if(lebron.second){
             amount_of_stalls_covered+=lebron.first;
            }
        }
        return amount_of_stalls_covered;
    } else{
        return annoying_part(state_tracking, boards_to_remove);
    }
}
/*
    Gameplan: 
        step 1: obvious
            we pass through, flag our consectuive stalls
        step 2: less obvious
            2 parameters exist:
                hard parameter(unavoidable)-> M boards
                soft parameter(just would be nice to have, secondary) -> MINIMIZE stalls covered
            we are currently bypassing hard parameter
            we are maximizing soft parameter.
            now we adjust in the minimum way the hard parameter
            we do this choosing stall gaps with the smallest difference between to cover up, effectively minimizing extra stalls covered
*/