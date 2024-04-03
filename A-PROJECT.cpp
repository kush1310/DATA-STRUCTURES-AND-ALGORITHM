// MICRO-PROJECT FOR DATA STRUCTURE AND ALGORITHM
// MADE BY:- 
// KUSH AMIT SHAH [70] [LEADING CREATOR]

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// USING THE STRUCTURE FOR STORING DETAILS

struct Contact 
{
    string name;
    string phoneNumber;
};

// USING CONCEPT OF CLASS

class TelephoneDirectory 
{
	
private:
    vector<Contact> contacts;

public:
	
	// FUNCTION TO ADD THE CONTACT
	
    void addContact(const Contact& contact) 
	{
        contacts.push_back(contact);
    }
	
	// FUNCTION TO SEARCH THE CONTACT
	
    void searchContact(const string& name) 
	{
        auto it = find_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) -> bool 
		{
            return contact.name == name;
        });

        if (it != contacts.end()) 
		{
            cout << "NAME: " << it->name << ", PHONE NUMBER: " << it->phoneNumber << endl;
        } 
		
		else 
		{
            cout << "CONTACT NOT FOUND... PLEASE TRY AGAIN!" << endl;
        }
    }
	
	// FUNCTION TO MODIFY THE CONTACT
	
    void modifyContact(const string& name, const string& newPhoneNumber) 
	{
        auto it = find_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) -> bool 
		{
            return contact.name == name;
        });

        if (it != contacts.end()) 
		{
            it->phoneNumber = newPhoneNumber;
            cout << "CONTACT MODIFIED SUCCESSFULLY..." << endl;
        } 
		
		else 
		{
            cout << "CONTACT NOT FOUND..." << endl;
        }
    }
	
	// FUNCTION TO TRAVERSE THROUGH THE STORED LIST OF CONTACTS
	
    void listContacts() 
	{
        if (contacts.empty()) 
		{
            cout << "NO CONTACTS AVAILABLE...";
            return;
        }

        cout << "LISTING ALL CONTACTS..." << endl;
        for (const auto& contact : contacts) 
		{
            cout << "NAME: " << contact.name << ", PHONE NUMBER: " << contact.phoneNumber << endl;
        }
    }

	// FUNCTION TO DELETE THE CONTACT
	
    void deleteContact(const string& name) 
	{
        auto it = remove_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) 
		{
            return contact.name == name;
        });

        if (it != contacts.end()) 
		{
            contacts.erase(it, contacts.end());
            cout << "CONTACT DELETED SUCCESSFULLY..." << endl;
        } 
		
		else 
		{
            cout << "CONTACT NOT FOUND...";
        }
    }
};

// THE MAIN FUNCTION

int main() 
{
    TelephoneDirectory directory;
    
    while (true) 
	{
        cout <<endl << "REGISTRY: " << endl;
        cout << "1. ADD CONTACTS " << endl;
        cout << "2. SEARCH CONTACTS " << endl;
        cout << "3. MODIFY CONTACTS " << endl;
        cout << "4. LIST CONTACTS " << endl;
        cout << "5. DELETE CONTACTS " << endl;
        cout << "6. QUIT " <<endl;
        cout << "ENTER YOUR CHOICE: ";

        int choice;
        cin >> choice;

        switch (choice) 
		{
			
			// CASE 1 TO ADD THE CONTACT
			
            case 1: 
			{
                Contact newContact;
                cout << "ENTER NAME:- " << endl;
                cin.ignore(); 
                getline(cin, newContact.name);
                cout << "ENTER PHONE NUMBER:- " << endl;
                cin >> newContact.phoneNumber;
                directory.addContact(newContact);
                cout << "CONTACT ADDED SUCCESSFULLY..." << endl;
                break;
            }
            
            // CASE 2 FOR SEARCHING THE CONTACT
            
            case 2: 
			{
                string searchName;
                cout << "ENTER NAME TO SEARCH: " << endl;
                cin.ignore();
                getline(cin, searchName);
                directory.searchContact(searchName);
                break;
            }
            
            // CASE 3 TO MODIFY THE EXISTING CONTACT
            
            case 3: 
			{
                string modifyName, newPhoneNumber;
                cout << "ENTER EXISTING NAME TO MODIFY: " << endl;
                cin.ignore();
                getline(cin, modifyName);
                cout << "ENTER NEW PHONE NUMBER: " << endl;
                cin >> newPhoneNumber;
                directory.modifyContact(modifyName, newPhoneNumber);
                break;
            }
            
            // CASE 4 TO LIST ALL THE STORED CONTACTS IN THE DIRECTORY
            
            case 4:
                directory.listContacts();
                break;
                
            // CASE 5 TO DELETE AN EXISTING CONTACT FROM THE DIRECTORY
            
            case 5: 
			{
                string deleteName;
                cout << "ENTER NAME TO DELETE: " << endl;
                cin.ignore();
                getline(cin, deleteName);
                directory.deleteContact(deleteName);
                break;
            }
            
            // CASE 6: THE EXIT MENU
            
            case 6:
            	cout << "SYSTEM EXIT SUCCESSFUL..... EXIT PIN: 192.168.12.5..." << endl;
            	cout << "THIS PROJECT IS DEVELOPED BY: " << endl;
            	cout << "KUSH AMIT SHAH (70) [LEADING CREATOR]" << endl;
                return 0;
            
            // DEFAULT CASE FOR INVALID CHOICE
            
			default:
                cout << "INVALID CHOICE... PLEASE TRY AGAIN!!!";
        }
    }
    return 0;
}
