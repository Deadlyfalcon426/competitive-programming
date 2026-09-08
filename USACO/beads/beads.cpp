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
    int n;
    fin >> n;

    string necklace;
    fin >> necklace;
    vector<string> sections;
    char new_identity = 'o';
    for(int start_point = 0; start_point<n;){
        int end_point = start_point+1;
        while(true){
            //da weird block for w start
            if(necklace.at(start_point)=='w'){
                if(end_point>=n){//this is to end a situation where the loop is the same thing throughout or with w or smth
                    fout << n;
                    return 0;
                }
                if(necklace.at(end_point)!='w'){
                    if(new_identity=='o'){
                        new_identity=necklace.at(end_point);
                        end_point++;
                        continue;
                    } else if(new_identity=='b' || new_identity=='r'){
                        if(new_identity==necklace.at(end_point)){
                            end_point++;
                            continue;
                        }else{
                            new_identity = 'o';
                            sections.push_back( necklace.substr( start_point, end_point-start_point ) );
                            start_point = end_point;
                            break;
                        }
                    }
                } else{
                    end_point++;
                    continue;
                }
            }


            if(end_point<necklace.size() && (necklace.at(end_point)==necklace.at(start_point) || necklace.at(end_point)=='w')){
                end_point++;
            } else if(end_point>n){//if we are wrapping back around
                if(end_point==start_point){//this is to end a situation where the loop is the same thing throughout or with w or smth
                        fout << n;
                        return 0;
                }
                if(necklace.at(end_point%n)==necklace.at(start_point) || necklace.at(end_point%n)=='w'){
                    end_point++;
                } else{
                    sections.push_back( necklace.substr(start_point) + necklace.substr(start_point, end_point-start_point) );//add the start->actual end plus actual beginning to end point
                    sections.erase(sections.begin());//remove the first since the new one joins
                    break;//we already finished basically
                }
            } else{
                sections.push_back( necklace.substr( start_point, end_point-start_point ) );
                start_point = end_point;
                break;
            }
        }
    }
    if(sections.size()==1){
        fout << n;
        return 0;
    }
    vector<int> lengths = vector<int>(sections.size());
    vector<char> types  = vector<char>(sections.size());
    for(int i = 0; i<sections.size(); i++){
        bool r_present = find(sections[i].begin(), sections[i].end(), 'r') != sections[i].end();
        bool b_present = find(sections[i].begin(), sections[i].end(), 'b') != sections[i].end();
        if(r_present) { types[i] = 'r'; }
        if(b_present) { types[i] = 'b'; }
        lengths[i] = sections[i].size();
    }
    int biggest_sum = 0;
    for(int i = 0; i<sections.size()-1; i++){
        if(biggest_sum<lengths[i]+lengths[i+1]){
            biggest_sum=lengths[i]+lengths[i+1];
        }
    }
    if(biggest_sum<lengths[sections.size()-1]+lengths[0]){
        biggest_sum=lengths[sections.size()-1]+lengths[0];
    }

    fout << biggest_sum;
    return 0;
}