#include "input_interface.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace spcs{
    namespace graphics {
        /*class arrow{
            private:
            sf::ConvexShape sup_arrow;
            sf::ConvexShape inf_arrow;

            public:
            arrow();
            void rotate(double ang);
            void setPosition(d_pair new_position);
            void draw(sf::RenderWindow& window);
        }; */
        //implementazione seria delle arrow da fare

        class graph_axis{
            sf::RectangleShape x_axis;
            sf::ConvexShape x_arrow;
            sf::RectangleShape y_axis;
            sf::ConvexShape y_arrow;

            public:
            graph_axis();
            void draw(sf::RenderWindow& window);
        };

        d_pair get_rescaling_factor(spcs::simulation& sim);

        class graph_point{
            sf::CircleShape point;

            public:
            graph_point(spcs::simulation& sim);
            void draw(sf::RenderWindow& window);
            void print_position_for_debug();
        };
    };
}