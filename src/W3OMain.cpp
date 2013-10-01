#include <iostream>
#include <fstream>

#include "SylkRecord.h"

using namespace std;

#define SYLKRECORD_UNIT

int main()
{
#ifdef SYLKFILE_UNIT
    SylkFile slk("D:\\TestDir\\mpq\\Units\\AbilityData.slk");
#endif
#ifdef SYLKRECORD_UNIT
    SylkRecord record;
    record.parser("C;X1;Y13;K\"wild\"");
    cout<<"Type="<<record.get_type()<<endl;
    cout<<"X="<<record.get_x()<<endl;
    cout<<"Y="<<record.get_y()<<endl;
    cout<<"Value="<<record.get_value()<<endl;
#endif
    return 0;
}

