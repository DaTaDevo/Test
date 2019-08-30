#include <iostream>
#include <model.h>

using namespace std;

int main ()
{
    Model m;
    m.setmodel("Name", 24,"man");
    m.saveinvector();
    m.setmodel("Name_1",23,"girl");
    m.saveinvector();
    cout <<m.get_info_about("Name_1")<< endl;
    return 0;
}
