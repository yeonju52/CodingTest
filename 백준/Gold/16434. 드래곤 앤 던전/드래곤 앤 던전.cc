#include <iostream>
#include <vector>
using namespace std;

int N, atk;

typedef long long ll;
struct tah {
    int t, a, h;
};
vector<tah> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> atk;
    for (int i = 0; i < N; i++) {
        int t, a, h;
        cin >> t >> a >> h;
        arr.push_back({ t, a, h });
    }

    ll st = 1, ed = 1000000LL * 1000000LL * N, mid, ans;
    while(st <= ed) {
        mid = st + ((ed - st) / 2);
        ll i_hp = mid, i_atk = atk;
        for (auto &cur : arr) {
            if (cur.t == 1) {
                i_hp -= cur.a * (cur.h / i_atk); // 소수점 버리기 (죽은 몬스터 취급)
                if (cur.h % i_atk == 0) i_hp += cur.a; // 죽은 몬스터는 공격하지 못함
            }
            else {
                i_atk += cur.a, i_hp = min(mid, i_hp + cur.h);
            }
            if (i_hp <= 0) break;
        }
        if (i_hp > 0) { // 정답
            ed = mid - 1;
            ans = mid;
        }
        else {
            st = mid + 1;
        }
    }
    cout << ans;
}