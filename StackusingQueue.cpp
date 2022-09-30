#include <bits/stdc++.h>

using namespace std;
class Stacks{
    
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    Stacks(){
        N=0;
    }
    void push(int x){
        q2.push(x);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1=q2;
        q2=temp;
    }
    void pop(){
        q1.pop();
        N--;
    }
    int top(){
        return  q1.front();
    }
};

class Stacks2{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
    Stacks2(){
        N=0;
    }
    void push(int x){
        N++;
        q1.push(x);
    }

    void pop(){
        if (q1.empty())
        {
            return;
        }
        while (q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--; 
        queue<int> temp = q1;
        q1=q2;
        q2=temp;
        
    }
    int top(){
        if (q1.empty())
        {
            return -1;
        }
        while (q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q2.push(x);
        queue<int> temp = q1;
        q1=q2;
        q2=temp;

        return x;
    }
};

int main(){


    Stacks2 st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<< st.top()<<endl;
    st.pop();

    cout<< st.top()<<endl;
    return 0;

}