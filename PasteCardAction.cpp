#include "PasteCardAction.h"

#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"

#include "CardOne.h"
#include "CardTwo.h"
#include"CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"


PasteCardAction::PasteCardAction(ApplicationManager *pApp) : Action(pApp)
{
}
void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("click on the destination cell...");

}
void PasteCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	ReadActionParameters();
	pCard=pGrid->GetClipboard();
	if(pCard)
	{
		pos =new CellPosition( pIn->GetCellClicked());
		int cardNumber=pCard->GetCardNumber();

		switch (cardNumber) // not completed
		{
		case 1: pCard = new CardOne(*pos); break;
		case 2: pCard = new CardTwo(*pos); break;
		case 3: pCard = new CardThree(*pos); break;
		case 4: pCard = new CardFour(*pos); break;
		case 5: pCard = new CardFive(*pos); break;	 
		case 6: pCard = new CardSix(*pos); break;
		case 7: pCard = new CardSeven(*pos); break;
		case 8: pCard = new CardEight(*pos); break;
		case 9: pCard = new CardNine(*pos); break;
		case 10: pCard = new CardTen(*pos); break;
		case 11: pCard = new CardEleven(*pos); break;
		case 12: pCard = new CardTwelve(*pos); break;
		case 13: pCard = new CardThirteen(*pos); break;
		case 14: pCard = new CardFourteen(*pos); break;
		}
	}
	else
	{
		pGrid->PrintErrorMessage("Clipboard has no card to paste.");
		return;
	}
	if(pos->IsValidCell())
	{
		if(pCard)
		{
			bool obj_can_be_added = ( pGrid-> AddObjectToCell(pCard) );
			if (obj_can_be_added) 
				pCard->Draw(pOut);
			pOut->ClearStatusBar();
		}
		else
		{
			pOut->ClearStatusBar();
			return;
		}
	}
}
PasteCardAction::~PasteCardAction()
{
}
