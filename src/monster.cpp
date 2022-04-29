#include "../headers/monster.hpp"

#include <math.h>




Monster::Monster (double x,double y,int direction,int apper,int z):
    x{x},y{y},direction{direction},apper{apper},z(z)
{

}

void Monster::reduce_apper()
{
    if(apper)
    {
        apper--;
    }

}

int Monster::move(Shapes s,int cenx ,int ceny,std::pair<int, int> weapon)
{
    double sensitivity = 0.0002;
    if(apper == 0 )
    {
        int p1= direction%s.points.size();
        int p2=(direction+1)%s.points.size();
        //std::cout << p1 << || std::endl
        double mx=(s.points[p1].first+s.points[p2].first)/2 - weapon.first;
        double my=(s.points[p1].second+s.points[p2].second)/2 - weapon.second;


        x += sensitivity*(mx-x);
        y += sensitivity*(my-y);
        if(abs(x  - mx) < 1 && abs(y  - my)< 1 )
        {
            //monsters.erase(i--);

            //lifeval--;
            return 0;
        }
    }
    return 1;
}



//Monster::~Monster (){}




