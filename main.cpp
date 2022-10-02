#include <iostream>
#include <ctime>
#include <random>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

template <typename T>
class Node
{
    private:
        T elem;
        Node<T>* next;
        
    public:
        Node(T elem) : elem(elem), next(NULL) {}

        // To access the private members
        template <typename E> friend class LinkedList;
        friend int loginAdmin(string username, string password);
        friend int loginMember(string username, string password);
        friend void updateClassDetails(int classID);
        friend void deleteFitnessClass(int classID);
        friend void viewClassesWithVacancies();
        friend void viewMemberList();
        friend void bookAClass(int classID);
        friend void viewBookingList();
        friend void cancelBooking(int classID);
        friend void changeClassCapacity(int classID, int cap);
        // friend FitnessClass splitClass(int classID, int cap = 10);
        friend int main();
        friend void quitProgram();
};

template <typename T>
class LinkedList
{
    private:
        Node<T>* head;

    public:
        LinkedList();
        ~LinkedList ();
        bool empty();
        void addFront(T elem); 
        void removeFront();
        void remove(T elem);
        T front();
        int countElem(int elem);
        int getIndexOf(int elem);
        void display();
        void next();
        
        // To access the private members
        friend int loginAdmin(string username, string password);
        friend int loginMember(string username, string password);
        friend void updateClassDetails(int classID);
        friend void deleteFitnessClass(int classID);
        friend void viewClassesWithVacancies();
        friend void viewMemberList();
        friend void bookAClass(int classID);
        friend void viewBookingList();
        friend void cancelBooking(int classID);
        friend void changeClassCapacity(int classID, int cap);
        // friend FitnessClass splitClass(int classID, int cap = 10);
        friend int main();
        friend void quitProgram();
};

    template <typename T> LinkedList<T>::LinkedList() 
    {
        this->head = NULL;
    }

    template <typename T> LinkedList<T>::~LinkedList() 
    {
        while (head != NULL) 
        {
            removeFront();
        }

        delete head;
    }

    template <typename T> bool LinkedList<T>::empty() 
    {
        if (head == NULL)
        {
            return true;
        }

        return false;
    }

    template <typename T> void LinkedList<T>::addFront(T elem)
    {
        Node<T>* v = new Node<T>(elem);
        v->elem = elem;
        v->next = head;
        head = v;
    }

    template <typename T> void LinkedList<T>::removeFront() 
    {
        Node<T>* old = head;
        head = old->next;
        delete old;
    }

    template <typename T> void LinkedList<T>::remove(T elem) 
    {
        
        while (true) 
        {

            if (head == NULL) 
            {
                cout<<"List is already empty!"<<endl;
                break;
            }
            
            if (head->next == NULL && head->elem == elem) 
            {
                delete head;
                head = NULL;
                cout<<"deleted successfully"<<endl;
                break;
            }
            
            if (head->elem == elem) 
            {
                removeFront();
            }
            
            Node<T> *temp = head;
            while (temp->next != NULL) 
            {
                if (temp->next->elem == elem) 
                {
                    delete temp->next;
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
            }
            break;
        }
    }

    template <typename T> T LinkedList<T>::front() 
    {
        return head->elem;
    }

    template <typename T> void LinkedList<T>::next() 
    {
        head = head->next;
    }

    template <typename T> int LinkedList<T>::countElem(int elem) 
    {
        int count = 0;
        Node<T>* temp = head;

        // As element is found, increment count
        while (temp != NULL)
        {
            if (temp->elem == elem)
            {
                count++;
                temp = temp->next;
            }
            temp = temp->next;
        }

        return count;
    }

    template <typename T> int LinkedList<T>::getIndexOf(int elem) 
    {
        Node<T> *p = head;
        int index = 0;

        while (p != NULL)
        {

            if (p->elem == elem)
            {
                return index;
            }

            index+=1;
            p = p->next;
        }

        return -1;
    }

    template <typename T> void LinkedList<T>::display() 
    {
        cout<<"Head -> ";
        Node<T>* temp = head;

        while (temp != NULL)
        {
            cout<<temp->elem<<" -> ";
            temp = temp->next;
        }

        cout<<"NULL"<<endl;
    }

class Stack
{
    private:
        LinkedList<int> S;
        int n;

    public :
        Stack();
        int size();
        bool empty();
        int top();
        void push(int e);
        void pop();
        void remove(int elem);

};

    Stack::Stack(): S(), n(0) 
    {}

    int Stack::size() 
    {
        return n;
    }

    bool Stack::empty() 
    {
        if (n == 0) 
        {
            return true;
        }

        return false;
    }

    int Stack::top() 
    {
        if (empty()) 
        {
            cout<<"No Top existing! The stack is Empty."<<endl;
            exit(1);
        }
        return S.front();
    }

    void Stack::push(int e) 
    {
        ++n;
        S.addFront(e);
    }

    void Stack::pop() 
    {
        if (empty()) 
        {
            cout<<"Nothing to Pop! The stack is Empty."<<endl;
            exit(1);
        }

        --n;
        S.removeFront();
    }

    void Stack::remove(int elem) 
    {
        int *tempArr = new int[n-1];
        int elementsInArray = 0;
        bool elementFound = false;
        
        if (empty()) 
        {
            cout<< "The array is already Empty!"<<endl;
            exit(1);
        }
        
        while (true)
        {
            if (elem == this->top())
            {
                elementFound = true;
                this->pop();
                break;
            }

            tempArr[elementsInArray] = this->top();
            elementsInArray++;
            
            this->pop();
        }

        // Shifting elements back if the element to remove doesn't exist
        for (int i = 0; i <= elementsInArray - 1; i++)
        {
            this->push(tempArr[i]);
        }
        
        if (elementFound == false) {
            cout<<"No such element existing to delete"<<endl;
        }
        
        delete []tempArr;
    }

class Admin
{
    private:

        int adminID;
        string firstName; 
        string lastName;
        string username;
        string password;
        
    public:

        Admin() 
        {}

        Admin(int adminID);
        
        int getAdminID();
        void setAdminID(int ID) ;
        string getUsername();
        string getPassword();
        void setUsername(string username);
        void setPassword(string password);
        string getFirstName();
        void setFirstName(string fName);
        string getLastName();
        void setLastName(string lName);
        
        void displayDetails();


    };

    // To make the default admin ID
    Admin::Admin(int adminID)
    {
        this->adminID = adminID;
        firstName = "admin";
        lastName = "admin";
        username = "admin1";
        password = "admin1";
    }

    int Admin::getAdminID()
    {
        return adminID;
    }

    void Admin::setAdminID(int ID)
    {
        this->adminID = ID;
    }

    string Admin::getFirstName()
    {
        return firstName;
    }

    string Admin::getLastName()
    {
        return lastName;
    }

    void Admin::setFirstName(string fName)
    {
        this->firstName = fName;
    }

    void Admin::setLastName(string lName)
    {
        this->lastName = lName;
    }

    string Admin::getUsername()
    {
        return username;
    }

    void Admin::setUsername(string username)
    {
        this->username = username;
    }

    string Admin::getPassword()
    {
        return password;
    }

    void Admin::setPassword(string password)
    {
        this->password = password;
    }

    void Admin::displayDetails()
    {
        cout<<"AdminID: "<<adminID<<endl;
        cout<<"First Name: "<<firstName<<endl;
        cout<<"Last Name: "<<lastName<<endl;
        cout<<"Username: "<<username<<endl;
        cout<<"Password: "<<password<<endl;
    }

class Member
{

    private:
        int memberID;
        string firstName, lastName;
        string username;
        string password;

    public:
        Member() 
        {}
        
        int getMemberID();
        void setMemberID(int ID);
        string getUsername();
        string getPassword();
        void setUsername(string username);
        void setPassword(string password);
        string getFirstName();
        void setFirstName(string fName);
        string getLastName();
        void setLastName(string lName);
        void displayDetails();
        
    };

    int Member::getMemberID()
    {
        return memberID;
    }

    void Member::setMemberID(int ID)
    {
        this->memberID = ID;
    }

    string Member::getFirstName()
    {
        return firstName;
    }

    string Member::getLastName()
    {
        return lastName;
    }

    void Member::setFirstName(string fName)
    {
        this->firstName = fName;
    }

    void Member::setLastName(string lName)
    {
        this->lastName = lName;
    }

    string Member::getUsername()
    {
        return username;
    }

    void Member::setUsername(string username)
    {
        this->username = username;
    }

    string Member::getPassword()
    {
        
        return password;
    }
    void Member::setPassword(string password)
    {
        this->password = password;
    }

    void Member::displayDetails()
    {
        cout<<"Member ID: "<<memberID<<endl;
        cout<<"First Name: "<<firstName<<endl;
        cout<<"Last Name: "<<lastName<<endl;
        cout<<"Username: "<<username<<endl;
        cout<<"Password: "<<password<<endl;
    }

int retrieveMID; // Current User Logged In

class FitnessClass
{

    private:
        int classID;
        string className, classDate, classTime;
        int maxCapacity, roomNo;
        int currCapacity;
        Stack classMembersList;

    public:

        FitnessClass(): maxCapacity(10), currCapacity(0)
        {}

        FitnessClass(int classID, string className, string classDate, string classTime, int maxCapacity, int roomNo);

        int getClassID();
        void setClassID(int ID);
        string getClassName();
        string getClassDate();
        string getClassTime();
        void setClassName(string className);
        void setClassDate(string classDate);
        void setClassTime(string classTime);
        int getMaxCapacity();
        int getRoomNo();
        int getCurrCapacity();
        void setMaxCapacity(int maxCapacity);
        void setRoomNo(int roomNo);
        void setCurrCapacity(int currCapacity);
        Stack getclassMembersList();

        void displayDetails();
        void addMemberToClass();
        void removeMemberFromClass();
        bool findMember();
        void addToList(int inputMID);
        void removeFromList();
        
        friend int main();
        friend void viewClassesWithVacancies(); 
        friend void viewBookingList();
        friend void quitProgram();
        
    };

    FitnessClass::FitnessClass(int classID, string className, string classDate, string classTime, int maxCapacity, int roomNo)
    {
        this->classID = classID;
        this->className = className;
        this->classDate = classDate;
        this->classTime = classTime;
        this->maxCapacity = maxCapacity;
        this->roomNo = roomNo;
        this->currCapacity = 0;
    }

    int FitnessClass::getClassID()
    {
        return classID;
    }

    void FitnessClass::setClassID(int ID)
    {
        this->classID = ID;
    }

    string FitnessClass::getClassName()
    {
        return className;
    }

    string FitnessClass::getClassDate()
    {
        return classDate;
    }

    string FitnessClass::getClassTime()
    {
        return classTime;
    }

    void FitnessClass::setClassName(string className)
    {
        this->className = className;
    }

    void FitnessClass::setClassDate(string classDate)
    {
        this->classDate = classDate;
    }

    void FitnessClass::setClassTime(string classTime)
    {
        this->classTime = classTime;
    }

    int FitnessClass::getMaxCapacity()
    {
        return maxCapacity;
    }

    int FitnessClass::getRoomNo()
    {
        return roomNo;
    }

    void FitnessClass::setMaxCapacity(int maxCapacity)
    {
        this->maxCapacity = maxCapacity;
    }

    void FitnessClass::setRoomNo(int roomNo)
    {
        this->roomNo = roomNo;
    }

    int FitnessClass::getCurrCapacity()
    {
        return currCapacity;
    }

    void FitnessClass::setCurrCapacity(int currCapacity)
    {
        this->currCapacity = currCapacity;
    }

    Stack FitnessClass::getclassMembersList()
    {
        return classMembersList;
    }

    void FitnessClass::displayDetails()
    {
        cout<< "Class ID: "<<classID<<endl;
        cout<< "Class name: "<<className<<endl;
        cout<< "Class Date: "<<classDate<<endl;
        cout<< "Class Time: "<<classTime<<endl;
        cout<< "Room Number: "<<roomNo<<endl;
    }

    void FitnessClass::addMemberToClass()
    {
        classMembersList.push(retrieveMID);
        currCapacity++;
    }

    void FitnessClass::removeMemberFromClass()
    {
        classMembersList.remove(retrieveMID);
        currCapacity--;
    }

    void FitnessClass::addToList(int inputMID)
    {
        currCapacity = currCapacity + 1;
        classMembersList.push(inputMID);
    }

    void FitnessClass::removeFromList()
    {
        currCapacity = currCapacity + 1;
        classMembersList.pop();
        currCapacity--;
    }

// Global Variables
LinkedList<Admin> adminsList;
LinkedList<Member> membersList;
LinkedList<FitnessClass> fitnessClassesList;

// Function Prototypes

int loginAdmin(string username, string password);
int loginMember(string username, string password);
string login(string username, string password);
Admin registerAdmin(string firstName, string lastName);
Member registerMember(string firstName, string lastName);
void viewMemberList();
FitnessClass addFitnessClass();
void deleteFitnessClass(int classID);
void updateClassDetails(int classID);
void changeClassCapacity(int classID, int cap);
FitnessClass splitClass(int classID, int cap = 10); 
void bookAClass(int classID);
void viewClassesWithVacancies();
void viewBookingList();
void cancelBooking(int classID);
string logout();
void quitProgram();

//Operater Overload
bool operator==(FitnessClass a, FitnessClass b)
{
    return a.getClassID() == b.getClassID();
}

int main()
{

    srand(time(NULL));
    
    // Load Admin Data
    ifstream adminData("Admins.txt");

    if (adminData.is_open())
    {
        string line;
        int i;
        i = 1;
        while (getline(adminData, line))
        {
            stringstream ss(line);

            string ID, fname, lname, user, pass;
            getline(ss, ID, ',');
            getline(ss, fname, ',');
            getline(ss, lname, ',');
            getline(ss, user, ',');
            getline(ss, pass, ',');

            Admin tempAdmin;

            tempAdmin.setAdminID(stoi(ID));
            tempAdmin.setFirstName(fname);
            tempAdmin.setLastName(lname);
            tempAdmin.setUsername(user);
            tempAdmin.setPassword(pass);

            adminsList.addFront(tempAdmin);
        }
    }
    else
    {
        cerr << "Error! File could not be opened." << endl;
        exit(1);
    }
    // End of loading Admin Data

    // Load Member Data
    ifstream memberData("Members.txt");

    if (memberData.is_open())
    {
        string line;
        int i;
        i = 0;
        while (getline(memberData, line))
        {
            stringstream ss(line);

            string ID, fname, lname, user, pass;
            getline(ss, ID, ',');
            getline(ss, fname, ',');
            getline(ss, lname, ',');
            getline(ss, user, ',');
            getline(ss, pass, ',');

            Member tempMember;

            tempMember.setMemberID(stoi(ID));
            tempMember.setFirstName(fname);
            tempMember.setLastName(lname);
            tempMember.setUsername(user);
            tempMember.setPassword(pass);

            membersList.addFront(tempMember);
        }
    }
    else
    {
        cerr << "Error! File could not be opened." << endl;
        exit(1);
    }
    // End of loading Member Data

    // Load Fitness Classes Data
    ifstream classesData("FitnessClasses.txt");

    if (classesData.is_open())
    {
        string line;
        int i;
        i = 0;

        while (getline(classesData, line))
        {
            stringstream ss(line);

            string ID, name, date, time, cap, room, members;
            getline(ss, ID, ',');
            getline(ss, name, ',');
            getline(ss, date, ',');
            getline(ss, time, ',');
            getline(ss, cap, ',');
            getline(ss, room, ',');
            getline(ss, members, ']');

            FitnessClass tempClass(stoi(ID), name, date, time, stoi(cap)-3, stoi(room));

            fitnessClassesList.addFront(tempClass);

            members = members.substr(1);

            int j;
            j = 0;

            string their_IDs;
            stringstream input_members(members);

            while (getline(input_members, their_IDs))
            {
                stringstream ss1(their_IDs);

                string IDs[stoi(cap)];

                getline(ss1, IDs[0], ',');

                while (j < stoi(cap) && IDs[j] != "")
                {
                    getline(ss1, IDs[j+1], ',');
                    tempClass.addToList(stoi(IDs[j]));
                    j++;

                }

            }

            tempClass.setCurrCapacity(j);
            i++;
        }
    }
    else
    {
        cerr << "Error! File could not be opened." << endl;
        exit(1);
    }
    // End of loading Fitness Classes Data

    // Default Admin ID
    Admin mainAdmin(1);
    adminsList.addFront(mainAdmin);

    bool if_end = false;

    // Validation for Correct Credentials
    while (if_end == false)
    {

        string username, password;
        if_end = true;

        string loginResult = login(username, password); // Collects the user type and its validation
        
        // If the credentials are wrong, ask for credentials again
        if (loginResult == "FalseAdmin" || loginResult == "FalseMember") 
        {
            if_end = false;
            continue;
        }

        while (loginResult == "TrueAdmin") // Interface for admin
        {
            int choice;
            // Menu
            cout<<endl<<"The list of available operations for Admins are: "<<endl;
            cout<<"1) Register a new Admin"<<endl;
            cout<<"2) Register a new Member"<<endl;
            cout<<"3) View the current List of Members"<<endl;
            cout<<"4) Add a Fitness Class"<<endl;
            cout<<"5) Delete a Fitness Class"<<endl;
            cout<<"6) Update the details of a fitness class"<<endl;
            cout<<"7) Change the Capacity of the Class"<<endl;
            cout<<"8) Split the Class"<<endl;
            cout<<"9) Display the classes with vacancies"<<endl;
            cout<<"10) Logout"<<endl;
            cout<<"0) Quit the Program"<<endl;
        
            cin >> choice;

            switch (choice) {
                case 1:
                {
                    Admin newAdmin;
                    
                    string firstName, lastName;
                    cout << "Please enter New Admin's First Name: ";
                    cin >> firstName;
                    cout << "Please enter New Admin's Last Name: ";
                    cin >> lastName;
                    newAdmin = registerAdmin(firstName, lastName);

                    adminsList.addFront(newAdmin);
                    
                    break;
                }

                case 2:
                {
                    Member newMember;
                    
                    string firstName, lastName;
                    cout << "Please enter New Member's First Name: ";
                    cin >> firstName;
                    cout << "Please enter New Member's Last Name: ";
                    cin >> lastName;
                    newMember = registerMember(firstName, lastName);

                    membersList.addFront(newMember);

                    break;
                }
                    
                case 3:
                {
                    viewMemberList();
                    break;
                }

                case 4:
                {

                    FitnessClass class1;
                    class1 = addFitnessClass();

                    fitnessClassesList.addFront(class1);
                    
                    // Success Message
                    cout << "The class been successfully added." << endl;
                    break;
                }

                case 5:
                {
                    int classID;
                    cout << "Please enter the class ID: ";
                    cin >> classID;
                    
                    deleteFitnessClass(classID);

                    // Success Message
                    cout << "Class Deleted Successfully!" << endl;
                    break;
                }

                case 6:
                {
                    int classID;
                    cout << "Please enter the class ID: ";
                    cin >> classID;
                    
                    updateClassDetails(classID);
                    break;
                }

                case 7:
                {
                    int classID;
                    cout<< "Please enter the class ID: ";
                    cin>>classID;

                    int maxCap;
                    cout<< "Please enter the changed maximum capacity of the class: ";
                    cin>>maxCap;

                    changeClassCapacity(classID, maxCap);
                    break;

                }

                case 8:
                {

                    int classID;
                    cout<< "Please enter the class ID: ";
                    cin>>classID;

                    int maxCap;
                    cout<< "Please enter the changed maximum capacity of the class: ";
                    cin>>maxCap;

                    FitnessClass class1;
                    class1 = splitClass(classID, maxCap);

                    fitnessClassesList.addFront(class1);
                    break;

                }

                case 9:
                {
                    viewClassesWithVacancies();
                    break;
                }

                case 10:
                {
                    loginResult = logout();

                    if_end = false; // Goes back to the first screen

                    break;
                }

                case 0:
                {
                    quitProgram();
                }

                default:
                {
                    cout << "Please enter a valid number from the MENU presented above. " << endl;
                    break;
                }

            } 

        }

        while (loginResult == "TrueMember") // Interface for Member
        {
            int choice;

            // Menu
            cout<<endl<<"The list of available operations for Members are: "<<endl;
            cout<<"1) Book a Class"<<endl;
            cout<<"2) Display the classes with vacancies"<<endl;
            cout<<"3) Cancel Booking"<<endl;
            cout<<"4) Logout"<<endl;
            cout<<"5) Quit the Program"<<endl;
            cin >> choice;

            switch (choice) {
                case 1:
                {
                    int classID;
                    cout << "Welcome! Please enter the class ID of the class you wish to join." << endl;
                    cin >> classID;
                    
                    bookAClass(classID);
                    break;
                }
                case 2:
                {
                    viewClassesWithVacancies();
                    break;
                }
                    
                case 3:
                {
                    viewBookingList();
                    break;
                }
                    
                case 4:
                {
                    int classID;
                    cout << "Hi! We're sad to see you leave. Please enter the classID: " << endl;
                    cin >> classID;
                    
                    cancelBooking(classID);
                    break;
                }
                
                case 5:
                {
                    loginResult = logout();
                    if_end = false;
                    break;
                }

                case -1:
                {
                    quitProgram();
                }

                default:
                {
                    cout<<"Invalid choice! Please enter a valid choice from the MENU above."<<endl;
                    break;
                }
            }
        }
    }

    return(0);
}

// Functions Definitions

int loginAdmin(string username, string password)
{
    
    bool loggedIn = false;
    int login = 0;
    Node<Admin> *tempAdmin = adminsList.head;

    while (true) 
    {
        if (tempAdmin!= NULL && tempAdmin->elem.getUsername() == username) 
        {

            if (tempAdmin->elem.getPassword() == password) 
            {

                loggedIn = true;
                cout << "Log In Successful!"<<endl<<endl;
                return 1;
            }
            else 
            {
                cout << "WRONG PASSWORD, PLEASE TRY AGAIN!"<<endl<<endl;
                return 2;
            }
        }
        if (tempAdmin == NULL) 
        {
            cout << "ADMIN NOT FOUND, PLEASE TRY AGAIN!"<<endl<<endl;
            return 2;
        }
        tempAdmin = tempAdmin->next;
    }
}

int loginMember(string username, string password)
{

    bool loggedIn = false;
    int login;
    
    Node<Member> *tempMember = membersList.head;
    
    while (true) 
    {
        if (tempMember!=NULL && tempMember->elem.getUsername() == username) 
        {
            if (tempMember->elem.getPassword() == password) 
            {
                loggedIn = true;
                cout<<"Log In Successful!"<<endl<<endl;
                retrieveMID = tempMember->elem.getMemberID();
                return 1;
            }
            else 
            {
                cout<<"WRONG PASSWORD, PLEASE TRY AGAIN!"<<endl<<endl;
                return 2;
            }
        }

        if (tempMember == NULL) 
        {
            cout<<"MEMBER NOT FOUND, PLEASE TRY AGAIN!"<<endl<<endl;
            return 2;
        }
        tempMember = tempMember->next;
    }
}

string login(string username, string password)
{
    int counter = 0;
    string choice;
    bool loggedin;

    while (true)
    {

        if (counter==0)
        {

            cout << "Welcome to Fitness Management System!" << endl;
            cout << "Please enter you account type before we proceed: [member/admin]" << endl;
            cin >> choice;

            if (choice == "admin" or choice == "member")
            {
                break;
            }

        }

        else
        {

        cout << "Invalid account type! Please try again." << endl;
        cout << "Enter you account type before we proceed: [member/admin]" << endl;
        cin >> choice;

            if (choice == "admin" or choice == "member")
            {
                break;
            }

        }

        counter+=1;

    }
    
    cout << "Please write your Username: ";
    cin >> username;
    cout << "Please write your Password: ";
    cin >> password;
    
    string accountType;
    if (choice == "admin")
    {
        int temp;
        temp = loginAdmin(username, password);

        if (temp == 1)
        {
            accountType = "TrueAdmin";
        }
        if (temp == 2)
        {
            accountType = "FalseAdmin";
        }
        
    }
    else if (choice == "member")
    {
        int temp;
        temp = loginMember(username, password);

        accountType = "TrueMember";

        if (temp == 1)
        {
            accountType = "TrueMember";
        }
        if (temp == 2)
        {
            accountType = "FalseMember";
        }
    }
    return accountType;
}

Admin registerAdmin(string firstName, string lastName) 
{
    
    int adminID;
    string newAdmin_username, newAdmin_password;
    
    Admin admin1;
    
    // Generating username and password
    adminID = (random()% 8999) + 1000;
    admin1.setAdminID(adminID);
    

    transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
    admin1.setFirstName(firstName);

    transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);
    admin1.setLastName(lastName);
    
    newAdmin_username = firstName + to_string(adminID);
    admin1.setUsername(newAdmin_username);
    
    int randNum;
    srand(static_cast<unsigned int>(time(0)));
    randNum = (rand() % 8999) + 1000;
    newAdmin_password = lastName + to_string(randNum);
    admin1.setPassword(newAdmin_password);
    
    cout<<"The Username of the new Admin is: "<<newAdmin_username<<endl;
    cout<<"The Password of the new Admin is: "<<newAdmin_password<<endl;
    cout<<"Admin account added succesfully!"<<endl<<endl;

    return admin1;
}

