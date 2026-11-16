[![Academic Year](https://img.shields.io/badge/Epitech-Tek2-green?style=for-the-badge&logo=epitech&logoColor=white)](https://www.epitech.eu/)
[![Language: C](https://img.shields.io/badge/Language-C-00599C.svg?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Concurrency: POSIX](https://img.shields.io/badge/Concurrency-POSIX_Threads_%26_Semaphores-informational.svg?style=for-the-badge)](#)
[![Module](https://img.shields.io/badge/Module-G--CCP--400-informational?style=for-the-badge)](#)

# 🍲 Panoramix — Synchronisation Multi-Threads & Sémaphores POSIX en C

**Panoramix** est une simulation concurrente en langage C modélisant le problème classique de synchronisation de threads (variante du problème du *Barbier Endormi* / *Producteur-Consommateur*). Le programme simule le village gaulois où les guerriers consomment des portions de potion magique dans une marmite commune gérée par le druide Panoramix avant d'aller combattre les Romains.

---

## 👥 Modèle de Concurrence & Synchronisation

- **Ressource Partagée : La Marmite de Potion** :
  - Capacité maximale fixe de portions (`pot_size`).
  - Accès critique protégé contre les conditions de course (*race conditions*) par un mutex POSIX (`pthread_mutex_t mutex`).
- **Threads Villageois (`villagers`)** :
  - Chaque guerrier souhaite combattre $N$ fois (`nb_fights`).
  - Avant chaque combat, le guerrier vérifie la marmite.
  - S'il reste de la potion, il décrémente la marmite et part au combat.
  - Si la marmite est vide, il réveille le druide via le sémaphore `sem_t call_druid` et attend qu'elle soit remplie.
- **Thread Druide (`druid`)** :
  - Panoramix dort tant que la marmite contient des portions.
  - Lorsqu'il est réveillé par un villageois, il remplit la marmite à sa capacité maximale `pot_size` et signale la disponibilité via `sem_t potion_portions`.
  - Le druide effectue un nombre maximal de recharges (`nb_refills`). Une fois épuisées, il se retire.
- **Absence de Deadlock** : Ordonnancement strict des verrous garantissant une terminaison propre sans interblocage ni famine (*starvation*).

---

## 💻 Paramètres d'Utilisation

```bash
./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
```

| Argument | Description | Contrainte |
|---|---|---|
| `nb_villagers` | Nombre total de threads villageois gaulois. | $> 0$ |
| `pot_size` | Capacité maximale de portions dans la marmite. | $> 0$ |
| `nb_fights` | Nombre de combats que chaque villageois doit mener. | $> 0$ |
| `nb_refills` | Nombre de recharges de marmite que le druide peut effectuer. | $> 0$ |

---

## 🛠️ Compilation

```bash
make        # Génère l'exécutable 'panoramix'
make clean  # Nettoie les fichiers objets temporaires
make fclean # Supprime les fichiers objets et le binaire
make re     # Recompile le programme
```

### Exemple d'Exécution :
```bash
./panoramix 3 5 2 1
```
