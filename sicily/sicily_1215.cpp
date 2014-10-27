#include <iostream>  
#include <queue>  
#include <map>  
#include <cstring>  
  
using namespace std;  
  
struct pos {  
    pos(int xx=0, int yy=0):x(xx),y(yy) {}  
    int x, y;  
};  
  
struct state {  
    state(pos p1, pos h1) {  
        p = p1;  
        h = h1;  
        step = 0;  
    }  
    pos p, h;  
    int step;  
};  
  
const int mov[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};  
const int N = 21;  
map<char,int> dir;      
int girl[4];    //Helen移动的方向  
char matrix[N][N];  
bool vis[N][N][N][N];  
int n, m;  
  
bool isOver(pos p)   
{  
    if (p.x >= 1 && p.x <= m && p.y >= 1 && p.y <= n)  
        return false;  
    return true;  
}  
  
int bfs(pos hh, pos pp)   
{      
    vis[pp.x][pp.y][hh.x][hh.y] = true;  
    queue<state> q;  
    q.push(state(pp,hh));  
  
    while (!q.empty()) {  
        state cur = q.front();    
        q.pop();  
        if (cur.step > 255)           
            break;        
  
        cur.step++;  
        for (int i = 0;i < 4; i++) {  
            pos _p, _h;  
            _p.x = cur.p.x + mov[i][0];  
            _p.y = cur.p.y + mov[i][1];  
            _h.x = cur.h.x + mov[girl[i]][0];  
            _h.y = cur.h.y + mov[girl[i]][1];     
      
            //这一步一定要先做判断！！！  
            if (matrix[_h.x][_h.y] == '#')  
                    _h = cur.h;  
  
            if (!isOver(_p) && !isOver(_h) && matrix[_p.x][_p.y] == '.' &&  
                !vis[_p.x][_p.y][_h.x][_h.y] && matrix[_h.x][_h.y] != '!') {                               
  
                vis[_p.x][_p.y][_h.x][_h.y] = true;                
                if ((_p.x == _h.x && _p.y == _h.y) || (_p.x == cur.h.x && _p.y == cur.h.y &&  
                    _h.x == cur.p.x && _h.y == cur.p.y))  
                    return cur.step;  
  
                state tmp(_p, _h);  
                tmp.step = cur.step;  
                q.push(tmp);  
            }  
        }  
    }     
    return -1;  
}  
int main()   
{  
//  freopen("input.txt","r",stdin);  
    dir['N'] = 0;  
    dir['S'] = 1;  
    dir['W'] = 2;  
    dir['E'] = 3;     
  
    while (cin >> n >> m) {  
        memset(vis, false, sizeof(vis));      
        int i, j;     
        pos p, h;  
        for (i = 1; i <= n; i++)  
            for (j = 1;j <= m; j++)  
            {  
                cin >> matrix[j][i];  
                if (matrix[j][i] == 'H')  
                {  
                    h.x = j;  
                    h.y = i;      
                    matrix[j][i] = '.';  
                }  
                else if (matrix[j][i] == 'P') {  
                    p.x = j;  
                    p.y = i;                  
                    matrix[j][i] = '.';  
                }  
            }  
  
            char d;  
            for (i = 0; i < 4; i++) {                 
                cin >> d;  
                girl[i] = dir[d];             
            }  
  
            int ans = bfs(h, p);  
            if (ans == -1)  
                cout << "Impossible\n";  
            else  
                cout << ans << endl;  
  
    }  
    return 0;  
}


