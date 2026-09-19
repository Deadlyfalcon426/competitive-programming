/*
ID: ahsan.m1
TASK: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(){
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int units_wanted, amount_of_farmers;
    fin >> units_wanted >> amount_of_farmers;
    //price then amount they got
    vector<pair<int, int>> all_da_stuff = vector<pair<int, int>>(amount_of_farmers);
    for(auto& yo_bro : all_da_stuff){
        int temp;
        int temp2;
        fin >> temp >> temp2;
        yo_bro = make_pair(temp, temp2);
    }
    //fill in complete
    
    //sort by price
    sort(all_da_stuff.begin(), all_da_stuff.end());
    int cost_in_cents = 0;
    for(auto& farmer : all_da_stuff){
        if(farmer.second>units_wanted){
            cost_in_cents += units_wanted * farmer.first;
            units_wanted=0;
            break;
        }else{
            cost_in_cents += farmer.second * farmer.first;
            units_wanted-=farmer.second;
        }
    }
    fout << cost_in_cents << "\n";
}