#include "funciones.hpp"
#include "clases.hpp"


#define PRUEBA 10


std::tuple<char*, double, int, int, size_t> parser(int argc, char* argv[]){


    char *f ="Conocido.csv";
    double u = -1;
    int g = 500;
    int o = 1; 
    int pop_q = 10;

    for(size_t i = 0; i < argc; i++){
        if(strcmp(argv[i], "-f")==0){
            f = argv[i+1];
            i++;
        }else if(strcmp(argv[i], "-u")==0){
            u = strtod(argv[i+1], NULL);
            if(u<=0){
                u = -1; 
            }else{
                i++;
            }
        }else if(strcmp(argv[i], "-g")==0){
            g = strtol(argv[i+1], NULL, 10);
            if(g<=0){
                g = 10; 
            }else{
                i++;
            }
        }else if(strcmp(argv[i], "-o")==0){
            o = strtol(argv[i+1], NULL, 10);
            if(o <=0 || o!=1 || o !=2){
                o = 3;
            }
            i++;
        }else if(strcmp(argv[i], "--help")==0){
            return std::make_tuple(argv[i], u, g, o, pop_q);
        }else if(strcmp(argv[i], "-p")==0){
            pop_q = strtol(argv[i+1], NULL, 10);
            if(pop_q<=10){
                pop_q = 10; 
            }else if(pop_q>10){
                pop_q = 500; 
                i++;
            }
        }
    }

    return std::make_tuple(f,u,g,o, pop_q);
}

int main(int argc, char *argv[])
{
    
    std::tuple<char*, double, int, int, int> t = parser(argc, argv);
    if(strcmp(std::get<0>(t), "--help")==0){
        std::cout << "-f: file name for the graph" <<std::endl;
        std::cout << "-u: variation threshold" <<std::endl;
        std::cout << "-g: quantity of generations" <<std::endl;
        std::cout << "-o: return option. 1 for a graph of the best path, 2 for a graph based on overall fitness through the generations o 3 para los dos graficos" <<std::endl;
        std::cout << "-p: define quantity of individuals" <<std::endl;
        std::cout << "--help: get guidance" <<std::endl;
        return 0;
    }


    char* filefc = std::get<0>(t); 
    double umbral = std::get<1>(t);
    double gen = std::get<2>(t);
    double option = std::get<3>(t); 
    size_t pop_quantity = std::get<4>(t);

    
    srand(time(NULL));
    std::tuple<std::vector<Gen *> *, std::vector<City *> *, int> city_tuple = csv(filefc);

    std::vector<City *> *pC = std::get<1>(city_tuple);
    std::vector<Gen *> *pC2 = std::get<0>(city_tuple);
    int quant = std::get<2>(city_tuple);

    TravelerGeneticAlgorithm algorithm(pC, pC2, pop_quantity);
    TravelerGeneticAlgorithm *palgorithm = &algorithm;

    std::tuple<std::vector<double>*, std::vector<Gen*>*> data_tuple = palgorithm->Play(gen, umbral);
    std::vector<int> save_id;
    std::vector<std::tuple<double,double>>* xyvec = new std::vector<std::tuple<double,double>>;
    TranslateToCoord(&data_tuple, &save_id, pC, xyvec);

    
    generarCsv(std::get<0>(data_tuple),xyvec);

    if(option == 1){
        //EL GRAFICO DEL BEST PATH***
        system("python3 graphRoad.py");
    }else if(option==2){
        //EL GRAFICO DEL OVERALL FITNESS***
        system("python3 graphFittness.py");
    } else{
        system("python3 graphRoad.py");
        system("python3 graphFittness.py");
    }

    

    
    for(size_t i = 0; i < pC->size(); i++){
        delete pC->at(i);
    }
    
    delete pC;
    for(size_t i = 0; i < pC2->size(); i++){
        delete pC2->at(i);
    }
    delete pC2;

    
   
    delete xyvec;
    

    return EXIT_SUCCESS;
}