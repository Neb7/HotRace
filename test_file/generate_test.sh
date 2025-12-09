#!/bin/bash

# Vérifier les arguments
if [ $# -ne 2 ]; then
    echo "Usage: $0 <nombre_entrees> <nombre_recherches>"
    echo "Exemple: $0 10000 1000"
    exit 1
fi

NUM_ENTRIES=$1
NUM_SEARCHES=$2
OUTPUT="test_${NUM_ENTRIES}e_${NUM_SEARCHES}s.htr"

echo "Génération de $NUM_ENTRIES entrées..."

# Génération des paires clé-valeur
for i in $(seq 1 $NUM_ENTRIES); do
    echo "key_${i}"
    echo "value_${i}_$(date +%s%N | md5sum | head -c 20)"
done > $OUTPUT

# Ligne vide séparatrice
echo "" >> $OUTPUT

echo "Génération de $NUM_SEARCHES recherches..."

# Génération de recherches (50% existantes, 50% non-existantes)
for i in $(seq 1 $NUM_SEARCHES); do
    if [ $((i % 2)) -eq 0 ]; then
        # Clé existante
        echo "key_$((RANDOM % NUM_ENTRIES + 1))"
    else
        # Clé non-existante
        echo "notfound_${i}"
    fi
done >> $OUTPUT

echo "✅ Fichier $OUTPUT généré avec $NUM_ENTRIES entrées et $NUM_SEARCHES recherches"
ls -lh $OUTPUT
