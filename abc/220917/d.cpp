#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<string>> get_perms(vector<string> &values) {
    result =  vector<vector<string>>();
    if (values.size() == 0) {
        return result;
    }
    if (values.size() == 1) {
        result.push_back(values);
        return result;
    }
    for (int i = 0; i < values.size(); i++) {
        vector<vector<string>> others = get_perms()
    }
}

int main()
{
    int N , M;
    cin>>N >> M;
    vector<string> s_list(N);
    int letter_count = -1;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        s_list.push_back(str);
        letter_count += str.size() + 1;
    }

    set<string> t_list;
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        t_list.insert(str);
    }

    if (letter_count < 3) {
        cout << -1;
        return 0;
    }
    int additional_count = 16 - letter_count;
}