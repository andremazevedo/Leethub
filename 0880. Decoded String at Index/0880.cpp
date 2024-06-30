#include <iostream>
#include <stack>

#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = 0;
        int div = 1;

        int i;
        for (i = 0; ; i++) {
            if ('1' <= s[i] && s[i] <= '9') {
                div = n;
                n *= s[i] - '0';
            } else {
                div = 1;
                n++;
            }
            
            if (n == k)
                return string(1,s[i]);
            else if (n > k)
                break;
        }
        cout << k % div - 1 << endl;
        n = 0;
        int j = 0;
        for (int j = 0; j < i - 1; j++) {
            if ('1' <= s[j] && s[j] <= '9') {
                if (n * (s[i] - '0') > )
                n *= (s[i] - '0');
            }
            else {
                n++;
            }

            cout << j << endl;
            cout << n << endl;

            if (n == k % div - 1) {
                break;
            }
        }

        return string(1, s[j]);
    }
};

int main() {

    string s = "leet2code3";
    int k = 20;

    // string s = "a23";
    // int k = 6;

    // string s = "y959q969u3hb22odq595";
    // int k = 222280369;

    // string s = "cpmxv8ewnfk3xxcilcmm68d2ygc88daomywc3imncfjgtwj8nrxjtwhiem5nzqnicxzo248g52y72v3yujqpvqcssrofd99lkovg";
    // int k = 480551547;
    
    cout << "Input: s = \"" << s << "\", k = " << k << endl;
    
    cout << "output: \"" << Solution().decodeAtIndex(s, k) << "\"" << endl;

    return 0;
}
