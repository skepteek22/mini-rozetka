#include <iostream>
#include "View.h"
using namespace std;

int main()
{
    Model model;
    Controller controller(&model);
    View view(&controller);
    view.Start();
    return 0;
}

