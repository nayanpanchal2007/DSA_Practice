#include <bits/stdc++.h>
using namespace std;

int time_to_buy_tickets(vector<int> tickets, int k) {
    queue<int> q;

    for (int i = 0; i < tickets.size(); i++) {
        q.push(i);
    }

    int time = 0;

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        tickets[i]--;
        time++;

        if (i == k && tickets[i] == 0) return time;
        if (tickets[i] > 0) q.push(i);
    }

    return time;
}

int main() {
    cout << time_to_buy_tickets({5, 3, 2}, 2) << endl;
    cout << time_to_buy_tickets({5, 1, 1, 1}, 0) << endl;
    cout << time_to_buy_tickets({1, 1, 1}, 0) << endl;
    cout << time_to_buy_tickets({3, 4, 2, 1}, 2) << endl;
    cout << time_to_buy_tickets({1}, 0) << endl;
    return 0;
}