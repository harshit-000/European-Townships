#include<bits/stdc++.h>
using namespace std;

double ACCENT_PAINT_AMOUNT = 1.5;
double ACCENT_PAINT_TIME = 2.5;
double REGULAR_PAINT_AMOUNT = 2.25;
double REGULAR_PAINT_TIME = 3.25;

double calculate_paint_hours(double accent_walls, double regular_walls) {
    double accent_paint_qty = accent_walls * ACCENT_PAINT_AMOUNT;
    double regular_paint_qty = regular_walls * REGULAR_PAINT_AMOUNT;
    double accent_paint_time = accent_walls * ACCENT_PAINT_TIME;
    double regular_paint_time = regular_walls * REGULAR_PAINT_TIME;
    double total_paint_qty = accent_paint_qty + regular_paint_qty;
    double total_paint_time = accent_paint_time + regular_paint_time;
    return total_paint_time;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> houses(n,vector<int>(4));
        for(int i=0;i<n;i++) {
            string s;
            cin >> s;
            s.push_back(',');
            int idx=0,j=0;
            while(idx < s.length()) {
                while(s[idx] == ' ') idx++;
                int start = idx;
                idx++;
                while(idx<s.length() && s[idx] != ',') idx++;
                houses[i][j] = stoi(s.substr(start,idx));
                idx++;
                j++;
            }
        }
        int totalWall = 0;
        for(int i=0;i<n;i++) {
            totalWall += ((houses[i][1]*3)+(houses[i][2]*4)+(houses[i][3]*6));
        }

        double accent_walls = (double)(totalWall)/3.0;
        double regular_walls = totalWall-accent_walls;

        double accent_paint_qty = accent_walls * ACCENT_PAINT_AMOUNT;
        double regular_paint_qty = regular_walls * REGULAR_PAINT_AMOUNT;
        double total_paint_time = calculate_paint_hours(accent_walls,regular_walls);

        cout << fixed << setprecision(2) << total_paint_time << "," << accent_paint_qty << "," << regular_paint_qty << "\n";
        
    }
    return 0;
}