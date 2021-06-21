

#ifndef _s_
#define _s_

#include"RCP.h"
#include"forString.h"


class String
{
public:
    String(const char *s):m_rep(0)
    {
        m_rep = new forString(s);
    }
    ~String(){}
    String(const String &s):m_rep(s.m_rep){}
    String &operator=(const String &s)
    {
        m_rep = s.m_rep;
        return *this;
    }
    int operator==(const String &s) const
    {
        return m_rep->equal(*s.m_rep);
    }
    String operator+(const String &a) const
    {
        int len = this->length()+ a.length()+1;
        char* n = new char[len];
        strcpy(this->getRaw(),n);
        strcat(n,a.getRaw());
        return String(n);
    }
    int length() const
    {
        return m_rep->length();
    }
    const char* getRaw() const
    {
        return m_rep->raw();
    }
    int refCount() const
    {
        return m_rep->showCount();
    }
private:
    RCP<forString> m_rep;

};

#endif