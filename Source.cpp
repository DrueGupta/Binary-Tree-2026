#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;

int main()
{
	Tree<string>horror;
	horror.insert("Jason Vorhess");
	horror.insert("Freddy Kruger");
	horror.insert("Leatherface");
	horror.insert("Pennywise");
	horror.insert("Ghostface");
	horror.insert("Chucky");
	horror.insert("Micheal Myers");
	horror.insert("William Afton");
	horror.insert("Jigsaw");
	horror.print();
}
