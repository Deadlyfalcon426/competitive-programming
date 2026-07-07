#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool is_there_no_dupes(vector<int> sequence){
    set<int> unique_elements(sequence.begin(), sequence.end());
    if (sequence.size()==1){
        return true;
    }
    if (unique_elements.size()==sequence.size()){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    //input
    int testcases;
    int sequence_length;
    int temp;
    vector<int> sequence;
    cin >> testcases;
    for (int test_case = 0; test_case<testcases; test_case++){
        //set up vector?
        cin >> sequence_length;
        sequence.clear();
        sequence.resize(sequence_length);
        for (int i= 0; i<sequence_length;i++){
            cin >> sequence[i];
        }
        
        if (is_there_no_dupes(sequence)){
            //sort descending
            sort(sequence.begin(), sequence.end(), greater<int>());
            for (int i = 0; i<sequence.size();i++){
                cout<<sequence[i]<<" ";
            }
            cout<<"\n";
        } else{
            cout<<"-1"<<"\n";
        }
    }
}