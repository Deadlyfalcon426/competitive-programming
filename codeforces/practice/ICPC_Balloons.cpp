#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
using namespace std;
int main(){
    //problem: https://codeforces.com/problemset/problem/1703/B
    /*my plan of attack is to iterate over letters, check if they are already mentioned, and
    have a basic accumulator. at first glance this problem seems to easy for me but perhaps
    i will be pleasantly surprised!*/

    //define our wonderful data-holding fellows over here

    int test_cases;
    int temp;
    //read in inputs!

    cin >> test_cases;
    vector <int> lengths_of_sequences(test_cases);
    vector <string> sequences(test_cases);
    vector <char> used_characters;
    vector <int> scores_each_round(test_cases);
    for (int test_case = 0; test_case<test_cases; ++test_case){
        cin >> lengths_of_sequences[test_case];
        //above might be useless but at least the line is skipped
        cin >> sequences[test_case];
    }
    //input received!

    //lmao i dont think we needed the length of each sequence
    //now iterating over the sequence
    for (int round = 0; round<test_cases; ++round){
        used_characters.clear();
        for (char letter: sequences[round]){
            //if not found - meaning first time solve
            if (find(used_characters.begin(), used_characters.end(),letter) == used_characters.end()){
                used_characters.push_back(letter);
                scores_each_round[round]+=2;
            //at the end here is if it does find it, its not first time so reduced points
            } else {
                ++scores_each_round[round];
            }
        }
    }
    //printing out answers
    for (int round = 0; round<test_cases; ++round){
        cout<<scores_each_round[round]<<"\n";
    }

}