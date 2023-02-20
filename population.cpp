#include "clases.hpp"

#define MUTEPERC 0.5
Population::Population(size_t s, std::vector<Gen *> *pg, Fitness *f, std::vector<Individual *> *p, double tot_f)
{
    pop_quantity_ = s;
    pos_genes_ = pg;
    population_ = p;
    f_ = f;
    total_fitness = tot_f;
}

void Population::ToPerc()
{
    for (size_t i = 0; i < population_->size(); i++)
    {
        population_->at(i)->SetFitPerc(total_fitness);
    }
}

TravelerPopulation::TravelerPopulation(size_t s, std::vector<Gen *> *pg, Fitness *f) : Population(s, pg, f, NULL, 0)
{
    try
    {
        std::vector<Individual *> *v = new std::vector<Individual *>;
        double aux_f = 0;
        for (size_t i = 0; i < pop_quantity_; i++)
        {
            Individual *aux = new Path(pg, f); // pg stands for possible genes
            if (aux == NULL)
            {
                for (size_t j = 0; j < i; j++)
                {
                    delete v->at(i);
                }
                delete v;
                v = NULL;
            }
            else
            {
                v->emplace_back(aux);
                aux_f += aux->GetFitness();
            }
        }

        population_ = v;
        total_fitness = aux_f / v->size();
        ToPerc();
    }
    catch (std::bad_alloc &b)
    {
        std::cerr << "not enough memo\n";
        population_ = NULL;
    }
}

Population::~Population()
{
    for (size_t i = 0; i < pop_quantity_; i++)
    {
        delete population_->at(i);
    }
    delete population_;
    f_ = NULL;
    population_ = NULL;
}
size_t Population::GetPopQuantity() const
{
    return pop_quantity_;
}
std::vector<Individual *> *Population::GetPopulation() const
{
    return population_;
}
std::vector<Gen *> *Population::GetPosGenes() const
{
    return pos_genes_;
}
Fitness *Population::GetFitness() const
{
    return f_;
}
void Population::SetPopQuantity(size_t s)
{
    pop_quantity_ = s;
}
void Population::SetPopulation(std::vector<Individual *> *p)
{
    population_ = p;
}
void Population::SetPosGenes(std::vector<Gen *> *pg)
{
    pos_genes_ = pg;
}

TravelerPopulation::~TravelerPopulation()
{
    delete f_;
}


double Population::GetTotalFitness()
{
    return total_fitness;
}

void Population::UpdateTotalFitness()
{
    double aux = 0;
    for (size_t i = 0; i < pop_quantity_; i++)
    {
        aux += population_->at(i)->GetFitness();
    }
    total_fitness = aux / population_->size();
}

void Population::AddInd(Individual *ind)
{
    population_->emplace_back(ind);
}


void TravelerPopulation::Mutation()
{
    int quant_to_mutate = population_->size() * MUTEPERC;
    for (size_t i = 0; i < quant_to_mutate; i++)
    {
        // agarro un individuo al azar:
        int rand_ind = rand() % population_->size();
        // le cambio los genes al azar:
        population_->at(rand_ind)->Mutation();
    }
}