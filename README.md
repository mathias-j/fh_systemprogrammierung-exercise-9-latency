# Übung 9.1 – Latenz

Das Programm berechnet den Mittelwert der Daten von 100 Servern. Eine Anfrage
an einen Server (`requestDataFromServer()` in `main/library.c`) dauert zufällig
zwischen 0 und 2 Sekunden. Weil `calculateMean()` die Server nacheinander
abfragt, dauert ein Durchlauf insgesamt etwa 100 Sekunden.

## Aufgabe

Optimieren Sie die Funktion `calculateMean()` in `main/main.c`, damit das
Ergebnis schneller verfügbar ist. Das Ergebnis darf sich dabei nicht ändern.

Einschränkungen:

- Es dürfen nie mehr als 10 Verbindungen (`MAX_CONNECTIONS`) gleichzeitig offen
  sein. Jeder Aufruf von `requestDataFromServer()` hält eine Verbindung offen,
  bis er zurückkehrt. Sind es mehr, meldet die Bibliothek
  `Too many connections - server overloaded` und das Programm bleibt hängen.
- Die Bibliothek `main/library.c` soll nicht verändert werden.

## Bauen und Starten

Das Projekt ist für den ESP32-C3 mit ESP-IDF 6.1 eingerichtet.

```sh
idf.py build
idf.py -p COM<n> flash monitor   # Monitor mit Ctrl+] beenden
```

## Ausgabe

Nach dem Start gibt das Programm den Mittelwert, den erwarteten Wert und die
benötigte Zeit aus:

```text
I (...) main: Requesting data from 100 servers...
I (...) main: Mean value: 49 (expected 49, used <Zeit> ms)
```

Die Ausgangsversion braucht etwa 100 s. Bis dahin erscheint keine weitere
Ausgabe – das Programm hängt also nicht.
