#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>

#include "stackfun.h"
#include "exercises.h"

using namespace std;

template <typename T>
inline string to_string(const T & value)
{
	stringstream ss;
	ss << boolalpha << value;
	return ss.str();
}

template <typename T>
inline string colorize(const T & actual, const T & expected)
{
	if (actual == expected)
		return "\033[32m" + to_string(actual) + "\033[0m";
	else
		return "\033[31m" + to_string(actual) + "\033[0m";
}

int main()
{
    cout << boolalpha << endl; // make true and false print for bools, not 0 and 1

    // Run sumDigits:
    cout << "==== sumDigits ====" << endl;
    cout << "sumDigits(243) = " << colorize(sumDigits(243), 9) << endl;
    cout << "expected       = " << 9 << endl;
    cout << "sumDigits(49)  = " << colorize(sumDigits(49), 13) << endl;
    cout << "expected       = " << 13 << endl;
    cout << "sumDigits(1)   = " << colorize(sumDigits(1), 1) << endl;
    cout << "expected       = " << 1 << endl;
    cout << "sumDigits(0)   = " << colorize(sumDigits(0), 0) << endl;
    cout << "expected       = " << 0 << endl << endl;


    // Run triangle:
    cout << "==== triangle ====" << endl;
    cout << "triangle(0) = " << colorize(triangle(0), 0) << endl;
    cout << "expected    = " << 0 << endl;
    cout << "triangle(3) = " << colorize(triangle(3), 6) << endl;
    cout << "expected    = " << 6 << endl;
    cout << "triangle(6) = " << colorize(triangle(6), 21) << endl;
    cout << "expected    = " << 21 << endl << endl;


    // Run sum:
    cout << "==== sum ====" << endl;
    stack<int> s;

    const int n = 16;
    for (int i = 0; i <= n; i++)
        s.push(i);

    cout << "Sum:      " << colorize(StackFun::sum<int>(s), 136) << endl;
    cout << "Expected: " << 136 << endl << endl;


    // Run scramble:
    cout << "==== scramble ====" << endl;
    queue<int> q;
    for (int i = 0; i <= 16; i++)
        q.push(i);

    StackFun::scramble<int>(q);

	int expected[] = {0, 2, 1, 3, 4, 5, 9, 8, 7, 6, 10, 11, 12, 13, 14, 16, 15};
	cout << "Scrambled queue: ";
	for (int i = 0; i <= 16; i++)
	{
		cout << colorize(q.front(), expected[i]) << ' ';
		q.pop();
	}
    cout << endl;
    cout << "Expected:        0 2 1 3 4 5 9 8 7 6 10 11 12 13 14 16 15 " << endl << endl;


    // Run verifySame:
    cout << "==== verifySame ====" << endl;
    stack<int> s1;
    queue<int> q1;
    for (int i = 0; i < 5; i++)
    {
        s1.push(i);
        q1.push(i);
    }
    q = q1;
    s = s1;
    cout << "verifySame(true): " << colorize(StackFun::verifySame(s, q), true) << endl;
    if (q == q1 && s == s1)
        cout << "Stack and queue \033[32munmodified: :)\033[0m" << endl;
    else
        cout << "Stack or queue \033[31mCHANGED: :(\033[0m" << endl;

    stack<int> s2;
    queue<int> q2;
    for (int i = 0; i < 4; i++)
    {
        s2.push(i+1);
        q2.push(i);
    }
    s2.push(5);
    q2.push(5);

    q = q2;
    s = s2;
    cout << "verifySame(false): " << colorize(StackFun::verifySame(s, q), false) << endl;
    if (q == q2 && s == s2)
        cout << "Stack and queue \033[32munmodified: :)\033[0m" << endl;
    else
        cout << "Stack or queue \033[31mCHANGED: :(\033[0m" << endl;
    cout << endl;
}
