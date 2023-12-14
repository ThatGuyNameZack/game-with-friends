#include <stdio.h>

int main(){
	
	struct player {
	   	char name[50];
	   	int health;
	   	int mana;
	   	int attack;
	   	int defense;
    };
	
	printf("Name: %s\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Mana: %d\n", player.mana);
    printf("Attack: %d\n", player.attack);
    printf("Defense: %d\n", player.defense);

}

void drawHealthBar(int currentHealth, int maxHealth) {
    int barWidth = 20;  // Adjust the width of the health bar as needed
    int healthBar = (int)(((double)currentHealth / maxHealth) * barWidth);
    int i;
    
    
    printf("Health: [");
    
    for (i = 0; i < barWidth; i++) {
        if (i < healthBar) {
            printf("#");
        } else {
            printf(" ");
        }
    }

    printf("] %d/%d\n", currentHealth, maxHealth);
}

int main() {
    int player.health =%d;
    int maxhealth = %d;

    drawHealthBar(player.health, maxHealth);

    return 0;
}

