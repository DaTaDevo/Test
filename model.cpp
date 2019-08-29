#include "model.h"

Procces::Procces()//стнадартные конструктор
{

}
void Procces::getdatafromfile(std::string name)//получение данных из файла под именем name 
{
    vec.clear();// очистка вектора перед внесением новых данных
    std::ifstream file;
    file.open(name+".txt");

    while (file >> m.name >> m.age >> m.sex)
    {
        vec.push_back(this->m);			//чтение  файла и внесение данных в вектор 
    }

    file.close();
}
Model Procces::fidnname(std::string name)		//поиск по имени 
{
    unsigned long long  size = vec.size();
    for(unsigned long long  i = 0; i<size; i++)
    {
        if(name == vec.at(i).name)
            return vec.at(i);// возвращаем обьект который нашли 
    }
}
void Procces::savedatainto(std::string file) //сохраняем данные в указанный файл
{
    std::ofstream f;
    f.open(file+".txt");

    for (unsigned long long i =0;i<vec.size();i++)
    {
        f << vec.at(i).name <<"\t"<< vec.at(i).age<<"\t"<< vec.at(i).sex << std::endl;
    }

    f.close();
}
void Procces::savemodel(Model* model)	//сохраняем модель в вектор
{
    vec.push_back(*model);
}
Model* Procces::readdata(Model *m)		//чтение данных из вектора 
{
    unsigned long long size = vec.size();
    for (unsigned long long i = 0; i < size;i++)
    {
        m[i] = vec.at(i);				//передаем данные из вектора в массив
    }
    return m;						//и возращаем данный массив 
}
