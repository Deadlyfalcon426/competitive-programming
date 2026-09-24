/*
ID: ahsan.m1
TASK: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
bool isSolution(vector<int> digits, int first_ones, int first_tens, int first_hundred, int second_ones, int second_tens);
int main(){
    ifstream fin ("crypt1.in");
    int n; fin >> n;
    vector<int> digits;
    for(int i = 0; i<n;i++){
        int temp;
        fin >> temp;
        digits.push_back(temp);
    }
    fin.close();
    sort(digits.begin(), digits.end());
    int solution_counter = 0;
    //only 10 digits max, so this cant take more than 10^5 iterations, then the thing inside max has to search entire array so 10^6 calculations
    for(int first_ones : digits){
        for(int first_tens : digits){
            for(int first_hundred : digits){
                for(int second_ones : digits){
                    for(int second_tens : digits){
                        if(isSolution(digits, first_ones, first_tens, first_hundred, second_ones, second_tens)){
                            solution_counter++;
                        }
                    }
                }
            }
        }
    }

    ofstream fout ("crypt1.out");
    fout << solution_counter << endl;
    fout.close();
}
bool isSolution(vector<int> digits, int first_ones, int first_tens, int first_hundred, int second_ones, int second_tens){
    unordered_map<int, bool> digits_present;
    for(int i = 0;i<10;i++){
        if(find(digits.begin(), digits.end(), i)!=digits.end()){
            digits_present[i] = true;
        }else{
            digits_present[i] = false;
        }
    }
    int first = first_hundred*100 + first_tens*10 + first_ones*1;
    int second = second_tens*10 + second_ones*1;
    string total = to_string(first*second);
    if(digits_present[total.at(3)-'0'] && digits_present[total.at(2)-'0'] && digits_present[total.at(1)-'0'] && digits_present[total.at(0)-'0']){
        if(first*second>9999){
            return false;
        }
    }else{
        return false;
    }
    total = to_string(first*second_tens); 
    if(digits_present[total.at(2)-'0'] && digits_present[total.at(1)-'0'] && digits_present[total.at(0)-'0']){
        if(first*second_tens>999){
            return false;
        }
    }else{
        return false;
    }
    total = to_string(first*second_ones); 
    if(digits_present[total.at(2)-'0'] && digits_present[total.at(1)-'0'] && digits_present[total.at(0)-'0']){
        if(first*second_ones>999){
            return false;
        }
    }else{
        return false;
    }
    return true;
}