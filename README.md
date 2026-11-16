# 🍲 Panoramix — POSIX Multithreading & Synchronization in C

[![Academic Year](https://img.shields.io/badge/Epitech-Tek2-green?style=for-the-badge&logo=epitech&logoColor=white)](https://www.epitech.eu/)
[![Module](https://img.shields.io/badge/Module-G--CCP--400-informational?style=for-the-badge)](#)
[![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)](#)

## 📘 Description
**Panoramix** résout le problème classique de concurrence et de synchronisation des threads (variante du problème du barbier / des philosophes). Des villageois gaulois consomment des portions d'une marmite de potion magique. Lorsque la marmite est vide, le druide Panoramix doit être réveillé pour la remplir à nouveau, sans aucune situation d'interblocage (deadlock) ni de famine (starvation).

## ⚙️ Notions Concurrence
- Synchronisation par sémaphores POSIX et variables de condition (`pthread_cond_wait`, `pthread_cond_signal`).
- Protection des sections critiques via `pthread_mutex_t`.
- Modèle producteur/consommateur multithreadé propre.

## 🔨 Compilation & Utilisation
```bash
make
./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
```
