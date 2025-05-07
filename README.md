# Testowanie funkcji `cmath` w C++ z użyciem Google Test

## Opis projektu

Projekt zawiera zestaw testów dla funkcji matematycznych zawartych w bibliotece C++ `cmath`. Testy zostały napisane przy użyciu frameworka **Google Test**.Dane testowe (wartości liczbowe) zostały wygenerowane za pomocą `ChatGTP`. 
<br><br>
Testowanie nie objęło pełnego pokrycia rozgałęzień i instrukcji dla wszystkich funkcji dostępnych w bibliotece cmath. Ponieważ nie miałem odpowiednich danych do testowania niektórych bardziej zawansowanych funkcji.

## Kompilacja i uruchomienie

Aby skompilować projekt i uruchomić testy należy uzyć poniższych poleceń w systemie operacyjnym linux:

```bash
g++ cmath_test.cpp -lgtest -lgtest_main -pthread -o cmath_test
./cmath_test
```

## Lista przetestowanych funkcji

<details>
<summary> Funkcje trygonometryczne</summary>

- `std::sin` – sinus  
- `std::cos` – cosinus  
- `std::tan` – tangens  
- `std::asin` – arcsinus  
- `std::acos` – arccosinus  
- `std::atan` – arctangens  
- `std::atan2` – arctangens dwóch zmiennych (kąt z prostokątnych współrzędnych)  
</details>

<details>
<summary> Funkcje wykładnicze i logarytmiczne</summary>

- `std::exp` – funkcja wykładnicza `e^x`  
- `std::exp2` – `2^x`  
- `std::expm1` – `e^x - 1`  
- `std::log` – logarytm naturalny  
- `std::log10` – logarytm dziesiętny  
- `std::log2` – logarytm binarny  
- `std::log1p` – `log(1 + x)`  
- `std::pow` – potęgowanie `x^y`  
</details>

<details>
<summary> Funkcje pierwiastkowe</summary>

- `std::sqrt` – pierwiastek kwadratowy  
- `std::cbrt` – pierwiastek sześcienny  
</details>

<details>
<summary> Funkcje zaokrąglające</summary>

- `std::ceil` – zaokrąglenie w górę  
- `std::floor` – zaokrąglenie w dół  
- `std::round` – zaokrąglenie do najbliższej liczby całkowitej  
- `std::trunc` – obcięcie części ułamkowej  
- `std::llround` – zaokrąglenie z wynikiem typu `long long`  
</details>

<details>
<summary> Funkcje pomocnicze i operacje na liczbach</summary>

- `std::abs` – wartość bezwzględna (dla `int`)  
- `std::fabs` – wartość bezwzględna (dla `double`)  
- `std::copysign` – kopiowanie znaku z jednej liczby na drugą  
- `std::fdim` – dodatnia różnica `max(x - y, 0)`  
- `std::fmod` – reszta z dzielenia zmiennoprzecinkowego  
- `std::fma` – mnożenie i dodawanie bez utraty precyzji (`x*y + z`)  
- `std::fmin` / `std::fmax` – minimum / maksimum dwóch liczb  
</details>

<details>
<summary> Funkcje specjalne i inne</summary>

- `std::frexp` – rozkład liczby na mantysę i wykładnik (`m * 2^exp`)  
- `std::ldexp` – odwrotność `frexp`, czyli `m * 2^exp`  
- `std::ilogb` – całkowity wykładnik binarny (`log2`)  
- `std::hypot` – obliczanie długości przeciwprostokątnej (pitagoras)  
- `std::erf` / `std::erfc` – funkcja błędu i jej dopełnienie  
</details>

## Działanie kodu
- Ponżej znajduje się struktura kodu liczenia czasu:
```bash
void Nanosec(std::string name, void(*fn)()) {
    auto a = std::chrono::high_resolution_clock::now();
    fn();
    auto b = std::chrono::high_resolution_clock::now();
    auto t = std::chrono::duration_cast<std::chrono::nanoseconds>(b - a).count();
    std::cout << name << " time:" << t << "ns" << std::endl;
}
```
<details>
<summary> Działanie poszczególnych elementów:</summary>

- `std::string name` – placeholder na tekst.
  
- `void(*fn)()` -  wskaźnik na funkcję.
  
- `std::chrono::high_resolution_clock::now()` - wywołuje funkcje now() zwraca aktualny czas.
  
- `fn();` - wywołanie funkcji przekazanej jako wskaźnik.
  
- `std::chrono::duration_cast<std::chrono::nanoseconds>` - przerzucenie na nanosekundy.
  
- `(b - a)` – różnica czasu trwania wykonania funkcji.
  
- `std::cout << name << " time:" << t << "ns" << std::endl;` - wypisanie danych.

</details>

- Ponżej znajduje się struktura kodu testu:

```bash
void testAbsValue() {
    EXPECT_EQ(std::abs(-5.2), 5.2);
    EXPECT_EQ(std::abs(0), 0);
    EXPECT_EQ(std::abs(-3.2), 3.2);
}
TEST(CMathTest, AbsValue) {
    Nanosec("AbsValue: ",testAbsValue);
}
```

<details>
<summary> Działanie poszczególnych elementów:</summary>

- `TEST(...)` – to funkcja z Google Test, które tworzy nowy test.

- `CMathTest` – to nazwa grupy testów, która pomaga pogrupować kilka testów razem (coś jak grupa).

- `AbsValue` – to nazwa konkretnego testu w tej grupie.

- `EXPECT_EQ(val1, val2)` – sprawdza, czy dwie wartości są równe. Idealne do porównań np. liczb całkowitych.

- `EXPECT_NEAR(val1, val2, tolerance)` – sprawdza, czy dwie liczby zmiennoprzecinkowe są prawie równe, z uwzględnieniem małego marginesu błędu (np. 0.0001).

- `std::abs` – funkcja z biblioteki C++, która zwraca wartość bezwzględną liczby.

- `std::` – oznaczenie, że używamy coś z biblioteki standardowej C++.
  
-  `Nanosec("AbsValue: ",testAbsValue);` - wywołanie funkcji.

</details>
