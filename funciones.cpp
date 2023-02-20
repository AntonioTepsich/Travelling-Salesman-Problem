#include "funciones.hpp"


std::tuple<std::vector<Gen *> *, std::vector<City *> *, int> csv(char* fileforcities)
{
    std::vector<double> lat;
    std::vector<Gen *> *gen_vector = new std::vector<Gen *>;
    std::vector<City *> *city_vector = new std::vector<City *>;

    std::ifstream archivo(fileforcities);
    std::string linea;
    char delimitar = ',', buscar = '#';
    int counter = 0;

    getline(archivo, linea); 
    while (getline(archivo, linea))
    {
        std::stringstream stream(linea);
        std::string ciudad, x, y;
        // extraigo datos
        getline(stream, ciudad, delimitar);
        getline(stream, x, delimitar);
        getline(stream, y, delimitar);

        std::size_t found = ciudad.find(buscar);
        if (found == std::string::npos)
        {
            gen_vector->emplace_back(new City(stod(x), stod(y), counter));
            city_vector->emplace_back(new City(stod(x), stod(y), counter));
            counter++;
        }
    }
    archivo.close();


    return std::make_tuple(gen_vector, city_vector, counter);
}


void progreso(std::vector<double>* vec1){
    std::ofstream archivo;
    int num;
    archivo.open("progreso.csv", std::ios::out);
    if (archivo.fail()){
        std::cout << "ERR_CAN_NOT_OPEN_FILE";
        exit(1);
    }
    for (int i = 0; i < vec1->size(); i++){
        archivo << i;
        archivo << ',';
        archivo << vec1->at(i);
        archivo << "\n";
    }
    archivo.close();

}

void recorrido(std::vector<double> vecx,std::vector<double> vecy){
    std::ofstream archivo2;
    int num;

    archivo2.open("recorrido.csv", std::ios::out);
    if (archivo2.fail()){
        std::cout << "ERR_CAN_NOT_OPEN_FILE";
        exit(1);
    }
    for (int i = 0; i < vecx.size(); i++){
        archivo2 << vecx[i];
        archivo2 << ',';
        archivo2 << vecy[i];
        archivo2 << "\n";
    }
    archivo2.close();

}

void generarCsv(std::vector<double>* vf, std::vector<std::tuple<double,double>>* xyv){
    std::vector<double> vx;
    std::vector<double> vy;

    for(size_t i = 0; i < xyv->size(); i++){
        vx.emplace_back(std::get<0>(xyv->at(i)));
        vy.emplace_back(std::get<1>(xyv->at(i)));
    }


    progreso(vf);
    recorrido(vx,vy);
}

void TranslateToCoord(std::tuple<std::vector<double>*, std::vector<Gen*>*> *data_tuple, std::vector<int>* save_id, std::vector<City *> *pC, std::vector<std::tuple<double,double>>* xyvec){

    for(size_t i = 0; i < std::get<1>(*data_tuple)->size(); i++){
        save_id->emplace_back(std::get<1>(*data_tuple)->at(i)->GetId());
    }
    
    for(size_t j = 0; j < save_id->size(); j++){
        int curr_id = save_id->at(j);
        for(size_t i = 0; i < pC->size();i++){
            if(curr_id == pC->at(i)->GetId()){
                xyvec->emplace_back(std::make_tuple(pC->at(i)->GetX(), pC->at(i)->GetY())); 
            }
        }
    }
}