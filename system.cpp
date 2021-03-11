#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<ctime>
#include<regex>
#include <conio.h>
#include <iomanip>

#include "md5_header.h"
#include "functions.h"
#include "captcha.h"

using namespace std;



int system()
{

    int menu(1);

    tops:
    string filesys;
    cout << "Terminal >> ";
    getline(cin, filesys);

     if(filesys == "filesystem -i")
     {
       cout <<endl;
    do
    {
        cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
        cout << "1.Run file system without existing user" << endl;
        cout << "2.Run file system with existing user" << endl;
        cout << "3.Exit file system" << endl;
        cout << endl;

        do
        {
            if(!cin || menu<1 || menu>3)
            {
                cout << "Response: Invalid Input. Please enter again." << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }

            cout << "Choose Option >> ";
            cin >> menu;
        }while(!cin || menu<1 || menu>3);

        password="";

        if(menu!=3)
        {

        cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
            cout<<"Enter a the valid username "<<endl;
            cout <<"Account username >>";
            cin >> username;

            if(check_username(username)==true && menu==1)
            {
                cout<<endl;
                cout <<"The username you have entered already exist"<<endl;
                cout <<"The system will shut down"<<endl;
                cout <<"Shutting down system"<<endl;
                cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                break;
            }

            srand(time(0));
            int randomInt = rand()%5+5;
            for(unsigned int i=0;i<randomInt;++i)
            {
                rand_gen_captcha += generate_value(captcha_s,captcha_s_lgt);
            }
            cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
            cout <<"To proceed further please enter the capthca"<<endl;
            do
            {
                cout<<endl;
                cout << "Random generated code >>  " << rand_gen_captcha << endl;
                cout << "Please enter the captcha >>  ";
                cin >> user_capthca;
                cout<<endl;

                if(user_capthca!=rand_gen_captcha)
                {
                   cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                   cout<<"Invalid input"<<endl;
                   cout<<"The captcha you entered is invalid"<<endl;
                   cout<<"Please try again"<<endl;
                }
            }while(user_capthca!=rand_gen_captcha);

            rand_gen_captcha="";


            string promptPw("Please enter your password: ");
            do
            {
                cout << promptPw;
                do
                {
                    passwd_index = getch();
                    switch(passwd_index)
                    {
                        case 0:
                        {
                            getch();
                            break;
                        }

                        case 13:
                        {
                            cout<<endl;
                            break;
                        }
                        case 8:
                        {
                            if(promptPw.length()+password.length()>promptPw.length())
                            {
                                password.erase(password.end()-1);
                                cout<<passwd_index<<' '<<passwd_index;
                            }
                            break;
                        }
                        default:
                        {
                            password += passwd_index;
                            cout<<'*';
                            break;
                        }
                    }
                }while(passwd_index!=13);

                if(!regex_match(password,passwd_pol))
                {
                    password="";
                    cout<<endl;
                    cout <<"Follow the instructions to create a strong password"<<endl;
                    cout <<"Min 8 characters"<<endl;
                    cout <<"Min 1 symbol"<<endl;
                    cout <<"Min 1 number"<<endl;
                    cout <<"Max 16 characters"<<endl;
                    cout <<endl;
                }
            }while(!regex_match(password,passwd_pol));
        }

        if(menu==1)
        {

            string promptConfirmPw("Confirm the entered password   :");

            do
            {
                cout << promptConfirmPw;
                do
                {
                    repasswd_index = getch();
                    switch(repasswd_index)
                    {
                        case 0:
                        {
                            getch();
                            break;
                        }

                        case 13:
                        {
                            cout<<endl;
                            break;
                        }

                        case 8:
                        {
                            if(promptConfirmPw.length()+re_Password.length()>promptConfirmPw.length())
                            {

                                re_Password.erase(re_Password.end()-1);
                                cout<<repasswd_index<<' '<<repasswd_index;
                            }
                            break;
                        }
                        default:
                        {

                            re_Password += repasswd_index;

                            cout<<'*';
                            break;
                        }
                    }
                }while(repasswd_index!=13);

                if(re_Password!=password)
                {
                    re_Password="";
                    cout << "password  not matched." << endl;
                }
            }while(re_Password!=password);



            do
            {
                if(!cin || user_clearance_reg<0 || user_clearance_reg>2)
                {
                    cout << "Invalid Input."<< endl;
                    cout<<"Please try again"<<endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
                 cout <<"Set user clearance"<<endl;
                 cout<<endl;
                 cout<<"User Clearance - 0"<<endl;
                 cout<<"Create = Privilege denied"<<endl;
                 cout<<"Read   = Privilege denied"<<endl;
                 cout<<"Write  = Privilege denied"<<endl;
                 cout<<"List   = Privilege allowed (0 and 1)"<<endl;
                 cout<<"Save   = Privilege denied"<<endl;

                 cout<<endl;
                 cout<<"User Clearance - 1"<<endl;
                 cout<<"Create = Privilege denied"<<endl;
                 cout<<"Read   = Privilege allowed (0 and 1)"<<endl;
                 cout<<"Write  = Privilege allowed "<<endl;
                 cout<<"List   = Privilege allowed (0 and 1)"<<endl;
                 cout<<"Save   = Privilege denied."<<endl;

                 cout<<endl;
                 cout<<"User Clearance - 2"<<endl;
                 cout<<"Create = Privilege allowed"<<endl;
                 cout<<"Read   = Privilege allowed"<<endl;
                 cout<<"Write  = Privilege allowed"<<endl;
                 cout<<"List   = Privilege allowed"<<endl;
                 cout<<"Save   = Privilege allowed"<<endl;

                 cout<<endl;

                cout << "User clearance (0 or 1 or 2) :";
                cin >> user_clearance_reg;
            }while(!cin || user_clearance_reg<0 || user_clearance_reg>2);

            int user_GroupID;

            if(user_clearance_reg==0)
            {
                user_GroupID=000;
            }
            else if(user_clearance_reg==1)
            {
                user_GroupID=111;
            }
            else if(user_clearance_reg==2)
            {
                user_GroupID=222;
            }

            srand(time(0));


            for(int i=0;i<8;++i)
            {
                rand_gen_salt += generate_value(salt_s,salt_s_lgt);
            }

            ofstream out_file;
            out_file.open("salt.txt", ios::app);
            out_file << username << ":" << rand_gen_salt << endl;
            out_file.close();

            val_combine=password+rand_gen_salt;
            out_file.open("shadow.txt", ios::app);
            out_file << username << ":" << md5(val_combine) << ":" << user_clearance_reg << endl;
            out_file.close();

            int user_UserID;
            get_userid(user_clearance_reg,user_UserID);

            out_file.open("passwd.txt", ios::app);
            out_file << username << ":x:"
                          << setw(3) << setfill('0') << user_UserID+1 << ":"
                          << setw(3) << setfill('0') << user_GroupID
                          << ":Filesystem_User:/home/" << username
                          << ":/bin/bash" << endl;
            out_file.close();

        }

        else if(menu==2)
        {
            string retrivedSalt;

            if(account_validation(username)==true)
            {

                cout << username << " found in file :"<<endl;
                cout << "salt.txt "<<endl;
                cout << "passwd.txt" << endl;

                get_salts(username,retrivedSalt);

                cout << endl;
                cout << "Hashing process" << endl;
                cout << "Hash passwd >>" << md5(password+retrivedSalt) << endl;
                cout << endl;

                if(passwd_match(username,md5(password+retrivedSalt))==true)
                {
                    loging_process=true;
                    get_salt(username,md5(password+retrivedSalt),user_clearance_valid);

                    cout << "Searching for account " << username << " successful." << endl;
                    cout << "The clearance for the account is "<< user_clearance_valid<< endl;
                    cout <<"You have logged in successfully"<< endl;
                    cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                    cout <<endl;
                }
                else
                {
                     cout << "No matches" << endl;
                     cout <<"The system will shut down"<<endl;
                     cout <<"Shutting down system"<<endl;
                    break;
                }
            }

            else if(account_validation(username)==false)
            {
                cout<<endl;
                cout <<"The username you have entered does not exist"<<endl;
                cout <<"The system will shut down"<<endl;
                cout <<"Shutting down system"<<endl;
                break;
            }

            char e;
            char valid_E;
            char exitSystem('N');

            if(loging_process==true)
            {

                fstream out_file_Save;
                out_file_Save.open("Files.Store", ios::out | ios::app);

                do
                {
                    cout<<endl;
                    cout << "File system operation" << endl;
                    cout << endl;
                    cout << "1.Create" << endl;
                    cout << "2.Read" << endl;
                    cout << "3.Write" << endl;
                    cout << "4.List" << endl;
                    cout << "5.Save" << endl;
                    cout << "6.Exit\n" << endl;

                    do
                    {
                        cout << "Choose Option : ";
                        cin >> e;
                        valid_E = toupper(e);

                        if(valid_E!='1'
                           && valid_E!='2'
                           && valid_E!='3'
                           && valid_E!='4'
                           && valid_E!='5'
                           && valid_E!='6')
                        {
                            cout << "Invalid Input" << endl;

                        }
                    }while(valid_E!='1'
                           && valid_E!='2'
                           && valid_E!='3'
                           && valid_E!='4'
                           && valid_E!='5'
                           && valid_E!='6');

                    switch(valid_E)
                    {

                        case '1':
                        {
                            string fileName_Create;
                            int securityLevel_Create(0);

                            if(user_clearance_valid!=2)
                            {
                                cout << "Access denied" << endl;
                            }
                            else
                            {
                                cout << "Enter file name: ";
                                cin >> fileName_Create;

                                if(check_file_exist(fileName_Create)==true)
                                {
                                    cout << "File name already exist." << endl;
                                    break;
                                }
                                else
                                {
                                    do
                                    {
                                        if(!cin || securityLevel_Create<0 || securityLevel_Create>2)
                                        {
                                            cout << "Invalid Input" << endl;
                                            cin.clear();
                                            cin.ignore(INT_MAX, '\n');
                                        }

                                        cout << "user clearance 0,1,2 :";
                                        cin >> securityLevel_Create;
                                    }while(!cin || securityLevel_Create<0 || securityLevel_Create>2);

                                    ofstream createfile;
                                    createfile.open("./Filesystem/" + fileName_Create);
                                    createfile.close();

                                    ofstream createFile_FileStore;
                                    createFile_FileStore.open("Files.Store", ios::app);

                                    createFile_FileStore << fileName_Create << ":" << securityLevel_Create << endl;

                                    createFile_FileStore.close();

                                    cout << "File successfully created." << endl;
                                }
                            }

                            break;
                        }

                        case '2':
                        {
                            string fileName_Read;
                            ifstream open_file_Read;

                            if(user_clearance_valid==0)
                            {
                                cout << "Access denied" << endl;
                            }
                            else
                            {
                                cout << "Enter file name: ";
                                cin >> fileName_Read;

                                if(check_file_exist(fileName_Read)==true)
                                {
                                    cout << "File found" << endl;

                                    int file_SecurityLevel = (int)getfile_sec_level(fileName_Read).back()-48;

                                    if(user_clearance_valid==1 && file_SecurityLevel==2)
                                    {
                                        cout << "Access Denied" << endl;
                                    }
                                    else
                                    {
                                        cout << "Reading files" << endl;
                                        cout<<endl;
                                        open_file_Read.open("./Filesystem/" + fileName_Read);
                                        string readStuff;
                                        string total_readStuff;

                                        while(getline(open_file_Read,readStuff))
                                        {
                                            total_readStuff+=readStuff;
                                        }

                                        open_file_Read.clear();
                                        open_file_Read.seekg(0, ios::beg);

                                        total_readStuff.erase(remove(total_readStuff.begin(), total_readStuff.end(), ' '), total_readStuff.end());

                                        if(total_readStuff.size()!=0)
                                        {
                                            while(getline(open_file_Read,readStuff))
                                            {
                                                cout << readStuff << endl;
                                            }
                                            cout<<endl;
                                        }

                                        else
                                            cout << "None" << endl;

                                        open_file_Read.close();
                                    }
                                }
                                else

                                    cout<< endl;
                            }

                            break;
                        }

                        case '3':
                        {

                            string fileName_Write;

                            if(user_clearance_valid==0)
                            {
                                cout << "Access denied" << endl;
                            }
                            else
                            {
                                cout << "Enter the file name : ";
                                cin >> fileName_Write;

                                if(check_file_exist(fileName_Write)==true)
                                {
                                    cout << "File found." << endl;

                                    int file_SecurityLevel = (int)getfile_sec_level(fileName_Write).back()-48;

                                    if(user_clearance_valid==1 && (file_SecurityLevel==2 || file_SecurityLevel==1))
                                    {
                                        cout << "Access Denied" << endl;
                                    }
                                    else
                                    {
                                        ofstream write_file_Write;
                                        write_file_Write.open("./Filesystem/" + fileName_Write, ios::app);

                                        cout << "Write to file is allowed.\n" << endl;
                                        string writetofile;

                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');

                                        getline(cin,writetofile);
                                        write_file_Write << writetofile << endl;

                                        write_file_Write.close();

                                    }
                                }
                                else
                                    cout << "File not found" << endl;
                            }


                            break;
                        }

                        case '4':
                        {
                            ifstream open_file_List;

                            cout << "Reading files" << endl;

                            open_file_List.open("Files.Store");
                            string readStuff;

                            if(user_clearance_valid==0 || user_clearance_valid==1)
                            {
                                while(getline(open_file_List,readStuff))
                                {
                                    if((int)readStuff.back()-48==0 || (int)readStuff.back()-48==1)
                                        cout << readStuff.substr(0,readStuff.length()-2) << endl;
                                }
                            }
                            else
                            {
                                while(getline(open_file_List,readStuff))
                                {
                                    cout << readStuff.substr(0,readStuff.length()-2) << endl;
                                }
                            }
                            open_file_List.close();

                            break;
                        }

                        case '5':
                        {


                            if(user_clearance_valid!=2)
                            {
                                cout << "Access denied." << endl;
                            }
                            else
                            {
                                string fileName_Save;

                                cout << " Enter filename: ";
                                cin >> fileName_Save;

                                if(check_file_exist(fileName_Save)==true)
                                {
                                    if(check_file_exist(fileName_Save)==true)
                                    {
                                        cout<<endl;
                                        cout << "File saved" << endl;
                                    }
                                    else
                                    {
                                        cout << "The file does not exist" << endl;
                                        cout << "Please Enter user clearance  for the file." << endl;
                                        int securityLevel_Save(0);

                                        do
                                        {
                                            if(!cin || securityLevel_Save<0 || securityLevel_Save>2)
                                            {
                                                cout << "Invalid Input" << endl;
                                                cin.clear();
                                                cin.ignore(INT_MAX, '\n');
                                            }

                                            cout << "user clearance 0,1,2 :";
                                            cout << "Enter user clearance  :";
                                            cin >> securityLevel_Save;
                                        }while(!cin || securityLevel_Save<0 || securityLevel_Save>2);

                                        cout << "\nFile successfully saved." << endl;

                                        ofstream saveFile;
                                        saveFile.open("Files.Store", ios::app);

                                        saveFile << fileName_Save << ":" << securityLevel_Save << endl;

                                        saveFile.close();
                                    }
                                }
                                else
                                    cout << "The file does not exists." << endl;
                            }

                            break;
                        }
                        case '6':
                        {
                            cout << "Do you want to shut down the file system" << endl;
                            char valid_ExitSystem;

                            do
                            {
                                cout << "Yes or No  :";
                                cin >> exitSystem;
                                valid_ExitSystem = toupper(exitSystem);

                                if(valid_ExitSystem!='Y' && valid_ExitSystem!='N')
                                {
                                   cout << "Invalid Input" << endl;
                                }
                            }while(valid_ExitSystem!='Y' && valid_ExitSystem!='N');

                            if(toupper(exitSystem)=='N')

                           cout<<endl;

                            else if(toupper(exitSystem)=='Y')
                            {

                           cout<<endl;

                                ifstream open_file_List;

                                open_file_List.open("Files.Store");
                                string readStuff;

                                if(user_clearance_valid==0 || user_clearance_valid==1)
                                {

                                    while(getline(open_file_List,readStuff))
                                    {
                                        if((int)readStuff.back()-48==0 || (int)readStuff.back()-48==1)
                                            cout << readStuff.substr(0,readStuff.length()-2) << endl;
                                    }
                                }
                                else
                                {
                                    while(getline(open_file_List,readStuff))
                                    {
                                        cout << readStuff.substr(0,readStuff.length()-2) << endl;
                                    }
                                }
                                open_file_List.close();
                            }

                           cout<<endl;

                            out_file_Save.close();

                            cin.clear();
                            cin.ignore(INT_MAX, '\n');

                            break;
                        }
                    }
                }while(toupper(exitSystem)!='Y');
            }
        }
    }while(menu!=3);
}

else
    {
        cout << "Invalid command" << endl;

        goto tops;
    }

    cout<<endl;
    cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    cout <<"Thank you for using the system";
    cout <<endl;



}
