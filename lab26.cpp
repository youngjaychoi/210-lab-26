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
void calculate_average(long long results[NUM_SIMULATIONS][NUM_OPERATIONS][DATA_STRUCTURES]);

template <typename Container>
void readData(Container &container);
template <typename Container>
void insertMid(Container &container, const string &value);
void insertMid(set<string> &s, const string &value);
template <typename Container>
void deleteMid(Container &container);
void deleteMid(set<string> &s);

int main() {
    long long results[NUM_SIMULATIONS][NUM_OPERATIONS][DATA_STRUCTURES] = { 0 };

    simulation(results);
    calculate_average(results);

    return 0;
}

void simulation(long long results[NUM_SIMULATIONS][NUM_OPERATIONS][DATA_STRUCTURES]) {
    for (int sim = 0; sim < NUM_SIMULATIONS; ++ sim) {
        vector<string> vector;
        list<string> list;
        set<string> set;

        long long vectorTime = 0, listTime = 0, setTime = 0;

        // READING
        auto start = high_resolution_clock::now();
        readData(vector);
        auto end = high_resolution_clock::now();
        vectorTime = duration_cast<microseconds>(end - start).count();

        start = high_resolution_clock::now();
        readData(list);
        end = high_resolution_clock::now();
        listTime = duration_cast<microseconds>(end - start).count();

        start = high_resolution_clock::now();
        readData(set);
        end = high_resolution_clock::now();
        setTime = duration_cast<microseconds>(end - start).count();

        results[sim][READ][0] = vectorTime;
        results[sim][READ][1] = listTime;
        results[sim][READ][2] = setTime;

        // SORTING
        start = high_resolution_clock::now();
        sort(vector.begin(), vector.end());
        end = high_resolution_clock::now();
        vectorTime = duration_cast<microseconds>(end - start).count();

        start = high_resolution_clock::now();
        list.sort();
        end = high_resolution_clock::now();
        listTime = duration_cast<microseconds>(end - start).count();

        results[sim][SORT][0] = vectorTime;
        results[sim][SORT][1] = listTime;
        results[sim][SORT][2] = setTime;
        
        // INSERTING
        start = high_resolution_clock::now();
        insertMid(vector, "TESTCODE");
        end = high_resolution_clock::now();
        vectorTime = duration_cast<microseconds>(end - start).count();

        start = high_resolution_clock::now();
        insertMid(list, "TESTCODE");
        end = high_resolution_clock::now();
        listTime = duration_cast<microseconds>(end - start).count();

        start = high_resolution_clock::now();
        insertMid(set, "TESTCODE");
        end = high_resolution_clock::now();
        setTime = duration_cast<microseconds>(end - start).count();

        results[sim][INSERT][0] = vectorTime;
        results[sim][INSERT][1] = listTime;
        results[sim][INSERT][2] = setTime;

        // DELETING
        start = high_resolution_clock::now();
        deleteMid(vector);
        end = high_resolution_clock::now();
        vectorTime = duration_cast<microseconds>(end - start).count();

        start = high_resolution_clock::now();
        deleteMid(list);
        end = high_resolution_clock::now();
        listTime = duration_cast<microseconds>(end - start).count();

        start = high_resolution_clock::now();
        deleteMid(set);
        end = high_resolution_clock::now();
        setTime = duration_cast<microseconds>(end - start).count();

        results[sim][DELETE][0] = vectorTime;
        results[sim][DELETE][1] = listTime;
        results[sim][DELETE][2] = setTime;
    }
}

void calculate_average(long long results[NUM_SIMULATIONS][NUM_OPERATIONS][DATA_STRUCTURES]) {
    long long average[NUM_OPERATIONS][DATA_STRUCTURES] = { 0 };

    for (int sim = 0; sim < NUM_SIMULATIONS; ++sim) {
        for (int op = 0; op < NUM_OPERATIONS; ++ op) {
            for (int ds = 0; ds < DATA_STRUCTURES; ++ ds) {
                average[op][ds] += results[sim][op][ds];
            }
        }
    }

    for (int op = 0; op < NUM_OPERATIONS; ++op) {
        for (int ds = 0; ds < DATA_STRUCTURES; ++ds) {
            average[op][ds] /= NUM_SIMULATIONS;
        }
    }
    
    cout << "Number of simulations: " << NUM_SIMULATIONS << endl;
    cout << right << setw(9) << "Operation" << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    for (int op = 0; op < NUM_OPERATIONS; ++op) {
        switch (op) {
        case READ:
            cout << right << setw(9) << "Read";
            break;
        case SORT:
            cout << right << setw(9) << "Sort";
            break;
        case INSERT:
            cout << right << setw(9) << "Insert";
            break;
        case DELETE:
            cout << right << setw(9) << "Delete";
            break;
        }
        cout << right << setw(9) << average[op][0] << setw(10) << average[op][1] << setw(10) << average[op][2] << endl;
    }
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
