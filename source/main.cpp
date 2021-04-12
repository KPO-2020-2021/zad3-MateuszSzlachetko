#include "lacze_do_gnuplota.hh"
#include "Rectangle.h"
#include <chrono>
#include <thread>

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

    Matrix2x2 m(-1); // matrix for rotation (angle=1)
    Matrix2x2 m2(-3);

    Rectangle rectangle1(Vector2D(10, 8), Vector2D(15, 10));
    Rectangle rectangle2(Vector2D(-1, -1), Vector2D(-15, -10));

    rectangle1.Write_to_file("../data/vertex.xy", 1); // Make first output of created rectangle
    rectangle2.Write_to_file("../data/vertex.xy", 2);

    Lacze.Rysuj(); // draw created rectangle
    rectangle1.Side_length();
    int i = 0; // Number of rotations
    while (i < 36000000)
    {
        rectangle1.Rotation(m);
        rectangle2.Rotation(m2);

        if (rectangle1.Check_Collision(rectangle2))
        {
            std::cout << "hit" << std::endl;
            break;
        }
        rectangle1.Write_to_file("../data/vertex.xy", 1);
        rectangle2.Write_to_file("../data/vertex.xy", 2);

        std::this_thread::sleep_for(std::chrono::nanoseconds(100000000)); //0.1s 100000000
        Lacze.Rysuj();
        i++;
    }
    rectangle1.Side_length();

    std::cout << "Aby zakonczyc nacisnij ENTER ..." << std::flush;
    std::cin >> std::noskipws >> Opcja;
}
