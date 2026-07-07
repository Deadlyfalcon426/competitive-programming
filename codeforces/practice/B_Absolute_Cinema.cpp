#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long testcases;
    long long length;
    long long temp;
    vector<long long> numbers;
    vector<long long> numbers2;
    long long sum;
    cin >> testcases;
    for (int tcase = 0; tcase<testcases;tcase++){
        cin >> length;
        numbers.clear();
        numbers2.clear();
        sum = 0;
        for (int x = 0; x<length;x++){
            cin >> temp;
            numbers.push_back(temp);
        }
        for (int x = 0; x<length;x++){
            cin >> temp;
            numbers2.push_back(temp);
        }
        for(int x = 0; x<length;x++){
            if(numbers2[x]>=numbers[x]){
                sum+=numbers2[x];
            } else{
                temp = numbers2[x];
                numbers2[x] = numbers[x];
                numbers[x] = temp;
                sum+=numbers2[x];
            }
        }
        sum+=*max_element(numbers.begin(), numbers.end());
        cout<<sum<<"\n";
    }
}