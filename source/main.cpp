#include "lacze_do_gnuplota.hh"
#include "Rectangle.h"
#include <chrono>
#include <thread>
void Display_menu()
{
    std::cout << "\n r-rotate rectangle" << std::endl;
    std::cout << " t-translate rectangle" << std::endl;
    std::cout << " d-display rectangle" << std::endl;
    std::cout << " m-show menu" << std::endl;
    std::cout << " c-test collision" << std::endl;
    std::cout << " q-quit" << std::endl;
}

int main()
{

    char Opcja;
    PzG::LaczeDoGNUPlota Lacze;
    Lacze.DodajNazwePliku("../data/vertex.xy")
        .ZmienSposobRys(PzG::SR_Ciagly)
        .ZmienSzerokosc(6);
    Lacze.DodajNazwePliku("../data/vertex.xy")
        .ZmienSposobRys(PzG::SR_Punktowy)
        .ZmienSzerokosc(2);
    Lacze.Inicjalizuj(); // Tutaj startuje gnuplot.
    Lacze.ZmienTrybRys(PzG::TR_2D);
    Lacze.UstawZakresY(-30, 30);
    Lacze.UstawZakresX(-30, 30);

    char option = ' ';
    double angle = 0;
    int rotations = 0, i = 0;
    Matrix2x2 r_matrix, r_matrix_collision;
    Vector2D translation_vector;
    Rectangle rectangle1(Vector2D(0, 0), Vector2D(10, 10));
    Rectangle rectangle2(Vector2D(-2, -2), Vector2D(-15, -15)); // second rec for collision check
    Rectangle temp = rectangle1;                                // to reset the file with default value of rec1
    Lacze.Rysuj();
    Display_menu();

    do
    {
        std::cout << "Choice (m-menu):\t";
        std::cin >> option;

        if (option != 'r' && option != 't' && option != 'd' && option != 'm' && option != 'q' && option != 'c')
        {
            std::cerr << "[ERROR] Invalid menu argument" << std::endl;
            option = ' ';
        }

        switch (option)
        {
        case 'm':
            Display_menu();
            break;
        case 'd':
            std::cout << rectangle1 << std::endl;
            break;
        case 't':
            std::cout << "Enter translation vector \" x y \" " << std::endl;
            std::cin >> translation_vector;
            rectangle1.Translate(translation_vector);
            Lacze.Rysuj();
            break;
        case 'r':
            std::cout << "Enter the degrees for rotation matrix" << std::endl;
            std::cin >> angle;
            r_matrix = Matrix2x2(angle);
            std::cout << "Enter the number of rotations" << std::endl;
            std::cin >> rotations;
            std::cout << "Do you want to animate it? [Y/n]" << std::endl;
            std::cout << "Approximate time of animation: [" << rotations / 30 << "s]" << std::endl;
            std::cin >> option;
            if (option != 'Y' && option != 'n')
            {
                std::cerr << "[ERROR] Invalid decision" << std::endl;
                break;
            }
            if (option == 'Y') // for faster computing check statement outside of the loop
            {
                while (i < rotations)
                {
                    rectangle1.Rotation(r_matrix);
                    rectangle1.Write_to_file("../data/vertex.xy", 1);
                    std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000 / 30)); //1s -> 1000000000  divide (How much FPS we want)
                    Lacze.Rysuj();
                    i++;
                }
            }
            else
            {
                while (i < rotations)
                {
                    rectangle1.Rotation(r_matrix);
                    i++;
                }
                rectangle1.Write_to_file("../data/vertex.xy", 1);
                Lacze.Rysuj();
            }
            rectangle1.Side_length();
            i = 0;
            break;
        case 'c':
            std::cout << "Enter the degrees for rotation matrix" << std::endl;
            std::cin >> angle;
            r_matrix = Matrix2x2(angle);
            std::cout << "Enter the degrees for the second matrix" << std::endl;
            std::cin >> angle;
            r_matrix_collision = Matrix2x2(angle);
            rotations = 720;
            while (i < rotations)
            {
                rectangle1.Rotation(r_matrix);
                rectangle2.Rotation(r_matrix_collision);
                rectangle1.Write_to_file("../data/vertex.xy", 1);
                rectangle2.Write_to_file("../data/vertex.xy", 2);
                if (rectangle1.Check_Collision(rectangle2))
                {
                    std::cout << "hit[" << i << ']' << std::endl;
                }
                std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000 / 30)); //1s -> 1000000000  divide (How much FPS we want)
                Lacze.Rysuj();
                i++;
            }
            i = 0;
            break;
        default:
            break;
        }
    } while (option != 'q');

    temp.Write_to_file("../data/vertex.xy", 1); // reset the file
}
