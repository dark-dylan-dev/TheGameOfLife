#include "RoundedRectangle.hpp"

RoundedRectangleShape::RoundedRectangleShape(const sf::Vector2f size, const float radius)
{
    setSize(size);
    setCornerRadius(radius);
}


////////////////////////////////////////////////////////////
void RoundedRectangleShape::setSize(sf::Vector2f size)
{
    m_size = size;
    update();
}


////////////////////////////////////////////////////////////
sf::Vector2f RoundedRectangleShape::getSize() const
{
    return m_size;
}


////////////////////////////////////////////////////////////
void RoundedRectangleShape::setCornerRadius(float radius)
{
    m_percentRadius = radius;
    update();
}


////////////////////////////////////////////////////////////
float RoundedRectangleShape::getCornerRadius() const
{
    return m_percentRadius;
}


////////////////////////////////////////////////////////////
std::size_t RoundedRectangleShape::getPointCount() const
{
    return 4;
}


////////////////////////////////////////////////////////////
sf::Vector2f RoundedRectangleShape::getPoint(std::size_t index) const
{
    switch (index)
    {
        default:
            [[fallthrough]]
        case 0:
            return {0, 0};
        case 1:
            return {m_size.x, 0};
        case 2:
            return {m_size.x, m_size.y};
        case 3:
            return {0, m_size.y};
    }
}


////////////////////////////////////////////////////////////
sf::Vector2f RoundedRectangleShape::getGeometricCenter() const
{
    return m_size / 2.f;
}