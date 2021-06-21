

#ifndef _rco_
#define _rco_

#include<assert.h>
class RCobject
{
private:
    int count;
public:
    RCobject():count(0){ };
    virtual ~RCobject(){ assert(count == 0);}
    RCobject(const RCobject&):count(0){ }
    void incr(){count++;}
    void decr()
    {
        count--;
        if(count == 0){
            delete this;
        }
    }
    int showCount(){ return count; }
};

#endif