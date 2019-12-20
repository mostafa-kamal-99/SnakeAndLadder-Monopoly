#pragma once
#include "card.h"
class Player;
class CardEleven : public Card
{
	static int card_price;
	static int  fees;
	static Player *owner;
	static int exists;
	
public:
	CardEleven(const CellPosition & pos);
	CardEleven();
	void ReadCardParameters(Grid *);
	void Apply(Grid* pGrid, Player* pPlayer); 
	static void setExists(int);
	static int getExists();
	static void SetOwner(Player*);
	static Player* GetOwner();

	void Save(ofstream &OutFile) ;
	void Load(ifstream &Infile,Grid* pGrid) ;
	
	~CardEleven(void);
};


