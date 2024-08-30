#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para calcular o máximo dano possível com a capacidade dada
int knapsack_max_damage(const vector<pair<int, int>>& projectiles, int capacity) {
    vector<int> dp(capacity + 1, 0);

    for (const auto& projectile : projectiles) {
        int power = projectile.first;
        int weight = projectile.second;
        // Atualizar o vetor dp de trás para frente para garantir que cada projétil seja considerado apenas uma vez
        for (int current_capacity = capacity; current_capacity >= weight; --current_capacity) {
            dp[current_capacity] = max(dp[current_capacity], dp[current_capacity - weight] + power);
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> projectiles(N);
        for (int i = 0; i < N; ++i) {
            int power, weight;
            cin >> power >> weight;
            projectiles[i] = make_pair(power, weight);
        }

        int K;
        cin >> K;

        int R;
        cin >> R;

        int max_damage = knapsack_max_damage(projectiles, K);

        if (max_damage >= R) {
            cout << "Missao completada com sucesso" << endl;
        } else {
            cout << "Falha na missao" << endl;
        }
    }

    return 0;
}