Member registerMember(string firstName, string lastName) 
{

    int memberID;
    string newMember_username, newMember_password;

    Member member1;
    
    // Generating username and password
    memberID = (random()% 8999) + 1000;
    member1.setMemberID(memberID);

    transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
    member1.setFirstName(firstName);

    transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);
    member1.setLastName(lastName);
    
    newMember_username = firstName + to_string(memberID);
    member1.setUsername(newMember_username);
    
    int randNum;
    srand(static_cast<unsigned int>(time(0)));
    randNum = (rand() % 8999) + 1000;
    newMember_password = lastName + to_string(randNum);
    member1.setPassword(newMember_password); 
    
    cout<<"The Username of the new Admin is: "<<newMember_username<<endl;
    cout<<"The Password of the new Admin is: "<<newMember_password<<endl;
    cout<<"Admin account added succesfully!"<<endl<<endl;

    return member1;
}

void viewMemberList() 
{
    Node<Member>* newMember = membersList.head;
    
    int memberCount = 0;
    while (newMember != NULL) //as long as the head is not NULL, execute the following
    {
        cout<<endl<<"Member "<<memberCount+1<<endl;
        cout<<"MemberID: "<<newMember->elem.getMemberID()<<endl;
        cout<<"First Name: "<<newMember->elem.getFirstName()<<endl;
        cout<<"Last Name: "<<newMember->elem.getLastName()<<endl;
        
        memberCount++;
        newMember = newMember->next;
    }
    
    if (memberCount == 0) 
    {
        cout<<"No Members Currently Registered"<<endl;
    }
    else 
    {
        cout<<"Total members in the system: "<<memberCount<<endl<<endl;
    }
}

