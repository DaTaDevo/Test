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
    Mlist array(4);
    array[0] = 1.0;
    array[1] = 2.0;
    array[2] = 3.0;
    array[3] = 4.0;
    double *item = array.begin();
    cout <<*item<< endl;
    return 0;
}
