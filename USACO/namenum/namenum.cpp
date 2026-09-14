/*
ID: ahsan.m1
TASK: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(){
    ifstream fin ("namenum.in");
    ofstream fout ("namenum.out");
    ifstream fin_dict ("dict.txt");
    string cell_code;
    fin >> cell_code;
    string temp;
    char current = 'A';
    unordered_map<char, vector<string>> all_names_by_start_letter;
    all_names_by_start_letter.insert({'A', {}});
    while(fin_dict >> temp){
        if(temp.at(0)==current){
            all_names_by_start_letter[current].push_back(temp);
        } else{
            current++;//next letter
            all_names_by_start_letter.insert({current, {}});
        }
        temp.clear();
    }
    //so now we have filled up the map for speedy ahh stuff, this is just preporcessing btw idk if its needed but it sure looks sexy and its not that hard
    //next we need to make sense of the code... this is just permutations honestly,
    //we aren't doing things like checking for vowels or whatever
    vector<string> names_viable; //i like this because important thing, known-for first then info later
    //well for decoding we can actually use another map
    unordered_map<int, vector<char>> map_cell = {
        {2, {'A','B','C'}},
        {3, {'D','E','F'}},
        {4, {'G','H','I'}},
        {5, {'J','K','L'}},
        {6, {'M','N','O'}},
        {7, {'P','R','S'}},
        {8, {'T','U','V'}},
        {9, {'W','X','Y'}}
    };
    vector<char> chars_available;
    for(auto& num : cell_code){
        int num = num-0;
        chars_available.reserve(chars_available.size() + map_cell[num].size());//memorymaxxing
        chars_available.insert(chars_available.end(), map_cell[num].begin(), map_cell[num].end());
    }
    map_cell.clear();//done, just cleaning up
    

}