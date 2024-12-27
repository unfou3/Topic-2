#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
#include <stdio.h>
#include <stdbool.h>

using namespace std;

int n, m;
vector<vector<int>> a;
vector<int> color;

void color_g(int u, int v, FILE* fout) {
    if (u > 0 && u <= 100) {
        fprintf(fout, "%d [fillcolor=aliceblue, style=filled];\n", v);
    } else if (u > 100 && u <= 200) {
        fprintf(fout, "%d [fillcolor=midnightblue, style=filled];\n", v);
    } else if (u > 200 && u <= 300) {
        fprintf(fout, "%d [fillcolor=springgreen1, style=filled];\n", v);
    } else if (u > 300 && u <= 400) {
        fprintf(fout, "%d [fillcolor=aqua, style=filled];\n", v);
    } else if (u > 400 && u <= 500) {
        fprintf(fout, "%d [fillcolor=yellow, style=filled];\n", v);
    } else if (u > 500 && u <= 600) {
        fprintf(fout, "%d [fillcolor=IndianRed1, style=filled];\n", v);
    } else if (u > 600 && u <= 700) {
        fprintf(fout, "%d [fillcolor=Firebrick1, style=filled];\n", v);
    } else if (u > 700 && u <= 800) {
        fprintf(fout, "%d [fillcolor=DarkOrange, style=filled];\n", v);
    } else if (u > 800 && u <= 900) {
        fprintf(fout, "%d [fillcolor=Red1, style=filled];\n", v);
    } else if (u > 900 && u <= 1000) {
        fprintf(fout, "%d [fillcolor=DeepPink1, style=filled];\n", v);
    } else if (u > 1000 && u <= 1100) {
        fprintf(fout, "%d [fillcolor=PaleVioletRed, style=filled];\n", v);
    } else if (u > 1100 && u <= 1200) {
        fprintf(fout, "%d [fillcolor=Magenta2, style=filled];\n", v);
    } else if (u > 1200 && u <= 1300) {
        fprintf(fout, "%d [fillcolor=MediumVioletRed, style=filled];\n", v);
    } else if (u > 1300 && u <= 1400) {
        fprintf(fout, "%d [fillcolor=gold, style=filled];\n", v);
    } else if (u > 1400) {
        fprintf(fout, "%d [fillcolor=DarkCyan, style=filled];\n", v);
    }
}
//check x i co phai canh ke hay khong de to mau

bool check(int x, int t) {
    for (int i = 1; i <= n; i++) {
        if (color[i] == t && a[x][i] == 1) {
            return false;
        }
    }
    return true;
}
//kiểm tra xem có bao nhiêu đỉnh có thể tô được màu t rồi tô màu t
int dinh_max(int t) {
    int dem = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0 && check(i, t)) {
            color[i] = t;
            dem++;
        }
    }
    return dem;
}

void makefdot() {
    ifstream fin("dothi.txt");
    if (!fin) {
        cout << "Khong the mo file." << endl;
        return;
    }

    fin >> n >> m;
    a.resize(n + 1, vector<int>(n + 1, 0));
    color.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        fin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    fin.close();

    int sl = 0, col = 1;
    while (sl < n) {
        sl += dinh_max(col++);
    }

    FILE* fout = fopen("dothitomau.dot", "w");
    if (fout == NULL) {
        cout << "Khong the mo file output." << endl;
        return;
    }

    fprintf(fout, "graph dothi\n{\n");
    for (int i = 1; i <= n; i++) {
        color_g(color[i], i, fout);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] == 1) {
                fprintf(fout, "%d -- %d;\n", i, j);
            }
        }
    }

    fprintf(fout, "}\n");
    fclose(fout);
}