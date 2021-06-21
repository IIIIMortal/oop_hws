
#ifndef _fs_
#define _fs_

#include "RCobject.h"
#include <cstring>

class forString: public RCobject
{
public:
    forString(const char * s)
    {
        if(s)
        {
            int len = strlen(s) + 1;
            data = new char[len];
            strcpy(data,s);
        }
        else{
            data = new char[1];
            *data = '\0';
        }
    }
    ~forString()
    {
        delete[] data;
    }
    forString(const forString& sr)
    {
        int len = sr.length();
        data = new char[len+1];
        strcpy(data,sr.data);
    }
    int length() const{
        return strlen(data);
    }
    int equal(const forString& a) const{
        return (strcmp(data,a.data) == 0);
    }
    char* raw() const
    {
        return this->data;
    }
private:
    char* data;
    void operator=(const forString& sp) { }
};

#endif