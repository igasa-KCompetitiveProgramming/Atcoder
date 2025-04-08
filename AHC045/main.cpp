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

clock_t start;

class UnionFind{
    public:
    UnionFind() = default;

    explicit UnionFind(size_t n) : m_parents(n){
        iota(m_parents.begin(), m_parents.end(), 0);
    }

    ll root(ll i){
        if(m_parents[i] == i) return i;
        return(m_parents[i] = root(m_parents[i]));
    }

    void merge(ll a,ll b){
        a = root(a);
        b = root(b);
        if(a != b) m_parents[b] = a;
    }

    bool connecter(ll a,ll b){
        return root(a) == root(b);
    }
    private:
    vector<ll> m_parents;
};

class solve{
  public:
    ll city_num = 800;
    ll group_num;
    ll query_num = 400;
    ll query_max_size;
    ll city_max_size;

    ll max_rectangle_size = 0;

    vector<ll> group_size;

    vector<pll> left;
    vector<pll> right;

    vector<tuple<ll,ll,ll>> city_center_point;
    vector<vector<pll>> city_distance;

    vector<vector<ll>> group;
    vector<vector<pll>> group_vertex;
    vector<ll> assigned;

    vector<pll> test_edge;

    void input(){
        cin >> city_num >> group_num >> query_num >> query_max_size >> city_max_size;

        group_size.resize(group_num);
        group.resize(group_num);
        group_vertex.resize(group_num);
        
        left.resize(city_num);
        right.resize(city_num);
        test_edge.resize(city_num);

        city_center_point.resize(city_num);
        city_distance.resize(city_num);

        rep(group_num) cin >> group_size[i];
        rep(city_num) cin >> left[i].fi >> right[i].fi >> left[i].se >> right[i].se;

        rep(city_num) city_center_point[i] = {(left[i].fi + right[i].fi)/2, (left[i].se + right[i].se)/2, (right[i].fi - left[i].fi)*(right[i].se - right[i].se)};
        rep(city_num) max_rectangle_size = max(max_rectangle_size, (right[i].fi - left[i].fi)*(right[i].se - right[i].se));

        rep(i,city_num){
            rep(j,city_num){
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

    void make_first_answer(vector<ll> group_order) {
        assigned.resize(city_num, -1);
        for (ll gi = 0; gi < group_num; ++gi) {
            ll group_index = group_order[gi];
            ll n = group_size[group_index];
    
            // 各都市の密集度（近い順にn個までの距離の総和）
            vector<pair<ll, ll>> city_density; // {密集度, city_id}
            rep(i, city_num) {
                if (assigned[i] != -1) continue;
                ll sum = 0;
                ll cnt = 0;
                for (auto [dist, v] : city_distance[i]) {
                    if (assigned[v] != -1) continue;
                    sum += dist;
                    cnt++;
                    if (cnt == n) break;
                }
                city_density.emplace_back(sum, i);
            }
    
            // 密集度が小さい順にソート（＝密集している）
            sort(city_density.begin(), city_density.end());
    
            // 密集している都市からBFS開始
            for (auto [_, i] : city_density) {
                if (assigned[i] != -1) continue;
    
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
                break; // このグループは埋まったので次へ
            }
        }
    }
    
    
    int Kruskal(vector<ll> edge_list){
        UnionFind uf(city_num + 1);
        priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq;
        rep(i,edge_list.size()){
            rep(j,edge_list.size()){
                if(i == j) continue;
                pll a = {get<0>(city_center_point[edge_list[i]]), get<1>(city_center_point[edge_list[i]])};
                pll b = {get<0>(city_center_point[edge_list[j]]), get<1>(city_center_point[edge_list[j]])};
                ll distance = pow((a.fi - b.fi),2) + pow(a.se - b.se, 2);
                pq.push({distance, edge_list[i], edge_list[j]});
            }
        }
        ll ret = 0;
        while(!pq.empty()){
            auto [dist, u, v] = pq.top();
            pq.pop();
            if(uf.connecter(u,v)) continue;
            uf.merge(u,v);
            ret+=dist;
        }
        return ret;
    }

    void improve_first_answer(){
        int i = 0;
        vector<vector<ll>> minimum_answer;
        ll minimum_distance = INF;
        // グループを group_size の大きい順に処理
        vector<ll> group_order(group_num);
        iota(group_order.begin(), group_order.end(), 0);
        sort(group_order.begin(), group_order.end(), [&](ll a, ll b) {
            return group_size[a] > group_size[b];
        });
        ll ii;
        ll jj;
        while(clock() - start < 1.6 * CLOCKS_PER_SEC){
            make_first_answer(group_order);
            ll total_distance = 0;
            rep(i, group_num) {
                total_distance += Kruskal(group[i]);
            }
            if (total_distance < minimum_distance) {
                minimum_distance = total_distance;
                minimum_answer = group;
            }else swap(group_order[ii], group_order[jj]);
            // グループを1点変更
            while(clock() - start < 1.6 * CLOCKS_PER_SEC){
                ii = rand() % group_num;
                jj = rand() % group_num;
                ll ai = group_order[ii];
                ll aj = group_order[jj];
                if(ai == aj) continue;
                if(group_size[ai] == group_size[aj]) continue;
                if(group_size[ai] == 1 || group_size[aj] == 1) continue;
                swap(group_order[ii], group_order[jj]);
                break;
            }
            if(clock() - start > 1.6 * CLOCKS_PER_SEC) break;
            // グループを再構築
            for (ll i = 0; i < group_num; ++i) {
                group[i].clear();
            }
            assigned.assign(city_num, -1);
        }
        group = minimum_answer;
    }
    

    void make_second_answer(){
        vector<ll> answer;
        rep(group.size()){
            vector<bool> used(group[i].size(), false);
            vector<tuple<ll,ll,ll>> edges_list(group[i].size());
            rep(j,group[i].size()){
                auto[x, y, z] = city_center_point[group[i][j]];
                edges_list[j] = {x, y, group[i][j]};
            }
            sort(edges_list.begin(), edges_list.end());
            priority_queue<tuple<ll,ll,ll,ll>,vector<tuple<ll,ll,ll,ll>>,greater<tuple<ll,ll,ll,ll>>> pq;
            int see = 0;
            answer.pb(get<2>(edges_list[0]));
            used[see] = true;
            rep(j,edges_list.size()){
                if(used[j]) continue;
                ll x = get<0>(edges_list[see]);
                ll y = get<1>(edges_list[see]);
                ll index = get<2>(edges_list[j]);
                ll distance = pow((x - get<0>(edges_list[j])),2) + pow(y - get<1>(edges_list[j]), 2);
                pq.push({distance, see, j, index});
            }
            while(!pq.empty()){
                auto [dist, u, v, index] = pq.top();
                pq.pop();
                if(used[v]) continue;
                used[v] = true;
                answer.pb(index);
                rep(j,edges_list.size()){
                    if(used[j]) continue;
                    ll x = get<0>(edges_list[v]);
                    ll y = get<1>(edges_list[v]);
                    ll distance = pow((x - get<0>(edges_list[j])),2) + pow(y - get<1>(edges_list[j]), 2);
                    pq.push({distance, v, j, get<2>(edges_list[j])});
                }
            }
            group[i] = answer;
            answer.clear();
        }
    }

    void make_third_answer(){
        rep(group.size()){
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

    void make_third_answer_test(){
        rep(group.size()){
            int tmp = 0;
            while(true){
                if(tmp + 1 >= group[i].size()) break;
                vector<ll> edge_list(min(query_max_size, (ll)group[i].size() - tmp));
                rep(j,edge_list.size()){
                    //cout << tmp + j << endl;
                    edge_list[j] = group[i][tmp+j];
                }
                //cout << endl;
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
        cout << '!' << endl;
        rep(i,group_num){
            rep(j,group[i].size()){
                cout << group[i][j] << spa;
            }
            cout << endl;
            rep(j,group_vertex[i].size()){
                cout << group_vertex[i][j].fi << spa << group_vertex[i][j].se << endl;
            }
        }
    }
};

void test(){
    solve s;
    s.input();
    s.test_input();
    s.improve_first_answer();
    s.make_second_answer();
    s.make_third_answer_test();
    s.answer();
}

void submit(){
    solve s;
    s.input();
    s.improve_first_answer();
    s.make_second_answer();
    s.make_third_answer();
    s.answer();
}

int main(){
    start = clock();
    //test();
    submit();
}