#include "simulator.h"

Simulator::Simulator(const Automate &automate, unsigned int buffer) : automate(automate), max_nb_etats(buffer)
{
    etats = new Etat *[max_nb_etats];
    for (unsigned int i = 0; i < max_nb_etats; i++)
        etats[i] = NULL;
    reset();
}

Simulator::Simulator(const Automate &automate, const Etat &dep, unsigned int buffer) : automate(automate), max_nb_etats(buffer), start(&dep)
{
    etats = new Etat *[max_nb_etats];
    for (unsigned int i = 0; i < max_nb_etats; i++)
        etats[i] = NULL;
    etats[0] = new Etat(dep);
    reset();
}

void Simulator::build(unsigned int iEtat)
{
    if (iEtat >= max_nb_etats)
        throw AutomateException("Erreur taille");
    if (etats[iEtat] == NULL)
        etats[iEtat] = new Etat();
}

void Simulator::reset()
{
    if (start == NULL)
        throw AutomateException("Etat start non défini");
    build(0);
    *etats[0] = *start;
    rank = 0;
}

void Simulator::run(unsigned int nb_steps)
{
    for (unsigned int i = 0; i < nb_steps; i++)
        next();
}

void Simulator::next()
{
    if (start == NULL)
        throw AutomateException("Etat start non defini");
    rank++;

    build(rank % max_nb_etats);
    automate.applyTransition(
        *etats[(rank - 1) % max_nb_etats],
        *etats[(rank) % max_nb_etats]);
}

const Etat &Simulator::last() const
{
    return *etats[rank % max_nb_etats];
}

Simulator::~Simulator()
{
    for (unsigned int i = 0; i < max_nb_etats; i++)
    {
        if (etats[i] != NULL)
            delete etats[i];
    }
    delete[] etats;
}
