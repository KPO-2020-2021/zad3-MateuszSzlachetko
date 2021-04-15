# Projekt 3 - Rotacje 2D

## Budowanie programu i testów

W celu zbudowania programu należy zainstalować program cmake,przejść do folderu build

```bash
			cd build
```

użyć komendy

```bash
			cmake ..
```

która wygeneruje Makefile'e dla folderu z testami i plikami źródłowymi programu.Jeżeli proces się powiódł wystarczy użyć z poziomu folderu komendy

```bash
			make
```

Która wykona kompilację dla całego programu i dołączonych testów

## Uruchamianie programu

Aby uruchomić program z poziomu folderu build należy użyć następującej komendy

```bash
			./Rotation2D_run
```

## Uruchamianie testów

Do uruchomienia testów z poziomu build należy przejść do folderu test

```bash
			cd test
```

i wywołać testy komendą

```bash
			./Rotation2D_tst
```

Jeżeli testy przebiegną pomyślnie program powinien zwrócić nastepujący komunikat.

```js
[----------] Global test environment tear-down
[==========] 25 tests from 16 test suites ran. (x ms total)
[  PASSED  ] 25 tests.
```

Powyższy ciąg komend można wywołać jednorazowo wklejając poniższą komendę do terminala

```bash
			cd build && cmake .. && make && cd test && ./Rotation2D_tst && cd .. && ./Rotation2D_run
```

W razie problemów proszę o kontakt <259370@student.pwr.edu.pl>

# Rozszerzenia

W programie zastosowałem oba rozszerzenia,animacje obrotów prostokąta z komunikatem o przybliżonym czasie potrzebnym do wykonania animacji,oraz wykrywanie kolizji z wykorzystaniem SAT ([link do poradnika](https://www.gamedev.net/tutorials/_/technical/game-programming/2d-rotated-rectangle-collision-r2604/)).

Implementacja wartości dla wierzchołków prostokątów ,oraz wizualizacja kolizji jest zaimplementowana z góry w funkcji main.Jednak można ją dowolnie zmodyfikować,podążając już za aktualną strukturą "menu".

# Struktura repozytorium

&nbsp;&nbsp; [source](source/) - folder z plikami źródłowymi\
&nbsp;&nbsp; ├── [main.cpp](source/main.cpp) - główny plik main programu\
&nbsp;&nbsp; ├── [Rectangle.cpp](source/Rectangle.cpp) - plik źródłowy dla klasy reprezentującej prostokąt\
&nbsp;&nbsp; ├── [Vector2D.cpp](source/Vector2D.cpp) - plik źródłowy dla klasy Wektora 2D\
&nbsp;&nbsp; └── [Matrix2x2.cpp](source/Matrix2x2.cpp) - plik źródłowy dla klasy Macierz 2x2

&nbsp;&nbsp; [include](include/) - folder z plikami nagłówkowymi\
&nbsp;&nbsp; ├── [Rectangle.h](include/Rectangle.h) - plik nagłówkowy dla klasy reprezentującej prostokąt\
&nbsp;&nbsp; ├── [Vector2D.h](include/Vector2D.h) - plik nagłówkowy klasy Wektora 2D\
&nbsp;&nbsp; └── [Matrix2x2.h](include/Matrix2x2.h) - plik nagłówkowy dla klasy Macierz 2x2

&nbsp;&nbsp; [test](test/) - zawiera pliki źródłowe testów\
&nbsp;&nbsp; ├── [CMakeLists.txt](test/CMakeLists.txt) - cmake generujący makefile dla programu Rotation2D_tst\
&nbsp;&nbsp; ├── [Matrix2x2-test.cpp](test/Matrix2x2-test.cpp)\
&nbsp;&nbsp; ├── [Rectangle-test.cpp](test/Rectangle-test.cpp)\
&nbsp;&nbsp; ├── [Vector2d-test.cpp](test/Vector2d-test.cpp)\
&nbsp;&nbsp; └── [main.cpp](test/main.cpp) - plik main dla programu Rotation2D_tst

&nbsp;&nbsp; [lib](lib/) - zawiera biblioteke googletest i łącze do GNUPlota\
&nbsp;&nbsp; ├── [GNUPlot](lib/GNUPlot/) - folder z plikami do obsługi GNUPlota\
&nbsp;&nbsp; └── [googletest](lib/googletest) - folder z biblioteką googletest

&nbsp;&nbsp; [build](build/) 

&nbsp;&nbsp; [documentation](documentation/) - dokumentacja i przygotowanie\
&nbsp;&nbsp; [CMakeLists.txt](CMakeLists.txt) - cmake generujący makefile dla programu Rotation2D_run
