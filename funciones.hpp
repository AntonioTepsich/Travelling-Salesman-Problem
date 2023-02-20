#include "clases.hpp"

std::tuple<std::vector<Gen *> *, std::vector<City *> *, int> csv(char*);


void progreso(std::vector<double>*);

void recorrido(std::vector<double>,std::vector<double>);

void generarCsv(std::vector<double>*, std::vector<std::tuple<double,double>>*);

void TranslateToCoord(std::tuple<std::vector<double>*, std::vector<Gen*>*>*, std::vector<int>*, std::vector<City *> *, std::vector<std::tuple<double,double>>*);