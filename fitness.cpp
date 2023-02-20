#include "clases.hpp"

Fitness::Fitness() {}
Fitness::~Fitness()
{}

TravelerFitness::~TravelerFitness()
{
    delete matrix_;
}

TravelerFitness::TravelerFitness(DistanceMatrix *m) : Fitness(), matrix_(m) {}

double TravelerFitness::CalcFitness(std::vector<Gen *> *v)
{ 
    if (v == NULL)
    {
        return 0;
    }
    double distance = 0;
    for (size_t i = 0; i < v->size(); i++)
    {
        if (i == (v->size() - 1))
        {
            distance += (matrix_->GetDistanceMatrix())[v->at(i)->GetId()][v->at(0)->GetId()];
        }
        else
        {
            distance += (matrix_->GetDistanceMatrix())[v->at(i)->GetId()][v->at(i + 1)->GetId()];
        }
    }

    return distance;
}
