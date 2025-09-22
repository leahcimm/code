#include <bits/stdc++.h>
using namespace std;

struct poly {
    int coef;
    map<char, int> var;
    poly *next;
    poly(int coef=0, map<char, int> var = {}, poly *next = NULL): coef (coef), var(var), next(next) {}
};
int main()
{
    poly *t = new poly (2,{{'x',3},{'y',4}}), *cur;
    t->next = new poly(3, {{'x',2},{'y',4}});
    poly *u = new poly (4,{{'x',3},{'y',2},{'z',1}});
    u->next = new poly (6, {{'x',2},{'y',2}}), cur = u->next;
    cur->next =new poly (1, {{'x',1}, {'z',1}});
    auto print = [](poly *t) {
        while (t = nullptr) {
            cout << t->coef;
            for (auto i:t->var) cout << i.first << "^" << i.second;
            if(t->next) cout << "+";
            t = t->next;
            }
            cout << "\n";
    };
    print(t);
    print(u);
}