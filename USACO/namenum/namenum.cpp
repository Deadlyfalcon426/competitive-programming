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
#include <cmath>
using namespace std;
ofstream fout ("namenum.out");
unordered_map<char, vector<string>> all_names_by_start_letter;
bool empty1 = true;
int recursion(vector<vector<char>> chars_available, string string_possible){
    //we need to unpack...
    //chars available, all names by start letter, yeah thats lowk it
    if(chars_available.size()==0){
        char first_char = string_possible[0];
        auto holder = find(all_names_by_start_letter[first_char].begin(), all_names_by_start_letter[first_char].end(), string_possible);
        if(holder != all_names_by_start_letter[first_char].end()){
            fout << string_possible << "\n";
            empty1=false;
        }
        return 0;
    }
    vector<char> vec = chars_available[0];
    chars_available.erase(chars_available.begin());
    for(auto& chr : vec){
        string_possible+=chr;
        recursion(chars_available, string_possible);
        string_possible.erase(string_possible.end()-1);
    }
    return 0;
}
int main(){
    ifstream fin ("namenum.in");
    ifstream fin_dict ("dict.txt");
    string cell_code;
    fin >> cell_code;
    string temp;
    char current = 'A';
    all_names_by_start_letter.insert({'A', {}});
    while(fin_dict >> temp){
        if(temp[0]==current){
            all_names_by_start_letter[current].push_back(temp);
        } else{
            current++;//next letter
            all_names_by_start_letter.insert({current, {temp}});
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
    vector<vector<char>> chars_available;//this can be skipped, it lowers time a little and adds a little of space.
    for(auto& num : cell_code){
        int bob = num-0;
        bob-=48;
        chars_available.push_back(map_cell[bob]);
    }
    map_cell.clear();//done, just cleaning up
    //now, we have this sort of list : [A, B, C] , [G, H, I], [W, X, Y]
    //holey moly this isnt that hard. we cant even reorganize.
    //so just out of the above only AGW to CIY is possible
    //maybe i didnt need that much preprocessing;
    //well i gave up here goes recursion
    string string_possible;
    recursion(chars_available, string_possible);
    if(empty1){
        fout<<"NONE"<<"\n";
    }
    return 0;

}