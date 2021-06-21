
#ifndef _RCPointer_
#define _RCPointer_

template<class T>
class RCP
{
private:
    T* obj;
    void increment(){ if(obj) obj->incr();}
    void decrement(){ if(obj) obj->decr();}
public:
    RCP(T* r = 0):obj(r){increment();}
    ~RCP(){decrement();}
    RCP(const RCP<T>& p)
    { 
        obj = p.obj;
        increment();    
    }
    RCP& operator=(const RCP<T>& p)
    {
        if(obj!= p.obj)
        {
            decrement();
            obj = p.obj;
            increment();
        }
        return *this;
    }
    T* operator->() const
    {
        return obj;
    }
    T& operator*() const
    {
        return *obj;
    }
};

#endif