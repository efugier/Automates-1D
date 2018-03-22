#ifndef ETAT_H
#define ETAT_H

#include <ostream>

class Etat
{
private:
  unsigned int dimension;
  bool *values; // std::verctor aurait été bien plus simple à gérer !

public:
  Etat(unsigned int dim = 0);
  ~Etat();
  Etat(const Etat &other);

  Etat &operator=(const Etat &other);

  inline void setCellule(unsigned int i, bool val) { values[i] = val; }
  inline unsigned int getDimension() const { return dimension; }
  inline bool getCellule(unsigned int i) const { return values[i]; }
};

std::ostream &operator<<(std::ostream &stream, const Etat &etat);

#endif // ETAT_H