#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;


void printList(const list<string>& lst, const string& label) {
    cout << label << ": [";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << "\"" << *it << "\"";
        if (next(it) != lst.end()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}


void printVector(const vector<string>& vec, const string& label) {
    cout << label << ": [";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "\"" << vec[i] << "\"";
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}


string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return "";
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

int main() {

    list<string> inventory = {"apples", "bananas", "oranges", "pears"};
    list<string> shipment = {"kiwis", " bananas", "grapes"}; 
    vector<string> sold_out = {"apples", "oranges"};


    for (auto& item : shipment) {
        item = trim(item);
    }

    printList(inventory, "Current Inventory");
    printList(shipment, "Shipment");
    printVector(sold_out, "Sold-out items");


    for (const auto& sold_item : sold_out) {
        inventory.remove(sold_item);
    }


    inventory.insert(inventory.end(), shipment.begin(), shipment.end());


    printList(inventory, "\nUpdated Inventory");

    return 0;
}
