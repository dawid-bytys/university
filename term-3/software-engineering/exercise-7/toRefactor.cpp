#include <iostream>
class sprzedawca
{
	
	public: 
	int liczbaOpoznionychDostaw=0;
	
	void raportujOpoznionaDostawe()
	{
		liczbaOpoznionychDostaw++;
	};
	
	bool ileOpoznien()
	{
		return liczbaOpoznionychDostaw>5;
	}
	bool sprawdzTerminowoscSprzedawcy()
	{
	     return ileOpoznien()? false : true;
	};
	//inne pola metody itd;
};


