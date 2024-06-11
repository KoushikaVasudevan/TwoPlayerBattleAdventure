#include <cstdlib>
#include <iostream>
#include <random>
#include <string>

class Player {
  protected:
  int health;
  int baseDamage;
  int additionalDamage;
  int healingCapacity;
  
  public:
  Player(){
    
  }

  int getHealth(){
    return health;
  }
  
  virtual void playerStats() = 0;
  virtual void takeDamage(int) = 0;
  virtual void giveBaseDamage(Player*) = 0;
  virtual void giveAdditionalDamage(Player*) = 0;
  virtual void heal() = 0;
};

// Player Type 1 - High health / Low Damage / Low Healing
class Warrior : public Player {
  public:
  Warrior()
  {
    health = 150;
    baseDamage = 10;
    additionalDamage = rand() % 10 + 1;
    healingCapacity = rand() % 5 + 1;
    //totalDamage = baseDamage + additionalDamage;
  }

  void playerStats() {
    std::cout << "\nHealth: " << health;
    std::cout << "\nBase Damage: " << baseDamage;
    std::cout << "\nAdditional Damage: " << additionalDamage;
    std::cout << "\nHealing Capacity: " << healingCapacity << std::endl;
  }

  void takeDamage(int damage) {
    health -= damage;
    std::cout << "\nWarrior health after taking damage " <<  health;
  }

  void giveBaseDamage(Player *opponentPlayer) {
    std::cout << "\nWarrior player deals base damage of "
              << baseDamage << std::endl;
    opponentPlayer->takeDamage(baseDamage);
  }

  void giveAdditionalDamage(Player *opponentPlayer) {
    std::cout << "\nWarrior player deals additional damage of "
              << additionalDamage << std::endl;
    opponentPlayer->takeDamage(additionalDamage);
  }

  void heal() {
    health += healingCapacity;
    if(health > 150) {
      std::cout << "\nWarrior has max health" << std::endl;
      health = 150;
    }
    if(health <= 0){
      std::cout << "\nWarrior health = 0, Warrior is dead!!" << std::endl;
    }
    std::cout << "\nWarrior healed by " << healingCapacity << "\nWarrior health after healing: " << health << std::endl;
  }
};

// Player Type 2 - Avg health / Avg Damage / Avg Healing
class Rogue : public Player {
  public:
  Rogue()
  {
    health = 100;
    baseDamage = 20;
    additionalDamage = rand() % 20 + 1;
    healingCapacity = rand() % 10 + 1;
  }

  void playerStats() {
    std::cout << "\nHealth: " << health;
    std::cout << "\nBase Damage: " << baseDamage;
    std::cout << "\nAdditional Damage: " << additionalDamage;
    std::cout << "\nHealing Capacity: " << healingCapacity << std::endl;
  }

  void takeDamage(int damage) {
    health -= damage;
    std::cout << "\nRogue health after taking damage " << health << std::endl;
  }

  void giveBaseDamage(Player *opponentPlayer) {
    std::cout << "\nRogue player deals base damage of "
              << baseDamage << std::endl;
    opponentPlayer->takeDamage(baseDamage);
  }

  void giveAdditionalDamage(Player *opponentPlayer) {
    std::cout << "\nRogue player deals additional damage of "
              << additionalDamage << std::endl;
    opponentPlayer->takeDamage(additionalDamage);
  }

  void heal() {
    health += healingCapacity;
    if(health > 100) {
      std::cout << "\nRogue has max health" << std::endl;
      health = 100;
    }
    if(health <= 0){
      std::cout << "\nRogue health = 0, Rogue is dead!!" << std::endl;
    }
    std::cout << "\nRogue healed by " << healingCapacity << "\nRogue health after healing: " << health << std::endl;
  }
};

// Player Type 3 - Low health / High Damage / Avg Healing
class Barbarian : public Player {
  public:
  Barbarian()
  {
    health = 50;
    baseDamage = 30;
    additionalDamage = rand() % 30 + 1;
    healingCapacity = rand() % 10 + 1;
  }

