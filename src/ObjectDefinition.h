#ifndef OBJECTDEFINITION_H
#define OBJECTDEFINITION_H


class ObjectDefinition
{
public:
    ObjectDefinition();
    virtual ~ObjectDefinition();
protected:
private:
    int _original_id;
    int _new_id;

    string _original_id_str;
    string _new_id_str;

    int _modification_amount;
    vector<Modification> _modifications;
};

#endif // OBJECTDEFINITION_H
