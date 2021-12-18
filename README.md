# Contact Book in C Language
---
### **Requirements**
* Microsoft Visual Studio

### **Overview**
In this Project we will design a simple Contact Book in C language using Linked List data structure. This program is capable of Creating, Retrieving, Updating, Deleting and Sorting the Contact Book and also Inserting new elements into the Contact Book.

### **Main Functions**
1. **Insert Function**
> Take FirstName, Last Name, Number, Age, House Number as input from the user. Create a New Position Contact and store all the data in it. Search for First name and Last name in the Contact Book using Find Function. If that Contact already exists ten don’t add the Contact otherwise add the Contact at the start of the Linked List.

2. **Find Function**
> Take First Name, Last Name, and the List as input. Then Traverse the list using while loop until the contact with that First Name and Last Name is not found or the end of the list is not reached. If that Contact is found then return that Position.

3. **Edit Function**
> Take First Name, Last Name, and List as input. Find that Contact using Find Function. If found update all attributes of that Contact by taking input from the user.

4. **Delete Function**
> Take First Name, Last Name, and List as input. Find the Previous Contact of that Contact Using FindPrevious Function. Point that Contact to the Next of the Contact you want to delete. Bypass the deleted Contact.

5. **Sorting Function**
> Take Linked List as input and use bubble sort to sort the contacts. The first for loop will start at the First Contact and run until last Contact is reached. The second for loop will start from the Next of that Contact and run until the Last Contact is reached. If the ASCII value of First character of First Name of Contact is greater than the ASCII value of Next Contact then Swap the data of two Contacts.

### **Time Complexities**
| **Function** | **Best Case Running Time** | **Worst Case Running Time** |
| ------------ | -------------------------- | --------------------------- |
| Insert       | O(1)                       | O(N)                        |
| Find         | O(1)                       | O(N)                        |
| Delete       | O(1)                       | O(N)                        |
| Edit         | O(1)                       | O(N)                        |
| Sort         | O(N^2)                     | O(N^2)                      |

### **Outputs**
Creating a contact
> ![Contact](https://drive.google.com/uc?export=view&id=1pwsk4uPk-xbJ0uv8aMS8TVq9kokyGuTz)

Displaying the contact book
> ![Contact](https://drive.google.com/uc?export=view&id=1ThKe_mTVos2pCLG7btQLznUYf9kCLiat)

Editing a contact
> ![Contact](https://drive.google.com/uc?export=view&id=1DPBVfniPw9Y0MldY-nDE6nJPxUfV1LwP)

Deleting a contact
> ![Contact](https://drive.google.com/uc?export=view&id=11XmvZWRsuYCn0mSLr6cYNYJ9rgAkbP_m)

Loading contacts from a file
> ![Contact](https://drive.google.com/uc?export=view&id=19LlytWZUbd7st0IvkB0MN8m3FFjdco0B)

Displaying the loaded contacts
> ![Contact](https://drive.google.com/uc?export=view&id=1NrdPQ2IkL4W9zDXFJkc9CoUwJ-TMVDnF)

The file format for the load test is as follows,

FirstName   LastName    PhoneNumber     Age     HouseNo.
> ![Contact](https://drive.google.com/uc?export=view&id=1dDXd5souncJbf2Ij46MrE89donS5X02B)
