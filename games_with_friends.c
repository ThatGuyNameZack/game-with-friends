#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Player structure
struct Player {
    char name[50];
    int health;
    int attack;
    int defense;
};

// Enemy structure
struct Enemy {
    char name[50];
    int health;
    int attack;
};

// Function to perform combat
void doCombat(struct Player *player, struct Enemy *enemy) {
    // Combat logic goes here
    // Compare player's attack and enemy's defense, deduct health accordingly
}

int main() {
    srand(time(0)); // Seed for randomization

    struct Player player = {"Player", 100, 20, 10}; // Set player stats
    struct Enemy enemy = {"Goblin", 50, 15}; // Set enemy stats

    printf("Welcome to Text-Based RPG!\n");

    int choice;
    do {
        printf("\n1. Explore\n");
        printf("2. View Character Stats\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Simulate exploration or encounters
                // For example:
                printf("You encountered a %s!\n", enemy.name);
                doCombat(&player, &enemy); // Start combat
                break;
            case 2:
                // Display player stats
                printf("Name: %s\n", player.name);
                printf("Health: %d\n", player.health);
                printf("Attack: %d\n", player.attack);
                printf("Defense: %d\n", player.defense);
                break;
            case 3:
                printf("Exiting game. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
