#include <ostream>
#include "etat.h"

Etat::Etat(unsigned int dim) : dimension(dim)
{
    if (dim == 0)
    {
        values = nullptr;
    }
    else
    {
        values = new bool[dim];
        for (unsigned int i = 0; i < dim; i++)
        {
            values[i] = false;
        }
    }
}

Etat::~Etat()
{
    if (values)
    {
        delete[] values;
    }
}

Etat::Etat(const Etat &other) : dimension(other.dimension)
{
    if (dimension == 0)
    {
        values = nullptr;
    }
    else
    {
        values = new bool[dimension];
        for (unsigned int i = 0; i < dimension; i++)
        {
            values[i] = other.values[i];
        }
    }
}

Etat &Etat::operator=(const Etat &other)
{
    dimension = other.dimension;
    if (dimension == 0)
    {
        values = nullptr;
    }
    else
    {
        if (values)
        {
            delete[] values;
        }
        values = new bool[dimension];
        for (unsigned int i = 0; i < dimension; i++)
        {
            values[i] = other.values[i];
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Etat &etat)
{
    for (unsigned int i = 0; i < etat.getDimension(); i++)
    {
        stream << (etat.getCellule(i) ? "X" : " ");
    }
    return stream;
}