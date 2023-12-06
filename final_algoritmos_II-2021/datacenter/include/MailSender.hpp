#ifndef MAILSENDER_H
#define MAILSENDER_H

#include <iostream>
#include <string>
using namespace std; 

class MailSender
{
    public:
        MailSender();
        ~MailSender();
        bool send(string sender, string subject, string bodyMail, string recipient = "support@datacenter.com");
};

#endif