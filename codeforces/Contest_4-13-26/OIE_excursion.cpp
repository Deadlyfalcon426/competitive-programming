#include <vector>
#include <iostream>
using namespace std;
int main(){
    //input
    
    int testcases;
    int guards_count;
    int cycle_length;
    /*
    cin >> testcases;
    for (int test_case = 0; test_case<testcases; test_case++){
        cin >> guards;
        cin >> cycle_length;

    }
    //put this on hold for now
        */
    cin>>guards_count;
    cin>>cycle_length;
    int timer=0;
    vector<int> positions;
    int player=0;
    positions.resize(guards_count);
    bool still_stuck=true;
    for (int i = 0; i<guards_count;i++){
        cin >>positions[i];
    }
    while(still_stuck){
        if ((positions[player+1]+timer+1)%cycle_length!=0){
            
        }
    }
}