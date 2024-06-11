#include <cstdlib>
#include <iostream>
#include <random>
#include <string>

class Player {
  protected:
  int maxHealth;
  int health;
  int baseDamage;
  
  public:
  std::string playerName;

  public:
  Player() {}

  int getHealth() { return health; }

  bool isAlive() { 
    return (health > 0);
  }

  void playerStats(){
    std::cout << "Player Health: " << health << "\n";
    std::cout << "Player Base Damage: " << baseDamage << "\n";
  }

  virtual void takeDamage(int) = 0;
  virtual void giveBaseDamage(Player *) = 0;
  virtual void giveAdditionalDamage(Player *) = 0;
  virtual void heal() = 0;

  virtual
  ~Player () {}

};

// Player Type 1 - High health / Low Damage / Low Healing
class Warrior : public Player {
  private:
  int additionalDamage;
  int healingCapacity;
  int maxAdditionalDamage;
  int maxHealing;
  int minAdditionalDamage;
  int minHealing;

  public:
  Warrior() {
    maxHealth = 150;
    health = maxHealth;
    baseDamage = 10;
    maxAdditionalDamage = 10;
    minAdditionalDamage = 1;
    maxHealing = 5;
    minHealing = 1;
    playerName = "Warrior";
  }

  void takeDamage(int damage) {
    health -= damage;
    std::cout << "\n" << playerName << " health after taking damage " << health;
  }

  void giveBaseDamage(Player *player) {
    std::cout << "\n" << playerName << " deals base damage of " << baseDamage
              << std::endl;
    player->takeDamage(baseDamage);
  }

  void giveAdditionalDamage(Player *player) {
    additionalDamage = (rand() % (maxAdditionalDamage - minAdditionalDamage + 1)) + minAdditionalDamage;
    std::cout << "\n" << playerName << " deals additional damage of "
              << additionalDamage << std::endl;
    player->takeDamage(additionalDamage);
  }

  void heal() {
    healingCapacity = (rand() % (maxHealing - minHealing + 1)) + minHealing;
    health += healingCapacity;
    if (health > maxHealth) {
      std::cout << playerName << " has max health" << std::endl;
      health = maxHealth;
    }
    std::cout << "\n"<< playerName << " healed by " << healingCapacity << "\n" << playerName << " health after healing: " << health << std::endl;
  }

  ~Warrior() {}
};

// Player Type 2 - Avg health / Avg Damage / Avg Healing
class Rogue : public Player {
  private:
  int additionalDamage;
  int healingCapacity;
  int maxAdditionalDamage;
  int maxHealing;
  int minAdditionalDamage;
  int minHealing;
  
  public:
  Rogue() {
    maxHealth = 100;
    health = maxHealth;
    baseDamage = 20;
    maxAdditionalDamage = 20;
    minAdditionalDamage = 1;
    maxHealing = 10;
    minHealing = 1;
    playerName = "Rogue";
  }

    void takeDamage(int damage) {
      health -= damage;
      std::cout << "\n" << playerName << " health after taking damage " << health;
    }

    void giveBaseDamage(Player *player) {
      std::cout << "\n" << playerName << " deals base damage of " << baseDamage
                << std::endl;
      player->takeDamage(baseDamage);
    }

    void giveAdditionalDamage(Player *player) {
      additionalDamage = (rand() % (maxAdditionalDamage - minAdditionalDamage + 1)) + minAdditionalDamage;
      std::cout << "\n" << playerName << " deals additional damage of "
                << additionalDamage << std::endl;
player->takeDamage(additionalDamage);
    }

    void heal() {
      healingCapacity = (rand() % (maxHealing - minHealing + 1)) + minHealing;
      health += healingCapacity;
      if (health > maxHealth) {
        std::cout << playerName << " has max health" << std::endl;
        health = maxHealth;
      }
      std::cout << "\n"<< playerName << " healed by " << healingCapacity << "\n" << playerName << " health after healing: " << health << std::endl;
    }

  ~Rogue() {}
};

// Player Type 3 - Low health / High Damage / Avg Healing
class Barbarian : public Player {
  private:
  int additionalDamage;
  int healingCapacity;
  int maxAdditionalDamage;
  int maxHealing;
  int minAdditionalDamage;
  int minHealing;

  public:
  Barbarian() {
    maxHealth = 50;
    health = maxHealth;
    baseDamage = 30;
    maxAdditionalDamage = 30;
    minAdditionalDamage = 1;
    maxHealing = 10;
    minHealing = 1;
    playerName = "Barbarian";
  }

