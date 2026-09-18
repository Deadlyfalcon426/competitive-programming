/*
ID: ahsan.m1
TASK: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
bool is_palindrome(string string1);
string to_arbitrary_base(int old_int, int base_new);
int main(){
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    //brute force here we go

    //amount of integers before you are done
    int N;
    //starting integer
    int S;
    fin >> N >> S;
    fin.close();
    //input finished

    int approved_counter = 0;
    int current_guy = S;
    //iterate over all possible thingies until we give up
    while(approved_counter<N){
        current_guy++;//strictly greater than S so why not put it here
        int approved_bases = 0;
        int current_base = 2;
        while(approved_bases<2 && current_base<=10){
            if(is_palindrome(to_arbitrary_base(current_guy, current_base))){
                approved_bases++;
            }
            current_base++;
        }
        if(approved_bases==2){
            approved_counter++;
            fout << current_guy << "\n";
        }

    }
    return 0;
}
//below function is vetted, should work
bool is_palindrome(string string1){
    int len = string1.size();
    for(int i = 0; i<len/2;i++){
        if(string1[i]!=string1[len-1-i]){
            return false;
        }
    }
    return true;
}
/*ok this works. it doesnt choose good symbols but we can fix that with an unordered map later, 
the only issue is that since its a black box, ie we never need to see it, it doesnt really matter aside from debug
prob wont do but we will see*/

string to_arbitrary_base(int old_int, int base_new){
    int counter = 0;
    while(true){
        if(old_int<pow(base_new, counter)){
            counter--;
            break;
        }else if(old_int>pow(base_new, counter)){
            counter++;
        }else{
            break;
        }
    }
    string new_str = "";
    for(int i = counter; i>=0;i--){
        int multiplier = old_int/pow(base_new, i);
        old_int = old_int - multiplier * pow(base_new, i);
        new_str+=char(multiplier+65);
    }
    return new_str;
}