FitnessClass addFitnessClass() 
{
    
    string className, classDate, classTime;
    int classID, maxCapacity, roomNo;
    
    cout << "Enter a Class ID: ";
    cin >> classID;
    cout << "Enter the Class Name: ";
    cin >> className;
    cout << "Enter the Class Date: ";
    cin >> classDate;
    cout << "Enter the Class Time: ";
    cin >> classTime;
    cout << "Enter the Maximum Capacity: ";
    cin >> maxCapacity;
    cout << "Enter the Room Number: ";
    cin >> roomNo;
    
    FitnessClass newClass(classID, className, classDate, classTime, maxCapacity, roomNo);
    newClass.setCurrCapacity(0); 
    
    cout<<"Class Added!"<<endl;

    return newClass;
} 


void deleteFitnessClass(int classID) 
{
    Node<FitnessClass> *newFitnessClass = fitnessClassesList.head;
    
    while (true) 
    {
        if (newFitnessClass!=NULL && newFitnessClass->elem.getClassID() == classID) 
        {
            fitnessClassesList.remove(newFitnessClass->elem);
            break;
        }
        if (newFitnessClass == NULL) 
        {
            cout<<"Class Does Not Exist!"<<endl;
            break;
        }

        newFitnessClass = newFitnessClass->next;
    }
}

