#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

void tune_map() {
    cout << "Tune map" << endl;

    struct CmpStrLength {
        bool operator()(const string& a, const string& b) const {
            return a.size() < b.size();
        }
    };

    cout << "Lexicographical order" << endl;
    map<string, int> m = {{"c", 1}, {"abcde", 4}, {"df", 3}, {"bbb", 2}};
    for (auto e : m) {
        cout << e.first << " " << e.second << endl;
    }
    cout << endl;

    cout << "Ordered by length" << endl;
    map<string, int, CmpStrLength> m2(m.begin(), m.end());
    for (auto e : m2) {
        cout << e.first << " " << e.second << endl;
    }
    cout << endl;
}

void tune_unordered_map() {
    cout << "Tune unordered map" << endl;

    struct Pair {
        string first;
        string second;

        Pair(string first, string second): first(first), second(second) {}
    };

    cout << "Saved in map based on first AND second" << endl;
    struct HashAll {
        size_t operator()(const Pair& n) const {
            return hash<string>()(n.first) ^ hash<string>()(n.second);
        }
    };

    struct EqAll {
        bool operator()(const Pair& n1, const Pair& n2) const {
            return n1.first == n2.first && n1.second == n2.second;
        }
    };

    unordered_map<Pair, int, HashAll, EqAll> m = { { {"a", "a"}, 1 }, { {"b", "b"}, 2 }, { {"a", "b"}, 3 } };
    for (auto e : m) {
        cout << e.first.first << " " << e.first.second << " " << e.second << endl;
    }
    cout << endl;

    cout << "Saved in map based ONLY on first" << endl;
    struct HashFirst {
        size_t operator()(const Pair& n) const {
            return hash<string>()(n.first);
        }
    };

    struct EqFirst {
        bool operator()(const Pair& n1, const Pair& n2) const {
            return n1.first == n2.first;
        }
    };


    unordered_map<Pair, int, HashFirst, EqFirst> m2(m.begin(), m.end());
    for (auto e : m2) {
        cout << e.first.first << " " << e.first.second << " " << e.second << endl;
    }
    cout << endl;
}

void tune_priority_queue() {
    cout << "Tune priority queue" << endl;
    cout << "Top of pq is the last element in strict weak ordering\ndefined by comparator (the greatest element)" << endl;
    vector<int> input = {5, 10, 12, 2, 144};

    cout << "Descending order" << endl;
    priority_queue<int> pq(input.begin(), input.end());
    while (!pq.empty()) {
        auto e = pq.top();
        pq.pop();
        cout << e << endl;
    }
    cout << endl;

    cout << "Ordered from the farthest to 7 to the closest" << endl;
    struct CmpCloseTo7 {
        bool operator()(const int a, const int b) const {
            return abs(a - 7) < abs(b - 7);
        }
    };

    priority_queue<int, vector<int>, CmpCloseTo7> pq2(input.begin(), input.end());
    while (!pq2.empty()) {
        auto e = pq2.top();
        pq2.pop();
        cout << e << endl;
    }
    cout << endl;
}

int main() {
    tune_map();
    tune_unordered_map();
    tune_priority_queue();
}