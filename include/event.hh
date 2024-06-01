#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4AnalysisManager.hh"
#include "run.hh"



class MyEventAction : public G4UserEventAction
{
public:
    MyEventAction(MyRunAction* runAction);
    ~MyEventAction();

    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);
    //void AddEventAction(MyEventAction* eventAction);

    void AddEdep(G4double edep){ fEdep += edep; } // 计算能量沉积

private:
    G4double fEdep;
    //std::vector<MyEventAction*> fEventActions;
    MyRunAction *fRunAction;
};



#endif