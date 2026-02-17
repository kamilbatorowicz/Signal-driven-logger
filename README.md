# SIGNAL DRIVEN LOGGER

Projekt obejmuje implementację zaawansowanej biblioteki w języku C, służącej do logowania zdarzeń oraz wykonywania zrzutów stanu aplikacji (dumping). System jest unikalny, ponieważ jego konfiguracja i działanie są w pełni sterowane przez sygnały czasu rzeczywistego (POSIX real-time signals) wraz z przenoszonymi przez nie danymi.

Funkcjonalności:
- Sterowanie sygnałami RT: wykorzystanie mechanizmów POSIX do dynamicznego zarządzania biblioteką bez przerywania pracy aplikacji.
- Asynchroniczny system zrzutów (Dump): jeden z sygnałów generuje oddzielny plik z aktualnym stanem wewnętrznym aplikacji.
- Zawartość zrzutu jest konfigurowalna po stronie aplikacji.
- Dynamiczne logowanie zdarzeń (Log): włączanie/wyłączanie zapisu logów za pomocą dedykowanego sygnału., trzy poziomy szczegółowości: MIN, STANDARD, MAX.
- Filtrowanie komunikatów: decyzja o zapisie logu podejmowana jest na podstawie porównania istotności komunikatu z aktualnie ustawionym poziomem szczegółowości.
- Bezpieczeństwo wątkowe (Thread-Safety): pełna wsparcie dla aplikacji wielowątkowych.