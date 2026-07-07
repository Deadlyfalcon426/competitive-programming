//bismillah
#include <iostream>
using namespace std;
int main(){
    //input
    int test_cases;
    cin >> test_cases;
    for (int tcase = 0; tcase<test_cases; tcase++){
        int letters;
        cin >> letters;
        bool first_two_found = false;
        bool done = false;
        int current;
        for(int i = 0; i<letters;i++){
            cin >> current;
            if(current>2){
                done=true;
            }
            if(current==2){
                if(first_two_found){
                    done=true;
                }else{
                    first_two_found=true;
                }
            }
        }
        if(done){
            cout<<"YES"<<"\n";
        } else{
            cout<<"NO"<<"\n";
        }
    }
    /*
    what situations allow our thingy?
    if there are 2 letters that are same, and 2 other letters that are same, its possible
    if there are 3 letters that are same, its possible
    i think thats lowk enough but idk if im doing too much of a raw implementation
    as soon as you exceed 2 of a letter, it becomes allowed
    as soon as you have 2 letters that have more than 1 count, then it works
    what else?
    it is clearly shown that not much can be done with 2 and 1
    i feel like this is clear cut on purpose, i guess i'll pay the price for it
    */

}