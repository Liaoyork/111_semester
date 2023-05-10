#include <limits.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream in;
    in.open("1.in");
    string input;
    string ss = "";
    int block[10000];
    int num = 0;

    // read file
    while (getline(in, input)) {
        for (int i = 0; i < input.length(); i++) {
            while (isdigit(input[i])) {
                ss += input[i];
                i++;
            }
            if (ss == "")
                continue;
            else {
                block[num] = stoi(ss);
                num++;
                ss = "";
            }
        }
    }
    cout << num;
    // initialize the distance matrix
    int **distance = new int *[num];
    for (int i = 0; i < num; i++) {
        distance[i] = new int[num];
        for (int j = 0; j < num; j++) {
            distance[i][j] = INT_MAX;
        }
    }

    int big_layer = 1, small_layer = 1, now_num, now_pos = 1;
    now_num = 0;
    int ans = 0;
    int layer;
    int target_layer_num = 0;
    while (now_num <= num) {
        target_layer_num = 0;
        layer = 6 * pow(2, big_layer - 1);

        // find exit
        if (now_num + layer >= num) {
            if (block[now_num]) ans = now_num;
        }

        // cal the how much block in target layer
        for (int i = 1; i <= big_layer; i++) {
            if (i != big_layer) {
                target_layer_num += 6 * pow(2, i - 1) * i;
            } else {
                target_layer_num += small_layer * 6 * pow(2, i - 1);
            }
        }

        // first layer
        if (!block[now_num]) {
            now_num = now_num;
        } else if (small_layer == 1 && big_layer == 1) {
            // compare right
            if (block[(now_num + 7) % 6]) {
                distance[now_num][(now_num + 7) % 6] = block[(now_num + 7) % 6];
            }

            // left
            if (block[(now_num + 5) % 6]) {
                distance[now_num][(now_num + 5) % 6] = block[(now_num + 5) % 6];
            }

            // up
            if (block[(2 * now_num + 6)]) {
                distance[now_num][2 * now_num + 6] = block[2 * now_num + 6];
            }
            if (block[(2 * now_num + 7)]) {
                distance[now_num][2 * now_num + 7] = block[2 * now_num + 7];
            }
        } else {
            if (now_pos == layer) {
                if (block[now_num - layer + 1]) {
                    distance[now_num][now_num - layer + 1] = block[now_num - layer + 1];
                }
            } else {
                if (block[now_num + 1]) {
                    distance[now_num][now_num + 1] = block[now_num + 1];
                }
            }

            // left
            if (now_pos == 1) {
                if (block[now_num + layer - 1]) {
                    distance[now_num][now_num + layer - 1] = block[now_num + layer - 1];
                }
            } else {
                if (block[now_num - 1]) {
                    distance[now_num][now_num - 1] = block[now_num - 1];
                }
            }

            // up
            if (small_layer == big_layer) {
                if (now_num + layer < num) {
                    if (block[now_num + now_pos + layer]) {
                        distance[now_num][now_num + now_pos + layer] = block[now_num + now_pos + layer];
                    }
                    if (block[now_num + now_pos + layer - 1]) {
                        distance[now_num][now_num + now_pos + layer - 1] = block[now_num + now_pos + layer - 1];
                    }
                }

                // help next layer to connect down layer
                if (block[now_num] && now_num + layer + now_pos < num) {
                    if (block[now_num + now_pos + layer - 1]) {
                        distance[now_num + now_pos + layer - 1][now_num] = block[now_num];
                    }
                    if (block[now_num + now_pos + layer]) {
                        distance[now_num + now_pos + layer][now_num] = block[now_num];
                    }
                }
            } else {
                if (block[now_num + layer]) {
                    distance[now_num][now_num + layer] = block[now_num + layer];
                }
            }

            // down
            if (small_layer != 1) {
                if (block[now_num - layer]) {
                    distance[now_num][now_num - layer] = block[now_num - layer];
                }
            }
        }
        if (now_pos == layer) {
            if (now_num == target_layer_num - 1) {
                now_pos = 0;
                small_layer++;
            }
            if (small_layer > big_layer) {
                big_layer++;
                small_layer = 1;
                now_pos = 0;
            }
        }
        now_num++;
        now_pos++;
    }

    int pre[num];
    int ori_dis[num];

    for (int i = 0; i < num; i++) {
        if (i <= 6) {
            if (block[i]) {
                ori_dis[i] = block[i];
            } else {
                ori_dis[i] = INT_MAX;
            }
        }
    }

    bool find = false;

    for (int k = 0; k < 6; k++) {
        bool best[num];
        for (int i = 0; i < num; i++) {
            best[i] = false;
        }
        if (block[k]) {
            best[k] = true;
        } else {
            continue;
        }

        for (int i = k + 1; i < num; i++) {
            ori_dis[i] = distance[k][i];
            if (ori_dis[i] != INT_MAX) {
                pre[i] = k;
            } else {
                pre[i] = -1;
            }
        }

        for (int i = 0; i < num * num; i++) {
            int not_best = 0, num_not_best = INT_MAX;
            for (int j = k; j < num; j++) {
                if (!best[j]) {
                    if (num_not_best > ori_dis[j]) {
                        not_best = j;
                        num_not_best = ori_dis[j];
                    }
                }
            }
            best[not_best] = true;
            for (int j = k; j < num; j++) {
                if (!best[j]) {
                    if (distance[not_best][j] != INT_MAX) {
                        if (ori_dis[not_best] + distance[not_best][j] < ori_dis[j]) {
                            ori_dis[j] = ori_dis[not_best] + distance[not_best][j];
                            pre[j] = not_best;
                        }
                    }
                }
            }
        }
        if (ori_dis[ans] != INT_MAX) {
            int p = ans;
            find = true;
            vector<int> answer;
            answer.push_back(ans);
            while (p != 1) {
                answer.push_back(pre[p]);
                p = pre[p];
            }
            cout << k;
            for (long i = answer.size() - 2; i >= 0; i++) {
                cout << " -> " << answer[i];
            }

            break;
        }
    }

    if (!find) cout << "fail";
    // for (int i = 0; i < num; i++) {
    //     cout << ori_dis[i] << endl;
    // }

    return 0;
}