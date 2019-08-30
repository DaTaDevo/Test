#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>


class AbstractModel
{
public :
    virtual void saveinvector() = 0;
    virtual void setmodel(std::string, int , std::string) = 0;
    virtual std::string get_info_about(std::string) = 0;
};

class  Model : public  AbstractModel
{
private :
    std::string m_name;	//имя
    int m_age;		//лет
    std::string m_sex;	//пол
    std::vector <Model> _storage;
public :
    void operator = (Model m)  //оператор присваивания
    {
        this->m_name = m.m_name;
        this->m_age = m.m_age;
        this->m_sex = m.m_sex;
    }
//    void saveinvector() override
//    {
//        _storage.push_back(*this);
//    }
    void addpeople(std::string name, int age, std::string sex) override
    {
        m_name = name;
        m_age = age;
        m_sex = sex;
         _storage.push_back(*this);
    }
    std::string get_info_about(std::string name) override
    {
        for(int i =0;i < _storage.size();i++)
        {
            if (_storage.at(i).m_name == name)
            {
                return _storage.at(i).m_name + "\t" + std::to_string(_storage.at(i).m_age)+ "\t" + _storage.at(i).m_sex;
            }
        }
        return "Not Found!";
    }
};


#endif // MODEL_H
