#include "clases.hpp"

Individual::Individual(double fit, std::vector<Gen *> *g) : fitness_(fit), genoma_(g), gen_quant_(g->size()) {}

Individual::~Individual()
{
    delete genoma_;
    genoma_ = NULL;
}
Individual::Individual() : gen_quant_(0), genoma_(NULL), fitness_(0) {}
double Individual::GetFitness() const
{
    return fitness_;
}
double Individual::GetFitnessPerc() const
{
    return fitness_perc_;
}

Path::Path(std::vector<Gen *> *pg, Fitness *f_)
{
    try
    {
        std::vector<Gen *> copypg = *pg;
        std::vector<Gen *> *v = new std::vector<Gen *>;
        size_t size = pg->size();
        for (size_t i = 0; i < pg->size(); i++)
        {
            int rand_aux = rand() % (copypg.size());
            v->emplace_back(copypg.at(rand_aux));
            copypg.erase(copypg.begin() + rand_aux);
        }
        fitness_perc_ = 0;
        fitness_ = f_->CalcFitness(v);
        genoma_ = v;
        gen_quant_ = v->size();
    }
    catch (std::bad_alloc &b)
    {
        std::cerr << "not enough memo\n";
    }
}

Path::~Path(){}

void Individual::SetFitPerc(double totfit)
{
    fitness_perc_ = fitness_ / totfit;
}

size_t Individual::GetSize() const
{
    return gen_quant_;
}
std::vector<Gen *> *Individual::GetGenoma() const
{
    return genoma_;
}
void Individual::SetSize(size_t s)
{
    gen_quant_ = s;
}
void Individual::SetFitness(double f)
{
    fitness_ = f;
}
void Individual::SetGenoma(std::vector<Gen *> *g)
{
    genoma_ = g;
}

void Path::Mutation()
{
    int a = rand() % (genoma_->size()), b = rand() % (genoma_->size());
    while (genoma_->at(a) == genoma_->at(b))
    {
        b = rand() % (genoma_->size());
    }
    std::swap(genoma_->at(a), genoma_->at(b));
}