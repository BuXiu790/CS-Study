#include <iostream>
using namespace std;

// 基础配置
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 闰年判断
bool is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// 获取某年某月有多少天
int get_days(int y, int m) {
    if (m == 2 && is_leap(y)) return 29; 
    return days[m];
}

int main() {
    
    int y = 2000, m = 1, d = 1; // 2000年1月1日
    int w = 6;                  // 星期六
    int ans = 0;                // 计数器

   
    while (true) {
        
    
        ans++; // 每天必跑 1km
        if (w == 1 || d == 1) { 
            ans++; 
        }

        // 放在结算之后，确保最后一天(2020.10.1)也被算进去了
        if (y == 2020 && m == 10 && d == 1) {
            break; 
        }

       
        d++; 
        w++; 

       
        
        // 1. 星期越界：周日(7) 过了是 周一(1)
        if (w > 7) w = 1;

        // 2. 日子越界：比如 1月32日 -> 变成 2月1日
        if (d > get_days(y, m)) {
            d = 1;   // 日子归 1
            m++;     // 月份 +1
            
            // 3. 月份越界：比如 13月1日 -> 变成 明年1月1日
            if (m > 12) {
                m = 1;  // 月份归 1
                y++;    // 年份 +1
            }
        }
    }

    cout << ans << endl;
    return 0;
}