// ProjetImageC++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "Image.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <filesystem>
namespace fs = std::filesystem;

int ChargeImage() {
    // Solicitar al usuario que seleccione un archivo
    std::string nombreArchivo;
    std::cout << "Por favor, introduce la ruta del archivo: ";
    std::cin >> nombreArchivo;

    // Verificar si el archivo existe
    fs::path rutaArchivo(nombreArchivo);
    if (fs::exists(rutaArchivo) && fs::is_regular_file(rutaArchivo)) {
        std::cout << "El archivo seleccionado existe: " << rutaArchivo << std::endl;
    }
    else {
        std::cerr << "El archivo especificado no existe o no es un archivo regular." << std::endl;
    }
    return 0;
}
void additionAvecUnValeur(Image img) {
    // Exemple d'addition avec une valeur
    Image imgAddedValue = img + 50; // Augmente la luminosité
    // Sauvegarde de l'image après addition
    if (!imgAddedValue.saveImage("D:/Adriana/ESGI/Cursos/C++/projet final/Imagenes/Salida/result_added_value.jpg", "jpg")) {
        std::cerr << "Failed to save image with added value" << std::endl;
    }
}
void additionAvecUnPixel(Image img) {
    // Exemple d'addition avec une valeur
    std::vector<unsigned char> addPixel(3, 30);
    Image imgAddedPixel = img + addPixel; // Augmente la luminosité
    // Sauvegarde de l'image après addition
    if (!imgAddedPixel.saveImage("D:/Adriana/ESGI/Cursos/C++/projet final/Imagenes/Salida/result_added_pixel.jpg", "jpg")) {
        std::cerr << "Failed to save image with added value" << std::endl;
    }
}
void soustractionAvecUnValeur(Image img) {
    // Exemple de soustraction avec un pixel// Soustrait une petite valeur de chaque canal RGB
    Image imgSubtractedValeur = img - 50;

    // Sauvegarde de l'image après soustraction
    if (!imgSubtractedValeur.saveImage("D:/Adriana/ESGI/Cursos/C++/projet final/Imagenes/Salida/result_subtracted_value.jpg", "jpg")) {
        std::cerr << "Failed to save image with subtracted pixel" << std::endl;
    }
}
void soustractionPixel(Image img) {
    // Exemple de soustraction avec un pixel
    std::vector<unsigned char> subtractPixel(3, 30); // Soustrait une petite valeur de chaque canal RGB
    Image imgSubtractedPixel = img - subtractPixel;

    // Sauvegarde de l'image après soustraction
    if (!imgSubtractedPixel.saveImage("D:/Adriana/ESGI/Cursos/C++/projet final/Imagenes/Salida/result_subtracted_pixel.jpg", "jpg")) {
        std::cerr << "Failed to save image with subtracted pixel" << std::endl;
    }
}
void multiplicationValeur(Image img) {
    // Exemple d'inversion des valeurs de l'image
    Image imgMult = img * 20;

    // Sauvegarde de l'image après inversion
    if (!imgMult.saveImage("D:/Adriana/ESGI/Cursos/C++/projet final/Imagenes/Salida/result_mult.jpg", "jpg")) {
        std::cerr << "Failed to save inverted image" << std::endl;
    }
}
void divisionValeur(Image img) {
    // Exemple d'inversion des valeurs de l'image
    Image imgDiv = img / 20;

    // Sauvegarde de l'image après inversion
    if (!imgDiv.saveImage("D:/Adriana/ESGI/Cursos/C++/projet final/Imagenes/Salida/result_div.jpg", "jpg")) {
        std::cerr << "Failed to save inverted image" << std::endl;
    }
}
void inversionDesValeur(Image img) {
    // Exemple d'inversion des valeurs de l'image
    Image imgInverted = ~img;

    // Sauvegarde de l'image après inversion
    if (!imgInverted.saveImage("D:/Adriana/ESGI/Cursos/C++/projet final/Imagenes/Salida/result_inverted.jpg", "jpg")) {
        std::cerr << "Failed to save inverted image" << std::endl;
    }
}
std::string convertirRuta(const std::string& ruta) {
    std::string rutaConvertida = ruta;
    std::replace(rutaConvertida.begin(), rutaConvertida.end(), '/', '\\');
    return rutaConvertida;
}
int main()
{
    Image img;
    int op=-1;  
    // Mostrar el cuadro de diálogo del explorador de archivos
    std::cout << "Por favor, selecciona una imagen." << std::endl;
    system("explorer /select, \"%UserProfile%\\Pictures\"");

    
    /// Solicitar al usuario que seleccione un archivo
    std::string nombreArchivo;
    std::cout << "Por favor, introduce la ruta del archivo: ";
    std::cin >> nombreArchivo;

    std::string rutaConvertida = convertirRuta(nombreArchivo);
    cout << rutaConvertida;
    // Verificar si el archivo existe
    fs::path rutaArchivo(rutaConvertida);
    if (fs::exists(rutaArchivo) && fs::is_regular_file(rutaArchivo)) {
        std::cout << "El archivo seleccionado existe: " << rutaArchivo << std::endl;

        // Cargar la imagen utilizando la ruta proporcionada por el usuario
        if (!img.loadImage(rutaConvertida)) {
            std::cerr << "Failed to load image" << std::endl;
        }
    }
    else {
        std::cerr << "El archivo especificado no existe o no es un archivo regular." << std::endl;
    }
    //// Chargement d'une image
    //if (!img.loadImage("D:/Adriana/ESGI/Cursos/C++/projet final/Imagenes/original/lobo.jpg")) {
    //    std::cerr << "Failed to load image" << std::endl;
    //}

    // Affichage des propriétés de l'image chargée
    std::cout << "Loaded image with dimensions: " << img.getWidth() << "x" << img.getHeight()
        << " and channels: " << img.getChannels() << std::endl;
    while (op!=8)
    {
        system("cls");
        std::cout << "Seleccione un option: "<< std::endl;
        std::cout << "1. Addition avec une valeur. "<< std::endl;
        std::cout << "2. Addition avec une pixel. "<< std::endl;
        std::cout << "3. Soustraction avec une valeur. " << std::endl;
        std::cout << "4. Soustraction avec une pixel. " << std::endl;
        std::cout << "5. Multiplication avec une valeur. " << std::endl;
        std::cout << "6. Division avec une valeur. " << std::endl;
        std::cout << "7. Inversement. " << std::endl;
        std::cin >> op;
        switch (op) {
        case 0:
            ChargeImage();
            break;
        case 1:
            additionAvecUnValeur(img);
            break;
        case 2:
            additionAvecUnPixel(img);
            break;
        case 3:
            soustractionAvecUnValeur(img);
            break;
        case 4:
            soustractionPixel(img);
            break;
        case 5:
            multiplicationValeur(img);
            break;
        case 6:
            divisionValeur(img);
            break;
        case 7:
            inversionDesValeur(img);
            break;


        }
        
        fs::path rutaCarpeta = "D:\\Adriana\\ESGI\\Cursos\\C++\\projet final\\Imagenes\\Salida\\result_added_value.jpg";
        system(("start explorer \"" + rutaCarpeta.string() + "\"").c_str());
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
