//bismillah
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int testcases;
    int length;
    vector<int> array_main;
    vector<int> gaps;
    bool does_it_work = true;
    int max;
    int temp;
    cin >> testcases;
    for (int tcase = 0; tcase<testcases;tcase++){
        array_main.clear();
        gaps.clear();
        does_it_work = true;
        cin >> length;
        //fill main array
        for (int x = 0; x<length; x++){
            cin>>temp;
            array_main.push_back(temp);
        }
        //fill gaps array
        for (int x = 1; x<length;x++){
            gaps.push_back(array_main[x-1]-array_main[x]);
        }
        //pick biggest gap (yeah i dont think this is the best way for time complexity)
        max = *max_element(gaps.begin(), gaps.end());
        /*
        do we need to add k? 
        if no, 
            cool. 
        if yes, 
            if we do add k, 
                does it work? 
            cause otherwise 
                the whole array doesnt work
        */
        for(int x = 0; x<gaps.size();x++){
            if(array_main[x+1]<array_main[x]){
                array_main[x+1]+=max;
                if(array_main[x+1]<array_main[x]){
                    cout<<"NO"<<"\n";
                    does_it_work=false;
                    break;
                }
            }
        }
        //if it passes through the whole thing successfully then yay! say 'yes'!
        if (does_it_work){
            cout<<"YES"<<"\n";
        }
    }
}