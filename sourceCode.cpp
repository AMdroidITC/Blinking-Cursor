#include "pch.h"
#include <iostream>
#include <conio.h>
#include <string>
#include<Windows.h>
#include<chrono>
#include<thread>
using namespace std;

string args = "";
string newline = ">";
bool *state;

void foo(bool &c)
{
	try
	{
		while (c)
		{
			cout << newline << " " << args;
			Sleep(300);
			system("CLS");
			cout << "  " << args;
			this_thread::sleep_for(chrono::milliseconds(500));
			system("CLS");
			

		}
		string err = "";
		throw err;
	}
	catch (string exit)
	{
		cout << exit;
	}


}


int main()
{
	
	
		char ch;
		string *all=new string[10];
		int	i = 0;
		bool c = true;
		thread th(foo, ref(c));
		th.detach();
		while (true) {
			ch = _getch();
			if (ch != '\r') {
				args += ch;
			}
			else {
				system("CLS");
				if (args == "e")
				{

					c = false;
					system("CLS");
					this_thread::sleep_for(chrono::milliseconds(600));
					cout << "EXIT";
					this_thread::sleep_for(chrono::milliseconds(600));
					break;
				}
				else
				{
					all[i] = args;
					i++;
					args = "";
					this_thread::sleep_for(chrono::milliseconds(100));
				}
			}
		}
	
}