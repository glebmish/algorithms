#include <iostream>
#include <string>
using namespace std;

int KMP_substr(string str, string substr) {
    string s = substr + '#' + str;

    int *prefix = new int[s.length()];
    prefix[0] = 0;

    for (int i = 1; i < s.length(); ++i) {
        int j = prefix[i - 1];

        while (j > 0 && s[i] != s[j])
            j = prefix[j - 1];

        if (s[i] == s[j])
            prefix[i] = j + 1;
        else
            prefix[i] = 0;

        if (prefix[i] == substr.size()) {
            delete[] prefix;
            return i - 2 * substr.size();
        }
    }

    delete[] prefix;
    return -1;
}

int main() {
    string str, substr;
    cin >> str >> substr;

    cout << KMP_substr(str, substr);
}