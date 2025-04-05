#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rrep1(a)          for(ll i = (ll)(a-1); i >= (ll)0 ; i--)
#define rrep2(i, a)       for(ll i = (ll)(a-1); i >= (ll)0; i--)
#define rrep3(i, a, b)    for(ll i = (ll)(a-1); i >=(b); i--)
#define rrep4(i, a, b, c) for(ll i = (ll)(a-1); i >=(b); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define rep1(a)          for(ll i = 0; i < (ll)(a); i++)
#define rep2(i, a)       for(ll i = 0; i < (ll)(a); i++)
#define rep3(i, a, b)    for(ll i = (a); i < (ll)(b); i++)
#define rep4(i, a, b, c) for(ll i = (a); i < (ll)(b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define fi first
#define se second
#define pb push_back
#define spa " "

//！？！？
#define O print

inline void scan(){}
template<class Head,class... Tail>
inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)

#pragma GCC diagnostic ignored "-Wunused-value"
void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}
#pragma GCC diagnostic warning "-Wunused-value"

int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19

#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, rank, fixedRoot;
    
    UnionFind(int n) : parent(n), rank(n, 0), fixedRoot(n, -1) {
        iota(parent.begin(), parent.end(), 0);  // 各要素は最初自分自身が根
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);  // 経路圧縮
    }

    void initialMerge(int u, int v, int x) {
        int rootU = find(u);
        int rootV = find(v);
        int rootX = find(x);

        if (rootU == rootV) return; // 既に同じグループなら何もしない

        // `x` を強制的に新しい根とする
        parent[rootU] = rootX;
        parent[rootV] = rootX;
        fixedRoot[rootX] = x;  // `x` を固定根に設定
    }

    void merge(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return; // すでに同じグループなら何もしない

        // 固定された根があるかチェック
        if (fixedRoot[rootU] != -1 && fixedRoot[rootV] == -1) {
            parent[rootV] = rootU;  // `rootU` を根として維持
        } else if (fixedRoot[rootV] != -1 && fixedRoot[rootU] == -1) {
            parent[rootU] = rootV;  // `rootV` を根として維持
        } else if (fixedRoot[rootU] != -1 && fixedRoot[rootV] != -1) {
            // 両方固定済みなら何もしない（またはエラー）
        } else {
            // どちらも未固定なら通常の Union-Find のルール
            if (rank[rootU] < rank[rootV]) swap(rootU, rootV);
            parent[rootV] = rootU;
            if (rank[rootU] == rank[rootV]) rank[rootU]++;
        }
    }

    int getRoot(int x) {
        int root = find(x);
        return fixedRoot[root] != -1 ? fixedRoot[root] : root;
    }

    bool connecter(int u, int v) {
        return find(u) == find(v);
    }
};


class solve{
  public:
    ll city_num = 800;
    ll group_num;
    ll query_num = 400;
    ll query_max_size;
    ll city_max_size;

    vector<ll> group_size;

    vector<pll> left;
    vector<pll> right;

    vector<tuple<ll,ll,ll>> city_center_point;
    vector<vector<pll>> city_distance;

    vector<vector<ll>> group;
    vector<vector<pll>> group_vertex;

    vector<pll> test_edge;
    vector<bool> used;


    void input(){
        cin >> city_num >> group_num >> query_num >> query_max_size >> city_max_size;

        group_size.resize(group_num);
        group.resize(group_num);
        group_vertex.resize(group_num);
        
        left.resize(city_num);
        right.resize(city_num);
        test_edge.resize(city_num);
        used.resize(city_num, false);

        city_center_point.resize(city_num);
        city_distance.resize(city_num);

        rep(group_num) cin >> group_size[i];
        rep(city_num) cin >> left[i].fi >> right[i].fi >> left[i].se >> right[i].se;

        rep(city_num) city_center_point[i] = {(left[i].fi + right[i].fi)/2, (left[i].se + right[i].se)/2, (right[i].fi - left[i].fi)*(right[i].se - right[i].se)};

        rep(i,city_num){
            rep(j,i+1,city_num){
                if(i == j) continue;
                ll distance = pow((get<0>(city_center_point[i]) - get<0>(city_center_point[j])),2) + pow(get<1>(city_center_point[i]) - get<1>(city_center_point[j]), 2);
                city_distance[i].pb({distance, j});
            }
            sort(city_distance[i].begin(), city_distance[i].end());
        }
    }

    void test_input(){
        rep(city_num){
            cin >> test_edge[i].fi >> test_edge[i].se;
        }
    }

    void make_first_answer() {
        vector<ll> assigned(city_num, -1);
        ll group_index = 0;
        rep(i, city_num) {
            if (assigned[i] != -1) continue;
            if (group_index >= group_num) break;
            queue<ll> q;
            q.push(i);
            group[group_index].pb(i);
            assigned[i] = group_index;

            while (!q.empty() && group[group_index].size() < group_size[group_index]) {
                ll u = q.front();
                q.pop();
                for (auto [dist, v] : city_distance[u]) {
                    if (assigned[v] == -1) {
                        assigned[v] = group_index;
                        group[group_index].pb(v);
                        q.push(v);
                        if (group[group_index].size() == group_size[group_index]) break;
                    }
                }
            }
            group_index++;
        }
    }

