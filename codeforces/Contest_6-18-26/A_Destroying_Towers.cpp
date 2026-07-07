#include <iostream>
using namespace std;
int main(){
    //input
    int test_cases;
    cin >> test_cases;
    for (int tcase = 0; tcase<test_cases; tcase++){
        int sum = 0;
        int last = 0;
        int current = 0;
        int num_in_case;
        cin >> num_in_case;
        cin >> last;
        sum+=last;
        for(int i = 1; i<num_in_case;i++){
            cin >> current;
            if(last<current){
                current=last; //chopping part
                sum+=current; //add new
            } else{
                sum+=current;// no chop, just add
            }
            last=current;//reassign for next loop
        }
        cout<<sum<<"\n";
    }
}