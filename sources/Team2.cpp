#include "Team2.hpp"

Team2::Team2(Character *leader) : leader(leader) {add(leader);}

Team2::Team2(){}

Team2::~Team2()
{
    for (unsigned int i = 0; i < 10; i++)
    {
        delete fighters[i];
        fighters[i] = NULL;
    }
    leader = NULL;
}

void Team2::attack(Team2 *enemies)
{
    if (enemies == nullptr)
    {
        throw std::invalid_argument("Enemy team is null!");
    }
        for (const auto& fighter : fighters)
        {
            if (fighter->getIsCowboy())
            {
                Character *theEnemy;
                this->leader = closetMemberIsAlive(fighters, this->leader);
                theEnemy = closetEnemyIsAlive(enemies->fighters, this->leader);
                attackEnemy(fighter, theEnemy);
            }
        }

        for (const auto& fighter : fighters)
        {
            if (fighter->getIsNinja())
            {
                Character *theEnemy;
                this->leader = closetMemberIsAlive(fighters, this->leader);
                theEnemy = closetEnemyIsAlive(enemies->fighters, this->leader);
                attackEnemy(fighter, theEnemy);
            }
        } 
}
/// @brief change!!!!!!!!!!!!!!!!!!!!!!!!!!!1

void Team2::attackEnemy(Character *member, Character *enemy)
{
    if (Cowboy *cowboy = dynamic_cast<Cowboy*>(member))
    {
        if (!(cowboy->getBulletCounter()))
        {
            cowboy->reload();
        }
        else
        {
            cowboy->shoot(enemy);
        }
    }
    else if (Ninja *ninja = dynamic_cast<Ninja*>(member))
    {
        double dist = ninja->distance(enemy);
        if (dist < 1.0)
        {
            ninja->slash(enemy);
        }
        else
        {
            ninja->move(enemy);
        }
    }
}

void Team2::add(Character *player)
{
    if (fighters.size() == 10)
        throw runtime_error("there are maximum 10 members that are not already in other teams");
    if (player->getIsPlaying())
        throw runtime_error("The player is already in a team");

    fighters.push_back(player);
    player->setIsPlaying(true);
}

Character* Team2::closetMemberIsAlive(std::vector<Character *> &members, Character *leader)
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
    Character *newLeader;
    
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

Character* Team2::closetEnemyIsAlive(std::vector<Character *> &enemies, Character *leader)
{
    if (enemies.capacity() == 0)
    {
        throw std::invalid_argument("enemies team is empty!");
    }
    
    int max = 9999999;
    Character *newEnemy;
    
        for (const auto& enemy : enemies)
        {
            if (leader->distance(enemy) < max)
            {
                max = leader->distance(enemy);
                newEnemy = enemy;
            }
        }
    return newEnemy;
}

int Team2::stillAlive()
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

void Team2::print()
{
  for (Character *member : fighters)
    if (!member->getIsNinja())
      cout << member->print() << endl;
  for (Character *member : fighters)
    if (member->getIsNinja())
      cout << member->print() << endl;
}
//change!!!
void Team2::setLeader(Character *newLeader) { leader = newLeader; }