#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct client
{

	string Numero, ClientName, Nip;
	long Solde;

};

void DisplayFirstTitle(string TheTitle)
{
	cout << "\t\t";

	for (int i = 0; i < TheTitle.length(); i++)
	{
		cout << (char)toupper(TheTitle[i]);
	}

	cout << "\n\t\t";

	/*cout << TheTitle << "\n\t";*/

	for (int i = 0; i < TheTitle.length(); i++)
	{
		cout << "-";
	}

	cout << "\n";
}

void DisplaySecondTitle(string TheTitle)
{
	cout << "\t";

	for (int i = 0; i < TheTitle.length(); i++)
	{
		cout << (char)toupper(TheTitle[i]);
	}

	cout << "\n\t";

	/*cout << TheTitle << "\n\t";*/

	for (int i = 0; i < TheTitle.length(); i++)
	{
		cout << "-";
	}

	cout << "\n";
}

int ReadClientInfoFromFile(client info[])
{
	ifstream BankData;
	string amount;
	int i = 0;

	BankData.open("clients.txt");

	while (BankData.eof() == false)
	{

		getline(BankData, info[i].Numero);
		getline(BankData, info[i].ClientName);
		getline(BankData, info[i].Nip);
		getline(BankData, amount);
		info[i].Solde = stof(amount);

		i++;

	}

	BankData.close();

	return i;

}

void DisplayClientInfoFromFile(client info[], int NBclients)
{

	for (int i = 0; i < NBclients; i++)
	{

		cout << "The Client " << i + 1 << " Account Number is : " << info[i].Numero << endl;
		cout << "The Client " << i + 1 << " Name is : " << info[i].ClientName << endl;
		cout << "The Client " << i + 1 << " NIP is : " << info[i].Nip << endl;
		cout << "The client " << i + 1 << " Solde is : " << info[i].Solde << endl;

	}


}

string ReadAccountNumber(client info[], int NBclients)
{

	string comptenum;


	cout << "Entrez votre numero de compte : ";
	cin >> comptenum;

	/*cout << comptenum << endl;*/


	return comptenum;
}

int ValidateAccountNumber(client info[], string AccountNumber, int NBclients)
{
	int n = 0;




		for (int i = 0; i < NBclients; i++)
		{
			if (info[i].Numero == AccountNumber)
			{
				cout << "\tBienvenue " << info[i].ClientName << endl;
				n = 1;
			}

		}




	return n;


}

string ReadAccountNip(client info[], int NBclients, int n)
{

	string nip = "x";


	
	if (n == 1)
	{

		cout << "Entrez votre nip : ";
		cin >> nip;

		/*cout << nip << endl;*/

	}
	
	else
	{

		cout << "Account number not found\n";
	
	}

	return nip;
}

int ValidateAccountNip(client info[], string nip, string AcctNumber, int NBclients)
{
	int h = 0;
	
	
	for (int i = 0; i < NBclients; i++)
	{
		if (info[i].Numero == AcctNumber && info[i].Nip == nip)
		{
			/*cout << "Valid NIP\n";*/
			h = 1;
		}

	}




	return h;


}

void DisplayATMMenu(int h)
{

		switch (h)
		{

		case 1:
			cout << "\n\n";
			cout << "Choisir votre Transaction\n";
			cout << "\t 1 - Pour Deposer\n";
			cout << "\t 2 - Pour Retirer\n";
			cout << "\t 3 - Pour Consulter\n";

			break;


		default:

			cout << "ERROR! Account Nip invalid\n";

			break;
		}
	
	

}

short Readmakechoice(string choicetext)
{
	short option;

	do
	{
		cout << choicetext;
		cin >> option;

	} while (option < 1 || option > 3);


	return option;

}

int ReadAmountDeposer(string text, client info[])
{
	int AmmountDepo;
	
	
	cout << "\n";

	

		do
		{
			cout << text;
			cin >> AmmountDepo;

		} while (AmmountDepo < 2 || AmmountDepo > 20000);



		cout << "\n";
		cout << "--- la transaction a reussi ---\n\n";

	return AmmountDepo;

}


int ReadAmountRetirer(string text, client info[], int NBclients, string AccountNumber)
{
	int AmmountRetirer;

	cout << "\n";
	
	for (int i = 0; i < NBclients; i++)
	{
		if (info[i].Numero == AccountNumber)
		{
			do
			{

				cout << text;
				cin >> AmmountRetirer;

			} while (AmmountRetirer < 20 || AmmountRetirer > 500 && AmmountRetirer < info[i].Solde );
			
		}

	}
	


	cout << "\n";
	cout << "--- la transaction a reussi ---\n\n";

	return AmmountRetirer;


}

void ConsultClientInfo(client tabs[], string comptenum, int NBClients)
{
	for (int i = 0; i < NBClients; i++)
	{
		if (tabs[i].Numero == comptenum)
		{
			cout << "Les infos du compte\n";
			cout << "\tNumero : " << comptenum << endl;
			cout << "\tClient : " << tabs[i].ClientName << endl;
			cout << "\tNip : " << tabs[i].Nip << endl;
			cout << "\tSolde $ : " << tabs[i].Solde << endl;
		}

	}

}

void ConsultClientInfoUpdate(client tabs[], string comptenum, int NBClients, int Ammount, short option)
{
	for (int i = 0; i < NBClients; i++)
	{
		if (tabs[i].Numero == comptenum)
		{
			if (option == 1)
			{
				tabs[i].Solde = tabs[i].Solde + Ammount;
			}

			if (option == 2)
			{
				tabs[i].Solde = tabs[i].Solde - Ammount;
			}
			
			cout << "Les infos du compte\n";
			cout << "\tNumero : " << comptenum << endl;
			cout << "\tClient : " << tabs[i].ClientName << endl;
			cout << "\tNip : " << tabs[i].Nip << endl;
			cout << "\tSolde $ : " << tabs[i].Solde << endl;
		}

	}

}


void OWClientInfoToFile(client info[], int NBClients)
{
	ofstream BankData;
	string amount;
	

	BankData.open("clients.txt");

	for (int i = 0; i < NBClients; i++)
	{

		BankData << info[i].Numero << endl;
		BankData << info[i].ClientName << endl;
		BankData << info[i].Nip << endl;

		if (i == NBClients - 1)
		{
			BankData << info[i].Solde;
		}
		
		else
		{
			BankData << info[i].Solde << endl;
		}
		

	}

	BankData.close();

	

}



void Merci(string FinalText)
{

	cout << "\n\n";
	cout << FinalText << endl;


}
