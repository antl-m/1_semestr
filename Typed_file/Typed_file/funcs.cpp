#include "funcs.h"
using namespace std;



void maxmin(string file)
{
	ifstream fin;

	fin.open(file);

	countr str, max, min;

	max.lito = 0;
	max.osin  = 0;
	max.zyma  = 0;
	max.vesna = 0;
	min.lito = INT16_MAX;
	min.osin = INT16_MAX;
	min.zyma = INT16_MAX;
	min.vesna = INT16_MAX;

	int key;

	if (fin)
	{
		cout << "Choose season: " << endl;
		cout << "1.Lito " << endl;
		cout << "2.Osin " << endl;
		cout << "3.Zyma " << endl;
		cout << "4.Vesna " << endl;
		cout << "5.All " << endl;
		cin >> key;

		while (fin >> str.name)
		{
			if (!(key >= 1 && key <= 5)) { break; }
			fin >> str.lito;
			fin >> str.osin;
			fin >> str.zyma;
			fin >> str.vesna;

			if (key == 1)
			{
				if (str.lito > max.lito)
				{
					max = str;
				}
				if (str.lito < min.lito)
				{
					min = str;
				}
			}
			else if (key == 2)
			{
				if (str.osin > max.osin)
				{
					max = str;
				}
				if (str.osin < min.osin)
				{
					min = str;
				}
			}
			else if (key == 3)
			{
				if (str.zyma > max.zyma)
				{
					max = str;
				}
				if (str.zyma < min.zyma)
				{
					min = str;
				}
			}
			else if (key == 4)
			{
				if (str.vesna > max.vesna)
				{
					max = str;
				}
				if (str.vesna < min.vesna)
				{
					min = str;
				}
			}
			else if (key == 5)
			{
				if ((double)((str.lito + str.osin + str.zyma + str.vesna) / 4) > (double)((max.lito + max.osin + max.zyma + max.vesna) / 4))
				{
					max = str;
				}
				if ((double)((str.lito + str.osin + str.zyma + str.vesna) / 4) < (double)((min.lito + min.osin + min.zyma + min.vesna) / 4))
				{
					min = str;
				}
			}
		}

		if (key >= 1 && key <= 5) 
		{
			cout << "Min: " << min.name << (min.name.size() > 8 ? '\0' : '\t') <<'\t' << min.lito << '\t' << min.osin << '\t' << min.zyma << '\t' << min.vesna << endl;
			cout << "Max: " << max.name << (max.name.size() > 8 ? '\0' : '\t') <<'\t' << max.lito << '\t' << max.osin << '\t' << max.zyma << '\t' << max.vesna << endl << endl;
		}

	}
	else { cout << "error" << endl; }

	fin.close();
}

void MAXMIN(string file)
{
	ifstream fin;

	fin.open(file);

	countr str;

	long int maxtemp=0, mintemp=INT16_MAX;

	string maxseas, minseas, maxcountr, mincountr;

	if (fin)
	{
		while (fin >> str.name)
		{
			
			fin >> str.lito;
			fin >> str.osin;
			fin >> str.zyma;
			fin >> str.vesna;

			if (str.lito > maxtemp)
			{
				maxtemp = str.lito;
				maxseas = "lito";
				maxcountr = str.name;
			}
			if (str.osin > maxtemp)
			{
				maxtemp = str.osin;
				maxseas = "osin";
				maxcountr = str.name;
			}
			if (str.zyma > maxtemp)
			{
				maxtemp = str.zyma;
				maxseas = "zyma";
				maxcountr = str.name;
			}
			if (str.vesna > maxtemp)
			{
				maxtemp = str.vesna;
				maxseas = "vesna";
				maxcountr = str.name;
			}
			if (str.lito < mintemp)
			{
				mintemp = str.lito;
				minseas = "lito";
				mincountr = str.name;
			}
			if (str.osin < mintemp)
			{
				mintemp = str.osin;
				minseas = "osin";
				mincountr = str.name;
			}
			if (str.zyma < mintemp)
			{
				mintemp = str.zyma;
				minseas = "zyma";
				mincountr = str.name;
			}
			if (str.vesna < mintemp)
			{
				mintemp = str.vesna;
				minseas = "vesna";
				mincountr = str.name;
			}
				
		}

		cout <<"Min: "<< mincountr << (mincountr.size() > 8 ? '\0' : '\t') <<'\t' << minseas << '\t' << mintemp << endl;
		cout <<"Max: "<< maxcountr << (maxcountr.size() > 8 ? '\0' : '\t') <<'\t' << maxseas << '\t' << maxtemp << endl<<endl;


	}
	else { cout << "error" << endl; }

	fin.close();
}

