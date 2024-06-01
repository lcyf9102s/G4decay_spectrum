#include "run.hh"
#include "G4SystemOfUnits.hh"
#include <CLHEP/Units/SystemOfUnits.h>
#include <fstream>
#include <iostream>
#include "event.hh"


MyRunAction::MyRunAction()
{
    //G4AnalysisManager *man = G4AnalysisManager::Instance();
    //man->CreateNtuple("Hits", "Hits");
    //man->CreateNtupleIColumn("fEvent");
    //man->CreateNtupleDColumn("fX");
    //man->CreateNtupleDColumn("fY");
    //man->CreateNtupleDColumn("fZ");
    //man->CreateNtupleDColumn("Edep");
    //man->CreateH1("Edep", "Energy deposition", 2048, 0.*MeV, 8.*MeV);
    //man->FinishNtuple(0);
    
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
    //G4AnalysisManager *man = G4AnalysisManager::Instance();
    //man->CreateH1("Edep", "Energy deposition", 2048, 0.*MeV, 8.*MeV);
    //G4int runID = run->GetRunID();
    //std::stringstream strRunID;
    //strRunID << runID;
    nBins = 2048;
    globalHistogram.resize(nBins, 0.0);

    //man->OpenFile("output"+strRunID.str()+".root");

}



void MyRunAction::EndOfRunAction(const G4Run*)
{
    //G4AnalysisManager *man = G4AnalysisManager::Instance();
    std::ofstream outFile("output.dat");
    for(int i = 0; i < 2048; i++)
    {
        outFile << i << " " << globalHistogram[i] << "\n";
    }
    outFile.close();
    //man->Write();
    //man->CloseFile();
    
}

//void MyRunAction::AddEventAction(MyEventAction* eventAction) {
//    fEventActions.push_back(eventAction);
//}
