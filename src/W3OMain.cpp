#include "W3OUnits.h"
#include <unistd.h>
#include "Config.h"
#include "Ability.h"

const string kVersion = "0.1.1";

void usage()
{

}

/**
 * 合并Units目录下的所有profile
 */
void MergeProfiles(const char *filePath)
{
    ifstream ifs(filePath);
    TextFile profiles;
    string pathBase="D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\", fileName;
    while (ifs>>fileName)
    {
        profiles.load(pathBase+fileName);
    }
    profiles.save("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapTools\\output\\FuncAndStrings.txt");
}

/**
 * 从总Profile中读取每个小酒店的名称和英雄列表
 */
void GetHeroList(const char *profilePath)
{
    TextFile profile;
    string trvernList[] = {"n01B","n01P","n0GK","n0LJ","n01N","n007","n005","n0LI","n008","n0GJ","n01D","n0LH"};
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapTools\\conf\\FuncAndStrings.txt");
    for (int i=0; i<sizeof(trvernList); i++)
    {
        ObjectIdentity trvern_id;
        trvern_id.set_id(trvernList[i].c_str());
    }
}

void GetHeroAbilitys()
{
    //载入英雄编号与单位ID
    //vector<string> K34(111);
    //vector<string> heroNames(111);
    string K34[111];
    string heroNames[111];
    int abilityIdList[111][5];
    string abilityNameList[111][5];

    K34[1]="Hvwd";
    K34[2]="Hmbr";
    K34[3]="Emoo";
    K34[4]="O00P";
    K34[5]="Hjai";
    K34[6]="H001";
    K34[7]="HC49";
    K34[8]="Otch";
    K34[9]="HC92";
    K34[10]="N01O";
    K34[11]="H004";
    K34[12]="Nbbc";
    K34[13]="N01A";
    K34[14]="Hamg";
    K34[15]="O015";
    K34[16]="Hblm";
    K34[17]="Huth";
    K34[18]="Hmkg";
    K34[19]="Ntin";
    K34[20]="Emns";
    K34[21]="Ogrh";
    K34[22]="Ucrl";
    K34[23]="H00K";
    K34[24]="H00A";
    K34[25]="E005";
    K34[26]="Usyl";
    K34[27]="N016";
    K34[28]="Orkn";
    K34[29]="O01F";
    K34[30]="Npbm";
    K34[31]="H000";
    K34[32]="Naka";
    K34[33]="Hlgr";
    K34[34]="Edem";
    K34[35]="Nbrn";
    K34[36]="Harf";
    K34[37]="H00D";
    K34[38]="E00P";
    K34[39]="N01I";
    K34[40]="N01V";
    K34[41]="H00S";
    K34[42]="H00Q";
    K34[43]="E01Y";
    K34[44]="N00B";
    K34[45]="H00T";
    K34[46]="H06S";
    K34[47]="N0EG";
    K34[48]="E02N";
    K34[49]="E02J";
    K34[50]="E02I";
    K34[51]="E02F";
    K34[52]="H008";
    K34[53]="E02X";
    K34[54]="N0M0";
    K34[55]="E02K";
    K34[56]="H0DO";
    K34[57]="E032";
    K34[58]="U008";
    K34[59]="U006";
    K34[60]="Ewar";
    K34[61]="H00V";
    K34[62]="Udre";
    K34[63]="NC00";
    K34[64]="UC42";
    K34[65]="U000";
    K34[66]="UC91";
    K34[67]="UC01";
    K34[68]="E004";
    K34[69]="EC45";
    K34[70]="EC77";
    K34[71]="E002";
    K34[72]="U00C";
    K34[73]="H00H";
    K34[74]="Ofar";
    K34[75]="Oshd";
    K34[76]="U00E";
    K34[77]="U00F";
    K34[78]="O00J";
    K34[79]="Ubal";
    K34[80]="Nfir";
    K34[81]="U00K";
    K34[82]="Opgh";
    K34[83]="Hvsh";
    K34[84]="Udea";
    K34[85]="E01B";
    K34[86]="E01A";
    K34[87]="U00P";
    K34[88]="E01C";
    K34[89]="H00I";
    K34[90]="N01W";
    K34[91]="N00R";
    K34[92]="H00R";
    K34[93]="H00N";
    K34[94]="H00U";
    K34[95]="Uktl";
    K34[96]="O016";
    K34[97]="N0HP";
    K34[98]="H071";
    K34[99]="Eevi";
    K34[100]="Ekee";
    K34[101]="E02H";
    K34[102]="Ulic";
    K34[103]="UC76";
    K34[104]="UC18";
    K34[105]="EC57";
    K34[106]="UC11";
    K34[107]="UC60";
    K34[108]="U00A";
    K34[109]="N0M7";
    K34[110]="N0MK";

    //载入单位名称的Profile文件（所有*UnitStrings.txt，共6个）
    TextFile profile;
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\CampaignUnitStrings.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\HumanUnitStrings.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\NeutralUnitStrings.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\OrcUnitStrings.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\UndeadUnitStrings.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\nightelfunitstrings.txt");

    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\CampaignAbilityStrings.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\HumanAbilityStrings.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\ItemAbilityStrings.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\NeutralAbilityStrings.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\NightElfAbilityStrings.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\OrcAbilityStrings.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\UndeadAbilityStrings.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\commonabilitystrings.txt");

    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\CampaignAbilityFunc.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\CommonAbilityFunc.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\HumanAbilityFunc.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\ItemAbilityFunc.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\NeutralAbilityFunc.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\NightElfAbilityFunc.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\OrcAbilityFunc.txt");
    profile.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\UndeadAbilityFunc.txt");

    //载入单位技能对应slk文件(UnitAbilities.slk)
    SylkFile slk;
    slk.load("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapFiles\\Units\\UnitAbilities.slk");

    //载入单位技能
    int heroId = 0;
    int heroAbilListID = slk.get_field_order("heroAbilList");
    for (heroId = 1; heroId <= 110; heroId++ )
    {
        //获取单位名称
        heroNames[heroId] = profile.get_profile(K34[heroId], "Name");
        string heroIdNo="";
        if (heroId<100) heroIdNo+="0";
        if (heroId<10) heroIdNo+="0";
        heroIdNo+=int2str(heroId);
        int unitAbilID = slk.get_id_order( K34[heroId] );

        cout<<"No."<<heroIdNo<<" \'"<<K34[heroId]<<"\': "<<"<b>"<<heroNames[heroId]<<"</b>"<<endl;
        cout<<"<pre>"<<endl;

        //读取"heroAbilList"一项
        string heroAbilList = slk.getTableData(heroAbilListID, unitAbilID);
        vector<string> splited = split( heroAbilList,"," );
        multimap<int, string> skills;

        for (int i = 0; i<splited.size(); i++ )
        {
            if (splited[i]=="A0NR" || splited[i]=="Aamk") continue;
            string abilityName = profile.get_profile(splited[i], "Name");
            string tip = profile.get_profile(splited[i], "Tip");
            string::size_type endIndex = tip.find_first_of(" [|");
            tip = tip.substr(0, endIndex);
            if (tip=="")
            {
                tip = abilityName;
            }
            string hotkey = profile.get_profile(splited[i], "Researchhotkey");

            string abiName = "" + tip + "" + "[" + hotkey + "]";

            int btn_x, btn_y;
            string btn_xs, btn_ys;
            btn_xs = profile.get_profile(splited[i], "Buttonpos", 0);
            btn_ys = profile.get_profile(splited[i], "Buttonpos", 1);
            btn_x = str2int(btn_xs);
            btn_y = str2int(btn_ys);

            clog<<btn_xs<<","<<btn_ys<<endl;

            if (btn_xs!="" && btn_ys!="")
            {
                abiName += " ("+btn_xs+","+btn_ys+")";
            }

            //cout<<"\'"<<splited[i]<<"\': "<<abiName<<endl;
            string skill_desc = "\'" + splited[i] + "\': " + abiName;
            skills.insert( make_pair( btn_x+btn_y*4, skill_desc ) );
        }
        //输出重排序后的

        multimap<int, string>::iterator mmiter;
        for (mmiter=skills.begin(); mmiter!=skills.end(); mmiter++)
        {
            cout<<mmiter->second<<endl;
        }

        cout<<"</pre>"<<endl;

        //cout<<heroAbilList<<endl;
        //分割值
        //abilityIdList[heroId][]
    }
}

