#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    //input
    int test_cases;
    cin >> test_cases;
    for (int tcase = 0; tcase<test_cases; tcase++){
        int n;
        cin >> n;
        int temp;
        int smallest = INT_MAX;
        int biggest = INT_MIN;
        for (int z = 0; z<n;z++){
            cin>>temp;
            if(temp<smallest){
                smallest=temp;
            }
            if(temp>biggest){
                biggest=temp;
            }
        }
        cout<<(biggest-smallest+1)<<"\n";
    }
}