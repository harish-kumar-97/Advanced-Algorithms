#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

bool f(int x, int y) {
    return x > y;
}

void vectorDemo() {
      vector<int> A = {11, 2, 3, 14};

    cout << A[1] << endl;

    // sort the vector in ascending order
    sort(A.begin(), A.end());

    // 2, 3, 11, 14
    bool present = binary_search(A.begin(), A.end(), 3); // true
    present = binary_search(A.begin(), A.end(), 4); // false

    // insert an element in the end of vector
    A.push_back(100);

    present = binary_search(A.begin(), A.end(), 100); // true

    // 2, 3, 11, 14, 100
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    // 2, 3, 11, 14, 100, 100, 100, 100, 100, 123
    A.push_back(123);

    // finding the first occurrence of 100 in the array
    auto it = lower_bound(A.begin(), A.end(), 100); // >=
    auto it2 = upper_bound(A.begin(), A.end(), 100); // >

    cout << *it << " " << *it2 << endl;
    cout << it2 - it << endl; // 5

    // sort vector in reverse order(descending order)
    sort(A.begin(), A.end(), f);

    // using iterators to print vector
    vector<int>::iterator it3;
    for(int x : A) {   // iterate by value
        cout << x << " ";
    }
    cout << endl;

    for(int &x : A) {   // iterate by reference
        x++;    // changes the values in vector
        cout << x << " ";
    }
    cout << endl;
}

void setDemo() {
    set<int> S;
    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);

    for(int x:S) {
        cout << x << " ";
    }
    cout << endl;

    // -10 -1 1 2
    auto it = S.find(-1);
    if(it == S.end())
        cout << "Not Present" << endl;
    else
        cout << "Present " << *it << endl;

    auto it2 = S.upper_bound(-1);
    auto it3 = S.upper_bound(0);
    cout << *it2 << " " << *it3 << endl;

    auto it4 = S.upper_bound(2);
    if(it4 == S.end()) 
        cout << "Oops! Sorry, I could not find something like that " << endl;
}

void mapDemo() {
    map<int, int> A;
    A[1] = 100;
    A[2] = -1;
    A[3] = 200;
    A[100000232] = 1;

    map<char, int> cnt;
    string x = "harish kumar";

    for (char c : x) {
        cnt[c]++;
    }

    cout << cnt['a'] << " " << cnt['h'] << endl;
}

void powerOfStl() {
    // add interval [x, y]
    /* add [10, 20]
    add [30, 400]
    add [401, 450]
    give me the interval */

    set < pair<int, int> > S;

    S.insert({401, 450});
    S.insert({10, 20});
    S.insert({2, 3});
    S.insert({30, 400});
    // 2, 3
    // 10, 20
    // 30, 400
    // 401, 450
    int point = 401;
    auto it = S.upper_bound({ point, INT_MAX });
    if (it == S.begin()) {
        cout << "The given point is not present in any interval" << endl;
        return;
    }
    it--;
    pair<int, int> current = *it;
    if(current.first <= point && point <= current.second) {
        cout << "Yes, it's present: " << current.first << " " << current.second << endl;
    } else {
        cout << "The given point is not present in any interval" << endl;
    }
}

int main() {

    // C++ STL
    powerOfStl();
}