  void takeDamage(int damage) {
    health -= damage;
    std::cout << "\n" << playerName << " health after taking damage " << health;
  }

  void giveBaseDamage(Player *player) {
    std::cout << "\n" << playerName << " deals base damage of " << baseDamage
              << std::endl;
    player->takeDamage(baseDamage);
  }

  void giveAdditionalDamage(Player *player) {
    additionalDamage = (rand() % (maxAdditionalDamage - minAdditionalDamage + 1)) + minAdditionalDamage;
    std::cout << "\n" << playerName << " deals additional damage of "
              << additionalDamage << std::endl;
    player->takeDamage(additionalDamage);
  }

  void heal() {
    healingCapacity = (rand() % (maxHealing - minHealing + 1)) + minHealing;
    health += healingCapacity;
    if (health > maxHealth) {
      std::cout << playerName << " has max health" << std::endl;
      health = maxHealth;
    }
    std::cout << "\n"<< playerName << " healed by " << healingCapacity << "\n" << playerName << " health after healing: " << health << std::endl;
  }

  ~Barbarian() {}
};

class Game {
  public:
  void gameLoop() {
    char keyPressed;
    
    Player *player1 = playerType(1);
    Player *player2 = playerType(2);

    Player *currentPlayer = player1;
    Player *opponentPlayer = player2;

    while ((currentPlayer->isAlive()) && (opponentPlayer->isAlive())) {
      std::cout << "\n" << currentPlayer->playerName << " , press 'A' to attack " << opponentPlayer->playerName << " or press 'H' to heal" << std::endl;

      std::cin >> keyPressed;

      if (keyPressed == 'A' || keyPressed == 'a') {
        std::cout << currentPlayer->playerName << " attacks " << opponentPlayer->playerName << std::endl;
        currentPlayer->giveBaseDamage(opponentPlayer);
        currentPlayer->giveAdditionalDamage(opponentPlayer);
        std::cout << "\n" << opponentPlayer->playerName << " health after being attacked "
                  << opponentPlayer->getHealth() << "\n";
      } else if (keyPressed == 'H' || keyPressed == 'h') {
        currentPlayer->heal();
      } else {
        std::cout << "Invalid Key Pressed" << std::endl;
        continue;
      }

      Player *tempPlayer = currentPlayer;
      currentPlayer = opponentPlayer;
      opponentPlayer = tempPlayer;
    }
    if(!currentPlayer->isAlive())
    {
      std::cout << "\n Game over! " << opponentPlayer->playerName << " Wins!!" << std::endl;
    }
    else if(!opponentPlayer->isAlive())
    {
      std::cout << "\n Game over! " << currentPlayer->playerName << " Wins!!" << std::endl;
    }
    delete player1;
    delete player2;
  }

  Player* playerType(int i) {
    int playerType;
    Player *player;

    std::cout << "\nPlayer" << i << " Select Player Type - \n1. Warrior \n2. Rogue \n3. Barbarian"
              << std::endl;
    std::cin >> playerType;

    switch (playerType) {
    case 1:
      std::cout << "\nWarrior!!, weilds swords, axes, knives with ease. Great at "
                   "different combat strategies "
                << std::endl;
      player = new Warrior();
      break;

    case 2:
      std::cout << "\nRogue!!, shoots impressive arrows with great precision. "
                   "Agile with amazing reflexes "
                << std::endl;
      player = new Rogue();
      break;

    case 3:
      std::cout
          << "\nBarbarian!!, powerful, huge and mighty. Incredible melee attacker"
          << std::endl;
      player = new Barbarian();
      break;
    }

    std::cout << "\nPlayer" << i << "- " << player->playerName << " Stats:\n";

    player->playerStats();
    return player;
  }

  ~Game() {
  }  
};

int main() {

  std::cout << "\n Welcome to Battle Arena " << std::endl;

  std::cout << "\nRules" << std::endl;

  std::cout << "\n1. Each Player has only one turn at a time"<< std::endl;
  std::cout << "\n2. Each Player has different damage, additional damage and heal"<< std::endl;
  std::cout << "\n3. When Player's health goes below 0, the player dies"<< std::endl;
  std::cout << "\n4. Player can either attack by pressing 'a' or heal by pressing 'h', at each turn"<< std::endl;
  
  Game gameManager;
  gameManager.gameLoop();
}
