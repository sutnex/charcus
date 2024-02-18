#include <iostream>
#include <string>
#include <vector>

// Weapon class representing the character's weapon.
class Weapon {
private:
    std::string epicName;
    int damageValue;
    std::vector<std::string> specialAbilities;

public:
    Weapon(std::string epicName, int damageValue, std::vector<std::string> specialAbilities)
        : epicName(epicName), damageValue(damageValue), specialAbilities(specialAbilities) {}

    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon) {
        os << "Weapon: " << weapon.epicName << std::endl;
        os << "Damage: " << weapon.damageValue << std::endl;
        os << "Special Abilities: ";
        for (const std::string& ability : weapon.specialAbilities) {
            os << ability << ", ";
        }
        os << std::endl;
        return os;
    }

    bool operator==(const Weapon& other) const {
        return epicName == other.epicName && damageValue == other.damageValue && specialAbilities == other.specialAbilities;
    }
};

// Armor class representing the character's armor.
class Armor {
private:
    std::string epicName;
    std::string description;
    int armorValue;

public:
    Armor(std::string epicName, std::string description, int armorValue)
        : epicName(epicName), description(description), armorValue(armorValue) {}

    friend std::ostream& operator<<(std::ostream& os, const Armor& armor) {
        os << "Armor: " << armor.epicName << std::endl;
        os << "Description: " << armor.description << std::endl;
        os << "Armor Value: " << armor.armorValue << std::endl;
        return os;
    }

    bool operator==(const Armor& other) const {
        return epicName == other.epicName && description == other.description && armorValue == other.armorValue;
    }
};

// Character class representing the game character.
class Character {
public: // Change access specifier to public
    std::string name;
    std::string species;
    std::string epicBackstory;
    int startingHealth;
    Weapon weapon;
    Armor armor;

    Character(std::string name, std::string species, std::string epicBackstory, int startingHealth, Weapon weapon, Armor armor)
        : name(name), species(species), epicBackstory(epicBackstory), startingHealth(startingHealth), weapon(weapon), armor(armor) {}

    void displayInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Species: " << species << std::endl;
        std::cout << "Epic Backstory: " << epicBackstory << std::endl;
        std::cout << "Starting Health: " << startingHealth << std::endl;
        std::cout << weapon;
        std::cout << armor;
    }

    bool operator==(const Character& other) const {
        return name == other.name && species == other.species && epicBackstory == other.epicBackstory &&
            startingHealth == other.startingHealth && weapon == other.weapon && armor == other.armor;
    }
};


// Function to prompt user to select a weapon.
Weapon selectWeapon() {
    std::cout << "Choose a weapon:" << std::endl;
    std::cout << "1. Sword of Justice (Damage: 20, Abilities: Critical Strike, Holy Smite)" << std::endl;
    std::cout << "2. Axe of Fury (Damage: 25, Abilities: Berserk)" << std::endl;
    std::cout << "3. Bow of Precision (Damage: 18, Abilities: Long Shot)" << std::endl;

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(); // Clear input buffer.

    switch (choice) {
    case 1:
        return Weapon("Sword of Justice", 20, { "Critical Strike", "Holy Smite" });
    case 2:
        return Weapon("Axe of Fury", 25, { "Berserk" });
    case 3:
        return Weapon("Bow of Precision", 18, { "Long Shot" });
    default:
        std::cerr << "Invalid choice! Defaulting to Sword of Justice." << std::endl;
        return Weapon("Sword of Justice", 20, { "Critical Strike", "Holy Smite" });
    }
}

// Function to prompt user to select armor.
Armor selectArmor() {
    std::cout << "Choose armor:" << std::endl;
    std::cout << "1. Plate Armor (Armor Value: 30)" << std::endl;
    std::cout << "2. Chainmail (Armor Value: 25)" << std::endl;
    std::cout << "3. Leather Armor (Armor Value: 15)" << std::endl;

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(); // Clear input buffer.

    switch (choice) {
    case 1:
        return Armor("Plate Armor", "Heavy armor protecting the vital areas", 30);
    case 2:
        return Armor("Chainmail", "Flexible and strong armor made of interlocking metal rings", 25);
    case 3:
        return Armor("Leather Armor", "Lightweight armor made of cured leather", 15);
    default:
        std::cerr << "Invalid choice! Defaulting to Plate Armor." << std::endl;
        return Armor("Plate Armor", "Heavy armor protecting the vital areas", 30);
    }
}

// Function to display menu options.
void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. View Character\n";
    std::cout << "2. Compare Characters\n";
    std::cout << "3. Exit\n";
}

// Function to compare two characters.
void compareCharacters(const Character& char1, const Character& char2) {
    std::cout << "\nComparing Characters:\n";
    std::cout << "Character 1:\n";
    char1.displayInfo();
    std::cout << "\nCharacter 2:\n";
    char2.displayInfo();

    // Calculating stat differences.
    long long healthDifference = static_cast<long long>(char1.startingHealth) - char2.startingHealth;
    std::cout << "\nHealth Difference: " << healthDifference << std::endl;
}

int main() {
    // Welcome message.
    std::cout << "Welcome to @sutnex's character customizer!" << std::endl;

    std::vector<Character> characters;

    for (int i = 0; i < 3; ++i) {
        std::cout << "\nCreating Character " << i + 1 << std::endl;
        std::string name, species, epicBackstory;
        int startingHealth;
        std::cout << "Enter character name: ";
        std::getline(std::cin, name);
        std::cout << "Enter species: ";
        std::getline(std::cin, species);
        std::cout << "Enter epic backstory: ";
        std::getline(std::cin, epicBackstory);
        std::cout << "Enter starting health: ";
        std::cin >> startingHealth;
        std::cin.ignore();

        // Prompt user to choose weapon and armor for the character.
        Weapon weapon = selectWeapon();
        Armor armor = selectArmor();

        Character character(name, species, epicBackstory, startingHealth, weapon, armor);
        characters.push_back(character);
    }

    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear input buffer.

        switch (choice) {
        case 1: {
            std::cout << "Enter character number (1-3): ";
            int charNumber;
            std::cin >> charNumber;
            if (charNumber >= 1 && charNumber <= 3) {
                characters[charNumber - 1].displayInfo();
            }
            else {
                std::cerr << "Invalid character number!" << std::endl;
            }
            break;
        }
        case 2: {
            std::cout << "Enter character numbers to compare (1-3): ";
            int charNumber1, charNumber2;
            std::cin >> charNumber1 >> charNumber2;
            if (charNumber1 >= 1 && charNumber1 <= 3 && charNumber2 >= 1 && charNumber2 <= 3) {
                compareCharacters(characters[charNumber1 - 1], characters[charNumber2 - 1]);
            }
            else {
                std::cerr << "Invalid character numbers!" << std::endl;
            }
            break;
        }
        case 3:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cerr << "Invalid choice! Please enter a number between 1 and 3." << std::endl;
        }
    } while (choice != 3);

    return 0;
}

