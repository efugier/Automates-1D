#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "etat.h"
#include <ostream>

class AutomateException
{
public:
  AutomateException(const std::string &message) : info(message) {}
  std::string getInfo() const { return info; }

private:
  std::string info;
};

class Automate
{
private:
  unsigned short int nb;
  std::string bit_nb;

public:
  Automate(unsigned short int num);
  Automate(const std::string &);

  void applyTransition(const Etat &from, Etat &to) const;
  inline unsigned short int getNb() const { return nb; }
  inline std::string getBitNb() const { return bit_nb; }
};

short unsigned int BitNumToNum(const std::string &str);
std::string NumToNumBit(short unsigned int num);

std::ostream &operator<<(std::ostream &stream, const Automate &automate);

#endif // AUTOMATE_H