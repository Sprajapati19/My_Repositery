class Library:
    def __init__(self, Books):
        self.Books = Books
    
    def DisplayAvailableBooks(self):
        print(f"***Books Avalable in the Library are :")
        for i,item in enumerate(self.Books):
            print(str(i+1) + ")",item)
        print()
    
    def BorrowBook(self, BookName):
        if BookName in self.Books:
            print(f"Congratulation, You have been issued {BookName} book. please return the book within 30 days!")
            self.Books.remove(BookName)
        else:
            print(f"Sorry, {BookName} is currently either not available or someone issued the book, please wait until the book is available.")

    def ReturnBook(self, BookName):
        self.Books.append(BookName)
        print(f"Thanks {Student1.name} for returning the book, Hope you enjoyed reading it.")

class Student():
    def RequestBook(self):
        self.book = input("Enter the book name you want to issue : ")
        return self.book
    
    def ReturnBook(self):
        self.book = input("Enter the book name you want to return or donate to Library : ")
        return self.book

if __name__ == "__main__" :
    Books = ["Mathematics", "Social Science", "Python for Beginner", "C++ for Beginner"]
    Central = Library(Books)
    Student1 = Student()
    Student1.name = "Shubham"

    print('''\n*****Welcome to the Central Library of IIT Madras*****''')
    while(True):
        print('''
Press 1 :- To see the list of available Books
Press 2 :- To request issue of Book
Press 3 :- To return/Add the Book to library
Press 4 :- To exit the Library\n''' )
        try:
            num = int(input("Enter your choice : "))
            if num == 1:
                Central.DisplayAvailableBooks()
            elif num == 2:
                Central.BorrowBook(Student1.RequestBook())
            elif num == 3:
                Central.ReturnBook(Student1.ReturnBook())
            elif num == 4:
                print("Thanks for choosing this Library, Have a good day!")
                exit()
            else:
                print("Invalid entry! try again")
        except ValueError:
                print("Invalid entry pleaes enter a number as given in description!")