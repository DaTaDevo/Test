#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>


class Mlist //свой контейнер M - my или model (если будет использовать для модели ) list
{
    int length = 0;
    double* array = new double[length];
public:
    Mlist()
    {

    }
    Mlist(int size) : length(size)
    {

    }
    ~Mlist()
    {
        delete [] array;
    }
    void setlength(int size)
    {
        this->length = size;
    }
    int size()
    {
        return this->length;
    }
    void push_back( double item)
    {
        length++;
        array[length-1] = item;
    }
    void pop_back()
    {
        if (length-1 <= 0)//проверка на то будет ли массив пустым после выполнений функции
        {
            this->array = nullptr;
            length = 0;
            this->array = new double[length];
            return;
        }
            length --;
            double temp_array[this->length];
            for (int i = 0;i<length;i++)
            {
                temp_array[i] = this->array[i];
            }

            this->array = nullptr;  //читим массив дял присовоенния новых данных
            this->array = new double [length];
            for (int i = 0; i < length; ++i)
            {
                this->array[i] = temp_array[i];
            }
    }
    void push_front(double item)
    {
        length++;
        if (length-1 == 0)//проверка был ли массив пустым до выпонения этой функции
        {
            push_back(item);
            return;
        }
        for (int i = length-1;i>0;i--)
        {
            this->array[i] = this->array[i-1];
        }
        this->array[0] = item;
    }
    void pop_front()
    {
        if(length - 1 == 0)
        {
            this->array = nullptr;
            length--;
            this->array = new double[length];
            return;
        }
        else if (length - 1 < 0)
            return ;

        length --;
        double temp_array[length];
        for (int i = 0; i < length ;i++)
        {
            temp_array[i] = this->array[i+1];
        }
        //очистка array
        this->array = nullptr;
        this->array = new double[length];
        for (int i  = 0; i < length;i++)
        this->array[i] = temp_array[i];
    }
    double* begin()
    {
        return &array[0];
    }
    double* end ()
    {
        return &array[length-1];
    }
    double& operator [](const int index)
    {
        return array[index];
    }
};

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
