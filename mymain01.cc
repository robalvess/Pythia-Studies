//Headers and Namespaces. (gg -> t t\bar)

#include "Pythia8/Pythia.h" //Include Pythia headers.
using namespace Pythia8; //Let Pythia8:: be implicit.

int main(){
    
    //Set up generation.
    Pythia pythia;
    pythia.readString("Top:gg2ttbar = on"); //This is to switch on the process.
    pythia.readString("Top:qqbar2ttbar = on");
    pythia.readString("Beams:eCM = 8000."); //The usual scale is GeV, therefore this one is 8TeV.
    pythia.init();
    
    //Generate events.
    for (int iEvent = 0; iEvent < 5; ++iEvent){
        pythia.next();
        for (int i = 0; i < pythia.event.size(); i++){
            cout << "i = " << i << ", id = " << pythia.event[i].id() << endl;           
        }
    }
    
    pythia.stat();
    return 0;


}