void updateClassDetails(int classID)
{
    Node<FitnessClass> *newFitnessClass = fitnessClassesList.head;
    
    while (true) 
    {
        if (newFitnessClass!=NULL && newFitnessClass->elem.getClassID() == classID) 
        {
            int choice;
            cout<<"1. Change the Name"<<endl;
            cout<<"2. Change the Date"<<endl;
            cout<<"3. Change the Time"<<endl;
            cout<<"4. Change the Maximum Capacity"<<endl;
            cout<<"5. Change the Room Number"<<endl;
            cin>>choice;
            
            switch (choice) {
                case 1:
                {
                    string newClassName;
                    cout<<"Enter the new name: ";
                    cin>>newClassName;
                    newFitnessClass->elem.setClassName(newClassName);
                    cout<<"Class Name changed!!"<<endl;
                    break;
                }
                    
                case 2:
                {
                    string newClassDate;
                    cout<<"Enter the new date: ";
                    cin>>newClassDate;
                    newFitnessClass->elem.setClassDate(newClassDate);
                    cout<<"Class Date changed!"<<endl;
                    break;
                }
                    
                case 3:
                {
                    string newClassTime;
                    cout<<"Enter the new time: ";
                    cin>>newClassTime;
                    newFitnessClass->elem.setClassTime(newClassTime);
                    cout<<"Class Time changed!"<<endl;
                    break;
                }
                    
                case 4:
                {
                    int newClassMacCapacity;
                    cout<<"Enter the new maximum capacity: ";
                    cin>>newClassMacCapacity;
                    newFitnessClass->elem.setMaxCapacity(newClassMacCapacity);
                    cout<<"Max Capacity changed!"<<endl;
                    break;
                }
                    
                case 5:
                {
                    int newClassRoomNo;
                    cout<<"Enter the new room number: ";
                    cin>>newClassRoomNo;
                    newFitnessClass->elem.setRoomNo(newClassRoomNo);
                    cout<<"Room Number changed!"<<endl;
                    break;
                }
                    
                default:
                {
                    cout<<"Invalid input! Try again.";
                    break;
                }
            }
            break;
        }

        if (newFitnessClass == NULL) 
        {
            cout << "Class Does Not Exist!" << endl;
            break;
        }

        newFitnessClass = newFitnessClass->next;
    }
}

