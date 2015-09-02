#ifndef PARSE_H
#define PARSE_H
#include<vector>
//#include<string>
#include<QString>
class Parse
{

std::vector< std::vector<QString> > vProduction;
std::vector<QString> vStack;
std::vector<QString> vOutput;

public:
    Parse();

    void check(std::vector<QString>);
    std::vector<QString> getOutput();

};

#endif // PARSE_Hd