  void playerStats() {
    std::cout << "\nHealth: " << health;
    std::cout << "\nBase Damage: " << baseDamage;
    std::cout << "\nAdditional Damage: " << additionalDamage;
    std::cout << "\nHealing Capacity: " << healingCapacity << std::endl;
  }

  void takeDamage(int damage) {
    health -= damage;
    std::cout << "\nBarbarian health after taking damage " << health << std::endl;
  }

  void giveBaseDamage(Player *opponentPlayer) {
    std::cout << "\nBarbarian player deals base damage of "
              << baseDamage << std::endl;
    opponentPlayer->takeDamage(baseDamage);
  }

  void giveAdditionalDamage(Player *opponentPlayer) {
    std::cout << "\nBarbarian player deals additional damage of "
              << additionalDamage << std::endl;
    opponentPlayer->takeDamage(additionalDamage);
  }

  void heal() {
    health += healingCapacity;
    if(health > 100) {
      std::cout << "\nBarbarian has max health" << std::endl;
      health = 100;
    }
    if(health <= 0){
      std::cout << "\nBarbarian health = 0, Barbarian is dead!!" << std::endl;
    }
    std::cout << "\nBarbarian healed by " << healingCapacity << "\nBarbarian health after healing: " << health << std::endl;
  }
};

int playerTypeMenu() {
  int playerType;

  std::cout << "Select Player Type - \n1. Warrior \n2. Rogue \n3. Barbarian"
            << std::endl;
  std::cin >> playerType;

  switch (playerType) {
  case 1:
    std::cout << "\nWarrior!!, weilds swords, axes, knives with ease. Great at "
                 "different combat strategies "
              << std::endl;
    break;

  case 2:
    std::cout << "\nRogue!!, shoots impressive arrows with great precision. "
                 "Agile with amazing reflexes "
              << std::endl;
    break;

  case 3:
    std::cout
        << "\nBarbarian!!, powerful, huge and mighty. Incredible melee attacker"
        << std::endl;
    break;
  }

  return playerType;
}

int main() {
  Player *player1;
  Player *player2;

  int playerType1;
  int playerType2;

  char keyPressed;

  // 1st Player
  std::cout << "\n Player1 - Welcome to Battle Arena" << std::endl;
  playerType1 = playerTypeMenu();
  std::cout << "\nPlayer1 Stats: " << std::endl;

  if (playerType1 == 1) {
    player1 = new Warrior();
  }
  else if (playerType1 == 2) {
    player1 = new Rogue();
  } 
  else {
    player1 = new Barbarian();
  }

  player1->playerStats();

  // 2nd Player
  std::cout << "\n Player2 - Welcome to Battle Arena" << std::endl;
  playerType2 = playerTypeMenu();
  std::cout << "\nPlayer2 Stats: " << std::endl;

  if (playerType2 == 1) 
  {
    player2 = new Warrior();
  } 
  else if (playerType2 == 2) 
  {
    player2 = new Rogue();
  } 
  else 
  {
    player2 = new Barbarian();
  }
  
  player2->playerStats();

  std::cout << "\n Let the battle begin!!";
  std::cout << "\nPlayer1, press 'A' to attack Player2 or press 'H' to heal"
            << std::endl;
  std::cin >> keyPressed;

  if (keyPressed == 'A' || keyPressed == 'a') 
  {
    std::cout << "\nPlayer1 attacks Player2" << std::endl;
    player1->giveBaseDamage(player2);
    player1->giveAdditionalDamage(player2);
    std::cout << "\nPlayer2 health after being attacked" << player2->getHealth();
  } 
  else if (keyPressed == 'H' || keyPressed == 'h') 
  {
    player1->heal();
  } 
  else 
  {
    std::cout << "Invalid Key Pressed" << std::endl;
  }
}
