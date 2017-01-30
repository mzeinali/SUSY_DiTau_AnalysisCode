#include <fstream>
using namespace std;

void XSectionReader()
{ 
    ifstream fin("xsec_C1C1_wino.txt");

    double chiMass;
    double xsection;
    double error;

    while (fin >> chiMass >> xsection >> error)
    {
        /* do something with name, var1 etc. */
        //cout << " " << chiMass << " " << xsection << " " << error << "\n";
        //cout<<"xsection:  "<<xsection<<endl;
        cout<<"    "<<chiMass<<":"<<xsection<<","<<endl;
    }
}
