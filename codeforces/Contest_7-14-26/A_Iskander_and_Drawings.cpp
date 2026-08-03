//bismillah
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    //input
    int test_cases;
    cin >> test_cases;
    for (int tcase = 0; tcase<test_cases; tcase++){
        int length;
        cin >> length;
        string inp;
        cin >> inp;
        bool is_part_of_sequence = false;
        vector<int> largest_sequences;
        int sequence_counter = 0;
        for(int i = 0; i<=length;i++){
            if(is_part_of_sequence){
                if(i!=length && inp[i]=='#'){
                    sequence_counter++;
                } else{
                    if(i==length){
                        largest_sequences.push_back(sequence_counter);
                    }
                    is_part_of_sequence = false;
                    largest_sequences.push_back(sequence_counter);
                    sequence_counter=0;
                }
            } else{
                if(inp[i]=='#'){
                    is_part_of_sequence = true;
                    sequence_counter++;
                }
            }
        }
        int max = 0;
        for(int i = 0; i<largest_sequences.size();i++){
            largest_sequences[i]=round(largest_sequences[i]/2.0);
            if(max<largest_sequences[i]){
                max = largest_sequences[i];
            }
        }
        cout<<max<<"\n";
    }
}