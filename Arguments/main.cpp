// Arguments.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
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

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
