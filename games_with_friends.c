#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct Player {
    char name[50]; //int player, structure of the player
    int health;
    int mana;
    int attack;
    int defense;
    int slash;
    int magic;
    int luck;
};

struct Enemy { 
    char name[50];//structure of the enemy
    int health;
    int attack;
};

void delayPrint(const char *text) { //added for dramatic effects
    while (*text != '\0') {
        putchar(*text);
        fflush(stdout);
        if (*text != ' ') {
            usleep(350000);
        } else {
            usleep(250000);
        }
        text++;
    }
}

void enemyAttack(struct Player *player, struct Enemy *enemy) {
    int luck = player->luck;
    int randomNum = rand() % 100; 

    if (randomNum < (luck * 0.5)) {  //rng system for enemy
        int damage = enemy->attack - player->defense;
        if (damage > 0) {
            player->health -= damage;
            printf("%s attacked you and dealt %d damage!\n", enemy->name, damage);
        } else {
            printf("%s attacked you, but you blocked the attack!\n", enemy->name);
        }
    } else {
        printf("%s tried to attack you, but missed!\n", enemy->name);
    }
}



void displayEnemyStats(struct Enemy *enemy) {
    printf("\nEnemy Name: %s\n", enemy->name);
    printf("Enemy Health: %d\n", enemy->health);
    printf("Enemy Attack: %d\n", enemy->attack);
}

void displayPlayerStats(struct Player *player) {
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Mana: %d\n", player->mana);
    printf("Attack: %d\n", player->attack);
    printf("Defense: %d\n", player->defense);
    printf("luck : %d\n", player->luck);
}

void doCombat(struct Player *player, struct Enemy *enemy) {
    player->mana = 65;
    player->health = 150;

    int combat = 1;

    while (combat) {
        printf("\n1.Attack\n");
        printf("2.Skill\n");
        printf("3.Enemy Check\n");
        printf("4.NIGERUNDAYO!!!\n");
        printf("5.Player Stats\n");
        int combatChoices;
        scanf("%d", &combatChoices);

        switch (combatChoices) {
            case 1:
                printf("You attacked %s!\n", enemy->name);
                int damage = player->attack;
                if (damage > 0) {
                    enemy->health -= damage;
                    printf("Dealt %d damage to %s!\n", damage, enemy->name);

                    if (enemy->health <= 0) {
                        printf("You defeated %s\n", enemy->name);
                        combat = 0;
                    }
                }
                break;

            case 2:
                printf("\nHere are your skills\n");
                printf("1. Fireball(25 mana)\n");
                printf("2. World Slash (15 mana)\n");
                int skills;
                scanf("%d", &skills);

                switch (skills) {
                    case 1:
                        if (player->mana >= 25) {
                            printf("You cast Fireball\n");
                            printf("It hits %s\n", enemy->name);
                            enemy->health -= 60;
                            player->mana -= 25;
                        } else {
                            printf("Not enough mana to cast Fireball\n");
                        }
                        if (enemy->health <= 0) {
                            printf("You defeated %s\n", enemy->name);
                            combat = 0;
                        }
                        break;

                    case 2:
                        if (player->mana >= 15) { 
                            printf("You cast World Slash\n");
                            printf("It hits %s\n", enemy->name);
                            enemy->health -= 38;
                            player->mana -= 15; //mana cost
                        } else {
                            printf("Not enough mana to cast World Slash!\n");
                        }
                        if (enemy->health <= 0) {
                            printf("You defeated %s\n", enemy->name);
                            combat = 0;
                        }
                        break;
                }
                break;

            case 3:
                displayEnemyStats(enemy);
                break;

            case 4:
                printf("you try to ran away...");
                if (rand() % 100 < 30) { //30% of running away from enemy
                    printf("You successfully ran away!\n");
                    combat = 0;
                } else {
                    printf("CRAP, HE WONT LET YOU GET AWAY!\n");
                }
                break;

            case 5:
                displayPlayerStats(player); //display player currnt stats in combat
                break;

            case 666: 
                delayPrint(".........\n");
                delayPrint("Ryōiki Tenkai\n");
                delayPrint("Fukuma Mizushi\n");
                delayPrint("...\n");
                delayPrint("...\n");
                enemy->health -= 999;
                if (enemy->health <= 0) {
                    printf("it seems the %s already perished by your hands\n", enemy->name);
                    combat = 0;
                }
                break;
        }

        if (enemy->health > 0) { //if the enemy health is zero
            enemyAttack(player, enemy);

            if (player->health <= 0) {
                printf("You have been utterly defeated by the %s. Take this L with you!\n", enemy->name);
                combat = 0; //end the combat loop
            }
        } else {
            printf("You defeated %s\n", enemy->name);
            combat = 0; //end the combat loop
        }
    }
}

int main() {
    srand(time(0)); 

    struct Player player = {"Player", 150, 65, 30, 50, 40, 45, 10}; //player stats
    struct Enemy enemy; //enemy structure

    printf("Welcome to the game!\n");

    int choice; //lobby 
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
                    int randEnemy = rand() % 6; //enemy randomizer

                    switch (randEnemy) {
                        case 0:
                            enemy = (struct Enemy){"Goblin", 50, 15};
                            printf("this might be easy\n");
                            break;
                        case 1:
                            enemy = (struct Enemy){"Dragon", 250, 75};
                            printf("this might be dangerous\n");
                            break;
                        case 2:
                            enemy = (struct Enemy){"Skeleton", 30, 25};
                            printf("pretty spooky huh\n");
                            break;
                        case 3: 
                            enemy = (struct Enemy){"Skeleton King", 100, 65};
                            printf("kind of troubling this one\n");
                            break;
                        case 4:
                            enemy = (struct Enemy){"Elder God", 999, 999};
                            printf("it seems we have already lost...\n");
                            break;
                        case 5:
                            enemy = (struct Enemy){"Slime", 10, 5};
                            printf("pretty cute for being an enemy\n");
                            break;
                        case 6:
                            enemy = (struct Enemy){"Baby Dragon", 125, 32};
                            printf("we could probably handle this one\n");
                            break;
                    }
                    printf("You encountered a %s!\n", enemy.name);
                    doCombat(&player, &enemy);
                    break;
                }
            case 2:
                displayPlayerStats(&player); //hence the name it will display the player stats
                break;

            case 3:
                printf("Exiting game. Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3); //if choice 3 it will end the program

    return 0;
}

