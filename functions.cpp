#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<ctime>
#include<regex>
#include <conio.h>
#include <iomanip>


#include "md5_header.h"

using namespace std;

bool check_file_exist(string createfile)
{
    ifstream check_for_file;
    check_for_file.open("Files.Store");

    regex givencreatefile(createfile + ":(.*)");
    string file_records;

    while(check_for_file>>file_records)
    {
        if(regex_match(file_records,givencreatefile))
        {
            return true;
        }
    }

    check_for_file.close();

    return false;
}
string getfile_sec_level(string file_name)
{
	ifstream check_for_file;
   	check_for_file.open("Files.Store");

   	regex givenvalue(file_name + ":");
    string file_records;

    while(check_for_file>>file_records)
    {
        if(regex_match(file_records,givenvalue))
        {
            break;
        }
    }
    check_for_file.close();

    return file_records;
}

string get_limit_shadow(string const& get_string, string const limit)
{

    return get_string.substr(get_string.find(limit) + limit.size());
}

void get_userid(int user_clearance,int &user_id)
{
	ifstream check_for_file;

    string get_vdata;
        string get_latest_data;

    regex givenvalue("(.*):x:(.*):" + to_string(user_clearance) +"(.*)");

   	check_for_file.open("passwd.txt");

    while(check_for_file>>get_vdata)
    {
        if(regex_match(get_vdata,givenvalue))
        {
            get_latest_data=get_vdata;
        }
    }

    get_latest_data = get_limit_shadow(get_latest_data,":");
    get_latest_data = get_limit_shadow(get_latest_data,":");

    int get_value;

    get_value= get_latest_data.length();

    char get_latest_data_array[get_value + 1];
    strcpy(get_latest_data_array, get_latest_data.c_str());
    strtok(get_latest_data_array,":");

    user_id=atoi(get_latest_data_array);

    check_for_file.close();
}


string get_limit_passwd(string const& get_string, string const limit)
{
    return get_string.substr(get_string.find(limit) + limit.size());
}

void get_salt(string username,string hash_passwd,int &user_clearance_valid)
{
	ifstream check_for_file;
    string get_vdata;


    regex givenvalue(username+":"+hash_passwd+":(.*)");

   	check_for_file.open("shadow.txt");
    while(check_for_file>>get_vdata)
    {
        if(regex_match(get_vdata,givenvalue))
        {
            break;
        }
    }

    user_clearance_valid=stoi(get_limit_shadow(get_vdata,username+":"+hash_passwd+":"));

    check_for_file.close();
}



bool passwd_match(string username,string hash_passwd)
{
	ifstream check_for_file;
    string get_vdata;

    regex givenvalue(username+":"+hash_passwd+":(.*)");

   	check_for_file.open("shadow.txt");
    while(check_for_file>>get_vdata)
    {
        if(regex_match(get_vdata,givenvalue))
        {
            check_for_file.close();
            return true;
        }
    }

    check_for_file.close();

    return false;
}
string get_limit_salt(string const& get_string, string const limit)
{

    return get_string.substr(get_string.find(limit) + limit.size());
}

void get_salts(string username,string &saltvalue)
{
	ifstream check_for_file;
    string get_username;

    regex username_match(username+":(.*)");

   	check_for_file.open("salt.txt");
    while(check_for_file>>get_username)
    {
        if(regex_match(get_username,username_match))
        {
            break;
        }
    }

    saltvalue=get_limit_salt(get_username,":");

    check_for_file.close();
}


bool account_validation(string username)
{
	ifstream check_for_file;
    string get_username;
    int valid(0);

    regex username_match(username+":(.*)");

   	check_for_file.open("salt.txt");
    while(check_for_file>>get_username)
    {
        if(regex_match(get_username,username_match))
        {
            valid++;
            break;
        }
    }
    check_for_file.close();

   	check_for_file.open("passwd.txt");
    while(check_for_file>>get_username)
    {
        if(regex_match(get_username,username_match))
        {
            valid++;
            break;
        }
    }
    check_for_file.close();

    if(valid ==2)
    {
        return true;
    }

    return false;
}

char generate_value (const char char_a[], int char_a_length)
{
    return char_a[rand() % char_a_length];
}

bool check_file(string filename)
{
    ifstream check_for_file;

    check_for_file.open("./Filesystem/" + filename);
    if(check_for_file)
    {
        check_for_file.close();
        return true;
    }

    return false;
}

bool check_username(string username)
{
	ifstream check_for_file;
    string get_username;

    regex username_match(username+":(.*)");

   	check_for_file.open("salt.txt");
    while(check_for_file>>get_username)
    {
        if(regex_match(get_username,username_match))
        {
            check_for_file.close();
            return true;
        }
    }
    check_for_file.close();

    return false;
}
