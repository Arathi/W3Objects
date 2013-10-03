#include <iostream>
#include <fstream>

#include "SylkRecord.h"
#include "SylkFile.h"

using namespace std;

//#define SYLKRECORD_UNIT
//#define SYLKFILE_UNIT
#define IDCONVERT_UNIT

int main()
{
#ifdef SYLKFILE_UNIT
    SylkFile slk("D:\\TestDir\\mpq\\Units\\AbilityData.slk");
    slk.save("D:\\TestDir\\mpq\\UnitsCopy\\AbilityData.slk");
    slk.save("D:\\TestDir\\mpq\\UnitsCopy\\AbilityData.comp.slk", true);
    slk.gen_indexs();
#endif
#ifdef SYLKRECORD_UNIT
    SylkRecord record;
    record.parser("C;X1;Y13;K\"wild\"");
    cout<<"Type="<<record.get_type()<<endl;
    cout<<"X="<<record.get_x()<<endl;
    cout<<"Y="<<record.get_y()<<endl;
    cout<<"Value="<<record.get_value()<<endl;
#endif
#ifdef IDCONVERT_UNIT
    SylkFile slk("D:\\TestDir\\mpq\\Units\\AbilityData.slk");
    int i, line = slk.get_y();
    for (i=2; i<=line; i++)
    {
        string idStr=slk.getTableData(1, i);
        clog << idStr << " => " << id2int(idStr) <<endl;
    }
#endif // IDCONVERT_UNIT
    return 0;
}

