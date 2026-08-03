//bismillah
#include <iostream>
using namespace std;
int main(){
    //input
    long long test_cases;
    cin >> test_cases;
    for (long long tcase = 0; tcase<test_cases; tcase++){
        long long length;
        cin>>length;
        long long previous;
        long long current;
        cin>>previous;
        bool is_possible = true;
        long long buffer = 0;
        for(long long i =1;i<length;i++){
            cin>>current;
            if(previous>=i){
                buffer=previous-i;
                previous=i;
                current+=buffer;
                if(current<=previous){
                    is_possible=false;
                }
            } else{
                is_possible=false;
            }
            previous=current;
        }

/*
        for(int i =1;i<length;i++){
            cin>>current;
            if(previous>=i){
                current+=previous-i;
                previous=i;
                if(current<=previous){
                    is_possible=false;
                }
            }else{
                is_possible=false;
            }
            previous=current;
        }
*/

        /*
        for(int i = 1; i<length;i++){
            cin>>current;
            if(previous>=current){
                if(previous>previous2 && previous>1){
                    bool is_still_working = true;
                    while(is_still_working){
                        //check if there are still left to take (always works first time)
                        if(previous>previous2 && previous>1){
                            previous--;
                            current++;
                        } else{ //if there is nothing left to take and this loop is still running, we failed
                            is_still_working=false;
                            is_possible=false;
                        }
                        if(current>previous){//check if it worked at the end, else we have to run again
                            is_still_working=false;
                        }
                    }
                }else{
                    is_possible=false;
                }
            }
            previous2=previous;
            previous=current;
        }
            */
        if(is_possible){
            cout<<"YES"<<"\n";
        } else{
            cout<<"NO"<<"\n";
        }
    }
}

