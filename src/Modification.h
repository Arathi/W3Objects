#ifndef MODIFICATION_H
#define MODIFICATION_H


class Modification
{
public:
    Modification();
    virtual ~Modification();
protected:
private:
    int _id;
    string _id_str;

    int _type;
    int _level;
    int _data_ptr;
    Value _value;
    int _end;
};

#endif // MODIFICATION_H
