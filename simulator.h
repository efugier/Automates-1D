#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <string>
#include "automate.h"

#include "etat.h"

class Simulator
{
private:
  const Automate &automate;
  Etat **etats = nullptr;
  const Etat *start = nullptr;
  unsigned int max_nb_etats;
  unsigned int rank = 0;
  void build(unsigned int iEtat);

public:
  Simulator(const Automate &automate, unsigned int buffer = 2);
  Simulator(const Automate &automate, const Etat &start, unsigned int buffer = 2);
  ~Simulator();
  void reset();
  void next();
  void run(unsigned int nb_steps);
  const Etat &last() const;
};

#endif // SIMULATOR_H