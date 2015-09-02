#include "parse.h"

Parse::Parse()
{
    std::vector<QString> vRule;
    vRule.push_back("E");
    vRule.push_back("E+T");
    vRule.push_back("T");

    vProduction.push_back(vRule);
    vRule.clear();

    vRule.push_back("T");
    vRule.push_back("T*F");
    vRule.push_back("F");

    vProduction.push_back(vRule);
    vRule.clear();

    vRule.push_back("F");
    vRule.push_back("(E)");
    vRule.push_back("id");

    vProduction.push_back(vRule);
    vRule.clear();

    vStack.push_back("$");
    vOutput.push_back("Stack\tAction");

}
void Parse::check(std::vector<QString> inputString)
{
    bool flag=false;

//    vOutput.push_back(QString::number(inputString.size()));

    for(std::vector<QString>::size_type i=0; i< inputString.size(); ++i)
    {
        for(std::vector<QString>::size_type j=1; j<vProduction[0].size(); ++j)
        {
            if(inputString[i].compare(vProduction[0][j])==0)
            {
                vStack.pop_back();
                vStack.push_back(vProduction[0][0]);
                vOutput.push_back(inputString[i]+"\t"+"Reduce By"+vProduction[0][0]+"->"+vProduction[0][j]);
//                continue;
                flag=true;
                break;

            }
        }


        for(std::vector<QString>::size_type j=1; flag==false&&j<vProduction[1].size(); ++j)
        {
            if(inputString[i].compare(vProduction[1][j])==0)
            {
                vStack.pop_back();
                vStack.push_back(vProduction[1][0]);
                vOutput.push_back(inputString[i]+"\t"+"Reduce By"+vProduction[1][0]+"->"+vProduction[1][j]);
//                continue;
                flag=true;
                break;

            }
        }

        for(std::vector<QString>::size_type j=1; flag==false&&j<vProduction[2].size(); ++j)
        {
            if(inputString[i].compare(vProduction[2][j])==0)
            {
                if(vStack.empty()==false)
                {
                    vStack.pop_back();
                }
                vStack.push_back(vProduction[2][0]);
                vOutput.push_back(inputString[i]+"\t"+"Reduce By"+vProduction[2][0]+"->"+vProduction[2][j]);
//                continue;
                flag=true;
                break;

            }
        }

        if(flag==false)
        {
        vStack.push_back(inputString[i]);
        vOutput.push_back(inputString[i]+"\t"+"Shift");
        }
        flag=false;

//        vOutput.push_back(QString::number(vProduction.size()));
    }
}

std::vector<QString> Parse::getOutput(){
    return vOutput;
}
