/*
ID: ahsan.m1
TASK: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int mod(int a, int b);

int main(){
    //input section
    ifstream fin ("combo.in");
    int n; fin >> n;
    vector<int> john_locke = vector<int>(3);
    vector<int> master_lock = vector<int>(3);
    for(auto& j : john_locke){
        fin >> j;
    }
    for(auto& j : master_lock){
        fin >> j;
    }
    fin.close();
    //input complete

    //create triples
    set<vector<int>> possible_triples;
    for(int i = -2; i<=2;i++){
        for(int j = -2; j<=2;j++){
            for(int k = -2; k<=2;k++){
                possible_triples.insert({mod(john_locke[0]+i, n), mod(john_locke[1]+j, n), mod(john_locke[2]+k, n)});
                possible_triples.insert({mod(master_lock[0]+i, n), mod(master_lock[1]+j, n), mod(master_lock[2]+k, n)});
            }
        }
    }
    ofstream fout ("combo.out");
    fout << possible_triples.size() << endl;
    fout.close();
    return 0;
}
int mod(int a, int b) {
    return ((a % b) + b) % b;
}