int main(int argc, char **argv)
{
    cout<<"W3Objects v"<<kVersion<<endl;
    string configPath="";
    if (argc==1)
    {
        char pwd[256];
        getcwd(pwd, sizeof(pwd));
        configPath = pwd;
        configPath += "/default.ini";
    }
    else if (argc==2)
    {
        configPath = argv[1];
    }
    else
    {
        usage();
        return 1;
    }
    Config config=Config::getConfig(configPath);
    string basePath = config.get_base_path();
    clog<<"配置目录："<<basePath<<endl;

    GetHeroAbilitys();

    //UnitMain();
    //--------------以下是Ability读取的逻辑--------------
    /*
    CampaignAbilityFunc.txt
    campaignabilitystrings.txt
    CommonAbilityFunc.txt
    CommonAbilityStrings.txt
    HumanAbilityFunc.txt
    HumanAbilityStrings.txt
    ItemAbilityFunc.txt
    ItemAbilityStrings.txt
    NeutralAbilityFunc.txt
    NeutralAbilityStrings.txt
    NightElfAbilityFunc.txt
    NightElfAbilityStrings.txt
    OrcAbilityFunc.txt
    OrcAbilityStrings.txt
    UndeadAbilityFunc.txt
    UndeadAbilityStrings.txt
    */

    /*
    Ability ability;
    SylkFile slk;
    TextFile txt;
    slk.load(basePath+"AbilityData.slk");

    txt.load(basePath+"\\Units_126\\"+"ItemAbilityFunc.txt");
    txt.load(basePath+"\\Units_126\\"+"ItemAbilityStrings.txt");
    txt.save("D:\\TestDir\\mpq\\UnitsCopy\\ItemAbility.txt");

    ability.loadSylk(slk);
    */
    //MergeProfiles("D:\\Games\\Warcraft III\\Maps\\MapHack\\DotAHackS7\\MapTools\\conf\\profilelist.txt");
    //UnitMain();
    return 0;
}
