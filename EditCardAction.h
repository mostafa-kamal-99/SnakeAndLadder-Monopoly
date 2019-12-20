#pragma once

#include "Action.h"

class EditCardAction : public Action
{
	int cardNumber;            // 1- the card number
	CellPosition cardPosition;
	// Note: These parameters should be read in ReadActionParameters()

public:
	EditCardAction(ApplicationManager *pApp); // A Constructor
	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute(); // Creates a new Card Object of the specific Card Number
	                        // and Reads the Parameters of This Card Number (if any)
	                        // then Sets this Card Object to GameObject Pointer of its Cell

	virtual~EditCardAction();
};

