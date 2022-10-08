// Arguments.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
//

#include <iostream>
#include "Arguments.h"

int main(const int argv, const char* argc[])
{
    Arguments arg(nullptr);
    arg.registerCallback("-test", [=](const std::string& a_value, void* a_userData)
        {
            std::cout << "argument: "<< "-test" << std::endl;
            std::cout << "value: " << a_value << std::endl;
        });
    arg.registerCallback("-data", [=](const std::string& a_value, void* a_userData)
        {
            std::cout << "argument: " << "-data" << std::endl;
            std::cout << "value: " << a_value << std::endl;
        });
    arg.process(argv, argc);
    std::cout << "Hello World!\n";
    return 0;
}

// Ex�cuter le programme�: Ctrl+F5 ou menu D�boguer�> Ex�cuter sans d�bogage
// D�boguer le programme�: F5 ou menu D�boguer�> D�marrer le d�bogage

// Astuces pour bien d�marrer�: 
//   1. Utilisez la fen�tre Explorateur de solutions pour ajouter des fichiers et les g�rer.
//   2. Utilisez la fen�tre Team Explorer pour vous connecter au contr�le de code source.
//   3. Utilisez la fen�tre Sortie pour voir la sortie de la g�n�ration et d'autres messages.
//   4. Utilisez la fen�tre Liste d'erreurs pour voir les erreurs.
//   5. Acc�dez � Projet�> Ajouter un nouvel �l�ment pour cr�er des fichiers de code, ou � Projet�> Ajouter un �l�ment existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, acc�dez � Fichier�> Ouvrir�> Projet et s�lectionnez le fichier .sln.
