#ifndef MESSAGER_H
#define MESSAGER_H

#include <string>

using namespace std;

class Messager {
public:
    virtual void sendMesagge(string message, string to, string from) = 0;
    virtual ~Messager() = default;
};

class Facebook : public Messager {
public:
    void sendMesagge(string message, string to, string from) override;
};

class Instagram : public Messager {
public:
    void sendMesagge(string message, string to, string from) override;
};

class Whatsapp : public Messager {
public:
    void sendMesagge(string message, string to, string from) override;
};

#endif // MESSAGER_H
