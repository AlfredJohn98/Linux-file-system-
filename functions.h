#include <iostream>

using namespace std;

bool check_username(string username);
bool check_file(string filename);
char generate_value (const char char_a[], int char_a_length);
bool account_validation(string username);
void get_salts(string username,string &saltvalue);
string get_limit_salt(string const& get_string, string const limit);
bool passwd_match(string username,string hash_passwd);
void get_salt(string username,string hash_passwd,int &user_clearance_validation);
string get_limit_passwd(string const& get_string, string const limit);
void get_userid(int user_clearance,int &user_id);
string get_limit_shadow(string const& get_string, string const limit);
string getfile_sec_level(string file_name);
bool check_file_exist(string createfile);
