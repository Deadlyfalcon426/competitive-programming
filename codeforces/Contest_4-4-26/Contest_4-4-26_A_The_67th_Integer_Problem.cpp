#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    //testcases
    int testcases;
    cin>>testcases;
    vector <int> answers(testcases);
    vector <int> integers(testcases);
    for (int tcase = 0; tcase<testcases;tcase++){
        cin>>integers[tcase];
    }
    //read in complete
    //compute
    for (int tcase = 0; tcase<testcases;tcase++){
        if(integers[tcase]==67){
            answers[tcase]=67;
        } else{
            answers[tcase]=integers[tcase]+1;
        }
    }
    //print out
    for (int tcase = 0; tcase<testcases;tcase++){
        cout<<answers[tcase]<<"\n";
    }
    return 0;
}