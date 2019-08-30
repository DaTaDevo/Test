#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>

class Model;

class AbstractModel
{
public :
    virtual void addPeople(std::string, int , std::string) = 0;
    virtual Model findPeople(std::string) = 0;
    virtual std::string toString() = 0;
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
    void addPeople(std::string name, int age, std::string sex) override
    {
        m_name = name;
        m_age = age;
        m_sex = sex;
         _storage.push_back(*this);
    }
    Model findPeople(std::string name) override
    {
        std::vector<Model>::const_iterator iter_strg = _storage.cbegin();

        for(iter_strg;iter_strg < _storage.cend();iter_strg++)
        {
            if ( iter_strg->m_name== name)
            {
                return *iter_strg;
            }
        }
        return *this;
    }
    std::string toString() override
    {
        return this->m_name +"\t" + std::to_string(this->m_age) +"\t" + this->m_sex;
    }
};


#endif // MODEL_H
