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

using namespace std;

int main()
{
 ///Generate salt
    static const char salt_v[] = "1234567890";
    int saltPool_Length=sizeof(salt_v)-1;
    string randomSalt,combinedValue;

    ///Generate captcha
    static const char captchaPool[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int captchaPool_Length=sizeof(captchaPool)-1;
    string randomCaptcha;

    ///Variables
    char password_Array, rePassword_Array;
    string username,password,re_Password;
    regex passwordPolicy("^(?=.*[0-9])(?=.*[a-zA-Z])(?=.*[!@#$%^&*])[0-9a-zA-Z!@#$%^&*]{8,16}");
    int user_clearance_regis(0),user_clearance_auth(0);
    string user_captcha;
    bool proceedLoggingIn(false);
}
