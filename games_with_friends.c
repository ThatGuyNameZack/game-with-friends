#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Player structure
struct Player {
    char name[50];
    int health;
    int mana;
    int attack;
    int defense;
    int slash;
    int magic;
};

// Enemy structure
struct Enemy {
    char name[50];
    int health;
    int attack;
};



void displayEnemyStats(struct Enemy *enemy) {
    printf("\nEnemy Name: %s\n", enemy->name);
    printf("Enemy Health: %d\n", enemy->health);
    printf("Enemy Attack: %d\n", enemy->attack);
}

void doCombat(struct Player *player, struct Enemy *enemy) {
    int combat = 1; 
    while(combat)
    {
        printf("\n1.Attack\n");
        printf("2.Skill\n");
        printf("3.Enemy Check\n");
        printf("4.NIGERUNDAYO!!!\n");
        int combatChoices;
        scanf("%d", &combatChoices);


            switch(combatChoices)
            {
                case 1:
                printf("You attacked %s!\n", enemy-> name);
                break;

                case 2:
                printf("\nHere are your skills\n");
                printf("1. Fireball\n");
                printf("2. World Slash\n");
                 int skills;
                scanf("%d", &skills);
                   
                    switch(skills)
                   {
                    
                    case 1:
                        if (player->mana >= 25) {
                            printf("You case Fireball\n");
                            printf("it hit %s\n", enemy -> name);

                        player->mana -= 15;
                        } else {
                            printf("Not enough mana to cast Fireball\n");
                        }
                        break;

                    
                    case 2:
                        if (player->mana >= 15) {
                            printf("You cast World Slash\n");
                            printf("It hit %s\n", enemy->name);
                            // Reduce mana when World Slash is used
                         player->mana -= 15;
                        } else {
                            printf("Not enough mana to cast World Slash!\n");
                        }
                        break;
                   }
                case 3:
                    displayEnemyStats(enemy);
                    break;
                case 4:
                    printf("you try to ran away...");
                //gave it a 30% chance to escape
                if (rand() % 100 < 30) {
                    printf("You successfully ran away!\n");
                    combat = 0; // Exit combat loop
                } else {
                    printf("CRAP, HE WONT LET YOU GET AWAY!\n");
                    // Continue the combat loop
                }
                break;
            }
           




    }
}

int main() {
    srand(time(0)); // Seed for randomization

    struct Player player = {"Player", 100, 50, 20, 10, 40, 45}; // Set player stats
    struct Enemy enemy;

    printf("Welcome to the game!\n");

    int choice;
    do {
        printf("\n1. Explore\n");
        printf("2. View Character Stats\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int randEnemy = rand() % 6; // Change 3 to the number of different enemies you have

                    switch (randEnemy) {
                        case 0:
                            // Set stats for enemy type 1
                            enemy = (struct Enemy){"Goblin", 50, 15};
                            printf("this might be easy");
                            break;
                        case 1:
                            // Set stats for enemy type 2
                            enemy = (struct Enemy){"Dragon", 250, 75};
                            printf("this might be dangerous");
                            break;
                        case 2:
                            // Set stats for enemy type 3
                            enemy = (struct Enemy){"Skeleton", 30, 25};
                            printf("pretty spooky huh");
                            break;
                        case 3: 
                            enemy = (struct Enemy){"Skeleton King", 100, 50};
                            printf("kind of troubling this one");
                            break;
                        case 4:
                            enemy = (struct Enemy){"Elder God", 999, 999};
                            printf("it seems we have already lost...");
                            break;
                        case 5:
                            enemy = (struct Enemy){"Slime", 10, 5};
                            printf("pretty cute for being an enemy");
                            break;
                        case 6:
                            enemy = (struct Enemy){"Baby Dragon", 125, 32};
                            printf("we could probably handle this one");
                            break;
                    }
                    printf("You encountered a %s!\n", enemy.name);
                    doCombat(&player, &enemy); // Start combat
                    break;
                }
            case 2:
                // Display player stats
                printf("Name: %s\n", player.name);
                printf("Health: %d\n", player.health);
                printf("Mana: %d\n", player.mana);
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
