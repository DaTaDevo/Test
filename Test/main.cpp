#include <iostream>
#include <model.h>

using namespace std;

int main ()
{
    Model m;
    Model m2;
    m.addPeople("Name", 24,"man");
    m.addPeople("Name_1",23,"girl");
    m2 = m;
    std::string str = m.toString();
    cout <<str<< endl;
    return 0;
}
