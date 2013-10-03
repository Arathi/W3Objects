#include "ProfileNode.h"

ProfileNode::ProfileNode()
{
    //ctor
}

ProfileNode::~ProfileNode()
{
    //dtor
}

vector<string> ProfileNode::split_value(string value_line)
{
    vector<string> values;
    int i, startAt=0, endAt, quoteStartAt, line_length=value_line.length();
    for (i=0; i<line_length; i++)
    {

    }
}

void ProfileNode::addParam(string key, string value)
{
    int index=_param_index_map[key];
    if (index==0)
    {
        //插入新的值
        _values.push_back(value);
        index = _values.size() - 1;
    }
    else
    {
        _values[index]=value;
    }
}
