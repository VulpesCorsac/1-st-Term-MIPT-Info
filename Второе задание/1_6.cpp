#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define all(c) c.begin(), c.end()

using namespace std;

class stacknode
{
public:
    char data;
    stacknode *link;

    stacknode(int d = 0,stacknode *l = NULL)
    {
        data = d;
        link = l;
    }

    char GetData()
    {
        return data;
    }

    stacknode* GetLink()
    {
        return link;
    }
};

class stack
{
public:
    stacknode *top;

    stack()
    {
        top = NULL;
    }

    void push(char y)
    {
        top = new stacknode(y, top);
    }

    char pop()
    {
        if (top == NULL)
            return 0;
        char retvalue;
        stacknode *x = top;
        retvalue = top->GetData();
        top = x->GetLink();
        delete x;
        return retvalue;
    }

    bool empty()
    {
        if(top == NULL)
            return true;
        return false;
    }
};

class Postfix
{
public:
    bool isoprand(char symb)
    {
        if (symb == '+' ||
            symb == '-' ||
            symb == '*' ||
            symb == '/' ||
            symb == '^' ||
            symb == '(' ||
            symb == ')' )
            return false;
        return true;
    }

    bool isoperand(string symb)
    {
        for (size_t i = 0; i < symb.length(); i++)
            if (!(isalnum(symb[i])))
                return false;
        return true;
    }

    bool isoperator(char symb)
    {
        if (symb == '+' ||
            symb == '-' ||
            symb == '*' ||
            symb == '/' ||
            symb == '^')
            return true;
        return false;
    }

    bool precedence(char operator1, char operator2)
    {
        char s[4][3] = {"()", "+-", "*/", "^^"};
        int k1, k2;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 2; j++)
            {
                if (operator1 == s[i][j])
                    k1 = i;
                if (operator2 == s[i][j])
                    k2 = i;
            }
        if (k1 < k2)
            return false;
        return true;
    }

    vector <string> parse(string _s)
    {
        vector <string> answer;
        string s = _s + " ";
        string temp = "";
        int state = 0; // 0 - новый элемент, 1 - число, 2 - оператор или скобка
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (temp != "")
                    answer.push_back(temp);
                temp = "";
                state = 0;
                continue;
            }
            if (state == 0)
            {
                temp += s[i];
                if (isalnum(s[i]))
                    state = 1;
                else
                    state = 2;
                continue;
            }
            if (state == 1 && isalnum(s[i]))
            {
                temp += s[i];
                continue;
            }
            if (state == 1 && !isalnum(s[i]))
            {
                if (temp != "")
                    answer.push_back(temp);
                temp = "";
                if (isoperator(s[i]))
                    state = 2;
                else
                    state = 0;
                temp += s[i];
                continue;
            }
            if (state == 2)
            {
                if (temp != "")
                    answer.push_back(temp);
                temp = "";
                temp += s[i];
                if (isalnum(s[i]))
                    state = 1;
                if (s[i] == ' ')
                    state = 0;
                if (!(s[i] == ' ') || isalnum(s[i]))
                    state = 2;
                continue;
            }
        }
        return answer;
    }

    void str_infix_postfix(string infix, string &postfix)
    {
        postfix = "";
        vector <string> parsed;
        parsed = parse(infix);
        char top_operator;
        stack operator_stack;
        for (size_t i = 0; i < parsed.size(); i++)
        {
//            cout << endl << "|" << postfix << "|";
//            cout << endl << "adding: " << i + 1 << " - " << parsed[i] << " " << endl;
            if (isoperand(parsed[i]))
            {
                postfix += parsed[i];
                postfix += " ";
//                cout << "operand";
            }
            else
            {
                if (parsed[i] == ")")
                {
                    while ((top_operator = operator_stack.pop()) && top_operator != '(' )
                        postfix += top_operator;
                        postfix += " ";
//                    cout << "closed";
                }
                if (parsed[i] == "(")
                {
                    operator_stack.push('(');
//                    cout << "open";
                }
                if (!(parsed[i] == ")" || parsed[i] == "("))
                {
//                    cout << "operator";
                    while ((top_operator = operator_stack.pop()) && precedence(top_operator, parsed[i][0]))
                    {
                        postfix += top_operator;
                        postfix += " ";
                    }
                    if(top_operator)
                        operator_stack.push(top_operator);
                    operator_stack.push(parsed[i][0]);
                }
            }
        }
        while (!operator_stack.empty())
        {
            postfix += operator_stack.pop();
            postfix += " ";
        }
    }
};

int main()
{
//    freopen("in.txt", "r+", stdin);

    Postfix P;

    string infix, postfix;
    getline(cin, infix);
//    cout << infix << endl;
    P.str_infix_postfix(infix, postfix);
    cout << postfix << endl;

//    fclose(stdin);

    return 0;
}
