#include <iostream>

using namespace std;


    static const char salt_s[] = "0123456789";
    int salt_s_lgt=sizeof(salt_s)-1;
    string rand_gen_salt,val_combine;
    char passwd_index, repasswd_index;
    string username,password,re_Password;
    regex passwd_pol("^(?=.*[0-9])(?=.*[a-zA-Z])(?=.*[!@#$%^&*])[0-9a-zA-Z!@#$%^&*]{8,16}");
    int user_clearance_reg(0),user_clearance_valid(0);
    string user_capthca;
    bool loging_process(false);
    static const char captcha_s[] ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int captcha_s_lgt=sizeof(captcha_s)-1;
    string rand_gen_captcha;

