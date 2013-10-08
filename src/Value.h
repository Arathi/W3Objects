#ifndef VALUE_H
#define VALUE_H


class Value
{
public:
    Value();
    virtual ~Value();
protected:
private:
    int _integer;
    float _real;
    string _string;
};

#endif // VALUE_H
