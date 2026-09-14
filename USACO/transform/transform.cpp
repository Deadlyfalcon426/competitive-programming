/*
ID: ahsan.m1
TASK: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//beautiful C++... it checks all the elements in std::vector and all u gotta do is classic ==
using namespace std;
int main(){
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n;
    fin >> n;
    vector<vector<int>> og = vector<vector<int>>(n);
    string temp;
    int counter;

    for(auto& buddy : og){//fill up the vector
        fin>>temp;
        for(char& bud : temp){
            buddy.push_back(static_cast<char>(bud));
        }
    }
    vector<vector<int>> withered = vector<vector<int>>(n);
    for(auto& buddy : withered){//fill up the vector
        fin>>temp;
        for(char& bud : temp){
            buddy.push_back(static_cast<char>(bud));
        }
    }
    //well... it is the brute force chapter
    //we will check individual scenarios and be sure to rule out repeat scenarios

    vector<vector<int>> temp90 = vector<vector<int>>(n);
    //Case 1: 90 Degree clockwise
    for(int i = 0;i<n;i++){
        for(int j = n-1;j>=0;j--){
            temp90[i].push_back(og[j][i]);
        }
    }
    if(withered==temp90){
        fout << "1" << "\n";
        return 0;
    }
    //Case 2: 180 Degree clockwise
        //alright hear me out its just the 90 degrees again
    vector<vector<int>> temp180 = vector<vector<int>>(n);
    for(int i = 0;i<n;i++){
        for(int j = n-1;j>=0;j--){
            temp180[i].push_back(temp90[j][i]);
        }
    }
    if(withered==temp180){
        fout << "2" << "\n";
        return 0;
    }
    //Case 3: 270 Degree clockwise
        //lowk same thing again tuff
    vector<vector<int>> temp270 = vector<vector<int>>(n);
    for(int i = 0;i<n;i++){
        for(int j = n-1;j>=0;j--){
            temp270[i].push_back(temp180[j][i]);
        }
    }
    if(withered==temp270){
        fout << "3" << "\n";
        return 0;
    }
    //Case 4: flip left stuff to right, flipping over long edge
    vector<vector<int>> flipped_horz = vector<vector<int>>(n);
    for(int i = 0;i<n;i++){
        for(int j = n-1; j>=0;j--){
            flipped_horz[i].push_back(og[i][j]);
        }
    }
    if(withered==flipped_horz){
        fout << "4" << "\n";
        return 0;
    }
    //Case 5: Combo-> 4 + one of the first 3
    vector<vector<int>> temp1 = vector<vector<int>>(n);
    for(int i = 0;i<3;i++){
        for(int i = 0;i<n;i++){
            for(int j = n-1;j>=0;j--){
                temp1[i].push_back(flipped_horz[j][i]);
            }
        }
        if(withered==temp1){
            fout << "5" << "\n";
            return 0;
        }
        flipped_horz=temp1;
        for(auto& vec : temp1){
            vec.clear();
        }
    }
    //Case 6: Zero change... lets move this to the front because it's less computationally expensive?? idk sounds correct and cant hurt
    //never mind, minimum number meant number choice, not number of transformations
    if(og==withered){
        fout<<"6" << "\n";
        return 0;
    }
    //Case 7: Basically if none, so default, we can make this auto by setting it up to always run, and then making all of the above cancel as soon as task complete
    fout << "7" << "\n";
    return 0;
}