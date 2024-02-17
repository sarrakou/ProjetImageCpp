// ProjetImageC++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "Image.h"
#include <iostream>

int main()
{
    Image img;

    // Chargement d'une image
    if (!img.loadImage("C:/Users/sarra/source/repos/ProjetImageC++/x64/Release/free-nature-images.jpg")) {
        std::cerr << "Failed to load image" << std::endl;
        return 1;
    }

    // Affichage des propriétés de l'image chargée
    std::cout << "Loaded image with dimensions: " << img.getWidth() << "x" << img.getHeight()
        << " and channels: " << img.getChannels() << std::endl;

    // Exemple d'addition avec une valeur
    Image imgAddedValue = img + 50; // Augmente la luminosité

    // Sauvegarde de l'image après addition
    if (!imgAddedValue.saveImage("C:/Users/sarra/source/repos/ProjetImageC++/x64/Release/result_added_value.jpg", "jpg")) {
        std::cerr << "Failed to save image with added value" << std::endl;
    }

    // Exemple de soustraction avec un pixel
    std::vector<unsigned char> subtractPixel(3, 30); // Soustrait une petite valeur de chaque canal RGB
    Image imgSubtractedPixel = img - subtractPixel;

    // Sauvegarde de l'image après soustraction
    if (!imgSubtractedPixel.saveImage("C:/Users/sarra/source/repos/ProjetImageC++/x64/Release/result_subtracted_pixel.jpg", "jpg")) {
        std::cerr << "Failed to save image with subtracted pixel" << std::endl;
    }

    // Exemple d'inversion des valeurs de l'image
    Image imgInverted = ~img;

    // Sauvegarde de l'image après inversion
    if (!imgInverted.saveImage("C:/Users/sarra/source/repos/ProjetImageC++/x64/Release/result_inverted.jpg", "jpg")) {
        std::cerr << "Failed to save inverted image" << std::endl;
    }

    // Ajout d'un commentaire pour indiquer la réussite de toutes les opérations
    std::cout << "All operations completed successfully." << std::endl;

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
