#include<iostream>
#include<string>
#include <iomanip> 


 class Contact
    {
        public:
            std::string FirstName;
            std::string LastName;
            std::string NickName;
            std::string PhoneNumber;

    };

class Phonebook
    {
        private:
            int NumofContacts;
            Contact contacts[8];

        public:
            Phonebook() : NumofContacts(0) {}

            void AddContact()
            {
                if (NumofContacts == 8)
                {
                    std::cout << "PhoneBook is full. Delete the old Chracters.\n";
                    NumofContacts--;
                }

                Contact NewContact;
                std::string input;

                std::cout << "Enter first name: ";
                std::getline(std::cin, NewContact.FirstName);

                std::cout << "Enter last name: ";
                std::getline(std::cin, NewContact.LastName);

                std::cout << "Enter nick name: ";
                std::getline(std::cin, NewContact.NickName);

                std::cout << "Enter phone number: ";
                std::getline(std::cin, NewContact.PhoneNumber);

                contacts[NumofContacts] = NewContact;
                NumofContacts++;
                

            }

            void SearchContact()
            {
                if (NumofContacts == 0){

                }


                std::cout << "Contacts:\n";
                std::cout << "----------------------------------------\n";
                std::cout << "Index    | First Name | Last Name  | Nickname  \n";
                std::cout << "----------------------------------------\n";

                for (int i = 0; i < NumofContacts; i++)
                {
                    std::cout << std::right << std::setw(8) << i + 1 << " | ";
                    std::cout << std::setw(10) << truncateText(contacts[i].FirstName) << " | ";
                    std::cout << std::setw(10) << truncateText(contacts[i].LastName) << " | ";
                    std::cout << std::setw(10) << truncateText(contacts[i].NickName) << "\n";   
                }

                std::cout << "----------------------------------------\n";

                int index;
                std::cout << "Enter the index of the contact to display: ";
                std::cin >> index;
                std::cin.ignore();
                
                if (index < 1 || index > NumofContacts)
                {
                    std::cout << "Invalid index.\n";
                    return;
                
                }
                
                index--;

                std::cout << "Contact information:\n";
                std::cout << "First Name: " << contacts[index].FirstName << "\n";
                std::cout << "Last Name: " << contacts[index].LastName << "\n";
                std::cout << "Nickname: " << contacts[index].NickName << "\n";
                std::cout << "Phone Number: " << contacts[index].PhoneNumber << "\n";
                 
                
            }

        private:
            std::string truncateText(const std::string& text, int maxLength = 10)
            {
                if (text.length() <= maxLength) 
                    return text;
                                   
                return text.substr(0, maxLength -1) + ".";
            }
    };





int main()
{
    Phonebook phonebook;

    std::string command;

    while (true)
    {

        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            phonebook.AddContact();
        }
        else if (command == "SEARCH")
        {
            phonebook.SearchContact();
        }
        else if (command == "Exit")
        {
            break;
        }  
    
    }

    return 0;
    

}