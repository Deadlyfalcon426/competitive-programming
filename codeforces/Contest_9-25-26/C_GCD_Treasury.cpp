#include <iostream>
#include <vector>
#include <map>
using namespace std;

int gcd(int a, int x);
signed main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    for (int tcase = 0; tcase < test_cases; tcase++) {
        int n; cin >>n;
        int divisor; cin >>divisor;
        vector<int> piles;
        vector<int> base_gcd;
        map<int, int, greater<>> distinct_dudes;
        for(int i = 0; i<n; i++){
            int temp; cin >> temp;
            piles.push_back(temp);
            base_gcd.push_back(gcd(temp, divisor));
            distinct_dudes[temp]++;
        }
        int high_score = 0;
        //n and n+1 never have gcd bigger than 1
        while (distinct_dudes.size()>0) {
            int iterate = distinct_dudes.begin()->first;
            int current_score = 0;
            int active_divisor = divisor;
            while(true){
                if(distinct_dudes.find(0)!=distinct_dudes.end()){
                    distinct_dudes.erase(0);
                }
                if(distinct_dudes.size()==0){
                    break;
                }
                int stolen;
                stolen = gcd(active_divisor, iterate);
                if(stolen == 1){
                    distinct_dudes.erase(iterate);
                    break;
                }
                if(iterate-stolen>0){
                    if(distinct_dudes.find(iterate-stolen)==distinct_dudes.end()){
                        distinct_dudes[iterate-stolen] = 0;
                    }
                    distinct_dudes[iterate-stolen]+=distinct_dudes[iterate];
                }
                current_score+=distinct_dudes[iterate]*stolen;
                active_divisor = stolen;
                distinct_dudes.erase(iterate);
                if(distinct_dudes.size()==0){
                    break;
                }
                bool new_found = false;
                for (auto [i , j] : distinct_dudes) {
                    if(i>=iterate){
                        continue;
                    }
                    if(i==0){
                        continue;
                    }
                    if(gcd(i, active_divisor)!=1){
                        iterate=i;
                        new_found=true;
                        break;
                    }
                }
                if(!new_found){
                    break;
                }
            }
            if(current_score>high_score){
                high_score=current_score;
            }
            if(distinct_dudes.size()==0){
                break;
            }
        }

        cout << high_score << endl;
    }
    return 0;
}
int gcd(int a, int x){
    //euclidean
    while(x!=0){
        int r = a%x;
        a=x;
        x=r;
    }
    return a;
}
/*
Gameplan:
    gcd implemented. 
    is there anything preventing a sort by biggest and then gcd each thats possible?
    6 - 2,3,2,3,2,3 - last alg. is good
    6 - 9,9,4,4,4,4,4 - two choices -> 
        9 -> 3+3+3+3+3+3 = 18
        4 -> (2+2)*5 = 20
        breaks old algorithm
    cool thing, we can eliminate anyone who is not the gcd from the beginning, 
    because we keep limiting our gcd to the next gcd, so we will never gain a new prime factor
    what if we do that and brute force?

    cool thing: splitting by main annoying prime factor, also splitting by type of number?
    like a three tree and a 4/2 tree?
    ok ive got something. iterate over unique dudes, notice their size, then like add their chains!
    we could have smth like 8-4-2 chain value vs 12-6-3 vs 12-4-2 or smth???
    then return the best

    dang i need more testcases

    ok i am storing different instances of distinct numbers, now i need to group by gcd
    what is an optimal way to group by gcd?
    9 8 7 6 5 4 3 2 1
    9   ->6 ->4 ->2
            ->3
    8   ->4 ->2
    7   
    you know what we cross out 6 because it is a submember!
    then 5 is prime
    4 is submember
    3 and 2 are submember

*/