#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string exp;
    int op, num1, num2;
    stack<int> calc;
    stack<int> temp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> exp;
        
        reverse(exp.begin(), exp.end());
        for (string::iterator it = exp.begin(); it != exp.end(); it++) {
            calc.push(*it);
        }

        num1 = calc.top() - '0';
        calc.pop();
        temp.push(num1);

        while (!calc.empty()) {
            num1 = temp.top();
            temp.pop();
            op = calc.top();
            calc.pop();
            num2 = calc.top() - '0';
            calc.pop();
            switch (op) {
                case 'x':
                    temp.push(num1 * num2);
                    break;
                case '/':
                    temp.push(num1 / num2);
                    break;
                case '+':
                    temp.push(num1);
                    temp.push('+');
                    temp.push(num2);
                    break;
                case '-':
                    temp.push(num1);
                    temp.push('-');
                    temp.push(num2);
                    break;
            }
        }

        while(temp.size() > 1) {
            calc.push(temp.top());
            temp.pop();
        }

        while(!calc.empty()) {
            num1 = temp.top();
            temp.pop();
            op = calc.top();
            calc.pop();
            num2 = calc.top();
            calc.pop();
            switch (op) {
                case '+':
                    temp.push(num1 + num2);
                    break;
                case '-':
                    temp.push(num1 - num2);
                    break;
            }
        }
        
        if (temp.top() == 24) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        temp.pop();
    }
    return 0;
}
