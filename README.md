# Testowanie funkcji `cmath` w C++ z użyciem Google Test

## 📌 Opis projektu

Projekt ten zawiera zestaw testów jednostkowych dla funkcji matematycznych zawartych w standardowej bibliotece C++ `cmath`. Testy zostały napisane przy użyciu frameworka **Google Test**, który jest powszechnie stosowany do testowania kodu w języku C++.

## ⚙️ Kompilacja i uruchomienie

Aby skompilować projekt i uruchomić testy, użyj poniższych poleceń:

```bash
g++ cmath_test.cpp -lgtest -lgtest_main -pthread -o cmath_test
./cmath_test
