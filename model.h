#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <fstream>
#include <string>

struct Model
{
    std::string name;	//имя 
    int age;		//лет
    std::string sex;	//пол
    void operator = (Model m)//оператор присваивания
    {
        this->name = m.name;
        this->age = m.age;
        this->sex = m.sex;
    }
};


class Procces
{
    std::vector<Model> vec; //вектор для хранения данных
    Model m;
public:
    Procces();
    void savemodel(Model*);
    void getdatafromfile(std::string);
    Model fidnname(std::string);
    void savedatainto(std::string);
    Model* readdata(Model*);
};

#endif // MODEL_H
