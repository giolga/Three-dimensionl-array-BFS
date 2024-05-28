#include <bits/stdc++.h>
using namespace std;

struct ugra{ int l, r, c, step; };
queue <ugra> q;

ugra qin, qout;
int dr[4] = {1, -1,  0, 0}; //S,N,W,E
int dc[4] = {0,  0, -1, 1};

int l1, r1, c1, l2, r2, c2;
int layer,rowz, colz, newl, newr, newc, stepz;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true) {
        int l, r, c;
        cin >> l >> r >> c;
        if(l == r && r == c && c == 0) break;

        int board3D[l+1][r+1][c+1] = {0};
        char underGround[l+1][r+1][c+1] = {' '};
        

        for(int k = 1; k <= l; k++) 
            for(int i = 1; i <= r; i++) 
                for(int j = 1; j <= c; j++) 
                    board3D[k][i][j] = -1;

        for(int k = 1; k <= l; k++) 
            for(int i = 1; i <= r; i++) 
                for(int j = 1; j <= c; j++) {
                    cin >> underGround[k][i][j];
                    if(underGround[k][i][j] == 'S') {
                        l1 = k;
                        r1 = i;
                        c1 = j;
                        board3D[k][i][j] = 0;
                        continue;
                    }
                    if(underGround[k][i][j] == 'E') {
                        l2 = k;
                        r2 = i;
                        c2 = j;
                        continue;
                    }
                    if(underGround[k][i][j] == '#') {
                        board3D[k][i][j] = -5;
                        continue;
                    }

                }

        qin.step = 0;
        qin.l = l1;
        qin.r = r1;
        qin.c = c1;
        q.push(qin);

        while(!q.empty()) {
            qout = q.front();
            q.pop();
            stepz = qout.step + 1;
            layer = qout.l;
            rowz = qout.r;
            colz = qout.c;

            if(layer - 1 >= 1) {
                if(board3D[layer - 1][rowz][colz] == -1) {
                    board3D[layer - 1][rowz][colz] = stepz;
                    qin.l = layer - 1;
                    qin.r = rowz;
                    qin.c = colz;
                    qin.step = stepz;
                    q.push(qin);
                    // cout << rowz << " " << colz << " " << stepz << " \t layer" << layer - 1<< " \n";
                }
            }

            if(layer + 1 <= l) {
                if(board3D[layer + 1][rowz][colz] == -1) {
                    board3D[layer + 1][rowz][colz] = stepz;
                    qin.l = layer + 1;
                    qin.r = rowz;
                    qin.c = colz;
                    qin.step = stepz;
                    q.push(qin);
                    // cout << rowz << " " << colz << " " << stepz << " \t layer" << layer + 1 << " \n";
                }
            }
            
            for(int i = 0; i < 4; i++) {
                    newr = rowz + dr[i];
                    newc = colz + dc[i];

                    if(newr >= 1 && newr <= r && newc >= 1 && newc <= c) {
                        if(board3D[layer][newr][newc] == -1) {
                            board3D[layer][newr][newc] = stepz;
                            qin.l = layer;
                            qin.r = newr;
                            qin.c = newc;
                            qin.step = stepz;
                            q.push(qin);

                            // cout << newr << " " << newc << " " << stepz << " \t layer" << layer << " \n";
                        }
                    }
            }

        }

        if(board3D[l2][r2][c2] > 0) cout << "Escaped in " << board3D[l2][r2][c2] << " minute(s)." << endl;
        else cout << "Trapped!\n";

    }

    return 0;
}