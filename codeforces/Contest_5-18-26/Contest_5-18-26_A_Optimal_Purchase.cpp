//Bismillah
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main(){
    long testcases;
    long long num_of_students;
    long long single_price;
    long long triple_price;
    long long final_price;
    long long triple_price_groups = 0;
    long long single_ticket_students;
    cin >> testcases;
    for(int tcase = 0; tcase<testcases;tcase++){
        final_price =0;
        triple_price_groups = 0;
        cin >> num_of_students;
        cin >> single_price;
        cin >> triple_price;
        if(triple_price<single_price*3){
            triple_price_groups = num_of_students/3;
            num_of_students -= triple_price_groups*3;
            final_price += triple_price_groups*triple_price;
        }
        triple_price_groups = (ceil(num_of_students/3.0)*triple_price);
        if(single_price*num_of_students<ceil(num_of_students/3.0)*triple_price){
            final_price+= num_of_students*single_price;
        } else{
            final_price+= ceil(num_of_students/3.0)*triple_price;
            
        }
        cout << final_price << "\n";
    }
} 