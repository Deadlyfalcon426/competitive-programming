#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //read in

    //read in number of testcases
    int testcases;
    cin>>testcases;
    //set up our vectors
    vector <vector <int>> integer_sets(testcases, vector<int>(7));
    vector<int> sums(testcases);
    //read in the testcases
    for (int tcase = 0; tcase<testcases;tcase++){
        for (int &item:integer_sets[tcase]){
            cin>>item;
        }
    }
    //compute
    //sort to help begin the greed 
    int sum;
    for (int tcase = 0; tcase<testcases;tcase++){
        sum=0;
        sort(integer_sets[tcase].begin(), integer_sets[tcase].end());
        for (int index = 0;index<6;index++){
            sum-=integer_sets[tcase][index];
        }
        sum+=integer_sets[tcase][6];
        sums[tcase] = sum;
    }
    //answers!
    for (int tcase = 0; tcase<testcases;tcase++){
        cout<<sums[tcase]<<"\n";
    }
}