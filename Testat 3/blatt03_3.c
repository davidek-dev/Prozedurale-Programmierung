/*
1.3  
Größter gemeinsamer Teiler   (6 Punkte)
Schreiben Sie ein Programm, welches für zwei gegebene nicht-negative ganze Zahlen a
und b den größten gemeinsamen Teiler (ggT) bestimmt und auf dem Bildschirm ausgibt.

a) Implementieren Sie dafür den klassischen Euklidischen Algorithmus:
1. Berechnen Sie die absolute Differenz |a−b| der beiden gegebenen Zahlen.
2. Ersetzen Sie die größere der Zahlena, durch die in Schritt 1. berechnete Differenz.
3. Wiederholen Sie Schritt 1. und 2. solange, bis eine der Zahlen gleich Null ist. 
Die von Null verschiedene Zahl ist der ggT.

b) Implementieren Sie den effizienteren, modifizierten Euklidischen Algorithmus:
1. Bestimmen Sie den Rest bei der Integer-Division von a und b,
2. Ersetzen Sie a durch b und b durch den in 1. berechneten Rest,
3. Wiederholen Sie die Schritte 1. und 2. solange b ungleich Null ist.
Zur Berechnung des Restes der Integer-Division kann der Modulo-Operator % verwendet werden, 
z.B.13 % 4 = 1.

c) Nicht alle Architekturen und Programmiersprachen unterstützen die Modulo-Operation.
Wie kann unter Ausnutzung der Integer-Division der Divisionrest trotzdem noch effizient berechnet werden? 
Wie verändert sich das Programm aus b)?
*/