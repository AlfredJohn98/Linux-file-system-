# Linux-file-system-
This program is written by alfred john using c++. it is a linux based file system with authentication and access control using a specific model with 3 level of user access control 

Program user clearance 

 Create	= Create files
 Read = Read files
 Write = Write into files
 List = List all the files
 Save = Save files			  
 


User Clearance == 0
Create	- Access Denied
Read	- Access Denied
Write	- Access Denied
List	- Allowed (0 and 1)
Save	- Access Denied

User Clearance == 1
Create	- Access Denied
Read	- Allowed (0 and 1)
Write	- Access Denied
List	- Allowed (0 and 1)
Save	- Access Denied

User Clearance == 2
Create	- Allowed (To all files)
Read	- Allowed (To all files)
Write	- Allowed (To all files)
List	- Allowed (To all files)
Save	- Allowed (To all files)


When the program launches the terminal will require user to enter a command filesystem -i 
Then the program will show menu 

1. Run file system without existing user
2. Run file system with existing user
3. Exit file system




If menu == 1

1 - Enter a username to create the account if username is taken program will shutdown

2 - Enter the captcha if captcha entered wrongly enter again till valid 

3 - Enter a password according to the passwd policy which is :
    Follow the instructions to create a strong password
    1.Min 8 characters
    2.Min 1 symbol
    3.Min 1 number
    4.Max 16 characters
 
4 = Enter the password again till valid to passed policy

5 = Enter user clearance 

When all above is completed the program will set user a group to user depending on user clearance level.
All user details will be hashed and stored in salt, passwd and shadow files.


If menu == 2

1 - Enter the username and password that was previous created, and the program will get 
    all the details combine and see if it matches the salt, passwd and shadow files. 
    Before this for verification program will prompt a captcha 

2 - After login user will be given file operation:
    Create 
    Read 
    Write 
    List 
    Save 
    Exit 
This options will work according to the user clearance set during the creating of the user account 

If menu == 3 

Exit program 

All file clearance details will be store in Files.Store
