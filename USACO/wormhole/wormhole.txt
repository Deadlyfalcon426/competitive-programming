/*
ID: ahsan.m1
TASK: wormhole
LANG: C++
*/

/*
i had to consult an editorial in order to figure this one out. 
I will take substantial notes in order to learn from my loss and analyze the foreign solution
its not going well because i cant find any editorials and just code
i guess i will be reverse engineering a lot of what is happening

so i still had to write it out and adapt it to my style
cause the guy who wrote it 12 years ago had really bad style and mine is cleaner and excessively commented
anything for learning ig
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//number of wormholes, <=12
int n;
/*
we store x & y values (parallel array),
partner of each wormhole, probably by index
wormholes that could lead to a loop, ones that are on the same line
*/
vector<int> x, y, partner, next_wormhole;

bool cycle_exists();
int solve();
int main(){
    //input section
    ifstream fin ("wormhole.in");
    fin >> n;
    x = vector<int>(n+1);//since vector is reference object type thing i cant assign them all same thing
    y = vector<int>(n+1);
    partner = vector<int>(n+1);
    next_wormhole = vector<int>(n+1);
    for(int j = 1; j<=n;j++){
        fin >> x[j];//x
        fin >> y[j];//y
    }
    fin.close();
    //input section complete

    for(int i=1;i<=n;i++){//iterate through all wormholes
        for(int j=1;j<=n;j++){//iterating over all second wormholes
            if(x[j]>x[i] && y[j] == y[i]){//if they share same line and second is to the right:  (also note that this prevents using the same wormhole twice)
                if(next_wormhole[i]==0 || x[j]-x[i] < x[next_wormhole[i]]-x[i]){
                    /*
                    if either the next wormhole hasnt been set,
                    or 
                    if the new j is closer than the old next wormhole

                    might be worth a test to see if the first condition is unnecessary
                    */
                    next_wormhole[i] = j;//so if that happens we reach for the closer loop
                }
            }
        }
    }
    //essentially, the above code is used to find any same level loops

    //output section
    ofstream fout ("wormhole.out");
    fout << solve() << endl;
    fout.close();
    return 0;
}

int solve(){
    int i, total = 0;
    for(i = 1; i<n+1; i++){//gives back the first index that isnt filled with a partner
        if(partner[i]==0){
            break;
        }
    }

    if(i>n){//well perhaps everyone has been paired
        if(cycle_exists()){//so before writing cycle_exists i realize that this is what does the logic based on whichever pair combo iteration we are on
            return 1;//that would be the extra point ig
        }else{
            return 0;
        }
    }

    //now try pairing partnerless i with all other wormholes
    for(int j = i+1; j<=n; j++){
        if(partner[j] == 0){//if partner not set
            partner[i] = j;
            partner[j] = i;
            total += solve();
            partner[i] = partner[j] = 0;//reset, clean up as we exit the call stack
        }
    }

    return total; //end of recursion, bottom of call stack
}
bool cycle_exists(){//so this one is supposed to search for across thingies or sum
    for(int start = 1; start<n+1; start++){//iterate over partners list
        int pos = start;
        for(int count = 1; count<n+1; count++){//iterate over full list
            pos = next_wormhole[partner[pos]];//jump from each partner's next wormhole???
        }
        if(pos != 0){//well if we end up outside of it i guess this is our situation???
            return true;
        }
    }
    return false;
}