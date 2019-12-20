#include "LaunchAttack.h"
#include "Attack.h"
#include "Ice.h"
#include "Lighting.h"
#include "Poison.h"
#include "Fire.h"
LaunchAttack::LaunchAttack(Grid* g )
{
	
	pGrid=g;
	Player *pPlayeratt=NULL;	
	Player *pPlayerdef=NULL;
	//pPlayerdef=p;

}
LaunchAttack::LaunchAttack()
{
}
		
void LaunchAttack::ReadActionParameters() // Reads LaunchAttack action parameters (AttackNumber, player to act)
{
// 1- Get a Pointer to the Input / Output Interfaces
	
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the "AttackNumber" parameter and set its data member
	pOut->PrintMessage("please enter an attack number Ice : 1 ,Fire : 2 , Poison : 3 , lighting : 4");
	int AttackNumberin= pIn->GetInteger(pOut);
	if (AttackNumberin>0 && AttackNumberin<5) AttackNumber=AttackNumberin;
	else AttackNumber=-1;
	//////////////////////////12.dec
	// 3- checking that player is not attacking himself
	if (AttackNumber!=4)
	{
	Player * attackingplayer=pGrid->GetCurrentPlayer();
	pOut->PrintMessage("please enter a player number to launch attack on ");
	int playernumin= pIn->GetInteger(pOut);
	if (playernumin>0 && playernumin<4) Playernum=playernumin;
	while (attackingplayer->get_player_num()==Playernum)
	{
	pOut->PrintMessage("please enter a valid player number to launch attack on ");
	int playernumin= pIn->GetInteger(pOut);
	if (playernumin>0 && playernumin<4) Playernum=playernumin;
	}
	// 4- assigning values
	for (int i=0;i<4;i++)
	{
		if ((pGrid->GetCurrentPlayer())->get_player_num()==Playernum) {pPlayerdef=(pGrid->GetCurrentPlayer()); /*break;*/}
		pGrid->AdvanceCurrentPlayer();
	}
	}
/* 5.dec
	// 3- Read the "Player number" 
	
	pOut->PrintMessage("please enter a player number to launch attack on ");
	int playernumin= pIn->GetInteger(pOut);
	if (AttackNumberin>0 && AttackNumberin<4) Playernum=playernumin;
	// the function used below makes its own validations , hence no else statment used
	pPlayerdef = pGrid->get_player_from_num (Playernum);
	// 4- the player is not attacking himself
	while (pPlayerdef==pPlayeratt)
	{
	pGrid->PrintErrorMessage("please enter a  valid player number to launch attack on ,click to containue...");
	int playernumin= pIn->GetInteger(pOut);
	if (AttackNumberin>0 && AttackNumberin<4) Playernum=playernumin;
	else continue;
	pPlayerdef = pGrid->get_player_from_num (Playernum);
	}
	*/
	// 5- Clear status bar
	
	pOut->ClearStatusBar() ;
}
	
 void LaunchAttack::Execute()
{
	this->ReadActionParameters();
	Attack * pAttack = NULL; 
	switch (AttackNumber)  //ice : 1 ,Fire : 2 , Poison : 3 , lighting : 4
	{
	case 1:  pAttack = new Ice(pGrid,pPlayerdef);  break;
	case 2:  pAttack = new Fire(pGrid,pPlayerdef);   break;
	case 3:  pAttack = new Poison(pGrid,pPlayerdef); break;	 
	case 4:  pAttack = new Lighting(pGrid,pPlayerdef);  break;
	}

	

}

LaunchAttack::~LaunchAttack(void)
{
}
