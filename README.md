# Testowanie funkcji `cmath` w C++ z użyciem Google Test

## 📌 Opis projektu

Projekt ten zawiera zestaw testów jednostkowych dla funkcji matematycznych zawartych w standardowej bibliotece C++ `cmath`. Testy zostały napisane przy użyciu frameworka **Google Test**, który jest powszechnie stosowany do testowania kodu w języku C++.
Dane testowe (wartości liczbowe) zostały wygenerowane za pomocą `ChatGTP`.

## ⚙️ Kompilacja i uruchomienie

Aby skompilować projekt i uruchomić testy, użyj poniższych poleceń:

```bash
g++ cmath_test.cpp -lgtest -lgtest_main -pthread -o cmath_test
./cmath_test
```

## 🧪 Lista przetestowanych funkcji

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

## ⚙️ Działanie kodu
Kod testowy został napisany z użyciem frameworka Google Test. Struktura testu wygląda następująco:

```bash
TEST(CMathTest, AbsValue) {
    EXPECT_EQ(std::abs(-5), 5);
    EXPECT_EQ(std::abs(0), 0);
    EXPECT_EQ(std::abs(3), 3);
}
```

### Poniżej znajdziesz wyjaśnienie każdego elementu:

TEST(...) – makro z Google Test, które definiuje nowy przypadek testowy.

Pierwszy argument (CMathTest) to nazwa grupy testowej – służy do logicznego pogrupowania testów.

Drugi argument (AbsValue) to nazwa konkretnego testu w ramach tej grupy.

EXPECT_EQ(val1, val2) – sprawdza, czy val1 i val2 są sobie równe. Używane głównie do wartości całkowitych i dokładnych porównań.

EXPECT_NEAR(val1, val2, tolerance) – sprawdza, czy val1 i val2 są blisko siebie w ramach określonej tolerancji (np. 0.0001). Używane przy porównywaniu liczb zmiennoprzecinkowych, gdzie występują drobne błędy zaokrągleń.

std::abs – funkcja z biblioteki standardowej C++ (cmath), oblicza wartość bezwzględną liczby.

std:: – przestrzeń nazw standardowej biblioteki C++. Wszystkie funkcje z cmath (np. std::sin, std::log, std::pow) są w tej przestrzeni nazw.
