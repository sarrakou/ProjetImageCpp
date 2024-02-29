// ProjetImageC++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "Image.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;

void additionAvecUnValeur(Image img) {
    // Exemple d'addition avec une valeur
    Image imgAddedValue = img + 50; // Augmente la luminosité
    // Sauvegarde de l'image après addition
    if (!imgAddedValue.saveImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/result_added_value.jpg", "jpg")) {
        std::cerr << "Failed to save image with added value" << std::endl;
    }
    fs::path rutaCarpeta = "C:\\Users\\adria\\OneDrive\\Documentos\\ESGI\\C++\\images\\result_added_value.jpg";
    system(("start explorer \"" + rutaCarpeta.string() + "\"").c_str());
}
void additionAvecUnPixel(Image img) {
    // Exemple d'addition avec une valeur
    std::vector<unsigned char> addPixel(3, 30);
    Image imgAddedPixel = img + addPixel; // Augmente la luminosité
    // Sauvegarde de l'image après addition
    if (!imgAddedPixel.saveImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/result_added_pixel.jpg", "jpg")) {
        std::cerr << "Failed to save image with added value" << std::endl;
    }
    fs::path rutaCarpeta = "C:\\Users\\adria\\OneDrive\\Documentos\\ESGI\\C++\\images\\result_added_pixel.jpg";
    system(("start explorer \"" + rutaCarpeta.string() + "\"").c_str());
}
void soustractionAvecUnValeur(Image img) {
    // Exemple de soustraction avec un pixel// Soustrait une petite valeur de chaque canal RGB
    Image imgSubtractedValeur = img - 50;

    // Sauvegarde de l'image après soustraction
    if (!imgSubtractedValeur.saveImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/result_subtracted_value.jpg", "jpg")) {
        std::cerr << "Failed to save image with subtracted pixel" << std::endl;
    }

    fs::path rutaCarpeta = "C:\\Users\\adria\\OneDrive\\Documentos\\ESGI\\C++\\images\\result_subtracted_value.jpg";
    system(("start explorer \"" + rutaCarpeta.string() + "\"").c_str());
}
void soustractionPixel(Image img) {
    // Exemple de soustraction avec un pixel
    std::vector<unsigned char> subtractPixel(3, 30); // Soustrait une petite valeur de chaque canal RGB
    Image imgSubtractedPixel = img - subtractPixel;

    // Sauvegarde de l'image après soustraction
    if (!imgSubtractedPixel.saveImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/result_subtracted_pixel.jpg", "jpg")) {
        std::cerr << "Failed to save image with subtracted pixel" << std::endl;
    }
    fs::path rutaCarpeta = "C:\\Users\\adria\\OneDrive\\Documentos\\ESGI\\C++\\images\\result_subtracted_pixel.jpg";
    system(("start explorer \"" + rutaCarpeta.string() + "\"").c_str());
}
void differenceAvecUnValeur(Image img) {
    // Exemple de soustraction avec un pixel// Soustrait une petite valeur de chaque canal RGB
    Image imgdifferenceValeur = img ^ 50;

    // Sauvegarde de l'image après soustraction
    if (!imgdifferenceValeur.saveImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/result_difference_value.jpg", "jpg")) {
        std::cerr << "Failed to save image with subtracted pixel" << std::endl;
    }

    fs::path rutaCarpeta = "C:\\Users\\adria\\OneDrive\\Documentos\\ESGI\\C++\\images\\result_difference_value.jpg";
    system(("start explorer \"" + rutaCarpeta.string() + "\"").c_str());
}
void differencePixel(Image img) {
    // Exemple de soustraction avec un pixel
    std::vector<unsigned char> differencePixel(3, 30); // Soustrait une petite valeur de chaque canal RGB
    Image imgDifferencedPixel = img ^ differencePixel;

    // Sauvegarde de l'image après soustraction
    if (!imgDifferencedPixel.saveImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/result_difference_pixel.jpg", "jpg")) {
        std::cerr << "Failed to save image with subtracted pixel" << std::endl;
    }
    fs::path rutaCarpeta = "C:\\Users\\adria\\OneDrive\\Documentos\\ESGI\\C++\\images\\result_difference_pixel.jpg";
    system(("start explorer \"" + rutaCarpeta.string() + "\"").c_str());
}
void multiplicationValeur(Image img) {
    // Exemple d'inversion des valeurs de l'image
    Image imgMult = img * 20;

    // Sauvegarde de l'image après inversion
    if (!imgMult.saveImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/result_mult.jpg", "jpg")) {
        std::cerr << "Failed to save inverted image" << std::endl;
    }
    fs::path rutaCarpeta = "C:\\Users\\adria\\OneDrive\\Documentos\\ESGI\\C++\\images\\result_mult.jpg";
    system(("start explorer \"" + rutaCarpeta.string() + "\"").c_str());

}
void divisionValeur(Image img) {
    // Exemple d'inversion des valeurs de l'image
    Image imgDiv = img / 20;

    // Sauvegarde de l'image après inversion
    if (!imgDiv.saveImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/result_div.jpg", "jpg")) {
        std::cerr << "Failed to save inverted image" << std::endl;
    }
    fs::path rutaCarpeta = "C:\\Users\\adria\\OneDrive\\Documentos\\ESGI\\C++\\images\\result_div.jpg";
    system(("start explorer \"" + rutaCarpeta.string() + "\"").c_str());
}
void inversionDesValeur(Image img) {
    // Exemple d'inversion des valeurs de l'image
    Image imgInverted = ~img;

    // Sauvegarde de l'image après inversion
    if (!imgInverted.saveImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/result_inverted.jpg", "jpg")) {
        std::cerr << "Failed to save inverted image" << std::endl;
    }
    fs::path rutaCarpeta = "C:\\Users\\adria\\OneDrive\\Documentos\\ESGI\\C++\\images\\result_inverted.jpg";
    system(("start explorer \"" + rutaCarpeta.string() + "\"").c_str());
}
void addition2Images(Image img1, Image img2) {

    // Realizar operaciones de suma y resta
    Image suma = img1 + img2; // Suma de imágenes

    // Sauvegarde de l'image après inversion
    if (!suma.saveImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/result_addition_images.jpg", "jpg")) {
        std::cerr << "Failed to save inverted image" << std::endl;
    }
    fs::path rutaCarpeta = "C:\\Users\\adria\\OneDrive\\Documentos\\ESGI\\C++\\images\\result_addition_images.jpg";
    system(("start explorer \"" + rutaCarpeta.string() + "\"").c_str());
}
void soustraction2Images(Image img1, Image img2) {

    // Realizar operaciones de suma y resta
    Image suma = img1 - img2; // Suma de imágenes

    // Sauvegarde de l'image après inversion
    if (!suma.saveImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/result_soustraction_images.jpg", "jpg")) {
        std::cerr << "Failed to save inverted image" << std::endl;
    }
    fs::path rutaCarpeta = "C:\\Users\\adria\\OneDrive\\Documentos\\ESGI\\C++\\images\\result_soustraction_images.jpg";
    system(("start explorer \"" + rutaCarpeta.string() + "\"").c_str());
}
void difference2Images(Image img1, Image img2) {

    // Realizar la diferencia entre las imágenes
    Image diferencia = img1 ^ img2;

    // Sauvegarde de l'image après inversion
    if (!diferencia.saveImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/result_diferencia_images.jpg", "jpg")) {
        std::cerr << "Failed to save inverted image" << std::endl;
    }
    fs::path rutaCarpeta = "C:\\Users\\adria\\OneDrive\\Documentos\\ESGI\\C++\\images\\result_diferencia_images.jpg";
    system(("start explorer \"" + rutaCarpeta.string() + "\"").c_str());
}

