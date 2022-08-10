class Contacts:
    def __init__(self, ContactList):
        self.Contacts = ContactList

    def DisplayContacts(self):
        Numbers = self.Contacts.values()
        print("\nYour Contacts : ")
        for i, item in enumerate(self.Contacts):
            print(str(i+1) + ")", item, end=" : ")
            for j, k in enumerate(Numbers):
                if j == i:
                    print(k)

    def AddContact(self, Name, Number):
        self.Contacts[Name] = Number

    def RemoveContact(self, Name):
        if Name in self.Contacts:
            del self.Contacts[Name]
        else:
            print(f"{Name} is not in the Contacts, Try Another")


class ContactDetails:
    def AddContactName(self):
        Name = input("Enter Contact Name : ")
        return Name

    def AddContactNumber(self):
        Number = input("Enter Contact Number : ")
        return Number

    def RemoveContact(self):
        Name = input("Enter Contact Name : ")
        return Name


if __name__ == "__main__":
    ContactList = {"Shubham": '9644783742',
                   "Pankaj": '7869037024', "Jio": '9399773033'}
    Contact1 = Contacts(ContactList)
    NewContact = ContactDetails()

    while(True):
        Contact1.DisplayContacts()
        print('''
Press 1 :- Add New Contact
Press 2 :- Delete existing Contact
Press 3 :- Exit the Contacts\n''')
        try:
            num = int(input("Enter your choice : "))

            if num == 1:
                Contact1.AddContact(NewContact.AddContactName(),
                                    NewContact.AddContactNumber())

            elif num == 2:
                Contact1.RemoveContact(NewContact.RemoveContact())

            elif num == 3:
                print("Thanks for Looking your Contacts List!")
                exit()

            else:
                print("Invalid entry!")

        except Exception:
            print("Invalid entry please select as given in instructions!")