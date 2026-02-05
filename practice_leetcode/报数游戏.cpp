#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
  
    for(int i=1; i<=5; i++) q.push(i);

    cout << "地上的牌: ";
    
   
    while(!q.empty()) {
        // --- 动作 1：扔掉最上面的牌 ---
        // 1.1 拿到队头 (front)
        // 1.2 打印它
        // 1.3 把它弹出去 (pop)
        
        cout << q.front()<< " "; 
        q.pop();

        // --- 动作 2：把下一张插到最后面 ---
        // 只有当队列还没空的时候，才做这一步！
        if (!q.empty()) {
           int x=q.front();
           q.pop();
           q.push(x);

        }
    }

    return 0;
}