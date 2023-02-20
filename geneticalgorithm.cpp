#include "clases.hpp"

#define CRAZY_TIME 5
#define SpartanPercentage 0.5

//PONERLO EN EL ALGORITMO
bool checkrep(Gen *n, std::vector<Gen *> *num)
{
    for (int i = 0; i < num->size(); i++)
        if (n == num->at(i))
            return true;
    return false;
}

//lo mismo
bool comp(const Individual *a, const Individual *b)
{
    return a->GetFitness() < b->GetFitness();
}

GeneticAlgorithm::GeneticAlgorithm(Population *p) : population_(p) {}
GeneticAlgorithm::GeneticAlgorithm() : population_(NULL) {}

GeneticAlgorithm::~GeneticAlgorithm()
{
    delete population_;
}

TravelerGeneticAlgorithm::TravelerGeneticAlgorithm(std::vector<City *> *pc, std::vector<Gen *> *pg, size_t individual_quant)
{
    DistanceMatrix *distance_matrix = new DistanceMatrix(pc);
    Fitness *fitness = new TravelerFitness(distance_matrix);
    Population *population = new TravelerPopulation(individual_quant, pg, fitness);
    DataGuardian *dg = new DataGuardian;
    population_ = population;
    g = dg;
}

TravelerGeneticAlgorithm::~TravelerGeneticAlgorithm()
{delete g;}

Population *GeneticAlgorithm::GetPopulation() const
{
    return population_;
}


void TravelerGeneticAlgorithm::ReprSelection(int g)
{
    std::vector<Individual*> hijos;
    int RanNum;

    std::sort(population_->GetPopulation()->begin(), population_->GetPopulation()->end(), &comp);
   
    if (g%CRAZY_TIME==0){
        for(size_t i =0; hijos.size() < (population_->GetPopulation()->size()); i++){
            RanNum = rand() %population_->GetPopulation()->size();
	        hijos.emplace_back(Reproduction(population_->GetPopulation()->at(i), population_->GetPopulation()->at(RanNum)));         
        }
    }
    else{
        for (size_t i =0; hijos.size() < (population_->GetPopulation()->size()); i+=2){
            int a=i, b=i+1;
            a%= population_->GetPopulation()->size();
            b%= population_->GetPopulation()->size();
            hijos.emplace_back(Reproduction(population_->GetPopulation()->at(a), population_->GetPopulation()->at(b)));

        }
    }
	

	   for(size_t i = 0; i < hijos.size(); i++){
			population_->AddInd(hijos.at(i));
		}
         std::sort(population_->GetPopulation()->begin(), population_->GetPopulation()->end(), &comp);

}


Individual *TravelerGeneticAlgorithm::Reproduction(Individual *a, Individual *b)
{
    std::vector<Gen *> *hijo1 = new std::vector<Gen *>;
    int n = rand() % (a->GetGenoma()->size());
    while ((n < (a->GetGenoma()->size()) * 0.2) || n > (a->GetGenoma()->size()) * 0.80)
    {
        n = rand() % (a->GetGenoma()->size());
    }
    for (size_t i = 0; i < n; i++)
    {
        hijo1->emplace_back(a->GetGenoma()->at(i));
    }

    for (size_t i = 0; i < (b->GetGenoma()->size()); i++)
    {
        if (!checkrep(b->GetGenoma()->at(i), hijo1))
        {
            hijo1->emplace_back(b->GetGenoma()->at(i));
        }
    }

    Individual *hijo = new Path(hijo1, population_->GetFitness());
    delete hijo1;
    hijo->SetFitPerc(population_->GetTotalFitness());


    return hijo;
}


void TravelerGeneticAlgorithm::Mutation()
{
    population_->Mutation();
}

void TravelerGeneticAlgorithm::SpartanSelection()
{
    
	for(size_t i = ((population_->GetPopulation()->size())/2); i < (population_->GetPopulation()->size()); i++){
        delete population_->GetPopulation()->at(i);
    }
    (population_->GetPopulation())->erase(population_->GetPopulation()->end() - (population_->GetPopulation()->size() * SpartanPercentage), population_->GetPopulation()->end());
}

void TravelerGeneticAlgorithm::UpdateInfo()
{
    population_->UpdateTotalFitness();
}


std::tuple<std::vector<double>*, std::vector<Gen*>*> TravelerGeneticAlgorithm::Play(int quant_generations, double variation)
{
    int generation = 0;
    double last_total_fitness = 0;
    double current_variation = 0.5;
    while (generation < quant_generations && current_variation>= variation)
    {
        ReprSelection(generation);
        Mutation();
        std::sort(population_->GetPopulation()->begin(), population_->GetPopulation()->end(), &comp);
        SpartanSelection();
        UpdateInfo();

        g->AddOverallGenFitness(population_->GetTotalFitness());
        generation++;

        if(last_total_fitness - population_->GetTotalFitness() >= 0){
            current_variation = last_total_fitness - population_->GetTotalFitness();
        }else{
            current_variation = -1*(last_total_fitness - population_->GetTotalFitness());
        }
        

        last_total_fitness = population_->GetTotalFitness();
    }
    std::sort(population_->GetPopulation()->begin(), population_->GetPopulation()->end(), &comp);

    return std::make_tuple(g->GetOverallGenFitness(), population_->GetPopulation()->at(0)->GetGenoma());
}