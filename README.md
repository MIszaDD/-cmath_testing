# Testowanie funkcji `cmath` w C++ z użyciem Google Test

## 📌 Opis projektu

Projekt ten zawiera zestaw testów jednostkowych dla funkcji matematycznych zawartych w standardowej bibliotece C++ `cmath`. Testy zostały napisane przy użyciu frameworka **Google Test**, który jest powszechnie stosowany do testowania kodu w języku C++.

## ⚙️ Kompilacja i uruchomienie

Aby skompilować projekt i uruchomić testy, użyj poniższych poleceń:

```bash
g++ cmath_test.cpp -lgtest -lgtest_main -pthread -o cmath_test
./cmath_test
```

## 🧪 Lista przetestowanych funkcji

### Funkcje trygonometryczne:
* std::sin

* std::cos

* std::tan

* std::asin

* std::acos

* std::atan

* std::atan2

### Funkcje wykładnicze i logarytmiczne:
std::exp

* std::exp2

* std::expm1

* std::log

* std::log10

* std::log2

* std::log1p

* std::pow

### Funkcje pierwiastkowe:
* std::sqrt

* std::cbrt

### Funkcje zaokrąglające:
* std::ceil

* std::floor

* std::round

* std::trunc

* std::llround

### Funkcje pomocnicze:
* std::fabs – wartość bezwzględna (dla double)

* std::abs – wartość bezwzględna (dla int)

* std::copysign – kopiowanie znaku

* std::fdim – różnica dodatnia

* std::fmod – reszta z dzielenia zmiennoprzecinkowego

* std::fma – mnożenie i dodawanie (Fused Multiply-Add)

* std::fmin / std::fmax – minimum i maksimum

### Inne:
* std::frexp – rozkład na mantysę i wykładnik

* std::hypot – obliczanie odległości euklidesowej

* std::ilogb – całkowity logarytm binarny

* std::ldexp – odwrotność frexp, mnożenie przez potęgę dwójki

* std::erf / std::erfc – funkcja błędu i jej dopełnienie
