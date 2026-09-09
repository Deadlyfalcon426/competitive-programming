/*
ID: ahsan.m1
TASK: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int mod(int a, int b) {
    return ((a % b) + b) % b;
}
int main(){
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    //output section
    int n;
    fin >> n;
    string str;
    fin >> str;

    //initilaizations
    string necklace = str+str;//add it to itself
    vector<pair<char, int>> sections;
    vector<pair<char, string>> same_runs;
    //split for same-runs
    int idx = 0;
    char type = necklace.at(idx);
    int start_point = 0;
    while(true){
        if(idx>=necklace.size()){
            if(same_runs[same_runs.size()-1].first==same_runs[0].first){
                same_runs[0].second=necklace.substr(start_point)+same_runs[0].second;
            }
            break;
        }
        char this_index = necklace.at(idx);
        if(this_index!=type){
            same_runs.push_back(make_pair(type, necklace.substr(start_point, idx-start_point)));
            type=this_index;
            start_point=idx;
        }
        idx++;
    }
    //next, we want to merge sections that are sandwiched
    //this is like technically recursive so i'd say this section is like borderline o(n^2)
    int ppp = -1;
    for(int i = 0; i<same_runs.size();i++){
        
        if(i>=same_runs.size()-2){
            if(i==same_runs.size()-2){
            int start = i;
            int mid = i+1;
            int end = 0;
            if(same_runs[start].first==same_runs[end].first){
                if(same_runs[mid].first=='w'){
                    //i would say id rather have the end be chopped off than to take stuff from the front
                    //so we will add to the end cause thats the front now
                    string temp = "";
                    for(auto s : same_runs[mid].second){
                        temp+=same_runs[start].first;
                    }//this is the converted middle string
                    temp=same_runs[start].second+temp;//technically the order doesnt matter cause all same letter
                    same_runs[end].second += temp;//adding it to the first, yeah here we reverse order but ts doesnt matter
                    same_runs.erase(same_runs.begin()+mid);//erase second
                    same_runs.erase(same_runs.begin()+start);//erase third, which became new second
                    i=ppp;
                    continue;
                }
            }
            }else if(i==same_runs.size()-1){
            int start = i;
            int mid = 0;
            int end = 1;
            if(same_runs[start].first==same_runs[end].first){
                if(same_runs[mid].first=='w'){
                    string temp = "";
                    for(auto s : same_runs[mid].second){
                        temp+=same_runs[start].first;
                    }//this is the converted middle string
                    //so here, i'd rather delete the last and second strings
                    same_runs[mid].second=temp;//update middle string
                    same_runs[mid].second += same_runs[start].second + same_runs[end].second;//add on strings, order dont matter
                    same_runs.erase(same_runs.begin()+start);//erase last string
                    same_runs.erase(same_runs.begin()+end);//erase second string
                    i=ppp;
                    continue;
                }
            }
        }
            else{
            //so, you managed to escape the matrix? heres a reward so you dont get stuck here again, good luck in the enxt layer...
            ppp++;
            continue;
        }
        }
        if(same_runs[i].first==same_runs[i+2].first){
            if(same_runs[i+1].first=='w'){
                string temp = "";
                for(auto s : same_runs[i+1].second){
                    temp+=same_runs[i].first;
                }
                temp+=same_runs[i+2].second;
                same_runs[i].second += temp;//adding it to the first
                same_runs.erase(same_runs.begin()+i+2);//erase third
                same_runs.erase(same_runs.begin()+i+1);//erase second
                //first iteration, first is at zero, i is at 2. 
                //now that the stuff there is gone, where do we put i?
                //i needs to be 2 ahead of the enxt guy, so it needs to be at 3
                //no need to change i then
                //lowk im going to make i reset the whole freaking loop because like that way we get a full sweep...
                //we will see how this goes
                i=ppp;
                continue;
            } else{
                //so, you managed to escape the matrix? heres a reward so you dont get stuck here again, good luck in the enxt layer...
                ppp++;
            }
        }
    }
    //merge set up complete, its beautiful
    //note: it has not bonded front and back sections yet.
    //newnote: after trials and tribulation we have done that part!
    //lastly we have look at each w section and then we run our O(n^2) part
    int largest_run=0;
    int len = same_runs.size();
    for(int i = 0; i<len;i++){
        auto sect = same_runs[i];
        int current_run_l = 0;
        int current_run_r = 0;
        int counter = 1;
        type=sect.second.at(0);
        while(true){
            if(counter>=len){
                break;
            }
            if(same_runs[mod((i-counter),len)].first=='w'){
                current_run_l+=same_runs[mod((i-counter),len)].second.size();
                counter++;
                continue;
            } else if(same_runs[mod((i-counter),len)].first!=type){
                if(type=='w'){
                    type=same_runs[mod((i-counter),len)].first;
                    current_run_l+=same_runs[mod((i-counter),len)].second.size();
                    counter++;
                    continue;
                } else if((type=='b' || type=='r')){
                    break;
                }
            } else if(same_runs[mod((i-counter),len)].first==type){
                current_run_l+=same_runs[mod((i-counter),len)].second.size();
                counter++;
                continue;
                }
            }
        //backwards one
        counter=1;
        type='w';
        while(true){
                if(counter>=len){
                    break;
                }
                if(same_runs[mod((i+counter),len)].first=='w'){
                    current_run_r+=same_runs[mod((i+counter),len)].second.size();
                    counter++;
                    continue;
                } else if(same_runs[mod((i+counter),len)].first!=type){
                    if(type=='w'){
                        type=same_runs[mod((i+counter),len)].first;
                        current_run_r+=same_runs[mod((i+counter),len)].second.size();
                        counter++;
                        continue;
                    } else if((type=='b' || type=='r') ){
                        break;
                    }
                } else if(same_runs[mod((i+counter),len)].first==type){
                    current_run_r+=same_runs[mod((i+counter),len)].second.size();
                    counter++;
                    continue;
                }
                
            }
        //joiner
        int largest_of_2 = current_run_l+ current_run_r;
        if(largest_of_2+sect.second.size()>largest_run){
            largest_run = largest_of_2+sect.second.size();
        }
    }
    
    fout << largest_run << "\n";
    return 0;
}
/*
Notes:
Now, we're going to try something with invariants, we are going to find out good breakpoints. 
What would be a dumb breakpoint?
    A dumb breakpoint would be the middle letter in bbb -> its not very useful
    we can probably skip those.
    one thing i want to look at -> skipping sections such as bbb, rrr, www
    we had something a little bit like that in v1
    w is an interesting breakpoint because thats where stuff changes, otherwise all we have is a random point that doesnt mean much
    ok new idea, merge sort type shi-> 
        find all runs of letters, ie rrr, bb, wwww, and make sure to loop the last one with the first if type matches
        next, iterate over that and bond any three consecutive sections if 1st and 3rd are same type and middle is w
        now, you should have just r and b sections interupted by the w sections
        iterate over w sections, try to get a long ahh combo by doing this:
            go left, 
                add the main w section, continue until b/r, 
                then basically continue stacking up b/r and w 
                until we run into the opposite, then we keep stacking that one with w, 
                we stop when we hit the first type again or if we hit our og w section
                if we hit our og w section we can lowk just exit...
                also there's something i've been thinking about for a long time where we only iterate over the middle section of the double necklace???
            go right,
            basically same thing icl
        ok tuff plan fr fr?
        now that we have all those sections all we gotta do was keep a running total during that bs when we were like stacking sections
*/