#include <iostream>
#include <thread>
using namespace std;
// Function pointers
// void fun(int x)
// {
//     while (x-- > 0)
//     {
//         cout << x << " ";
//     }
// }
// void gun(int x)
// {
//     for (int i = 0; i < x; i++)
//     {
//         cout << i << " ";
//     }
// }
// int main()
// {
//     thread t1(fun, 10);
//     thread t2(gun, 10);
//     t1.join();
//     t2.join();
//     return 0;
// }

// 2.Lambda funtion
// int main()
// {
//     thread t([](int x)
//              {
//         while(x-->0){
//             cout<<x<<" ";
//         } },
//              10);
//     t.join();
//     return 0;
// }
// 3.Function Object
// class base
// {
// public:
//     void operator()(int x)
//     {
//         while (x-- > 0)
//         {
//             cout << x << " ";
//         }
//     }
// };
// int main()
// {
//     thread t((base()), 10);
//     t.join();
//     return 0;
// }
// 4.non Static member function
// class base
// {
// public:
//     void run(int x)
//     {
//         while (x-- > 0)
//         {
//             cout << x << " ";
//         }
//     }
// };
// int main()
// {
//     base b;
//     thread t(&base::run, &b, 10);
//     t.join();
//     return 0;
// }
// 5.Static function
class base
{
public:
    static void tun(int x)
    {
        while (x-- > 0)
        {
            cout << " Static" << x << " ";
        }
    }
};
int main()
{
    thread t(&base::tun, 10);
    t.join();
    return 0;
}