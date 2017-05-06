#include <vector>
#include <climits>
#include <iostream>

using namespace std;

// error

class Solution {
public:
    int leastBricks(vector<vector<int> >& wall) {
        sum = 0;
        for(int i=0;i<wall[0].size();i++)
            sum += wall[0][i];
        build(wall);
        int size = n;
        int nmin = size;
        int cur;
        while((cur = pop(wall)) != -1){
            if(cur == sum) break;
            int add = size - 1;
            while(top() == cur){
                add--;
                pop(wall);
            }
            if(top() == -1) break;
           // cout << cur << " " << add << endl;
            if(add < nmin)
                nmin = add;
        }
        return nmin;
    }

private:
    int *heap;
    int *length, *ind;
    int n, sum;
    void build(vector<vector<int> >& wall){
        n = wall.size();
        cout << "n =" << n;
        heap = new int[n + 1];
        length = new int[n + 1];
        ind = new int[n + 1];
        for(int i=1;i<=n;i++){
            heap[i] = i;
            ind[i] = 0;
            length[i] = wall[i-1][ind[i]++];
        }
        for(int i=n/2 + 1;i>=1;i--){
            decrease(i);
        }

    }

    void decrease(int index){
        int pre = heap[index];
        while(true){
            int next = index*2;
            if(next < n && length[heap[next + 1]] < length[heap[next]]) next++;
            if(next <= n && length[heap[next]] < length[heap[index]]){
                heap[index] = heap[next];
                index = next;
            }
            else break;
        }
        heap[index] = pre;
        int i=1;
    }

    int pop(vector<vector<int> >& wall){
        int ans = top();
        if(ans == -1) return ans;
        length[heap[1]] += wall[heap[1]-1][ind[heap[1]]++];
        cout << length[heap[1]] << " " << heap[1] << endl;
        int k = length[heap[1]];
        if(ind[heap[1]] == wall[heap[1]-1].size()) n--;
        decrease(1);
        return ans;


    }

    int top(){
        if(n == 0) return -1;
        return length[heap[1]];
    }
};


int main(){
    vector<vector<int> > wall;
    vector<int> wall0;
    wall0.push_back(1);
    wall0.push_back(1);
    wall0.push_back(1);
    wall0.push_back(1);
    wall.push_back(wall0);
    vector<int> wall1;
    wall1.push_back(1);
    wall1.push_back(2);
    wall1.push_back(1);
    wall.push_back(wall1);
    Solution solution;
    cout << solution.leastBricks(wall);
}
