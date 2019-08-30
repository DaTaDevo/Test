#include <iostream>
#include <model.h>

using namespace std;

int main ()
{
    Model m;
    m.addPeople("Name", 24,"man");
    m.addPeople("Name_1",23,"girl");
    std::string str = m.findPeople("Name").toString();
    cout <<str<< endl;
    return 0;
}
