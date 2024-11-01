#include <stdio.h>
#include <stdbool.h>

int n, m;
int a[1001][1001];
int color[1001];
void color_g(int u, int v, FILE* fout) {
    if (u == 1) {
        fprintf(fout, "%d [fillcolor=aliceblue, style=filled];\n", v);
    } else if (u == 2) {
        fprintf(fout, "%d [fillcolor=midnightblue, style=filled];\n", v);
    } else if (u == 3) {
        fprintf(fout, "%d [fillcolor=springgreen1, style=filled];\n", v);
    } else if (u == 4) {
        fprintf(fout, "%d [fillcolor=aqua, style=filled];\n", v);
    } else if (u == 5) {
        fprintf(fout, "%d [fillcolor=yellow, style=filled];\n", v);
    } else if (u == 6) {
        fprintf(fout, "%d [fillcolor=IndianRed1, style=filled];\n", v);
    } else if (u == 7) {
        fprintf(fout, "%d [fillcolor=Firebrick1, style=filled];\n", v);
    } else if (u == 8) {
        fprintf(fout, "%d [fillcolor=DarkOrange, style=filled];\n", v);
    } else if (u == 9) {
        fprintf(fout, "%d [fillcolor=Red1, style=filled];\n", v);
    } else if (u == 10) {
        fprintf(fout, "%d [fillcolor=DeepPink1, style=filled];\n", v);
    } else if (u == 11) {
        fprintf(fout, "%d [fillcolor=PaleVioletRed, style=filled];\n", v);
    } else if (u == 12) {
        fprintf(fout, "%d [fillcolor=Magenta2, style=filled];\n", v);
    } else if (u == 13) {
        fprintf(fout, "%d [fillcolor=MediumVioletRed, style=filled];\n", v);
    } else if (u == 14) {
        fprintf(fout, "%d [fillcolor=gold, style=filled];\n", v);
    } else if (u == 15) {
        fprintf(fout, "%d [fillcolor=DarkCyan, style=filled];\n", v);
    }
}
//check x i co phai canh ke hay khong de to mau
bool check(int x, int t) {
    for (int i = 1; i <= n; i++) {
        if (color[i] == t && a[x][i] == 1) {
            return false; //khong the to mau t cua dinh i cho dinh x
        }
    }
    return true; //co the to mau t cho dinh x
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

int main() {
    FILE *fin;
    fin = fopen("dothi.txt", "r");

    if (fin == NULL) {
        printf("Khong the mo file.\n");
        return 1;
    }
    fscanf(fin, "%d %d", &n, &m);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        fscanf(fin, "%d %d", &x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    fclose(fin);

    for (int i = 1; i <= n; i++) {
        color[i] = 0;
    }

    int sl = 0, col = 1;
    while (sl < n) {
        sl += dinh_max(col++);
    }

    FILE *fout;
    fout = fopen("dothitomau.dot", "w");
    if (fout == NULL) {
        printf("Khong the mo file output.\n");
        return 1;
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

    return 0;
}

