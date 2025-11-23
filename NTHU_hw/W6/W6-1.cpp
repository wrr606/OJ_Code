#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

constexpr int n = 6;

inline bool check(const int &a, const int &b){
    if(0 > a || a >= n || 0 > b || b >= n)
        return 0;
    return 1;
}

class Car{
public:
    int id;
    pii start, end;
    bool dir;
};
int cars_number = 0;

class State{
public:
    int cnt;
    vvi mp;
    vector<Car> cars;
    State(int cnt, vvi mp, vector<Car> cars): cnt(cnt), mp(mp), cars(cars){}
};
State init_State(0, vvi(n, vi(n)), vector<Car>());
set<vvi> visited;

int BFS(){
    queue<State> que;
    que.emplace(init_State), visited.emplace(init_State.mp);
    while(que.size()){
        auto [cnt, mp, cars] = move(que.front());
        que.pop();
        if(cnt >= 10)
            continue;
        int obstacle = count_if(mp[2].begin() + cars[0].end.second + 1, mp[2].end(), [](const int &a){
            return a != 0;
        });
        if(!obstacle){
            int t = n - cars[0].start.second;
            if(cnt + t <= 10)
                return cnt + t;
        }
        for(auto &car: cars){
            if(car.dir == 0){
                if(check(car.end.first, car.end.second + 1) && !mp[car.end.first][car.end.second + 1]){
                    swap(mp[car.end.first][car.end.second + 1], mp[car.start.first][car.start.second]);
                    ++car.start.second, ++car.end.second;
                    if(!visited.count(mp)){
                        visited.emplace(mp);
                        que.emplace(cnt + 1, mp, cars);
                    }
                    --car.start.second, --car.end.second;
                    swap(mp[car.end.first][car.end.second + 1], mp[car.start.first][car.start.second]);
                }
                if(check(car.start.first, car.start.second - 1) && !mp[car.start.first][car.start.second - 1]){
                    swap(mp[car.end.first][car.end.second], mp[car.start.first][car.start.second - 1]);
                    --car.start.second, --car.end.second;
                    if(!visited.count(mp)){
                        visited.emplace(mp);
                        que.emplace(cnt + 1, mp, cars);
                    }
                    ++car.start.second, ++car.end.second;
                    swap(mp[car.end.first][car.end.second], mp[car.start.first][car.start.second - 1]);
                }
            }
            else{
                if(check(car.end.first + 1, car.end.second) && !mp[car.end.first + 1][car.end.second]){
                    swap(mp[car.end.first + 1][car.end.second], mp[car.start.first][car.start.second]);
                    ++car.start.first, ++car.end.first;
                    if(!visited.count(mp)){
                        visited.emplace(mp);
                        que.emplace(cnt + 1, mp, cars);
                    }
                    --car.start.first, --car.end.first;
                    swap(mp[car.end.first + 1][car.end.second], mp[car.start.first][car.start.second]);
                }
                if(check(car.start.first - 1, car.start.second) && !mp[car.start.first - 1][car.start.second]){
                    swap(mp[car.end.first][car.end.second], mp[car.start.first - 1][car.start.second]);
                    --car.start.first, --car.end.first;
                    if(!visited.count(mp)){
                        visited.emplace(mp);
                        que.emplace(cnt + 1, mp, cars);
                    }
                    ++car.start.first, ++car.end.first;
                    swap(mp[car.end.first][car.end.second], mp[car.start.first - 1][car.start.second]);
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    init_State.cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>init_State.mp[i][j];
        cars_number = max(cars_number, *max_element(all(init_State.mp[i])));
    }
    init_State.cars.resize(cars_number);
    for(int idx=0;idx<cars_number;idx++){
        auto &car = init_State.cars[idx];
        car.id = idx + 1;
        vector<pii> t;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(init_State.mp[i][j] == car.id)
                    t.emplace_back(i, j);
            }
        }
        car.start = t[0], car.end = t.back();
        car.dir = (car.start.first == car.end.first) ? 0 : 1;
    }
    if(init_State.cars[0].dir || init_State.cars[0].end.first != 2){
        cout<<-1;
        return 0;
    }
    cout<<BFS();
}