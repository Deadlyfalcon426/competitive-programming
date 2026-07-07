#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long combat(vector<long long> monster_powers, long long combat_power, long long flip_flops){
    //copying in the old logic for easy access
    /*
    for each monster in the lane, check if it can be killed. 
    if yes, 
        add as many flip flops as possible to make it same level. then kill it and go to next monster
    if no,
        wrap it up lil bro because they are sorted there's no way to beat him
    */
   int flip_flops_to_throw;
   //for each monster
    for (long long monster_power : monster_powers){
        flip_flops_to_throw = 0;

        if (combat_power==monster_power){
            //if player is equal:

            //defeat monster
            combat_power = combat_power+monster_power;
        } else if(combat_power>monster_power){
            //if the player is already greater 

            //if we have flip_flops to throw
            if (flip_flops>0){
                //now we need to check how many flip flops to throw
                //as many as possible, bounded by how many we have and our current combat level
                //if level gap is too wide to cover with flip flops
                if (combat_power-monster_power >= flip_flops){
                    flip_flops_to_throw = flip_flops;
                    flip_flops = flip_flops-flip_flops_to_throw;
                    monster_power = monster_power+flip_flops_to_throw;
                }
                //if level gap can be covered with flip flops
                if (combat_power-monster_power < flip_flops){
                    flip_flops_to_throw = combat_power-monster_power;
                    flip_flops = flip_flops-flip_flops_to_throw;
                    monster_power = monster_power+flip_flops_to_throw;
                }
                //defeat monster
                combat_power = combat_power+monster_power;
            }
            //if we dont have any flip flops
            else{
                //defeat monster
                combat_power = combat_power+monster_power;
            }
        } else if(combat_power<monster_power){
            //if the player is not greater, run
            return combat_power;
        }
    }
    return combat_power;
    }


int main(){
    //reading in

    int test_cases;
    vector<int> monster_numbers;
    vector<long long> combat_power;
    vector<long long> flip_flops;
    int temp;
    vector<vector<long long>> monster_combat_powers_ALL_CASES;
    cin >> test_cases;
    for (int test_case = 0; test_case<test_cases; ++test_case){
        cin >> temp;
        monster_numbers.push_back(temp);
        cin >> temp;
        combat_power.push_back(temp);
        cin >> temp;
        flip_flops.push_back(temp);
        monster_combat_powers_ALL_CASES.resize(test_cases);
        for (int monster_counter = 0; monster_counter<monster_numbers[test_case]; ++monster_counter){
            cin >> temp;
            monster_combat_powers_ALL_CASES[test_case].push_back(temp);
        }
    }
    //completed reading in
    //beginning actual job
    /*our ideal algorithm would be using all the flip flops every single time to maximize
    the amount of same-level monsters, then take them out
    OK WAIT I GOT IT
    SORT ALL THE MONSTER LISTS!!!
    smallest to greatest
    for each monster in the lane, check if it can be killed. 
    if yes, 
        add as many flip flops as possible to make it same level. then kill it and go to next monster
    if no,
        wrap it up lil bro because they are sorted there's no way to beat him*/


    for (int test_case = 0; test_case<test_cases; ++test_case){
        sort(monster_combat_powers_ALL_CASES[test_case].begin(), monster_combat_powers_ALL_CASES[test_case].end());
    }
    //now that its sorted, lets get to the combat!
    //we will outsource this a bit as i dont want to break everything
    vector<long long> answers;
    for (int test_case = 0; test_case<test_cases; ++test_case){
        answers.push_back(combat(monster_combat_powers_ALL_CASES[test_case], combat_power[test_case], flip_flops[test_case]));
    }

    //printing results
    for (int test_case = 0; test_case<test_cases; ++test_case){
        
        cout<< answers[test_case]<< "\n";
    }

}
