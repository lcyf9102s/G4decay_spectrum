#ifndef RUN_HH
#define RUN_HH

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "G4AnalysisManager.hh"
//#include "event.hh"



class MyRunAction : public G4UserRunAction
{
public:
    MyRunAction();
    ~MyRunAction();

    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
    //void AddEventAction(MyEventAction* eventAction);
    void AddHist(G4double fEdep) {
        if((fEdep > 0)&&(fEdep < 8))
    {
        int ch = ceil(((fEdep)*2048)/8);
        globalHistogram[ch] += 1;
    }
    };

private:
    //std::vector<MyEventAction*> fEventActions;
    std::vector<G4double> globalHistogram;
    G4double minEnergy;
    G4double maxEnergy;
    G4int nBins;

    
};

#endif