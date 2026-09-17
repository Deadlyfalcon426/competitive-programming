/*
ID: ahsan.m1
TASK: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cmath>
//define b10 base 10
//nah thats a joke but when i say b10 i usually mean base 10, and b8 meaning base 8, and so on and so forth
using namespace std;

//below map is just for to speed things up with not too much memory. actually yk what. Im not going to be a goon. I'm going to use direct adding to values of char
//ok i skipped map in favor of cool but easily screwed up char thingy
bool is_palindrome(string s){//tested, should work fine. so when ur debugging, chances are its not this guy's fault
    int len = s.size();
    for(int i = 0; i<len/2;i++){
        if(s[i]!=s[len-1-i]){
            return false;
        }
    }
    return true;
}
string to_arbitrary_base(int old_in_base_10, int new_base){//alright ts might be done and working but idk tho 😂✌️
    /*
    we will use just alphabetic system, 
    honestly it doesnt matter what system we use as long as they are all distinct symbols. 
    but we shouldnt need more symbols because, 
    well i am having difficulty understanding what eEXACTLY the problem is saying,
    but I think we only go up to base 20, being from A to T, so no issue there
    */
    int old = old_in_base_10;//just annoying having a long name, past one was to describe
    int counter = 0;
    while(true){
        counter++;
        if(old<pow(new_base, counter)){
            counter--;
            break;
        }
    }
    string s = "";
    for(int i = counter; i>=0;i--){
        char char_value = 97;
        int z = pow(new_base, i);
        if(old >= z){
            int j = old/z;
            old = old % z;
            s+=char_value+j;
        }else{
            if(z<new_base){
                s+=char_value+old;
            }else{
                s+=char_value+0;
            }
        }

    }
    return s;
}
string to_int_from_random_base_string(string based_string){
    string answer;
    for(char c : based_string){
        int mohammed_salah = (c-'a');//grr i dont like debugging
        if(mohammed_salah>=10){
            answer += mohammed_salah+'A'-10;
            continue;
        }
        answer += (c-'a')+'0';
    }
    return answer;
}
int main(){
    ifstream fin ("palsquare.in");
    ofstream fout ("palsquare.out");
    int base_B;
    fin >> base_B;//now, I need to think about representing this one.
    //we can probably start by knowing how to convert anything from b10 to bx for any x
    //screw it we will make a method so i dont have a bunch of clogged code.
    
    for(int num_in_b10 = 1; num_in_b10<=300;num_in_b10++){
        int squared = pow(num_in_b10, 2);
        if(is_palindrome(to_arbitrary_base(squared, base_B))){
            fout << to_int_from_random_base_string(to_arbitrary_base(num_in_b10, base_B)) << " " << to_int_from_random_base_string(to_arbitrary_base(squared, base_B)) << "\n";
            
        }
    }

}