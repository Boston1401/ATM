//#include "ATMBANK.h"
//
//void yhhmainyuju()
//{
//	client tabsinfo[5];
//	string ACCTNumber, NIP;
//	int NBClients, N;
//	short option;
//
//	DisplayFirstTitle("BANQUE ROYALE");
//	DisplaySecondTitle("Guichet Automatique Bancaire");
//
//	NBClients = ReadClientInfoFromFile(tabsinfo);
//
//	cout << NBClients << endl;
//
//	DisplayClientInfoFromFile(tabsinfo, NBClients);
//	ACCTNumber = ReadAccountNumber(NBClients, tabsinfo);
//	
//	/*n = ValidateAccountNumber(tabsinfo, ACCTNumber, NBClients);*/
//
//	
//	NIP = ReadAccountNip(tabsinfo, ACCTNumber, NBClients);
//
//	N = ValidateAccountNumberAndNIP(tabsinfo, NIP, ACCTNumber, NBClients);
//
//	DisplayATMMenu(N);
//
//	option = Readmakechoice("Entrez votre choix (1-3) : ");
//
//	switch (option)
//	{
//
//	case 1: 
//		ReadAmountDeposerRetirer("Entrez le montant a deposer $ : ", option);
//
//		ConsultClientInfo(tabsinfo, ACCTNumber, NBClients);
//		break;
//		
//	case 2:
//		ReadAmountDeposerRetirer("Entrez le montant a retirer $ : ");
//
//		ConsultClientInfo(tabsinfo, ACCTNumber, NBClients);
//		break;
//
//
//	default:
//
//		ConsultClientInfo(tabsinfo, ACCTNumber, NBClients);
//
//		break;
//	}
//	
//
//	Merci();
//
//
//
//}