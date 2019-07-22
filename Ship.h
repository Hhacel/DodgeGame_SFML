#ifndef SHIP_H
#define SHIP_H
#include "Bullets.h"

class Ship : public Bullets
{
    public:
        Ship(sf::Vector2f size);
        virtual ~Ship();

        float move_speed;
        float gravity;
        bool collision_test();

        sf::RectangleShape ship;

        void draw_to(sf::RenderWindow &window);
        void move(sf::Vector2f distance);
        void set_position(sf::Vector2f new_position);

        void game_over();


    protected:

    private:

};

#endif // SHIP_H
