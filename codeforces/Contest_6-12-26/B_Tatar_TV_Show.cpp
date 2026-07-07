#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    //input
    int test_cases;
    cin >> test_cases;
    for (int tcase = 0; tcase<test_cases; tcase++){
        int n; cin >> n;
        int k; cin >>k;
        string temp;
        cin >> temp;
        vector<int> binary_string;
        for(char c : temp){
            binary_string.push_back(c - '0');
        }
        int one_count = count(binary_string.begin(), binary_string.end(), 1);
        if(one_count%2==1){
            cout<<"NO"<<"\n";
        } else if(one_count==0){
            cout<<"YES"<<"\n";
        } 
        else{
            vector<int> ones;
            for(int j = 0; j<binary_string.size();j++){
                if(binary_string[j]==1){
                    ones.push_back(j%k);
                }
            }
            bool ayo_it_worked = true;
            sort(ones.begin(), ones.end());
            for(int y = 1; y<ones.size();y+=2){
                if(ones[y-1]!=ones[y]){
                    cout<<"NO"<<"\n";
                    ayo_it_worked=false;
                    break;
                }
            }
            if(ayo_it_worked){
                cout<<"YES"<<"\n";
            }
            
        }
        
        
    }
}