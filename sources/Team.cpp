#include "Team.hpp"

Team::Team(Character *leader) : leader(leader) {add(leader);}

Team::~Team()
{
    for (const auto& fighter : fighters)
    {
        delete fighter;   
    }
};

void Team::add(Character *player)
{
    if (fighters.size() == 10)
        throw runtime_error("there are maximum 10 members that are not already in other teams");
    if (player->getIsPlaying())
        throw runtime_error("The player is already in a team");

    fighters.push_back(player);
    player->setIsPlaying(true);
}

/// @brief 
    std::vector<Character *> Team::getAliveMembers(const std::vector<Character *> &characters) const
    {
        std::vector<Character *> aliveMembers;
        for (auto character : characters)
        {
            if (character->isAlive())
            {
                aliveMembers.push_back(character);
            }
        }
        return aliveMembers;
    }
/// @param enemies 
void Team::attack(Team *enemies)
{
    if (enemies == nullptr)
    {
        throw std::invalid_argument("Enemy team is null!");
    }

    if (!enemies->stillAlive())
    {
        throw std::runtime_error("The enemy is already dead");
    }
        for (const auto& fighter : fighters)
        {
            if (fighter->getIsCowboy())
            {
                Character *theEnemy;
                this->leader = closetMemberIsAlive(fighters, this->leader);
                std::vector<Character *> aliveMembers = getAliveMembers(enemies->fighters);
                if(aliveMembers.capacity() == 0)
                {return;}
                theEnemy = closetEnemyIsAlive(aliveMembers, this->leader);
                attackEnemy(fighter, theEnemy);
            }
        }

        for (const auto& fighter : fighters)
        {
            if (fighter->getIsNinja())
            {
                Character *theEnemy;
                this->leader = closetMemberIsAlive(fighters, this->leader);
                std::vector<Character *> aliveMembers = getAliveMembers(enemies->fighters);
                if(aliveMembers.capacity() == 0)
                {return;}
                theEnemy = closetEnemyIsAlive(aliveMembers, this->leader);
                attackEnemy(fighter, theEnemy);
            }
        } 
}
/// @brief change!!!!!!!!!!!!!!!!!!!!!!!!!!!1

void Team::attackEnemy(Character *member, Character *enemy)
{
    if (Cowboy *cowboy = dynamic_cast<Cowboy*>(member))
    {
        if (!(cowboy->getBulletCounter()))
        {
            cowboy->reload();
        }
        else
        {
            if (enemy->isAlive())
            {
                cowboy->shoot(enemy);
            }
            else
                return;
        }
    }
    else if (Ninja *ninja = dynamic_cast<Ninja*>(member))
    {
        double dist = ninja->distance(enemy);
        if (dist < 1)
        {
            if (enemy->isAlive())
            {
                ninja->slash(enemy);
            }
            else
                return;
        }
        else
        {
            ninja->move(enemy);
        }
    }
}

Character* Team::closetMemberIsAlive(std::vector<Character *> &members, Character *leader)
{
    if (members.capacity() == 0)
    {
        throw std::invalid_argument("Members team is empty!");
    }

    else if (leader->isAlive())
    {
        return leader;
    }
    
    int max = 9999999;
    Character *newLeader = nullptr;
    
    if (!(leader->isAlive()))
    {
        for (const auto& member : members)
        {
            if (leader->distance(member) < max)
            {
                max = leader->distance(member);
                newLeader = member;
            }
        }
    }
    return newLeader;
}

Character* Team::closetEnemyIsAlive(std::vector<Character *> &enemies, Character *leader)
{
    if (enemies.capacity() == 0)
    {
        throw std::invalid_argument("enemies team is empty!");
    }
    
    int max = 9999999;
    Character *newEnemy = nullptr;
    
        for (const auto& enemy : enemies)
        {
            
            if (enemy->isAlive())
            {
                double aaa = leader->distance(enemy);
                if (aaa < max)
                {
                    max = aaa;
                    newEnemy = enemy;
                }
            }
        }
    return newEnemy;
}

int Team::stillAlive()
{
    int counter = 0;

    for (const auto& fighter : fighters)
    {
        if (fighter->isAlive())
        {
            counter++;
        }
    }
    return counter;
}

//change!!!!!!!!!!!!1

void Team::print()
{
  for (Character *member : fighters)
    if (!member->getIsNinja())
      cout << member->print() << endl;
  for (Character *member : fighters)
    if (member->getIsNinja())
      cout << member->print() << endl;
}
//change!!!
void Team::setLeader(Character *newLeader) { leader = newLeader; }