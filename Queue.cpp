#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <chrono>

using namespace std;


class Person {
public:
    string name;
    int ticket_number;

    Person(string name, int ticket_number) : name(name), ticket_number(ticket_number) {}
};


class Queue {
private:
    queue<Person> peopleQueue;
    int currentTicketNumber = 1;

public:

    void enqueue(string name) {
        Person person(name, currentTicketNumber++);
        peopleQueue.push(person);
        cout << name << " added to the queue with Ticket #" << person.ticket_number << endl;
        cout << "Queue size: " << peopleQueue.size() << endl;
    }


    void autoDequeue() {
        if (!peopleQueue.empty()) {
            cout << "\nAfter 1 minute...\n";
            Person frontPerson = peopleQueue.front();
            cout << "Dequeue: " << frontPerson.name << " received a ticket (Ticket #" << frontPerson.ticket_number << ")" << endl;
            peopleQueue.pop();
            cout << "Queue size: " << peopleQueue.size() << endl;
            if (!peopleQueue.empty()) {
                Person nextPerson = peopleQueue.front();
                cout << "Next in line: " << nextPerson.name << " (Ticket #" << nextPerson.ticket_number << ")" << endl;
            }
        } else {
            cout << "Queue is empty." << endl;
        }
    }


    bool isEmpty() const {
        return peopleQueue.empty();
    }

    int size() const {
        return peopleQueue.size();
    }


    void peek() const {
        if (!peopleQueue.empty()) {
            Person frontPerson = peopleQueue.front();
            cout << "Next in line: " << frontPerson.name << " with Ticket #" << frontPerson.ticket_number << endl;
        } else {
            cout << "Queue is empty." << endl;
        }
    }


    int position(string name) const {
        int pos = 1;
        queue<Person> tempQueue = peopleQueue;

        while (!tempQueue.empty()) {
            Person currentPerson = tempQueue.front();
            if (currentPerson.name == name) {
                return pos;
            }
            tempQueue.pop();
            pos++;
        }

        return -1; 
    }
};


void displayMenu(Queue &queue) {
    int choice;
    string name;

    do {
        cout << "\n1. Enqueue a person\n2. Check your position in the queue\n3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the name: ";
                cin >> name;
                queue.enqueue(name);
                break;

            case 2:
                cout << "Enter your name: ";
                cin >> name;
                int pos;
                pos = queue.position(name);
                if (pos == -1) {
                    cout << name << " is not in the queue." << endl;
                } else {
                    cout << name << " is currently at position " << pos << " in the queue." << endl;
                }
                break;

            case 3:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);
}


void autoDequeueSimulation(Queue &queue) {
    while (true) {
        this_thread::sleep_for(chrono::seconds(60)); 
        queue.autoDequeue();
    }
}

int main() {
    Queue queue;


    thread autoDequeueThread(autoDequeueSimulation, ref(queue));

    cout << "Welcome to Olivia Rodrigo's Concert Ticketing System!" << endl;


    displayMenu(queue);


    autoDequeueThread.detach();

    return 0;
}
