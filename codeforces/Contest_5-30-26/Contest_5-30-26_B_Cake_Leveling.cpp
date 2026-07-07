#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
int main(){
    //input
    int test_cases;
    cin >> test_cases;
    for (int tcase = 0; tcase<test_cases; tcase++){
        int n;
        cin>>n;
        int last_position;
        int current_position;
        int cake_on_knife;
        cin>>last_position;
        cout<<last_position;
        int temp;
        for(int idx = 1;idx<n;idx++){
            cin>>current_position;
            last_position=temp;
            if(current_position>=last_position){
                cake_on_knife+=current_position-last_position;
                temp=current_position;
                current_position=last_position;
            } else{
                double average = (current_position+last_position)/2.0;
                if(int(average*2)%2==0){
                    temp=current_position;
                    current_position=int(average);
                } else{
                    temp=current_position;
                    current_position=int(average);
                    cake_on_knife++;
                }
            }
            cout<<"\t"<<current_position<<"\n";
        }
    }
}