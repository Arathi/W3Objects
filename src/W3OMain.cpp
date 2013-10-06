#include <iostream>
#include <fstream>

#include "SylkRecord.h"
#include "SylkFile.h"
#include "ProfileNode.h"
#include "ProfileParam.h"

using namespace std;

//#define SYLKRECORD_UNIT
//#define SYLKFILE_UNIT
//#define IDCONVERT_UNIT
#define PROFILE_NODE_UNIT
#define PROFILE_UNIT

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
#ifdef PROFILE_NODE_UNIT
    ProfileNode node;
    //ProfileParam param;
    //param.parse("Art=ReplaceableTextures\\CommandButtons\\BTNReplenishManaOn.blp");
    //param.parse("Buttonpos=0,2");
    //cout<<param.to_string()<<endl;
    node.set_object_id("Ucrl");
    node.add_param("Art=ReplaceableTextures\\CommandButtons\\BTNHeroCryptLord.blp");
    node.add_param("Buttonpos=0,1");
    node.add_param("RequiresCount=3");
    node.add_param("Requires=");
    node.add_param("Requires1=unp1");
    node.add_param("Requires2=unp2");
    node.add_param("Specialart=Objects\\Spawnmodels\\Undead\\UndeadLargeDeathExplode\\UndeadLargeDeathExplode.mdl");
    node.add_param("Attachmentanimprops=medium");
    node.add_param("ScoreScreenIcon=UI\\Glues\\ScoreScreen\\scorescreen-hero-cryptlord.blp");
    cout<<node.to_string()<<endl;
#endif // PROFILE_NODE_UNIT
    return 0;
}

