#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "WELCOME WELCome Welcome welcome..." << endl;
    cout << "Enter 'exit' if you want to exit." << endl;
    ifstream file("flag.txt");
    if (file) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Failed to open flag.txt" << endl;
    }
    while(true) {
        string s;
        cout << ">> ";
        getline(cin, s);
        if (s == "exit") break;
        cout << s << endl;
    }
    cout << "Thank youuuu~~~" << endl;
}