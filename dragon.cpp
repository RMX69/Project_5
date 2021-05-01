#include "dragon.hpp"


Dragon::Dragon(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid) :
    Entity(builder, inventory, uid)
{
    std::cout << Name() << " the dragon has entered the battle" << std::endl;    
}



void Dragon::Fire_Breath(Entity * target)
{
    Attack(target, GetStrength() * 0.8, "Fire Breath");
}

void Dragon::Bite(Entity * target)
{
    Attack(target, GetStrength() * 0.5, "Bite");
}

void Dragon::OutputStatus() const
{
    std::cout << Class() << ": " << this->Name()
                << "\n\tCurrent HP: " << this->CurrentHP()
                <<"\n\tStrength: " << this->GetStrength()
                << std::endl;

    PrintInventory();
}

void Dragon::WeaponAttack(Entity * target)
{
    Attack(target, 4.0, "Tail Slap");
}

void Dragon::UseAction(Entity * target, const std:: string& spellName, const std::string & args)
{
    if(spellName == "weapon_attack")
    {
        WeaponAttack(target);
        return;
    }
    if(spellName == "fire_breath")
    {
        Fire_Breath(target);
        return;
    }
    if(spellName == "bite")
    {
        Bite(target);
        return;
    }
    errorFindingAbility(spellName);
}