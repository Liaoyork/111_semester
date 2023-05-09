#include <cstdlib>
#include <iostream>

using namespace std;

void I_randomArray(int[5][7]);
void randomArray(char p[2][5][7]);
// void printfArray (int [5][7]);
void growingPlant(int[5][7], int[5][7], int[5][7]);
void printfArray(char[2][5][7], int[5][7]);
int wateringPlant(int[5][7], int, int);
enum vegetable { T,
                 C,
                 W,
                 S,
                 P,
                 Y,
                 G };

int main() {
    int growedPlant[5][7] = {0};
    char p1[2][5][7];
    int patch[5][7];
    int I_patch[5][7] = {0};
    int x = 0, y = 0;

    I_randomArray(patch);
    randomArray(p1);
    //	printfArray(p1, growedPlant);
    while (1) {
        cin >> x >> y;

        wateringPlant(I_patch, x, y);

        if (x == -1 && y == -1)
            break;
        else {
            growingPlant(patch, growedPlant, I_patch);
            printfArray(p1, growedPlant);
        }
    }

    return 0;
}
void I_randomArray(int p[5][7]) {
    int i = 0, j = 0;
    int temp;
    int counter[7] = {0};

    srand(0);

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 7; j++) {
            do {
                temp = rand() % 7;
            } while (counter[temp] >= 5);
            switch (temp) {
                case T:
                    p[i][j] = T;
                    break;
                case C:
                    p[i][j] = C;
                    break;
                case W:
                    p[i][j] = W;
                    break;
                case S:
                    p[i][j] = S;
                    break;
                case P:
                    p[i][j] = P;
                    break;
                case Y:
                    p[i][j] = Y;
                    break;
                case G:
                    p[i][j] = G;
                    break;
            }
            counter[temp]++;
        }
    }
}
void growingPlant(int p[5][7], int gP[5][7], int I_p[5][7]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            switch (p[i][j]) {
                case T:
                    gP[i][j] = 2 * I_p[i][j] / 3;
                    break;
                case C:
                    gP[i][j] = 2 * I_p[i][j] / 3;
                    break;
                case W:
                    gP[i][j] = 4 * I_p[i][j] / 9;
                    break;
                case S:
                    gP[i][j] = 2 * I_p[i][j] / 3;
                    break;
                case P:
                    gP[i][j] = 4 * I_p[i][j] / 3;
                    break;
                case Y:
                    gP[i][j] = 4 * I_p[i][j] / 3;
                    break;
                case G:
                    gP[i][j] = 4 * I_p[i][j] / 3;
                    break;
            }
        }
    }
}
void randomArray(char p[][5][7]) {
    int i = 0, j = 0;
    int temp;
    int counter[7] = {0};

    srand(0);

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 7; j++) {
            do {
                temp = rand() % 7;
            } while (counter[temp] >= 5);
            switch (temp) {
                case T:
                    p[0][i][j] = 't';
                    p[1][i][j] = 'T';
                    break;
                case C:
                    p[0][i][j] = 'c';
                    p[1][i][j] = 'C';
                    break;
                case W:
                    p[0][i][j] = 'w';
                    p[1][i][j] = 'W';
                    break;
                case S:
                    p[0][i][j] = 's';
                    p[1][i][j] = 'S';
                    break;
                case P:
                    p[0][i][j] = 'p';
                    p[1][i][j] = 'P';
                    break;
                case Y:
                    p[0][i][j] = 'y';
                    p[1][i][j] = 'Y';
                    break;
                case G:
                    p[0][i][j] = 'g';
                    p[1][i][j] = 'G';
                    break;
            }
            counter[temp]++;
        }
    }
}

void printfArray(char p[][5][7], int gP[5][7]) {
    int count1, count2;

    for (int i = 0; i < 5; i++) {
        cout << "+---------------------------+" << endl;

        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 7; k++) {
                count1 = gP[i][k];
                count2 = gP[i][k];

                cout << "|";
                for (int l = 0; l < 2; l++) {
                    if (j == 0 && count1 > 0) {
                        cout << p[1][i][k];
                        count1--;
                    } else if (j == 0 && count1 <= 0) {
                        cout << p[0][i][k];
                    } else if (j == 1 && count2 > 2) {
                        cout << p[1][i][k];
                        count2--;
                    } else if (j == 1 && count2 <= 2) {
                        cout << p[0][i][k];
                    }
                    if (l < 1) cout << " ";
                }
            }
            cout << "|" << endl;
        }
    }
    cout << "+---------------------------+" << endl;
}

int wateringPlant(int I_patch[5][7], int x, int y) {
    if (x >= 1 && x <= 5 && y >= 1 && y <= 3) {
        for (int i = y - 1; i <= y + 1; i++) {
            for (int j = x - 1; j <= x + 1; j++) {
                I_patch[i][j]++;
            }
        }
    } else if (x == 0 && y == 0) {
        for (int i = y; i <= y + 1; i++) {
            for (int j = x; j <= x + 1; j++) {
                I_patch[i][j]++;
            }
        }
    } else if (x == 0 && y == 4) {
        for (int i = y - 1; i <= y; i++) {
            for (int j = x; j <= x + 1; j++) {
                I_patch[i][j]++;
            }
        }
    } else if (x == 6 && y == 0) {
        for (int i = y; i <= y + 1; i++) {
            for (int j = x - 1; j <= x; j++) {
                I_patch[i][j]++;
            }
        }
    } else if (x == 6 && y == 4) {
        for (int i = y - 1; i <= y; i++) {
            for (int j = x - 1; j <= x; j++) {
                I_patch[i][j]++;
            }
        }
    } else if (x >= 1 && x <= 5 && y == 0) {
        for (int i = y; i <= y + 1; i++) {
            for (int j = x - 1; j <= x + 1; j++) {
                I_patch[i][j]++;
            }
        }
    } else if (x >= 1 && x <= 5 && y == 4) {
        for (int i = y - 1; i <= y; i++) {
            for (int j = x - 1; j <= x + 1; j++) {
                I_patch[i][j]++;
            }
        }
    } else if (x == 0 && y <= 3 && y >= 1) {
        for (int i = y - 1; i <= y + 1; i++) {
            for (int j = x; j <= x + 1; j++) {
                I_patch[i][j]++;
            }
        }
    } else if (x == 6 && y <= 3 && y >= 1) {
        for (int i = y - 1; i <= y + 1; i++) {
            for (int j = x - 1; j <= x; j++) {
                I_patch[i][j]++;
            }
        }
    }
    return I_patch[5][7];
}