void changeClassCapacity(int classID, int cap)
{
    Node<FitnessClass> *newFitnessClass = fitnessClassesList.head;

    while (true) 
    {

        if (newFitnessClass!=NULL && newFitnessClass->elem.getClassID() == classID) 
        {
            if (cap<newFitnessClass->elem.getCurrCapacity())
            {
                int diff = newFitnessClass->elem.getCurrCapacity() - cap;

                for (int i = 0; i < diff; ++i)
                {
                    newFitnessClass->elem.removeFromList();
                }
            }

            newFitnessClass->elem.setMaxCapacity(cap);

            cout<<"Class Capacity Successfully Changed!"<<endl;

            break;
        }

        if (newFitnessClass == NULL) 
        {
            cout << "No class existing with this classID!" << endl;
            break;
        }

        newFitnessClass = newFitnessClass->next;
    }
}

FitnessClass splitClass(int classID, int cap) 
{

   LinkedList<FitnessClass> newFitnessClass = fitnessClassesList;

   while (true) 
   {

        FitnessClass temp1 = newFitnessClass.front();

        if (temp1.getClassID() == classID) 
        {

            string classDate, classTime;
            int classID;
            
            cout << "Enter a Class ID: ";
            cin >> classID;
            cout << "Enter the Class Date: ";
            cin >> classDate;
            cout << "Enter the Class Time: ";
            cin >> classTime;

            temp1.setMaxCapacity(cap);

            FitnessClass class1(classID, temp1.getClassName(), classDate, classTime, cap, temp1.getRoomNo());

            if (cap<temp1.getCurrCapacity())
            {
                int diff = temp1.getCurrCapacity() - cap;

                for (int i = 0; i < diff; ++i)
                {
                    class1.addToList(temp1.getclassMembersList().top());
                    temp1.removeFromList();
                }
            }

            cout<<"Class Successfully Splitted!"<<endl;

            return class1;

            break;
        }

        fitnessClassesList.next();
    
    }
}

