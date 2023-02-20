#include "clases.hpp"


DataGuardian::DataGuardian()
{
    std::vector<double> *v = new std::vector<double>;
    if (v == NULL)
    {
        delete v;
        v = NULL;
    }
    overall_gen_fitness_ = v;
    
}
DataGuardian::~DataGuardian()
{
    delete overall_gen_fitness_;
    std::cout << "Destructor de DataGuardian\n";
}
void DataGuardian::AddOverallGenFitness(double f)
{
    overall_gen_fitness_->emplace_back(f);
}

std::vector<double>* DataGuardian::GetOverallGenFitness(){
    return overall_gen_fitness_;
}