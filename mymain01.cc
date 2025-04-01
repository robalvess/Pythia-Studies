//Headers and Namespaces. (gg -> t t\bar)

#include "Pythia8/Pythia.h" //Include Pythia headers.
using namespace Pythia8; //Let Pythia8:: be implicit.

int main(int argc, char* argv[]){
    
    //Set up generation.
    Pythia pythia;
    pythia.readFile(argv[1]);
    pythia.init();
    int iTop = 0; //I will try to keep track of the remaining tops at each event.
    Hist topPt("top transverse momentum", 100, 0., 200.);
    Hist topEta("top pseudorapidity", 100, -5., 5.);
    Hist Pt("Transverse momentum", 100, 0., 200.);
    Hist eta("Pseurapidity", 100, -5., 5.);
    Hist pz("Z momentum", 100, -200.,200.);
    Hist charge("Charge multiplicity",100, -1., 399.);
    
    //Generate events.
    for (int iEvent = 0; iEvent < 20; ++iEvent){
        pythia.next();
        
        int entries = pythia.event.size(); //This gives us the number of particles created.
        std::cout << "Event: " << iEvent << std::endl;
        std::cout << "Event size: " << entries << std::endl;
        int multiplicity = 0;


        for (int i = 0; i < entries; i++) //Here I am looping over the # of particles created and getting their info. This is known as particle loop.
        {
            if (pythia.event[i].id() == 6) iTop = i;
            cout << "i = " << i << ", id = " << pythia.event[i].id() << endl;
            Pt.fill(pythia.event[i].pT());
            eta.fill(pythia.event[i].eta());
            pz.fill(pythia.event[i].pz());
            
            if (pythia.event[i].isFinal() && pythia.event[i].isCharged()) multiplicity ++;           
        }
        std::cout << "Top: " << iTop << std::endl;

        topPt.fill(pythia.event[iTop].pT());
        topEta.fill(pythia.event[iTop].eta());
        charge.fill(multiplicity);
     

    }


    HistPlot hpl("plot1");
    hpl.frame("output", "Transverse Momentum", "Transverse Momentum", "Entries");
    hpl.add(topPt);
    HistPlot hpl2("plot2");
    hpl2.frame("Pseudorapidity", "Pseudorapidity", "Pseudorapidity", "Entries");    
    hpl2.add(topEta);
    hpl.plot();
    hpl2.plot();

    HistPlot hpl3("plot3");
    hpl3.frame("pt", "Transverse Momentum", "Transverse Momentum", "Entries");
    hpl3.add(Pt);
    hpl3.plot();

    HistPlot hpl4("plot4");
    hpl4.frame("eta", "Pseudorapidity", "Pseudorapidity", "Entries");
    hpl4.add(eta);
    hpl4.plot();

    HistPlot hpl5("plot5");
    hpl5.frame("pz", "pz", "pz", "entries");
    hpl5.add(pz);
    hpl5.plot();

    HistPlot hpl6("plot6");
    hpl6.frame("Charge Multiplicity", "Charge Multiplicity", "Charge Multiplicity", "Entries");
    hpl6.add(charge);
    hpl6.plot();
    
    pythia.stat();
    return 0;


}