void bookAClass(int classID) 
{
    
    Node<FitnessClass> *newFitnessClass = fitnessClassesList.head;
    
    while (true) 
    {
        if (newFitnessClass!=NULL && newFitnessClass->elem.getClassID() == classID) 
        {
            int maxCap, currCap;
            maxCap = newFitnessClass->elem.getMaxCapacity();
            currCap = newFitnessClass->elem.getCurrCapacity();
            if (currCap < maxCap)
            {
                newFitnessClass->elem.addMemberToClass();
                cout<<"You have been successfully added to the class!"<<endl;
            }
            if (currCap == maxCap) 
            {
                cout<<"Sorry! The class is already FULL!"<<endl;
            }
            break;
        }

        if (newFitnessClass == NULL) 
        {
            cout<<"Class not found!"<<endl;
            break;
        }

        newFitnessClass = newFitnessClass->next;
    }
}

void viewClassesWithVacancies() 
{

    Node<FitnessClass> *newFitnessClass = fitnessClassesList.head;

    while (true) 
    {

        if (newFitnessClass!=NULL) 
        {

            if (newFitnessClass->elem.currCapacity < newFitnessClass->elem.maxCapacity) 
            {

                cout<<"Class ID: "<<newFitnessClass->elem.getClassID()<<endl;
                cout<<"Class Date: "<<newFitnessClass->elem.getClassDate()<<endl;
                cout<<"Class Name: "<<newFitnessClass->elem.getClassName()<<endl;
                cout<<"Class Time: "<<newFitnessClass->elem.getClassTime()<<endl;
                cout<<"Room No: "<<newFitnessClass->elem.getRoomNo()<<endl;
            }

        }

        if (newFitnessClass == NULL) 
        {
            break;
        }

        newFitnessClass = newFitnessClass->next;
    }
}

