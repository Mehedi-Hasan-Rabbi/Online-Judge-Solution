#include<bits/stdc++.h>
using namespace std;

//void solve_1()
//{
//    int n;
//    cin >> n;
//
//    double sq_root = sqrt(n);
//
//    if(ceil(sq_root) == floor(sq_root))
//        cout << "YES" << endl;
//    else
//        cout << "NO" << endl;
//
//    // ceil() and floor() both function's return type is double/float.
//    // And comparing two double/float using '=', gives wrong answer some times.
//}

//void solve_2()
//{
//    int n;
//    cin >> n;
//
//    double sq_root = sqrt(n);
//    double difference = ceil(sq_root) == floor(sq_root);
//
//    if(difference < 0.00001)
//        cout << "YES" << endl;
//    else
//        cout << "NO" << endl;
//}

void solve_3()
{
    int n;
    cin >> n;

    int sq_root = sqrt(n);

    if(sq_root * sq_root == n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        solve_3(); // Best solution is solve 3 and 2. solve 1 has some problem.
    }
    return 0;
}
