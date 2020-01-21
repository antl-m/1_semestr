/*
1. порахувати к≥льк≥сть букв, символ≥в та розд≥лових знак≥в розд≥лов≥ знаки : ., -!? : ; Ф()
2. порахувати к≥льк≥сть сл≥в та речень
3. порахувати к≥льк≥сть сл≥в, що починаютьс€ та зак≥нчуютьс€ голосною / приголосною буквою
4. порахувати к≥льк≥сть сл≥в(та вивести њх на екран), €к≥ м≥ст€ть подвоЇн≥ букви
5. вивести найдовше / найкоротше слово та його довжину
6. перев≥рити на на€вн≥сть у текст≥ слово, введене користувачем
7. зам≥нити в текст≥ вс≥ голосн≥ букви символом *
8. видалити вс≥ голосн≥ букви
9. зам≥нити вс≥ л≥тери k на р€док УmathФ
*/


#include "funcs.h"

int main()
{
	string file = "C:/Users/Antl_M/Desktop/text.txt";

	bool exit = 0;

	while (1)
	{
		int key;

		cout << "Input number(1-9) of function (0 to exit): ";

		cin >> key;

		cout << endl;

		switch (key) 
		{
		case 1: symb_count(file); break;
		case 2: word_count(file); break;
		case 3: sound_count(clear(file)); break;
		case 4: double_count(clear(file)); break;
		case 5: max_min_word(clear(file)); break;
		case 6: search(clear(file)); break;
		case 7: redo_gol(file); break;
		case 8: delete_gol(file); break;
		case 9: redo_k(file); break;
		case 0: exit = 1; break;
		}
		
		if (exit) { break; }
	}
	return 0;
}


/*English is a West Germanic language that was
first spoken in early medieval Englandand eventually became a global
lingua franca.It is named after the Angles, one of the Germanic
tribes that migrated to the area of Great Britain that later took their
name, as England.Both names derive from Anglia, a peninsula in the
Baltic Sea.The language is closely related to Frisianand Low Saxon, and
its vocabulary has been significantly influenced by other Germanic
languages, particularly Norse(a North Germanic language), and to a
greater extent by Latinand French.*/