void viewBookingList() 
{
    
    Node<FitnessClass> *newFitnessClass = fitnessClassesList.head;
    bool found = false;
    
    int count = 0;
    
    while (true) 
    {
        if (newFitnessClass!=NULL) 
        {
            count++;

            Stack tempStack;

            while (true) 
            {
                if (newFitnessClass->elem.classMembersList.empty()) 
                {
                    break;
                }

                if (retrieveMID == newFitnessClass->elem.classMembersList.top()) 
                {
                    found = true;
                    cout<<"Class Name:"<<newFitnessClass->elem.getClassName()<<endl;
                    cout<<"Date: "<<newFitnessClass->elem.getClassDate()<<endl;
                    cout<<"Time: "<<newFitnessClass->elem.getClassName()<<endl;
                    cout<<"Room No: "<<newFitnessClass->elem.getRoomNo()<<endl;
                    break;
                }

                tempStack.push(newFitnessClass->elem.classMembersList.top());
                newFitnessClass->elem.classMembersList.pop();
            }

            while (true) 
            {
                if (tempStack.empty()) 
                {
                    break;
                }
                newFitnessClass->elem.classMembersList.push(tempStack.top());
                tempStack.pop();
                }
            }
        
        if (newFitnessClass == NULL && count == 0) 
        {
            cout<<"No bookings found for the Member!"<<endl;
        }
        
        if (newFitnessClass == NULL) 
        {
            break;
        }
        newFitnessClass = newFitnessClass->next;
    }
}

