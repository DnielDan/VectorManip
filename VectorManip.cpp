#include <iostream>
#include <vector>

using namespace std;

void display_options();
char selected_option();
void handle_print(const vector<int> &vec);
void handle_add(vector<int> &vec);
void handle_mean(const vector<int> &vec);
void handle_smallest(const vector<int> &vec);
void handle_largest(const vector<int> &vec);
void handle_search(const vector<int> &vec);
void handle_clear(vector<int> &vec);
void handle_quit();
void handle_unknown();

void handle_print_vector(const vector<int> &vec);
double calculate_mean(const vector<int> &vec);
int find_smallest(const vector<int> &vec);
int find_largest(const vector<int> &vec);
int find_number(const vector<int> &vec, int target);

int main() {
    
    char selection{};
    vector<int> vec{};

    do {
        display_options();
        selection = selected_option();
        if(selection == 'P' || selection == 'p') {
            handle_print(vec);
        }
        else if(selection == 'A' || selection == 'a') {
            handle_add(vec);
        }
        else if(selection == 'M' || selection == 'm') {
            handle_mean(vec);
        }
        else if(selection == 'S' || selection == 's') {
            handle_smallest(vec);
        }
        else if(selection == 'L' || selection == 'l') {
            handle_largest(vec);
        }
        else if(selection == 'F' || selection == 'f') {
            handle_search(vec);
        }
        else if(selection == 'C' || selection == 'c') {
            handle_clear(vec);
        }
        else if(selection == 'Q' || selection == 'q') {
            handle_quit();
        }
        else {
            handle_unknown();
        }
    } while(selection != 'Q' && selection != 'q');

    cout << endl;
    return 0;
}

void display_options() {
    cout << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add numbers" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "F - Find a number and its frequency" << endl;
    cout << "C - Clear out list of numbers" << endl;
    cout << "Q - Quit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
}

char selected_option() {
    char selection{};
    cin >> selection;
    return selection;
}

void handle_print(const vector<int> &vec) {
    if(vec.empty()) {
        cout << "[] - the list is empty" << endl;
    }
    else {
        handle_print_vector(vec);
    }
}

void handle_add(vector<int> &vec) {
    cout << "Enter an integer to add to the list: ";
    int integer{};
    cin >> integer;
    vec.push_back(integer);
    cout << integer << " added" << endl;
}

void handle_mean(const vector<int> &vec) {
    if(vec.empty()) {
        cout << "Unable to calculate the mean - no data" << endl;
    }
    else {
        cout << "The mean is " << calculate_mean(vec) << endl;
    }
}

void handle_smallest(const vector<int> &vec) {
    if(vec.empty()) {
        cout << "Unable to determine the smallest number - list is empty" << endl;
    }
    else {
        cout << "The smallest number is: " << find_smallest(vec) << endl;
    }
}

void handle_largest(const vector<int> &vec) {
    if(vec.empty()) {
        cout << "Unable to determine the largest number - list is empty" << endl;
    }
    else {
        cout << "The largest number is: " << find_largest(vec) << endl;
    }
}

void handle_search(const vector<int> &vec) {
    if(vec.empty()) {
        cout << "Unable to find number - list is empty" << endl;
    }
    else {
        int target{};
        cout << "Enter a number to find: ";
        cin >> target;
        int count = find_number(vec, target);
        if(count == 0) {
            cout << "Unable to find number" << endl;
        }
        else {
            cout << target << " was found " << count << " time(s)" << endl;
        }
    }
}

void handle_clear(vector<int> &vec) {
    vec.clear();
    cout << "List successfully cleared" << endl;
}

void handle_quit() {
    cout << "Goodbye" << endl;
}

void handle_unknown() {
    cout << "Unknown selection, please try again" << endl;
}

void handle_print_vector(const vector<int> &vec) {
    cout << "[ ";
        for(size_t i{}; i < vec.size(); i++) {
            cout << vec.at(i) << ' ';
        }
        cout << "]" << endl;
}

double calculate_mean(const vector<int> &vec) {
    double sum{};
    for(size_t i{}; i < vec.size(); i++) {
        sum += vec.at(i);
    }
    return sum / vec.size();
}

int find_smallest(const vector<int> &vec) {
    int smallest = vec.at(0);
    for(size_t i{}; i < vec.size(); i++) {
        if(vec.at(i) < smallest) {
            smallest = vec.at(i);
        }
    }
    return smallest;
}

int find_largest(const vector<int> &vec) {
    int largest = vec.at(0);
    for(size_t i{}; i < vec.size(); i++) {
        if(vec.at(i) > largest) {
            largest = vec.at(i);
        }
    }
    return largest;
}

int find_number(const vector<int> &vec, int target) {
    int count{};
    for(size_t i{}; i < vec.size(); i++) {
        if(target == vec.at(i)) {
            count++;
        }
    }
    return count;
}
