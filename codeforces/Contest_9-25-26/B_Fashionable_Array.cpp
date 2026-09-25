#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
//took a bit under an hour
signed main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    for (int tcase = 0; tcase < test_cases; tcase++) {
        //input section
        int n; cin >> n;
        vector<int> main;
        for(int i = 0; i<n;i++){
            int temp; cin >> temp;
            main.push_back(temp);
        }
        //input complete

        sort(main.rbegin(), main.rend());
        vector<int> other;
        int start = 0; 
        vector<int> main2;
        for(int counter = 0; counter<main.size()-1; counter++){
            start++;
            if(main[counter]==main[counter+1]){
                main.push_back(main[counter+1]);
                main.erase(main.begin()+counter+1);
                bool rest_is_same = true;
                for(int i = counter; i<main.size(); i++){
                    if(main[i]!=main[counter]){
                        rest_is_same = false;
                    }
                }
                if(!rest_is_same){
                    counter--;
                }

            }else if(main[counter]>main[counter+1]){

            }else if(main[counter]<main[counter+1]){
                
            }
        }
        for(auto& mai : main){
            cout << mai << " ";
        }
        cout << endl;

    }
    return 0;
}
/*
Gameplan:
for this, our ideal set up is all distinct numbers with biggest in front
however as we continue we might find smaller numbers that take over as the mode
our goal is to maximize the amount of times that big numbers get to be the mode
probably we can start with descending order for now
cool plan:
    we like sort it normally, then we maintain distinct numbers counting down, then we do it again!
    current: iterate through, if we find a copy we bump it down
*/