#include <MailSender.hpp>

MailSender::MailSender(){}

MailSender::~MailSender(){}

bool MailSender::send(string sender, string subject, string bodyMail, string recipient) 
{
    cout << " Sending email....." << endl;
    cout << "   Email Sender: " << sender << endl;
    cout << "   Email Recipient: " << recipient << endl;
    cout << "   Email Subject: " << subject << endl;
    cout << "   Email Body: " << bodyMail << endl;
    return true;
}