void sortby(string file)
{
	ifstream fin;

	fin.open(file);

	countr str;

	deque<countr> sort;

	int key, key1;

	if (fin)
	{
		cout << "Choose order: " << endl;
		cout << "1.Up " << endl;
		cout << "2.Down " << endl;
		cin >> key1;

		cout << "Choose season: " << endl;
		cout << "1.Lito " << endl;
		cout << "2.Osin " << endl;
		cout << "3.Zyma " << endl;
		cout << "4.Vesna " << endl;
		cout << "5.All " << endl;
		cin >> key;

		while (fin >> str.name)
		{
			if (!(key1 >= 1 && key1 <= 2)) { break; }

			if (!(key >= 1 && key <= 5)) { break; }
			fin >> str.lito;
			fin >> str.osin;
			fin >> str.zyma;
			fin >> str.vesna;

			sort.push_back(str);			
		}

		countr temp;

		if (key == 1)
		{
			for (countr cur: sort)
			{
				for (int i = 0; i < sort.size()-1; i++) 
				{
					if (sort[i].lito > sort[i + 1].lito)
					{
						temp = sort[i];       
						sort[i] = sort[i + 1];  
						sort[i + 1] = temp;    
					}
				}
			}
		}
		else if (key == 2)
		{
			for (countr cur : sort)
			{
				for (int i = 0; i < sort.size()-1; i++)
				{
					if (sort[i].osin > sort[i + 1].osin)
					{
						temp = sort[i];
						sort[i] = sort[i + 1];
						sort[i + 1] = temp;
					}
				}
			}
		}
		else if (key == 3)
		{
			for (countr cur : sort)
			{
				for (int i = 0; i < sort.size()-1; i++)
				{
					if (sort[i].zyma > sort[i + 1].zyma)
					{
						temp = sort[i];
						sort[i] = sort[i + 1];
						sort[i + 1] = temp;
					}
				}
			}
		}
		else if (key == 4)
		{
			for (countr cur : sort)
			{
				for (int i = 0; i < sort.size()-1; i++)
				{
					if (sort[i].vesna > sort[i + 1].vesna)
					{
						temp = sort[i];
						sort[i] = sort[i + 1];
						sort[i + 1] = temp;
					}
				}
			}
		}
		else if (key == 5)
		{
			for (countr cur : sort)
			{
				for (int i = 0; i < sort.size()-1; i++)
				{
					if ((double)((sort[i].lito + sort[i].osin + sort[i].zyma + sort[i].vesna) / 4) > (double)((sort[i+1].lito + sort[i+1].osin + sort[i+1].zyma + sort[i+1].vesna) / 4))
					{
						temp = sort[i];
						sort[i] = sort[i + 1];
						sort[i + 1] = temp;
					}
				}
			}
		}

		if (key >= 1 && key <= 5)
		{
			if (key1 == 1) 
			{
				for (countr cur : sort)
				{
					cout << cur.name << (cur.name.size() > 8 ? '\0' : '\t') <<'\t' << cur.lito << '\t' << cur.osin << '\t' << cur.zyma << '\t' << cur.vesna << endl;
				}
			}
			else if (key1 == 2)
			{
				for (int k=sort.size()-1; k>=0;k--)
				{
					cout << sort[k].name << (sort[k].name.size() > 8 ? '\0' : '\t') <<'\t' << sort[k].lito << '\t' << sort[k].osin << '\t' << sort[k].zyma << '\t' << sort[k].vesna << endl;
				}
			}


		}

	}
	else { cout << "error" << endl; }
	cout << endl;
	fin.close();
}

