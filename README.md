# Signal Driven Logger 📡

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![POSIX](https://img.shields.io/badge/POSIX-RT_Signals-red?style=for-the-badge)
![Thread-Safe](https://img.shields.io/badge/Thread--Safe-Yes-success?style=for-the-badge)

## 📋 Opis projektu

Projekt obejmuje implementację zaawansowanej biblioteki w języku C, służącej do asynchronicznego logowania zdarzeń oraz wykonywania zrzutów stanu aplikacji (dumping). System wyróżnia się unikalnym podejściem do sterowania: konfiguracja i zachowanie biblioteki są zarządzane dynamicznie za pomocą **sygnałów czasu rzeczywistego (POSIX RT)**, co pozwala na zmianę parametrów pracy bez konieczności restartu procesu.

---

## 🏗️ Struktura Projektu (Zgodnie z wymaganiami)

### 1. Opis problemu
Standardowe biblioteki logujące wymagają restartu aplikacji lub stałego monitorowania plików konfiguracyjnych w celu zmiany poziomu logowania. Wyzwaniem było stworzenie mechanizmu, który pozwoli na "gorącą" rekonfigurację (Hot-Reloading) przy minimalnym narzucie wydajnościowym, wykorzystując natywne mechanizmy jądra Linux.

### 2. Sterowanie sygnałami RT (Control Plane)
Wykorzystanie mechanizmów `sigaction` oraz `sigqueue` do przesyłania danych sterujących wraz z sygnałem.
* Dynamiczne zarządzanie biblioteką bez przerywania pracy głównej pętli aplikacji.
* Przekazywanie dodatkowych wartości (si_value) w celu precyzyjnego sterowania parametrami.

### 3. Dynamiczne logowanie i filtrowanie
System oferuje inteligentne zarządzanie strumieniem komunikatów:
* **Trzy poziomy szczegółowości**: `MIN`, `STANDARD` oraz `MAX`.
* **Filtrowanie**: Porównywanie priorytetu nadchodzącego zdarzenia z aktualnie ustawionym progiem (Runtime Filtering).
* Możliwość całkowitego wyciszenia/aktywacji logowania dedykowanym sygnałem.

### 4. Asynchroniczny system zrzutów (Dump)
Implementacja mechanizmu diagnostycznego:
* Generowanie oddzielnych plików `.dump` z aktualnym stanem wewnętrznym struktur danych.
* Mechanizm asynchroniczny zapobiegający blokowaniu krytycznych sekcji kodu podczas zapisu na dysk.

### 5. Bezpieczeństwo i wielowątkowość
Projekt został zaprojektowany z myślą o nowoczesnych aplikacjach serwerowych:
* **Thread-Safety**: Pełne wsparcie dla środowisk wielowątkowych dzięki zastosowaniu prymitywów synchronizacji (mutexy/atomics).
* Bezpieczeństwo wewnątrz programów obsługi sygnałów (*Async-Signal-Safe*).

---

## 🛠️ Technologie

* **Język:** C (Standard C11)
* **Standardy:** POSIX Real-time Signals (SIGRTMIN+n)
* **Biblioteki:** Pthreads (do obsługi wielowątkowości)
* **Narzędzia:** Makefile, GDB, Valgrind (do sprawdzania wycieków pamięci)

---

## 🚀 Szybki start

1. Sklonuj repozytorium:
   ```bash
   git clone [https://github.com/TwojUser/Signal-Driven-Logger.git](https://github.com/TwojUser/Signal-Driven-Logger.git)
