/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


int main() {
   //  Point a(32.3,44),b(1.3,3.5);
   //  assert(a.distance(b) == b.distance(a));
   //  Cowboy *tom = new Cowboy("Tom", a);
   //  OldNinja *sushi = new OldNinja("sushi", b);
   //  tom->shoot(sushi);
   //  cout << tom->print() <<endl;

   //  sushi->move(tom);
   //  sushi->slash(tom);

   //  Team team_A(tom); 
   //  team_A.add(new YoungNinja("Yogi", Point(64,57)));

   //  // Team b(tom); should throw tom is already in team a

   //   Team team_B(sushi);
   //   team_B.add(new TrainedNinja("Hikari", Point(12,81)));


   //   while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
   //      team_A.attack(&team_B);
   //      team_B.attack(&team_A);
   //      team_A.print();
   //      team_B.print();
   //   }

   //   if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
   //   else cout << "winner is team_B" << endl;

         Cowboy cowboy{"Bobcow", Point{2, 3}};
         Ninja ninja{"ninjaal", Point{2, 3}, 100, 14,1,1};
         Team team(&cowboy);
         Team team2(&ninja);
         int x = team.stillAlive();
         int y = team2.stillAlive();
      //   Point p4{Point::moveTowards(p1, p2, third_p)};
      //   CHECK_EQ(p4.distance(p2), doctest::Approx(third_p * 2).epsilon(0.001));

      //   // There is no such a thing as negative distance
      //   CHECK_THROWS_AS(Point::moveTowards(p1, p2, -1),std::invalid_argument);


     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