void litoover30(string file)
{
	ifstream fin;

	fin.open(file);

	countr str;

	if (fin)
	{
		while (fin >> str.name)
		{
			fin >> str.lito;
			fin >> str.osin;
			fin >> str.zyma;
			fin >> str.vesna;
			
			if (str.lito > 30)
			{
				cout << str.name << (str.name.size() > 8 ? '\0' : '\t') << '\t' << str.lito <<endl;
			}
		}
	}
	else { cout << "error" << endl; }
	cout << endl;
	fin.close();
}

void zymaminus(string file)
{

	ifstream fin;

	fin.open(file);

	countr str;

	if (fin)
	{
		while (fin >> str.name)
		{
			fin >> str.lito;
			fin >> str.osin;
			fin >> str.zyma;
			fin >> str.vesna;

			if (str.zyma < 0)
			{
				cout << str.name << (str.name.size() > 8 ? '\0' :'\t' ) << '\t' << str.zyma << endl;
			}
		}
	}
	else { cout << "error" << endl; }
	cout << endl;
	fin.close();
}

void search(string file)
{
	ifstream fin;

	fin.open(file);

	countr str;

	string search;
	
	deque<countr> spys;
	
	if (fin)
	{
		while (fin >> str.name)
		{
			fin >> str.lito;
			fin >> str.osin;
			fin >> str.zyma;
			fin >> str.vesna;

			spys.push_back(str);
		}
		
		cout << "Input country: ";

		cin.ignore();
		getline(cin, search);

		int k = -1;
		bool flag = 0;

		for (int j=0;j< spys.size(); j++)
		{
			if (search.size() == spys[j].name.size())
			{
				for (int i = 0; i < search.size(); i++)
				{
					if (search[i] == spys[j].name[i]) { flag = 1; }
					else if (search[i] == spys[j].name[i] + 32) { flag = 1; }
					else if (search[i] == spys[j].name[i] - 32) { flag = 1; }
					else if (search[i] ==' '&& spys[j].name[i]=='_') { flag = 1; }
					else { flag = 0; break; }
				}
				
				if (flag)
				{
					k = j;
					break;
				}

			}
		}

		if (k != -1)
		{
			int max = ((spys[k].lito > spys[k].osin ? spys[k].lito : spys[k].osin) > (spys[k].zyma > spys[k].vesna ? spys[k].zyma : spys[k].vesna) ? (spys[k].lito > spys[k].osin ? spys[k].lito : spys[k].osin) : (spys[k].zyma > spys[k].vesna ? spys[k].zyma : spys[k].vesna));
			int min = ((spys[k].lito < spys[k].osin ? spys[k].lito : spys[k].osin) < (spys[k].zyma < spys[k].vesna ? spys[k].zyma : spys[k].vesna) ? (spys[k].lito < spys[k].osin ? spys[k].lito : spys[k].osin) : (spys[k].zyma < spys[k].vesna ? spys[k].zyma : spys[k].vesna));

			cout << "1) Max:\t\t" << max<<endl;
			cout << "2) Min:\t\t" << min<<endl;
			cout << "3) Avrg:\t" << (double)(spys[k].lito + spys[k].osin + spys[k].zyma + spys[k].vesna) / 4 << endl;
			cout << "4) Max-Min:\t" << max-min  << endl;
			
			int temp;
			cout << "   Input temperature: ";
			cin >> temp;

			cout << "5) Is higher: ";

			if (spys[k].lito > temp || spys[k].osin > temp || spys[k].zyma > temp || spys[k].vesna > temp) cout << "yes" << endl;
			else cout << "no" << endl;

			cout << "6) Is lower: ";

			if (spys[k].lito < temp || spys[k].osin < temp || spys[k].zyma < temp || spys[k].vesna < temp) cout << "yes" << endl;
			else cout << "no" << endl;

		}
		else
		{
			cout << "Not found." << endl;
		}
	}
	else { cout << "error" << endl; }
	cout << endl;
	fin.close();
}
