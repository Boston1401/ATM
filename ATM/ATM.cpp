#include "ATMFunct.h"

void main()
{
	client tabsinfo[200];
	int NBClients, N, H, Ammount;
	string ACCTNumber, NIP;
	short option;


	DisplayFirstTitle("BANQUE ROYALE");
	DisplaySecondTitle("Guichet Automatique Bancaire");
	NBClients = ReadClientInfoFromFile(tabsinfo);


	/*DisplayClientInfoFromFile(tabsinfo, NBClients);*/

	ACCTNumber = ReadAccountNumber(tabsinfo, NBClients);
	N = ValidateAccountNumber(tabsinfo, ACCTNumber, NBClients);
	NIP = ReadAccountNip(tabsinfo, NBClients, N);
	H = ValidateAccountNip(tabsinfo, NIP, ACCTNumber, NBClients);
	DisplayATMMenu(H);
	option = Readmakechoice("Entrez votre choix (1-3) : ");
	switch (option)
	{

	case 1:

		/*cout << "The option is : " << option << endl;*/

		Ammount = ReadAmountDeposer("Entrez le montant a deposer $ : ", tabsinfo);
		ConsultClientInfoUpdate(tabsinfo, ACCTNumber, NBClients, Ammount, option);
		OWClientInfoToFile(tabsinfo, NBClients);
		
		break;

	case 2:


		/*cout << "The option is : " << option << endl;*/

		Ammount = ReadAmountRetirer("Entrez le montant a retirer $ : ", tabsinfo, NBClients, ACCTNumber);
		ConsultClientInfoUpdate(tabsinfo, ACCTNumber, NBClients, Ammount, option);
		OWClientInfoToFile(tabsinfo, NBClients);

		break;

	default:

		ConsultClientInfo(tabsinfo, ACCTNumber, NBClients);

		break;
	}

	Merci("Merci d'avoir utiliser nos services\nAppuyez sur une touche pour continuer...");
	
	

}