    void make_first_answer_(){
        UnionFind uf(city_num);
        priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq;
        priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq2;
        rep(city_num){
            rep(j,i+1,city_num){
                ll distance = pow((get<0>(city_center_point[i]) - get<0>(city_center_point[j])),2) + pow(get<1>(city_center_point[i]) - get<1>(city_center_point[j]), 2);
                pq.push({distance, i, j});
            }
        }

        pq2 = pq;

        map<ll, ll> group_idx;
        vector<vector<ll>> group_list(group_num);

        int cnt = city_num;

        rep(group_num){
            if(group_size[i] == 1){
                cnt--;
                continue;
            }
            while(!pq.empty()){
                auto [dist, u, v] = pq.top();
                pq.pop();
                if(used[u] || used[v]){
                    if(used[v]) swap(u, v);
                    if(group_merge(uf.getRoot(u), u, v, group_idx, group_list)){
                        cnt--;
                        uf.merge(u, v);
                    }
                    continue;
                }
                uf.initialMerge(u, v, u);
                group_idx[u] = i;
                group_list[i].pb(u);
                group_list[i].pb(v);
                used[u] = true;
                used[v] = true;
                cnt -= 2;
                break;
            }
        }

        pq = pq2;

        while(!pq.empty()){
            auto [dist, u, v] = pq.top();
            pq.pop();
            if(used[v]) swap(u, v);
            if(group_merge(uf.getRoot(u), u, v, group_idx, group_list)){
                cnt--;
                uf.merge(u, v);
            }
            if(cnt == 0) break;
        }


        rep(i, group_num) {
            if(group_size[i] == 1) continue;
            rep(j, group_list[i].size()) {
                group[i].pb(group_list[i][j]);
            }
        }
    }

    bool group_merge(int r, int u, int v, map<ll,ll>& group_idx, vector<vector<ll>>& group_list){
        if(used[u] == used[v]) return false;
        int idx = group_idx[r];
        if(group_list[idx].size() == group_size[idx]) return false;
        group_list[idx].pb(v);
        used[u] = true;
        used[v] = true;
        return true;
    }

    void make_second_answer(){
        rep(group.size()){
            if(group[i].size() == 1) continue;
            int tmp = 0;
            while(true){
                if(tmp + 1 >= group[i].size()) break;
                vector<ll> edge_list(min(query_max_size, (ll)group[i].size() - tmp));
                rep(j,edge_list.size()){
                    edge_list[j] = group[i][tmp+j];
                }
                cout << '?' << spa << edge_list.size() << spa;
                rep(j,edge_list.size()){
                    cout << edge_list[j] << spa;
                }
                cout << endl;
                rep(j,edge_list.size() - 1){
                    int u,v;
                    cin >> u >> v;
                    group_vertex[i].pb({u,v});
                }
                tmp += edge_list.size()-1;
            }
        }
    }

    void make_second_answer_test(){
        rep(group.size()){
            if(group[i].size() == 1) continue;
            int tmp = 0;
            while(true){
                if(tmp + 1 >= group[i].size()) break;
                vector<ll> edge_list(min(query_max_size, (ll)group[i].size() - tmp));
                cout << "? " << edge_list.size() << spa;
                rep(j,edge_list.size()){
                    cout << group[i][tmp+j] << spa;
                    edge_list[j] = group[i][tmp+j];
                }
                cout << endl;
                vector<pll> ret = test_kruskal(edge_list);
                rep(j,ret.size()){
                    group_vertex[i].pb(ret[j]);
                }
                tmp += edge_list.size()-1;
            }
        }
    }

    vector<pll> test_kruskal(vector<ll> edge_list){
        UnionFind uf(city_num + 1);
        priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq;
        rep(edge_list.size()){
            rep(j,edge_list.size()){
                if(i == j) continue;
                ll distance = pow((test_edge[edge_list[i]].fi - test_edge[edge_list[j]].fi),2) + pow(test_edge[edge_list[i]].se - test_edge[edge_list[j]].se, 2);
                pq.push({distance, edge_list[i], edge_list[j]});
            }
        }
        vector<pll> ret;
        while(!pq.empty()){
            auto [dist, u, v] = pq.top();
            pq.pop();
            if(uf.connecter(u,v)) continue;
            uf.merge(u,v);
            ret.pb({u,v});
        }
        return ret;
    }

    void answer(){
        vector<bool> use(city_num, false);
        cout << '!' << endl;
        rep(i,group_num){
            //if(group_size[i] != 1 && (group[i].size() != group_size[i])) cout << "error" << spa;
            //cout << spa << group_size[i] << spa << group[i].size() << endl;
            if(group_size[i] == 1){
                rep(j,city_num){
                    if(used[j]) continue;
                    else{
                        cout << j << endl;
                        used[j] = true;
                        use[j] = true;
                        break;
                    }
                }
            }else{
                rep(j,group[i].size()){
                    cout << group[i][j] << spa;
                    use[group[i][j]] = true;
                }
                cout << endl;
                rep(j,group_vertex[i].size()){
                    cout << group_vertex[i][j].fi << spa << group_vertex[i][j].se << endl;
                }
            }
        }
        rep(i,city_num){
            if(!use[i]){
                cout << "error" << spa;
                cout << i << endl;
            }
        }
    }
};

int main(){
    solve s;
    s.input();
    //s.test_input();
    //s.make_first_answer();
    s.make_first_answer_();
    s.make_second_answer();
    //s.make_second_answer_test();
    s.answer();
}