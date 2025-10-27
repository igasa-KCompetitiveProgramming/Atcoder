#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

struct Weapon {
    int dur;
    vector<int> power;
};

bool all_open(const vector<int>& H) {
    for (int h : H) if (h > 0) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin >> N)) return 0;
    vector<int> H0(N);
    for(int i=0;i<N;i++) cin >> H0[i];
    vector<Weapon> W0(N);
    for(int i=0;i<N;i++) cin >> W0[i].dur;
    for(int i=0;i<N;i++){
        W0[i].power.resize(N);
        for(int j=0;j<N;j++) cin >> W0[i].power[j];
    }

    int best_prefix_len = INT_MAX;
    vector<int> chosen_H;
    vector<int> chosen_weaponDur;
    vector<char> chosen_obtained;
    vector<pair<int,int>> chosen_actions;

    for(int first=0; first<N; ++first){
        vector<int> curH = H0;
        vector<int> curDur(N);
        for(int i=0;i<N;i++) curDur[i] = W0[i].dur;
        vector<char> obtained(N, 0);
        vector<pair<int,int>> actions;

        // 1手目: 素手で first を殴る
        for(int k=0;k<H0[first];++k){
            curH[first] -= 1;
            actions.emplace_back(-1, first);
        }
        if(curH[first] <= 0) obtained[first] = 1;

        // 2手目: first の武器で最大火力の未開封宝箱を攻撃
        int target = -1;
        int maxA = -1;
        for(int j=0;j<N;j++){
            if(curH[j]<=0 || j==first) continue;
            if(W0[first].power[j] > maxA){
                maxA = W0[first].power[j];
                target = j;
            }
        }

        if(target != -1 && obtained[first]){
            while(curH[target] > 0 && curDur[first] > 0){
                curH[target] -= W0[first].power[target];
                curDur[first] -= 1;
                actions.emplace_back(first, target);
            }

            while(curH[target] > 0){
                bool attacked = false;
                for(int w=0;w<N;w++){
                    if(!obtained[w] || curDur[w]<=0) continue;
                    long long potential = 1LL*curDur[w]*W0[w].power[target];
                    if(potential >= curH[target]){
                        while(curH[target]>0 && curDur[w]>0){
                            curH[target]-=W0[w].power[target];
                            curDur[w]-=1;
                            actions.emplace_back(w,target);
                        }
                        attacked = true;
                        break;
                    }
                }
                if(attacked) break;

                int bestW=-1, bestP=-1;
                for(int w=0;w<N;w++){
                    if(!obtained[w] || curDur[w]<=0) continue;
                    if(curH[target]<10) continue; // 体力10未満は武器使わず素手
                    if(curH[target]<=50 && curH[target]-W0[w].power[target]<=-100) continue;
                    if(W0[w].power[target]>bestP){
                        bestP=W0[w].power[target];
                        bestW=w;
                    }
                }
                if(bestW!=-1){
                    while(curH[target]>0 && curDur[bestW]>0){
                        curH[target]-=W0[bestW].power[target];
                        curDur[bestW]-=1;
                        actions.emplace_back(bestW,target);
                    }
                    if(curH[target]<=0) break;
                    continue;
                }

                while(curH[target]>0){
                    curH[target]-=1;
                    actions.emplace_back(-1,target);
                }
                break;
            }

            if(curH[target]<=0) obtained[target]=1;
        }

        int prefix_len=(int)actions.size();
        if(prefix_len<best_prefix_len){
            best_prefix_len=prefix_len;
            chosen_H=curH;
            chosen_weaponDur=curDur;
            chosen_obtained=obtained;
            chosen_actions=actions;
        }
    }

    vector<int> curH=chosen_H;
    vector<int> curDur=chosen_weaponDur;
    vector<char> obtained=chosen_obtained;
    vector<pair<int,int>> actions=chosen_actions;

    // 3手目以降の貪欲戦略
    while(!all_open(curH)){
        bool attacked=false;

        for(int b=0;b<N && !attacked;b++){
            if(curH[b]<=0) continue;
            for(int w=0;w<N;w++){
                if(!obtained[w] || curDur[w]<=0) continue;
                if(curH[b]<10) continue; // 体力10未満は素手
                if(curH[b]<=50 && curH[b]-W0[w].power[b]<=-100) continue;
                long long potential=1LL*curDur[w]*W0[w].power[b];
                if(potential>=curH[b]){
                    curH[b]-=W0[w].power[b];
                    curDur[w]-=1;
                    actions.emplace_back(w,b);
                    if(curH[b]<=0) obtained[b]=1;
                    attacked=true;
                    break;
                }
            }
        }
        if(attacked) continue;

        int bestW=-1, bestB=-1, bestA=-1;
        for(int w=0;w<N;w++){
            if(!obtained[w] || curDur[w]<=0) continue;
            for(int b=0;b<N;b++){
                if(curH[b]<=0) continue;
                if(curH[b]<10) continue; // 体力10未満は素手
                if(curH[b]<=50 && curH[b]-W0[w].power[b]<=-100) continue;
                if(W0[w].power[b]>bestA){
                    bestA=W0[w].power[b];
                    bestW=w;
                    bestB=b;
                }
            }
        }
        if(bestW!=-1){
            curH[bestB]-=W0[bestW].power[bestB];
            curDur[bestW]-=1;
            actions.emplace_back(bestW,bestB);
            if(curH[bestB]<=0) obtained[bestB]=1;
            continue;
        }

        // 体力10未満の宝箱や武器残無しの場合は素手で最小体力宝箱
        int minH=INT_MAX, targetB=-1;
        for(int b=0;b<N;b++){
            if(curH[b]>0 && curH[b]<minH){
                minH=curH[b];
                targetB=b;
            }
        }
        if(targetB!=-1){
            curH[targetB]-=1;
            actions.emplace_back(-1,targetB);
            if(curH[targetB]<=0) obtained[targetB]=1;
            continue;
        }

        break;
    }

    for(auto &p:actions){
        cout<<p.first<<" "<<p.second<<"\n";
    }
    return 0;
}
