#include <iostream>
#include <model.h>

using namespace std;

int main ()
{
    Model m;
    m.addpeople("Name", 24,"man");
    m.addpeople("Name_1",23,"girl");
    cout <<m.get_info_about("Name_1")<< endl;
    return 0;
}