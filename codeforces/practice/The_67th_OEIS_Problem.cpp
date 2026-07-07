/*
https://codeforces.com/contest/2218/problem/D
same contest as 4-4-26, however it's over so im just practicing the ones from it that i didnt get to
basically no 2 consecutive numbers can have the same GCD
soo first maybe ill make a GCD finding function?
no that might not be necessary this seems like a math problem.
well we know that 1 and 2 can be always included. 
next GCD should be like 2, so maybe 2 and 4
next GCD should be 3, so 4 doesnt work, so [1, 2 , 6, 12, 20, 30, ]?
so we are reaching a theme here where each number is the product of n * n+1
idk it could work its worth a shot

did not work as we needed GCF not CF, anyways that solution was too simple to be true
alright i have a new idea to throw out the old factor as soon as we get the new one
as well as use prime numbers as factors to prevent GCF from being bad!
[1,(1) 2,(2), 6, 15, 35, 77
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> get_primes(int limit){
    vector<bool> primes={};
    vector<int> answer_primes;
    primes.resize(limit+1);
    for(int x = 0; x<limit+1; x++){
        primes[x] = true;
    }
    primes[0] = primes[1] = false;
    for (int i = 2; i*i<limit+1;i++){
        if (primes[i]){
            for (int z = i*i;z<limit+1;z+=i){
                primes[z] = false;
            }
        }
    }
    for (int i = 2; i<limit+1;i++){
        if (primes[i]){
            answer_primes.push_back(i);
        }
    }
    return answer_primes;
}

int main(){
    //input
    int testcases;
    cin >> testcases;
    int amount_of_numbers = 1;
    int temp;
    for (int test_case = 0; test_case<testcases; test_case++){
        //read in amount
        cin >> amount_of_numbers;
        vector<int> primes = get_primes(amount_of_numbers);
        for (int i = 0; i<primes.size();i++){
            cout<<primes[i]<<"\t";
        }
        //setup
        cout << "1" << " " << "2" << " ";
        for (int count = 2; count<amount_of_numbers; count++){
            cout << primes[count]*primes[count-1] <<" ";
        }

    }   
}