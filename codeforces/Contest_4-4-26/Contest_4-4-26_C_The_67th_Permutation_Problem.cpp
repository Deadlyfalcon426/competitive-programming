#include <iostream>
#include <vector>
using namespace std;
int main(){
    //input
    int testcases;
    cin >> testcases;
    int n;
    vector<int> current_sequence;
    vector<int> new_sequence;
    int counter = 0;
    int counter_back = 0;
    for (int test_case = 0; test_case<testcases; test_case++){
        cin >> n;
        current_sequence.resize(3*n);
        //fill out current sequence
        for (int i = 0; i<3*n; i++){
            current_sequence[i] = i+1;
        }
        //switch up the array, as well as print out
        counter=0;
        counter_back = current_sequence.size()-1;
        new_sequence.resize(3*n);
        for (int i = n; i>0; i--){
            cout << current_sequence[counter_back]<< " ";
            counter_back--;
            cout << current_sequence[counter_back]<< " ";
            counter_back--;
            cout << current_sequence[counter]<< " ";
            counter++;
        }
        cout << "\n";
    }
}