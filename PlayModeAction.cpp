#include "PlayModeAction.h"

#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "Player.h"


PlayModeAction::PlayModeAction(ApplicationManager *pApp) : Action(pApp)
{
}
void PlayModeAction::ReadActionParameters()
{
}
void PlayModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Do you want to save before proceeding? Y/N ");
	string choice = pIn->GetSrting(pOut);
	if(choice=="Y"|| choice=="y")
	{
		pManager->ExecuteAction(Save_Grid);
		pOut->CreatePlayModeToolBar();
	}
	else
		pOut->CreatePlayModeToolBar();
}

PlayModeAction::~PlayModeAction()
{
}