std::string convertirRuta(const std::string& ruta) {
    std::string rutaConvertida = ruta;
    std::replace(rutaConvertida.begin(), rutaConvertida.end(), '/', '\\');
    return rutaConvertida;
}
int main()
{
    Image img;
    Image img2;
    int op=-1;  
   /* // Mostrar el cuadro de diálogo del explorador de archivos
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
    }*/

    // Chargement d'une image
    if (!img.loadImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/lobo.jpg")) {
        std::cerr << "Failed to load image" << std::endl;
    }
    if (!img2.loadImage("C:/Users/adria/OneDrive/Documentos/ESGI/C++/images/paisaje.jpg")) {
        std::cerr << "Failed to load image" << std::endl;
    }

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
        std::cout << "8. Difference avec un valeur." << std::endl;
        std::cout << "9. Difference avec un pixel." << std::endl;
        std::cout << "10. Addition 2 images. " << std::endl;
        std::cout << "11. Soustraction 2 images. " << std::endl;
        std::cout << "12. Difference 2 images. " << std::endl;
        std::cin >> op;
        switch (op) {
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
        case 8:
            differenceAvecUnValeur(img);
            break;
        case 9:
            differencePixel(img);
            break;
        case 10:
            addition2Images(img, img2);
            break;
        case 11:
            soustraction2Images(img, img2);
            break;
        case 12:
            difference2Images(img, img2);
            break;
        case 13:
            soustraction2Images(img, img2);
            break;
        }
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