void cancelBooking(int classID) 
{
    Node<FitnessClass> *newFitnessClass = fitnessClassesList.head;
    
    while (true) 
    {
        if (newFitnessClass!=NULL && newFitnessClass->elem.getClassID() == classID) 
        {
            newFitnessClass->elem.removeMemberFromClass();
            cout<<"Booking Cancellation Succesfull!!"<<endl;
            break;
        }
        
        if (newFitnessClass == NULL) 
        {
            cout<<"Class not found!"<<endl;
            break;
        }
        newFitnessClass = newFitnessClass->next;
    }
}

string logout() 
{
    return "Admin/Member False"; // Anything works here
}

void quitProgram() 
{

        ofstream adminData;
        adminData.open("Admins.txt", ios::out);

        if (adminData.fail())
        {
            cerr << "Error! File could not be opened." << endl;
            exit(1);
        }

        ofstream memberData;
        memberData.open("Members.txt", ios::out);
        if (memberData.fail())
        {
            cerr << "Error! File could not be opened." << endl;
            exit(1);
        }
        
        ofstream classesData;
        classesData.open("FitnessClasses.txt", ios::out);
        if (classesData.fail())
        {
            cerr << "Error! File could not be opened." << endl;
            exit(1);
        }

        Node<Admin> *tempAdmin = adminsList.head;
        while (true) {
            if (tempAdmin!= NULL) {
                adminData << tempAdmin->elem.getAdminID() << "," << tempAdmin->elem.getFirstName() << "," << tempAdmin->elem.getLastName() << "," << tempAdmin->elem.getUsername() << "," << tempAdmin->elem.getPassword() << endl;
            }
            if (tempAdmin == NULL) {
                break;
            }
            tempAdmin = tempAdmin->next;
        }
        
        Node<Member> *tempMember = membersList.head;
        while (true) {
            if (tempMember!= NULL) {
                memberData << tempMember->elem.getMemberID() << "," << tempMember->elem.getFirstName() << "," << tempMember->elem.getLastName() << "," << tempMember->elem.getUsername() << "," << tempMember->elem.getPassword() << endl;
            }
            if (tempMember == NULL) {
                break;
            }
            tempMember = tempMember->next;
        }
        
        Node<FitnessClass> *tempClass = fitnessClassesList.head;
        while (true) {
            if (tempClass!= NULL) {
                classesData << tempClass->elem.getClassID() << "," << tempClass->elem.getClassName() << "," << tempClass->elem.getClassDate() << "," << tempClass->elem.getClassTime() << "," << tempClass->elem.getMaxCapacity() << "," << tempClass->elem.getCurrCapacity() << "," << "[";
                
                while(!tempClass->elem.classMembersList.empty())
                {
                    classesData << tempClass->elem.classMembersList.top() << ",";
                    tempClass->elem.classMembersList.pop();
                }
                
                classesData << "]" << endl;
            }
            if (tempClass == NULL) {
                break;
            }
            tempClass = tempClass->next;
        }
        
    exit(0);
}

