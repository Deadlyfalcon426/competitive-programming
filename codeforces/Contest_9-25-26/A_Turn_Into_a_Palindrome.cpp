#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//20-25 min ish
#define int long long

signed main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    for (int tcase = 0; tcase < test_cases; tcase++) {
        int n; cin >> n;
        char c; cin >> c;
        string main; cin >> main;
        string first = string(main.begin(), main.end()-(main.size()/2));
        string second = string(main.begin()+(main.size()/2), main.end());
        reverse(second.begin(), second.end());
        int change_counter = 0;
        for(int i = 0; i<first.size(); i++){
            if(first.at(i)==second.at(i)){
                change_counter+=0;
            }else if(first.at(i)==c || second.at(i)==c){
                change_counter++;
            }else{
                change_counter+=2;
            }
        }
        cout << change_counter << endl;
    }
    return 0;
}