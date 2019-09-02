#include <bits/stdc++.h>
#define OPPO(no) 1^no
using namespace std;

struct Role {
    int health;
    int attack;
    Role(int health, int attack): health(health), attack(attack) {}
};

vector<Role> player[2] = {{Role(30,0)}, {Role(30,0)}};

void remove_role(int no, int pos) {
    player[no].erase(player[no].begin() + pos);
}

int main() {
    int no = 0;
    int n;

    cin >> n;
    while (n--) {
        string action;
        cin >> action;
        if (action == "summon") {
            int position, attack, health;
            cin >> position >> attack >> health;
            player[no].insert(player[no].begin() + position, Role(health, attack));
        } else if (action == "attack") {
            int attacker, defender;
            cin >> attacker >> defender;
            // attack each other
            player[no][attacker].health -= player[OPPO(no)][defender].attack;
            player[OPPO(no)][defender].health -= player[no][attacker].attack;
            // remove if dead
            if (player[no][attacker].health <= 0 && attacker != 0) {
                remove_role(no, attacker);
            }
            if (player[OPPO(no)][defender].health <= 0 && defender != 0) {
                remove_role(OPPO(no), defender);
            }
        } else if (action == "end") {
            no = OPPO(no);
        }
    }

    if (player[0][0].health > 0 && player[1][0].health > 0) {
        puts("0");
    } else if (player[0][0].health > 0 && player[1][0].health <= 0) {
        puts("1");
    } else if (player[0][0].health <= 0 && player[1][0].health > 0) {
        puts("-1");
    }
    
    for (int i = 0; i < 2; ++i) {
        cout << player[i][0].health << endl;
        cout << player[i].size() - 1;
        for (int j = 1; j < player[i].size(); ++j) {
            cout << " " << player[i][j].health;
        }
        cout << endl;
    }

    return 0;
}