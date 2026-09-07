/*
ID: ahsan.m1
TASK: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    vector<int> counts_of_13 = vector<int>(7);//count on how many 13ths
    int current_day_of_month = 1;
    int current_day_of_week = 1;//would be 2... but our loops start from the day before the month! elite tech?????
    int current_month;
    vector<int> months_30 = {4, 6, 9, 11};
    vector<int> months_31 = {1,3,5,7,8,10,12};
    int february = 2;
    int current_year = 1900;
    int temp;
    fin >> temp;
    int end_year = temp+current_year;
    for(int current_year1 = current_year; current_year1<end_year; current_year1++){
        for(int month = 1; month<=12;month++){
            current_day_of_month = 0;
            if(std::find(months_31.begin(), months_31.end(), month) != months_31.end()){
                current_day_of_week = (current_day_of_week + 13) % 7;
                counts_of_13[current_day_of_week]++;
                current_day_of_week= (current_day_of_week + (31-13)) % 7;//update to last day of month and then take mod
            } else if(find(months_30.begin(), months_30.end(), month) != months_30.end()){
                //if 30 days then what
                current_day_of_week = (current_day_of_week + 13) % 7;
                counts_of_13[current_day_of_week]++;
                current_day_of_week= (current_day_of_week + (30-13)) % 7;//update to last day of month and then take mod
            } else if(month == february){
                //leap type shi
                if(current_year1 % 4 == 0){
                    if(current_year1 % 400 == 0){
                        //400 year
                        current_day_of_week = (current_day_of_week + 13) % 7;
                        counts_of_13[current_day_of_week]++;
                        current_day_of_week= (current_day_of_week + (29-13)) % 7;//update to last day of month and then take mod
                    }else if(current_year1 % 100 == 0){
                        //100 year thats not a 400 year
                        current_day_of_week = (current_day_of_week + 13) % 7;
                        counts_of_13[current_day_of_week]++;
                        current_day_of_week= (current_day_of_week + (28-13)) % 7;//update to last day of month and then take mod
                    } else{
                        //normal leap year
                        current_day_of_week = (current_day_of_week + 13) % 7;
                        counts_of_13[current_day_of_week]++;
                        current_day_of_week= (current_day_of_week + (29-13)) % 7;//update to last day of month and then take mod
                    }
                }else{
                    //not a leap year
                    current_day_of_week = (current_day_of_week + 13) % 7;
                    counts_of_13[current_day_of_week]++;
                    current_day_of_week= (current_day_of_week + (28-13)) % 7;//update to last day of month and then take mod
                }
            }
        }
    }
    fout << counts_of_13[0] <<" "<< counts_of_13[1] <<" "<< counts_of_13[2] <<" "<< counts_of_13[3] <<" "<< counts_of_13[4] <<" "<< counts_of_13[5] <<" "<< counts_of_13[6] << endl;
    return 0;
}