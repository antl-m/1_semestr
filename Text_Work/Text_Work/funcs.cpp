#include "funcs.h"

void symb_count(string file)
{
	ifstream fin;

	fin.open(file);
	
	char symb;

	int letters = 0, symbs = 0, marks = 0;

	if(fin)
	{
		while (fin.get(symb))
		{
			
			
			if ((symb >='A' && symb<='Z') || (symb >= 'a' && symb <= 'z'))
			{
				letters++;
			}
			else if (symb == '.' || symb == ',' || symb == '-' || symb == '!' || symb == '?' || symb == ':' || symb == ';' || symb == '"' || symb == '(' || symb == ')')
			{
				marks++;
			}
			symbs++;
		}
		
		cout << "Letters: "<< letters << endl;
		cout << "Punctuation marks: "<< marks << endl;
		cout << "Symbols: " << symbs << endl << endl;
		
	} else { cout << "error" << endl; }

	fin.close();
}

void word_count(string file)
{
	ifstream fin;

	fin.open(file);

	string word;

	int sent = 0, words=0;


	if (fin)
	{
		while (fin >> word)
		{
		
			

			if (word[word.size() - 1] == '.' || word[word.size() - 1] == '!' || word[word.size() - 1] == '?')
			{
				sent++;
				words++;
			}
			else { words++; }

		}
		
		cout << "Words: " << words << endl;
		cout << "Sentences: " << sent << endl<<endl;
	}

	fin.close();
}

