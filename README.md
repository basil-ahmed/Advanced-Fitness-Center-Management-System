# Advanced-Fitness-Center-Management-System

## Introduction

This is a new version of the Fitness Center Management system, which is accessible by administrative staff and members. It stores and manages the fitness classes at the center. An admin can mainly add/delete fitness classes, and register a member. On the other hand, a member can mainly book a spot in a class, and cancel a booking.

The program utilizes the concepts of object-oriented programming (OOP) (this may include: Classes, inheritance, templates, and error handling).
        
## Implementation

### Initialization:

1. At the beginning, the latest system files are to be loaded:
2. 
a) Admins.txt
b) Members.txt
c) FitnessClasses.txt

2. The system should have at least the following classes defined with their main attributes:
3. 
a) Admin Class – Admin ID, First name, Last name, Username, Password.
b) Member Class – Member ID, First name, Last name, Username, Password.
c) FitnessClass Class – Class ID, Class Name, Class date, Class time, Maximum
capacity, Room number, List of members.
 - The list of members should be implemented as a linked list-based stack of member IDs.

### Main Operations:

1. The program should print out a welcome message and ask the user to identify themselves either as an administrative staff or as a member. Figure 1 shows an example illustration of how the expected user interface should look like and how the different operations should be invoked. Refrain from asking the user to enter a long input to invoke a task; a number from the list should suffice.

2. The system will ask the user to log in by providing their credentials (username and password). If the credentials are valid, the corresponding (terminal) interface will appear with the list of all possible actions they can choose from with respect to their category.
a) If invalid credentials are provided, a message should appear asking the user to re- enter their credentials.
b) Only registered members can log in to the system.
system should have at least the following classes defined with their main attributes:

3. login(username, password): Any registered user should be able to login by entering a valid set of username and password, with respect to their category.

4. registerMember(firstname, lastname): An admin should be able to register a member in the system by providing the member’s first name and the last name. The member ID, username and password of the new member should be generated automatically as follows:

a) Member ID: a randomly generated number of 4 digits. You need to make sure the generated ID is unique. (Hint: you may use the rand() method from cstdlib (sodlib.h) headerfile, e.g. int pw = rand()%100; //pw in the range 0 to 99)
b) Username: lowercase the first name and concatenate it with the member ID.
c) Password: lowercase the last name and concatenate it with another randomly
generated number of 4 digits.

5. registerAdmin(firstname, lastname): An admin should be able to register another admin in the system by providing the admin’s first name and the last name. The admin ID, username and password of the new member should be generated automatically as follows:

a) Admin ID: a randomly generated number of 4 digits. You need to make sure the generated ID is unique.
b) Username: lowercase the first name and concatenate it with the admin ID.
c) Password: lowercase the last name and concatenate it with another randomly
generated number of 4 digits.

6. viewMemberList(): An admin should be able to view the current list of members in the system. For each member on the list, display the member ID, First name and Last name.

7. addFitnessClass(..): An admin should be able to add a new fitness class, which is initially with an empty list of members, by providing the following details:

Class ID, Class Name, Class date, Class time, Maximum capacity (default of 10), Room number

8. deleteFitnessClass(class_id): An admin should be able to delete a fitness class by providing its ID.

9. updateClassDetails(class_id): An admin should be able to update a class assigned room/date/time by providing the class ID. The user should be able to choose what data member to update. A single data member is to be updated with every call of this method.

10. changeClassCapacity(class_id, new_cap): An admin should be able to change the capacity of a class by providing the class ID and the updated value (the min and max capacity to assign are 5 and 15, respectively). If the class is currently at full capacity and the new capacity is less than the current capacity by n spots, then the last n members in registration will be removed from the list of members for that class.

11. splitClass(class_id, cap): An admin should be able to split an existing class (identified by its ID) into two classes.

a) The capacity of the two resulting classes can be provided by the admin. If there is no value provided by the admin for the capacity, then the default capacity (10) will be assigned as the capacity for both classes.
b) One of the classes will have the original information of the class to be split, while the other one will have a new ID, and may have different time and date if the admin choses to, but the class name will remain the same.
c) If the original class has some registered members and the new assigned capacity is less than the number of registered members by n spots, then the last n members in registration will be moved to the second class.

12. bookAClass(class_id): A member should be able to book a spot in a class, if the maximum capacity has not been reached yet, by providing the class ID.
a) As a result, the member will be added to the list of members of that class.

13. viewClassesWithVacancies(): Any user should be able to view the list of classes that are not yet full. For each class in the list, display all the class information, except for the class capacity and the list of members.

14. viewBookingList(): A member should be able to view a list of their current bookings. For each booking on the list, display class name, date, time and room number.

15. cancelBooking(class_id): A member should be able to cancel a booking by providing the class ID. The class’s list of members should be updated accordingly.

16. logout(): Any user should be able to logout from the program properly. Another user may login afterwards.

17. quitProgram(): Any user should be able to quit the program properly.
The system should create files with the data recorded during the current session

a) The list of classes should be saved in a “FitnessClasses.txt” file. For each class record, the values of all the data members should be saved, comma separated, as follows [Class ID, Class Name, Class date, Class time, Maximum capacity, Room number, List of Members]. The list of members should contain the list of member IDs, e.g. [5879,4380,9090].
Example of a class record: 1,Boxing,23-09-21,16:00,10,2,[5879,4380,9090]
b) The list of Admin should be saved in a “Admins.txt” file. For each admin record, the values of all the data members should be saved, comma separated, [Admin ID, First name, Last name, Username, Password].
Example of an admin record: 6564,Mai,Oudah,mai6564,oudah8382
c) The list of members should be saved in a “Members.txt” file. For each member record, the values of all the data members should be saved, comma separated [Member ID, First name, Last name, Username, Password].
Example of a member record: 5879,Jones,Ray,jones5879,ray8422

• You have to use linked lists to store/contain the instances created from each class in any open session of the program.
• The system should ask for the relevant information needed to be provided by the user for each of the aforementioned operations.
• You can add more classes/operations as you see fit.
• The system should handle errors, missing and invalid input.
• The system should print out a message indicating that an operation was completed successfully.
