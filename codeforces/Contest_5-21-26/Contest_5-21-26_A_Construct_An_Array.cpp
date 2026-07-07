//bismillah
#include <iostream>
using namespace std;
int main(){
    int testcases;
    int n;
    cin >> testcases;
    for (int tcase = 0; tcase<testcases;tcase++){
        cin >> n;
        for (int number = 1; number<2*n;number+=2){
            cout<<number<<" ";
        }
        cout<<"\n";
    }
}