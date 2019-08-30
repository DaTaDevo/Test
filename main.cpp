#include <iostream>
#include <model.h>

using namespace std;

int main ()
{
    Model m;
    string str;
    m.addpeople("Name", 24,"man");
    m.addpeople("Name_1",23,"girl");
    str = m.findpeople("Name_1");
    return 0;
}
