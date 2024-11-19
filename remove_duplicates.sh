#!/bin/bash

# Plik wejściowy
input_file="movie_database.csv"

# Plik wyjściowy
output_file="movie_database_no_duplicates.csv"

# Usuń nadmiarowe spacje wokół danych i zapisz do tymczasowego pliku
awk -F ',' '{ 
    # Usuń nadmiarowe spacje wokół słów
    gsub(/^[ \t]+|[ \t]+$/, "", $1); 
    gsub(/^[ \t]+|[ \t]+$/, "", $2); 
    gsub(/^[ \t]+|[ \t]+$/, "", $3); 
    gsub(/^[ \t]+|[ \t]+$/, "", $4); 
    # Wydrukuj dane w formacie: tytuł,rok,gatunek1,gatunek2
    print $1","$2","$3","$4
}' $input_file | sort -u > $output_file

# Usuń oryginalny plik
rm $input_file

# Zmień nazwę pliku wyjściowego na oryginalną nazwę
mv $output_file $input_file

echo "Plik $input_file został zaktualizowany, duplikaty usunięte."
