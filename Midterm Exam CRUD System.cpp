#include <iostream> //provide input output 
#include <vector>  //provide vector container
#include <string> //provide string data type

using namespace std; 


// structure it stores contact details
struct Contact {
    string name;
    string phoneNumber;
};


// class that manage the list of contacts
class ContactManager {
private:
    vector<Contact> contacts; // dynamic array to store contacts

public:
    
    // function po to add new contacts
    void createContact() {
        Contact newContact; //create new contact
        cout << "Enter name: ";
        cin >> newContact.name; //get the name from the user so it can be stored
        cout << "Enter phone number: ";
        cin >> newContact.phoneNumber;
        contacts.push_back(newContact); //add the contact to the list
        cout << "Contact added successfully!\n";
    }

    //function po to display all contacts
    void readContacts() {
        cout << "\nContact List\n";
        //loop of the list of contacts and print each one
        for (size_t i = 0; i < contacts.size(); i++) {
            cout << i + 1 << ". Name: " << contacts[i].name 
                 << ", Phone Number: " << contacts[i].phoneNumber << "\n";
        }
        
        // pag walang contact
        if (contacts.empty()) {
            cout << "No contacts available.\n";
        }
    }

    
    //function po to update contact details
    void updateContact() {
        int index; // magstostore ng contact numbers to update
        readContacts(); // show list of contacts
        cout << "Enter the number of the contact to update: "; 
        cin >> index; 

        
        // check kung valid ang napiling contact number index
        if (index > 0 && index <= contacts.size()) {
            cout << "Enter new name: ";
            cin >> contacts[index - 1].name; //update name
            cout << "Enter new phone number: ";
            cin >> contacts[index - 1].phoneNumber; //update phonenumb
            cout << "Contact updated successfully!\n";
        } else {
            cout << "Invalid contact number.\n";
        }
    }

    //function po to delete contact
    void deleteContact() {
        int index; //magstostore ng idedelete na contact number
        readContacts();
        cout << "Enter the number of the contact to delete: ";
        cin >> index;

        
        // checheck kung valid
        if (index > 0 && index <= contacts.size()) {
            contacts.erase(contacts.begin() + index - 1);
            cout << "Contact deleted successfully!\n";
        } else {
            cout << "Invalid contact number.\n";
        }
    }
};

int main() {
    ContactManager manager; //create an object to manage the contact
    int choice; //nagstostore ng users menu choice

    
    
    //loop  to keep showing menu
    do {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Update Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        //execute the respond function
        switch (choice) {
            case 1:
                manager.createContact(); //add contact
                break;
            case 2:
                manager.readContacts(); //view contact
                break;
            case 3:
                manager.updateContact(); //update contact
                break;
            case 4:
                manager.deleteContact(); //delete contact
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5); //paulitulit pag ayaw padin mag exit

    return 0; //end of code
}
