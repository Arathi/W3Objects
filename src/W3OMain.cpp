#include <iostream>
#include <fstream>

#include "SylkRecord.h"
#include "SylkFile.h"
#include "ProfileNode.h"
#include "ProfileParam.h"
#include "TextFile.h"
#include "W3_File.h"

using namespace std;

//#define SYLKRECORD_UNIT
//#define SYLKFILE_UNIT //读写SLK功能
//#define CONVERT_UNIT
//#define PROFILE_PARAM_UNIT
//#define PROFILE_NODE_UNIT
//#define PROFILE_UNIT //读写TXT功能
#define W3OFILE_UNIT //读写W3*功能

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
#ifdef CONVERT_UNIT
    //SylkFile slk("D:\\TestDir\\mpq\\Units\\AbilityData.slk");
    //int i, line = slk.get_y();
    //for (i=2; i<=line; i++)
    //{
    //    string idStr=slk.getTableData(1, i);
    //    clog << idStr << " => " << id2int(idStr) <<endl;
    //}
    char bytes[]={1,0,0,0};
    convertInt(bytes);
#endif // IDCONVERT_UNIT
#ifdef PROFILE_PARAM_UNIT
    ProfileParam param;
    param.parse("Art=ReplaceableTextures\\CommandButtons\\BTNReplenishManaOn.blp");
    param.parse("Buttonpos=0,2");
    cout<<param.to_string()<<endl;
#endif // PROFILE_PARAM_UNIT
#ifdef PROFILE_NODE_UNIT
    ProfileNode node, node2;
    node.init("Ucrl");
    node.add_param("Art=ReplaceableTextures\\CommandButtons\\BTNHeroCryptLord.blp");
    node.add_param("Buttonpos=0,1");
    node.add_param("RequiresCount=3");
    node.add_param("Requires=");

    node2.init("Ucrl");
    node2.add_param("Requires1=unp1");
    node2.add_param("Requires2=unp2");
    node2.add_param("Specialart=Objects\\Spawnmodels\\Undead\\UndeadLargeDeathExplode\\UndeadLargeDeathExplode.mdl");
    node2.add_param("Attachmentanimprops=medium");
    node2.add_param("ScoreScreenIcon=UI\\Glues\\ScoreScreen\\scorescreen-hero-cryptlord.blp");
    //cout<<node.to_string()<<endl;
    //cout<<node2.to_string()<<endl;
    node.merge(node2);
    cout<<node.to_string()<<endl;
#endif // PROFILE_NODE_UNIT
#ifdef PROFILE_UNIT
    TextFile profile;
    profile.load("D:\\TestDir\\mpq\\Units_126\\ItemFunc.txt");
    profile.save("D:\\TestDir\\mpq\\UnitsCopy\\ItemFunc.txt");
#endif // PROFILE_UNIT
#ifdef W3OFILE_UNIT
    W3_File w3a;
    w3a.load("D:\\TestDir\\mpq\\war3map.w3a");
    w3a.save("D:\\TestDir\\mpq\\war3map_copy.w3a");
#endif // W3OFile_UNIT
    return 0;
}
