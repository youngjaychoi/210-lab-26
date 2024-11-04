#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
using namespace std;
using namespace std::chrono;

const int NUM_SIMULATIONS = 15;
const int NUM_OPERATIONS = 4;
const int DATA_STRUCTURES = 3;

enum Operation { READ, SORT, INSERT, DELETE };

void simulation(long long results[NUM_SIMULATIONS][NUM_OPERATIONS][DATA_STRUCTURES]);
void average(long long results[NUM_SIMULATIONS][NUM_OPERATIONS][DATA_STRUCTURES]);

template <typename Container>
void readData(Container &container);
template <typename Container>
void insertMid(Container &container, const string &value);
void insertMid(set<string> &s, const string &value);
template <typename Container>
void deleteMid(Container &container);
void deleteMid(set<string> &s);

int main() {
    // vector<string> vector;
    // list<string> list;
    // set<string> set;

    // long long vectorTime = 0, listTime = 0, setTime = 0;

    // // READING
    // auto start = high_resolution_clock::now();
    // readData(vector);
    // auto end = high_resolution_clock::now();
    // vectorTime = duration_cast<microseconds>(end - start).count();

    // start = high_resolution_clock::now();
    // readData(list);
    // end = high_resolution_clock::now();
    // listTime = duration_cast<microseconds>(end - start).count();

    // start = high_resolution_clock::now();
    // readData(set);
    // end = high_resolution_clock::now();
    // setTime = duration_cast<microseconds>(end - start).count();

    // cout << right << setw(9) << "Operation" << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    // cout << right << setw(9) << "Read" << setw(10) << vectorTime << setw(10) << listTime << setw(10) << setTime << endl;

    // // SORTING
    // start = high_resolution_clock::now();
    // sort(vector.begin(), vector.end());
    // end = high_resolution_clock::now();
    // vectorTime = duration_cast<microseconds>(end - start).count();

    // start = high_resolution_clock::now();
    // list.sort();
    // end = high_resolution_clock::now();
    // listTime = duration_cast<microseconds>(end - start).count();

    // cout << right << setw(9) << "Sort" << setw(10) << vectorTime << setw(10) << listTime << setw(10) << setTime << endl;

    // // INSERTING
    // start = high_resolution_clock::now();
    // insertMid(vector, "TESTCODE");
    // end = high_resolution_clock::now();
    // vectorTime = duration_cast<microseconds>(end - start).count();

    // start = high_resolution_clock::now();
    // insertMid(list, "TESTCODE");
    // end = high_resolution_clock::now();
    // listTime = duration_cast<microseconds>(end - start).count();

    // start = high_resolution_clock::now();
    // insertMid(set, "TESTCODE");
    // end = high_resolution_clock::now();
    // setTime = duration_cast<microseconds>(end - start).count();

    // cout << right << setw(9) << "Insert" << setw(10) << vectorTime << setw(10) << listTime << setw(10) << setTime << setw(10) << endl;

    // // DELETING
    // start = high_resolution_clock::now();
    // deleteMid(vector);
    // end = high_resolution_clock::now();
    // vectorTime = duration_cast<microseconds>(end - start).count();

    // start = high_resolution_clock::now();
    // deleteMid(list);
    // end = high_resolution_clock::now();
    // listTime = duration_cast<microseconds>(end - start).count();

    // start = high_resolution_clock::now();
    // deleteMid(set);
    // end = high_resolution_clock::now();
    // setTime = duration_cast<microseconds>(end - start).count();

    // cout << right << setw(9) << "Delete" << setw(10) << vectorTime << setw(10) << listTime << setw(10) << setTime << endl;

    // return 0;
}


void simulation(long long results[NUM_SIMULATIONS][NUM_OPERATIONS][DATA_STRUCTURES]) {
    for (int sim = 0;)
}

void average(long long results[NUM_SIMULATIONS][NUM_OPERATIONS][DATA_STRUCTURES]) {

}






template <typename Container>
void readData(Container &container) {
    ifstream inFile("codes.txt");
    string line;
    while (getline(inFile, line)) {
        container.insert(container.end(), line);
    }
    inFile.close();
}

template <typename Container>
void insertMid(Container &container, const string &value) {
    auto it = container.begin();
    advance(it, container.size() / 2);
    container.insert(it, value);
}

void insertMid(set<string> &s, const string &value) {
    s.insert(value);
}

template <typename Container>
void deleteMid(Container &container) {
    auto it = container.begin();
    advance(it, container.size() / 2);
    container.erase(it);
}

void deleteMid(set<string> &s) {
    auto it = s.begin();
    advance(it, s.size() / 2);
    s.erase(it);
}
