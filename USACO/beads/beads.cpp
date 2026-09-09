/*
ID: ahsan.m1
TASK: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    //output section
    int n;
    fin >> n;
    string necklace;
    fin >> necklace;

    string necklace_new = necklace+necklace;//add it to itself
    
    vector<pair<char, int>> sections;
    int idx = 0;
    char type = necklace_new.at(0);
    int new_start = 0;
    while(true){
        if(idx>=necklace_new.size()){
            sections.push_back(make_pair(type, idx-new_start));//if we max
            break;//only break if we run out of space
        }
        char this_index = necklace_new.at(idx);//convenience
        if(this_index==type || this_index=='w'){//if same type or if w, we absorb w immediately NOTE THIS IS NOT TRUE, WE DONT KNOW IF TO ABSORB IMMEDIATE OR NOT
            /*ok u see the above thing... 
            well we did reverse to fix it, but like theres one dumb situation 
            where front is reverse back is not so reverse. 
            we could treat w as pivot point but that sounds really annoying
            we need to patch together reverse sections and not reverse sections somehow
            but i feel like the only straightforward way to do that is modifying the w behavior
            but that kinda tanks space complexity i feel just cause of its stupidity
            */
            idx++;//advance
            continue;
        }else{
            if(type=='w'){//adapt type, also we start by adapting type... wait we can start with the first char cause its either b/r or w anyway
                type=this_index;//change type
                idx++;//advance
                continue;
            } else{//time to switch type
                sections.push_back(make_pair(type, idx-new_start));//create new pair
                type=this_index;//change type to new guy
                new_start=idx;//change begin point of new section for length calc
                idx++;//advance
                continue;
            }
        }
    }
    //now we need to iterate through our spanking new list
    if(sections.size()==1){//situation of full list of b, w, or r, for which we can count sections for
        fout << n << "\n";
        return 0;
    } 
    int largest_length = 0;
    for(int i = 0; i<sections.size()-1;i++){
        if(largest_length < sections[i].second + sections[i+1].second){
            largest_length = sections[i].second + sections[i+1].second;
        }
    }


    //now reverse!!!!!!! cause w isnt always like good to do like that? 
    sections={};
    string necklace_new_reverse(necklace_new.rbegin(), necklace_new.rend());
    idx = 0;
    type = necklace_new_reverse.at(0);
    new_start = 0;
    while(true){
        if(idx>=necklace_new_reverse.size()){//LMAO THIS TOOK ME SO LONG TO CATCH BUT I WAS DOING JUST N BEFORE! KUDOS TO VS CODE DEBUGGER I LEARNED HOW TO USE IT
            sections.push_back(make_pair(type, idx-new_start));//if we max
            break;//only break if we run out of space
        }
        char this_index = necklace_new_reverse.at(idx);//convenience
        if(this_index==type || this_index=='w'){//if same type or if w, we absorb w immediately NOTE THIS IS NOT TRUE, WE DONT KNOW IF TO ABSORB IMMEDIATE OR NOT
            idx++;//advance
            continue;
        }else{
            if(type=='w'){//adapt type, also we start by adapting type... wait we can start with the first char cause its either b/r or w anyway
                type=this_index;//change type
                idx++;//advance
                continue;
            } else{//time to switch type
                sections.push_back(make_pair(type, idx-new_start));//create new pair
                type=this_index;//change type to new guy
                new_start=idx;//change begin point of new section for length calc
                idx++;//advance
                continue;
            }
        }
    }
    //check this list, notably without resetting largest length
    for(int i = 0; i<sections.size()-1;i++){
        if(largest_length < sections[i].second + sections[i+1].second){
            largest_length = sections[i].second + sections[i+1].second;
        }
    }
    
    fout << largest_length << "\n";
    return 0;
}