void sound_count(string file)
{
	ifstream fin;

	fin.open(file);

	string word;

	int gol = 0, prygol = 0;


	if (fin)
	{
		while (fin >> word)
		{
			
			
			for (int i = 0; i < word.size(); i++)
			{
				if (!((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')))
				{
					continue;
				}
				else if(word[i] == 'A' || word[i] == 'a' || word[i] == 'E' || word[i] == 'e' || word[i] == 'I' || word[i] == 'i' || word[i] == 'O' || word[i] == 'o' || word[i] == 'U' || word[i] == 'u' || word[i] == 'Y' || word[i] == 'y')
				{
					for (int k = word.size() - 1; k >=0; k--)
					{
						if (!((word[k] >= 'A' && word[k] <= 'Z') || (word[k] >= 'a' && word[k] <= 'z')))
						{
							continue;
						}
						else if (word[k] == 'A' || word[k] == 'a' || word[k] == 'E' || word[k] == 'e' || word[k] == 'I' || word[k] == 'i' || word[k] == 'O' || word[k] == 'o' || word[k] == 'U' || word[k] == 'u' || word[k] == 'Y' || word[k] == 'y')
						{
							gol++;
							break;
						}
						else { break; }

					}
					break;
				}
				else 
				{
					for (int m = word.size() - 1; m >= 0; m--)
					{
						if (!((word[m] >= 'A' && word[m] <= 'Z') || (word[m] >= 'a' && word[m] <= 'z')))
						{
							continue;
						}
						else if (!(word[m] == 'A' || word[m] == 'a' || word[m] == 'E' || word[m] == 'e' || word[m] == 'I' || word[m] == 'i' || word[m] == 'O' || word[m] == 'o' || word[m] == 'U' || word[m] == 'u' || word[m] == 'Y' || word[m] == 'y'))
						{
							prygol++;
							break;
						}
						else { break; }

					}
					break;
				}

			}

		}

		cout << "Golosni: " << gol << endl;
		cout << "Prygolosni: " << prygol << endl<<endl;
	}

	fin.close();
}

void double_count(string file)
{
	ifstream fin;

	fin.open(file);

	string word;

	int words = 0;


	if (fin)
	{
		while (fin>>word)
		{
		

			for (int i = 0; i < word.size()-1; i++)
			{
				if (word[i] == word[i + 1] && ((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')))
				{
					words++;
					cout << word << endl;
				}
			}

		}

		cout << "Words with double letters: " << words << endl<<endl;
	}

	fin.close();
}

void max_min_word(string file)
{
	
	ifstream fin;

	fin.open(file);

	string word, min, max;

	if (fin)
	{
		bool flag = 1;

		while (fin >> word)
		{

			if (flag)
			{
				min = word;
				max = word;
				flag = 0;
			}

			if (word.size() > max.size()) { max = word; }
			
			if (word.size() < min.size()) { min = word; }

		}

		cout << "Max word have " << max.size() << " letters: "<< max << endl;
		cout << "Min word have " << min.size() << " letters: "<< min << endl<< endl;
	}

	fin.close();
}

void search(string file)
{
	ifstream fin;

	fin.open(file);

	string word, search;

	cout << "Searchable word: ";

	cin >> search;

	if (fin)
	{
		bool flag = 0;

		while (fin >> word && !flag)
		{
			

			if (search.size()==word.size()) 
			{
				for (int i = 0; i < search.size(); i++)
				{
					if (search[i] == word[i]) { flag = 1; }
					else if (search[i] == word[i]+32) { flag = 1; }
					else if (search[i] == word[i]-32) { flag = 1; }
					else { flag = 0; break; }
				}
			}
		}

		if (flag)
		{
			cout << "True" << endl<< endl;
		}
		else
		{
			cout << "False" << endl << endl;
		}

	}

	fin.close();
}

void redo_gol(string file)
{
	ifstream fin;
	ofstream fout;

	fin.open(file);
	fout.open("C:/Users/Antl_M/Desktop/text2.txt");

	fin.seekg(0, ios::cur);
	fout.seekp(0, ios::cur);

	char a;

	if (fin)
	{
		while (fin.get(a))
		{
			

			if (a == 'A' || a == 'a' || a == 'E' || a == 'e' || a == 'I' || a == 'i' || a == 'O' || a == 'o' || a == 'U' || a == 'u' || a == 'Y' || a == 'y')
			{
				fout.put('*');
			}
			else { fout.put(a);}
		}
		cout << "Success" << endl << endl;
	}
	else
	{
		cout << "Error" << endl << endl;
	}

	fin.close();
	fout.close();
}

void delete_gol(string file)
{
	ifstream fin;
	ofstream fout;

	fin.open(file);
	fout.open("C:/Users/Antl_M/Desktop/text2.txt");

	fin.seekg(0, ios::cur);
	fout.seekp(0, ios::cur);

	char a;

	if (fin)
	{
		while (fin.get(a))
		{
			

			if (a == 'A' || a == 'a' || a == 'E' || a == 'e' || a == 'I' || a == 'i' || a == 'O' || a == 'o' || a == 'U' || a == 'u' || a == 'Y' || a == 'y')
			{
				
			}
			else { fout.put(a); }
		}
		cout << "Success" << endl << endl;
	}
	else
	{
		cout << "Error" << endl << endl;
	}

	fin.close();
	fout.close();
}

void redo_k(string file)
{
	ifstream fin;
	ofstream fout;

	fin.open(file);
	fout.open("C:/Users/Antl_M/Desktop/text2.txt");

	fin.seekg(0, ios::cur);
	fout.seekp(0, ios::cur);

	char a;

	if (fin)
	{
		while (fin.get(a))
		{
			

			if (a == 'k' || a=='K')
			{
				fout.put('m'); fout.put('a'); fout.put('t'); fout.put('h');
			}
			else { fout.put(a); }
		}
		cout << "Success" << endl << endl;
	}
	else
	{
		cout << "Error" << endl << endl;
	}

	fin.close();
	fout.close();
}

string clear(string file)
{
	ifstream fin;
	ofstream fout;

	fin.open(file);
	fout.open("C:/Users/Antl_M/Desktop/text2.txt");

	fin.seekg(0, ios::cur);
	fout.seekp(0, ios::cur);

	char a;

	if (fin)
	{
		while (fin.get(a))
		{
			

			if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || a == ' ')
			{
				fout.put(a);
			}
			else if (a == '.' || a == ',' || a == '!' || a == '?' || a == ':' || a == ';' || a == '"' || a == '(' || a == ')'||a=='\n') 
			{ fout.put(' '); }
		}
	}

	fin.close();
	fout.close();
	return "C:/Users/Antl_M/Desktop/text2.txt";
}
