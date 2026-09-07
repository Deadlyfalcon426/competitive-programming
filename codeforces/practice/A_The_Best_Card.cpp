#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define int long long

signed main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    for (int tcase = 0; tcase < test_cases; tcase++) {
        int n;
        cin >> n;
        /*
        vector<int> vec;
        //create vector
        for(int i = 2; i<=n+1;i++){
            vec.push_back(i);
        }
            */
        int largest = n+1;
        
        //sieve of erastosthens
        /*
        for(int i = 0; i<vec.size()-2;i++){
            int remover = vec[i];
            if(remover==1){//optimizes plus probably fixes issues
                continue;
            }
            vec[i] = 1;
            for(int j = i;j<vec.size();j+=remover){
                vec[j] = 1;
            }
        }
        
        if(vec[vec.size()-1]!=1){
            cout<<"YES"<<"\n";
        } else{
            cout<<"NO"<<"\n";
        }
            */
        //riddle me this. why use sieve of erastosthens when we can just spam divide until we get to zero?
        //anyway we dont need extra primes, this was a relic from previous thought path
        int counter = pow(largest, 0.5);//further optimize, after square root its factor pair counterparts
        bool factor_found = false;
        while(counter>=2){
            if(largest%counter==0){
                factor_found = true;
                break;
            }
            counter--;
        }
        if(factor_found){
            cout<<"NO"<<"\n";
        } else{
            cout<<"YES"<<"\n";
        }
    }
    return 0;
}