#include <iostream>
#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include <G4UIExecutive.hh>
#include <G4VisManager.hh>
#include <G4VisExecutive.hh>
#include <G4UImanager.hh>
#include <construction.hh>
#include "physics.hh"
#include "action.hh"
#include "G4HadronicParameters.hh"
#include <cstdlib>
#include <fstream>
#include "TH1.h"
#include "TFile.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TStyle.h"

void nn()
{
    using namespace std;
    TGraph *graph = new TGraph();
    graph->SetMarkerStyle(kFullCircle);

    fstream file;
    file.open("output.dat", ios::in);

    while(true)
    {
        double x, y;
        file >> x >> y;
        graph->SetPoint(graph->GetN(), x, y);
        if(file.eof()) break;
    }
    file.close();
    
    graph->GetXaxis()->SetTitle("Channel");
    graph->GetXaxis()->CenterTitle();
    graph->GetYaxis()->SetTitle("Counts");
    graph->GetYaxis()->CenterTitle();

    TCanvas *canvas = new TCanvas("canvas", "Exponential Decay Fit", 800, 600);
    graph->Draw("AL");

    graph->GetXaxis()->SetRangeUser(0, 2047);
    canvas->Update();
    canvas->SaveAs("EnergyDeposition.png");

}

int main(int argc, char** argv)
{
    system("rm *.png *.dat");
    G4RunManager *runManager = new G4RunManager();
    runManager->SetUserInitialization(new MyDetectorConstruction());
    runManager->SetUserInitialization(new MyPhysicsList());
    runManager->SetUserInitialization(new MyActionInitialization());


    // runManager->Initialize();
    G4HadronicParameters::Instance()->SetTimeThresholdForRadioactiveDecay( 1.0e+60*CLHEP::year );

    G4UIExecutive *ui = 0;
    if(argc == 1)
    {
        ui = new G4UIExecutive(argc, argv);
    }

    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();
    G4UImanager *UImanager = G4UImanager::GetUIpointer();

    if (ui)
    {
        runManager->Initialize();  
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart(); 
    }
    else
    {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
        //system("hadd test3.root *.root");
        //dot();
        nn();
    }

    return 0;
}
