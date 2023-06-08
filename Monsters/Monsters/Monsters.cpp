// Monsters.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <cstdlib> // для rand() и srand()
#include <ctime> // для time()

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем генерацию значения из диапазона
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class  Creature
{
protected:
    std::string m_name;
    char m_sym;
    int m_health;
    int m_damage;
    int m_gold;
public:
    Creature (std::string name, char sym, int health, int damage, int gold)
        : m_name(name), m_sym(sym), m_health(health), m_damage(damage), m_gold(gold){}
    const std::string getName() { return m_name; }
    char getSym() { return m_sym; }
    int getHealth() { return m_health; }
    int getDamage() { return m_damage; }
    int getGold() { return m_gold; }

    void reduceHealth(int health){ m_health -= health; }
    bool isDead() { return m_health <= 0; }
    void addGold(int gold) { m_gold += gold; }
    void addHealth(int health) { m_health += health; }
};

class Player : public Creature
{
private:
    int m_level = 1;
public:
    Player(std::string name): Creature(name, '@', 10, 1, 0) {}
    void levelUp() { ++m_level; ++m_damage; }
    int getLevel() { return m_level; }
    bool hasWon() { return m_level >= 20; }
};

class Monster : public Creature
{    
public:
    enum Type
    {
        DRAGON, 
        ORC,
        SLIME,
        MAX_TYPES,
    };
    
    struct MonsterData
    {
        const char* name;
        char sym;
        int health;
        int damage;
        int gold;
    };

    static MonsterData monsterData[MAX_TYPES];
    static Monster getRandomMonster()
    {
        int num = getRandomNumber(0, MAX_TYPES - 1);
        return Monster(static_cast<Type>(num));
    }

    Monster(Type type) : 
        Creature(monsterData[type].name, monsterData[type].sym, monsterData[type].health, 
            monsterData[type].damage, monsterData[type].gold){}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
    { "dragon", 'D', 20, 4, 100 },
    { "orc", 'o', 4, 2, 25 },
    { "slime", 's', 1, 1, 10 }
};

// Этот метод обрабатывает атаку монстра игроком
void attackMonster(Player& p, Monster& m)
{
    if (p.isDead())
        return;
    std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";

    m.reduceHealth(p.getDamage());

    if (m.isDead())
    {
        std::cout << "You killed the " << m.getName() << ".\n";
        p.levelUp();
        p.addHealth(m.getDamage());
        std::cout << "Your health is " << p.getHealth() << " now!!! \n";
        std::cout << "You are now level " << p.getLevel() << ".\n";
        std::cout << "You found " << m.getGold() << " gold.\n";
        std::cout << std::endl;
        p.addGold(m.getGold());
    }
}

void attackPlayer(Monster& m, Player& p)
{
    // Если монстр мертв, то он не может атаковать игрока
    if (m.isDead())
        return;
    p.reduceHealth(m.getDamage());
    std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";  
    std::cout << "Your health is " << p.getHealth() << " now!!! \n";
}

void fightMonster(Player& p)
{
    bool fighting = false;
    Monster m = Monster::getRandomMonster();
    std::cout << "You have encountered a " << m.getName() << " (" << m.getSym() << ").\n";
    while (!m.isDead() && !p.isDead())
    {
      /*  std::cout << "(R)un or (F)ight: ";
        char input;
        std::cin >> input;
        if (input == 'R' || input == 'r')*/
        if((!fighting) && ((p.getDamage() < m.getDamage()) || (p.getHealth() <= m.getHealth()/2)))
        {
            // 50/50 шанс удачного побега
            if (getRandomNumber(1, 2) == 1)
            {
                std::cout << "You successfully fled.\n";
                std::cout << std::endl;
                return; // встречу с монстром удалось избежать
            }
            else
            {
                // Неудачная попытка побега дает монстру право атаковать
                std::cout << "You failed to flee.\n";
                std::cout << std::endl;
                attackPlayer(m, p);
                continue;
            }
        }
        else
        //if (input == 'F' || input == 'f')
        {
            // Сначала атакует игрок, затем монстр
            fighting = true;
            attackMonster(p, m);
            attackPlayer(m, p);
            
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
    rand(); // сбрасываем первый результат

    std::cout << "Enter your name: Sergii \n";
    std::string playerName = "Sergii";
    //std::cin >> playerName;

    Player p(playerName);
    std::cout << "Welcome, " << p.getName() << '\n';

    // Если игрок не мертв и еще не победил, то игра продолжается
    while (!p.isDead() && !p.hasWon())
        fightMonster(p);

    // К этому моменту игрок либо мертв, либо победил
    if (p.isDead())
    {
        std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
    }
    else
    {
        std::cout << "You won the game with " << p.getGold() << " gold!\n";
    }

    return 0;
}

