#include <ostream>
#include "automate.h"

Automate::Automate(unsigned short int num) : nb(num), bit_nb(NumToNumBit(num)) {}

Automate::Automate(const std::string &str) : nb(BitNumToNum(str)), bit_nb(str) {}

void Automate::applyTransition(const Etat &from, Etat &to) const
{
    to = from;
    for (unsigned int i = 0; i < from.getDimension(); i++)
    {
        unsigned short int conf = 0;
        if (i > 0)
            conf += (from.getCellule(i - 1) ? 1 : 0) * 4;
        conf += (from.getCellule(i) ? 1 : 0) * 2;
        if (i < from.getDimension() - 1)
            conf += (from.getCellule(i + 1) ? 1 : 0);
        to.setCellule(i, bit_nb[7 - conf] - '0');
    }
}

std::ostream &operator<<(std::ostream &stream, const Automate &automate)
{
    stream << automate.getNb();
    stream << " : " << automate.getBitNb();
    return stream;
}

short unsigned int BitNumToNum(const std::string &bit_num)
{
    if (bit_num.size() != 8)
        throw AutomateException("Numero d’automate indefini");
    int power = 1;
    short unsigned int num = 0;
    for (int i = 7; i >= 0; i--)
    {
        if (bit_num[i] == '1')
        {
            num += power;
        }
        else if (bit_num[i] != '0')
        {
            throw AutomateException("Numero d’automate indefini");
        }
        power *= 2;
    }
    return num;
}

std::string NumToNumBit(short unsigned int num)
{
    std::string bit_num;
    if (num > 256)
    {
        throw AutomateException("Numero d’automate indefini");
    }
    unsigned short int p = 128;
    int i = 7;
    while (i >= 0)
    {
        if (num >= p)
        {
            bit_num.push_back('1');
            num -= p;
        }
        else
        {
            bit_num.push_back('0');
        }
        i--;
        p /= 2;
    }
    return bit_num;
}