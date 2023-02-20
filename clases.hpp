#pragma once 
#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>


class Gen {
    protected:
        size_t id_;
    public:
        Gen(size_t i);
        size_t GetId() const;
};

class Individual {
    protected:
        size_t gen_quant_;
        std::vector<Gen*> *genoma_;
        double fitness_;
        double fitness_perc_;
    public:
        Individual();
        Individual(double, std::vector<Gen*>*);
        virtual ~Individual(); 
        size_t GetSize() const; 
        double GetFitness() const; 
        double GetFitnessPerc() const; 
        std::vector<Gen*>* GetGenoma() const; 
        void SetSize(size_t); 
        void SetFitness(double); 
        void SetFitPerc(double);
        void SetGenoma(std::vector<Gen*>*);
        virtual void Mutation() = 0;
};

class Fitness {
    public:
        Fitness();
        virtual ~Fitness();
        virtual double CalcFitness(std::vector<Gen*>*) = 0;
        double AssignFitness(Individual*);
};

class Population{
    protected:
        size_t pop_quantity_;
        std::vector<Individual*> *population_;
        std::vector<Gen*>* pos_genes_; 
        Fitness* f_;
        double total_fitness;

    public:
        Population(size_t, std::vector<Gen*>*, Fitness*, std::vector<Individual*>*, double);
        virtual ~Population();
        size_t GetPopQuantity()const;
        std::vector<Individual*>* GetPopulation()const;
        std::vector<Gen*>* GetPosGenes() const;
        Fitness* GetFitness() const;
				double GetTotalFitness();
        void SetPopQuantity(size_t);
        void SetPopulation(std::vector<Individual*>*);
        void SetPosGenes(std::vector<Gen*>*);
        void UpdateTotalFitness();
        void ToPerc(); //***
				void AddInd(Individual*);
        virtual void Mutation() = 0;
 

};

class GeneticAlgorithm{
    protected:
        Population *population_;
    public:
        GeneticAlgorithm();
        GeneticAlgorithm(Population*);
        virtual ~GeneticAlgorithm();
        Population* GetPopulation() const;

        virtual std::tuple<std::vector<double>*, std::vector<Gen*>*> Play(int, double)=0;
        virtual void ReprSelection(int) = 0;
        virtual Individual* Reproduction(Individual*, Individual*) = 0;
        virtual void SpartanSelection() = 0;
        virtual void Mutation() = 0;
        virtual void UpdateInfo() = 0;

};

//QUE DERIVAN:


class City : public Gen {
public:
    double x_;
    double y_; 
    City(double, double, size_t);
    double GetX() const;
    double GetY() const;

};


class DistanceMatrix {
    double **matrix_;
    size_t rows_;
    size_t col_;

public:
    DistanceMatrix(std::vector<City*>*);
    ~DistanceMatrix();   
    double** GetDistanceMatrix() const;
    size_t GetRows() const;
    size_t GetCol() const;
    void SetRows(size_t);
    void SetCol(size_t);

};

class TravelerFitness : public Fitness {
        DistanceMatrix *matrix_;
    public: 
        TravelerFitness(DistanceMatrix*);
        ~TravelerFitness();
        double CalcFitness(std::vector<Gen*>*) override;
};

class Path : public Individual {
    public:
        Path(std::vector<Gen*>*, Fitness*); 
        ~Path();
        void Mutation() override;
};

class TravelerPopulation : public Population {
    public:
        TravelerPopulation(size_t, std::vector<Gen*>*, Fitness*);
        ~TravelerPopulation();
        void Mutation() override;

};

class DataGuardian {
        std::vector<double> *overall_gen_fitness_;
    public:
        DataGuardian();
        ~DataGuardian();
        void AddOverallGenFitness(double f);
        std::vector<double>* GetOverallGenFitness();
    
};

class TravelerGeneticAlgorithm : public GeneticAlgorithm {
    DataGuardian *g;
public:
    TravelerGeneticAlgorithm(std::vector<City*>*, std::vector<Gen*>*, size_t);
    ~TravelerGeneticAlgorithm();
    std::tuple<std::vector<double>*, std::vector<Gen*>*> Play(int, double) override;
    void ReprSelection(int) override;
    Individual* Reproduction(Individual*, Individual*) override;
    void Mutation () override;
    void SpartanSelection() override;
    void UpdateInfo() override;

};